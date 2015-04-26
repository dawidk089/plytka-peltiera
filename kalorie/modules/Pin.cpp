#include "Pin.h"

// static members

Pin Pin::instances[] =
{
	#include "../config/pinout.h"
};

// interface

void Pin::low()
{
	Register::setOn(addr.direction, addrMask);
	Register::setOff(addr.outState, addrMask);
}

void Pin::high()
{
	Register::setOn(addr.direction, addrMask);
	Register::setOn(addr.outState, addrMask);
}

const bool Pin::state() const
{
	return Register::state(addr.inState, addrMask);
}

void Pin::hi_z()
{
	Register::setOff(addr.direction, addrMask);
	low();
}

void Pin::pull_up()
{
	Register::setOff(addr.direction, addrMask);
	high();
}

Pin &Pin::get(const int &index)
{
	if (index > 0 && index < CONFIG_PINOUT_COUNT + 1 && instances[index - 1].isAllowed)
		return instances[index - 1];
	else
		return instances[0];
}

// hidden

Pin::Pin(const Pin::Addr &n_addr, const int &n_addrMask, const bool &n_isAllowed)
: addr(n_addr), addrMask(n_addrMask), isAllowed(n_isAllowed)
{
}