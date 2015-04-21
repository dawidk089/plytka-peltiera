#define F_CPU 11059200UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "modules/Pin.h"




int main(void)
{
	//DDRD |= (1<<PD2);	
	
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
		if (counter % 2 == 1)
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
	}
	
	return 1;
}