#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic 01_substring_sort.C 01_substring_sort_a.C -o example && ./example
sudo bash -c "echo -1 > /proc/sys/kernel/perf_event_paranoid"
perf stat ./example

perf list

perf stat -e cycles,instructions,branches,branch-misses,cache-references,cache-misses ./example

# ---

perf record ./example

#perf report
perf report --stdio
