#include<pic.h>
void main()
{
	TRISB=0x00;
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
    unsigned int i;
	for(i=0;i<1000;i++)
	{
	}
}