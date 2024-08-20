#include<pic.h>
#define rw RC0
#define rs RC1
#define en RC2
#define delay for(j=0;j<100000;j++)
int j;

void cmd(unsigned char a);
void dat(unsigned char b);

void main()
{
	TRISD=TRISC0=TRISC1=TRISC2=0;
    cmd(0x38);
    cmd(0x0c);
    cmd(0x80);
    dat('w');
		
}
void cmd(unsigned char a)
{
	PORTD=a;
	rs=0;
	rw=0;
	en=1;
	delay;
	en=0;
}
void dat(unsigned char b)
{
	PORTD=b;
	rs=1;
	rw=0;
	en=1;
	delay;
	en=0;
}
