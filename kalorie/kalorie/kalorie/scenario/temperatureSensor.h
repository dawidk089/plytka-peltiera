#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

#include "../modules/Usart.h"
#include "../modules/Adc.h"

const uint8_t temperatureSensor()
{
	Adc::configure(Adc::V2_56, 5);
	Adc::RegisterState measurement = Adc::result();
	Usart::buffer[0] = measurement.low;
	Usart::buffer[1] = measurement.high;
	return 2;
}

#endif /* TEMPERATURESENSOR_H_ */