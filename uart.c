#include "uart.h"
char reception[100];
char i=0;

void init_uart(void)
{
    /*UART Variables*/
    unsigned char UARTConfig = 0, baud = 0;
    
    /*UART PINS*/
    TRISCbits.RC6 = 0; //TX pin set as output
    TRISCbits.RC7 = 1; //RX pin set as input 
    
    /*Ajout de l'interruption sur le port RX*/
    RCIF = 0; //reset RX pin flag
    RCIP = 0; //Not high priority
    RCIE = 1; //Enable RX interrupt
    PEIE = 1; //Enable pheripheral interrupt (serial port is a pheripheral)
    ei();   //(INTCONbits.GIE = 1)
    
    /*UART Configuration*/
    UARTConfig = USART_TX_INT_OFF & USART_RX_INT_ON & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_BRGH_HIGH ;
    baud=51; //Formula 16(X+1) = Fosc/Baud Rate
    OpenUSART(UARTConfig,baud); //9600
}

void interrupt SerialRxPinInterrupt(void)
{
    unsigned char data;
    //check if the interrupt is caused by RX pin
    if(PIR1bits.RCIF == 1)
    {
    do{    
    while(!DataRdyUSART());// Wait for data to be received

    data = getcUSART();    // Get a character from the USART
    reception[i] = data;
    i++;              
    }while(PIR1bits.RCIF);
    }
}