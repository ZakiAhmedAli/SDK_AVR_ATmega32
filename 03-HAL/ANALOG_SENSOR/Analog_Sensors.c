/******************************************************************************
*    !Comment : include Standard Library Directive   						  *
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Privatee.h"

#include "ADC_interface.h"
#include "Analog_Sensors.h"


u16 POTVolt_u16Read_mV(void)
{
	u16 LOC_u16ADCValue=0;
	u16 LOC_u16Volt=0;

	LOC_u16ADCValue = ADC_u16Read(POT_CHANNEL);

	LOC_u16Volt = (((u32)5000*LOC_u16ADCValue)/1024);

	return LOC_u16Volt;
}


u16 POTPercent_u16Read(void)
{
	u16 LOC_u16ADCValue=0;
	u16 LOC_u16Volt    =0;
	u16 LOC_u16Present =0;

	LOC_u16ADCValue = ADC_u16Read(POT_CHANNEL);

	LOC_u16Volt= ((u32)5000UL * LOC_u16ADCValue)/1024;

	LOC_u16Present = ((u32)LOC_u16Volt*100)/5000;

	return LOC_u16Present;
}
u16 LM35Volt_u16Read_mV(void)
{
	u16 LOC_u16ADCValue=0;
	u16 LOC_u16Volt    =0;
	u16 LOC_u16Temp =0;

	LOC_u16ADCValue = ADC_u16Read(LM35_CHANNEL);

	LOC_u16Volt= ((u32)5000*LOC_u16ADCValue)/1024;

	LOC_u16Temp = LOC_u16Volt;

	return LOC_u16Temp;
}
