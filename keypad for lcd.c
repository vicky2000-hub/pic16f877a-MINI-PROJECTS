#include<pic.H>
#define rw RC0
#define en RC1
#define rs RC2
#define delay for(j=0;j<1000;j++)
int j;
void lcd_int();
void cmd(unsigned char a); 
void dat(unsigned char b);
void main()
{
	TRISB1=1;
    TRISC0=TRISC1=TRISC2=0;
    TRISD=0;
    
while(1)
{    
if(RB1==1)
  {
	lcd_int();
    dat('w');
    }
else
{
cmd(0x01);
}
}
}
void lcd_int()
{
	cmd(0x38);
	cmd(0x0C);
	cmd(0x01);
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
	