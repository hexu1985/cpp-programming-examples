#!/bin/bash

#set -x
clang++ -g -O3 -mavx2 -Wall -pedantic 01_substring_sort.C 01_substring_sort_a.C -o example -L${HOME}/local/gperftools/lib/ -lprofiler

