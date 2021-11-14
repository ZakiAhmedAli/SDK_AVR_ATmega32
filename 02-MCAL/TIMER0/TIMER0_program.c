#include"STD_TYPES.h"
#include"BIT_MATHS.h"
#include "Dio_Interface.h"
#include "timer0_interface.h"
#include "timer0_private.h"
#include "timer0_configure.h"


void (*TIMER0_OV_CALLBACK) (void) = NULLPTR;
void (*TIMER0_CTC_CALLBACK) (void);

void (*TIMER0_DELAY_CALLBACK)(void);


/*****************************************************************************************
 * Description    :  This function used toInitialize Timer0 	                         *
 * Inputs         :  void 			            			                             *
 * return         :  void						                                         *
 *****************************************************************************************/
void TIMER0_void_Init( Timer0Mode_t Mode, Prescal_t Prescal, OC0Mode_t OCO_Mode){

	switch (Mode) {
		case TIMER0_NORMAL:
			 CLR_BIT(TCCR0 , WGM00);
			 CLR_BIT(TCCR0 , WGM01);
		break;

		case TIMER0_PHASE_CRRECT:
			 SET_BIT(TCCR0 , WGM00);
			 CLR_BIT(TCCR0 , WGM01);
		break;

		case TIMER0_CTC:
			 CLR_BIT(TCCR0 , WGM00);
			 SET_BIT(TCCR0 , WGM01);
		break;

		case TIMER0_FAST_PWM:
			 SET_BIT(TCCR0 , WGM00);
			 SET_BIT(TCCR0 , WGM01);
		break;

		default:		break;
	}
	TCCR0 &=0xF8;
	TCCR0 |=Prescal;

	switch (OCO_Mode) {
		case OCO_DISCONNECTED:
			 CLR_BIT(TCCR0,COM00);
			 CLR_BIT(TCCR0,COM01);
		break;
		case OCO_TOGGLE:
			 SET_BIT(TCCR0,COM00);
			 CLR_BIT(TCCR0,COM01);
		break;
		case OCO_NON_INVERTING:
			 CLR_BIT(TCCR0,COM00);
			 SET_BIT(TCCR0,COM01);
		break;
		case OCO_INVERTING:
			 SET_BIT(TCCR0,COM00);
			 SET_BIT(TCCR0,COM01);
		break;
		default: /**/ break;
	}
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

void TIMER0_Void_SETDELAYCALLBACK( void (*Copy_Ptr) (void) )
{

	TIMER0_DELAY_CALLBACK = Copy_Ptr;
}


void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	if( TIMER0_OV_CALLBACK != NULLPTR)
	{
		TIMER0_OV_CALLBACK();
	}

}


void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{

	TIMER0_CTC_CALLBACK();
}

