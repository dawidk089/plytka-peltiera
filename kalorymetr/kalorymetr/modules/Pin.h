#ifndef PIN_H
#define PIN_H

#include "Register.h"

class Pin
{

public:
	
	struct Addr
	{
		Register::ADDR direction;
		Register::ADDR inState;
		Register::ADDR outState;
	};

	void low();
	void high();
	const bool state() const;
	void hi_z();
	void pull_up();
	static Pin &get(const int &index);

private:

	Pin(const Addr &addr, const Register::BIT_NR &addrMask, const bool &isAllowed);
	
	static Pin instances[];
	Addr addr;
	Register::BIT_NR addrMask;
	bool isAllowed;

};

#endif