
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT.h
 *       Module:  PORT
 *
 *  Description:  header file for DIO Module    
 *  
 *********************************************************************************************************************/
#ifndef __Port_H__
#define __Port_H__

/**********************************************************************************************************************
- * INCLUDES
- *********************************************************************************************************************/
#include "Std_Types.h"
#include "MCU_HW.h"
#include "PORT_Lcfg.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
	typedef enum
	{
		PORT_DIO = 0
		/*to do*/
	}PORT_PinMode_Type;


	typedef enum
	{
		PORT_INPUT = 0,
		PORT_OUTPUT
		
	}PORT_PinDirection_Type;


	typedef enum
	{
		PORT_LOW = 0,
		PORT_HIGH
		
	}PORT_PinLevel_Type;

	typedef enum
	{
		PORT_PULLUP = 0,
		PORT_PULLDOWN,
		PORT_OPEN_DRAIN
		
	}PORT_PinINternalAttach_Type;

	typedef enum
	{
		PORT_PIN_CURR_2MA = 0,
		PORT_PIN_CURR_4MA,
		PORT_PIN_CURR_8MA
		
	}PORT_PinOutputCurrent_Type;

	typedef enum
	{
		PORT_PORTA = GPIO_PORTA ,
		PORT_PORTB = GPIO_PORTB ,
		PORT_PORTC = GPIO_PORTC ,
		PORT_PORTD = GPIO_PORTD ,
		PORT_PORTE = GPIO_PORTE ,
		PORT_PORTF = GPIO_PORTF
		
	}PORT_PortNum_type;

	typedef enum
	{
		PORT_PIN0 = 0,
		PORT_PIN1,
		PORT_PIN2,
		PORT_PIN3,
		PORT_PIN4,
		PORT_PIN5,
		PORT_PIN6,
		PORT_PIN7,
		
	}PORT_PinNum_Type;
	
	typedef struct
	{
		PORT_PortNum_type						PortNum;
		PORT_PinNum_Type						PinNum;
		PORT_PinDirection_Type 			PinDir;
		PORT_PinMode_Type 					PinMode;
		PORT_PinINternalAttach_Type InternallAttach;
		PORT_PinOutputCurrent_Type 	OutputCurrent;
		PORT_PinLevel_Type					PinLevel;
		
	}PORT_ConfigType;

/*******************************************************************************
 *                              Extern variabes 		                           *
 *******************************************************************************/

extern const PORT_ConfigType User_Pins_cfg[];

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/******************************************************************************
* \Syntax          :                                    
* \Description     : 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
 
void Port_Init( const PORT_ConfigType	 * ConfigPtr);

	

#endif  /* Port_H */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
