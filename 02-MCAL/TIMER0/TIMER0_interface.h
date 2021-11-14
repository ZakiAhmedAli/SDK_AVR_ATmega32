/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : Interface Timer0                                                    *
*     Date        : 20 Sep 2019                                                         *
*     Version     : 1.0                                                                 *
*****************************************************************************************/




/****************************************************************************************
*     Description : Guard to Protect this file from include more than one time          *
*                                                                                       *
****************************************************************************************/

#ifndef  _TIMER0_INTERFACE_H_
#define  _TIMER0_INTERFACE_H_



/*********************************************************************************
*     Description : Macros to Choose Mode [as a timer OR as a counter ]          *
*                                                                                *
*********************************************************************************/
#define TIMER0_AS_TIMER_		   0
#define TIMER0_AS_COUNTER	       2


/**********************************************************************************
*     Description : macros for Waveform Generation Mode                           *
*     [control the counting sequence of the counter]                              *
*                                                                                 *
***********************************************************************************/
typedef enum
{
	TIMER0_NORMAL =0,
	TIMER0_PHASE_CRRECT,
	TIMER0_CTC,
	TIMER0_FAST_PWM ,

}Timer0Mode_t;


/************************************************************************************
*     Description : Compare Match Output Mode [control the Output Compare pin]      *
*                                                                                   *
************************************************************************************/
typedef enum
{
	OCO_DISCONNECTED=0,
	OCO_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING

}OC0Mode_t;


/************************************************************************************
*     Description : Macros to choose prescaller[Division factor ] to Control speed  *
*      of count                                                                     *
*                                                                                   *
************************************************************************************/

typedef enum
{
	TIMR_CTR_STOP =0 ,
	PRESCAL_BY_1     , 
	PRESCAL_BY_8     ,
	PRESCAL_BY_64    ,
	PRESCAL_BY_256   ,
	PRESCAL_BY_1024  ,
	EX_CLK_FALING_EDGE,
	EX_CLK_RASING_EDGE,
					 
}Prescal_t;



 /*****************************************************************
 * Description    :  This function used to initialize Timer0      *
 * Inputs         :  void 			            			      *
 * return         :  void						                  *
 ******************************************************************/
void TIMER0_void_Init( Timer0Mode_t Mode, Prescal_t Prescal, OC0Mode_t OCO_Mode);

void TIMER0_VoidEnable(Prescal_t Copy_Prescal);

void TIMER0_void_Disable(void);

void TIMER0_Delay_MS(u8 DELAY_MS);

   //CLR Flag
void TIMER0_Void_CLRFlag(void);

/************************************************************************
 * Description    :  This function used to Enable Overflow Timer0 	    *
 * Inputs         :  void 			            			            *
 * return         :  void						                        *
 ************************************************************************/
void TIMER0_voidEnableOVInt(void);


 /***********************************************************************
 * Description    :  This function used to Disable Overflow Timer0 	    *
 * Inputs         :  void 			            			            *
 * return         :  void						                        *
 ************************************************************************/
void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

/***********************************************************************
* Description    :  This function used to Disable Timer0         	    *
* Inputs         :  void 			            			            *
* return         :  void						                        *
************************************************************************/
//void TIMER0_void_Disable(void);



void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);
u8 TIMER0_void_GetTimerReg();
void TIMER0_void_SetCompareVal(u8 Copy_uint8Val);


/***********************************************************************
* Description    :  This function used to Enable Global Interrupt       *
* Inputs         :  void 			            			            *
* return         :  void						                        *
************************************************************************/
void GIE_VoidEnable(void);


/***********************************************************************
* Description    :  This function used to Disable Global Interrupt      *
* Inputs         :  void 			            			            *
* return         :  void						                        *
************************************************************************/
void GIE_VoidDisable(void);


/********************************************************************
* Description    :  Timer0 callBack functions     	    			* 
*********************************************************************/

void TIMER0_Void_SETOVCALLBACK( void (*Copy_Ptr) (void) );

void TIMER0_Void_SETCTCCALLBACK(void (*Cpoy_Ptr) (void)) ;

void TIMER0_Void_SETDELAYCALLBACK(void (*Cpoy_Ptr) (void)) ;

#endif
