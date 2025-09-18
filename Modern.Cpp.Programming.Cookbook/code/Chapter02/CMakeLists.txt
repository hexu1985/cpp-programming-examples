
#add_compile_definitions(HAS_FORMAT_LIBRARY=1)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories($ENV{HOME}/local/fmtlib/include)

file(GLOB headers *.h)
add_executable(chapter02 main.cpp ${headers})
