
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *
 -------------------------------------------------------------------------------------------------------------------
 *         File: DIO.h
 *       Module: DIO
 *
 *  Description:  Header file Contains all Configuration of DIO Driver
 *
 *********************************************************************************/
#ifndef __DIO_H__
#define __DIO_H__

/**********************************************************************************************************************
 *                                         INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
 *                                      Definitions MACROS                                 *
 *******************************************************************************/

#define PORTA 1
#define PORTB 2
#define PORTC 3
#define PORTD 4
#define PORTE 5
#define PORTF 6

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for DIO_ChannelType required by the DIO APIs */
typedef uint8 DIO_ChannelType;

/* Type definition for DIO_PortType required by the DIO APIs */
typedef uint8 DIO_PortType;

/* Type definition for DIO_LevelType required by the DIO APIs */
typedef uint8 DIO_LevelType;

/* Type definition for DIO_PortLevelType required by the DIO APIs */
typedef uint32 DIO_PortLevelType;


/*******************************************************************************
 *                              CONFIGURATION STRUCTURE                        *
 *******************************************************************************/


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO flip channel API */
DIO_LevelType DIO_FlipChannel(DIO_PortType PortID,DIO_ChannelType ChannelId);

/* Function for DIO write Port API */
void DIO_WriteChannel(DIO_PortType PortID,DIO_ChannelType ChannelId, DIO_LevelType Level);

/* Function for DIO read Port API */
DIO_LevelType DIO_ReadChannel(DIO_PortType PortID,DIO_ChannelType ChannelId);

/* Function for DIO read Channel API */
DIO_PortLevelType DIO_ReadPort(DIO_PortType PortId);

/* Function for DIO write Channel API */
void DIO_WritePort(DIO_PortType PortId, DIO_PortLevelType Level);

	

void GPIOA_Handler(void);
void GPIOB_Handler(void);
void GPIOC_Handler(void);
void GPIOD_Handler(void);
void GPIOE_Handler(void);
void GPIOF_Handler(void);

/*******************************************************************************
 *                       External Variables                                    
 *******************************************************************************/
extern void (*GPIOA_Handler_Callback_ptr)(void);
extern void (*GPIOB_Handler_Callback_ptr)(void);
extern void (*GPIOC_Handler_Callback_ptr)(void);
extern void (*GPIOD_Handler_Callback_ptr)(void);
extern void (*GPIOE_Handler_Callback_ptr)(void);
extern void (*GPIOF_Handler_Callback_ptr)(void);


#endif

