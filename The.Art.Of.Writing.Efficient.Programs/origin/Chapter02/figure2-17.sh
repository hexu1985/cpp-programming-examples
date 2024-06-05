#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic 01a_substring_sort_a.C 01a_substring_sort_b.C 01a_substring_sort_c.C 01a_substring_sort.C -lprofiler -o example
CPUPROFILE=prof.data CPUPROFILE_FREQUENCY=1000 ./example
