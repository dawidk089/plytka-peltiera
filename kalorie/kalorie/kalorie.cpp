#include "config/scenario_glue.h"
#include "modules/Usart.h"
#include "modules/Adc.h"


int main(void)
{ DDRC |= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3);
	Usart::init();
	#include "config/scenario_register.h"
	Usart::run();
	return 0;
} 