#!/bin/bash

CPUPROFILE=prof.data ./example

export PATH=${PATH}:${HOME}/local/gperftools/bin/
pprof-symbolize --web ./example prof.data  # 交互式查看
