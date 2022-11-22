
#include "LED0.h"

void LED0_Initialization(void)
{
	//SET_BIT(LED0_DDR, LED0);
	DIO_SetPinDirection(LED0_PORT, LED0, LED0_OUT);
}

//****************************************************************************
void LED0_ON(void)
{
	//SET_BIT(LED0_PORT, LED0);
	DIO_SetPinValue(LED0_PORT, LED0, LED0_ONN);
}

//****************************************************************************


void LED0_OFF(void)
{
	//CLR_BIT(LED0_PORT, LED0);
	DIO_SetPinValue(LED0_PORT, LED0, LED0_OFFF);
}
//****************************************************************************


void LED0_TGL(void){
	DIO_TogglePinValue(LED0_PORT,DIO_PIN1);
}
