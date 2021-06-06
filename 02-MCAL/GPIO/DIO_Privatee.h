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

#ifndef  DIO_REGISTER_H_
#define  DIO_REGISTER_H_

/*************************************************************************************
*     Description : Memory Mapping I/O Preipheral                                    *
*                                                                                    *
*************************************************************************************/

/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT A    								 *
*************************************************************************************/

#define	 	PORTA_REGISTER  *((volatile u8*)(0x3B))
#define 	DDRA_REGISTER   *((volatile u8*)(0x3A))
#define		PINA_REGISTER   *((volatile u8*)(0x39))


/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT B    								 *
*************************************************************************************/
#define	 	PORTB_REGISTER  *((volatile u8*)(0x38))
#define 	DDRB_REGISTER   *((volatile u8*)(0x37))
#define		PINB_REGISTER   *((volatile u8*)(0x36))

/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT C    								 *
*************************************************************************************/


#define	 	PORTC_REGISTER  *((volatile u8*)(0x35))
#define 	DDRC_REGISTER   *((volatile u8*)(0x34))
#define		PINC_REGISTER   *((volatile u8*)(0x33))


/*************************************************************************************
*     Description : REGISTER ADDERSSES FOR PORT D    								 *
*************************************************************************************/
#define	 	PORTD_REGISTER  *((volatile u8*)(0x32))
#define 	DDRD_REGISTER   *((volatile u8*)(0x31))
#define		PIND_REGISTER   *((volatile u8*)(0x30))

/*	SPI	 */


/***********************************************************************************
*   Description : SPI Control Register – (SPCR) Contains 7 Bits[                   *
*                  Bit 7 – SPIE: SPI Interrupt Enable                              *
*				   Bit 6 – SPE : SPI Enable                                        *
*				   Bit 5 – DORD: Data Order                                        *
*				   Bit 4 – MSTR: Master/Slave Select                               *
*				   Bit 3 – CPOL: Clock Polarity                                    *
*				   Bit 2 – CPHA: Clock Phase                                       *
*				   Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0]          *
*	Page Number : 134 in Data sheet			                                       *
***********************************************************************************/


#define SPCR  			(*((volatile u8 * )(0x2D)))

/********************************************************************************
*   Description : SPI Status Register – (SPSR) Contains 8 Bits[ we uses 3 Bits  *
*                  • Bit 7 – SPIF: SPI Interrupt Flag                         	*
*				   • Bit 6 – WCOL: Write COLlision Flag                       	*
*				   • Bit 0 – SPI2X: Double SPI Speed Bit                      	*
*				                                                                *
*	Page Number : 136 in Data sheet			                                    *
********************************************************************************/
#define SPSR   			(*((volatile u8 * )(0x2E)))


/**********************************************************************************
*   Description : SPI Data Register– (SPDR)                                      *
*                 The SPI Data Register is a read/write register used for         *
*                 data transfer between the Register File and the SPI Shift       *
*				  Register. Writing to the register initiates data transmission.  *
*                 Reading the register causes the Shift Register Receive buffer   *
*				  to be read.                                                     *
*				                                                                  *
*	Page Number : 136 in Data sheet			                                      *
*                                                                                 *
**********************************************************************************/

#define		 SPDR     		(*((volatile u8 * )(0x2F)))
/********************************************************************************
*			SPI Control Register – SPCR[Bits]									*
********************************************************************************/
#define 	SPIE	7
#define		SPE     6
#define		DORD	5
#define		MSTR 	4
#define		CPOL	3
#define		CPHA	2
#define		SPR1	1
#define 	SPR0	0
 
 
/********************************************************************************
*			SPI Status Register – SPSR[Bits]									*
********************************************************************************/ 
#define 	SPIF	7
#define 	WCOL	6
#define		SPI2X	0

/*********************************************************
*		I2C Register Description						 *
*********************************************************/


#define		TWBR  	(*(volatile u8*)(0x20))

/*********************************************************
*		TWBR Register Bits Description					 *
*********************************************************/
#define 	TWBR7	7 
#define 	TWBR6	6
#define		TWBR5   5
#define		TWBR4	4 
#define		TWBR3	3
#define		TWBR2	2 
#define		TWBR1	1
#define		TWBR0	0
/**********************************************************/


/**********************************************************
*			TWI Control Register – TWCR					  *		
**********************************************************/

#define 	TWCR  (*(volatile u8*)(0x56))

/**************TWCR Register Bits Description**************/

#define		TWINT	7
#define		TWEA	6
#define		TWSTA	5
#define		TWSTO	4
#define		TWWC	3
#define		TWEN	2
#define		TWIE	0

/**********************************************************
*			TWI Status Register – TWSR					  *		
**********************************************************/

#define		TWSR		(*(volatile u8*)(0x21))

/**************TWSR Register Bits Description**************/

#define		TWS7	7 
#define		TWS6	6 
#define		TWS5 	5
#define		TWS4 	4
#define		TWS3  	3
#define		TWPS1	1
#define		TWPS0	0

/**********************************************************
*			TWI Data Register – TWDR					  *		
**********************************************************/

#define		TWDR		(*(volatile u8*)(0x23))

/**************TWDR Register Bits Description**************/

#define		TWD7	7 
#define		TWD6 	6
#define		TWD5 	5
#define		TWD4 	4
#define		TWD3	3
#define		TWD2 	2
#define		TWD1 	1
#define		TWD0	0

/**********************************************************
*			TWI (Slave) Address Register– TWAR			  *		
**********************************************************/

#define		TWAR		(*(volatile u8*)(0x22))

/**************TWAR Register Bits Description**************/

#define		TWA6	7 
#define		TWA5 	6
#define		TWA4 	5
#define		TWA3	4
#define		TWA2 	3
#define		TWA1 	2
#define		TWA0 	1
#define		TWGCE	0









#endif
