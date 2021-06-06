
#include "STD_TYPES.h"
#include "BIT_MATTH.h"
#include "TIMER2_int.h"
#include "TIMER2_priv.h"
#include "TIMER2_config.h"

void (*TIMER2_voidOVCallBack)(void);
void (*TIMER2_voidCTCCallBack)(void);

void TIMER2_voidInitialize(void)
{
#if _TIMER2_u8_MODE_ ==  TIMER2_u8_NORMAL
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#elif _TIMER2_u8_MODE_ ==  TIMER2_u8_CTC
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#elif _TIMER2_u8_MODE_ ==  TIMER2_u8_FAST_PWM
	SET_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#elif _TIMER2_u8_MODE_ ==  TIMER2_u8_PHASE_CORRECT
	SET_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#endif


#if TIMER2_u8_PRE_SCALAER == TIMER2_u8_DIV_BY_1
	SET_BIT(TCCR2,0);
	CLR_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);

#elif TIMER2_u8_PRE_SCALAER == TIMER2_u8_DIV_BY_8
	CLR_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);

#elif TIMER2_u8_PRE_SCALAER == TIMER2_u8_DIV_BY_32
	SET_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);

#elif TIMER2_u8_PRE_SCALAER == TIMER2_u8_DIV_BY_64
	CLR_BIT(TCCR2,0);
	CLR_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);

#elif TIMER2_u8_PRE_SCALAER == TIMER2_u8_DIV_BY_128
	SET_BIT(TCCR2,0);
	CLR_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);

#elif TIMER2_u8_PRE_SCALAER == TIMER2_u8_DIV_BY_256
	CLR_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);

#elif TIMER2_u8_PRE_SCALAER == TIMER2_u8_DIV_BY_1024
	SET_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);

#endif

#if TIMER2_COM_EVENT == TIMER2_u8_NO_ACTION
	CLR_BIT(TCCR2,4);
	CLR_BIT(TCCR2,5);
#elif TIMER2_COM_EVENT == TIMER2_u8_TOGGLE
	SET_BIT(TCCR2,4);
	CLR_BIT(TCCR2,5);
#elif TIMER2_COM_EVENT == TIMER2_u8_SET
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);
#elif TIMER2_COM_EVENT == TIMER2_u8_CLEAR
	SET_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);
#endif

	/*  DISABLE INTERRUPT   */
	CLR_BIT(TIMSK,6);
	CLR_BIT(TIMSK,7);

	/* CLEAR FLAG  */
	SET_BIT(TIFR,6);
	SET_BIT(TIFR,7);

	/* CLEAR REGISTER   */
	TCNT2=0;
	OCR2=0;


}

void TIMER2_voidSetTimerReg(u8 Copy_u8value)
{
	TCNT2=Copy_u8value;
}

void TIMER2_voidDisableOvINT(void)
{
	CLR_BIT(TIMSK,6);
}

void TIMER2_voidEnableOvINT(void)
{
	SET_BIT(TIMSK,6);
}

void TIMER2_voidDisableCTCINT(void)
{
	CLR_BIT(TIMSK,7);
}

void TIMER2_voidEnableCTCINT(void)
{
	SET_BIT(TIMSK,7);
}

void TIMER2_voidSetOvCallBack(void(*Copy_ptr)(void))
{
	TIMER2_voidOVCallBack=Copy_ptr;
}

void TIMER2_voidSetCTCCallBack(void(*Copy_ptr)(void))
{
	TIMER2_voidCTCCallBack=Copy_ptr;
}

void TIMER2_voidSetComparValue(u8 Copy_u8Value)
{
	OCR2=Copy_u8Value;
}

void __vector_5(void) __attribute__((signal,used));
void __vector_5(void)
{
	TIMER2_voidOVCallBack();
}

void __vector_4(void) __attribute__((signal,used));
void __vector_4(void)
{
	TIMER2_voidCTCCallBack();
}


u8 TIMER2_u8GetREGvale(void)
{
	return TCNT2;
}
