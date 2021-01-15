#include<pic.h>
void delay();
void main()
{
TRISD=0x00000000;
while(1)
{
PORTB=0xff;
delay();
PORTB=0x00;
delay();
}
}
void delay()
{
unsigned int i,j;
for(i=0;i<=1000;i++)
{
for(j=0;j<=100000;j++)
	{
		}
}
}
