#ifndef USART_H
#define USART_H

#include "../config/main.h"
#include "../config/scenario_param_bitsets_glue.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

class Usart
{
	
public:

	struct Scenario
	{
		Scenario(void* &function, const uint8_t &paramsBits);
		void* function;
		uint8_t paramsBits;
	};

	// public members
	static char incomeChar;
	static bool newCharReceived;

	// interface
	static void init();
	static void run();
	static void send(char toSend);
	static void pushFunction(const Scenario &scenario, uint8_t id);
	
private:

	// hidden functions
	static void processChar(const char &charRecv);

	// private properties
	static Scenario scenarios;
	static uint8_t params[4];
	static uint8_t paramsToRecv;
	static uint8_t commandWithArguments;
	
};

#endif