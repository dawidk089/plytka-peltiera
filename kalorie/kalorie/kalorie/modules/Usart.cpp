﻿#include "Usart.h"
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
	UBRRL = USART_UBRRL;
	sei();
}

void Usart::run()
{
	while (true)
	{
		const char &scenarioCode = receive();
		const uint8_t &scenarioParams = scenarios[scenarioCode - 32].paramsBytes;
		for (uint8_t i = 0; i < scenarioParams; ++i)
			params[i] = receive();
		scenarios[scenarioCode - 32].function();
		send(scenarioCode);
	}
}

const char &Usart::receive()
{
	_delay_ms(USART_SLEEP_TIME);
	while (!newCharReceived);
	newCharReceived = false;
	return incomeChar;
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