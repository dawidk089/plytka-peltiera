#ifndef PIN_H
#define PIN_H

#include <avr/io.h>
#include "Register.h"

class Pin
{

public:

	void low();
	void high();
	const bool isHigh() const;
	void hi_z();
	void pull_up();
	static Pin &get(const uint8_t &index);

private:

	Pin(const uint8_t &nr, Register::ADDR &direction, Register::ADDR &inState, Register::ADDR &outState, const int &n_addrMask, const bool &n_isAllowed);
	
	static Pin instances[];
	uint8_t nr;
	Register::ADDR &direction;
	Register::ADDR &inState;
	Register::ADDR &outState;
	Register::BIT_NR addrMask;
	bool isAllowed;

};

#endif