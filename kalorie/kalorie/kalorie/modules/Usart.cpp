#include "Usart.h"

// inicjalizacja wlasciwosci statycznych klasy Usart
const uint8_t (*Usart::functions[224])();
char Usart::buffer[CHAR_BUFFER_COMMAND_SIZE];
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
	UCSRB = ((1<<TXEN) | (1<<RXEN) | (1<<RXCIE));
	//nastaw 8-bitowej ramki
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
	// for 9600 baud at 1MHz
	UBRRL = 71;
	sei();
}

void Usart::run()
{
	while (true)
	{
		_delay_ms(USART_SLEEP_TIME);
		if (newCharReceived)
		{
			char charRecv = incomeChar;
			newCharReceived = false;
			if (charRecv >= 32 && functions[charRecv - 32])
			{
				const uint8_t bufferSize = functions[charRecv - 32]();
				send(charRecv);
				for (uint8_t i = 0; i < bufferSize; ++i)
					send(buffer[i]);
			}
		}
	}
}

void Usart::send(char toSend)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = toSend;
}

void Usart::pushFunction(const uint8_t (*fun)(), uint8_t id)
{
	functions[id - 32] = fun;
}

void Usart::pushText(const char *text, uint8_t pos)
{
	while (*text != '\0')
		buffer[pos++] = *text++;
}