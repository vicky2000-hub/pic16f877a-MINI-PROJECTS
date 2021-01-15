#include<pic.h>
#define rw RC0
#define rs RC1
#define en RC2
#define delay for(j=0;j<100000;j++)
int j;
void show(unsigned char *s);
void show1(unsigned char *s1);
void cmd(unsigned char a);
void dat(unsigned char b);

void main()
{
	TRISB0=1;
	TRISD=TRISC0=TRISC1=TRISC2=0;
    cmd(0x38);
    cmd(0x0c);
    cmd(0x80);
    show("detected");
    show1(" non detected");
		
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
if(RB0==1){
void show(unsigned char *s)
{
	while(*s)
	{
		dat(*s++);
		}
		}
		}
else{
	void show1(unsigned char *s1)
{
	while(*s1)
	{
		dat(*s1++);
		}
		}
}		
		
