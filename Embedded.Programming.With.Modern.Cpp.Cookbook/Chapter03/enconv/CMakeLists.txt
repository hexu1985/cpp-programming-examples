cmake_minimum_required(VERSION 3.5.1)
project(enconv)
add_executable(sender sender.cpp)
add_executable(receiver receiver.cpp)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_CXX_FLAGS "--std=c++14")
set(CMAKE_CXX_COMPILER /usr/bin/aarch64-linux-gnu-g++)


