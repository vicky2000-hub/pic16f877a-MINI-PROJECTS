#include<pic.h>
void main()
{
TRISB=0x00;
TRISC=0xFF;
while(1)
{
if(RC0==1)
{
RB0=0;
RB1=0;
RB2=0;
RB3=0;
}

else if(RC1==1)
{
RB0=1;
RB1=1;
RB2=1;
RB3=1;
}

else if(RC2==1)
{
RB0=0;
RB1=1;
RB2=0;
RB3=1;
}

else if(RC3==1)
{
RB0=1;
RB1=0;
RB2=1;
RB3=0;
}
else 
{
RB0=0;
RB1=0;
RB2=0;
RB3=0;
}
}
}

