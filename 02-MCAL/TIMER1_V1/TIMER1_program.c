
#define F_CPU  8000000UL

#include"LIB/STD_TYPES.h"
#include"LIB/BIT_MATH.h"
#include"DIO_INTERFACE.h"
#include"TIMER1_interface.h"
#include"TIMER1_private.h"
#include"TIMER1_config.h"


 /********Pointer to functions to be assigned to ISR********/
void (*TIMER_VOID_OVF_CALLBACK)(void);
void (*TIMER1_VOID_CTCA_CALLBACK)(void);
void (*TIMER1_VOID_CTCB_CALLBACK)(void);
void (*TIMER1_VOID_CAPTURE_EVENT_CALLBACK)(void);
/************************************************************/

void TIMER1_VoidInit(Timer1Mode_t Mode,Timer1Prescaler_t Prescal,OC1A_Mode_t OC1AMode,OC1B_Mode_t OC1BMode)
{
	switch(Mode)
	{
		case NORMAL_MODE  :
			 TCCR1A |=(CLR<<WGM11)|(CLR<<WGM10);
			 TCCR1B |=(CLR<<WGM13)|(CLR<<WGM12);
		break;		
		
		case MODE_PWM_PAHSE_CORRECT_8  :
			 TCCR1A |=(CLR<<WGM11)|(SET<<WGM10);
			 TCCR1B |=(CLR<<WGM13)|(CLR<<WGM12);
		break;	
		
		case MODE_CTC_4   :
			 TCCR1A |=(CLR<<WGM11)|(CLR<<WGM10);
			 TCCR1B |=(CLR<<WGM13)|(SET<<WGM12);
		break;			

		case MODE_PWM_FAST_8_BIT :
			 TCCR1A |=(CLR<<WGM11)|(SET<<WGM10);
			 TCCR1B |=(CLR<<WGM13)|(SET<<WGM12);
		break;
		
		case MODE_PWM_PAHSE_FREQ_CORRECT_ICR :
			 TCCR1A |=(CLR<<WGM11)|(CLR<<WGM10);
			 TCCR1B |=(SET<<WGM13)|(CLR<<WGM12);
		break;
		
		case MODE_PWM_PAHSE_FREQ_CORRECT_OCRA:
			 TCCR1A |=(CLR<<WGM11)|(SET<<WGM10);
			 TCCR1B |=(SET<<WGM13)|(CLR<<WGM12);
		break;	
		
		case MODE_PWM_PAHSE_CORRECT_ICR      :
			 TCCR1A |=(SET<<WGM11)|(CLR<<WGM10);
			 TCCR1B |=(SET<<WGM13)|(CLR<<WGM12);
		break;
		
		case MODE_PWM_PAHSE_CORRECT_OCR      :
			 TCCR1A |=(SET<<WGM11)|(SET<<WGM10);
			 TCCR1B |=(SET<<WGM13)|(CLR<<WGM12);
		break;	
		case MODE_PWM_FAST_ICR 		       	 :
			 TCCR1A |=(CLR<<WGM11)|(SET<<WGM10);
			 TCCR1B |=(SET<<WGM13)|(SET<<WGM12);
		break;	
		
		case MODE_PWM_FAST_OCRA 		     : 	
			 TCCR1A |=(SET<<WGM11)|(SET<<WGM10);
			 TCCR1B |=(SET<<WGM13)|(SET<<WGM12);
		break;				
	}
	
	switch(OC1AMode)
	{
		case OCRA_NO_ACTION     :TCCR1A |=(CLR<<COM1A1)|(CLR<<COM1A0); break; 
		
		case OCRA_TOGGLE        :TCCR1A |=(CLR<<COM1A1)|(SET<<COM1A0); break; 
		
		case OCRA_NON_INVERTING :TCCR1A |=(SET<<COM1A1)|(CLR<<COM1A0); break; 
		
		case OCRA_INVERTING     :TCCR1A |=(SET<<COM1A1)|(SET<<COM1A0); break; 
	}
	
	switch(OC1BMode)
	{
		case OCRA_NO_ACTION     :TCCR1A |=(CLR<<COM1B1)|(CLR<<COM1B0); break; 
		
		case OCRA_TOGGLE        :TCCR1A |=(CLR<<COM1B1)|(SET<<COM1B0); break; 
		
		case OCRA_NON_INVERTING :TCCR1A |=(SET<<COM1B1)|(CLR<<COM1B0); break; 
		
		case OCRA_INVERTING     :TCCR1A |=(SET<<COM1B1)|(SET<<COM1B0); break; 
	}	

	TCCR1B|=Prescal;

}
void TIMER1_ICUSelectEdge(ICU_Edge_t Edge)
{
	switch(Edge)
	{
		case RISING  : SET_BIT(TCCR1B,ICES1); break ;
		case FALLING : CLR_BIT(TCCR1B,ICES1); break ;
	}
}

