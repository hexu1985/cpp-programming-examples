基于Ubuntu 20.04 安装perf性能分析工具

联网情况下输入以下安装命令：

apt install linux-tools-common
apt install linux-tools-5.13.0-40-generic
apt install linux-cloud-tools-5.13.0-40-generic
由此安装完成

接着输入：perf -v 查看安装的perf版本
perf version 5.13.19

root@virtual-machine:/opt/perf# perf --help

usage: perf [–version] [–help] [OPTIONS] COMMAND [ARGS]

The most commonly used perf commands are:
annotate Read perf.data (created by perf record) and display annotated code
archive Create archive with object files with build-ids found in perf.data file
bench General framework for benchmark suites
buildid-cache Manage build-id cache.
buildid-list List the buildids in a perf.data file
c2c Shared Data C2C/HITM Analyzer.
config Get and set variables in a configuration file.
daemon Run record sessions on background
data Data file related processing
diff Read perf.data files and display the differential profile
evlist List the event names in a perf.data file
ftrace simple wrapper for kernel’s ftrace functionality
inject Filter to augment the events stream with additional information
iostat Show I/O performance metrics
kallsyms Searches running kernel for symbols
kmem Tool to trace/measure kernel memory properties
kvm Tool to trace/measure kvm guest os
list List all symbolic event types
lock Analyze lock events
mem Profile memory accesses
record Run a command and record its profile into perf.data
report Read perf.data (created by perf record) and display the profile
sched Tool to trace/measure scheduler properties (latencies)
script Read perf.data (created by perf record) and display trace output
stat Run a command and gather performance counter statistics
test Runs sanity tests.
timechart Tool to visualize total system behavior during a workload
top System profiling tool.
version display the version of perf binary
probe Define new dynamic tracepoints
trace strace inspired tool

See ‘perf help COMMAND’ for more information on a specific command.


```
WARNING: perf not found for kernel 5.15.0-102

  You may need to install the following packages for this specific kernel:
    linux-tools-5.15.0-102-generic
    linux-cloud-tools-5.15.0-102-generic

  You may also want to install one of the following packages to keep up to date:
    linux-tools-generic
    linux-cloud-tools-generic
```
