


#include "SW2.h"


void BTN2_Initialization(void)
{
	DIO_SetPinDirection(BTN2_PORT, BTN2_PIN, BTN2_INP);
    SET_BIT(GPIO_PORTF_PUR_R,BTN2_PIN);
}

uint8 BTN2_Read(void)
{
	uint8 Btn = NPRESSED;
	uint8 val = 1;
	val = DIO_ReadPinValue(BTN2_PORT, BTN2_PIN);
    Btn = val; 
    while (val==0)
    {
        val = DIO_ReadPinValue(BTN2_PORT, BTN2_PIN);
    }
    
	return Btn;

}


