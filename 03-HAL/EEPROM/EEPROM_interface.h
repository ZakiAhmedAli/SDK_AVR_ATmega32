/*
 *      Description : EEPROM_interface.h
 *      Created on  : 19/8/2020
 *      Author      : zaki ahmed hamed
 *		Version		: V02
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


/************ Function prototypes************/

/*
	Function Name        : EEPROM_init
	Function Returns     : void
	Function Arguments   : viod
	Function Description : call I2C initialize function 
*/
void EEPROM_init(void);
/*
	Function Name        : EEPROM_write
	Function Returns     : void
	Function Arguments   : u16 address ,u8 data
	Function Description : Write one byte to given address.
*/
void EEPROM_write( u16 address ,u8 data);

/*
	Function Name        : EEPROM_read
	Function Returns     : uint8
	Function Arguments   : u16 address , u8 * data
	Function Description : Read one byte from the given  address.
*/
void EEPROM_read( u16 address , u8 * data);
/*
	Function Name        : EEPROM_PageWrite
	Function Returns     : void
	Function Arguments   : u16 address, char*data
	Function Description : Write block of bytes  of the given address(u16 address).
*/
void EEPROM_PageWrite(u16 address, char*data);

/*
	Function Name        : EEPROM_PageRead
	Function Returns     : void
	Function Arguments   : u16 address,  u8*  data
	Function Description : Read block of bytes of the given size (size)
*/
char*  EEPROM_PageRead(u16 address,  u8*  data);


#endif /* EEPROM_INTERFACE_H_ */
