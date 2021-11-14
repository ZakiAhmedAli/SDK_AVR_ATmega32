/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : Contain memory mapped of([TCCR0,TCNT0,OCR0,TIMSK,TIFR] Registers    *
*     Date        : 25 Mar 2020                                                         *
*     Version     : V1.0                         									    *
****************************************************************************************/


/********************************************************************************
*     Description : Guard to Protect this file from include more than one time  *
********************************************************************************/

#ifndef _TIMER1_PRIVATE_H
#define _TIMER1_PRIVATE_H



/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of TCCR1A[0x4F] */
/**			   and TCCR1B Register[0x4E]						*/
/****************************************************************/


#define  TCCR1    (*(volatile u16*)(0x4E))
#define  TCCR1B   (*(volatile u8 *)(0x4E))
#define  TCCR1A   (*(volatile u8 *)(0x4F))


#define  TCNT1    (*(volatile u16*)(0x4C))	//16 bit Register
#define  TCNT1L   (*(volatile u8 *)(0x4C))
#define  TCNT1H   (*(volatile u8 *)(0x4D))

#define  OCR1A    (*(volatile u16*)(0x4A))	//16 bit Register = OCR1AL + OCR1AH
#define  OCR1AL   (*(volatile u8 *)(0x4A))
#define  OCR1AH   (*(volatile u8 *)(0x4B))

#define  OCR1B    (*(volatile u16*)(0x48))	//16 bit Register = OCR1BL + OCR1BH
#define  OCR1BL   (*(volatile u8 *)(0x48))
#define  OCR1BH   (*(volatile u8 *)(0x49))

#define  ICR1     (*(volatile u16*)(0x46))
#define  ICR1L    (*(volatile u8 *)(0x46))
#define  ICR1H    (*(volatile u8 *)(0x47))

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
/*******************************/

#define SET		            1
#define CLR	                0



#endif  /* _TIMER1_PRIVATE_H*/




