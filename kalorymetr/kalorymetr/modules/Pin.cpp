#include "Pin.h"

// static members

Pin Pin::instances[] =
{
	Pin(PIN1),
	Pin(PIN2),
	Pin(PIN3),
	Pin(PIN4),
	Pin(PIN5),
	Pin(PIN6),
	Pin(PIN7),
	Pin(PIN8),
	Pin(PIN9),
	Pin(PIN10),
	Pin(PIN11),
	Pin(PIN12),
	Pin(PIN13),
	Pin(PIN14),
	Pin(PIN15),
	Pin(PIN16),
	Pin(PIN17),
	Pin(PIN18),
	Pin(PIN19),
	Pin(PIN20),
	Pin(PIN21),
	Pin(PIN22),
	Pin(PIN23),
	Pin(PIN24),
	Pin(PIN25),
	Pin(PIN26),
	Pin(PIN27),
	Pin(PIN28)
};

// interface

const uns &Pin::get_addr()
{
	return addr;
}

void Pin::low(const &OUT_STATE)
{
	rejestr(addr, OUT_STATE) &= ~OUT(addr);
}

void Pin::high()
{
	rejestr(addr, OUT_STATE) |= OUT(addr);
}

const STATE &Pin::state()
{
	return (rejestr(addr, IN_STATE) & OUT(addr));
}

void Pin::hi_z()
{
	pin_in(addr);
	low();
}

void Pin::pull_up()
{
	pin_in(addr);
	high();
}

Pin &Pin::get(const int &index)
{
	if (index > 0 && index < 29)
		return instances[index - 1];
	else
		return instances[0];
}

// hidden

Pin::Pin(const uns &addr)
: addr(addr)
{
}