#!/bin/bash

set -x
sudo perf stat -e cycles,instructions,branches,branch-misses,cache-references,cache-misses ./example
