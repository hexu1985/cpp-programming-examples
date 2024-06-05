#!/bin/bash

set -x
GBENCH_DIR=~/local/google_benchmark
clang++ -g -O3 -mavx2 -Wall -pedantic -I$GBENCH_DIR/include 01_superscalar_1.C \
    $GBENCH_DIR/lib/libbenchmark.a -pthread -lrt -lm -o benchmark
./benchmark
