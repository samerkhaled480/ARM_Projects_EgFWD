
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *
 -------------------------------------------------------------------------------------------------------------------
 *         File: PORT.h
 *       Module: PORT
 *
 *  Description:  Header file Contains all Configuration of PORT Driver
 *
 *********************************************************************************/


/**********************************************************************************************************************
 *                                         INCLUDES
 *********************************************************************************************************************/

#include "PORT.h"
#include "MCU_HW.h"

/************************************************************************************
* Description       : Function to intialize GPIOs with all its features
											base on configuration files 
* Parameters (in)   : none
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : none
************************************************************************************/
void Port_Init( void)
{
		uint8 i = 0;
		volatile uint8 dummy = 1;
		
		PORT_PortNum_type PortNum ;
		PORT_PinNum_Type  PinNum ;
		
		for(i=0 ; i < NUMBER_OF_ACTIVATED_PINS ; i++)
		{
			
			PortNum = User_Pins_cfg[i].PortNum;
		  PinNum 	= User_Pins_cfg[i].PinNum;
			
			//step1 : init clock
			switch(PortNum)
			{
				case PORT_PORTA :
				{
					SET_BIT( SYSCTL_REGCGC2_REG , 0);
				}break;
				case PORT_PORTB :
				{
					SET_BIT( SYSCTL_REGCGC2_REG , 1);
				}break;
				case PORT_PORTC :
				{
					SET_BIT( SYSCTL_REGCGC2_REG , 2);
				}break;
				case PORT_PORTD :
				{
					SET_BIT( SYSCTL_REGCGC2_REG , 3);
				}break;
				case PORT_PORTE :
				{
					SET_BIT( SYSCTL_REGCGC2_REG , 4);
				}break;
				case PORT_PORTF :
				{
					SET_BIT( SYSCTL_REGCGC2_REG , 5);
				}break;
			}
			
			/* delay of more than 3 clock cycles till clock stablize according to data sheet*/
			dummy = dummy + 4;

			
			//step 2 : unlock GPIO commit register and enable write ops on GPIO registers if required 
			if(  (PortNum == GPIO_PORTF && PinNum == PORT_PIN0)  ||  (PortNum == GPIO_PORTD && PinNum == PORT_PIN7) )
			{
				
				GPIO_LOCK(PortNum) = GPIO_LOCK_REG_KEY;
				GPIO_CR(PortNum) = 0xFF;
				SET_BIT( GPIO_CR(PortNum) , PinNum );
			}
			
			
			//step3 : set direction 
			switch(User_Pins_cfg[i].PinDir)
			{
				case PORT_INPUT:
				{
					CLR_BIT( GPIO_DIR( PortNum) , PinNum );
				}break;
				case PORT_OUTPUT:
				{
					SET_BIT( GPIO_DIR( PortNum) , PinNum );
				}break;
			}
			
			
			//step4 : set mode
			switch(User_Pins_cfg[i].PinMode)
			{
				case PORT_DIO:
				{
					CLR_BIT( GPIO_AMSEL(PortNum) , PinNum );
					CLR_BIT( GPIO_AFSEL(PortNum) , PinNum );
					SET_BIT( GPIO_DEN(PortNum) , PinNum );
				
				}break;
			}
			
			//only if the pin is set to input
			if( User_Pins_cfg[i].PinDir == PORT_INPUT)
			{
				//step 5 : set pin internal attach 
				switch(User_Pins_cfg[i].InternallAttach)
				{
					case PORT_PULLDOWN:
					{
						SET_BIT ( GPIO_PDR(PortNum) , PinNum);
					}break;
					case PORT_PULLUP:
					{
						SET_BIT ( GPIO_PUR(PortNum) , PinNum);
					}break;
					case PORT_OPEN_DRAIN:
					{
						SET_BIT ( GPIO_ODR(PortNum) , PinNum);
					}break;
				}//end of switch
				
				//step 6 : enable interrupt if required 
				if(User_Pins_cfg[i].IntrruptEnable == PORT_Enable)
				{
					
					//step 6.1 set the interrupt sense 
					if(User_Pins_cfg[i].Trigger == PORT_Level_Trigger)
					{
						SET_BIT ( GPIO_IS(PortNum) , PinNum);
					}
					else 
					{
						CLR_BIT ( GPIO_IS(PortNum) , PinNum);
					}
					
					
					//step 6.2 set the interrupt event 
					if(User_Pins_cfg[i].IntEvent == PORT_Falling_Edge_Or_Low_Level)
					{
						CLR_BIT ( GPIO_IBE(PortNum) , PinNum);
						SET_BIT ( GPIO_IEV(PortNum) , PinNum);
					}
					else if(User_Pins_cfg[i].IntEvent == PORT_Rising_Edge_Or_High_Level)
					{
						CLR_BIT ( GPIO_IBE(PortNum) , PinNum);
						CLR_BIT ( GPIO_IEV(PortNum) , PinNum);
					}
					else if(User_Pins_cfg[i].IntEvent == PORT_Both_Edges)
					{
						SET_BIT ( GPIO_IBE(PortNum) , PinNum);
					}
					else{}
						
					//step 6.3 clear any previous interrupts
					SET_BIT ( GPIO_ICR(PortNum) , PinNum);
						
					//step 6.4 unmask(enable GPIO interrupt gate) the interrupt
					SET_BIT ( GPIO_IM(PortNum) , PinNum);
					
				}//end of if condition 
			}//end of if condition 
			
			// step 6 and 7 if only pin is set to output
			if( User_Pins_cfg[i].PinDir == PORT_OUTPUT)
			{
				//step6 : set output current
				switch(User_Pins_cfg[i].OutputCurrent)
				{
					case PORT_PIN_CURR_2MA:
					{
						SET_BIT( GPIO_DR2R(PortNum) , PinNum );
					
					}break;
					case PORT_PIN_CURR_4MA:
					{
						SET_BIT( GPIO_DR4R(PortNum) , PinNum );
					}break;
					case PORT_PIN_CURR_8MA:
					{
						SET_BIT( GPIO_DR8R(PortNum) , PinNum );
					}break;
				}//end of switch
			
				//step7 : set intial level level
				switch(User_Pins_cfg[i].PinLevel)
				{
					case PORT_HIGH:
					{
						SET_BIT( GPIO_DATA(PortNum) , PinNum );
						
					}break;
					case PORT_LOW:
					{
						CLR_BIT( GPIO_DATA(PortNum) , PinNum );
					}break;
				}//end of switch
				
			}//end of if conidtion
			
		}//end of for loop
	
}//end of function 


