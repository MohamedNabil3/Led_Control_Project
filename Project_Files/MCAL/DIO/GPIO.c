#include "GPIO.h"



/**********************************     GPIO_NVIC_CNTRL     **********************************************/

#if (GPIO_PORTA_INT_STATUS == INT_ENABLE)
    SELECT_INT_REQUEST(GPIO_PRIOR,GPIO_PortA);
#endif

#if (GPIO_PORTB_INT_STATUS == INT_ENABLE)
    SELECT_INT_REQUEST(GPIO_PRIOR,GPIO_PortB);
#endif

#if (GPIO_PORTC_INT_STATUS == INT_ENABLE)
    SELECT_INT_REQUEST(GPIO_PRIOR,GPIO_PortC);
#endif

#if (GPIO_PORTD_INT_STATUS == INT_ENABLE)
    SELECT_INT_REQUEST(GPIO_PRIOR,GPIO_PortD);
#endif

#if (GPIO_PORTE_INT_STATUS == INT_ENABLE)
    SELECT_INT_REQUEST(GPIO_PRIOR,GPIO_PortE);
#endif

#if (GPIO_PORTF_INT_STATUS == INT_ENABLE)
    SELECT_INT_REQUEST(GPIO_PRIOR,GPIO_PortF);
#endif




/**********************************     CLOCK_INIT     ***************************************************/

void GPIO_Clock_Init(Port port){

switch (port)
{
    case DIO_PORTA:
        SYSCTL_RCGC2_R|=0x1;
				GPIO_PORTA_LOCK_R=0x4C4F434B;
				GPIO_PORTA_CR_R|=0xff;
				GPIO_PORTA_DEN_R|=0xff;
        break;
    case DIO_PORTB:
        SYSCTL_RCGC2_R|=0x2;
				GPIO_PORTB_LOCK_R=0x4C4F434B;
				GPIO_PORTB_CR_R|=0xff;
				GPIO_PORTB_DEN_R|=0xff;
        break;
    case DIO_PORTC:
        SYSCTL_RCGC2_R|=0x4;
				GPIO_PORTC_LOCK_R=0x4C4F434B;
				GPIO_PORTC_CR_R|=0xff;
				GPIO_PORTC_DEN_R|=0xff;
        break;
    case DIO_PORTD:
        SYSCTL_RCGC2_R|=0x8;
				GPIO_PORTD_LOCK_R=0x4C4F434B;
				GPIO_PORTD_CR_R|=0xff;
				GPIO_PORTD_DEN_R|=0xff;
        break;
    case DIO_PORTE:
        SYSCTL_RCGC2_R|=0x10;
				GPIO_PORTE_LOCK_R=0x4C4F434B;
				GPIO_PORTE_CR_R|=0xff;
				GPIO_PORTE_DEN_R|=0xff;
        break;
    case DIO_PORTF:
        SYSCTL_RCGC2_R|=0x20;
				GPIO_PORTF_LOCK_R=0x4C4F434B;
				GPIO_PORTF_CR_R|=0xff;
				GPIO_PORTF_DEN_R|=0xff;
        break;
}

}
/**********************************     CLOCK_DIS     ***************************************************/

void GPIO_Clock_Dis(Port port){
switch (port)
{
    case DIO_PORTA:
        CLR_BIT(SYSCTL_RCGC2_R,0);
        break;
    case DIO_PORTB:
        CLR_BIT(SYSCTL_RCGC2_R,1);
        break;
    case DIO_PORTC:
        CLR_BIT(SYSCTL_RCGC2_R,2);
        break;
    case DIO_PORTD:
        CLR_BIT(SYSCTL_RCGC2_R,3);
        break;
    case DIO_PORTE:
        CLR_BIT(SYSCTL_RCGC2_R,4);
        break;
    case DIO_PORTF:
        CLR_BIT(SYSCTL_RCGC2_R,5);
        break;
}

}
/**************************************************************************************************/



void GPIO_Init(Port port,Pin pin,ALT_FUNC FUN){     
	
    switch (FUN)
    {
    case GPIO:
        switch (port){
        case DIO_PORTA:
            CLR_BIT(GPIO_PORTA_AFSEL_R,pin);
            break;
        case DIO_PORTB:
            CLR_BIT(GPIO_PORTB_AFSEL_R,pin);
            break;
        case DIO_PORTC:
            CLR_BIT(GPIO_PORTC_AFSEL_R,pin);
            break;
        case DIO_PORTD:
            CLR_BIT(GPIO_PORTD_AFSEL_R,pin);
            break;
        case DIO_PORTE:
            CLR_BIT(GPIO_PORTE_AFSEL_R,pin);
            break;
        case DIO_PORTF:
            CLR_BIT(GPIO_PORTF_AFSEL_R,pin);
            break;
        }
				break;
    case Alternative:
        switch (port){
        case DIO_PORTA:
            SET_BIT(GPIO_PORTA_AFSEL_R,pin);
            break;
        case DIO_PORTB:
            SET_BIT(GPIO_PORTB_AFSEL_R,pin);
            break;
        case DIO_PORTC:
            SET_BIT(GPIO_PORTC_AFSEL_R,pin);
            break;
        case DIO_PORTD:
            SET_BIT(GPIO_PORTD_AFSEL_R,pin);
            break;
        case DIO_PORTE:
            SET_BIT(GPIO_PORTE_AFSEL_R,pin);
            break;
        case DIO_PORTF:
            SET_BIT(GPIO_PORTF_AFSEL_R,pin);
            break;
            }
				break;
    }
	
	
}

/*
****************************************************************************************************************************
*/

