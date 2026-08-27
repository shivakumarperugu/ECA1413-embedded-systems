#include <reg51.h>
#include <stdio.h>

char putchar(char c)
{
    SBUF = c;
    while(TI == 0);
    TI = 0;
    return c;
}

void main(void)
{
    SCON = 0x50;
    TMOD = 0x20;
    TH1  = 0xFD;
    TR1  = 1;
    TI   = 1;

    while(1)
    {
        printf("Hello World!\n");
    }
}