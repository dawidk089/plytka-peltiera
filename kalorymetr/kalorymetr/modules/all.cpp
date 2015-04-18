#include "aliasy.h"

typedef unsigned short int uns;

/* definicje wszystkich dostepnych funkcji
SPIS:
* piny
* pwm
* timer
* opoznienie
* transmisja
* przetwornik a/c

*/

//---PINS----------------------------------------



void pin_out( uns addr ){
	rejestr(addr, DIRECTION) |= OUT(addr);
} // pin_out( 3 );

void pin_low( uns addr ){
	rejestr(addr, OUT_STATE) &= ~OUT(addr);
}

void pin_high( uns addr ){
	rejestr(addr, OUT_STATE) |= OUT(addr);
}

void pin_in( uns addr){
	rejestr(addr, DIRECTION) &= ~OUT(addr);
}

STATE pin_state( uns addr ){
	return (rejestr(addr, IN_STATE) & OUT(addr) );
}


//---PWM-----------------------------------------

/*
PWM::get(PWM_2).on();  ---> sprawdz ustawienia, ustaw sei()
	if( zegar != 0, !(COM plug out))
	pwm_pin(out);
	sei();

PWM::get(PWM_2).off(); ---> odlacz zegar, power na 0, pin na HI_Z, COM na 0:
	timer_resolution( 2, TPRESC_0 );
	PWM::get(PWM_2).power( 0 );
	PIN::get( pwm_pin(PWM_2) ).hi_z(); (???)
	pwm_plug_out_com( PWM_2 )
	
PWM::get(PWM_2).prescaler( 64 ) ---> ustawia preskaler przez zewnetrzna funkcje:
	timer_resolution( 2, TPRESC_64 );

PWM::get(PWM_2).mode( FAST ); ---> uzywa funkcji:
	pwm_mode( PWM_2, FAST );
	
PWM::get(PWM_2).power( 95.4 ); ---> uzywa zew funkcji:
	pwm_width_state( PWM_2, percent); ---> gdzie percent to { 100-95.4 lub 95.4 }

PWM::get(PWM_2).inversion(false); --->uzywa zew funkcji:
	pwm_inversion( PWM_2, false );
	
PWM::get(PWM_2).prescaler( 64 ); ---> uzywa zewn innej funkcji:
	TIMER::get(2).resolution( TPRESC_64 ); ---> implementacja wkrotce 

*/

enum PWM_MODES{
	FAST
};

enum PWM_ID{
	PWM_1A,
	PWM_1B,
	PWM_2	
};


void pwm_mode( PWM_ID addr, PWM_MODES mode ){
	switch(mode){
		case FAST:
		switch(addr){
			case 2:
				TCCR2 |= (1<<WGM21) | (1<<WGM20);
				break;
			case 1A:
			case 1B:
				TCCR1A |= (1<<WGM10);
				TCCR1A &= ~(1<<WGM11);
				TCCR1B |= (1<<WGM12);
				TCCR1B &= ~(1<<WGM13);
				break;
		}
		default:
			break;
	}
	
	}
}

void pwm_width_state( PWM_ID addr, float percent){
	
	switch(addr){
		case PWM_1A: 
			OCR1A = (int)(percent*255/100.0);
			break;
		
		case PWM_1B:
			OCR1B = (int)(percent*255/100.0);
			break;
			
		case PWM_2:
			OCR2 = (int)(percent*255/100.0);
			break;
	}
	
}

void pwm_plug_out_com( PWM_ID addr ){
	switch( addr ){
		case PWM_1A:
			TCCR1A &= ~((1<<COM1A0)|(1<<COM1A1));
			break;
		case PWM_1B:
			TCCR1A &= ~((1<<COM1B0)|(1<<COM1B1));
			break;
		case PWM_2:
			TCCR2 &= ~((1<<COM20)|(1<<COM21));
			break;
	}
	
}





void pwm_inversion( PWM_ID addr, bool is_invert ){
	
	switch( addr ){
	
		case 2:
			TCCR2 |= (1<<COM21);
			if( is_invert )
			TCCR2 |= (1<<COM20);
			else
			TCCR2 &= ~(1<<COM20);
			break;
	}
}

//---TIMER---------------------------------------
enum TIMER_PRESCALER{
	TPRESC_0,
	TPRESC_1,
	TPRESC_8,
	TPRESC_64,
	TPRESC_256,
	TPRESC_1024	
};


