#include "Usart.h"

// inicjalizacja wlasciwosci statycznych klasy Usart
void (*Usart::functions[224])();
char Usart::incomeChar;
bool Usart::newCharReceived;

// definicja wektora przerwan odbioru danych USART
ISR(USART_RXC_vect)
{
	Usart::incomeChar = UDR;
	Usart::newCharReceived = true;
}

void Usart::init()
{
	// wlaczenie transmisji, wlaczenie odbioru, wlaczenie przerwania odbioru
	UCSRB = (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);
	//nastaw 8-bitowej ramki
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
	// for 9600 baud at 1MHz
	UBRRL = 6;
	sei();
}

void Usart::run()
{
	//petla glowna programu
	while (true)
	{
		PORTC |= (1<<PC0); _delay_ms(1000); PORTC &= ~(1<<PC0); _delay_ms(1000);
		_delay_ms(USART_SLEEP_TIME);
		if (!newCharReceived)
			continue;
		char charRecv = incomeChar;
		newCharReceived = false;
		if (charRecv >= 32 && functions[charRecv - 32])
		{
			functions[charRecv - 32]();
			send(charRecv);
			//_delay_ms(1000);
		}
	}
}

void Usart::send(char toSend)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = toSend;
}

void Usart::pushFunction(void (*fun)(), uint8_t id)
{
	functions[id - 32] = fun;
}