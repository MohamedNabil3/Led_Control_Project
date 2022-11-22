#ifndef INT_CONFIG_H_
#define INT_CONFIG_H_

/*
        INCLUDES
*/


#include "STD_TYPES.h"
#include "PRIVET.h"

/***********************************************/


/*
        GLOBAL CONSTANT MACROS
*/

#define INT_DISABLE 0
#define INT_ENABLE 1

/***********************************************/

/*
        GLOBAL DATA TYPES
*/

typedef enum
{
	xxx = 0,
	xxy = 1,
	xyy = 2,
	yyy = 3
}APINT_GROUPING;



typedef enum
{
	PRIORITY_0 = 0,
	PRIORITY_1 = 1,
	PRIORITY_2 = 2,
	PRIORITY_3 = 3,
  PRIORITY_4 = 4,
  PRIORITY_5 = 5,
  PRIORITY_6 = 6,
  PRIORITY_7 = 7
}PRIORITY;


/***********************************************/


/*
        GLOBAL DATA PROTOTYPE
*/




void SELECT_INT_REQUEST(PRIORITY prio,INTERRUPTS INT_RqST);


/***********************************************/







#endif
