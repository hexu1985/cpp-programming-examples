cmake_minimum_required( VERSION 3.15 )

project ( example )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GPERFTOOLS_DIR "$ENV{HOME}/local/gperftools")
message( STATUS "GPERFTOOLS_DIR = ${GPERFTOOLS_DIR}")
message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

set(TEST_SCRIPTS flamegraph.pl pprof_flamegraph.sh pprof_text.sh pprof_web.sh)

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
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/pprof_flamegraph.sh
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/pprof_text.sh
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/pprof_web.sh
)

add_executable( example 01a_substring_sort.C 01a_substring_sort_a.C 01a_substring_sort_b.C 01a_substring_sort_c.C )
target_link_directories( example PRIVATE ${GPERFTOOLS_DIR}/lib )
target_link_libraries( example profiler )
add_dependencies( example copy_scripts )
