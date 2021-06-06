/*********************************************************************************************
*     Author      : Zaki Ahmed hamed                                                         *
*     Description : Contain memory mapped of([TCCR0,TCNT0,OCR0,TIMSK,TIFR] Registers)        *
*     Date        : 25 Mar 2020                                                              *
*     Version     : 1.0                         											 *
*********************************************************************************************/


/****************************************************************************************
*     Description : Guard to Protect this file from include more than one time          *
*                                                                                       *
****************************************************************************************/

#ifndef _TIMER1_PRIVATE_H
#define _TIMER1_PRIVATE_H



/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of TCCR1A[0x4F] */
/**			   and TCCR1B Register[0x4E]						*/
/****************************************************************/

#define TCCR1A    (*(volatile u8 *)(0x4F))
#define TCCR1B    (*(volatile u8 *)(0x4E))


#define  TCNT1H   (*(volatile u8 *)(0x4D))
#define  TCNT1L   (*(volatile u8 *)(0x4C))

#define  OCR1AH   (*(volatile u8 *)(0x4B))
#define  OCR1AL   (*(volatile u8 *)(0x4A))

#define  OCR1BH   (*(volatile u8 *)(0x49))
#define  OCR1BL   (*(volatile u8 *)(0x48))

#define  ICR1H    (*(volatile u8 *)(0x47))
#define  ICR1L    (*(volatile u8 *)(0x46))

#define  TIFR     (*(volatile u8 *)(0x58))
#define  TIMSK    (*(volatile u8 *)(0x59))


/***************************************************************************
** !comment : From Data Sheet :  Memory mapped of SREG	   		           *
**			   Register	is  0X5F [Global interrupt enable]	               *
***************************************************************************/

#define SREG		* ( ( volatile u8 * ) ( 0X5F ) )



/**********************************************************************************
*     Description : macros for Waveform Generation Mode                           *
*     [control the counting sequence of the counter]                              *
*                                                                                 *
**********************************************************************************/

#define MODE_NORMAL0 			       		  0

#define MODE_PWM_PAHSE_CORRECT_8       		  1

#define MODE_CTC_4     			       		  4

#define MODE_PWM_FAST_8_BIT 	       		  5

#define MODE_PWM_PAHSE_FREQ_CORRECT_ICR       8

#define MODE_PWM_PAHSE_FREQ_CORRECT_OCRA      9

#define MODE_PWM_PAHSE_CORRECT_ICR     		  10

#define MODE_PWM_PAHSE_CORRECT_OCR     		  11

#define MODE_PWM_FAST_ICR 		       		  14

#define MODE_PWM_FAST_OCRA 		       		  15


//	TCCRA PINS
	
#define 	COM1A1			7 
#define 	COM1A0 			6
#define 	COM1B1			5 
#define 	COM1B0			4 
#define 	FOC1A			3 
#define 	FOC1B			2 
#define 	WGM11			1 
#define 	WGM10			0

/*==========================================*/


//TCCR1B PINS
#define		CNC1			7
#define		ICES1			6
#define		WGM13			4
#define		WGM12			3
#define		CS12 			2
#define		CS11 			1	
#define		CS10			0


/*==========================================*/

//TIMSK Register PINS
#define		TICIE1 			5
#define		OCIE1A 			4
#define		OCIE1B			3 
#define		TOIE1			2


/*============================*/
//TIFR Register PINS
#define		ICF1			5
#define		OCF1A			4 
#define		OCF1B			3 
#define		TOV1			2
/************************************************************************************
*     Description : Compare Match Output Mode [control the Output Compare pin]      *
*                                                                                   *
************************************************************************************/
#define TIMER1_u8_NO_ACTION          			0
#define TIMER1_u8_TOGGLE_OR_RESERVED_IN_PWM     1
#define TIMER1_u8_SET_OR_NONINVERTED_IN_PWM     2
#define TIMER1_u8_CLEAR_OR_INVERTED_IN_PWM      3




#define ENABLE_CHANEL_A		1
#define DISABLE_CHANEL_A	0


#define ENABLE_CHANEL_B		1
#define DISABLE_CHANEL_B	0

#define ENABLE_ICU    		1
#define DISABLE_ICU   		4

#define RISING_EDGE   		5
#define FALLING_EDGE  		8
 /*======================================================
 *Prescaler Macros
 *======================================================*/
 #define No_Prescaller             1
 #define Prescaller_8              2
 #define Prescaller_64             3
 #define Prescaller_256            4
 #define Prescaller_1024           5
 #define Prescaller_FalExtClk      6
 #define Prescaller_RaisExtClk     7


#endif  /* _TIMER1_PRIVATE_H*/




