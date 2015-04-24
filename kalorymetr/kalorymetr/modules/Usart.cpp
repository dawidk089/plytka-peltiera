#include "Usart.h"

// tworzenie instancji struktury CharBuffer
CharBuffer charBuffer;

// definicja wektora przerwan odbioru danych USART
ISR(USART_RXC_vect)
{
	charBuffer.buffer[charBuffer.iterator] = UDR;
	++charBuffer.iterator;
	charBuffer.buffer[charBuffer.iterator] = '\0';
}

// inicjalizacja wlasciwosci statycznych klasy Usart
uint8_t Usart::readIter;
const uint8_t (*Usart::functions[224])();
char Usart::buffer[CHAR_BUFFER_COMMAND_SIZE];

void Usart::init()
{
	UCSRB = ((1<<TXEN) | (1<<RXEN) | (1<<RXCIE)); // wlaczenie transmisji, wlaczenie odbioru, wlaczenie przerwania odbioru
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0); //nastaw 8-bitowej ramki
	UBRRL = 71; // for 9600 baud at 1MHz
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
			if (charRecv >= static_cast<int>(32) && functions[charRecv - 32])
			{
				int bufferSize = functions[charRecv - 32]();
				send(charRecv);
				for (uint8_t i = 0; i < bufferSize; ++i)
					send(buffer[i]);
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

void Usart::pushFunction(const uint8_t (*fun)(), uint8_t id)
{
	functions[id - 32] = fun;
}

void Usart::pushText(const char *text, uint8_t pos)
{
	while (*text != '\0')
		buffer[pos++] = *text++;
}