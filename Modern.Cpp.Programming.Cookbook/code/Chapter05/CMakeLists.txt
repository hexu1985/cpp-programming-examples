cmake_minimum_required( VERSION 3.15 )

project ( Chapter05 LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB headers *.h)
add_executable(chapter05 main.cpp ${headers})
include_directories(${CMAKE_SOURCE_DIR}/include)
