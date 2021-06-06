#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include"LED.h"

void LED_voidLedInit(void)
{

	Dio_VoidSetPinDirection(LED_PORT , DIO_U8_PIN_0 , DIO_U8_OUTPUT);

	
}


void LED_voidLedON(u8 Cpy_u8PinNo)
{

			Dio_VoidSetPinValue(LED_PORT ,Cpy_u8PinNo , DIO_U8_HIGH);
}

void LED_voidLedOFF(u8 Cpy_u8PinNo)
{
	
			Dio_VoidSetPinValue(LED_PORT ,Cpy_u8PinNo , DIO_U8_LOW);

}
