#ifndef USART_H
#define USART_H

#define F_CPU 11592000UL


#include <avr/io.h>
#include <util/delay.h>
#include "usart_vect.h"
#include "../scenario/commend32.h"
#include "../config/main.h"


class Usart
{
	
public:

	static void init();
	static void run();
	static void pushFunction(const char *(*fun)(void), uint8_t id);
	
private:

	static uint8_t readIter;
	static const char *(*functions[224])(void);
	
	static void send(char toSend);
	
};

#endif