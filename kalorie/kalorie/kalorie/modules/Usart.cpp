#include "Usart.h"
#include "Pin.h"

// inicjalizacja wlasciwosci statycznych klasy Usart
Usart::Scenario Usart::scenarios[224];
uint8_t Usart::params[4];
uint8_t Usart::paramsToRecv;
uint8_t Usart::commandWithArguments;
char Usart::incomeChar;
bool Usart::newCharReceived;

// definicja wektora przerwan odbioru danych USART
ISR(USART_RXC_vect)
{
	Usart::incomeChar = UDR;
	Usart::newCharReceived = true;
}

Usart::Scenario::Scenario()
{
}

Usart::Scenario::Scenario(void (*function)(), const uint8_t &paramsBytes)
: function(function), paramsBytes(paramsBytes)
{
}

void Usart::init()
{
	// wlaczenie transmisji, wlaczenie odbioru, wlaczenie przerwania odbioru
	UCSRB = (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);
	//nastaw 8-bitowej ramki
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
	// for 9600 baud at 1MHz
	UBRRL = 95;
	sei();
}

void Usart::run()
{
	while (true)
	{
		_delay_ms(USART_SLEEP_TIME);
		if (!newCharReceived)
			continue;
		char charRecv = incomeChar;
		newCharReceived = false;
		processChar(charRecv);
	}
}

// jeden wielki bajzel, proszę posprzątać!!!
void Usart::processChar(const char &charRecv)
{
	if (commandWithArguments)
	{
		if (paramsToRecv > 0)
		{
			params[scenarios[commandWithArguments - 32].paramsBytes - paramsToRecv] = charRecv;
			--paramsToRecv;
		}
		else
		{
			params[scenarios[commandWithArguments - 32].paramsBytes - paramsToRecv] = charRecv;
			send(commandWithArguments);
		}
	}
	else
	{
		Pin::get(22).setHigh();
		if (scenarios[charRecv - 32].paramsBytes == 0)
		{
			scenarios[charRecv - 32].function();
			send(charRecv);
			commandWithArguments = 0;
		}
		else
		{
			Pin::get(23).setHigh();
			//if ()
			commandWithArguments = charRecv;
			paramsToRecv = scenarios[commandWithArguments - 32].paramsBytes;
		}		
	}
}

void Usart::send(char toSend)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = toSend;
}

void Usart::pushFunction(const Scenario &scenario, uint8_t id)
{
	scenarios[id - 32] = scenario;
}

const bool &Usart::getBit(const uint8_t &nr)
{
	return params[nr<<3] & (1 << (nr - (nr<<3>>3)));
}

const uint32_t &Usart::getBits(const uint8_t &start, const uint8_t &size)
{
	uint32_t bits;
	for (uint8_t i = 0; i < size; ++i)
		bits += (getBit(start + i) << i);
	return bits;
}