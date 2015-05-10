#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

#include "../modules/Usart.h"
#include "../modules/Adc.h"

void temperatureSensor()
{
	Adc::configure(Adc::V2_56, 5);
	Adc::RegisterState measurement = Adc::result();
	Usart::send(measurement.low);
	Usart::send(measurement.high);
}

#endif /* TEMPERATURESENSOR_H_ */

