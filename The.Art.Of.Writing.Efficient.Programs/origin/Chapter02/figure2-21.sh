#!/bin/bash

set -x
cat <<EOF
Samples: 244  of event 'cycles', 4000 Hz, Event count (approx.): 274418007
std::__introsort_loop<__gnu_cxx::__normal_iterator<char const**, std::vector<char const*, std::allocator<char const*> > >, long, __gnu_cxx::__ops::_Iter_comp_iter<main::$_0> >  /ho
Percent│       nop
       │310:   mov    (%r15),%rbp
       │       mov    (%r14),%rcx
       │     operator()():
       │     std::sort(vs.begin(), vs.end(), [&](const char* a, const char* b) { ++count; return compare(a, b, L); });
       │       add    $0x1,%r9
       │       mov    %r9,0x0(%r13)
       │     _Z7comparePKcS0_j():
       │     if (s1 == s2) return false;
       │       cmp    %rcx,%rbp
       │     ↓ je     3b4
       │327:   mov    $0x3,%edi
       │       nop
       │     if (s1[i1] != s2[i2]) return s1[i1] > s2[i2];
       │330:   movzbl -0x3(%rbp,%rdi,1),%eax
       │       movzbl -0x3(%rcx,%rdi,1),%ebx
  0.50 │       cmp    %bl,%al
       │     ↓ jne    380
 13.82 │       movzbl -0x2(%rbp,%rdi,1),%eax
       │       movzbl -0x2(%rcx,%rdi,1),%ebx
       │       cmp    %bl,%al
       │     ↓ jne    380
       │       movzbl -0x1(%rbp,%rdi,1),%eax
 17.78 │       movzbl -0x1(%rcx,%rdi,1),%ebx
       │       cmp    %bl,%al
       │     ↓ jne    380
  0.50 │       movzbl 0x0(%rbp,%rdi,1),%eax
       │       movzbl (%rcx,%rdi,1),%ebx
 11.58 │       cmp    %bl,%al
       │     ↓ jne    380
       │     for (unsigned int i1 = 0, i2 = 0; i1 < l; ++i1, ++i2) {
       │       add    $0x4,%rdi
       │       cmp    $0x40003,%rdi
 12.41 │     ↑ jne    330
       │     ↓ jmp    3a0
       │       nop
       │     if (s1[i1] != s2[i2]) return s1[i1] > s2[i2];
       │380:   cmp    %bl,%al
       │     _ZSt21__unguarded_partitionIN9__gnu_cxx17__normal_iteratorIPPKcSt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIZ4mainE3$_0EEET_SD_SD_SD_T0_():
       │     while (__comp(__first, __pivot))
       │     ↓ jle    3a0
       │     _ZN9__gnu_cxx5__ops15_Iter_comp_iterIZ4mainE3$_0EclINS_17__normal_iteratorIPPKcSt6vectorIS7_SaIS7_EEEESC_EEbT_T0_():
  0.50 │       mov    0x8(%r15),%rbp
       │     _ZN9__gnu_cxx17__normal_iteratorIPPKcSt6vectorIS2_SaIS2_EEEppEv():
       │     ++_M_current;
       │       add    $0x8,%r15
EOF
