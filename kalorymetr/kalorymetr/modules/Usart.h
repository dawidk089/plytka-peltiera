#ifndef USART_H
#define USART_H

#define F_CPU 11592000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../config/main.h"

struct CharBuffer
{
	char buffer[256];
	uint8_t iterator;
};

class Usart
{
	
public:

	// public members
	static char buffer[CHAR_BUFFER_COMMAND_SIZE];

	// interface
	static void init();
	static void run();
	static void pushFunction(const uint8_t (*fun)(), uint8_t id);
	static void pushText(const char *text, uint8_t pos = 0);
	
private:

	// private properties
	static uint8_t readIter;
	static const uint8_t (*functions[224])();
	
	// private functions
	static void send(char toSend);
	
};

#endif