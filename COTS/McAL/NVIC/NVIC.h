
#ifndef __NVIC_H__
#define __NVIC_H__

#include "Std_Types.h"	
#include "NVIC_Lcfg.h"

typedef enum{

    Reset            = 1,
    NMI                 ,
    Hard_Fault          ,
    Memory_Managmnet    ,
    Bus_Fault           ,
    Usage_Fault         ,
    SVCall          = 11,
    Debug_Monitor       ,
    PendSV          = 14,
    SysTick             ,
    GPIO_PORT_A         ,
    GPIO_PORT_B         ,
    GPIO_PORT_C         ,
    GPIO_PORT_D         ,
    GPIO_PORT_E         ,
    UART0               ,
    UART1               ,
    SSI0                ,
    I2C0                ,
    PWM0_GEN0           ,
    PWM0_GEN1           ,
    PWM0_GEN2           ,
    QEI0                ,
    ADC0_SEQ0           ,
    ADC0_SEQ1           ,
    ADC0_SEQ2           ,
    ADC0_SEQ3    
 //TODO : restof vector table 

}NVIC_InterruptNameType;

typedef enum
{
    NVIC_8_Groups_1_SubGroups = 0x4UL,
    NVIC_4_Groups_2_SubGroups      , 
    NVIC_2_Groups_4_SubGroups      ,
    NVIC_1_Groups_8_SubGroups      

}GroupPriorityConfigType;

typedef struct 
{
    NVIC_InterruptNameType InterruptName;
    uint8 Group_Priority;
    uint8 SubGroup_Priority;
   
}NVIC_Interrups_Cfg;

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void NVIC_Init(void);


/**********************************************************************************************************************
 *                                     GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

extern const NVIC_Interrups_Cfg NVIC_User_Cfg[];

extern const GroupPriorityConfigType  NVIC_user_Group_Cfg;


	
	
#endif
