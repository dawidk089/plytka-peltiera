#ifndef PIN_H
#define PIN_H

#include "all.cpp"

class Pin
{

public:

	void low(const &OUT_STATE);
	void high();
	const STATE state() const;
	void hi_z();
	void pull_up();
	static Pin &get(const int &index);

private:

	Pin(const ADR &addr);
	
	static Pin instances[];
	unsigned addr;

};

#endif