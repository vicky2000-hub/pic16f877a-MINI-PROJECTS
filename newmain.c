
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include <pic16f877a.h>


#define _XTAL_FREQ 8000000

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


short z;


void interrupt I2C_Slave_Read()
{ 
    if(SSPIF == 1)
    {
       SSPCONbits.CKP = 0;
       
       if ((SSPCONbits.SSPOV) || (SSPCONbits.WCOL))
       {
             z = SSPBUF;            // Read the previous value to clear the buffer
             SSPCONbits.SSPOV = 0; // Clear the overflow flag
             SSPCONbits.WCOL = 0;   // Clear the collision bit
             SSPCONbits.CKP = 1;
       }

      if(!SSPSTATbits.D_nA && !SSPSTATbits.R_nW) 
       {
           z = SSPBUF;
           while(!BF);
           PORTD = SSPBUF;
           SSPCONbits.CKP = 1;
           SSPM3 = 0;
       }
       else if(!SSPSTATbits.D_nA && SSPSTATbits.R_nW)
       {
           z = SSPBUF;
           BF = 0;
           SSPBUF = PORTB ;
           SSPCONbits.CKP = 1;
           while(SSPSTATbits.BF);
       }
       
       SSPIF = 0;
    }
}

void I2C_Slave_Init(short address)
{
    SSPSTAT = 0x80;
    SSPADD = address;
    SSPCON = 0x36;
    SSPCON2 = 0x01;
    TRISC3 = 1;
    TRISC4 = 1;
    GIE = 1;
    PEIE = 1;
    SSPIF = 0;
    SSPIE = 1;
}

void main()
{
    nRBPU = 0;
    TRISB = 0xFF;;
    TRISD = 0x00;
    PORTD = 0x00;
    I2C_Slave_Init(0x30);
    while(1);
}