/****************************************************************************************
*     Author      : Zaki Ahmed hamed                                                    *
*     Description : Configuration Timer1                                               	*
*     Date        : 20 Mar 2020                                                         *
*     Version     : 1.0                                                               	*
*****************************************************************************************/


/****************************************************************************************
*     Description : Guard to Protect this file from include more than one time          *
*                                                                                       *
****************************************************************************************/
#ifndef _TIMER1_CONFIGURE_H
#define _TIMER1_CONFIGURE_H


/****************************************************************************************
*     Description : Macros to choose timer1 mode                                        *
*                                                                                       *
****************************************************************************************/
#define TIMER1_MODE  MODE_NORMAL0

/************************************************************************************
*     Description : Macros to choose prescaller [Division factor ] to Control speed *
*   			                                                                    *
*                                                                                   *
************************************************************************************/
#define TIMER1_PRESCALER   Prescaller_64


/************************************************************************************
*     Description : Compare Match Output Mode [control the Output Compare pin]      *
*                                                                                   *
************************************************************************************/

#define TIMER1_CHANNEL_A_EVENT         TIMER1_u8_CLEAR_OR_INVERTED_IN_PWM
#define TIMER1_CHANNEL_B_EVENT         TIMER1_u8_CLEAR_OR_INVERTED_IN_PWM


/************************************************************************************
*     Description : Control ChannelA Enable/Disable     							*
*					ENABLE_CHANEL_A													*
* 		   			DISABLE_CHANEL_A												*
*																					*
************************************************************************************/
#define CHANNEL_A	ENABLE_CHANEL_A

/************************************************************************************
*     Description : Control ChannelB Enable/Disable     							*
*					ENABLE_CHANEL_B													*
* 		   			DISABLE_CHANEL_B												*
*																					*
************************************************************************************/
#define CHANNEL_B	ENABLE_CHANEL_B

/************************************************************************************
*   Description : Control of Input Capture Unit 								 	*
*				  #define ENABLE_ICU                                                *
*				  #define DISABLE_ICU											    *
************************************************************************************/
#define ICU_MODULE		DISABLE_ICU


/*
 *	#define RISING_EDGE
 *	#define FALLING_EDGE
 *
 */
#define ICU_MODULE_EDGE


#endif /* _TIMER1_CONFIGURE_H*/

