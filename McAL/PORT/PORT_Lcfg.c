
#include "PORT.h"

 const PORT_ConfigType User_Pins_cfg[NUMBER_OF_ACTIVATED_PINS] ={
	
	 /*elements template*/
	 /*
	{
		port name , 
		pin name ,
		pin direction,
		pin function,
		Internal attachment,
		pad current,
		level
		Interrupt ebable,
		Interrupt trigger ,
		interrupt event ,

 },
	 */
	
	{//element 1
		PORT_PORTF,
		PORT_PIN1,
		PORT_OUTPUT,
		PORT_DIO,
		PORT_OPEN_DRAIN,
		PORT_PIN_CURR_8MA,
		PORT_LOW,
		PORT_Disable,
		PORT_NULL_Trigger,
		PORT_NULL_EVENT
	},  
		
	{//element 2
		PORT_PORTF,
		PORT_PIN0, 
		PORT_INPUT, 
		PORT_DIO, 
		PORT_PULLUP, 
		PORT_PIN_CURR_8MA, 
		PORT_LOW,
		PORT_Enable,
		PORT_Edge_Trigger,
		PORT_Falling_Edge_Or_Low_Level
	} 

};
