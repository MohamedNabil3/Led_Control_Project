#ifndef INT_CTRL_H_
#define INT_CTRL_H_

/*
        INCLUDES
*/


#include "PRIVET.h"
#include "INT_CONFIG.h"
#include "STD_TYPES.h"

/***********************************************/


/*
        GLOBAL CONSTANT MACROS
*/



/***********************************************/


/*
        GLOBAL DATA TYPES
*/


extern APINT_GROUPING APINT_g;
extern uint8 INT_ARR[139];


/*
        GLOBAL DATA PROTOTYPE
*/

void INT_CTRL_Init(void);
void INT_REQUEST_DIS(uint32 INT_REQUST);

/***********************************************/


#endif 



