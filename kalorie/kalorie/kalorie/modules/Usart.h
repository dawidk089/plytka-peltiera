#ifndef USART_H
#define USART_H

#include "../config/main.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

class Usart
{
	
public:

	// public members
	static char buffer[BUFFER_FOR_SCENARIO_SIZE];
	static char incomeChar;
	static bool newCharReceived;

	// interface
	static void init();
	static void run();
	static void pushFunction(const uint8_t (*fun)(), uint8_t id);
	static void pushText(const char *text, uint8_t pos = 0);
	
private:

	// private properties
	static const uint8_t (*functions[224])();
	
	// private functions
	static void send(char toSend);
	
};

#endif