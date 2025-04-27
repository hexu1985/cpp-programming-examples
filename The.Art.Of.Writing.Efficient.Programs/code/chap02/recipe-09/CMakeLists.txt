cmake_minimum_required( VERSION 3.15 )

project ( example )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

set(TEST_SCRIPTS flamegraph.pl stackcollapse-perf.pl perf_record_flamegraph.sh perf_record_report.sh perf_stat.sh)

foreach(script ${TEST_SCRIPTS})
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${script}
        #COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/${script}
                ${CMAKE_CURRENT_BINARY_DIR}/${script}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${script}
        COMMENT "Copying test script ${script}"
    )
endforeach()

add_custom_target(copy_scripts ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/flamegraph.pl
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/stackcollapse-perf.pl
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/perf_record_flamegraph.sh
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/perf_record_report.sh
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/perf_stat.sh
)

add_executable( example 02_substring_sort.C )
add_dependencies( example copy_scripts )
