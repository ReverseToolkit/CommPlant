#pragma once

#include <cerrno>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <sys/mman.h>
#include <unistd.h>

#ifndef PROT_HIDE
#define PROT_HIDE 0x40
#endif

namespace commplant::prot_hide {

inline int StripHide(int prot) { return prot & ~PROT_HIDE; }

inline void *Mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    const int want = StripHide(prot) | PROT_HIDE;
    void *p = ::mmap(addr, length, want, flags, fd, offset);
    if (p != MAP_FAILED) return p;
    if (errno != EINVAL && errno != ENOSYS) return MAP_FAILED;
    return ::mmap(addr, length, StripHide(prot), flags, fd, offset);
}

inline bool Mprotect(void *addr, size_t length, int prot) {
    const int want = StripHide(prot) | PROT_HIDE;
    if (::mprotect(addr, length, want) == 0) return true;
    if (errno != EINVAL && errno != ENOSYS) return false;
    return ::mprotect(addr, length, StripHide(prot)) == 0;
}

// Android arm64 TBI / MTE keeps a tag in bits 56-63. maps ranges are untagged.
inline uintptr_t UntagUser(uintptr_t addr) { return addr & 0x00ffffffffffffffULL; }

inline bool MappedReadable(uintptr_t addr) {
    const uintptr_t needle = UntagUser(addr);
    if (needle < 0x10000) return false;
    FILE *maps = fopen("/proc/self/maps", "re");
    if (!maps) return false;
    bool ok = false;
    char line[512];
    while (fgets(line, sizeof(line), maps)) {
        unsigned long start = 0, end = 0;
        char r = '-';
        if (sscanf(line, "%lx-%lx %c", &start, &end, &r) < 3) continue;
        if (needle < start || needle + 4 > end) continue;
        ok = r == 'r';
        break;
    }
    fclose(maps);
    return ok;
}

// Hide the whole VMA that contains `addr`. mprotect on a subrange would split
// the VMA and leave the tail visible in maps.
inline bool HideVmaContaining(const void *addr) {
    if (!addr) return false;
    FILE *maps = fopen("/proc/self/maps", "re");
    if (!maps) return false;
    char line[512];
    const auto needle = UntagUser(reinterpret_cast<uintptr_t>(addr));
    bool ok = false;
    while (fgets(line, sizeof(line), maps)) {
        unsigned long start = 0, end = 0;
        char r = '-', w = '-', x = '-';
        if (sscanf(line, "%lx-%lx %c%c%c", &start, &end, &r, &w, &x) < 5) continue;
        if (needle < start || needle >= end) continue;
        int prot = 0;
        if (r == 'r') prot |= PROT_READ;
        if (w == 'w') prot |= PROT_WRITE;
        if (x == 'x') prot |= PROT_EXEC;
        if (prot == 0) prot = PROT_READ;
        ok = Mprotect(reinterpret_cast<void *>(start), end - start, prot);
        break;
    }
    fclose(maps);
    return ok;
}

inline bool LooksLikeDex(const uint8_t *p) {
    return p && (memcmp(p, "dex\n", 4) == 0 || memcmp(p, "cdex", 4) == 0);
}

// art::DexFile on Android 15 has a virtual destructor, so word 0 is the vtable
// and begin_ is the next word. Pointers may carry a TBI tag. Load through the
// original address, then match maps with the tag cleared.
inline bool HideArtDexFile(const void *dex_file) {
    if (!dex_file || !MappedReadable(reinterpret_cast<uintptr_t>(dex_file))) return false;
    auto *words = reinterpret_cast<const uintptr_t *>(dex_file);
    for (int i = 0; i < 12; ++i) {
        const uintptr_t cand = UntagUser(words[i]);
        if (!MappedReadable(cand)) continue;
        auto *p = reinterpret_cast<const uint8_t *>(cand);
        if (LooksLikeDex(p)) return HideVmaContaining(p);
    }
    return false;
}

}  // namespace commplant::prot_hide
