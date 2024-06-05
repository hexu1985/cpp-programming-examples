#!/bin/bash

set -x
GBENCH_DIR=~/local/google_benchmark
clang++ -g -O3 -mavx2 -Wall -pedantic -I$GBENCH_DIR/include 11_compare_mbm.C \
    11_compare_mbm_a.C 11_compare_mbm_b.C 11_compare_mbm_c.C \
    $GBENCH_DIR/lib/libbenchmark.a -pthread -lrt -lm -o benchmark
./benchmark
