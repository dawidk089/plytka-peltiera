#ifndef PIN_H
#define PIN_H

#include <avr/io.h>
#include "Register.h"




class Pin
{

public:
	
	class Addr
	{
		public:
			Register::ADDR & direction;
			Register::ADDR & inState;
			Register::ADDR & outState;
	
			Addr( Register::ADDR &n_direction,  Register::ADDR &n_inState,  Register::ADDR &n_outState)
			: direction(n_direction), inState(n_inState), outState(n_outState)	{}
	};

	void low();
	void high();
	const bool state() const; //#FIXME! bool ---> enum HIGH, LOW
	void hi_z();
	void pull_up();
	static Pin &get(const int &index);

private:

	Pin(const Addr &n_addr, const int &n_addrMask, const bool &n_isAllowed);
	
	static Pin instances[];
	Addr addr;
	Register::BIT_NR addrMask;
	bool isAllowed;

};

#endif