/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : Configure Timer0                                                    *
*     Date        : 20 Sep 2019                                                         *
*     Version     : 1.0                                                                 *
*****************************************************************************************/




/***********************************************************************************
*     Description : Guard to Protect this file from include more than one time     *
*                                                                                  *
************************************************************************************/

#ifndef _TIMER0_CONFIGURE_H_
#define _TIMER0_CONFIGURE_H_



/****************************************************************************************
*     Description : Macros to choose timer0 mode                                        *
*                                                                                       *
****************************************************************************************/
#define TIMER0_MODE         TIMER0_FAST_PWM


/************************************************************************************
*     Description : Macros to choose prescaller [Division factor ] to Control speed *
*      of count                                                                     *
*                                                                                   *
************************************************************************************/
#define TIMER0_PRESCALER    TIMER0_DIV_BY_8

/************************************************************************************
*     Description : Compare Match Output Mode [control the Output Compare pin]      *
*                                                                                   *
************************************************************************************/
#define TIMER0_COM_EVENT   TIMER0_CLEAR


#endif

