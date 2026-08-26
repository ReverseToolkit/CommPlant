cmake_minimum_required(VERSION 3.18.1)
project("commplant_test")

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(external/lsparself)
add_library(test SHARED test.cpp)
set_target_properties(test PROPERTIES CXX_SCAN_FOR_MODULES ON)
find_package(dobby REQUIRED CONFIG)
find_package(commplant REQUIRED CONFIG)

get_property(commplant_INCLUDE TARGET commplant::commplant PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
file(GLOB_RECURSE commplant_MODULES "${commplant_INCLUDE}/*.ixx")
target_sources(commplant::commplant INTERFACE FILE_SET CXX_MODULES BASE_DIRS ${commplant_INCLUDE} FILES ${commplant_MODULES})
set_target_properties(commplant::commplant PROPERTIES IMPORTED_CXX_MODULES_COMPILE_FEATURES "cxx_std_23")
set_target_properties(commplant::commplant PROPERTIES IMPORTED_CXX_MODULES_INCLUDE_DIRECTORIES "${commplant_INCLUDE}")

target_link_libraries(test log dobby::dobby commplant::commplant lsparself)
