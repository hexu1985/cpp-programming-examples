#include <8051.h>

void timer_ISR (void) __interrupt(1)
{
    P0_0 = !P0_0;
}

void main(void) 
{
    TMOD = 0x02;
    TH0 = 0xa3;
    TL0 = 0x0;
    TR0 = 1;
    EA = 1;
    while (1);
}
