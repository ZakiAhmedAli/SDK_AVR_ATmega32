


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include "DIO_Privatee.h"
#include <util/delay.h>
#include"SPI.h"



/****************************************************************/
/* Description    :  This function  Initialize SPI Master Device*/
/* Inputs 		  :  pointer to struct to set Frequency		    */
/* return 		  :  void								  	    */
/****************************************************************/

void SPI_voidInitMaster(SPI_ConfigType *Config_Freq)
{
	/*set SS as output*/
	Dio_VoidSetPinDirection(DIO_U8_PORT_B , DIO_U8_PIN_4 , DIO_U8_OUTPUT);
	 /* set MOSI as output*/
	Dio_VoidSetPinDirection(DIO_U8_PORT_B , DIO_U8_PIN_5 , DIO_U8_OUTPUT);
	 /* set MISO as input*/
	Dio_VoidSetPinDirection(DIO_U8_PORT_B , DIO_U8_PIN_6 , DIO_U8_INPUT);
	 /* set SCK as output*/
	Dio_VoidSetPinDirection(DIO_U8_PORT_B , DIO_U8_PIN_7 , DIO_U8_OUTPUT);

		/*
		 * enable SPI
		 * enable master
		 * set frequancy
	*/
	SPCR = (1<<SPE)|(1<<MSTR)|(Config_Freq->frequency<<SPR0);


	/*set MSB is transmitted first*/
	CLR_BIT(SPCR , DORD);

	 /* SCK is low when idl*/
	CLR_BIT(SPCR , CPOL);

}
/********************************************************************/
/* Description    :  This function  Initialize SPI Slave Device		*/
/* Inputs 		  :  pointer to struct to set Frequency		        */
/* return 		  :  void									  	    */
/********************************************************************/
void SPI_voidInitSlave(SPI_ConfigType *Config_Freq)
{
	/*set SS as input*/
	Dio_VoidSetPinDirection(DIO_U8_PORT_B , DIO_U8_PIN_4 , DIO_U8_INPUT);
	 /* set MOSI as input*/
	Dio_VoidSetPinDirection(DIO_U8_PORT_B , DIO_U8_PIN_5 , DIO_U8_INPUT);
	 /* set MISO as output*/
	Dio_VoidSetPinDirection(DIO_U8_PORT_B , DIO_U8_PIN_6 , DIO_U8_OUTPUT);
	 /* set SCK as input*/
	Dio_VoidSetPinDirection(DIO_U8_PORT_B , DIO_U8_PIN_7 , DIO_U8_INPUT);

	/*
	 * enable SPI
	 * enable slave
	 * set frequency
*/
SPCR = (1<<SPE)|(Config_Freq->frequency<<SPR0);

/*get LSB is first*/
CLR_BIT(SPCR , DORD);

/* SCK is low when idle */
CLR_BIT(SPCR , CPOL);

}

/********************************************************************/
/* Description    :  This function to transmit Byte					*/
/* Inputs 		  :  It has input argument of data to be transmit.  */
/* return 		  :  void									  	    */
/********************************************************************/
void SPI_voidSendByte(u8 Cpy_u8Data)
{

	/* Wait for transmission complete */
	while( !(SET_BIT(SPSR,SPIF)));
	/* Start transmission */
	SPDR = Cpy_u8Data;
}

/********************************************************************/
/* Description    :  This function to transmit string				*/
/* Inputs 		  :  It has input argument of data to be transmit.  */
/* return 		  :  void									  	    */
/********************************************************************/
void SPI_voidSendString(u8 *Cpy_u8Data)
{
	u8 Loc_u8Counter=0;
	while(Cpy_u8Data[Loc_u8Counter] != '\0')
	{
		SPI_voidSendByte(Cpy_u8Data[Loc_u8Counter] );
		Loc_u8Counter++;
		/*
		 * while(*Cpy_u8Data > 0)
		 * SPI_u8SendByte(*Cpy_u8Data++);
		 * */
	}
}

/********************************************************************/
/* Description    :  This function to Receiving Byte				*/
/* Inputs 		  :  void										  	*/
/* return 		  :  u8: data it recived					  	    */
/********************************************************************/
u8 SPI_u8ReciveByte(void)
{
	while(CLR_BIT(SPSR , SPIF));
	return SPDR;
}

/********************************************************************/
/* Description    :  This function to Receiving string				*/
/* Inputs 		  :  void										  	*/
/* return 		  :  u8: data it recived					  	    */
/********************************************************************/
void SPI_voidReciveString(u8 *Cpy_u8Data)
{
	u8 Loc_u8Counter=0;
/*
	Cpy_u8Data[Loc_u8Counter] = SPI_u8ReciveByte();
	do
	{
		Loc_u8Counter++;
		Cpy_u8Data[Loc_u8Counter] = SPI_u8ReciveByte();

	}while(Cpy_u8Data[Loc_u8Counter-1] != '\r');
*/
	Cpy_u8Data[Loc_u8Counter] = SPI_u8ReciveByte();
	while(Cpy_u8Data[Loc_u8Counter] != '\r')
	{
		Loc_u8Counter++;
		Cpy_u8Data[Loc_u8Counter] = SPI_u8ReciveByte();
	}
	Cpy_u8Data[Loc_u8Counter] = '\0';

}


