#include <reg51.h>
#include <stdio.h>

char ch;
bit dataReady = 0;

void serial_ISR(void) interrupt 4
{
    if(RI)
    {
        RI = 0;
        ch = SBUF;
        dataReady = 1;
    }
}

void delay(void)
{
    unsigned int i;
    for(i=0;i<50000;i++);
}

void main(void)
{
    SCON = 0x50;
    TMOD = 0x20;
    TH1  = 0xFD;
    TR1  = 1;

    IE = 0x90;

    TI = 1;

    while(1)
    {
        printf("Hello World\n");

        if(dataReady)
        {
            printf("Interrupt Received : %c\n", ch);
            dataReady = 0;
        }

        delay();
    }
}