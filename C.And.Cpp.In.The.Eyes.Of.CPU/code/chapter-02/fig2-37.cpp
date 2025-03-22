#include <stdio.h>

void func1()
{
    long a[2];
    a[1] = 1;
    a[0] = 2;
    a[-1] = 3;
    a[-2] = 4;
}

void func2()
{
    long b[4];
    b[3] = 1;
    b[2] = 2;
    b[1] = 3;
    b[0] = 4;
}

