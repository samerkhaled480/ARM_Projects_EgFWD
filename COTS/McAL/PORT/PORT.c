

#include "PORT.h"
#include "MCU_HW.h"

 
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

			
			//step3 : unlock GPIO commit register and enable write ops on GPIO registers if required 
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
			
			
			//step5 : set output current
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
			}
			
			
			
			//step6 : set level
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
			}
			
		
		}//end of for loop
	
}//end of function 