void DIO_SetPinDirection (Port port, Pin pin, State state){

    	switch (state)
	{
		case DIO_INPUT:
        switch (port)
         {
             case DIO_PORTA:
             CLR_BIT(GPIO_PORTA_DIR_R, pin);
             break;
             case DIO_PORTB:
             CLR_BIT(GPIO_PORTB_DIR_R, pin);
             break;
             case DIO_PORTC:
             CLR_BIT(GPIO_PORTC_DIR_R, pin);
             break;
             case DIO_PORTD:
             CLR_BIT(GPIO_PORTD_DIR_R, pin);
             break;
             case DIO_PORTE:
             CLR_BIT(GPIO_PORTE_DIR_R, pin);
             break;
             case DIO_PORTF:
             CLR_BIT(GPIO_PORTF_DIR_R, pin);
                break;
            }
						break;
		case DIO_OUTPUT:
			switch (port)
					{
						case DIO_PORTA:
						SET_BIT(GPIO_PORTA_DIR_R, pin);
						break;
						case DIO_PORTB:
						SET_BIT(GPIO_PORTB_DIR_R, pin);
						break;
						case DIO_PORTC:
						SET_BIT(GPIO_PORTC_DIR_R, pin);
						break;
						case DIO_PORTD:
						SET_BIT(GPIO_PORTD_DIR_R, pin);
						break;
						case DIO_PORTE:
						SET_BIT(GPIO_PORTE_DIR_R, pin);
						break;
						case DIO_PORTF:
						SET_BIT(GPIO_PORTF_DIR_R, pin);
						break;
					}
					break;
				}

			}
/*
**************************************************************************************************************************************
*/


void DIO_TogglePinValue (Port port, Pin pin)
		{
			switch (port)
				{
					case DIO_PORTA:
					TGL_BIT(GPIO_PORTA_DATA_R, pin);
					break;
					case DIO_PORTB:
					TGL_BIT(GPIO_PORTB_DATA_R, pin);
					break;
					case DIO_PORTC:
					TGL_BIT(GPIO_PORTD_DATA_R, pin);
					break;
					case DIO_PORTD:
					TGL_BIT(GPIO_PORTC_DATA_R, pin);
					break;
					case DIO_PORTE:
					TGL_BIT(GPIO_PORTE_DATA_R, pin);
					break;
					case DIO_PORTF:
					TGL_BIT(GPIO_PORTF_DATA_R, pin);
					break;
			}
}



void DIO_SetPinValue (Port port, Pin pin, Status status){

    	switch (status)
	{
		case DIO_LOW:
            switch (port)
            {
                case DIO_PORTA:
                    CLR_BIT(GPIO_PORTA_DATA_R, pin);
                    break;
                case DIO_PORTB:
                    CLR_BIT(GPIO_PORTB_DATA_R, pin);
                    break;
                case DIO_PORTC:
                    CLR_BIT(GPIO_PORTC_DATA_R, pin);
                    break;
                case DIO_PORTD:
                    CLR_BIT(GPIO_PORTD_DATA_R, pin);
                    break;
                case DIO_PORTE:
                    CLR_BIT(GPIO_PORTE_DATA_R, pin);
                    break;
                case DIO_PORTF:
                    CLR_BIT(GPIO_PORTF_DATA_R, pin);
                    break;  
            }
		break;
		case DIO_HIGH:
            switch (port)
            {
                case DIO_PORTA:
                SET_BIT(GPIO_PORTA_DATA_R, pin);
                break;
                case DIO_PORTB:
                SET_BIT(GPIO_PORTB_DATA_R, pin);
                break;
                case DIO_PORTC:
                SET_BIT(GPIO_PORTC_DATA_R, pin);
                break;
                case DIO_PORTD:
                SET_BIT(GPIO_PORTD_DATA_R, pin);
                break;
                case DIO_PORTE:
                SET_BIT(GPIO_PORTE_DATA_R, pin);
                break;
                case DIO_PORTF:
                SET_BIT(GPIO_PORTF_DATA_R, pin);
                break;
            }
            break;
        }
}



//**************************************************************************************


uint8 DIO_ReadPinValue (Port port, Pin pin){
	uint8 reading = 0;
	switch (port)
	{
		case DIO_PORTA:
		reading = GET_BIT(GPIO_PORTA_DIR_R, pin);
		break;
		case DIO_PORTB:
		reading = GET_BIT(GPIO_PORTB_DIR_R, pin);
		break;
		case DIO_PORTC:
		reading = GET_BIT(GPIO_PORTC_DIR_R, pin);
		break;
		case DIO_PORTD:
		reading = GET_BIT(GPIO_PORTD_DIR_R, pin);
		break;
		case DIO_PORTE:
		reading = GET_BIT(GPIO_PORTE_DIR_R, pin);
		break;
		case DIO_PORTF:
		reading = GET_BIT(GPIO_PORTF_DIR_R, pin);
		break;
	}
	return reading;
}


//*******************************************************************************

uint32 DIO_ReadPortValue(Port port){
    uint32 reading = 0;
	switch (port)
	{
		case DIO_PORTA:
		    reading = GPIO_PORTA_DIR_R;
		    break;
		case DIO_PORTB:
		    reading = GPIO_PORTB_DIR_R;
		    break;
		case DIO_PORTC:
		    reading = GPIO_PORTC_DIR_R;
		    break;
		case DIO_PORTD:
		    reading = GPIO_PORTD_DIR_R;
		    break;
		case DIO_PORTE:
		    reading = GPIO_PORTE_DIR_R;
		    break;
		case DIO_PORTF:
		    reading = GPIO_PORTF_DIR_R;
		    break;
	}
	return reading;
}

