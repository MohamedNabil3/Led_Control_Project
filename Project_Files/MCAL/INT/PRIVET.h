#ifndef PRIVET_H_
#define PRIVET_H_

/*
        INCLUDES
*/



/***********************************************/


/*
        GLOBAL CONSTANT MACROS
*/

#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_R              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_R              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_R              (*((volatile unsigned long *)0xE000E10C))
#define NVIC_EN4_R              (*((volatile unsigned long *)0xE000E110))

#define NVIC_DIS0_R             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_R             (*((volatile unsigned long *)0xE000E184))
#define NVIC_DIS2_R             (*((volatile unsigned long *)0xE000E188))
#define NVIC_DIS3_R             (*((volatile unsigned long *)0xE000E18C))
#define NVIC_DIS4_R             (*((volatile unsigned long *)0xE000E190))

#define NVIC_PRI0_R             (*((volatile unsigned long *)0xE000E400))
#define NVIC_PRI1_R             (*((volatile unsigned long *)0xE000E404))
#define NVIC_PRI2_R             (*((volatile unsigned long *)0xE000E408))
#define NVIC_PRI3_R             (*((volatile unsigned long *)0xE000E40C))
#define NVIC_PRI4_R             (*((volatile unsigned long *)0xE000E410))
#define NVIC_PRI5_R             (*((volatile unsigned long *)0xE000E414))
#define NVIC_PRI6_R             (*((volatile unsigned long *)0xE000E418))
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_PRI8_R             (*((volatile unsigned long *)0xE000E420))
#define NVIC_PRI9_R             (*((volatile unsigned long *)0xE000E424))
#define NVIC_PRI10_R            (*((volatile unsigned long *)0xE000E428))
#define NVIC_PRI11_R            (*((volatile unsigned long *)0xE000E42C))
#define NVIC_PRI12_R            (*((volatile unsigned long *)0xE000E430))
#define NVIC_PRI13_R            (*((volatile unsigned long *)0xE000E434))
#define NVIC_PRI14_R            (*((volatile unsigned long *)0xE000E438))
#define NVIC_PRI15_R            (*((volatile unsigned long *)0xE000E43C))
#define NVIC_PRI16_R            (*((volatile unsigned long *)0xE000E440))
#define NVIC_PRI17_R            (*((volatile unsigned long *)0xE000E444))
#define NVIC_PRI18_R            (*((volatile unsigned long *)0xE000E448))
#define NVIC_PRI19_R            (*((volatile unsigned long *)0xE000E44C))
#define NVIC_PRI20_R            (*((volatile unsigned long *)0xE000E450))
#define NVIC_PRI21_R            (*((volatile unsigned long *)0xE000E454))
#define NVIC_PRI22_R            (*((volatile unsigned long *)0xE000E458))
#define NVIC_PRI23_R            (*((volatile unsigned long *)0xE000E45C))
#define NVIC_PRI24_R            (*((volatile unsigned long *)0xE000E460))
#define NVIC_PRI25_R            (*((volatile unsigned long *)0xE000E464))
#define NVIC_PRI26_R            (*((volatile unsigned long *)0xE000E468))
#define NVIC_PRI27_R            (*((volatile unsigned long *)0xE000E46C))
#define NVIC_PRI28_R            (*((volatile unsigned long *)0xE000E470))
#define NVIC_PRI29_R            (*((volatile unsigned long *)0xE000E474))
#define NVIC_PRI30_R            (*((volatile unsigned long *)0xE000E478))
#define NVIC_PRI31_R            (*((volatile unsigned long *)0xE000E47C))
#define NVIC_PRI32_R            (*((volatile unsigned long *)0xE000E480))
#define NVIC_PRI33_R            (*((volatile unsigned long *)0xE000E484))
#define NVIC_PRI34_R            (*((volatile unsigned long *)0xE000E488))

#define NVIC_APINT_R            (*((volatile unsigned long *)0xE000ED0C))

/***********************************************/


/*
        GLOBAL DATA TYPES
*/

typedef enum{
GPIO_PortA = 0,
GPIO_PortB,
GPIO_PortC,
GPIO_PortD,
GPIO_PortE,
UART0,
UART1,
SSI0,
I2C0,
PWM0_Fault,
PWM0_Generator0,
PWM0_Generator1,
PWM0_Generator2,
QEI0,
ADC0_Sequence0,
ADC0_Sequence1,
ADC0_Sequence2,
ADC0_Sequence3,
Watchdog_Timers0_and_1,
_16_32_Bit_Timer0A,
_16_32_Bit_Timer0B,
_16_32_Bit_Timer1A,
_16_32_Bit_Timer1B,
_16_32_Bit_Timer2A,
_16_32_Bit_Timer2B,
Analog_Comparator0,
Analog_Comparator1,
Reserved_27,
System_Control,
Flash_Memory_Control,
GPIO_PortF,
Reserved_31,
Reserved_32,
UART2,
SSI1,
_16_32_Bit_Timer3A,
_16_32_Bit_Timer3B,
I2C1,
QEI1,
CAN0,
CAN1,
Reserved_41,
Reserved_42,
Hibernation_Module,
USB,
PWM_Generator3,
UDMASoftware,
UDMA_Error,
ADC1_Sequence0,
ADC1_Sequence1,
ADC1_Sequence2,
ADC1_Sequence3,
Reserved_52,
Reserved_53,
Reserved_54,
Reserved_55,
Reserved_56,
SSI2,
SSI3,
UART3,
UART4,
UART5,
UART6,
UART7,
Reserved_64,
Reserved_65,
Reserved_66,
Reserved_67,
I2C2,
I2C3,
_16_32_Bit_Timer4A,
_16_32_Bit_Timer4B,
Reserved_72,
Reserved_73,
Reserved_74,
Reserved_75,
Reserved_76,
Reserved_77,
Reserved_78,
Reserved_79,
Reserved_80,
Reserved_81,
Reserved_82,
Reserved_83,
Reserved_84,
Reserved_85,
Reserved_86,
Reserved_87,
Reserved_88,
Reserved_89,
Reserved_90,
Reserved_91,
_16_32_Bit_Timer5A,
_16_32_Bit_Timer5B,
_32_64_Bit_Timer0A,
_32_64_Bit_Timer0B,
_32_64_Bit_Timer1A,
_32_64_Bit_Timer1B,
_32_64_Bit_Timer2A,
_32_64_Bit_Timer2B,
_32_64_Bit_Timer3A,
_32_64_Bit_Timer3B,
_32_64_Bit_Timer4A,
_32_64_Bit_Timer4B,
_32_64_Bit_Timer5A,
_32_64_Bit_Timer5B,
System_Exception,
Reserved_107,
Reserved_108,
Reserved_109,
Reserved_110,
Reserved_111,
Reserved_112,
Reserved_113,
Reserved_114,
Reserved_115,
Reserved_116,
Reserved_117,
Reserved_118,
Reserved_119,
Reserved_120,
Reserved_121,
Reserved_122,
Reserved_123,
Reserved_124,
Reserved_125,
Reserved_126,
Reserved_127,
Reserved_128,
Reserved_129,
Reserved_130,
Reserved_131,
Reserved_132,
Reserved_133,
PWM1_Generator0,
PWM1_Generator1,
PWM1_Generator2,
PWM1_Generator3,
PWM1_Fault
}INTERRUPTS;

/***********************************************/


/*
        GLOBAL DATA PROTOTYPE
*/

/***********************************************/







#endif
