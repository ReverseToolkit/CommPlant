module;

#include "commplant.hpp"

export module commplant;

export namespace commplant::inline v2{
    using commplant::v2::InitInfo;
    using commplant::v2::Init;
    using commplant::v2::Hook;
    using commplant::v2::UnHook;
    using commplant::v2::IsHooked;
    using commplant::v2::Deoptimize;
    using commplant::v2::GetNativeFunction;
    using commplant::v2::MakeClassInheritable;
    using commplant::v2::MakeDexFileTrusted;
    using commplant::v2::MmapHidden;
    using commplant::v2::HideDexFile;
    using commplant::v2::HideClassLoaderDex;
}
