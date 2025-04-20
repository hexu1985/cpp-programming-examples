#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic 03_substring_sort.C 03_substring_sort_a.C -o example && ./example
