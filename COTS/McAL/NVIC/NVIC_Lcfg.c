

#include "NVIC.h"

/**********************************************************************************************************************
 *                                                  LOCAL DATA 
 *********************************************************************************************************************/
const NVIC_Interrups_Cfg NVIC_User_Cfg[NVIC_NUM_OF_ENABLED_INTERRUPT] = {
 
    // highest priority is 0
   // InterruptNum, Group priority , SubGroup priority 
   {SysTick ,  2, 0},

};

const GroupPriorityConfigType  NVIC_user_Group_Cfg = NVIC_8_Groups_1_SubGroups;

/*end*/