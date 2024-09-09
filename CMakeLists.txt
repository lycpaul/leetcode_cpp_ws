cmake_minimum_required(VERSION 3.27)
project(leetcode_cpp_ws LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(USER_HOME_DIR $ENV{HOME})
include(${USER_HOME_DIR}/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(fmt CONFIG REQUIRED)
find_package(pprint CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

# setup options
option(BUILD_TESTS "whether or not to build the tests" OFF)
if (BUILD_TESTS)
    # print catch2 directory
    enable_testing()
    message(STATUS "Catch2_DIR: ${Catch2_DIR}")
    list(APPEND CMAKE_MODULE_PATH ${Catch2_DIR})
    # include(Test)
endif (BUILD_TESTS)

# Get all .cpp files
file(
        GLOB_RECURSE
        SourceFiles
        "ArrayString/*.cpp"
        "LinkedList/*.cpp"
        "TreesGraphs/*.cpp"
        "SortingSearching/*.cpp"
        "DynamicProgramming/*.cpp"
        "Design/*.cpp"
        "Math/*.cpp"
        "Hashing/*.cpp"
        "SlidingWindow/*.cpp"
        "Others/*.cpp")

# Loop through each .cpp file to create a target
foreach (SourceFile ${SourceFiles})
    # Get the filename without the extension
    get_filename_component(TargetName ${SourceFile} NAME_WE)

    # Add executable for each target
    add_executable(${TargetName} ${SourceFile})

    # Include directories
    target_include_directories(
            ${TargetName} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${COMMON_INCLUDE_DIR})

    # Link libraries
    target_link_libraries(${TargetName} PRIVATE fmt::fmt-header-only)
endforeach ()
