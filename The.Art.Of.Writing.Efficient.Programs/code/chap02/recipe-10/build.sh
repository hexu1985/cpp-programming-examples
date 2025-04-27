#!/bin/bash

set -x
clang++ -g -O3 -mavx2 -Wall -pedantic -o benchmark 05a_compare_timer.C

