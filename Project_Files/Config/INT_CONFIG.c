
#include "INT_CONFIG.h"

// Configuration of grouping and subgrouping
APINT_GROUPING APINT_g = xxx;
 
// ARRAY OF INTERUPTS HANDLER 8 means it will  not be enabled if small than 8 it will be enabled
uint8 INT_ARR[139]={8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8};

//**************************************************************
	 
void SELECT_INT_REQUEST(PRIORITY prio,INTERRUPTS INT_RqST){
		INT_ARR[INT_RqST]=prio;
}
