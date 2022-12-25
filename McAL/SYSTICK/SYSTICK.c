/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *
 -------------------------------------------------------------------------------------------------------------------
 *         File: SYSTICK.c
 *       Module: SYSTICK TIMER 
 *
 *  Description:  Header file Contains all Functions Definitions of SYSTICK Driver
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *                                         INCLUDES
 *********************************************************************************************************************/
#include "SYSTICK.h"
#include "MCU_HW.h"


void (* SysTick_Handler_Callback_ptr )(void) = NULL_PTR;


/************************************************************************************
* Service Name: DIO_WriteChannel
* Parameters (in): 	PortId , ChannelId , Level 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void SYSTICK_Enable(boolean ClockSource , boolean IsInterruptEnabled)
{
	//enable clock sourece
	
	//clear counting register 
	SYSTICK_CURRENT = 0x0;
	
	//select clock source 
	if(ClockSource == True)SET_BIT(SYSTICK_CTRL , SYSTICK_CLK_SRC_POS);
	else 					 				 CLR_BIT(SYSTICK_CTRL , SYSTICK_CLK_SRC_POS);
	
	//enable or disable interrup gate in systick only
	if(IsInterruptEnabled == True)SET_BIT(SYSTICK_CTRL , SYSTICK_INT_EN_POS);
	else 													CLR_BIT(SYSTICK_CTRL , SYSTICK_INT_EN_POS);
	
	//start the counter 
	SET_BIT(SYSTICK_CTRL , SYSTICK_EN_POS);
}

/************************************************************************************
* Service Name: DIO_WriteChannel
* Parameters (in): 	PortId , ChannelId , Level 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void SYSTICK_Disable(void)
{
	CLR_BIT(SYSTICK_CTRL , SYSTICK_INT_EN_POS);
	CLR_BIT(SYSTICK_CTRL , SYSTICK_EN_POS);
}
/************************************************************************************
* Service Name: DIO_WriteChannel
* Parameters (in): 	PortId , ChannelId , Level 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void SYSTICK_PeriodSet(uint32 Period)
{
	// To Do : implment mechanism for different clock cycles not only 16Mhz
	SYSTICK_RELOAD |= ((( Period * 16000)-1) & 0xFFFFFF) ;
}

/************************************************************************************
* Service Name: DIO_WriteChannel
* Parameters (in): 	PortId , ChannelId , Level 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
boolean SYSTICK_Is_Time_out(void)
{
	if( READ_BIT(SYSTICK_CTRL,SYSTICK_COUNT_FLAG_POS) || SYSTICK_CURRENT == 0) 
	{
		CLR_BIT(SYSTICK_CTRL,SYSTICK_COUNT_FLAG_POS);
		return True;
	}
	else return False; 
}

/************************************************************************************
* Service Name: DIO_WriteChannel
* Parameters (in): 	PortId , ChannelId , Level 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void SysTick_Handler(void)
{
	if(SysTick_Handler_Callback_ptr != NULL_PTR)
	{
		SysTick_Handler_Callback_ptr();
	}
}


/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
