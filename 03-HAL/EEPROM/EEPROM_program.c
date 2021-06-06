/*
 *      Description : EEPROM_program.c , file contain implementation EEPROM functions
 *      Created on  : 19/8/2020
 *      Author      : zaki ahmed hamed
 *		Version		: V02
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_Interface.h"
#include"eeprom.h"



void EEPROM_init(void)
{
	/* just initialize the I2C(TWI) module inside the MC */
	I2C_voidInit();
}

void EEPROM_write( u16 address ,u8 data)
{

	/* Send the Start Bit */
	 I2C_voidStart();

	  /* Send the device address, we need to get A0 A1 A2 address bits from the
	  * memory location address and R/W=0 (write) */
	 I2C_WriteByte((u8)(0xA0 | ((address & 0x0700)>>7)));
	 /* Send the required memory location address */
	 I2C_WriteByte((u8)(address));
	 /* write byte to EEPROM */
	 I2C_WriteByte(data);
	 /* Send the Stop Bit */
	 I2C_voidStop();
}

void EEPROM_read( u16 address , u8 * data)
{
	/* Send the Start Bit */
	I2C_voidStart();

	 /* Send the device address, we need to get A0 A1 A2 address bits from the
	 * memory location address and R/W=0 (write) */
	I2C_WriteByte((u8)(0xA0 | ((address & 0x0700)>>7)));
	 /* Send the required memory location address */
	I2C_WriteByte((u8)(address));
	 /* Send the Repeated Start Bit */
	I2C_voidStart();
	 /* Send the device address, we need to get A0 A1 A2 address bits from the
	 * memory location address and R/W=1 (Read) */
	 I2C_WriteByte((u8)(0xA0 | ((address & 0x0700)>>7)| 1));
	 /* Read Byte from Memory without send ACK */
	 *data=I2C_u8Read_Ack();
	 /* Send the Stop Bit */
	 I2C_voidStop();

}


void EEPROM_PageWrite(u16 address, char*data)
{
	u8 i=0;
	/* Send the Start Bit */
	 I2C_voidStart();
	  /* Send the device address, we need to get A0 A1 A2 address bits from the
	  * memory location address and R/W=0 (write) */
	 I2C_WriteByte((u8)(0xA0 | ((address & 0x0700)>>7)));
	 /* Send the required memory location address */
	 I2C_WriteByte((u8)(address));
	 while(data[i]!='\0')
	 {
	 /* write byte to EEPROM */
		 I2C_WriteByte(data[i]);
	 i++;
	 }
	 data[i]='\0';
	 I2C_WriteByte(data[i]);
	 /* Send the Stop Bit */
	 I2C_voidStop();
}
char *EEPROM_PageRead(u16 address,  u8*  data)
{
	u8 i=0;
	/* Send the Start Bit */
	I2C_voidStart();
	  /* Send the device address, we need to get A0 A1 A2 address bits from the
	  * memory location address and R/W=0 (write) */
	 I2C_WriteByte((u8)(0xA0 | ((address & 0x0700)>>7)));
	 /* Send the required memory location address */
	 I2C_WriteByte((u8)(address));
	    /* Send the Repeated Start Bit */
	 I2C_voidStart();
	    /* Send the device address, we need to get A0 A1 A2 address bits from the
	     * memory location address and R/W=1 (Read) */
	 I2C_WriteByte((u8)(0xA0 | ((address & 0x0700)>>7)| 1));
	    /* Read Byte from Memory without send ACK */
	 data[i]= I2C_u8Read_Ack();
	 while(data[i]!='\0')
	 	{
		 	i++;
		 	data[i]=I2C_u8Read_Ack();
	 	}
	 data[i]='\0';

	 I2C_voidStop();

	return data;
}
