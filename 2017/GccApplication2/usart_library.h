#ifndef usart_library
#define usart_library
#include <avr/io.h>
#include <util/delay.h>


//void ConfigureUART(unsigned int BAUD, unsigned int Double_Or_Not);
void USART_Init( unsigned int baud);
void USART_TransmitString(char *str);
void uart_data_transmit (unsigned char data);

unsigned char uart_data_receive(void);

void USART_InterruptEnable(void);


#endif