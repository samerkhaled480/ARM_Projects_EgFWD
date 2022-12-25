
#include "LED_Control.h"
	
//for debugging only 
//0x40000000 , 0x400FFFFF

volatile static uint32 time_secondes = 0 ;
static uint8	sw_flag =0 ,  Time_on = 3 , Time_off = 3;

int main(void)
{
	Port_Init();
	NVIC_Init();
	
	GPIOF_Handler_Callback_ptr = GPIOF_isr;
	SysTick_Handler_Callback_ptr = systick_isr;

	while(1)				
	{
		if(sw_flag == 1)
		{
			
			if(Time_on == 5)
			{
				Time_on = 1;
				Time_off = 5;
			}
			else
			{
				Time_on++;
				Time_off--;
			}
			
			sw_flag=0;
		}
		
		Define_Duty(Time_on,Time_off);
	}
  
}


void Define_Duty(uint32 ON_Time ,uint32 OFF_Time)
{
		static uint8  LED_state_flag = 0 , init_flag = 0 ;
	
		
		if(init_flag == 0)
		{
			SYSTICK_PeriodSet(1000); // equal to 1 sec
			SYSTICK_Enable(True , True);
			init_flag++;
		}
		
		if( time_secondes == OFF_Time && LED_state_flag == 0)
		{
			DIO_WriteChannel(LED_PORT , LED_1_PIN , STD_HIGH);
			LED_state_flag = 1;
			time_secondes  = 0;
		}	
		else if(time_secondes == ON_Time && LED_state_flag == 1)
		{
			DIO_WriteChannel(LED_PORT , LED_1_PIN , STD_LOW);
			LED_state_flag = 0;
			time_secondes  = 0;
		} 
		else if ( time_secondes>Time_off && time_secondes>Time_on)time_secondes =0 ; 
	}
	
	
void systick_isr(void)
{
	time_secondes++;
}


void GPIOF_isr(void)
{
	sw_flag = 1;
	SET_BIT ( GPIO_ICR(PORT_PORTF) , SW1_PIN);
	
}
