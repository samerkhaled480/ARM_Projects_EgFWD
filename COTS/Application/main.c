
#include "NVIC.h"
#include "PORT.h"
#include "DIO.h"
#include "SYSTICK.h"
	
//for debugging only 
//0x40000000 , 0x400FFFFF

#define LED_PORT PORTF

#define LED_1_PIN PIN1
#define LED_2_PIN PIN2
#define LED_3_PIN PIN3

const static PORT_ConfigType * ptr = User_Pins_cfg;

int main(void)
{
	NVIC_Init();
	
	Port_Init( ptr);
	
	DIO_WriteChannel(LED_PORT , LED_1_PIN , STD_LOW);
	DIO_WriteChannel(LED_PORT , LED_2_PIN , STD_LOW);
	DIO_WriteChannel(LED_PORT , LED_3_PIN , STD_LOW);
	
	
	SYSTICK_PeriodSet(10);//10 ms
	
	SYSTICK_Enable(True , False);
	while(!SYSTICK_Is_Time_out() );
	DIO_WriteChannel(LED_PORT , LED_3_PIN , STD_HIGH);
	
	SYSTICK_Disable();
	
	while(1)				
	{
		
	}
}

