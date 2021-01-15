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
	TRISB1=1;
	TRISB2=1;
	TRISB3=1;
	TRISC3=0;
	TRISC4=0;
	TRISC5=0;
	TRISC6=0;
	
	TRISD=TRISC0=TRISC1=TRISC2=0;
    cmd(0x38);
    cmd(0x0a);
    cmd(0x01);
while(1)
{
	RC3=1;
	RC4=0;
	RC5=0;
	RC6=0;
if(RB0==1)
{    
    show(" b1");
}
if(RB1==1)
{    
    show(" b2");
}
if(RB2==1)
{    
    show(" b3");
}
if(RB3==1)
{    
    show(" b4");
}

    RC3=0;
	RC4=1;
	RC5=0;
	RC6=0;
if(RB0==1)
{    
    show(" b5");
}
if(RB1==1)
{    
    show(" b6");
}
if(RB2==1)
{    
    show(" b7");
}
if(RB3==1)
{    
    show(" b8");
}
    RC3=0;
	RC4=0;
	RC5=1;
	RC6=0;
if(RB0==1)
{    
    show(" b9");
}
if(RB1==1)
{    
    show(" b10");
}
if(RB2==1)
{    
    show(" b11");
}
if(RB3==1)
{    
    show(" b12");
}
    RC3=0;
	RC4=0;
	RC5=0;
	RC6=1;
if(RB0==1)
{    
    show(" b13");
}
if(RB1==1)
{    
    show(" b14");
}
if(RB2==1)
{    
    show(" b15");
}
if(RB3==1)
{    
    show(" b16");
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
