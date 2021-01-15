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

void UART_send_char(char bt)  
{
    while(!TXIF);  // hold the program till TX buffer is free
    TXREG = bt; //Load the transmitter buffer with the received value  (final step 3)
}

void UART_send_string(char* st_pt)
{
    while(*st_pt) //if there is a char
        UART_send_char(*st_pt++); //process it as a byte data (step 2)
}
void main(void)
{
    int get_value;
    
    TRISB = 0x00; //Initialize PortB as output
    Initialize_UART();    //Initialize UART module                    
    
    UART_send_string("UART Module Initialized and active");    // Introductory Tex (step 1)
}