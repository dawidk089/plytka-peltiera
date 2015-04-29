#include "Adc.h"

bool Adc::isConfigured = false;

Adc::RegisterState::RegisterState(const Register::ADDR &low, const Register::ADDR &high)
: low(low), high(high)
{
}

Adc::RegisterState::RegisterState()
: low(0xff), high(0xff)
{
}
/*
void Adc::configure(const SPECIAL_VREF &specialVref, const PRESCALER &prescaler)
{
	startConfigure(specialVref, prescaler);
	isConfigured = true;
}
*/
void Adc::configure(const VREF &vref, const uint8_t &pin, const PRESCALER &prescaler)
{
	startConfigure(vref | (pin & 0x0f), prescaler);
	for (uint8_t i = 0; i < 6; ++i)
		Pin::get(23 + i).pullUp();
	Pin::get(23 + pin).read();
	isConfigured = true;
}

void Adc::startConfigure(const uint8_t &admux, const PRESCALER &prescaler)
{
	if (isConfigured)
	{
		while (ADCSRA & (1<<ADSC));
		ADCSRA &= ~(1<<ADEN);
		_delay_ms(ADC_SLEEP_TIME);
	}
	ADCSRA |= (1<<ADEN) | prescaler;
	ADMUX |= admux;
	sei();
}

const Adc::RegisterState Adc::result()
{
	if (!isConfigured)
		return Adc::RegisterState();
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC));
	return Adc::RegisterState(ADCL, ADCH);
}