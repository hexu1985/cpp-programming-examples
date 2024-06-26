#!/bin/bash

#set -x
clang++ -g -O3 -mavx2 -Wall -pedantic example.C -o example -L${HOME}/local/gperftools/lib/ -lprofiler
export LD_LIBRARY_PATH=${HOME}/local/gperftools/lib/:${LD_LIBRARY_PATH}
CPUPROFILE=prof.data CPUPROFILE_FREQUENCY=1000 ./example

export PATH=${PATH}:${HOME}/local/gperftools/bin/
pprof --text --lines ./example prof.data
