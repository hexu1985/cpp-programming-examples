#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic 04_substring_sort.C 04_substring_sort_a.C -o example
