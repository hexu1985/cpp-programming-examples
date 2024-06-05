#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic 02_substring_sort.C -lprofiler -o example
CPUPROFILE=prof.data CPUPROFILE_FREQUENCY=1000 ./example
pprof --text --lines ./example prof.data
