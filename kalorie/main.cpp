#include "config/scenario_glue.h"
#include "modules/Usart.h"

int main(void)
{
	Usart::init();
	#include "config/scenario_register.h"
	Usart::run();
	return 0;
}