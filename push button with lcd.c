#include<pic.h>
#define rw RC0
#define rs RC1
#define en RC2
#define delay for(j=0;j<1000;j++)
int j;
void show(unsigned char *s);
void cmd(unsigned char a);
void dat(unsigned char b);

void main()
{
	TRISB0=1;
	TRISD=TRISC0=TRISC1=TRISC2=0;
    cmd(0x38);
    cmd(0x0a);
    cmd(0x01);
while(1)
{
if(RB0==1)
{    
    show(" button presed");
//cmd(0x01);
}
else{
    show(" not pressed");
}		
}
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

void show(unsigned char *s)
{
	while(*s)
	{
		dat(*s++);
		}
		}		
