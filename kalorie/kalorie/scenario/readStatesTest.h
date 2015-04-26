#ifndef READSTATESTEST_H_
#define READSTATESTEST_H_

#include "../modules/Pin.h"
#include "../modules/Usart.h"

const uint8_t readStatesTest()
{
	Pin::get(4).pullUp();
	for (uint8_t i = 0; i < 60; ++i)
	{
		if (Pin::get(4).isHigh())
			Usart::send(0xff);
		else
			Usart::send(0x00);
		_delay_ms(1000);
	}
	return 0;
}

#endif /* READSTATESTEST_H_ */