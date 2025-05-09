#!/bin/bash

current_dir=$( cd $(dirname ${BASH_SOURCE[0]}) && pwd )
src_dir=${current_dir}
build_dir=${current_dir}/build

cmake -S ${src_dir} -B ${build_dir} -D CMAKE_BUILD_TYPE=Debug -D fmt_DIR=${HOME}/local/fmtlib/lib/cmake/fmt
cmake --build ${build_dir} -j 4 -- VERBOSE=1

