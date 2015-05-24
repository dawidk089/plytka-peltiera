#ifndef VOLTOMETER_H_
#define VOLTOMETER_H_

#include "../modules/Usart.h"
#include "../modules/Adc.h"
#include "../modules/Pin.h"

/************************************************************************
#kodowanie parametrow:                            
   -3: id_pin 0-7
   -1: voltage_references 0-1[enum: 2,56;Vcc]
************************************************************************/ 

void voltometer()
{
	uint8_t adcPinNr = Usart::getBits(0,3);
	if( getBit(4) )	Adc::configureSingle(adcPinNr, Adc::VCC);
	else Adc::configureSingle(adcPinNr, Adc::V2_56);
	
	Adc::Measurement measurement = Adc::measure();
	Usart::send(measurement.high);
	Usart::send(measurement.low);
}

#endif /* VOLTOMETER_H_ */

//Adc::configureGained(const Adc::PIN_PAIR &pinPair, const bool &isCallibration, const Adc::GAIN &gain, const Adc::VREF &vref, const Adc::PRESCALER &prescaler)