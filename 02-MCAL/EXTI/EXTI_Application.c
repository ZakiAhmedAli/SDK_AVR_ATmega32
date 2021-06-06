#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "reg.h"
#include "Dio_Interface.h"
#include "EXTI_Interfac.h"
#include "EXTI_Private.h"
#include "EXTI_Configure.h"
#include "avr/interrupt.h"

/****************************************************************/
/* Description    : pointer to function for EXTI0 used in ISR() */
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void (*EXTI0_CALLBACK) (void);
void (*EXTI1_CALLBACK) (void);
void (*EXTI2_CALLBACK) (void);



void EXTI_VoidInitialize(void)
{
	#if EXTI0_State == EXTI_ENABLE
		EXTI0_VoidEnable();
		//Set PD3 (INT0) to input direction
		Dio_vidSetPinDirection(DIO_U8_PORT_D, DIO_U8_PIN_2, DIO_U8_DIR_IN);

		#if EXTI0_Sense_Control == EXTI_LOW_LEVEL

			CLR_BIT(MCUCR , 0);
			CLR_BIT(MCUCR , 1);

		#elif EXTI0_Sense_Control == EXTI_IOC

			SET_BIT(MCUCR , 0);
			CLR_BIT(MCUCR , 1);

		#elif EXTI0_Sense_Control == EXTI_RISING_EDGE

			CLR_BIT(MCUCR , 0);
			SET_BIT(MCUCR , 1);

		#elif  EXTI0_Sense_Control == EXTI_FALLING_EDGE

			SET_BIT(MCUCR , 0);
			SET_BIT(MCUCR , 1);
		#endif
	#endif

	#if	EXTI1_State == EXTI_ENABLE
			// Enable (INT1)
			EXTI1_VoidEnable();
			//Set PD3 (INT1) to input direction
		Dio_vidSetPinDirection(DIO_U8_PORT_D, DIO_U8_PIN_3, DIO_U8_DIR_IN);

		#if EXTI1_Sense_Control == EXTI_LOW_LEVEL

			CLR_BIT(MCUCR , 2);
			CLR_BIT(MCUCR , 3);

		#elif EXTI1_Sense_Control == EXTI_IOC

			SET_BIT(MCUCR , 2);
			CLR_BIT(MCUCR , 3);

		#elif EXTI1_Sense_Control == EXTI_RISING_EDGE

			CLR_BIT(MCUCR , 2);
			SET_BIT(MCUCR , 3);

		#elif  EXTI1_Sense_Control == EXTI_FALLING_EDGE

			SET_BIT(MCUCR , 2);
			SET_BIT(MCUCR , 3);
		#endif

	#endif

	#if EXTI2_State == EXTI_ENABLE
			// Enable (INT1)
			EXTI2_VoidEnable();

	  Dio_vidSetPinDirection(DIO_U8_PORT_B, DIO_U8_PIN_2, DIO_U8_DIR_IN);

		#if EXTI2_Sense_Control == EXTI_RISING_EDGE

		  SET_BIT(MCUCSR , 6);

		#elif EXTI2_Sense_Control == EXTI_FALLING_EDGE
		  CLR_BIT(MCUCSR , 6);

		#endif
	#endif
}


void EXTI0_VoidEnable(void)
{
	SET_BIT(GICR , 6);
}

void EXTI0_VoidDisable(void)
{
	CLR_BIT(GICR , 6);
}


/****************************************************************/
/* Description    : This function used to Enable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI1_VoidEnable(void)
{
	SET_BIT(GICR , 7);
}


/****************************************************************/
/* Description    : This function used to Disable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI1_VoidDisable(void)
{
	CLR_BIT(GICR , 7);

}


/****************************************************************/
/* Description    : This function used to Enable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI2_VoidEnable(void)
{
	SET_BIT(GICR , 5);
}


/****************************************************************/
/* Description    : This function used to Disable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI2_VoidDisable(void)
{
	CLR_BIT(GICR , 5);
}

/****************************************************************************************
* Description    :  This function used to Enable Global Interrupt         	             *
* Inputs         :  void 			            			                             *
* return         :  void						                                         *
*****************************************************************************************/
void GIE_VoidEnable(void){
	SET_BIT(SREG , 7);
}

/****************************************************************************************
* Description    :  This function used to Disable Global Interrupt         	             *
* Inputs         :  void 			            			                             *
* return         :  void						                                         *
*****************************************************************************************/
void GIE_VoidDisable(void){

	CLR_BIT(SREG , 7);
}


void EXTI0_VoidSetCallback(void (*Cpy_ptr) (void) )
{
	 EXTI0_CALLBACK = Cpy_ptr;
}

void EXTI1_VoidSetCallback(void (*Cpy_Ptr) (void) )
{
	 EXTI1_CALLBACK = Cpy_Ptr;
}
void EXTI2_VoidSetCallback(void (*Cpy_ptr) (void) )
{
	 EXTI2_CALLBACK = Cpy_ptr;
}


ISR(INT0_vect)
{
	EXTI0_CALLBACK();
}

ISR(INT1_vect)
{
	EXTI1_CALLBACK();
}
ISR(INT2_vect)
{
	EXTI2_CALLBACK();
}

