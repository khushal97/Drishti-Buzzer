/*
 * test_usart.c
 *
 * Created: 26-07-2017 17:45:45
 * Author : admin
 */ 
#include "usart_library.h"

void USART_Init(unsigned int baud)
{
//    sei();
	//Initialize baud Rate(9600)
	UBRR0H=(unsigned char)(baud>>8);
	UBRR0L=(unsigned char)baud;
	//TX RX Enable
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);//|(1<<UCSZ02);
	//Set 8-bit data, Parity disabled
	UCSR0C |= (3<<UCSZ00);
}

/*The function is declared to transmit data.*/
void uart_data_transmit (unsigned char data)
{
	//int UBRRH_VALUE;
	while (!((UCSR0A)&(1<<UDRE0)));
	UDR0 = data;
	
}
/*The function is declared to receive data.*/
unsigned char uart_data_receive(void)
{
	while(!((UCSR0A) & (1<<RXC0)));                   // wait while data is being received
	return UDR0;                                   // return 8-bit data
}



void USART_TransmitString(char *str)//, uint8_t n)
{
	for(unsigned int i=0;i<strlen(str);++i)
	{
		uart_data_transmit(str[i]);
		//_delay_ms(25);
	}
}

void USART_InterruptEnable(void)
{
	UCSR0B|=(1<<RXCIE0);
}
