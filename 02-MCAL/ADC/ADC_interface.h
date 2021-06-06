/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : ADC_Interface.h for ADC                                             *
*     Date        : 16 Mar 2020                                                         *
*     Version     : 1.0                                                                 *
****************************************************************************************/

	/******************************************************************************
	*    Description : Guard to protect this file to include more than one time   *
	******************************************************************************/

#ifndef  _ADC_INTERFACE_H
#define  _ADC_INTERFACE_H

/******************************************************************************
*    Description : Macros voltage reference selection [Bit(6,7)]              *
*                 															  *
*				  REFS1 REFS0 Voltage Reference Selection					  *
*				  0      0    ->AREF, Internal Vref turned off				  *
*				  0      1    ->AVCC with external capacitor at AREF pin	  *
*				  1 	 0    ->Reserved									  *
*				  1 	 1    ->Internal 2.56V Voltage Reference with 		  *
*							  ->external capacitor at AREF pin  	   		  *
******************************************************************************/
#define VOLTAGE_REFERENCE_AREF       0

#define VOLTAGE_REFERENCE_AVCC       1

#define VOLTAGE_REFERENCE_INTERNAL   2  

/******************************************************************************
*    Description : Macros to select left adjustment or right adjustment       *
*                  if Bit-5[ADLAR] write one result= left adjustment          *
*					otherwise result= right adjustment 						  *
******************************************************************************/

#define     LEFT_ADJUSTMENT      0
#define     RIGHT_ADJUSTMENT     1


#define     DIVIDE_BY_2           1
#define     DIVIDE_BY_4           2
#define     DIVIDE_BY_8           3
#define     DIVIDE_BY_16          4
#define     DIVIDE_BY_32          5
#define     DIVIDE_BY_64          6
#define     DIVIDE_BY_128         7




/*************************************************************************************/
/* Description    :  This function used to initialize ADC 	                         */
/* Inputs         : void 			            			                         */
/* return         : void						                                     */
/*************************************************************************************/
void ADC_voidInit(void);

  /*************************************************************************************
  *  Description : This function enable ADC must be used after ADC initialize          *
  *  Input       : Void                                                                *
  *  Return      : Void                                                                *
  **************************************************************************************/
void ADC_voidEnable(void);


  /************************************************************************************
  *  Description : This function used to disable ADC                                  *
  *  Input       : Void                                                               *
  *  Return      : Void                                                               *
  ************************************************************************************/
void ADC_voidDisable(void);


  /*************************************************************************************
  *  Description : This function used to Start Conversion                              *
  *  Input       : Void                                                                *
  *  Return      : Void                                                                *
  **************************************************************************************
  *             percondition : must be used after ADC initialize                       *
  *************************************************************************************/
void ADC_voidStartConversion(void);

  /*************************************************************************************
  *  Description : ADC Auto Trigger Enable When this bit is written to one,            *
  *				   Auto Triggering of the ADC is enabled. The ADC will start           *
  *				   a conversion on a positive edge of the selected trigger signal	   *                             *
  *  Input       : void                                                                *
  *  Return      : Void                                                                *
  **************************************************************************************
  *             percondition : must be used after ADC initialize                       *
  *************************************************************************************/
void ADC_AutoTrigger_Enable(void);

  /*************************************************************************************
  *  Description : ADC Auto Trigger Disable                                        	   *
  *  Input       : void                                                                *
  *  Return      : Void                                                                *
  **************************************************************************************
  *             percondition : must be used after ADC initialize                       *
  *************************************************************************************/
void ADC_AutoTrigger_Disable(void);

/************************************************************************************/
/* Description    : THhis function is used to enable ADC - Interrupt.               */
/*					When this bit(3) is written to one and the I-bit in SREG is set,*/
/*					the ADC Conversion Complete Interrupt is activated.   	        */
/*								 												 	*/ 
/*	Inputs : void					  			 				 					*/
/*	Return : void		 					     				 					*/
/************************************************************************************/
void ADC_Interrupt_Enable(void);


/*****************************************************************/
/* Description    : This function used to Enable GIE			 */ 
/*																 */
/*					Inputs : void					  			 */
/*					Return : void		 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt  */
/*     				 initialized 							     */
/*****************************************************************/

void GLOBAL_INT_voidEnable(void);

/*****************************************************************/
/* Description    : This function used to Disable GIE			 */ 
/*																 */
/*					Inputs : void					  			 */
/*					Return : void		 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt  */
/*     				 initialized 							     */
/*****************************************************************/

void GLOBAL_INT_voidDisable(void);

  /**************************************************************************************
  *  Description : This function read the value of ADC                                  *
  *  Input       : takes the channel number                                             *
  *  Return      : u16 Digital Converting [return 0 to 1023 mellivolt]                  *
  **************************************************************************************/

u16 ADC_u16Read(u8 Cpy_u8ChannelNo);


#endif /* _DIO_INTERFACE_H */
