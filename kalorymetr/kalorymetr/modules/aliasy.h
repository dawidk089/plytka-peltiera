#include "typedefinition.h"

#ifndef INCFILE1_H_
#define INCFILE1_H_

#define ADR_REG volatile uint8_t
#define ADR_PIN volatile uint8_t

typedef unsigned short int uns; //#!

enum PIN_REGISTER_TYPE{
	DIRECTION,
	IN_STATE,
	OUT_STATE
};

enum PIN{
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
//	_7 NOT EXIST
//	_8 NOT EXIST
	_9,
	_10,
	_11,
	_12,
	_13,
	_14,
	_15,
	_16,
	_17,
	_18,
	_19,
//	_20 NOT EXIST
//	_21 NOT EXIST
//	_22 NOT EXIST
	_23,
	_24,
	_25,
	_26,
	_27,
	_28
};
	

ADR_REG pin_register ( PIN id_pin, PIN_REGISTER_TYPE registr );
ADR_PIN pin_address( PIN id_pin );

enum STATE{
	LOW = 0,
	HIGH = 1
};

#endif /* INCFILE1_H_ */