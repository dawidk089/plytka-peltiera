#ifndef ADC_H_
#define ADC_H_

#include "../config/main.h"
#include "Usart.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Pin.h"

class Adc
{

public:

	enum VREF
	{
		EXT = 0x00,
		AVCC = 0x40,
		V2_56 = 0xc0
	};

	enum SPECIAL_VREF
	{
		VGB = 0x0e,
		GND = 0x0f
	};
	
	enum PRESCALER
	{
		_2 = 0x01,
		_4 = 0x02,
		_8 = 0x03,
		_16 = 0x04,
		_32 = 0x05,
		_64 = 0x06,
		_128 = 0x07
	};
	
	struct RegisterState
	{
		RegisterState(const Register::ADDR &low, const Register::ADDR &high);
		RegisterState();
		uint8_t low;
		uint8_t high;
	};

	static void configure(const VREF &vref, const uint8_t &pin, const PRESCALER &prescaler = _64);
	static const RegisterState result();

private:

	static bool isConfigured;
	
	static void startConfigure(const uint8_t &admux, const PRESCALER &prescaler);

};

#endif /* ADC_H_ */