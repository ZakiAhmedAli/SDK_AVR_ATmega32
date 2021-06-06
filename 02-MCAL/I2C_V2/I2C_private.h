#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H


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


#endif
#define		TWBR1	1
#define		TWBR0	0
/**********************************************************/


/**********************************************************
*			TWI Control Register â€“ TWCR					  *		
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
*			TWI Status Register â€“ TWSR					  *		
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
*			TWI Data Register â€“ TWDR					  *		
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
*			TWI (Slave) Address Registerâ€“ TWAR			  *		
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
