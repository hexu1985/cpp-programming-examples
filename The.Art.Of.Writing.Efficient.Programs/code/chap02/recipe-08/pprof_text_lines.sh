#!/bin/bash

CPUPROFILE=prof.data CPUPROFILE_FREQUENCY=1000 ./example

export PATH=${PATH}:${HOME}/local/gperftools/bin/
pprof-symbolize --text --lines ./example prof.data
