#include "Pin.h"

// static members

Pin Pin::instances[] =
{
	#include "config/pinout.h"
};

// interface

const uns &Pin::get_addr()
{
	return addr;
}

void Pin::low()
{
	Register::setOff(addr.outState, addrMask);
}

void Pin::high()
{
	Register::setOn(addr.outState, addrMask);
}

const bool Pin::state()
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

Pin(const Pin::Addr &addr, const Register::BIT_NR &addrMask, const bool &isAllowed)
: addr(addr), addrMask(addrMask), isAllowed(isAllowed)
{
}