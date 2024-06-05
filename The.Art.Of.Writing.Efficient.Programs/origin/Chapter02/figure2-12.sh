#!/bin/bash

set -x
cat <<EOF
Samples: 315  of event 'cycles', 4000 Hz, Event count (approx.): 337037176
compare  /home/hexu/git/The.Art.Of.Writing.Efficient.Programs/Chapter02/example [Percent: local period]
Percent│                                                                                                                                                                           ▒
       │                                                                                                                                                                           ▒
       │    Disassembly of section .text:                                                                                                                                          ▒
       │                                                                                                                                                                           ▒
       │    0000000000401270 <compare(char const*, char const*, unsigned int)>:                                                                                                    ▒
       │    _Z7comparePKcS0_j():                                                                                                                                                   ▒
       │    // Comparison function for substring sort                                                                                                                              ▒
       │    bool compare(const char* s1, const char* s2, unsigned int l) {                                                                                                         ▒
       │      xor    %eax,%eax                                                                                                                                                     ▒
       │    if (s1 == s2) return false;                                                                                                                                            ▒
       │      cmp    %rsi,%rdi                                                                                                                                                     ▒
       │    ↓ je     28                                                                                                                                                            ▒
       │      test   %edx,%edx                                                                                                                                                     ▒
       │    ↓ je     28                                                                                                                                                            ▒
       │    for (unsigned int i1 = 0, i2 = 0; i1 < l; ++i1, ++i2) {                                                                                                                ▒
       │      mov    %edx,%eax                                                                                                                                                     ▒
       │      xor    %ecx,%ecx                                                                                                                                                     ▒
       │      nop                                                                                                                                                                  ▒
       │    if (s1[i1] != s2[i2]) return s1[i1] > s2[i2];                                                                                                                          ▒
       │10:┌─→movzbl (%rsi,%rcx,1),%edx                                                                                                                                            ▒
       │   │  cmp    %dl,(%rdi,%rcx,1)                                                                                                                                             ▒
       │   │↓ jne    25                                                                                                                                                            ▒
       │   │for (unsigned int i1 = 0, i2 = 0; i1 < l; ++i1, ++i2) {                                                                                                                ▒
 61.33 │   │  add    $0x1,%rcx                                                                                                                                                     ▒
       │   ├──cmp    %rcx,%rax                                                                                                                                                     ▒
 38.35 │   └──jne    10                                                                                                                                                            ▒
       │      xor    %eax,%eax                                                                                                                                                     ▒
       │    ← retq                                                                                                                                                                 ▒
       │    if (s1[i1] != s2[i2]) return s1[i1] > s2[i2];                                                                                                                          ▒
       │25:   setg   %al                                                                                                                                                           ▒
  0.32 │28: ← retq
EOF
