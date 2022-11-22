
#include "INT_CTRL.h"


//***************************************** DISABLE INTERUPT ON NVIC **********************************

void INT_REQUEST_DIS(uint32 INT_REQUST){
	
    uint32 dis1=INT_REQUST/32;     // DISABLE_Register_number = INT_REQ/32
    uint32 dis2=INT_REQUST%32;     //PIN_number_TO DIS = INT_REQ%32

        switch (dis1)
    {
    case 0:
        NVIC_DIS0_R|=(uint32)dis2;
				INT_ARR[INT_REQUST]=8;
        break;
    case 1:
        NVIC_DIS1_R|=(uint32)dis2;
				INT_ARR[INT_REQUST]=8;
        break;
    case 2:
        NVIC_DIS2_R|=(uint32)dis2;
        INT_ARR[INT_REQUST]=8;
				break;
    case 3:
        NVIC_DIS3_R|=(uint32)dis2;
				INT_ARR[INT_REQUST]=8;
        break;
    case 4:
        NVIC_DIS4_R|=(uint32)dis2;
				INT_ARR[INT_REQUST]=8;
        break;
    }   
}

//******************************  INTERUPT INIT   *************************************

void INT_CTRL_Init(){
	uint8 pr; //PRIORITY
	
	//LOOP IN THE ARRAY OF INTERRUPTS TO SEE WHICH INTERUPT WILL BE ENABLED
	
	for(uint8 i =0;i<139;i++){
		if(INT_ARR[i]<8){
			pr=INT_ARR[i];
    uint8 pri1=i/4;     // pri_number = INT_REQ/4
    uint32 pri2=i%4;     //number of groub = INT_REQ%4  
    uint32 en1=i/32;     // enable_Register_number = INT_REQ/32
    uint32 en2=i%32;     //PIN_number_TO ENALE = INT_REQ%32

	//**************************************************************************
	
	// CONFIGURE GROUBING AND SUBGROUBING
			
    switch (APINT_g)
    {
    case xxx:
        NVIC_APINT_R|=0xFA050000;          
        break;
    case xxy:
        NVIC_APINT_R|=0xFA050500;          
        break;
    case xyy:
        NVIC_APINT_R|=0xFA050600;          
        break;
    case yyy:
        NVIC_APINT_R|=0xFA050700;          
        break;
    }
//**************************************************************************
// SELECT PRIORITY ON NVIC
		
    switch (pri1)
    {
    case 0:
        switch (pri2)
        {
        case 0:
            NVIC_PRI0_R=(NVIC_PRI0_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI0_R=(NVIC_PRI0_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI0_R=(NVIC_PRI0_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI0_R=(NVIC_PRI0_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 1:
        switch (pri2)
        {
        case 0:
            NVIC_PRI1_R=(NVIC_PRI1_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI1_R=(NVIC_PRI1_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI1_R=(NVIC_PRI1_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI1_R=(NVIC_PRI1_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 2:
        switch (pri2)
        {
        case 0:
            NVIC_PRI2_R=(NVIC_PRI2_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI2_R=(NVIC_PRI2_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI2_R=(NVIC_PRI2_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI2_R=(NVIC_PRI2_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 3:
        switch (pri2)
        {
        case 0:
            NVIC_PRI3_R=(NVIC_PRI3_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI3_R=(NVIC_PRI3_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI3_R=(NVIC_PRI3_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI3_R=(NVIC_PRI3_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 4:
        switch (pri2)
        {
        case 0:
            NVIC_PRI4_R=(NVIC_PRI4_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI4_R=(NVIC_PRI4_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI4_R=(NVIC_PRI4_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI4_R=(NVIC_PRI4_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 5:
        switch (pri2)
        {
        case 0:
            NVIC_PRI5_R=(NVIC_PRI5_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI5_R=(NVIC_PRI5_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI5_R=(NVIC_PRI5_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI5_R=(NVIC_PRI5_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 6:
        switch (pri2)
        {
        case 0:
            NVIC_PRI6_R=(NVIC_PRI6_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI6_R=(NVIC_PRI6_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI6_R=(NVIC_PRI6_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI6_R=(NVIC_PRI6_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 7:
        switch (pri2)
        {
        case 0:
            NVIC_PRI7_R=(NVIC_PRI7_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI7_R=(NVIC_PRI7_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI7_R=(NVIC_PRI7_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI7_R=(NVIC_PRI7_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 8:
        switch (pri2)
        {
        case 0:
            NVIC_PRI8_R=(NVIC_PRI8_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI8_R=(NVIC_PRI8_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI8_R=(NVIC_PRI8_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI8_R=(NVIC_PRI8_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 9:
        switch (pri2)
        {
        case 0:
            NVIC_PRI9_R=(NVIC_PRI9_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI9_R=(NVIC_PRI9_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI9_R=(NVIC_PRI9_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI9_R=(NVIC_PRI9_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 10:
        switch (pri2)
        {
        case 0:
            NVIC_PRI10_R=(NVIC_PRI10_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI10_R=(NVIC_PRI10_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI10_R=(NVIC_PRI10_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI10_R=(NVIC_PRI10_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 11:
        switch (pri2)
        {
        case 0:
            NVIC_PRI11_R=(NVIC_PRI11_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI11_R=(NVIC_PRI11_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI11_R=(NVIC_PRI11_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI11_R=(NVIC_PRI11_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 12:
        switch (pri2)
        {
        case 0:
            NVIC_PRI12_R=(NVIC_PRI12_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI12_R=(NVIC_PRI12_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI12_R=(NVIC_PRI12_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI12_R=(NVIC_PRI12_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 13:
        switch (pri2)
        {
        case 0:
            NVIC_PRI13_R=(NVIC_PRI13_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI13_R=(NVIC_PRI13_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI13_R=(NVIC_PRI13_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI13_R=(NVIC_PRI13_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 14:
        switch (pri2)
        {
        case 0:
            NVIC_PRI14_R=(NVIC_PRI14_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI14_R=(NVIC_PRI14_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI14_R=(NVIC_PRI14_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI14_R=(NVIC_PRI14_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 15:
        switch (pri2)
        {
        case 0:
            NVIC_PRI15_R=(NVIC_PRI15_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI15_R=(NVIC_PRI15_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI15_R=(NVIC_PRI15_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI15_R=(NVIC_PRI15_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 16:
        switch (pri2)
        {
        case 0:
            NVIC_PRI16_R=(NVIC_PRI16_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI16_R=(NVIC_PRI16_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI16_R=(NVIC_PRI16_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI16_R=(NVIC_PRI16_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 17:
        switch (pri2)
        {
        case 0:
            NVIC_PRI17_R=(NVIC_PRI17_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI17_R=(NVIC_PRI17_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI17_R=(NVIC_PRI17_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI17_R=(NVIC_PRI17_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 18:
        switch (pri2)
        {
        case 0:
            NVIC_PRI18_R=(NVIC_PRI18_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI18_R=(NVIC_PRI18_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI18_R=(NVIC_PRI18_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI18_R=(NVIC_PRI18_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 19:
        switch (pri2)
        {
        case 0:
            NVIC_PRI19_R=(NVIC_PRI19_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI19_R=(NVIC_PRI19_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI19_R=(NVIC_PRI19_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI19_R=(NVIC_PRI19_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 20:
        switch (pri2)
        {
        case 0:
            NVIC_PRI20_R=(NVIC_PRI20_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI20_R=(NVIC_PRI20_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI20_R=(NVIC_PRI20_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI20_R=(NVIC_PRI20_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 21:
        switch (pri2)
        {
        case 0:
            NVIC_PRI21_R=(NVIC_PRI21_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI21_R=(NVIC_PRI21_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI21_R=(NVIC_PRI21_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI21_R=(NVIC_PRI21_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 22:
        switch (pri2)
        {
        case 0:
            NVIC_PRI22_R=(NVIC_PRI22_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI22_R=(NVIC_PRI22_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI22_R=(NVIC_PRI22_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI22_R=(NVIC_PRI22_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 23:
        switch (pri2)
        {
        case 0:
            NVIC_PRI23_R=(NVIC_PRI23_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI23_R=(NVIC_PRI23_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI23_R=(NVIC_PRI23_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI23_R=(NVIC_PRI23_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 24:
        switch (pri2)
        {
        case 0:
            NVIC_PRI24_R=(NVIC_PRI24_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI24_R=(NVIC_PRI24_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI24_R=(NVIC_PRI24_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI24_R=(NVIC_PRI24_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 25:
        switch (pri2)
        {
        case 0:
            NVIC_PRI25_R=(NVIC_PRI25_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI25_R=(NVIC_PRI25_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI25_R=(NVIC_PRI25_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI25_R=(NVIC_PRI25_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 26:
        switch (pri2)
        {
        case 0:
            NVIC_PRI26_R=(NVIC_PRI26_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI26_R=(NVIC_PRI26_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI26_R=(NVIC_PRI26_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI26_R=(NVIC_PRI26_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 27:
        switch (pri2)
        {
        case 0:
            NVIC_PRI27_R=(NVIC_PRI27_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI27_R=(NVIC_PRI27_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI27_R=(NVIC_PRI27_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI27_R=(NVIC_PRI27_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 28:
        switch (pri2)
        {
        case 0:
            NVIC_PRI28_R=(NVIC_PRI28_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI28_R=(NVIC_PRI28_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI28_R=(NVIC_PRI28_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI28_R=(NVIC_PRI28_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 29:
        switch (pri2)
        {
        case 0:
            NVIC_PRI29_R=(NVIC_PRI29_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI29_R=(NVIC_PRI29_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI29_R=(NVIC_PRI29_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI29_R=(NVIC_PRI29_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 30:
        switch (pri2)
        {
        case 0:
            NVIC_PRI30_R=(NVIC_PRI30_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI30_R=(NVIC_PRI30_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI30_R=(NVIC_PRI30_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI30_R=(NVIC_PRI30_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 31:
        switch (pri2)
        {
        case 0:
            NVIC_PRI31_R=(NVIC_PRI31_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI31_R=(NVIC_PRI31_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI31_R=(NVIC_PRI31_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI31_R=(NVIC_PRI31_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 32:
        switch (pri2)
        {
        case 0:
            NVIC_PRI32_R=(NVIC_PRI32_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI32_R=(NVIC_PRI32_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI32_R=(NVIC_PRI32_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI32_R=(NVIC_PRI32_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 33:
        switch (pri2)
        {
        case 0:
            NVIC_PRI33_R=(NVIC_PRI33_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI33_R=(NVIC_PRI33_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI33_R=(NVIC_PRI33_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI33_R=(NVIC_PRI33_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    case 34:
        switch (pri2)
        {
        case 0:
            NVIC_PRI34_R=(NVIC_PRI34_R&0xFFFFFF1F)|(((uint32)pr)<<5);
            break;
        case 1:
            NVIC_PRI34_R=(NVIC_PRI34_R&0xFFFF1FFF)|(((uint32)pr)<<13);
            break;
        case 2:
            NVIC_PRI34_R=(NVIC_PRI34_R&0xFF1FFFFF)|(((uint32)pr)<<18);
            break;
        case 3:
            NVIC_PRI34_R=(NVIC_PRI34_R&0x1FFFFFFF)|(((uint32)pr)<<29);
            break;
        }
        break;
    
    }
		
//**************************************************************************

		
// ENABLE INTERRUPT ON NVIC
		
    switch (en1)
    {
    case 0:
        NVIC_EN0_R|=(1<<en2);
        break;
    case 1:
        NVIC_EN1_R|=(1<<en2);
        break;
    case 2:
        NVIC_EN2_R|=(1<<en2);
        break;
    case 3:
        NVIC_EN3_R|=(1<<en2);
        break;
    case 4:
        NVIC_EN4_R|=(1<<en2);
        break;
     } //end of switch  
	 }//end of if	
 }//end of for		
}//end of function INIT
