#ifndef	I2C_INTERFACE_H	
#define I2C_INTERFACE_H
/*
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include"I2C_Config.h"
*/

/* Define CPU clock Frequency e.g. here its 8MHz */
#define F_CPU	8000000UL

/* Define SCL clock frequency */
#define F_SCL	400000UL

#define BITRATE ((((F_CPU / F_SCL) / TWI_PRESCALLER) - 16 ) / 2)

//#define BITRATE ((F_CPU / F_SCL) - 16) / (2 * TWI_PRESCALLER)


/****************************************************************
 *  Description : I2C initialize function						*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_voidInit(void);

/****************************************************************
 *  Description : I2C start condition function  				*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_voidStart(void);

/****************************************************************
 *  Description : I2C stop condition function  					*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_voidStop(void);
/****************************************************************
 *  Description : I2C wait function				  				*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_Wait(void);

/****************************************************************
 *  Description : This function write data/address on bus	  	*
 *  Input		: it has input argument of data/address.		*
 *  Return		: it returns status of event					*
 ***************************************************************/
u8 I2C_WriteByte(u8 Cpy_Data);

/****************************************************************
 *  Description : I2C Read acknowledge function		     		*
 *  Input		: void											*
 *  Return		: Return received data[TWDR]					*
 ***************************************************************/
u8 I2C_u8Read_Ack(void);

/****************************************************************
 *  Description : I2C Read Not acknowledge function		   		*
 *  Input		: void											*
 *  Return		: Return received data[TWDR]					*
 ***************************************************************/
u8 I2C_u8Read_NAck(void);


/****************************************************************
 *  Description : I2C repeated start function 					*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_Repeated_Start(void);

/****************************************************************
 *  Description : I2C Get status function	 					*
 *  Input		: void											*
 *  Return		: Status TWI									*
 ***************************************************************/
u8 I2C_GetStatus(void);

/***********************TWI Bit Rate Prescaller Macros*****************/

#define	PRESCALER1		1
#define	PRESCALER4		4
#define	PRESCALER16		16
#define	PRESCALER64		64
/*
typedef enum
{
	PRESCAL1,PRESCAL4,PRESCAL16,PRESCAL164
}PRESCALLER;*/
/***********************************************************************/

/*Acks for MT
	0x18 Check weather SLA+W transmitted & ack received or not?*/
#define	I2C_MT_SLA_W_ACK	0x18

/* 0x30	Check weather data transmitted & nack received or not?*/
#define	I2C_MT_DATA_NACK	0x30
/* 0x28	Check weather data transmitted & ack received or not?*/
#define	I2C_MT_DATA_ACK		0x28
/*0x20	Check weather SLA+R transmitted & nack received or not?*/
#define	I2C_MT_SLA_R_NACK	0x20
/*0x40	Check weather SLA+R transmitted & ack received or not?*/
#define	I2C_MT_SLA_R_ACK	0x40

#define	I2C_MR_DATA_NACK	0x58

/* Ack for start and Repeated start
0x08 Check weather start condition transmitted successfully or not?*/
#define I2C_SC_ACK          0x08
 /*0x10	Check weather repeated start condition transmitted successfully or not?*/
#define I2C_RESC_ACK        0x10

#define	CHECK_STATUS		0xF8

#endif /*I2C_INTERFACE_H */	
