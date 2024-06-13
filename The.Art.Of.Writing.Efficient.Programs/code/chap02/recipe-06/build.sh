#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic compare.C example.C -o example 
sudo bash -c "echo -1 > /proc/sys/kernel/perf_event_paranoid"
perf record ./example

#perf report
perf report --stdio
