#ifndef STATE_H
#define STATE_H

#include <avr/io.h>
#include "../modules/Usart.h"

const uint8_t state()
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
	return 9;
}

#endif