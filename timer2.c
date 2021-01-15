#include<pic.h>
void t2delay();
void main()
{
TRISB=0;
T2CON =0x04;
while(1)
{
PORTB=0xFF;
t2delay();
PORTB=0x00;
t2delay();
}
}
void t2delay()
{
int i;
for(i=0;i<8;i++)
{
while(!TMR2IF);
TMR2IF=0;
}
}