void TIMER1_VoidSetTimerRegister(u16 Copy_u16Value)
{
		TCNT1 = Copy_u16Value ;
}


u16 TIMER1_U16GetTimerRegister(void)
{
	return TCNT1 ;
}


void TIMER1_voidSet_OCRA_Value(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value ;
}

void TIMER1_voidSet_OCRB_Value(u16 Copy_u16Value)
{
	OCR1B = Copy_u16Value;
}

u16 ICU_u16GetRegValue(void)
{
	 return ICR1;
}
void TIMER1_VoidEnable_ICU_Interrupt(void)
{
	SET_BIT(TIMSK , TICIE1);
}

void TIMER1_VoidDisable_ICU_Interrupt(void)
{
	CLR_BIT(TIMSK , TICIE1);
}

void TIMER1_voidEnable_OV_Interrput(void)
{
	SET_BIT(TIMSK , TOIE1);
}

void TIMER1_voidDisable_OV_Interrput(void)
{
	CLR_BIT(TIMSK , TOIE1);
}

void TIMER1_voidEnable_CTC_Ch_A_Interrput(void)
{
	SET_BIT(TIMSK , OCIE1A);
}

void TIMER1_voidDisable_CTC_Ch_A_Interrput(void)
{
	CLR_BIT(TIMSK , OCIE1A);

}


void TIMER1_voidEnable_CTC_Ch_B_Interrput(void)
{
	SET_BIT(TIMSK , OCIE1B);

}

void TIMER1_voidDisable_CTC_Ch_B_Interrput(void)
{
	CLR_BIT(TIMSK , OCIE1B);
	
}

void TIMER1_VoidStop(void)
{
	CLR_BIT(TCCR1B , CS10);
	CLR_BIT(TCCR1B , CS11);
	CLR_BIT(TCCR1B , CS12);
}


void TIMER1_voidSet_OV_CallBack(void(*Cpy_Ptr)(void))
{
	TIMER_VOID_OVF_CALLBACK = Cpy_Ptr;
}


void TIMER1_voidSet_CTC_A_CallBack(void(*Cpy_Ptr)(void))
{
	TIMER1_VOID_CTCA_CALLBACK = Cpy_Ptr;
}


void TIMER1_voidSet_CTC_B_CallBack(void(*Cpy_Ptr)(void))
{
	TIMER1_VOID_CTCB_CALLBACK = Cpy_Ptr;
}

void TIMER1_voidSet_ICU_CallBack(void(*Cpy_Ptr)(void))
{
	TIMER1_VOID_CAPTURE_EVENT_CALLBACK = Cpy_Ptr;
}



void __vector_6 (void)__attribute__((signal , used));
void __vector_6 (void)
{
	TIMER1_VOID_CAPTURE_EVENT_CALLBACK();
}


void __vector_7 (void)__attribute__((signal , used));
void __vector_7 (void)
{
	TIMER1_VOID_CTCA_CALLBACK();
}


void __vector_8 (void)__attribute__((signal , used));
void __vector_8 (void)
{
	TIMER1_VOID_CTCB_CALLBACK();
}

void __vector_9(void)__attribute__((signal , used));
void __vector_9(void)
{
	TIMER_VOID_OVF_CALLBACK();
}
