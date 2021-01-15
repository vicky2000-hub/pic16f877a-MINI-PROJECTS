#include<pic.h>
void t0delay();
void main()
{
TRISB=0;
OPTION_REG=0x83;
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
for(i=0;i<1;i++)
{
while(!T0IF)
T0IF=1;
}
}

