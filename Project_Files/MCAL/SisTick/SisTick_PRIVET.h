#ifndef SisTick_PRIVET_H_
#define SisTick_PRIVET_H_

/*
        INCLUDES
*/

/***********************************************/


/*
        GLOBAL CONSTANT MACROS
*/

#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))


#define INT_DISABLE 0
#define INT_ENABLE 1


#define PRECESSION_CLK 0
#define INTRERNAL_CLK  1
/***********************************************/

/*
        GLOBAL DATA TYPES
*/


/***********************************************/


/*
        GLOBAL DATA PROTOTYPE
*/

/***********************************************/



#endif
