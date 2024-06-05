#!/bin/bash

set -x
cat <<EOF
$ gdb ./benchmark 
(gdb) start
Temporary breakpoint 1 at 0x401248: file 06_compare_timer.C, line 42.
Starting program: /home/hexu/git/The.Art.Of.Writing.Efficient.Programs/Chapter02/benchmark 

Temporary breakpoint 1, main () at 06_compare_timer.C:42
42          system_clock::time_point t0 = system_clock::now();
(gdb) next
46          system_clock::time_point t1 = system_clock::now();
(gdb) next
50          system_clock::time_point t2 = system_clock::now();
(gdb) next
51          cout << duration_cast<microseconds>(t1 - t0).count() << "us " << duration_cast<microseconds>(t2 - t1).count() << "us" << endl;
(gdb) next
1916652us 11747518us
52      }
(gdb) 
EOF
