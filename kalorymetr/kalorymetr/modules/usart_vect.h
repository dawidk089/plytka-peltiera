/*
 * usart_vect.h
 *
 * Created: 2015-04-22 02:54:35
 *  Author: mcmushroom
 */ 


#ifndef USART_VECT_H_
#define USART_VECT_H_

struct CharBuffer{
	uint8_t iterator;
	char buffer[256];
}charBuffer;





ISR(USART_RXC_vect)
{
	charBuffer.buffer[charBuffer.iterator] = UDR;
	++charBuffer.iterator;
	charBuffer.buffer[charBuffer.iterator] = '\0';
}


/*
while(!(UCSRA & (1<<UDRE)));
UDR = char(1);
*/

#endif /* USART_VECT_H_ */