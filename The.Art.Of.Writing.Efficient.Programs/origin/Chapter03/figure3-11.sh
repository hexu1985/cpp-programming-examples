#!/bin/bash

set -x
GBENCH_DIR=~/local/google_benchmark
clang++ -g -O3 -mavx2 -Wall --std=c++17 -I$GBENCH_DIR/include 01_superscalar_1_mca.C -mllvm -x86-asm-syntax=intel -S -o - \
    | llvm-mca -mcpu=btver2 -timeline
