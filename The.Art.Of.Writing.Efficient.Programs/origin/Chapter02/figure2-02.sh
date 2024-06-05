#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic 01_substring_sort_a.C 01_substring_sort.C -lprofiler -o example
CPUPROFILE=prof.data ./example

