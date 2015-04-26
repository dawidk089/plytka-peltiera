#ifndef PWM_H
#define PWM_H

#include "all.cpp"

///////////////////////////////

enum TIMER_PRESCALER
{
	OFF = 0,
	ON = 1,
	_8 = 8,
	_64 = 64,
	_256 = 256,
	_1024 = 1024
};

///////////////////////////////

class PWM
{

public:

	void mode(PWM_MODES mode);
	void power(float percent);
	void inversion(bool is_invert);
	void timer_resolution(TIMER_PRESCALER prescaler);
	bool on();
	void off();

private:

	PWM(const PWM_ID &id);
	const uns get_clock_id();

	static PWM instances[];
	bool is_inverted;
	bool is_comparator_enabled;
	PWM_ID id;

};

#endif