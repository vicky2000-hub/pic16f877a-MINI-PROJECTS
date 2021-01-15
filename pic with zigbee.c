#include <pic.h>
#define rs =RC1;
#define rw =RC0
#define e  =RC2;
#define r1 = RB0;
#define r2 = RB1;
#define r3 = RB2;
#define r4 = RB3;
#define c1 = RB4;
#define c2 = RB5;
#define c3 = RB6;
#define c4 = RB7;
void lcd_send_data(char dat);
void lcd_send_cmd(char cmd);
void string(unsigned char *s);
//void summa();
//void lcd_print();
//void show(unsigned char *s);
void delay();
void main()
{
TRISB0=TRISB1=TRISB2=TRISB3=0;//out
TRISB4=TRISB5=TRISB6=TRISB7=1;//in
TRISC=0;
TRISD=0;
	lcd_send_cmd(0x01);
	lcd_send_cmd(0x0c);
	//lcd_print();
	while(1)
	{
		r1=0,r2=1,r3=1,r4=1;
		if(c1==0)
		{
			
			  lcd_send_cmd(0x01);
				lcd_send_data('1');
				
			delay();
			
		}
		else if(c2==0)
		{
//			while(1)
			  lcd_send_cmd(0x01);
				lcd_send_data('2');
				
			delay();
	//		}
		}
		else if(c3==0)
		{
		//	while(1)
		//	{
			lcd_send_cmd(0x01);
				lcd_send_data('3');
				
			delay();
			//}
		}
		else if(c4==0)
		{
			//while(1)
		//	{
			lcd_send_cmd(0x01);
				lcd_send_data('4');
				
			delay();
			//}
		}
		//delay();
		r1=1,r2=0,r3=1,r4=1;
		if(c1==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				lcd_send_data('5');
			
			delay();
			//}
		}
		else if(c2==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				lcd_send_data('6');
				
			delay();
			//}
		}
		else if(c3==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				lcd_send_data('7');
				
			delay();
			//}
		}
		else if(c4==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				lcd_send_data('8');
	
			delay();
			//}
		}
		//delay();
		r1=1,r2=1,r3=0,r4=1;
		if(c1==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				lcd_send_data('9');
				
			delay();
			//}
		}
		else if(c2==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				string("10");
		
			delay();
			//}
		}
		else if(c3==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				string("11");
				
			delay();
			//}
		}
		else if(c4==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				string("12");
				
			delay();
			//}
		}
		//delay();
		r1=1,r2=1,r3=1,r4=0;
		if(c1==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				string("13");
			
			delay();
			//}
		}
		else if(c2==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				string("14");

			delay();
			//}
		}
		else if(c3==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				string("15");
		
			delay();
			//}
		}
		else if(c4==0)
		{
			//while(1)
			//{
			lcd_send_cmd(0x01);
				string("16");
				
			delay();
			//}
		}
		//delay();
}
}
void lcd_send_cmd(char cmd)
{
	P3=cmd;
	rs=0;
	rw=0;
	e=1;
	delay();
	e=0;
}
void lcd_send_data(char dat)
{
	P3=dat;
	rs=1;
	rw=0;
	e=1;
	delay();
	e=0;
}
void delay()
{ int unsigned i,j;
	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;j++)
		{}
		}
}
void string(unsigned char *s)
{
	while(*s)
	{
		lcd_send_data(*s++);
	}
}
