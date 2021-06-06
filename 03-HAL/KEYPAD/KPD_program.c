/*
 * File        : KPD_Program.c
 * Description : This file includes Keypad Driver implementations for
 * Author      : Zaki Ahmed Hamed
 * Date        : 22/August/2020
 * Git account : https://github.com/ZakiAhmedAli
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "KPD_interface.h"


const u8 KPD_u8value[ROW_SIZE][COL_SIZE]=
{
		{0x01 , 0x02 , 0x03 , 0x0A},
		{0x04 , 0x05 , 0x06 , '-' },
		{0x07 , 0x08 , 0x09 , '+' },
		{ '#' , 0x00 ,  '*' , '/' },
};

void KPD_voidInit(void)
{
		//set column as output
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_0 , DIO_U8_OUTPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_1 , DIO_U8_OUTPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_2 , DIO_U8_OUTPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_3 , DIO_U8_OUTPUT);

	//set row as input
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_4 , DIO_U8_INPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_5 , DIO_U8_INPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_6 , DIO_U8_INPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_7 , DIO_U8_INPUT);

	//active pull up rows pins
	Dio_VoidSetPinValue(KEYPAD_PORT , DIO_U8_PIN_0 , DIO_U8_HIGH);
	Dio_VoidSetPinValue(KEYPAD_PORT , DIO_U8_PIN_1 , DIO_U8_HIGH);
	Dio_VoidSetPinValue(KEYPAD_PORT , DIO_U8_PIN_2 , DIO_U8_HIGH);
	Dio_VoidSetPinValue(KEYPAD_PORT , DIO_U8_PIN_3 , DIO_U8_HIGH);



}

u8 KPD_u8GetPressed(void)
{
	u8 Loc_u8Col;
	u8 Loc_u8Row;

	  /* Initialize the switch status to NOT Pressed */
	u8 Loc_u8Key=NOT_PRESSED;
	/* Looping on columns of the Key Pad*/
	for(Loc_u8Col=COL_INIT ; Loc_u8Col< COL_FIN ; Loc_u8Col++)
	{
			/*Activate the Column */
		Dio_VoidSetPinValue(KEYPAD_PORT , Loc_u8Col , DIO_U8_LOW);
		//Loop on the rows of the Key Pad
		for(Loc_u8Row=ROW_INIT ; Loc_u8Row < ROW_FIN ; Loc_u8Row++)
		{
			/*heck the status of the switch*/
			if(!Dio_u8GetPinValue(KEYPAD_PORT ,Loc_u8Row))
			{
				Loc_u8Key=KPD_u8value[Loc_u8Row-ROW_INIT][Loc_u8Col];
				/* Wait until the switch is released (Single Press)*/
				while(!(GET_BIT(KEYPAD_PORT,Loc_u8Row)));

		        /* Delay to avoid bouncing                                                                                   */
		        _delay_ms(20);
			}

		}

		/* Deactivate the Column  */
		Dio_VoidSetPinValue(KEYPAD_PORT , Loc_u8Col , DIO_U8_HIGH);
	}

	return Loc_u8Key;
}
