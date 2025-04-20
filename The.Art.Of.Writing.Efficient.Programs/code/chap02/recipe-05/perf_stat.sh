#!/bin/bash

CPUPROFILE=prof.data ./example

sudo bash -c "echo -1 > /proc/sys/kernel/perf_event_paranoid"
perf stat ./example
#perf stat -e cycles,instructions,branches,branch-misses,cache-references,cache-misses ./example
