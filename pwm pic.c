#include<pic.h>
void delay(int cnt)
{
    while (cnt--);
}

int main() {
    char dutyCycle = 0;
	TRISC = 0x00;
 	CCP2CON =CCP1CON = 0x0F;
    PR2 = 100;      
    CCPR1L=CCPR2L=50;
  
    TMR2ON = 1;     


    while (1) {
        for (dutyCycle = 0; dutyCycle < 100; dutyCycle++) 
        {
            CCPR1L =dutyCycle;            
			delay(10000);
        }

        for (dutyCycle = 100; dutyCycle > 0; dutyCycle--) 
        {
            CCPR2L=dutyCycle;
            delay(10000);
        }
    }
}