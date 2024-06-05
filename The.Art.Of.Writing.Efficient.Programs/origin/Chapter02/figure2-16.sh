#!/bin/bash

set -x
cat <<EOF
$ pprof ./example prof.data 
Using local file ./example.
Using local file prof.data.
addr2line: DWARF error: section .debug_info is larger than its filesize! (0x93ef57 vs 0x530ea0)
Welcome to pprof!  For help, type 'help'.
(pprof) text
Total: 22 samples
      22 100.0% 100.0%       22 100.0% compare
       0   0.0% 100.0%       17  77.3% __gnu_cxx::__ops::_Iter_comp_iter::operator (inline)
       0   0.0% 100.0%        5  22.7% __gnu_cxx::__ops::_Val_comp_iter::operator (inline)
       0   0.0% 100.0%       22 100.0% __libc_start_main
       0   0.0% 100.0%       22 100.0% _start
       0   0.0% 100.0%       22 100.0% main
       0   0.0% 100.0%       22 100.0% operator (inline)
       0   0.0% 100.0%        5  22.7% std::__final_insertion_sort (inline)
       0   0.0% 100.0%       17  77.3% std::__introsort_loop
       0   0.0% 100.0%       22 100.0% std::__sort (inline)
(pprof) text --lines
Total: 22 samples
      12  54.5%  54.5%       12  54.5% compare /home/hexu/git/The.Art.Of.Writing.Efficient.Programs/Chapter02/01_substring_sort_a.C:5
      10  45.5% 100.0%       10  45.5% compare /home/hexu/git/The.Art.Of.Writing.Efficient.Programs/Chapter02/01_substring_sort_a.C:4
       0   0.0% 100.0%       17  77.3% __gnu_cxx::__ops::_Iter_comp_iter::operator (inline) /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/predefined_ops.h:143
       0   0.0% 100.0%        5  22.7% __gnu_cxx::__ops::_Val_comp_iter::operator (inline) /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/predefined_ops.h:215
       0   0.0% 100.0%       22 100.0% __libc_start_main ??:0
       0   0.0% 100.0%       22 100.0% _start ??:0
       0   0.0% 100.0%       22 100.0% main /home/hexu/git/The.Art.Of.Writing.Efficient.Programs/Chapter02/01_substring_sort.C:26
       0   0.0% 100.0%       22 100.0% operator (inline) /home/hexu/git/The.Art.Of.Writing.Efficient.Programs/Chapter02/01_substring_sort.C:26
       0   0.0% 100.0%        5  22.7% std::__final_insertion_sort (inline) /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_algo.h:1891
       0   0.0% 100.0%       17  77.3% std::__introsort_loop /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_algo.h:1958
(pprof) 
EOF
