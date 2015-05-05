/*
 * SimpleMeasurement.h
 *
 * Created: 2015-05-04 21:56:02
 *  Author: Kamil
 */ 


#ifndef SIMPLEMEASUREMENT_H_
#define SIMPLEMEASUREMENT_H_


struct SimpleMeasurement
{
	uint8_t pin: 3;
	uint8_t vref: 1;
};


#endif /* SIMPLEMEASUREMENT_H_ */