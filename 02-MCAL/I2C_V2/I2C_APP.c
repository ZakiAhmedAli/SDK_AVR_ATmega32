
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_Privatee.h"
#include"DIO_Interface.h"
#include"I2C_Config.h"		/* Include I2C configuration file */
#include "I2C_Interface.h"	/* Include I2C header file */


/****************************************************************
 *  Description : I2C initialize function						*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_voidInit(void)
{
		//check Prescaler
	#if	(TWI_PRESCALLER == PRESCALER1)
			CLR_BIT(TWSR , TWPS0);
			CLR_BIT(TWSR , TWPS1);

	#elif (TWI_PRESCALLER == PRESCALER4)
				SET_BIT(TWSR , TWPS0);
				CLR_BIT(TWSR , TWPS1);

	#elif (TWI_PRESCALLER == PRESCALER16)
				CLR_BIT(TWSR , TWPS0);
				SET_BIT(TWSR , TWPS1);

	#elif (TWI_PRESCALLER == PRESCALER64)
				SET_BIT(TWSR , TWPS0);
				SET_BIT(TWSR , TWPS1);
#endif
		/* Get bit rate register value by formula */

	TWBR = (u8)BITRATE;
	TWSR = 0x00;
	 TWCR=(1<<TWEN);

}
/****************************************************************
 *  Description : I2C start condition function  				*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_voidStart(void)
{
	/* Enable TWI, generate start condition and clear interrupt flag */

		   TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
		/*SET_BIT(TWCR , TWEN);
		SET_BIT(TWCR , TWSTA);
		SET_BIT(TWCR , TWINT);
*/
		/* Wait until TWI finish its current job (start condition) */
		while(!GET_BIT(TWCR , TWINT));

}
/****************************************************************
 *  Description : I2C stop condition function  					*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_voidStop(void)
{
	/* Enable TWI, generate stop condition and clear interrupt flag */
	TWCR=(1<<TWSTO) | (1<<TWINT)| (1<<TWEN);

	/* Wait until TWI finish its current job (stop condition) */
	//while(!(GET_BIT(TWCR , TWINT)));
}
/****************************************************************
 *  Description : I2C wait function				  				*
 *  Input		: void											*
 *  Return		: void											*
 ***************************************************************/
void I2C_Wait(void)
{
	while(!(GET_BIT(TWCR , TWINT)));
}
/****************************************************************
 *  Description : I2C write data[send] function	  				*
 *  Input		: data in TWI data register						*
 *  Return		: TWI status register[TWSR]						*
 ***************************************************************/
u8 I2C_WriteByte(u8 Cpy_Data)
{
	u8 LOC_u8Status=0;
	/* Copy data in TWI data register */
	TWDR = Cpy_Data;

	/* Enable TWI and clear interrupt flag */
	 TWCR = (1 << TWINT) | (1 << TWEN);
	/*SET_BIT(TWCR , TWEN);
	SET_BIT(TWCR , TWINT);*/

	// Wait for TWINT flag set in TWCR Register
	while(!GET_BIT(TWCR , TWINT));

	/* 0x28	Check weather data transmitted & ack received or not?*/
	LOC_u8Status = (TWSR & CHECK_STATUS );

	if(LOC_u8Status == I2C_MT_DATA_ACK)
		return 0;/* Return 0 to indicate ack received */

	if(LOC_u8Status == I2C_MT_DATA_NACK)
		return 1;/* Return 1 to indicate nack received */

	else
		return 2;/* Else return 2 for data transmission failure */

}

/****************************************************************
 *  Description : I2C Read acknowledge function		     		*
 *  Input		: void											*
 *  Return		: Return received data[TWDR]					*
 ***************************************************************/
u8 I2C_u8Read_Ack(void)
{
	/*enable TWI ,Clear interrupt flag and Generation of ACK */
	TWCR =  (1<<TWEN) | (1<<TWINT)|(1<<TWEA);

	/* Wait until TWI finish its current job (read operation) */
	while(!(GET_BIT(TWCR , TWINT)));

	/* Return received data */
	return TWDR;
}
/****************************************************************
 *  Description : I2C Read Not acknowledge function		   		*
 *  Input		: void											*
 *  Return		: Return received data[TWDR]					*
 ***************************************************************/
u8 I2C_u8Read_NAck(void)
{
	/*enable TWI ,Clear interrupt flag and Generation of ACK */
	TWCR =(1 << TWINT) | (1 << TWEN);

	/* Wait until TWI finish its current job (read operation) */
	while( !(GET_BIT(TWCR , TWINT)) );

	/* Return received data */
	return TWDR;
}

void  I2C_Repeated_Start(void)
{
	u8 LOC_Status;
	/* Enable TWI, generate start condition and clear interrupt flag */
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);

	/* Wait until TWI finish its current job (start condition) */
	while (!(GET_BIT(TWCR,TWINT)));

	/* Read TWI status register with masking lower three bits */
	LOC_Status = (TWCR & CHECK_STATUS);

	/* Check weather repeated start condition transmitted successfully or not? */
	if(LOC_Status != I2C_RESC_ACK)
		/* If no then return 0 to indicate repeated start condition fail */
		return;
}
/****************************************************************
 *  Description : I2C Get status function	 					*
 *  Input		: void											*
 *  Return		: Status TWI									*
 ***************************************************************/
u8 I2C_GetStatus(void)
{
	//Local variable to store status
	u8 LOC_Status;
	/* Read TWI status register with masking lower three bits */
	LOC_Status = (TWCR & CHECK_STATUS);
	//return status
	return LOC_Status;
}

