#!/bin/bash

CPUPROFILE=prof.data CPUPROFILE_FREQUENCY=1000 ./example

export PATH=${PATH}:${HOME}/local/gperftools/bin/
pprof-symbolize --web ./example prof.data  # 交互式查看
