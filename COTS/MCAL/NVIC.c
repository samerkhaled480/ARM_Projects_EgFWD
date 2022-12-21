
#include "MCU_HW.h"
#include "NVIC.h"

#define APINT_KEY 		0x05FAUL
#define APINT_KEY_POS	16UL
#define APINT_PRI_GROUP_BITS_POS 8UL

/******************************************************************************
* \Syntax          : Void NVIC_Init(void)        
* \Description     : Initalize the interrupts                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : No                    
* \Parameters (out): NO                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void NVIC_Init(void)
{
    //set priourity groups configuration 
    SCB_APINT |= ((APINT_KEY << APINT_KEY_POS) | (NVIC_user_Group_Cfg << APINT_PRI_GROUP_BITS_POS));
	
		uint8 VectNum = 0 ,Vect_Group_Pri = 0 ,Vect_Sub_Pri = 0 ,VectBit = 0  ,Index = 0;
		uint32 VectPri = 0  ;
		uint32 *VectReg = NULL_PTR ;
	
		for(Index = 0 ; Index <  NVIC_NUM_OF_ENABLED_INTERRUPT ; Index++)
	{
		VectNum 				= NVIC_User_Cfg[Index].InterruptName;
		Vect_Group_Pri  = NVIC_User_Cfg[Index].Group_Priority;
		Vect_Sub_Pri    = NVIC_User_Cfg[Index].SubGroup_Priority;
		
		if(VectNum > 15)
		{
			VectNum -= 16;
			// 1 - set priority 
			VectReg = (uint32*)( NVIC_PRI_BASS + ((VectNum / 4) * 4));
			VectBit = (((VectNum % 4) * 8) + 5); 
			
			VectPri = ((uint32)Vect_Group_Pri <<((NVIC_user_Group_Cfg - 0x4) | Vect_Sub_Pri));
			*VectReg |= (VectPri << VectBit);
			
			// 2 - enable interrupt nvic gate 
			VectReg = (uint32*)(NVIC_EN_BASS + ((VectNum / 32) * 4));
			VectBit = VectNum % 32;
			*VectReg |= (1<< VectBit);
			
		}
		else
		{
			//enable mechnism of SCB interruprts , not supported yet
			switch(VectNum)
			{
				case SysTick :
				{
					// 1 - set priority 					
					VectPri = ((uint32)Vect_Group_Pri <<((NVIC_user_Group_Cfg - 0x4) | Vect_Sub_Pri));
					SCB_SYS_PRI3 |= ( (VectPri & 0x7) << 29);
	
					
				}break;
			}

			
		}
		
	}

}

/*


extern const NVIC_Interrups_Cfg NVIC_User_Cfg;

extern const GroupPriorityConfigType  NVIC_user_Group_Cfg;

NVIC_NUM_OF_ENABLED_INTERRUPT

*/