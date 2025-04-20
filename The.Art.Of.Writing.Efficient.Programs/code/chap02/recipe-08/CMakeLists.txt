cmake_minimum_required( VERSION 3.15 )

project ( example )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GPERFTOOLS_DIR "$ENV{HOME}/local/gperftools")
message( STATUS "GPERFTOOLS_DIR = ${GPERFTOOLS_DIR}")
message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

add_executable( example 02_substring_sort.C )
target_link_directories( example PRIVATE ${GPERFTOOLS_DIR}/lib )
target_link_libraries( example profiler )
