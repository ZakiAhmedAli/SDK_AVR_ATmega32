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
#define TIMER0_NORMAL 		        0
#define TIMER0_CTC 			        2
#define TIMER0_FAST_PWM 	        3
#define TIMER0_PHASE_PWM 	        1

/************************************************************************************
*     Description : Compare Match Output Mode [control the Output Compare pin]      *
*                                                                                   *
************************************************************************************/
#define TIMER0_NO_ACTION          0
#define TIMER0_TOGGLE             1
#define TIMER0_SET                2
#define TIMER0_CLEAR              3


/************************************************************************************
*     Description : Macros to choose prescaller[Division factor ] to Control speed  *
*      of count                                                                     *
*                                                                                   *
************************************************************************************/
#define  DIVIDED_BY_1                1
#define  DIVIDED_BY_8                8
#define  DIVIDED_BY_64               64
#define  DIVIDED_BY_256              256
#define  DIVIDED_BY_1024             1024


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






 /****************************************************************************************
 * Description    :  This function used to initialize Timer0 	                         *
 * Inputs         :  void 			            			                             *
 * return         :  void						                                         *
 *****************************************************************************************/
void TIMER0_void_Initialize(void);

void TIMER0_void_Disable(void);

   //CLR Flag
void TIMER0_Void_CLRFlag(void);

/*****************************************************************************************
 * Description    :  This function used to Enable Overflow Timer0 	                     *
 * Inputs         :  void 			            			                             *
 * return         :  void						                                         *
 *****************************************************************************************/
void TIMER0_voidEnableOVInt(void);


 /****************************************************************************************
 * Description    :  This function used to Disable Overflow Timer0 	                     *
 * Inputs         :  void 			            			                             *
 * return         :  void						                                         *
 *****************************************************************************************/
void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

/****************************************************************************************
* Description    :  This function used to Disable Timer0         	                     *
* Inputs         :  void 			            			                             *
* return         :  void						                                         *
*****************************************************************************************/
//void TIMER0_void_Disable(void);



void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);
u8 TIMER0_void_GetTimerReg();
void TIMER0_void_SetCompareVal(u8 Copy_uint8Val);


/****************************************************************************************
* Description    :  This function used to Enable Global Interrupt         	             *
* Inputs         :  void 			            			                             *
* return         :  void						                                         *
*****************************************************************************************/
void GIE_VoidEnable(void);


/****************************************************************************************
* Description    :  This function used to Disable Global Interrupt         	             *
* Inputs         :  void 			            			                             *
* return         :  void						                                         *
*****************************************************************************************/
void GIE_VoidDisable(void);


/********************************************************************
* Description    :  Timer0 callBack functions     	    			* 
*********************************************************************/

void TIMER0_Void_SETOVCALLBACK( void (*Copy_Ptr) (void) );

void TIMER0_Void_SETCTCCALLBACK(void (*Cpoy_Ptr) (void)) ;

void TIMER0_Void_SETDELAYCALLBACK(void (*Cpoy_Ptr) (void)) ;

#endif
