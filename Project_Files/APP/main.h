#include "INT_CTRL.h"
#include "GPIO.h"
#include "SisTick_CONFIG.h"
#include "LED0.h"
#include "SW1.h"
#include "SW2.h"


uint8 duty_cycle_ = 90;


void callback_fnc(void);
