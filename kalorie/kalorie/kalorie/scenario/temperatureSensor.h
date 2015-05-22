#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

#include "../modules/Usart.h"
#include "../modules/Adc.h"

void temperatureSensor()
{
	Adc::configureSingle(5, Adc::V2_56);
	Adc::Measurement measurement = Adc::measure();
	Usart::send(measurement.low);
	Usart::send(measurement.high);
}

#endif /* TEMPERATURESENSOR_H_ */