#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic 02_substring_sort.C -o example
sudo perf record ./example
sudo perf report
