/***********************************************************************/
/*	Auther	    : zaki ahmed hamed								  	   */
/*  Date 	    : 03 August 2020								  	   */
/*  Description : KPD_interface.h 									   */
/*  Version     : V01											       */
/***********************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef  _KEYPAD_H
#define  _KEYPAD_H



#define ROW_SIZE  4
#define COL_SIZE  4


/***************************************** Macros *****************/
#define KEYPAD_PORT		DIO_U8_PORT_A

#define COL_INIT       0

#define COL_FIN        4

#define ROW_INIT       4

#define ROW_FIN        8

#define NOT_PRESSED    0
/*******************************************************************/

/****************************************************************/
/*	Description : function used to init sequence Keypad			*/
/*	Input		: void											*/
/*	Return		: void											*/
/****************************************************************/	
void KPD_voidInit(void);


/****************************************************************/
/*	Description : function used to Get key is pressd			*/
/*	Input		: void											*/
/*	Return		: key pressed value							    */
/****************************************************************/
u8 KPD_u8GetPressed(void);


#endif

