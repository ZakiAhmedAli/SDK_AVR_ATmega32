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



/*********************************************************************************
*     Description : Macros to Choose Mode [as a timer OR as a counter ]   		 *
*                                                                                *
*********************************************************************************/
#define TIMER1_AS_TIMER_		   0
#define TIMER1_AS_COUNTER	       2




 /****************************************************************************************
 * Description    :  This function used to initialize Timer1 	                         *
 * Inputs         :  void 			            			                             *
 * return         :  void						                                         *
 *****************************************************************************************/
void TIMER1_void_Initialize(void);


 /*******************************************************************************
 * Description    :  This function used to Disable(stop)Timer1/counter1         *
 * Inputs           :  void 			          		                        *
 * return           :  void													    *
 *******************************************************************************/
void TIMER1_void_Disable(void);


 /*******************************************************************************
 * Description    :  This function used to specific to set value TCNT1L & TCNT1H *
 * Inputs         	 :  u16 Cpy_U16Value[value to seting to Register]            *	 
 * return           :  void						                               	 *
 ********************************************************************************/
void TIMER1_Void_SetTimerRegister(u16 Copy_u16Value);



 /******************************************************************************************
 * Description    :  This function used to specific to get values from TCNT1L & TCNT1H	   *
 * Inputs         :  void 										      					   *		 
 * return         :  void						      			                           *
 ******************************************************************************************/
u16 TIMER1_U16_GetTimerRegister(void);


 /*************************************************************************************
 * Description    :  This function used to specific to get values from TCNT1L & TCNT1H*
 * Inputs         :  void 										                	  * 
 * return         :  void						                                      *
 *************************************************************************************/
void TIMER1_voidSet_OCRA_Value(u16 Copy_u16Value);

void TIMER1_voidSet_OCRB_Value(u16 Copy_u16Value);

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
