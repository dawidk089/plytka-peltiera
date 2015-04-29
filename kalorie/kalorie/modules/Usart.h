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
	static char incomeChar;
	static bool newCharReceived;

	// interface
	static void init();
	static void run();
	static void send(char toSend);
	static void pushFunction(void (*fun)(), uint8_t id);
	
private:

	// private properties
	static void (*functions[224])();
	
};

#endif