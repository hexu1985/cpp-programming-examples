cmake_minimum_required(VERSION 3.5.1)
project(prealloc)
add_executable(prealloc prealloc.cpp)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_CXX_FLAGS "--std=c++17")

set(CMAKE_CXX_COMPILER /usr/bin/aarch64-linux-gnu-g++)

