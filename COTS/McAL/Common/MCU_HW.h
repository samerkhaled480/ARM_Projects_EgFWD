


/*******************************************************************************************************************

 *  FILE DESCRIPTION
 *
 -------------------------------------------------------------------------------------------------------------------
 *         File: MCU_HW.h
 *       Module: Common header file 
 *  Description:  Header file Contains all rgister adresses of the MCU
 *
 ********************************************************************************************************************/
#ifndef __MCU_HW_H__
#define __MCU_HW_H__

/******************************************************************************
 *                            INCLUDES
 ******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
 *                         Definitions MACROS                                 
 *******************************************************************************/


/**************************************
*   GPIO REGISTRE
***************************************/
	#ifdef GPIO_APB

		#define GPIO_PORTA    0x40004000
		#define GPIO_PORTB    0x40005000
		#define GPIO_PORTC    0x40006000
		#define GPIO_PORTD    0x40007000
		#define GPIO_PORTE    0x40024000
		#define GPIO_PORTF    0x40025000
	
	#elif GPIO_AHB
		#error "Not Supported Yet"
	#else
		#error "choose a bus for GPIOs"
	#endif
	
	#define GPIO_DATA(GPIO_PORT)			*((volatile uint32 *)(GPIO_PORT+0x3FC))
	#define GPIO_DIR(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x400))
	
	#define GPIO_IS(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x404))
	#define GPIO_IBE(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x408))
	#define GPIO_IEV(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x40C))
	#define GPIO_IM(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x410))
	#define GPIO_RIS(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x414))
	#define GPIO_MIS(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x418))
	#define GPIO_ICR(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x41C))

	#define GPIO_AFSEL(GPIO_PORT)			*((volatile uint32 *)(GPIO_PORT+0x420))
	#define GPIO_LOCK(GPIO_PORT)			*((volatile uint32 *)(GPIO_PORT+0x520))
	#define GPIO_CR(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x524))
	#define GPIO_PCTL(GPIO_PORT)			*((volatile uint32 *)(GPIO_PORT+0x52C))
	#define GPIO_DR2R(GPIO_PORT)  	 	*((volatile uint32 *)(GPIO_PORT+0x500))
	#define GPIO_DR4R(GPIO_PORT)     	*((volatile uint32 *)(GPIO_PORT+0x504))
	#define GPIO_DR8R(GPIO_PORT)     	*((volatile uint32 *)(GPIO_PORT+0x508))
	#define GPIO_PUR(GPIO_PORT)      	*((volatile uint32 *)(GPIO_PORT+0x510))
	#define GPIO_PDR(GPIO_PORT)      	*((volatile uint32 *)(GPIO_PORT+0x514))
	#define GPIO_DEN(GPIO_PORT)				*((volatile uint32 *)(GPIO_PORT+0x51C))
	#define GPIO_AMSEL(GPIO_PORT)			*((volatile uint32 *)(GPIO_PORT+0x528))
	#define GPIO_ODR(GPIO_PORT)      	*((volatile uint32 *)(GPIO_PORT+0x50C))
	
	
	#define GPIO_LOCK_REG_KEY						0x4C4F434B
/**************************************
*   RCC REGISTRE
***************************************/
	#define SYSCTL_REGCGPIO_REG           (*((volatile uint32 *)0x400FE608))
	#define SYSCTL_REGCGC2_REG           (*((volatile uint32 *)0x400FE108))

/**************************************
*   SYSTICK REGISTRE
***************************************/
	#define SYSTICK_CTRL				*( (volatile uint32 *)0xE000E010)

	#define SYSTICK_EN_POS			  	(0UL)
	#define SYSTICK_INT_EN_POS 			(1UL)
	#define SYSTICK_CLK_SRC_POS			(2UL)
	#define SYSTICK_COUNT_FLAG_POS 		(16UL)
	
	//#define SYSTICK_RELOAD_BASS 0xE000E000
	//#define SYSTICK_RELOAD_OFFSET 0x014
	
	#define SYSTICK_RELOAD				*( (volatile uint32 *)0xE000E014)

	#define SYSTICK_RELOAD_POS 			(0UL) 	
	
	//#define SYSTICK_CURRENT_BASS 0xE000E000
	//#define SYSTICK_CURRENT_OFFSET 0x018
	
	#define SYSTICK_CURRENT				*( (volatile uint32 *)0xE000E018)
		
	#define SYSTICK_CURRENT_POS 		(0UL)
	

	
