/********************************************************************************
*     Author      : Zaki Ahmed hamed                                            *
*     Description : SPI Interface[APIs] 								        *
*     Date        : 20 June 2020                                                *
*     Version     : 2.0                                                         *
********************************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/

#ifndef SPI_H_
#define SPI_H_


typedef enum
{
	Fosc_4,
	Fosc_16,
	Fosc_64,
	Fosc_128,
	Fosc_2,
	Fosc_8,
	Fosc_32
}SCK_Frequency;

typedef struct
{
	SCK_Frequency frequency;

}SPI_ConfigType;


/****************************************************************/
/* Description    :  This function  Initialize SPI Master Device*/
/* Inputs 		  :  pointer to struct to set Frequency		    */
/* return 		  :  void								  	    */
/****************************************************************/
void SPI_voidInitMaster(SPI_ConfigType *Config_Freq);
/********************************************************************/
/* Description    :  This function  Initialize SPI Slave Device		*/
/* Inputs 		  :  pointer to struct to set Frequency		        */
/* return 		  :  void									  	    */
/********************************************************************/
void SPI_voidInitSlave(SPI_ConfigType *Config_Freq);
/********************************************************************/
/* Description    :  This function to transmit Byte					*/
/* Inputs 		  :  It has input argument of data to be transmit.  */
/* return 		  :  void									  	    */
/********************************************************************/
void SPI_voidSendByte(u8 Cpy_u8Data);

/********************************************************************/
/* Description    :  This function to transmit string				*/
/* Inputs 		  :  It has input argument of data to be transmit.  */
/* return 		  :  void									  	    */
/********************************************************************/
void SPI_voidSendString(u8 *Cpy_u8Data);
/********************************************************************/
/* Description    :  This function to Receiving Byte				*/
/* Inputs 		  :  void										  	*/
/* return 		  :  u8: Byte it recived					  	    */
/********************************************************************/
u8 SPI_u8ReciveByte(void);

/********************************************************************/
/* Description    :  This function to Receiving string				*/
/* Inputs 		  :  void										  	*/
/* return 		  :  u8: data it recived					  	    */
/********************************************************************/
void SPI_voidReciveString(u8 *Cpy_u8Data);
  


#endif /*SPI_H_*/
