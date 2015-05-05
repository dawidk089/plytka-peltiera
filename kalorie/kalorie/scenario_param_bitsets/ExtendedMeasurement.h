/*
 * ExtendedMeasurement.h
 *
 * Created: 2015-05-04 22:00:51
 *  Author: Kamil
 */ 


#ifndef EXTENDEDMEASUREMENT_H_
#define EXTENDEDMEASUREMENT_H_


struct ExtendedMeasurement
{
	uint8_t pinPlus: 1;
	uint8_t pinMinus: 1;
	uint8_t vref: 1;
	uint8_t gain: 1;
};


#endif /* EXTENDEDMEASUREMENT_H_ */