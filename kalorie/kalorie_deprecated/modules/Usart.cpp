#include "Usart.h"

// inicjalizacja wlasciwosci statycznych klasy Usart
Scenario Usart::scenarios;
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

Usart::Scenario::Scenario(void* &function, const uint8_t &paramsBits)
: function(function), paramsBits(paramsBits)
{
}

void Usart::init()
{
	// wlaczenie transmisji, wlaczenie odbioru, wlaczenie przerwania odbioru
	UCSRB = (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);
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
		if (!newCharReceived)
			continue;
		char charRecv = incomeChar;
		newCharReceived = false;
		processChar(charRecv);
	}
}

void Usart::processChar(const char &charRecv)
{
	if (commandWithArguments)
	{
		if (paramsToRecv > 0)
		{
			params[scenarios[commandWithArguments - 32].paramsBits - paramsToRecv] = charRecv;
			--paramsToRecv;
		}
		else
		{
			params[scenarios[commandWithArguments - 32].paramsBits - paramsToRecv] = charRecv;
			send(commandWithArguments);
		}
	}
	else
	{
		if (scenarios.paramsBits == 0)
		{
			((void (*)())(scenarios[charRecv - 32].function))();
			send(charRecv);
		}
		else
		{
			commandWithArguments = true;
			paramsToRecv = scenarios.paramsBits;
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
	scenarios[id - 32] = fun;
}