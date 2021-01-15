#include<pic.h>
void delay(){
unsigned int i;
for(i=0;i<10000;i++){
}
}
void main()
{
	TRISB0=0;
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    TRISB6=0;
	while(1)
{
RB0 = 0;//1
RB1 = 1;
RB2 = 1;
RB3 = 0;
RB4 = 0;
RB5 = 0;
RB6 = 0;
delay();
RB0 = 1;//2
RB1 = 1;
RB2 = 0;
RB3 = 1;
RB4 = 1;
RB5 = 0;
RB6 = 1;
delay();
RB0 = 1;//3
RB1 = 1;
RB2 = 1;
RB3 = 1;
RB4 = 0;
RB5 = 0;
RB6 = 1;
delay();
RB0 = 0;//4
RB1 = 0;
RB2 = 1;
RB3 = 0;
RB4 = 0;
RB5 = 1;
RB6 = 1;
delay();
RB0 = 1;//5
RB1 = 0;
RB2 = 1;
RB3 = 1;
RB4 = 0;
RB5 = 1;
RB6 = 1;
delay();
RB0 = 1;//6
RB1 = 0;
RB2 = 1;
RB3 = 1;
RB4 = 1;
RB5 = 1;
RB6 = 1;
delay();
RB0 = 1;//7
RB1 = 1;
RB2 = 1;
RB3 = 0;
RB4 = 0;
RB5 = 0;
RB6 = 0;
delay();
RB0 = 1;//8
RB1 = 1;
RB2 = 1;
RB3 = 1;
RB4 = 1;
RB5 = 1;
RB6 = 1;
delay();
RB0 = 1;//9
RB1 = 1;
RB2 = 1;
RB3 = 0;
RB4 = 0;
RB5 = 1;
RB6 = 1;
delay();
RB0 = 1;//0
RB1 = 1;
RB2 = 1;
RB3 = 1;
RB4 = 1;
RB5 = 1;
RB6 = 0;
delay();

}
}
