#include <pic.h>
#define _XTAL_FREQ 20000000
#define Baud_rate 9600

void Initialize_UART(void)
{    
TRISC6 = 0; // TX Pin set as output
TRISC7 = 1; // RX Pin set as input
SPBRG = ((_XTAL_FREQ/16)/Baud_rate) - 1;
BRGH  = 1;  // for high baud_rate
SYNC  = 0;    // Asynchronous
SPEN  = 1;    // Enable serial port pins
TXEN  = 1;    // enable transmission
CREN  = 1;    // enable reception
TX9   = 0;    // 8-bit reception selected
RX9   = 0;    // 8-bit reception mode selected
}

char UART_get_char()   
{
    if(OERR) // check for Error 
    {
        CREN = 0; //If error -> Reset 
        CREN = 1; //If error -> Reset 
    }
    
    while(!RCIF);  // hold the program till RX buffer is free
    
    return RCREG; //receive the value and send it to main function
}


void main(void)
{
    int get_value;
    
    TRISB = 0x00;
    Initialize_UART();    //Initialize UART module                    
    
    
    
    while(1) //Infinite loop
    {
      get_value = UART_get_char(); 
        
        if (get_value == '1') //If the user sends "1"
        {
            RB3=1; //Turn on LED
             }
        
        if (get_value == '0') //If the user sends "0"
        {
           RB3=0; //Turn off LED
           }
       
    }
}

