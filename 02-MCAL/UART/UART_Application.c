#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Interface.h"
#include "UART_private.h"




void USART_initialization(u16 USART_BAUDRATE ,Character_Size Size ,StopBits Bits,ParityMode Mode)
{
	u8 LOC_U8UCSRC_Temp;
	//recive Enable
	SET_BIT(UCSRB , 4);
	//Transmit sEnable
	SET_BIT(UCSRB , 3);

	switch(Size)
	{
		case FIVE_BITS :
			CLR_BIT(UCSRB , UCSZ0);
			CLR_BIT(LOC_U8UCSRC_Temp , UCSZ1);
			CLR_BIT(LOC_U8UCSRC_Temp , UCSZ2);
			break;

		case SIX_BITS  :
			SET_BIT(UCSRB , UCSZ0);
			CLR_BIT(LOC_U8UCSRC_Temp , UCSZ1);
			CLR_BIT(LOC_U8UCSRC_Temp , UCSZ2);
			break;

		case SEVEN_BITS:
			CLR_BIT(UCSRB , UCSZ0);
			SET_BIT(LOC_U8UCSRC_Temp , UCSZ1);
			CLR_BIT(LOC_U8UCSRC_Temp , UCSZ2);
			break;

		case EIGHT_BITS:
			SET_BIT(LOC_U8UCSRC_Temp , UCSZ0);
			SET_BIT(LOC_U8UCSRC_Temp , UCSZ1);
			CLR_BIT(UCSRB , UCSZ2);
			break;
		case NINE_BITS :
			SET_BIT(UCSRB , UCSZ0);
			SET_BIT(LOC_U8UCSRC_Temp , UCSZ1);
			SET_BIT(LOC_U8UCSRC_Temp , UCSZ2);
			break;
		default :/*NOT HERE*/ break;
	}
	switch(Bits)
	{
			case ONE_BIT :CLR_BIT(LOC_U8UCSRC_Temp , USBS); break;
			case TWO_BOTS:SET_BIT(LOC_U8UCSRC_Temp , USBS); break;
			default:/*nOT HERE*/break;
	}

	switch(Mode)
	{
			case DISABLE_PARITY:
				CLR_BIT(LOC_U8UCSRC_Temp , UPM0);
				CLR_BIT(LOC_U8UCSRC_Temp , UPM1);
				break;

			case ENABLE_EVEN_PARITY:
				CLR_BIT(LOC_U8UCSRC_Temp , UPM0);
				SET_BIT(LOC_U8UCSRC_Temp , UPM1);
				break;

			case ENABLE_ODD_PARITY:
				SET_BIT(LOC_U8UCSRC_Temp , UPM0);
				SET_BIT(LOC_U8UCSRC_Temp , UPM1);
				break;
			default: /*NOT HERE*/break;
	}

	/* Load UBRRL with lower 8 bit of prescale value */
	UBRRL =(u8) BAUD_PRESCALE;
	/* Load UBRRH with upper 8 bit of prescale value */
	UBRRH = (u8)(BAUD_PRESCALE >> 8);


	/****************************************************************/
	/** !comment :Bit 7 – URSEL: Register Select					*/
	/** 		  This bit selects between accessing the UCSRC or 	*/
	/*							the UBRRH Register.					*/
	/*				It is read as one when reading UCSRC.			*/
	/*				The URSEL must be one when writing the UCSRC.	*/
	/****************************************************************/
	SET_BIT(LOC_U8UCSRC_Temp ,7);

	/****************************************************************/
	/** !comment :    UCSRC  : USART control and status Registe		*/
	/** 		  	Force Acesses to UCSRC Register because sharing */
	/*				the	same I/O location with UBBRH.				*/
	/****************************************************************/
	UCSRC= LOC_U8UCSRC_Temp;
}

/* Data transmitting function */
void USART_voidTransmit_Char(u8 Copy_u8Data)
{
	/* Write data to be transmitting in UDR */
	UDR= Copy_u8Data;
	// check if USART Data Register Empty[bit5]
		while( !(GET_BIT(UCSRA , 5))  );

}

/* Send string of USART data function */
void USART_voidTransmit_String(u8 *Copy_u8Str)
{
	while(*Copy_u8Str > 0)
		USART_voidTransmit_Char(*Copy_u8Str++);
}

/* Data receiving function */
u8 USART_u8RXChar(void)
{
	/* Wait until new data receive */
	while( !(GET_BIT(UCSRA , 7)) );

	/* Get and return received data */
     return (UDR);
}
/*
void UART_recieveString(u8 * Str_Ptr)
{
	u8 i = 0;
	do
	{
		Str_Ptr[i] = USART_u8RXChar();

		i++;
	}while(Str_Ptr[i-1] != '\r');

	Str_Ptr[i] = '\0';
}
*/
void UART_recieveString(u8 * Str_Ptr)
{
	u8 i = 0;
	Str_Ptr[i] = USART_u8RXChar();
	while(Str_Ptr[i] != '\r')
	{
		i++;
		Str_Ptr[i] = USART_u8RXChar();
	}

	Str_Ptr[i] = '\0';
}

