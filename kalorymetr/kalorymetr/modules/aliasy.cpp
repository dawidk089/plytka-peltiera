#include "aliasy.h"
#include <avr/io.h>


bool is_allowed( PIN id_pin ){
	switch( id_pin ){
		case PIN(_1):
		case PIN(_2):
		case PIN(_3):
		//...
		case PIN(_17):
		case PIN(_18):
		case PIN(_19):
			return false;
			break;
		default:
			return true;
			break;
	}	
}

ADR_REG pin_register ( PIN id_pin, PIN_REGISTER_TYPE registr ){
	switch( id_pin ){
		
		case PIN(_1):
		case PIN(_23):
		case PIN(_24):
		case PIN(_25):
		case PIN(_26):
		case PIN(_27):
		case PIN(_28):
			switch( registr ){	
				case PIN_REGISTER_TYPE(DIRECTION):	return DDRC;					
				case PIN_REGISTER_TYPE(IN_STATE):	return PINC;					
				case PIN_REGISTER_TYPE(OUT_STATE):	return PORTC;
			} break;
		
		case PIN(_2):
		case PIN(_3):
		case PIN(_4):
		case PIN(_5):
		case PIN(_6):
		case PIN(_11):
		case PIN(_12):
		case PIN(_13):
			switch( registr ){
				case PIN_REGISTER_TYPE(DIRECTION):	return DDRD;
				case PIN_REGISTER_TYPE(IN_STATE):	return PIND;					
				case PIN_REGISTER_TYPE(OUT_STATE):	return PORTD;
			} break;	
			
		case PIN(_9):
		case PIN(_10):
		case PIN(_14):
		case PIN(_15):
		case PIN(_16):
		case PIN(_17):
		case PIN(_18):
		case PIN(_19):
			switch( registr ){
				case PIN_REGISTER_TYPE(DIRECTION):	return DDRB;					
				case PIN_REGISTER_TYPE(IN_STATE):	return PINB;				
				case PIN_REGISTER_TYPE(OUT_STATE):	return PORTB;
			} break;
		//default: //#!
	;}
}

ADR_PIN pin_address( PIN id_pin ){
	
	switch( id_pin ){
		case PIN(_1): return (1<<PC6); //CRESET
		case PIN(_2): return (1<<PD0); //DRxD
		case PIN(_3): return (1<<PD1); //DTxD
		case PIN(_4): return (1<<PD2); //DINT0
		case PIN(_5): return (1<<PD3); //DINT1
		case PIN(_6): return (1<<PD4); //DXCK/T0
		case PIN(_9): return (1<<PB6); //BXTAL1/TOSC1
		case PIN(_10): return (1<<PB7); //BXTAL2/TOSC2
		case PIN(_11): return (1<<PD5); //DT1
		case PIN(_12): return (1<<PD6); //DAIN0
		case PIN(_13): return (1<<PD7); //DAIN1
		case PIN(_14): return (1<<PB0); //BICP1
		case PIN(_15): return (1<<PB1); //BOC1A
		case PIN(_16): return (1<<PB2); //BSS/OC1A
		case PIN(_17): return (1<<PB3); //BMOSI/OC2
		case PIN(_18): return (1<<PB4); //BMISO
		case PIN(_19): return (1<<PB5); //BSCK
		case PIN(_23): return (1<<PC0); //CADC0
		case PIN(_24): return (1<<PC1); //CADC1
		case PIN(_25): return (1<<PC2); //CADC2
		case PIN(_26): return (1<<PC3); //CADC3
		case PIN(_27): return (1<<PC4); //CADC4/SDA
		case PIN(_28): return (1<<PC5); //CADC5/SCL
	}	
}