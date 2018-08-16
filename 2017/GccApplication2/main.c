/*
 * GccApplication2.c
 *
 * Created: 01-09-2017 18:32:00
 * Author : admin
 */ 
/*
 * GccApplication4.c
 *
 * Created: 15-08-2017 14:59:00
 * Author : admin
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include "usart_library.h"

unsigned int i=3;
int BuzzerData[7];
int j;

int main(void)
{
	for(j=0;j<7;++j)
	BuzzerData[j] = 0;
	
	USART_Init(12);
	
	DDRE &=~((1<<PINE4)|(1<<PINE5)|(1<<PINE6)|(1<<PINE7));
	DDRF|=(1<<PINF0)|(1<<PINF2)|(1<<PINF4)|(1<<PINF6);
	PORTF &=~((1<<PINF0)|(1<<PINF2)|(1<<PINF4)|(1<<PINF6));
	PORTF|=(1<<PINF0)|(1<<PINF2)|(1<<PINF4)|(1<<PINF6);
	EIMSK|=(1<<INT4)|(1<<INT5)|(1<<INT6)|(1<<INT7);
	EICRB|=(1<<ISC40)|(1<<ISC41)|(1<<ISC50)|(1<<ISC51)|(1<<ISC60)|(1<<ISC61)|(1<<ISC70)|(1<<ISC71);
	UCSR0B|=(1<<RXCIE0);
	
	sei();
    
	while (1) 
    {
		
    }`
}


ISR(INT4_vect)//Buzzer1
{   
	if(i<7)
	{
		if((BuzzerData[i-1]==1)||(BuzzerData[i-3]==1)||(BuzzerData[i-2]==1))
		BuzzerData[i]=0;
		else
		{BuzzerData[i]=1;
	    i++;
		}
		
	}
		
		
	
	uart_data_transmit('A');
	uart_data_transmit(BuzzerData[3]+'0');
	uart_data_transmit(BuzzerData[4]+'0');
	uart_data_transmit(BuzzerData[5]+'0');
	uart_data_transmit(BuzzerData[6]+'0');
	//USART_TransmitString(BuzzerData);
	uart_data_transmit('B');
	
}
ISR(INT5_vect)//Buzzer2
{  
	if(i<7)
	{
		if((BuzzerData[i-1]==2)||(BuzzerData[i-3]==2)||(BuzzerData[i-2]==2))
		BuzzerData[i]=0;
		else
		{BuzzerData[i]=2;
			i++;
		}
		
	}
	
	
	uart_data_transmit('A');
	uart_data_transmit(BuzzerData[3]+'0');
	uart_data_transmit(BuzzerData[4]+'0');
	uart_data_transmit(BuzzerData[5]+'0');
	uart_data_transmit(BuzzerData[6]+'0');
	uart_data_transmit('B');
	}

ISR(INT6_vect)
{  
	if(i<7)
	{
		if((BuzzerData[i-1]==3)||(BuzzerData[i-3]==3)||(BuzzerData[i-2]==3))
		BuzzerData[i]=0;
		else
		{BuzzerData[i]=3;
			i++;
		}
		
	}
	
	uart_data_transmit('A');
	uart_data_transmit(BuzzerData[3]+'0');
	uart_data_transmit(BuzzerData[4]+'0');
	uart_data_transmit(BuzzerData[5]+'0');
	uart_data_transmit(BuzzerData[6]+'0');
	//USART_TransmitString(BuzzerData);
	uart_data_transmit('B');
}
ISR(INT7_vect)//Buzzer4
{

	if(i<7)
	{
		if((BuzzerData[i-1]==4)||(BuzzerData[i-3]==4)||(BuzzerData[i-2]==4))
		BuzzerData[i]=0;
		else
		{BuzzerData[i]=4;
			i++;
		}
		
	}
	
	uart_data_transmit('A');
	uart_data_transmit(BuzzerData[3]+'0');
	uart_data_transmit(BuzzerData[4]+'0');
	uart_data_transmit(BuzzerData[5]+'0');
	uart_data_transmit(BuzzerData[6]+'0');
	uart_data_transmit('B');
}
ISR(USART0_RX_vect)//After a round or so
{
	char receive_data = uart_data_receive();
	if(receive_data == '0')
	{
	i=3;
	BuzzerData[3]=0;
	BuzzerData[4]=0;
	BuzzerData[5]=0;
	BuzzerData[6]=0;
	//USART_TransmitString("REC");
	PORTF &=~((1<<PINF0)|(1<<PINF2)|(1<<PINF4)|(1<<PINF6));
	}
if(receive_data == '1')
	PORTF|=((1<<PINF0)|(1<<PINF2)|(1<<PINF4)|(1<<PINF6));
}

