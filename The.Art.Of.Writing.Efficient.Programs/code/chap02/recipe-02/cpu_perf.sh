#!/bin/bash

CPUPROFILE=prof.data ./example

export PATH=${PATH}:${HOME}/local/gperftools/bin/
#pprof --text ./example prof.data
pprof-symbolize --text ./example prof.data
#pprof-symbolize --web ./example prof.data  # 交互式查看
