/*************************************************************************************
*     Author      : Zaki Ahmed hamed                                                 *
*     Description : Dio Driver                                   	                 *
*     Date        : 20 sep 2019                                                      *
*     Version     : 1.0                                                              *
*************************************************************************************/




/*************************************************************************************
*     Description : Guard to Protect this file from include more than one time       *
*                                                                                    *
*************************************************************************************/

#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H


/**************************************************************************************
 *										Include Header Files   						  *
 *************************************************************************************/
#include "STD_TYPES.h"


/*************************************************************************************
*     Description : PINS DEFINITION    											     *
*                                                                                    *
*************************************************************************************/

#define DIO_U8_PIN_0    	  0
#define DIO_U8_PIN_1    	  1
#define DIO_U8_PIN_2    	  2
#define DIO_U8_PIN_3    	  3
#define DIO_U8_PIN_4    	  4
#define DIO_U8_PIN_5    	  5
#define DIO_U8_PIN_6    	  6
#define DIO_U8_PIN_7    	  7

/*************************************************************************************
*     Description : PORT DEFINITIOS											         *
*                                                                                    *
*************************************************************************************/
#define DIO_U8_PORT_A          0
#define DIO_U8_PORT_B          1
#define DIO_U8_PORT_C          2
#define DIO_U8_PORT_D          3

/*************************************************************************************
*     Description : DEFINITIOS FOR DIO I/P AND O/P							         *
*                                                                                    *
*************************************************************************************/

#define  DIO_U8_INPUT         0
#define  DIO_U8_OUTPUT        1

/*************************************************************************************
*     Description : DEFINITIOS FOR DIO HIGH AND LOW							         *
*                                                                                    *
*************************************************************************************/

#define  DIO_U8_LOW       	  0
#define  DIO_U8_HIGH    	  1



 /**************************************************************************************/
 /* Description    :  This Function Set The Pin Direction in The Run Time	                         */
 /* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo, Cpy_u8PinDirection] 			            			                         */
 /* return         : void						                                         */
 /**************************************************************************************/

void Dio_VoidSetPinDirection(u8 Cpy_u8PortID, u8 Cpy_u8PinNo , u8 Cpy_u8PinDirection);

/**************************************************************************************/
/* Description    :  This Function Set The Pin value in The Run Time	                         */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo, Cpy_u8PinLevel] 			            			                         */
/* return         : void						                                         */
/**************************************************************************************/

void Dio_VoidSetPinValue(u8 Cpy_u8PortID , u8 Cpy_u8PinNo , u8 Cpy_u8PinLevel);


/**************************************************************************************/
/* Description    :  This Function Set The Pin value in The Run Time                  */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo] 			                          */
/* return         : u8 Pin_Value High Or Low					                                  */
/**************************************************************************************/
u8 Dio_u8GetPinValue(u8 Cpy_u8PortID ,u8 Cpy_u8PinNo );

void Dio_VoidTogglePinValue(u8 Cpy_u8PortID ,u8 Cpy_u8PinNo);

/**************************************************************************************/
/* Description    :  This Function Set The Port Direction in The Run Time             */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PortDirection]                 		      */
/* return         : void						                                      */
/**************************************************************************************/
void Dio_VoidSetPortDirecton(u8 Cpy_u8PortID , u8 Cpy_u8PortDirection);

/***********************************************************************/
/* Description    : This Function used to write values on BITS Value   */
/* Inputs         : Cpy_u8Port ,Cpy_u8Mask, Cpy_u8Value         	   */
/* return         : void						                       */
/***********************************************************************/
void Dio_voidWriteBitsInPort(u8 Cpy_u8PortID ,  u8 Cpy_u8Mask , u8 Cpy_u8Value );

/*****************************************************************************/
/* Description    :  This Function Set The Port HIGH/LOW at Run Time         */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PortValue]                   	 */
/* return         : void						                             */
/*****************************************************************************/
void Dio_VoidSetPortValue(u8 Cpy_u8PortID , u8 Cpy_u8PortValue);

/*********************************************************************/
/* Description    :  This Function used to write value on port	     */
/* Inputs         :  [port number,  PortValue]                   	 */
/* return         :  void						                     */
/*********************************************************************/
void Dio_VoidWritePortValue(u8 Cpy_u8PortID , u8 Cpy_u8PortValue);
/**************************************************************************************/
/* Description    :  This Function Set The Port Value at The Run Time                 */
/* Inputs         : [ Cpy_u8PortID]             					    		      */
/* return         : u8 Port_Value High Or Low				                          */
/**************************************************************************************/
u8 Dio_u8GetPortValue(u8 Cpy_u8PortID);

void Dio_vidTogglePort(u8 Cpy_u8PortID);


#endif
