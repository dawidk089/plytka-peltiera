/*
 * GainedMeasurement.h
 *
 * Created: 2015-05-04 21:58:07
 *  Author: Kamil
 */ 


#ifndef GAINEDMEASUREMENT_H_
#define GAINEDMEASUREMENT_H_

#include "SimpleMeasurement.h"

struct GainedMeasurement: SimpleMeasurement
{
	uint8_t gain: 1;
};


#endif /* GAINEDMEASUREMENT_H_ */