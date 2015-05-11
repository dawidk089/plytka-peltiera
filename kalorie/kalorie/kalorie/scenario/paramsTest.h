/*
 * paramsTest.h
 *
 * Created: 2015-05-11 01:00:24
 *  Author: Kamil
 */ 

#include "../modules/Usart.h"

#ifndef PARAMSTEST_H_
#define PARAMSTEST_H_

void paramsTest()
{
	Usart::send(Usart::getBits(0, 8));
	Usart::send(Usart::getBits(8, 8));
	Usart::send(Usart::getBits(16, 8));
	Usart::send(Usart::getBits(24, 8));
}

#endif /* PARAMSTEST_H_ */