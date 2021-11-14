
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Privatee.h"
#include"DIO_Interface.h"
#include"I2C_Interface.h"

void I2C_voidInit(Prescaler_t Prescale ,INTState_t State ,u8 Address )
{
	/* write address */
	TWAR = (Address<<1);

	//check Prescaler
	TWSR |= (Prescale & 0x03);
	/* Get bit rate register value by formula */
	TWBR =(u8)BITRATE;
	TWCR |= (1<<TWEN) | (State & 0x01) ;

}

void I2C_voidStart(void)
{
	/* Enable TWI, generate start condition and clear interrupt flag */
	TWCR &= 0X07;
	TWCR |=(1<<TWINT)|(1<<TWSTA);
		
	/* Wait until TWI finish its current job (start condition) */
	while(!(GET_BIT(TWCR , TWINT)));

}

void I2C_voidStop(void)
{
	/* Enable TWI, generate stop condition and clear interrupt flag */
	TWCR &= 0X07;
	TWCR |=(1<<TWINT)|(1<<TWSTO);
	/* Wait until TWI finish its current job (stop condition) */
	while(!(GET_BIT(TWCR , TWINT)));
}

void I2C_Wait(void)
{
	while(!(GET_BIT(TWCR , TWINT)));
}

void I2C_Write(u8 Cpy_Data)
{
	/* Copy data in TWI data register */
	TWDR = Cpy_Data;
	/*clear interrupt flag */
	SET_BIT(TWCR , TWINT);
}


u8 I2C_u8Read_Ack(void)
{
	TWCR &= 0X07;
	/*enable TWI ,Clear interrupt flag and Generation of ACK */
	TWCR |= (1<<TWINT)|(1<<TWEA);
	/* Wait until TWI finish its current job (read opeation) */
	while(!(GET_BIT(TWCR , TWINT)));
	/* Return received data */
	return TWDR;
}

u8 I2C_u8Read_NAck(void)
{
	TWCR &= 0X07;
	/*enable TWI ,Clear interrupt flag and Generation of ACK */
	TWCR |= (1<<TWINT);
	/* Wait until TWI finish its current job (read opeation) */
	while(!(GET_BIT(TWCR , TWINT)));
	/* Return received data */
	return TWDR;
}


u8 I2C_GetStatus(void)
{
	//Local variable to store status
	u8 LOC_Status;
	/* Read TWI status register with masking lower three bits */
	LOC_Status = (TWCR & 0xF8);
	//return status
	return LOC_Status;
}


I2C_States I2C_BytesWrite(u8 SL_Address,u8 Reg_Address ,u8 Data)
{
	/* start condition */
	/* SL_Address+W    */
	/* read address    */
	/* wait ACK        */
	/* Byte to write   */
	/* wait ACK 	   */
	/* stop condition  */
	I2C_voidStart();

	if( I2C_GetStatus() != TWI_START)
	{
		/* error occure */
		I2C_voidStop();
		return I2C_GetStatus();
	}
	
	I2C_Write( (SL_Address<<1) );
	
	if(I2C_GetStatus() != TWI_MT_SLA_W_ACK)
	{
		/* error occure */
		I2C_voidStop();
		/* return status */
		return I2C_GetStatus();
	}
	I2C_Write( Reg_Address );
	
	if(I2C_GetStatus() != TWI_MT_DATA_ACK)
	{
		/* error occure */
		I2C_voidStop();
		/* return status */
		return I2C_GetStatus();
	}
	I2C_Write( Data );

	if(I2C_GetStatus() != TWI_MT_DATA_ACK)
	{
		/* error occure */
		I2C_voidStop();
		/* return status */
		return I2C_GetStatus();
	}

	I2C_voidStop(); // Send A stop  // Release The Clock Bus 
	return 0;	
}

I2C_States I2C_BytesRead(u8 SL_Address,u8 Reg_Address ,u8 *DataReceive)
{
	/* start condition       */
	/* send SL_Address+W     */
	/* send Reg_Address      */
	/* send repeated start   */
	/* send SL_Address+W     */
	/* read data with no ack */
	/* stop condition  		 */
	I2C_voidStart();
	
	if( I2C_GetStatus() != TWI_START )
	{
		I2C_voidStop();
		return I2C_GetStatus();
		
	}
	I2C_Write( (SL_Address<<1));
	
	if( I2C_GetStatus() != TWI_MT_SLA_W_ACK )
	{
		I2C_voidStop();
		return I2C_GetStatus();
		
	}
	I2C_Write( Reg_Address);
	
	if( I2C_GetStatus() != TWI_MT_DATA_ACK )
	{
		I2C_voidStop();
		return I2C_GetStatus();
		
	}
	I2C_voidStart(); /*send repeated start*/	
	
	if( I2C_GetStatus() != TWI_REP_START )
	{
		I2C_voidStop();
		return I2C_GetStatus();
		
	}
	I2C_Write( ((SL_Address<<1) | READ) );
	
	if( I2C_GetStatus() != TWI_MT_SLA_R_ACK)
	{
		I2C_voidStop();
		return I2C_GetStatus();		
	}
	
	*DataReceive = I2C_u8Read_NAck();
	I2C_voidStop();
	return 0;
	
}
