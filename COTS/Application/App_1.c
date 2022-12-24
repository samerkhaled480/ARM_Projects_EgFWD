
#include "App_1.h"
	
//for debugging only 
//0x40000000 , 0x400FFFFF

volatile static uint32 time_secondes = 0;
volatile static uint8  LED_state_flag =0 , init_flag=0;


int main(void)
{
	NVIC_Init();
	Port_Init();
	
	SysTick_Handler_Callback_ptr = my_systick_isr;

	while(1)				
	{
		Define_Duty(LED_ON_TIME,LED_OFF_TIME);
	}
}


void Define_Duty(uint32 ON_Time ,uint32 OFF_Time)
{
		if(init_flag == 0)
		{
			SYSTICK_PeriodSet(1000); // equal to 1 sec
			SYSTICK_Enable(True , True);
			init_flag++;
		}
		
		
		if( time_secondes == OFF_Time && LED_state_flag == 0)
		{
			DIO_WriteChannel(LED_PORT , LED_2_PIN , STD_HIGH);
			LED_state_flag = 1;
			time_secondes = 0;
		}	
		else if(time_secondes == ON_Time && LED_state_flag == 1)
		{
			DIO_WriteChannel(LED_PORT , LED_2_PIN , STD_LOW);
			LED_state_flag = 0;
			time_secondes = 0;
		}
	}
	
void my_systick_isr(void)
{
	time_secondes++;
}
