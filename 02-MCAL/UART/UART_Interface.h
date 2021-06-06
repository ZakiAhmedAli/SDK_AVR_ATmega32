/********************************************************************/
/*	Auther	    : zaki ahmed									  	*/
/*  Date 	    : 18 Jul 2020								  		*/
/*  Description : UART_interface file function prototype		    */
/*  Version     : V01											  	*/
/********************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/
#ifndef _USART_INTERFASE_H
#define _USART_INTERFASE_H
#define F_CPU 8000000UL

//#define USART_BAUDRATE 9600
// BAUDRATE equation
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


typedef enum
{
	FIVE_BITS,
	SIX_BITS,
	SEVEN_BITS,
	EIGHT_BITS,
	NINE_BITS
}Character_Size;

typedef enum
{
	ONE_BIT,
	TWO_BOTS
}StopBits;

typedef enum
{
	DISABLE_PARITY,
	ENABLE_EVEN_PARITY=2,
	ENABLE_ODD_PARITY
	
}ParityMode;

/************************************************************************/
/* Description	: USART initialize function								*/
/* Input 		: BAUDRATE,Character_Size ,StopBits  , ParityMode		*/
/* Return		: void													*/
 /***********************************************************************/
void USART_initialization(u16 USART_BAUDRATE,Character_Size Size ,StopBits Bits , ParityMode Mode );

/************************************************************************/
/* Description	: Data transmitting function 							*/
/* Input 		: Copy_u8Data to send									*/
/* Return		: void													*/
 /***********************************************************************/
void USART_voidTransmit_Char(u8 Copy_u8Data);

/************************************************************/
/* Description	: Send string of USART data function 	   	*/
/* Input 		: string to send							*/
/* Return		: void					  					*/
 /***********************************************************/
void USART_voidTransmit_String(u8 *Copy_u8Str);



/************************************************************/
/* Description	: Data receiving function	 		 	   	*/
/* Input 		: void										*/
/* Return		: receiving data		  					*/
 /***********************************************************/
u8 USART_u8RXChar(void);

/************************************************************/
/* Description	: this functoin used to receiving string  	*/
/* Input 		: Str_Ptr to receiving tring				*/
/* Return		: void		  								*/
 /***********************************************************/
void UART_recieveString(u8 * Str_Ptr);




#endif//_USART_INTERFASE_H
