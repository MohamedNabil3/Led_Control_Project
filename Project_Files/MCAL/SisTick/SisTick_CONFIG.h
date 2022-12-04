#ifndef SisTick_CONFIG_H_
#define SisTick_CONFIG_H_

/*
        INCLUDES
*/

#include "SisTick_PRIVET.h"
#include "STD_TYPES.h"
#include "GPIO.h"
/***********************************************/


/*
        GLOBAL CONSTANT MACROS
*/

#define INT_STATUS INT_ENABLE
#define CLK_SOURCE INTRERNAL_CLK
   
/***********************************************/

/*
        GLOBAL DATA TYPES
*/

static uint8 power_flag = 0;
static uint8* duty_cycle;

/***********************************************/


/*
        GLOBAL DATA PROTOTYPE
*/

void SisTick_Init(uint8 power_on_duty_cycle);
void SisTick_Start(void);
void SisTick_Stop(void);
static void (*SisTick_Cllback)(void);

void Set_SisTick_Callback_ptr ( void(*ptr)(void));// ptr to app layer function
void Set_SisTick_Callback_dutycycle ( uint8 * dutyCycle );

/***********************************************/



#endif
