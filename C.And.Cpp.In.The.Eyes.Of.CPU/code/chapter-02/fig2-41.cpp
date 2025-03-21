#include <stdio.h>
#include <stdlib.h>

void malfunc()
{
    printf("💀💀💀💀");
    exit(4);
}

void func1()
{
    long a[2];
    a[3] = (long) &malfunc;
    a[1] = 1;
    a[0] = 2;
    a[-1] = 3;
    a[-2] = 4;
}

int main()
{
    func1();
    printf("岁月静好✅");
}
