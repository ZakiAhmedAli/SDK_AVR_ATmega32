/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : Contain memory mapped of([ADMUX,ADCSRA,ADCH,ADCL] Registers)        *
*     Date        : 20 Sep 2019                                                         *
*     Version     : 1.0                                                                 *
*****************************************************************************************/




/****************************************************************************************
*     Description : Guard to Protect this file from include more than one time          *
*                                                                                       *
****************************************************************************************/

#ifndef    ADC_PRIVATE_H
#define    ADC_PRIVATE_H


/************************************************************************************
*     Description : from data sheet memory mapped register                          *
************************************************************************************/

/*********************************************************************************** 
*    !Comment: Analog to digital converter multiplixer regiseter [ADMUX](0x27)     *
************************************************************************************
*				Bits(6,4)       : Reference Selection Bits						   *
*				Bit5(A)DLAR     : ADC Left Adjust Result                           *
*				Bits(4:0)MUX4:0 : Analog Channel and Gain Selection Bits		   *
***********************************************************************************/
#define  ADMUX           *((volatile u8*)(0x27))

/*********************************************************************************** 
*    !Comment: memory mapped ADC Control and Status Register A – ADCSRA(0x26)      *
************************************************************************************
*				Bit 7 – ADEN   : ADC Enable						                   *
*				• Bit 6 – ADSC : ADC Start Conversion                              *
*				• Bit 5 – ADATE: ADC Auto Trigger Enable                           *
*				• Bit 4 – ADIF : ADC Interrupt Flag                                * 
*				• Bit 3 – ADIE : ADC Interrupt Enable	                           *
*				• Bit 3 – ADIE : ADC Interrupt Enable							   *
*				• Bits 2:0–ADPS2:0: ADC Prescaler Select Bits					   *
***********************************************************************************/
#define  ADCSRA          *((volatile u8*)(0x26))

/********************************************************************************** 
*    !Comment: memory mapped The ADC Data Register –ADCL and ADCH (0x25),(0x24)   *
***********************************************************************************
*				when Bit(ADLAR) in regiseter (ADMUX)						      *  
*				ADLAR = 1: result = left adjust                                   *
*				ADLAR = 0: result = right adjust                                  *
*				ADCL must be read first, then ADCH					        	  *
**********************************************************************************/
#define  ADCH            *((volatile u8*)(0x25))
#define  ADCL            *((volatile u8*)(0x24))

/********************************************************************************** 
*    !Comment: memory mapped The Special FunctionIO Register–SFIOR[0x50]          *
***********************************************************************************
*				• Bit 7:5 – ADTS2:0: ADC Auto Trigger Source					  *  
*																	        	  *
**********************************************************************************/
#define  SFIOR           *((volatile u8*)(0X50))


/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of SREG	   		*/
/**			   Register	is  0X5F						   		*/
/****************************************************************/

#define SREG		* ( ( volatile u8 * ) ( 0X5F ) )

/**********ADC Multiplexer Selection Register ADMUX Bits******/

#define	REFS1	7
#define	REFS0 	6
#define	ADLAR	5

/**** ADC Control and Status Register A - ADCSRA Bits*****/
#define ADEN	7
#define ADSC 	6
#define ADATE 	5
#define ADIF 	4
#define ADIE 	3												
#define ADPS2 	2
#define ADPS1 	1
#define ADPS0	0



 /**************************************** 
 *    !Comment: End of the guard         *
 ****************************************/
#endif
