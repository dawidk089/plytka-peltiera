#define F_CPU 11059200UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "modules/Pin.h"
#include "modules/usart_vect.h"




int main(void)
{
		UCSRA=0;//podwójna prêdkoœæ
		//zerowanie flag bledu, flag odbioru i nadania, u2x... i will write soon
		UCSRB = ((1<<TXEN) | (1<<RXEN) | (1<<RXCIE)); // wlaczenie transmisji i odbioru, (przerwania)
		UCSRC=(1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
		UCSRC &= ~(1 << URSEL);
		UBRRH=0;
		UBRRL=71; // for 9600 baud at 1MHz
		sei();
	
	for( int i=0; i<30; ++i){
	while(!(UCSRA & (1<<UDRE)));
	UDR = char('x');
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
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
	*/
	return 1;
}