#!/bin/bash

export PATH=${PATH}:${HOME}/local/gperftools/bin/
CPUPROFILE=prof.data CPUPROFILE_FREQUENCY=1000 ./example
pprof-symbolize --pdf ./example prof.data > prof.pdf

