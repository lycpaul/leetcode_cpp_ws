cmake_minimum_required(VERSION 3.15)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Windows use MSVC cl.exe by default, but recommended clang
set(CMAKE_C_COMPILER cl.exe CACHE STRING "C compiler")
set(CMAKE_CXX_COMPILER cl.exe CACHE STRING "C++ compiler")
