#include<pic.h>
#define delay for (i=0;i<=1000;i++)
#define rs RC0
#define rw RC1
#define en RC2
void adc();
void lcd_int();
void cmd(unsigned int a);
void data(unsigned char b);
void show(unsigned char *s);
int i;
void main()
{
TRISB=TRISC=0;
TRISA0=1;
lcd_int();
show("adc value");
while(1)
{
cmd(0x8c);
adc();
}
}
void lcd_int()
{
cmd(0x38);
cmd(0x0c);
cmd(0x06);
cmd(0x80);
}
void cmd (unsigned int a)
{
PORTB=a;
rs=0;
rw=0;
en=1;
delay{}
en=0;
}
void data (unsigned char b)
{
PORTB=b;
rs=1;
rw=0;
en=1;
delay{}
en=0;
}
void show(unsigned char *s)
{
while(*s){
data(*s++);
}
}
void adc()
{
unsigned int adcval;
ADCON0=0xc0;
ADCON1=0x85;
while(GO_DONE);
adcval =((ADRESH<<8)|(ADRESL));// 8 bit data
adcval=(adcval/3)-1;//
data(((adcval/1000)+48));//9
data(((adcval/100)%10)+48);//99
data(((adcval/10)%10)+48);// 999
data((adcval/10)+48);//1023 print
}
