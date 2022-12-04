


#include "SW1.h"


void BTN1_Initialization(void)
{
	DIO_SetPinDirection(BTN1_PORT, BTN1_PIN, BTN1_INP);
    SET_BIT(GPIO_PORTF_PUR_R,BTN1_PIN);
}

uint8 BTN1_Read(void)
{
	uint8 Btn = NPRESSED;
	uint8 val = 1;
	val = DIO_ReadPinValue(BTN1_PORT, BTN1_PIN);
    Btn = val; 
    while (val==0)
    {
        val = DIO_ReadPinValue(BTN1_PORT, BTN1_PIN);
    }
    
	return Btn;

}


