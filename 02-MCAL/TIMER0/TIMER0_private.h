/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : Contain memory mapped of([TCCR0,TCNT0,OCR0,TIMSK,TIFR] Registers)        *
*     Date        : 29 Sep 2019                                                         *
*     Version     : 1.0                                                                 *
*****************************************************************************************/


/****************************************************************************************
*     Description : Guard to Protect this file from include more than one time          *
*                                                                                       *
****************************************************************************************/

#ifndef _TIMER0_PRIVATE_H
#define _TIMER0_PRIVATE_H



/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of TCCR0    	*/
/**			   Register	is  0x53						    	*/
/****************************************************************/
/**			   TCCR0 : Timer/Counter Control Register [TCCR0]	*/
/** 		   Bit[6,3] – WGM01:0: Waveform Generation Mode ,	*/
/**            Compare Output Mode, non-PWM Mode ,              */
/**			   Compare Output Mode, Fast PWM Mode ,	            */
/**			   Compare Output Mode, Phase Correct PWM Mode ,    */
/**			   Bit 2:0 – CS02:0: Clock Select	                */
/****************************************************************/
#define TCCR0			*( ( volatile u8 *)(0x53))


/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of TCNT0    	*/
/**			   Register	is  0x52						    	*/
/****************************************************************/
/**			   TCNT0: Timer/Counter Register –[TCNT0]			*/
/** 		   The Timer/Counter Register gives direct access,  */
/**			   both for read and write operations, to           */
/**		       the Timer/Counter unit 8-bit counter.			*/
/****************************************************************/
#define TCNT0			*( ( volatile u8 *)(0x52))

/*******************************************************************/
/** !comment : From Data Sheet :  Memory mapped of OCR    		   */
/**			   Register	is  0x0C						    	   */
/*******************************************************************/
/**			   OCR0: Output Compare Register[OCR0]			       */
/** 		   The Output Compare Register contains an 8-bit value */
/**			   that is continuously compared with the counter value*/
/**			   (TCNT0). A match can be used to generate an output  */
/**			   compare interrupt, or to generate a waveform output */
/**			   on the OC0 pin.  								   */
/*******************************************************************/
#define OCR0			*( ( volatile u8 *)(0x5C))

/*******************************************************************/
/** !comment : From Data Sheet :  Memory mapped of TIMSK Register  */
/**            is  0x59						    		           */
/*******************************************************************/
/**			   TIMSK: Timer/Counter Interrupt Mask Register [TIMSK]*/
/** 		   Bit [1] OCIE0 : Timer/Counter0 Output Compare Match */
/**            Interrupt Enable .								   */
/**			   Bit [0] TOIE0 : Timer/Counter0 Overflow Interrupt   */
/**               Enable										   */
/*******************************************************************/
/**			   GIFR : General Interrupt Flag Register			   */
/*******************************************************************/
#define TIMSK			*( ( volatile u8 *)(0x59))

#define TIFR			*( ( volatile u8 *)(0x58))


/***************************************************************************
** !comment : From Data Sheet :  Memory mapped of SREG	   		           *
**			   Register	is  0X5F [Global interrupt enable]	               *
***************************************************************************/

#define SREG		* ( ( volatile u8 * ) ( 0X5F ) )

/************************************************************************************
*     Description :Timer/Counter Control Register – TCCR0  [Bits]                         *
*      of count                                                                     *
*                                                                                   *
************************************************************************************/

#define	 FOC0           7
#define  WGM00          6
#define  COM01          5
#define  COM00          4
#define  WGM01          3
#define  CS02           2
#define  CS01           1
#define  CS00           0



#endif




