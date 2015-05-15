/*
 * asciiTest.h
 *
 * Created: 2015-05-16 00:50:16
 *  Author: Kamil
 */ 


#ifndef ASCIITEST_H_
#define ASCIITEST_H_

#include "../modules/Usart.h"

void asciiTest()
{
	for (uint8_t i = 0; i < 32; ++i)
		Usart::send(i);
}

#endif /* ASCIITEST_H_ */