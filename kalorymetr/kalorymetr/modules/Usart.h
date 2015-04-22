#ifndef USART_H
#define USART_H

#include "config/main.h"

class Usart
{
	
public:

	static void init();
	static void run();
	static void pushFunction(const char *(*fun)(void), uint8_t id);
	
private:

	static uint8_t readIter;
	static const char *(*functions[224])(void);
	
	static void send(char toSend)
	
};

#endif