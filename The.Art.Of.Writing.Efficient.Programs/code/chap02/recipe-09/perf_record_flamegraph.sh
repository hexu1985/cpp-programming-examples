#!/bin/bash

sudo bash -c "echo -1 > /proc/sys/kernel/perf_event_paranoid"
perf record -F 99 -g ./example

perf script -i perf.data &> out.perf

current_dir=$( cd $(dirname ${BASH_SOURCE[0]}) && pwd )

# 生成火焰图
${current_dir}/stackcollapse-perf.pl out.perf > out.folded
${current_dir}/flamegraph.pl out.folded > flamegraph.svg

