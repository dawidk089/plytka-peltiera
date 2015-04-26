/*
 * state_ln.h
 *
 * Created: 2015-04-25 00:54:44
 *  Author: mcmushroom
 */ 


#ifndef STATE_LN_H_
#define STATE_LN_H_

#include <avr/io.h>
#include "../modules/Usart.h"

const uint8_t state_ln()
{
	Usart::buffer[0] = DDRB;
	Usart::buffer[1] = DDRC;
	Usart::buffer[2] = DDRD;
	Usart::buffer[3] = PORTB;
	Usart::buffer[4] = PORTC;
	Usart::buffer[5] = PORTD;
	Usart::buffer[6] = PINB;
	Usart::buffer[7] = PINC;
	Usart::buffer[8] = PIND;
	/*Usart::pushText("\r\n", 9);*/
	Usart::buffer[9] = '\r';
	Usart::buffer[10] = '\n';
	return 11;
}

#endif /* STATE_LN_H_ */