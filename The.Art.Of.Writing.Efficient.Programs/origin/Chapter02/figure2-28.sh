#!/bin/bash

set -x
GBENCH_DIR=~/local/google_benchmark
clang++ -g -O3 -mavx2 -Wall -pedantic -I$GBENCH_DIR/include 10a_compare_mbm.C \
   $GBENCH_DIR/lib/libbenchmark.a -pthread -lrt -lm -o benchmark
./benchmark --benchmark_repetitions=10 --benchmark_report_aggregates_only=true
