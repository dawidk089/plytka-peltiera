/*
 * usart_vect.h
 *
 * Created: 2015-04-22 02:54:35
 *  Author: mcmushroom
 */ 


#ifndef USART_VECT_H_
#define USART_VECT_H_

#include <avr/interrupt.h>

//globalna strukturka do USART'a

struct CharBuffer{
	uint8_t iterator;
	char buffer[256];
} charBuffer;


//definicja przerwania RxD 

ISR(USART_RXC_vect)
{
	charBuffer.buffer[charBuffer.iterator] = UDR;
	++charBuffer.iterator;
	charBuffer.buffer[charBuffer.iterator] = '\0';
}

//wysyl ramki wzglednie char

/*
while(!(UCSRA & (1<<UDRE)));
UDR = char(1);
*/

//inicjalizacja USART'a

/*
UCSRB = ((1<<TXEN) | (1<<RXEN) | (1<<RXCIE)); // wlaczenie transmisji, wlaczenie odbioru, wlaczenie przerwania odbioru
UCSRC=(1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0); //nastaw 8-bitowej ramki
UBRRL=71; // for 9600 baud at 1MHz
sei();
*/


#endif /* USART_VECT_H_ */