/**************************************
*   NVIC REGISTRE
***************************************/
#define NVIC_PRI_BASS				0xE000E400UL
#define NVIC_PRI0           (*((volatile uint32 *)0xE000E400))
#define NVIC_PRI1           (*((volatile uint32 *)0xE000E404))
#define NVIC_PRI2           (*((volatile uint32 *)0xE000E408))
#define NVIC_PRI3           (*((volatile uint32 *)0xE000E40C))
#define NVIC_PRI4           (*((volatile uint32 *)0xE000E410))
#define NVIC_PRI5           (*((volatile uint32 *)0xE000E414))
#define NVIC_PRI6           (*((volatile uint32 *)0xE000E418))
#define NVIC_PRI7           (*((volatile uint32 *)0xE000E41C))
#define NVIC_PRI8           (*((volatile uint32 *)0xE000E420))
#define NVIC_PRI9           (*((volatile uint32 *)0xE000E424))
#define NVIC_PRI10          (*((volatile uint32 *)0xE000E428))
#define NVIC_PRI11          (*((volatile uint32 *)0xE000E42C))
#define NVIC_PRI12          (*((volatile uint32 *)0xE000E430))
#define NVIC_PRI13          (*((volatile uint32 *)0xE000E434))
#define NVIC_PRI14          (*((volatile uint32 *)0xE000E438))
#define NVIC_PRI15          (*((volatile uint32 *)0xE000E43C))
#define NVIC_PRI16          (*((volatile uint32 *)0xE000E440))
#define NVIC_PRI17          (*((volatile uint32 *)0xE000E444))
#define NVIC_PRI18          (*((volatile uint32 *)0xE000E448))
#define NVIC_PRI19          (*((volatile uint32 *)0xE000E44C))
#define NVIC_PRI20          (*((volatile uint32 *)0xE000E450))
#define NVIC_PRI21          (*((volatile uint32 *)0xE000E454))
#define NVIC_PRI22          (*((volatile uint32 *)0xE000E458))
#define NVIC_PRI23          (*((volatile uint32 *)0xE000E45C))
#define NVIC_PRI24          (*((volatile uint32 *)0xE000E460))
#define NVIC_PRI25          (*((volatile uint32 *)0xE000E464))
#define NVIC_PRI26          (*((volatile uint32 *)0xE000E468))
#define NVIC_PRI27          (*((volatile uint32 *)0xE000E46C))
#define NVIC_PRI28          (*((volatile uint32 *)0xE000E470))
#define NVIC_PRI29          (*((volatile uint32 *)0xE000E474))
#define NVIC_PRI30          (*((volatile uint32 *)0xE000E478))
#define NVIC_PRI31          (*((volatile uint32 *)0xE000E47C))
#define NVIC_PRI32          (*((volatile uint32 *)0xE000E480))
#define NVIC_PRI33          (*((volatile uint32 *)0xE000E484))
#define NVIC_PRI34          (*((volatile uint32 *)0xE000E488))

#define NVIC_EN_BASS				0xE000E100UL
#define NVIC_EN0            (*((volatile uint32 *)0xE000E100))
#define NVIC_EN1            (*((volatile uint32 *)0xE000E104))
#define NVIC_EN2            (*((volatile uint32 *)0xE000E108))
#define NVIC_EN3            (*((volatile uint32 *)0xE000E10C))
#define NVIC_EN4            (*((volatile uint32 *)0xE000E110))

#define NVIC_DIS_BASS				0xE000E180UL
#define NVIC_DIS0           (*((volatile uint32 *)0xE000E180))
#define NVIC_DIS1           (*((volatile uint32 *)0xE000E184))
#define NVIC_DIS2           (*((volatile uint32 *)0xE000E188))
#define NVIC_DIS3           (*((volatile uint32 *)0xE000E18C))
#define NVIC_DIS4           (*((volatile uint32 *)0xE000E190))

/*software interrupts not added yet*/

/**************************************
*   SCB REGISTRE
***************************************/
#define SCB_APINT					(*((volatile uint32 *)0xE000ED0C))
	
#define SCB_SYS_PRI1    	(*((volatile uint32 *)0xE000ED18))
#define SCB_SYS_PRI2    	(*((volatile uint32 *)0xE000ED1C))
#define SCB_SYS_PRI3   		(*((volatile uint32 *)0xE000ED20))
	
#define SCB_SYS_HND_CTRL  (*((volatile uint32 *)0xE000ED24))


/*******************************************************************************
 *                              CONFIGURATION STRUCTURE                        *
 *******************************************************************************/

#endif

