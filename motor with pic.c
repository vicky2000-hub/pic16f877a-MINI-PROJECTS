#include<pic.h>
void main()
{
TRISC0=0;//output declaration
TRISC1=0;
TRISC2=0;
TRISC3=0;
//TRISD4=0;

TRISB0=1;//input declaration
TRISB1=1;
TRISB2=1;
TRISB3=1;
TRISB4=1;
while(1)
{
if(RB0==1)
{
RC0=1;
RC1=0;
RC2=1;
RC3=0;
}
else if(RB1==1)
{
RC0=0;
RC1=1;
RC2=0;
RC3=1;
}
else if(RB2==1)
{
RC0=1;
RC1=0;
RC2=0;
RC3=0;
}
else if(RB3==1)
{
RC0=0;
RC1=0;
RC2=1;
RC3=0;
}
else
{
RC0=0;
RC1=0;
RC2=0;
RC3=0;
}
}
}