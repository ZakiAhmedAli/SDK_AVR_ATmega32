
/*******************************************************************************************
 *    Author      : Zaki ahmed hamed                                                       *
 *    Description : public Accessing mechanism prototype and Sense Mode Definition		   *       
 *    Date        : Aug 22, 2019                                                           *
 *    Version     : 1.0                                                                    *
 ******************************************************************************************/


/****************************************************************************************
*     Description : Guard to Protect this file from include more than one time          *
*                                                                                       *
****************************************************************************************/

#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H


/****************************************************************************************
* Description    :  Enable and Disable 	EXTI                                            *
****************************************************************************************/
#define EXTI_ENABLE     	1
#define EXTI_DISABLE    	0

/************************************************************************
*     Description : Sense Control Defenition         					*
*                                                                       *
************************************************************************/

#define  EXTI_LOW_LEVEL    	0
#define  EXTI_IOC          	1
#define  EXTI_RISING_EDGE   2
#define  EXTI_FALLING_EDGE  3

/***********************************************************************************
* Description    :   EXTI flag                                                     *
***********************************************************************************/
#define INT0_FLAG_BIT  	    6
#define INT1_FLAG_BIT       7
#define INT2_FLAG_BIT  	    5

/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void EXTI_VoidInitialize(void);


/****************************************************************/
/* Description    : This function used to Enable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI0_VoidEnable(void);

/****************************************************************/
/* Description    : This function used to Disable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI0_VoidDisable(void);

/****************************************************************/
/* Description    : This function used to Enable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI1_VoidEnable(void);


/****************************************************************/
/* Description    : This function used to Disable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI1_VoidDisable(void);


/****************************************************************/
/* Description    : This function used to Enable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI2_VoidEnable(void);


/****************************************************************/
/* Description    : This function used to Disable EXT0       	*/
/* Inputs         : void		 								*/
/* Return         : void				 						*/
/****************************************************************/
void EXTI2_VoidDisable(void);

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


/****************************************************************/
/* Description : This function used to communicate with the		*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/* Inputs : Pointer to function that points to					*/
/*							 the first line of the function(ISR)*/
/* Return : void	                            				*/
/****************************************************************/
void EXTI0_VoidSetCallback(void (*Cpy_ptr) (void) );

void EXTI1_VoidSetCallback(void (*Cpy_Ptr) (void) );

void EXTI2_VoidSetCallback(void (*Cpy_ptr) (void) );




#endif /* _EXTI_INTERFACE_H */
