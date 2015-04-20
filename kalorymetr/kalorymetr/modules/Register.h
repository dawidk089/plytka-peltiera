/*
 * Register.h
 *
 * Created: 2015-04-20 02:50:48
 *  Author: Kamil
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

class Register
{
	
public:
	
	typedef volatile uint8_t ADDR;
	typedef volatile uint8_t BIT_NR;
	
	static void setOn(const ADDR &addr, const BIT_NR &bitNr)
	{
		addr |= (1<<bitNr);
	}
	
	static void setOff(const ADDR &addr, const BIT_NR &bitNr)
	{
		addr &= ~(1<<bitNr);
	}
	
	static const bool state(const ADDR &addr, const BIT_NR &bitNr)
	{
		return addr & (1<<bitNr);
	}
	
};

#endif /* REGISTER_H_ */