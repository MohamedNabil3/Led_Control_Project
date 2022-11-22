#include "SisTick_CONFIG.h"




void SisTick_Init(uint8 power_on_duty_cycle){
    
		duty_cycle = power_on_duty_cycle;
		//check intetupt status
		#if (INT_STATUS == INT_ENABLE)
    NVIC_ST_CTRL_R |= (1<<1) ;
		#else
		NVIC_ST_CTRL_R &=~(1<<1) ;
		#endif
		//check clock source
		#if (CLK_SOURCE == INTRERNAL_CLK)
    NVIC_ST_CTRL_R |= (1<<2) ;
		#else
		NVIC_ST_CTRL_R &=~(1<<2) ;
		#endif
	
		NVIC_ST_CURRENT_R = 0;
    NVIC_ST_RELOAD_R=(16000000-(duty_cycle*16000000/100))-1;
}

//************************************************************

void SisTick_Start(){
	NVIC_ST_CTRL_R |= 1 ;
}


//*************************************************************************
void SisTick_Stop(){

	NVIC_ST_CTRL_R &=0xFFFFFFFE ;
}

//***********************************************************************

void SysTick_Handler(void){
		
		// if led was off make it on and vise versa 
		if(power_flag==0){ //led was off
			SisTick_Stop();
			NVIC_ST_CURRENT_R = 0;
			NVIC_ST_RELOAD_R=-(duty_cycle*16000000/100)-1;	 //time = (duty cycle*16000000/100)-1
			power_flag^=1;		
	}
		else{		//led was on
			SisTick_Stop();
			NVIC_ST_CURRENT_R = 0;
			NVIC_ST_RELOAD_R=(16000000-(duty_cycle*16000000/100))-1;	//((1-duty_cycle/100)*16000000)-1
			power_flag^=1;
	}
	SisTick_Cllback();
	SisTick_Start();
}

//****************************************************************************

void Set_SisTick_Callback_ptr ( void(*ptr)(void) ){

	SisTick_Cllback = ptr;

}
