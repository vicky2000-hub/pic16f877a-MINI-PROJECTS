#include<pic.H>
void delay();
void main()
{
	TRISB=0x00;
	while(1)
	{
PORTB=0x3F;
delay();
PORTB=0x06;
delay();
PORTB=0x5B;
delay();
PORTB=0x4F;
delay();
PORTB=0x66;
delay();
PORTB=0x6D;
delay();
PORTB=0x7D;
delay();
PORTB=0x07;
delay();
PORTB=0x7F;
delay();
PORTB=0x67;
delay();
}
}
void delay()
{
unsigned int i,j;
for(i=0;i<500;i++)
{
for(j=0;j<500;j++)
{
}
}
}