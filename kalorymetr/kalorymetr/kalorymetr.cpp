#define F_CPU 11059200UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Pin.h"

int main(void)
{
	/*DDRD |= (1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7);
	PORTD |= (1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7);
	DDRB |= (1<<PB0);
	PORTB |= (1<<PB0);*/
	
	Pin::get(4).pull_up();
	Pin::get(5).pull_up();
	Pin::get(6).pull_up();
	Pin::get(11).pull_up();
	Pin::get(12).pull_up();
	Pin::get(13).pull_up();
	Pin::get(14).pull_up();
	
	int counter = 0;
	while(1)
	{
		if (counter % 2 == 0)
		{
			Pin::get(4).high();
			Pin::get(5).high();
			Pin::get(6).high();
			Pin::get(11).high();
			Pin::get(12).high();
			Pin::get(13).high();
			Pin::get(14).high();
		}
		if (counter % 2 == 0)
		{
			Pin::get(4).low();
			Pin::get(5).low();
			Pin::get(6).low();
			Pin::get(11).low();
			Pin::get(12).low();
			Pin::get(13).low();
			Pin::get(14).low();
		}
		++counter;
		_delay_ms(1000);
		//PORTD ^= (1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7);
		//PORTB ^= (1<<PB0);
	}
	
	return 1;
}