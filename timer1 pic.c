#include<pic.h>
void t0delay();
void main()
{
TRISB=0;
T1CON = 0x01;
while(1)
{
PORTB = 0xFF;
t0delay();
PORTB = 0x00;
t0delay();
}
}
void t0delay()
{
int i;
for(i=0;i<8;i++)
{
TMR1H=TMR1L=0;
while(!TMR1IF);
TMR1IF=0;
}
}

