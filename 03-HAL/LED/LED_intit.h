#ifndef _LED_H
#define _LED_H

#define LED_PORT  DIO_U8_PORT_C


/**************************************************************/
/*	Description : function usde to initilaze Led pin direction*/
/*	Input		: void										  */
/*	Return      : void										  */
/**************************************************************/
void LED_voidLedInit(void);


/*****************************************************/
/*	Description : function usde to Set Led high   	 */
/*	Input		: pin number						 */
/*	Return      : void								 */
/*****************************************************/
void LED_voidLedON( u8 Cpy_u8PinNo );
/*****************************************************/
/*	Description : function usde to Set Led low		 */
/*	Input		: pin number						 */
/*	Return      : void								 */
/*****************************************************/
void LED_voidLedOFF( u8 Cpy_u8PinNo );

#endif
