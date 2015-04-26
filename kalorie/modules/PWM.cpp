#include "PWM.h"

// static members

PWM PWM::instances[] =
{
	PWM(PWM_1A),
	PWM(PWM_1B),
	PWM(PWM_2)
};

// interface

void PWM::mode(PWM_MODES mode)
{
	pwm_mode(id, mode);
}

void PWM::power(float percent)
{
	if (is_inverted)
		pwm_width_state(id, 100.0 - percent);
	else
		pwm_width_state(id, percent);
}

void PWM::inversion(bool is_invert)
{
	pwm_inversion(id, is_invert);
	is_comparator_enabled = true;
}

void PWM::timer_resolution(TIMER_PRESCALER prescaler)
{
	timer_resolution(id, prescaler);
}

bool PWM::on()
{
	if(/*FIXME!*/zegar != 0 && is_comparator_enabled)
	{
		Pin::get(pwm_pin(id)).out();
		sei();
		return true;
	}
	else
		return false;
}

void PWM::off()
{
	timer_resolution(get_clock_id(), TPRESC_0);
	power(0);
	Pin::get(pwm_pin(id)).hi_z();
	pwm_plug_out_com(id);
	is_comparator_enabled = false;
}

// hidden

PWM::PWM(const PWM_ID &id)
: is_comparator_enabled(false), id(id)
{
	inversion(false);
}

const uns PWM::get_clock_id()
{
	switch (id)
	{
		case PWM_1A:
		case PWM_1B:
			return 1;
		case PWM_2:
			return 2;
	}
	return 2;
}