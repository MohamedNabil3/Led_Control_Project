#ifndef GPIO_H_
#define GPIO_H_

/*
        INCLUDES
*/
/***********************************************/
#include "STD_TYPES.h"
#include "DIO_Adresses.h"
#include "DIO_PRIVET.h"



/*
        GLOBAL CONSTANT MACROS
*/


/***********************************************/

/*
        GLOBAL DATA TYPES
*/


/*

***********************************************

        GLOBAL DATA PROTOTYPE
*/

void GPIO_Clock_Init(Port port);
void GPIO_Clock_Dis(Port port);
void GPIO_Init(Port poet,Pin pin,ALT_FUNC FUN);
void DIO_SetPinDirection (Port port, Pin pin, State state);
void DIO_SetPinValue (Port port, Pin pin, Status status);
uint8 DIO_ReadPinValue (Port port, Pin pin);
uint32 DIO_ReadPortValue(Port port);
void DIO_TogglePinValue (Port port, Pin pin);
/***********************************************/


#endif 
