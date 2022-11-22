
#include "main.h"


	
int main(){
		// **************************** INITIALIZATION************************************
		GPIO_Clock_Init(DIO_PORTF);
		GPIO_Init(DIO_PORTF,DIO_PIN1,GPIO);
		LED0_Initialization();
	
		Set_SisTick_Callback_ptr(&callback_fnc); //for callcack function
		SisTick_Init(55);		//Configure SisTick timer with duty cycle 55
		SisTick_Start();		//Start count until reach zero 
			
		//****************************** super loop ****************************************	

		while(1){

		}
	}

// **************  callback function for SisTick INTERRUPT  ****************************
void callback_fnc(void){
		LED0_TGL();
}

