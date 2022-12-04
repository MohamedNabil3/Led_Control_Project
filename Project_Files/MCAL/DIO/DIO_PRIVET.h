
#ifndef DIO_PRIVET_H_
#define DIO_PRIVET_H_

/*
        INCLUDES
*/
/***********************************************/
#include "INT_CONFIG.h"

/*
        GLOBAL CONSTANT MACROS
*/
#define SET_BIT(REG, BIT) REG |= (1<<BIT)
#define CLR_BIT(REG, BIT) REG &=~(1<<BIT)
#define TGL_BIT(REG, BIT) REG ^= (1<<BIT)
#define GET_BIT(REG, BIT) ((REG>>BIT)&0X1)


#define GPIO_PORTA_INT_STATUS INT_DISABLE
#define GPIO_PORTB_INT_STATUS INT_DISABLE
#define GPIO_PORTC_INT_STATUS INT_DISABLE
#define GPIO_PORTD_INT_STATUS INT_DISABLE
#define GPIO_PORTE_INT_STATUS INT_DISABLE
#define GPIO_PORTF_INT_STATUS INT_DISABLE
/***********************************************/

/*
        GLOBAL DATA TYPES
*/

static PRIORITY GPIO_PRIOR = PRIORITY_3;

typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3,
  DIO_PORTE = 4,
  DIO_PORTF = 5
}Port;
//Define Pin type
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}Pin;
//Define State type
typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT = 1
}State;
//Define Status type
typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH = 1
}Status;

typedef enum
{
    edge = 0,
    level = 1
}INT_SENS;

typedef enum
{
    one_edge = 0,
    both_edges = 1
}Edges;

typedef enum
{
    rising = 0,
    falling = 1
}Event;

typedef enum
{
    not_masked = 0,
    masked = 1
}INT_Mask;

typedef enum
{
    GPIO = 0,
    Alternative = 1
}ALT_FUNC;

/*

        GLOBAL DATA PROTOTYPE
*/


/***********************************************/


#endif 
