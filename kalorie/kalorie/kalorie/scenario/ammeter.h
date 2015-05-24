#ifndef AMMETER_H_
#define AMMETER_H_

#include "../modules/Usart.h"
#include "../modules/Adc.h"
#include "../modules/Pin.h"

/************************************************************************
#kodowanie parametrow:                            
   -3: id_pin 0-7
   -1: voltage_references 0-1[enum: 2,56;Vcc]
************************************************************************/ 

void ammeter()
{
	Adc::configureGained(
		Usart::getBit(0) ? Adc::_3_2 : Adc::_1_0,
		Usart::getBit(2) ? Adc::_200x : Adc::_10x,
		Usart::getBit(1) ? Adc::VCC : Adc::V2_56
	);	
	Adc::Measurement measurement = Adc::measure();
	Usart::send(measurement.high);
	Usart::send(measurement.low);
}

#endif /* VOLTOMETER_H_ */

//Adc::configureGained(const Adc::PIN_PAIR &pinPair, const bool &isCallibration, const Adc::GAIN &gain, const Adc::VREF &vref, const Adc::PRESCALER &prescaler)