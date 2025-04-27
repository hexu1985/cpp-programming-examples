#!/bin/bash

set -x
GBENCH_DIR=~/local/google_benchmark
clang++ -g -O3 -mavx2 -Wall -pedantic -I${GBENCH_DIR}/include 10a_compare_mbm.C \
    -L${GBENCH_DIR}/lib/ -lbenchmark -pthread -lrt -lm -o benchmark
