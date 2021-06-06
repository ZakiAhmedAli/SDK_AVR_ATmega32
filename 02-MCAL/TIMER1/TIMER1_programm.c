#include"LIB/STD_TYPES.h"
#include"LIB/BIT_MATH.h"
#include"Dio_Interface.h"
#include"timer1_Interface.h"
#include"timer1_private.h"
#include"timer1_configure.h"


 /****************************************************************************************
 * Description    :  This function used to initialize Timer1 	                         *
 * Inputs         :  void 			            			                             *
 * return         :  void						                                         *
 ****************************************************************************************/
void TIMER1_void_Initialize(void)
{
	#if  TIMER1_MODE == MODE_NORMAL0
		 
			CLR_BIT(TCCR1A , WGM10);
			CLR_BIT(TCCR1A , WGM11);
			CLR_BIT(TCCR1B , WGM12);
			CLR_BIT(TCCR1B , WGM13);
	
	#elif  TIMER1_MODE == MODE_PWM_PAHSE_CORRECT_8
		 
			SET_BIT(TCCR1A , WGM10);
			CLR_BIT(TCCR1A , WGM11);
			CLR_BIT(TCCR1B , WGM12);
			CLR_BIT(TCCR1B , WGM13);	
			
	#elif  TIMER1_MODE == MODE_CTC_4
		 
			CLR_BIT(TCCR1A , WGM10);
			CLR_BIT(TCCR1A , WGM11);
			SET_BIT(TCCR1B , WGM12);
			CLR_BIT(TCCR1B , WGM13);

	#elif  TIMER1_MODE == MODE_PWM_FAST_8_BIT
		 
			SET_BIT(TCCR1A , WGM10);
			CLR_BIT(TCCR1A , WGM11);
			SET_BIT(TCCR1B , WGM12);
			CLR_BIT(TCCR1B , WGM13);

	#elif  TIMER1_MODE == MODE_PWM_PAHSE_FREQ_CORRECT_ICR
		 
			CLR_BIT(TCCR1A , WGM10);
			CLR_BIT(TCCR1A , WGM11);
			CLR_BIT(TCCR1B , WGM12);
			SET_BIT(TCCR1B , WGM13);	

	#elif  TIMER1_MODE == MODE_PWM_PAHSE_FREQ_CORRECT_OCRA
		 
			SET_BIT(TCCR1A , WGM10);
			CLR_BIT(TCCR1A , WGM11);
			CLR_BIT(TCCR1B , WGM12);
			SET_BIT(TCCR1B , WGM13);				
			
	#elif  TIMER1_MODE == MODE_PWM_PAHSE_CORRECT_ICR
		 
			CLR_BIT(TCCR1A , WGM10);
			SET_BIT(TCCR1A , WGM11);
			CLR_BIT(TCCR1B , WGM12);
			SET_BIT(TCCR1B , WGM13);

	#elif  TIMER1_MODE == MODE_PWM_PAHSE_CORRECT_OCR
		 
			SET_BIT(TCCR1A , WGM10);
			SET_BIT(TCCR1A , WGM11);
			CLR_BIT(TCCR1B , WGM12);
			SET_BIT(TCCR1B , WGM13);

	#elif  TIMER1_MODE == MODE_PWM_FAST_ICR
		 
			CLR_BIT(TCCR1A , WGM10);
			SET_BIT(TCCR1A , WGM11);
			SET_BIT(TCCR1B , WGM12);
			SET_BIT(TCCR1B , WGM13);

	#elif  TIMER1_MODE == MODE_PWM_FAST_OCRA
		 
			SET_BIT(TCCR1A , WGM10);
			SET_BIT(TCCR1A , WGM11);
			SET_BIT(TCCR1B , WGM12);
			SET_BIT(TCCR1B , WGM13);			
						
	#endif
	
	
	#if	TIMER1_PRESCALER == No_Prescaller
			SET_BIT(TCCR1B , CS10);
			CLR_BIT(TCCR1B , CS11);
			CLR_BIT(TCCR1B , CS12);
			
	#elif	TIMER1_PRESCALER == Prescaller_8
			CLR_BIT(TCCR1B , CS10);
			SET_BIT(TCCR1B , CS11);
			CLR_BIT(TCCR1B , CS12);

	#elif	TIMER1_PRESCALER == Prescaller_64
			SET_BIT(TCCR1B , CS10);
			SET_BIT(TCCR1B , CS11);
			CLR_BIT(TCCR1B , CS12);	

	#elif	TIMER1_PRESCALER == Prescaller_256
			CLR_BIT(TCCR1B , CS10);
			CLR_BIT(TCCR1B , CS11);
			SET_BIT(TCCR1B , CS12);		

	#elif	TIMER1_PRESCALER == Prescaller_1024
			SET_BIT(TCCR1B , CS10);
			CLR_BIT(TCCR1B , CS11);
			SET_BIT(TCCR1B , CS12);					

	#elif	TIMER1_PRESCALER == Prescaller_FalExtClk
			CLR_BIT(TCCR1B , CS10);
			SET_BIT(TCCR1B , CS11);
			SET_BIT(TCCR1B , CS12);					

	#elif	TIMER1_PRESCALER == Prescaller_RaisExtClk
			SET_BIT(TCCR1B , CS10);
			SET_BIT(TCCR1B , CS11);
			SET_BIT(TCCR1B , CS12);		
	#endif

	#if CHANNEL_A == ENABLE_CHANEL_A
	
	#if	TIMER1_COM_EVENT == TIMER1_NO_ACTION
			CLR_BIT(TCCR1A , COM1A0);
			CLR_BIT(TCCR1A , COM1A1);
			
	#elif	TIMER1_COM_EVENT == TIMER1_u8_TOGGLE_OR_RESERVED_IN_PWM
			SET_BIT(TCCR1A , COM1A0);
			CLR_BIT(TCCR1A , COM1A1);	

	#elif	TIMER1_COM_EVENT == TIMER1_u8_SET_OR_NONINVERTED_IN_PWM
			CLR_BIT(TCCR1A , COM1A0);
			SET_BIT(TCCR1A , COM1A1);

	#elif	TIMER1_COM_EVENT == TIMER1_u8_CLEAR_OR_INVERTED_IN_PWM
			SET_BIT(TCCR1A , COM1A0);
			SET_BIT(TCCR1A , COM1A1);
			
	#endif
	#endif
	
	#if CHANNEL_B == ENABLE_CHANEL_B
	#if	TIMER1_COM_EVENT == TIMER1_NO_ACTION
			CLR_BIT(TCCR1A , COM1B0);
			CLR_BIT(TCCR1A , COM1B1);
			
	#elif	TIMER1_COM_EVENT == TIMER1_u8_TOGGLE_OR_RESERVED_IN_PWM
			SET_BIT(TCCR1A , COM1B0);
			CLR_BIT(TCCR1A , COM1B1);	

	#elif	TIMER1_COM_EVENT == TIMER1_u8_SET_OR_NONINVERTED_IN_PWM
			CLR_BIT(TCCR1A , COM1B0);
			SET_BIT(TCCR1A , COM1B1);

	#elif	TIMER1_COM_EVENT == TIMER1_u8_CLEAR_OR_INVERTED_IN_PWM
			SET_BIT(TCCR1A , COM1B0);
			SET_BIT(TCCR1A , COM1B1);
			
	#endif
	#endif 
	
	#if ICU_MODULE == ENABLE_ICU
	#if ICU_MODULE_EDGE == RISING_EDGE
		
			SET_BIT(TCCR1B , ICES1);
	
	#elif ICU_MODULE_EDGE == RISING_EDGE 	
			CLR_BIT(TCCR1B , ICES1);
	
	#endif
	#endif
	
	
	
	//Disable Interrupts
	
	TIMER1_voidDisable_CTC_Ch_A_Interrput();
	TIMER1_voidDisable_CTC_Ch_B_Interrput();
	TIMER1_voidDisable_OV_Interrput();

	// Clear Flags
	
	SET_BIT(TIFR , TOV1);
	SET_BIT(TIFR , OCF1B);
	SET_BIT(TIFR , OCF1A);
	SET_BIT(TIFR , ICF1);
	
	
	//Cleare Registers
	TCNT1L = 0;
	TCNT1H = 0;
	
	TCCR1A = 0;
	TCCR1B = 0;
	
	OCR1BL=0;
	OCR1BH=0;
	
}

