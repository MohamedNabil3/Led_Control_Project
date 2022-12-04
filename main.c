
#include "main.h"


	
int main(){
		// **************************** INITIALIZATION************************************
		GPIO_Clock_Init(DIO_PORTF);
		GPIO_Init(DIO_PORTF,DIO_PIN1,GPIO);
		LED0_Initialization();
		BTN1_Initialization();
	  BTN2_Initialization();
	
		Set_SisTick_Callback_ptr(&callback_fnc);	//for callcack function
		Set_SisTick_Callback_dutycycle(&duty_cycle_);
	
		SisTick_Init(duty_cycle_);		//Configure SisTick timer with duty cycle 55
		SisTick_Start();		//Start count until reach zero 
			
		//****************************** super loop ****************************************	
		uint8 SW1_READING=1;
		uint8 SW2_READING=1;
		while(1){		
			SW1_READING = BTN1_Read();
			SW2_READING = BTN2_Read();
			if(SW1_READING==0&&duty_cycle_<90){
				duty_cycle_+=10;
			}
			if(SW2_READING==0&&duty_cycle_>10){
				duty_cycle_-=10;
		}
			
	}
}
// **************  callback function for SisTick INTERRUPT  ****************************
void callback_fnc(void){
		LED0_TGL();
}

