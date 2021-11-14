/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : Interface Timer1                                                    *
*     Date        : 20 Mar 2020                                                         *
*     Version     : 1.0                                                                 *
*****************************************************************************************/




/****************************************************************************************
*     Description : Guard to Protect this file from include more than one time          *
*                                                                                       *
****************************************************************************************/

#ifndef  _TIMER1_INTERFACE_H
#define  _TIMER1_INTERFACE_H


typedef enum
{
	NORMAL_MODE   					,
	MODE_PWM_PAHSE_CORRECT_8       	,
	MODE_CTC_4     			       	,
	MODE_PWM_FAST_8_BIT 	       	,
	MODE_PWM_PAHSE_FREQ_CORRECT_ICR ,
	MODE_PWM_PAHSE_FREQ_CORRECT_OCRA,
	MODE_PWM_PAHSE_CORRECT_ICR     	,
	MODE_PWM_PAHSE_CORRECT_OCR     	,
	MODE_PWM_FAST_ICR 		       	,
    MODE_PWM_FAST_OCRA

}Timer1Mode_t;

typedef enum{
	TIMER1_STOP=0		,
	TIMER1_SCALER_1     ,
	TIMER1_SCALER_8     ,
	TIMER1_SCALER_64    ,
	TIMER1_SCALER_256   ,
	TIMER1_SCALER_1024  ,
	EXTERNAL0_FALLING   ,
	EXTERNAL0_RISING

}Timer1Prescaler_t;

typedef enum
{
	RISING  ,
	FALLING

}ICU_Edge_t;

/************************************************************************************
*     Description : Compare Match Output Mode [control the Output Compare pin]      *
************************************************************************************/
typedef enum
{
	OCRA_NO_ACTION=0  ,
	OCRA_TOGGLE       ,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_t;

typedef enum
{
	OCRB_NO_ACTION = 0 ,
	OCRB_TOGGLE        ,
	OCRB_NON_INVERTING ,
	OCRB_INVERTING

}OC1B_Mode_t;


 /****************************************************************************************							
 * Description    :  This function used to initialize Timer1 at run time	                         
 * Inputs         :  Timer1Mode_t Mode,Timer1Prescaler_t Prescal,OC1A_Mode_t OC1AMode,OC1B_Mode_t OC1BMode
 * return         :  void						                                         
 *****************************************************************************************/
void TIMER1_VoidInit(Timer1Mode_t Mode , Timer1Prescaler_t Prescal ,OC1A_Mode_t OC1AMode ,OC1B_Mode_t  OC1BMode);

void TIMER1_VoidStart(void);
 /*******************************************************************************
 * Description    :  This function used to Disable(stop)Timer1/counter1         *
 * Inputs         :  void 			          		                            *
 * return         :  void													    *
 *******************************************************************************/
void TIMER1_VoidStop(void);

void TIMER1_ICUSelectEdge(ICU_Edge_t Edge);
 /*******************************************************************************
 * Description    :  This function used to specific to set value TCNT1L & TCNT1H *
 * Inputs         :  u16 Cpy_U16Value[value to seting to Register]               *	 
 * return         :  void						                               	 *
 ********************************************************************************/
void TIMER1_VoidSetTimerRegister(u16 Copy_u16Value);



 /******************************************************************************************
 * Description    :  This function used to specific to get values from TCNT1L & TCNT1H	   *
 * Inputs         :  void 										      					   *		 
 * return         :  void						      			                           *
 ******************************************************************************************/
u16 TIMER1_U16GetTimerRegister(void);


 /*************************************************************************************
 * Description    :  This function used to specific to get values from TCNT1L & TCNT1H*
 * Inputs         :  void 										                	  * 
 * return         :  void						                                      *
 *************************************************************************************/
void TIMER1_voidSetOCRAValue(u16 Copy_u16Value);

void TIMER1_voidSetOCRBValue(u16 Copy_u16Value);

u16 ICU_u16GetRegValue(void);
void TIMER1_VoidEnable_ICU_Interrupt(void);
void TIMER1_VoidDisable_ICU_Interrupt(void);

void TIMER1_voidEnable_OV_Interrput(void);
void TIMER1_voidDisable_OV_Interrput(void);


void TIMER1_voidEnable_CTC_Ch_A_Interrput(void);
void TIMER1_voidDisable_CTC_Ch_A_Interrput(void);


void TIMER1_voidEnable_CTC_Ch_B_Interrput(void);
void TIMER1_voidDisable_CTC_Ch_B_Interrput(void);

void TIMER1_voidSet_OV_CallBack(void(*Cpy_Ptr)(void));

void TIMER1_voidSet_CTC_A_CallBack(void(*Cpy_Ptr)(void));

void TIMER1_voidSet_CTC_B_CallBack(void(*Cpy_Ptr)(void));


void TIMER1_voidSet_ICU_CallBack(void(*Cpy_Ptr)(void));


#endif
