#ifndef	I2C_INTERFACE_H	
#define I2C_INTERFACE_H



/* Define CPU clock Frequency  here its 8MHz */
#define F_CPU	8000000UL


//#define BITRATE ((((F_CPU / F_SCL) / Prescale) - 16 ) / 2)
//#define BITRATE = ((F_CPU / SCLfreq) - 16) / (2 * TWI_PRESCALLER)


typedef enum {
	
	I2C_PRESCALE1,
	I2C_PRESCALE4,
	I2C_PRESCALE16,
	I2C_PRESCALE64,
	
}Prescaler_t;

/* I2C Status Bits in the TWSR Register */
typedef enum { 
	
	TWI_START		   =0x08,  /* Check weather Ack for start and Repeated start 0x08 Check weather start condition transmitted successfully or not?*/
	TWI_REP_START 	   =0x10,  /* Check weather repeated start condition transmitted successfully or not?*/
	TWI_MT_SLA_W_ACK   =0x18,  /* Check weather Acks for MT 0x18 Check weather SLA+W transmitted & ack received or not?*/
	TWI_MT_SLA_R_ACK   =0x40,  /* Check weather SLA+R transmitted & ack received or not?*/
	TWI_MT_DATA_ACK    =0x28,  /* Check weather data transmitted & ack received or not?*/
	TWI_MR_DATA_ACK    =0x50,  /* Check weather Master received data and send ACK to slave */
	TWI_MR_DATA_NACK   =0x58,  /* Check weather Data byte has been received NOT ACK has been returned */
	TWI_MT_SLA_W_NACK  =0x20,  /* Check weather SLA+R transmitted & nack received or not?*/
	TWI_MT_DATA_W_NACK =0x30,  /* Check weather data transmitted & nack received or not? */
	TWI_MT_SLA_ARB_LOST=0x38,  /* Check weather Arbitration lost in SLA+W or databytes */
	TWI_MT_SLA_R_NACK  =0x48,  /* Check weather SLA+R has been transmitted NOT ACK has been received*/

}I2C_States;

typedef enum {

	WRITE=0,
	READ=1

}ADDRESS_Mode;

typedef enum {

	intDisable = 0x00,
	intEnable= 0x01,

}INTState_t;


void I2C_voidInit(Prescaler_t Prescale ,INTState_t State , u32 F_SCL ,u8 Address );
void I2C_voidStart(void);


void I2C_voidStop(void);

void I2C_Wait(void);

void I2C_Write(u8 Cpy_Data);


u8 I2C_u8Read_Ack(void);

u8 I2C_u8Read_NAck(void);


u8 I2C_GetStatus(void);

I2C_States I2C_BytesWrite(u8 SL_Address,u8 Reg_Address , u8 Data);

I2C_States I2C_BytesRead(u8 SL_Address,u8 Reg_Address ,u8 *DataReceive);


#endif /*I2C_INTERFACE_H */	
