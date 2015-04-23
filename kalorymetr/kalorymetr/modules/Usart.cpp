#include "Usart.h"

void Usart::init()
{
	UCSRB = ((1<<TXEN) | (1<<RXEN) | (1<<RXCIE)); // wlaczenie transmisji, wlaczenie odbioru, wlaczenie przerwania odbioru
	UCSRC=(1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0); //nastaw 8-bitowej ramki
	UBRRL=71; // for 9600 baud at 1MHz
	sei();
}

void Usart::run()
{
	while (true)
	{
		_delay_ms(USART_SLEEP_TIME);
		char charRecv = charBuffer.buffer[readIter];
		if (charRecv != '\0')
		{
			if (charRecv >= static_cast<int>(32))
			{
				send(charRecv);
				const char *funRecv = functions[charRecv - 32]();
				while (funRecv != '\0')
					send(*funRecv++);
			}
			++readIter;
		}
	}
}

void Usart::send(char toSend)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = toSend;
}

void Usart::pushFunction(const char *(*fun)(void), uint8_t id)
{
	functions[id - 32] = fun;
}