void TIMER1_Void_SetTimerRegister(u16 Cpy_U16Value)
{
		TCNT1H = (Cpy_U16Value << 8);
		TCNT1L = (u8)(Cpy_U16Value);
}


u16 TIMER1_U16_GetTimerRegister(void)
{
	return (TCNT1L | (TCNT1H << 8));
}


void TIMER1_voidSet_OCRA_Value(u16 Copy_u16Value)
{
	OCR1AH = (Copy_u16Value << 8);
	OCR1AL = (u8)(Copy_u16Value);
}

void TIMER1_voidSet_OCRB_Value(u16 Copy_u16Value)
{
	OCR1BH = (Copy_u16Value << 8);
	OCR1BL = (u8)(Copy_u16Value);
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

void TIMER1_void_Disable(void)
{
	CLR_BIT(TCCR1B , CS10);
	CLR_BIT(TCCR1B , CS11);
	CLR_BIT(TCCR1B , CS12);
}

void (*TIMER_VOID_OVF_CALLBACK)(void);
void TIMER1_voidSet_OV_CallBack(void(*Cpy_Ptr)(void))
{
	TIMER_VOID_OVF_CALLBACK = Cpy_Ptr;
}

void (*TIMER1_VOID_CTCA_CALLBACK)(void);
void TIMER1_voidSet_CTC_A_CallBack(void(*Cpy_Ptr)(void))
{
	TIMER1_VOID_CTCA_CALLBACK = Cpy_Ptr;
}

void (*TIMER1_VOID_CTCB_CALLBACK)(void);
void TIMER1_voidSet_CTC_B_CallBack(void(*Cpy_Ptr)(void))
{
	TIMER1_VOID_CTCB_CALLBACK = Cpy_Ptr;
}


void (*TIMER1_VOID_CAPTURE_EVENT_CALLBACK)(void);
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
