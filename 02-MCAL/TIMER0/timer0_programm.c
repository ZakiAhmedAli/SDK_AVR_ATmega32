#include"STD_TYPES.h"
#include"BIT_MATHS.h"
#include "Dio_Interface.h"
#include "timer0_interface.h"
#include "timer0_private.h"
#include "timer0_configure.h"


void (*TIMER0_OV_CALLBACK)  (void);
void (*TIMER0_CTC_CALLBACK) (void);

void (*TIMER0_DELAY_CALLBACK)(void);


/*****************************************************************************************
 * Description    :  This function used toInitialize Timer0 	                         *
 * Inputs         :  void 			            			                             *
 * return         :  void						                                         *
 *****************************************************************************************/
void TIMER0_void_Initialize(void)
{
	#if(TIMER0_MODE == TIMER0_NORMAL)
		CLR_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);

	#elif(TIMER0_MODE == TIMER0_CTC)
		CLR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);

	#elif(TIMER0_MODE == TIMER0_FAST_PWM )
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);

	#elif(TIMER0_MODE == TIMER0_PHASE_PWM )
		SET_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);

	#endif

	#if(TIMER0_PRESCALER == TIMER0_DIV_BY_1)

		SET_BIT(TCCR0 , 0);
		CLR_BIT(TCCR0 , 1);
		CLR_BIT(TCCR0 , 2);

	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_8)

		CLR_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLR_BIT(TCCR0 , 2);

	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_64 )

		SET_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLR_BIT(TCCR0 , 2);

	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_256 )


		CLR_BIT(TCCR0 , 0);
		CLR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_1024 )

		SET_BIT(TCCR0 , 0);
		CLR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == COUNTER_FALLING )

		CLR_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == COUNTER_RISING )

		SET_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);

	#endif

	#if(TIMER0_COM_EVENT == TIMER0_NO_ACTION)
		CLR_BIT(TCCR0 , 4);
		CLR_BIT(TCCR0 , 5);


	#elif(TIMER0_COM_EVENT == TIMER0_TOGGLE)

		SET_BIT(TCCR0 , 4)
		CLR_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_CLEAR )
		CLR_BIT(TCCR0 , 4);
		SET_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_SET )
		SET_BIT(TCCR0 , 4);
		SET_BIT(TCCR0 , 5);


	#endif

	/*Disable Interrupts*/
		CLR_BIT(TIMSK , 0);
		CLR_BIT(TIMSK , 1);

		/*CLEAR FLAGS*/
	TIMER0_Void_CLRFlag();
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;


}

/*CLEAR FLAGS*/
void TIMER0_Void_CLRFlag(void){
	SET_BIT(TIFR , 0);
	SET_BIT(TIFR , 1);
}


/****************************************************************************************
* Description    :  This function used to Disable Timer0         	                     *
* Inputs         :  void 			            			                             *
* return         :  void						                                         *
*****************************************************************************************/

void TIMER0_void_Disable(void){

	CLR_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
}


/*****************************************************************************************
* Description    :  This function used to Receive value if Normal mode is use         	 *
* Inputs         :  value 			            			                             *
* return         :  void						                                         *
*****************************************************************************************/
void TIMER0_void_SetTimerReg(u8 Copy_uint8Val){
	
	 TCNT0 = Copy_uint8Val;
}


u8 TIMER0_void_GetTimerReg()
{

	 return TCNT0;
}

/****************************************************************************************
* Description    :  This function used to Receive value if CTC mode is use            *
* Inputs         :  value  			            			                             *
* return         :  void						                                         *
*****************************************************************************************/
void TIMER0_void_SetCompareVal(u8 Copy_uint8Val){
	   OCR0 = Copy_uint8Val;
}

void TIMER0_voidEnableOVInt(void){
	SET_BIT(TIMSK , 0);
}

void TIMER0_void_DisableOVInt(void){
	CLR_BIT(TIMSK , 0);

}

void TIMER0_void_EnableCTCInt(void){
	SET_BIT(TIMSK , 1);
}

void TIMER0_void_DisableCTCInt(void){
	CLR_BIT(TIMSK , 1);

}

void GIE_VoidEnable(void){
	SET_BIT(SREG , 7);
}


void GIE_VoidDisable(void){

	CLR_BIT(SREG , 7);
}


void TIMER0_Void_SETOVCALLBACK( void (*Copy_Ptr) (void) ){

	TIMER0_OV_CALLBACK = Copy_Ptr;
}

void TIMER0_Void_SETCTCCALLBACK(void (*Cpoy_Ptr) (void)) {

	TIMER0_CTC_CALLBACK = Cpoy_Ptr;
}



////
u16 counter;
void TIMER0_Void_SETDELAYCALLBACK( void (*Copy_Ptr) (void) ){
 counter++;
 if(counter == 3907){
	 counter = 0;
	  TIMER0_void_SetTimerReg(192);
	  DIO_vidSetPinValue(DIO_U8_PORTC , DIO_U8_PIN7 , DIO_U8_HIGH);
 
 }
 

	TIMER0_DELAY_CALLBACK = Copy_Ptr;
}


void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{

	TIMER0_OV_CALLBACK();
	TIMER0_DELAY_CALLBACK();
}

void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{

	TIMER0_CTC_CALLBACK();
}










