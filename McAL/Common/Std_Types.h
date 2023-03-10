
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
*********************************************************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/

    #define SET_BIT(Value,bit) 		(Value |=  (1UL << bit))
    #define CLR_BIT(Value,bit)  	(Value &= ~(1UL <<bit))
    #define TOG_BIT(Value,bit)  	(Value ^=  (1UL <<bit))
    #define READ_BIT(Value,bit)		((Value>>bit)& 1)
		
    /* NULL_PTR define with a void pointer to zero definition*/
    #define NULL_PTR       ((void *)0)

    #define STD_HIGH     1u /* Physical state 5V or 3.3V */
    #define STD_LOW      0u /* Physical state 0V */

    #define STD_ACTIVE   1u /* Logical state active */
    #define STD_IDLE     0u /* Logical state idle */

    #define STD_ON       1u
    #define STD_OFF      0u

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

    typedef unsigned char   uint8;
    typedef unsigned short  uint16;
    typedef unsigned long   uint32;

    typedef signed char     sint8;
    typedef signed short    sint16;
    typedef signed long     sint32;
		
		typedef enum{
				False,
				True
		}boolean;
		

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */

 


