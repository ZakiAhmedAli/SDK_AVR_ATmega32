/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : ADC_Application.c file                                              *
*     Date        : 16 mar 2020                                                         *
*     Version     : 1.0                                                                 *
****************************************************************************************/

/******************************************************************************
*    !Comment : include Standard Library Directive   						  *
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Privatee.h"


/****************************************************************************************
*     Description :          Component directive		                                *
****************************************************************************************/
#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_configure.h"


void ADC_voidInit(void)
{
	

	#if    ADC_VOLTAGE_REFFERENCE == VOLTAGE_REFERENCE_AREF
			
			CLR_BIT(ADMUX , REFS0);
			CLR_BIT(ADMUX , REFS1);
			
	#elif  ADC_VOLTAGE_REFFERENCE == VOLTAGE_REFERENCE_AVCC
			SET_BIT(ADMUX , REFS0);
			CLR_BIT(ADMUX , REFS1);

	#elif  ADC_VOLTAGE_REFFERENCE == VOLTAGE_REFERENCE_INTERNAL
	
			SET_BIT(ADMUX , REFS0);
			SET_BIT(ADMUX , REFS1);
	#endif

	#if ADC_ADJUST == RIGHT_ADJUSTMENT
		CLR_BIT(ADMUX , ADLAR);

	#elif ADC_ADJUST == LEFT_ADJUSTMENT
		SET_BIT(ADMUX , ADLAR);

	#endif	
	
	
	#if ADC_PRESCALLER == DIVIDE_BY_2
	
				SET_BIT(ADCSRA , ADPS0);
				CLR_BIT(ADCSRA , ADPS1);
				CLR_BIT(ADCSRA , ADPS2);

	#elif ADC_PRESCALLER == DIVIDE_BY_4
	
				CLR_BIT(ADCSRA , ADPS0);
				SET_BIT(ADCSRA , ADPS1);
				CLR_BIT(ADCSRA , ADPS2);			
                                                
	#elif ADC_PRESCALLER == DIVIDE_BY_8         

				SET_BIT(ADCSRA , ADPS0);
				SET_BIT(ADCSRA , ADPS1);
				CLR_BIT(ADCSRA , ADPS2);	

	#elif ADC_PRESCALLER == DIVIDE_BY_16
	
				CLR_BIT(ADCSRA , ADPS0);
				CLE_BIT(ADCSRA , ADPS1);
				SET_BIT(ADCSRA , ADPS2);

	#elif ADC_PRESCALLER == DIVIDE_BY_32
	
				SET_BIT(ADCSRA , ADPS0);
				CLR_BIT(ADCSRA , ADPS1);
				SET_BIT(ADCSRA , ADPS2);					

	#elif ADC_PRESCALLER == DIVIDE_BY_64
	
				CLR_BIT(ADCSRA , ADPS0);
				SET_BIT(ADCSRA , ADPS1);
				SET_BIT(ADCSRA , ADPS2);

	#elif ADC_PRESCALLER == DIVIDE_BY_128
	
				SET_BIT(ADCSRA , ADPS0);
				SET_BIT(ADCSRA , ADPS1);
				SET_BIT(ADCSRA , ADPS2);
	#endif	
	  
	  ADC_AutoTrigger_Disable();
	  ADC_voidEnable();
}


void GLOBAL_INT_voidEnable(void)
{
  SET_BIT(SREG , 7);
}


void GLOBAL_INT_voidDisable(void)
{
	CLR_BIT( SREG , 7);
}


void ADC_voidEnable(void)
{
	SET_BIT(ADCSRA , ADEN);
}

void ADC_voidDisable(void)
{
	CLR_BIT(ADCSRA , ADEN);
}		

void ADC_voidStartConversion(void)
{
	SET_BIT(ADCSRA , ADSC);
}

void ADC_AutoTrigger_Enable(void)
{
	SET_BIT(ADCSRA , ADATE);
}

void ADC_AutoTrigger_Disable(void)
{
	CLR_BIT(ADCSRA , ADATE);
}


void ADC_Interrupt_Enable(void)
{
	SET_BIT(ADCSRA , ADIE);
	GLOBAL_INT_voidEnable();	
}


u16 ADC_u16Read(u8 Cpy_u8ChannelNo) {

	u16 LOC_u16Value =0;
	ADMUX |=(Cpy_u8ChannelNo & 0x0F);	/* Set input channel to read */

	//1- Start ADC conversion
	ADC_voidStartConversion();
	//2- polling : wait until ADC Interrupt flag is High (until conversion is complete).
	while(!GET_BIT(ADCSRA , ADIF));
	//3- read ADCL and ADCH and put it in AdcValue to return it

	#if ADC_ADJUST == LEFT_ADJUSTMENT
		LOC_u16Value = (u16)ADCL | (((u16)ADCH) << 8);
		LOC_u16Value = ((ADCH * (5000UL))/256);

	#elif  ADC_ADJUST == RIGHT_ADJUSTMENT
		LOC_u16Value = ( (u16)(ADCL) | (u16)(ADCH<<8)  );
		LOC_u16Value = ( (LOC_u16Value * (5000UL)) / 1024);
#endif
			  //Datasheet:ADIF is cleared by writing a logical one to the flag.
	SET_BIT(ADCSRA , ADIF);

	return LOC_u16Value;

}