void timer_resolution( uns id, TIMER_PRESCALER prescaler ){
	
	#define CS(a,x,y,z) ((x<<CS##a##0)|(y<<CS##a##1)|(z<<CS##a##2))
	#define N(x) (((~((~0)<<1))&(~x))
	#define NCS(a,x,y,z) (N(x)<<CS##a##0)|(N(y)<<CS##a##1)|(N(z)<<CS##a##2))
	
	#define TCCR(x) TCCR##x
	
	switch(prescaler|(id<<4)){
		
		case (TPRESC_0|(0<<4)):
		TCCR(0) |= CS(0,0,0,0);
		TCCR(0) &= ~NCS(0,0,0,0);
		break;
		case (TPRESC_1|(0<<4)):
		TCCR(0) |= CS(0,0,0,1);
		TCCR(0) &= ~NCS(0,0,0,1);
		break;
		case (TPRESC_8|(0<<4)):
		TCCR(0) |= CS(0,0,1,0);
		TCCR(0) &= ~NCS(0,0,1,0);
		break;
		case (TPRESC_64|(0<<4)):
		TCCR(0) |= CS(0,0,1,1);
		TCCR(0) &= ~NCS(0,0,1,1);
		break;
		case (TPRESC_256|(0<<4)):
		TCCR(0) |= CS(0,1,0,0);
		TCCR(0) &= ~NCS(0,1,0,0);
		break;
		case (TPRESC_1024|(0<<4)):
		TCCR(0) |= CS(0,1,0,1);
		TCCR(0) &= ~NCS(0,1,0,1);
		break;
		
		case (TPRESC_0|(0<<4)):
		TCCR(1) |= CS(1,0,0,0);
		TCCR(1) &= ~NCS(1,0,0,0);
		break;
		case (TPRESC_1|(0<<4)):
		TCCR(1) |= CS(1,0,0,1);
		TCCR(1) &= ~NCS(1,0,0,1);
		break;
		case (TPRESC_8|(0<<4)):
		TCCR(1) |= CS(1,0,1,0);
		TCCR(1) &= ~NCS(1,0,1,0);
		break;
		case (TPRESC_64|(0<<4)):
		TCCR(1) |= CS(1,0,1,1);
		TCCR(1) &= ~NCS(1,0,1,1);
		break;
		case (TPRESC_256|(0<<4)):
		TCCR(1) |= CS(1,1,0,0);
		TCCR(1) &= ~NCS(1,1,0,0);
		break;
		case (TPRESC_1024|(0<<4)):
		TCCR(1) |= CS(1,1,0,1);
		TCCR(1) &= ~NCS(1,1,0,1);
		break;
		
		case (TPRESC_0|(0<<4)):
		TCCR(2) |= CS(2,0,0,0);
		TCCR(2) &= ~NCS(2,0,0,0);
		break;
		case (TPRESC_1|(0<<4)):
		TCCR(2) |= CS(2,0,0,1);
		TCCR(2) &= ~NCS(2,0,0,1);
		break;
		case (TPRESC_8|(0<<4)):
		TCCR(2) |= CS(2,0,1,0);
		TCCR(2) &= ~NCS(2,0,1,0);
		break;
		case (TPRESC_64|(0<<4)):
		TCCR(2) |= CS(2,0,1,1);
		TCCR(2) &= ~NCS(2,0,1,1);
		break;
		case (TPRESC_256|(0<<4)):
		TCCR(2) |= CS(2,1,0,0);
		TCCR(2) &= ~NCS(2,1,0,0);
		break;
		case (TPRESC_1024|(0<<4)):
		TCCR(2) |= CS(2,1,0,1);
		TCCR(2) &= ~NCS(2,1,0,1);
		break;
	}	
}

/*
#define CS(a,x,y,z) ((x<<CS##a##0)|(y<<CS##a##1)|(z<<CS##a##2))
#define TCCR(x) TCCR##x

	TCCR(1) |= CS(1,1,0,1);

// TCCRa |= (x<<CSa0)|(y<<CSa1)|(z<<CSa2)
*/


//===============================================================

#define REG_PRESC(id) TCCR##id
#define VAL_PRESC(id,val1,val2,val3) () 


PRESC(1) |= CS(1,1,1,0);




//==================================================================

void timer_get_time( uns id ){
	//najpierw czesc ulamkowa potem calkowita!!!
}


//---DELAY---------------------------------------

void delay( TYPE id, unsigned time, UNIT_TIME unit ){
	
}

//---USART---------------------------------------

void usart_bitrate( uns bitrate, bool double_speed ){
	
}

void usart_send( char character ){
	
}

void usart_receive( char& character, bool& is_coming ){
	
}

//---ADC-----------------------------------------

void adc_on(){
	
}

void adc_frequency( TIMER_RESOLUTION resolution ){
	
}

void adc_channel( uns addr ){
	
}

uns adc_measure(){
	
}