/*****************************************************************
*     Author      : Zaki Ahmed hamed                             *
*     Description : this file implementation Dio Functios        *
*     Date        : 20 August 2020                               *
*     Version     : V03                                          *
*****************************************************************/



/**********************************************************************************
 *	Description : Libirary Directive  											  *
 *********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**********************************************************************************
 *	Description : DIO Directive  												  *
 *********************************************************************************/
#include "DIO_Interface.h"
#include "DIO_Privatee.h"


/**********************************************************************************
 *	Description : DIO Implementaion      										  *
 *********************************************************************************/



 /**************************************************************************************/
 /* Description    :  This Function Set The Pin Direction in The Run Time	           */
 /* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo, Cpy_u8PinDirection] 			       */
 /* return         : void						                                       */
 /**************************************************************************************/
void Dio_VoidSetPinDirection(u8 Cpy_u8PortID, u8 Cpy_u8PinNo , u8 Cpy_u8PinDirection)
{
	if((Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
	   &&(Cpy_u8PinNo >= DIO_U8_PIN_0  && Cpy_u8PinNo  <=DIO_U8_PIN_7))
	{
		if(Cpy_u8PinDirection == DIO_U8_OUTPUT)
		{
			switch(Cpy_u8PortID)
			{
				case DIO_U8_PORT_A: SET_BIT(DDRA_REGISTER , Cpy_u8PinNo); break;
				case DIO_U8_PORT_B: SET_BIT(DDRB_REGISTER , Cpy_u8PinNo); break;
				case DIO_U8_PORT_C: SET_BIT(DDRC_REGISTER , Cpy_u8PinNo); break;
				case DIO_U8_PORT_D: SET_BIT(DDRD_REGISTER , Cpy_u8PinNo); break;
				default : /* No thing*/  break;
			}
		}
		else if(Cpy_u8PinDirection == DIO_U8_INPUT)
		{
			 switch(Cpy_u8PortID)
			  {
				 case DIO_U8_PORT_A: CLR_BIT(DDRA_REGISTER , Cpy_u8PinNo); break;
				 case DIO_U8_PORT_B: CLR_BIT(DDRB_REGISTER , Cpy_u8PinNo); break;
      			 case DIO_U8_PORT_C: CLR_BIT(DDRC_REGISTER , Cpy_u8PinNo); break;
		    	 case DIO_U8_PORT_D: CLR_BIT(DDRD_REGISTER , Cpy_u8PinNo); break;
				 default : /* No thing*/  break;
			  }
		}
		else{/* no thing*/}
	}
	else{/* no thing */}

}

/**************************************************************************************/
/* Description    :  This Function Set The Pin value in The Run Time	                         */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo, Cpy_u8PinLevel] 			            			                         */
/* return         : void						                                         */
/**************************************************************************************/

void Dio_VoidSetPinValue(u8 Cpy_u8PortID , u8 Cpy_u8PinNo , u8 Cpy_u8PinLevel)
{

	if((Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
	   &&(Cpy_u8PinNo >= DIO_U8_PIN_0  && Cpy_u8PinNo  <=DIO_U8_PIN_7))
	{
		if(Cpy_u8PinLevel == DIO_U8_HIGH)
		{
			switch(Cpy_u8PortID)
			{
				case DIO_U8_PORT_A : SET_BIT(PORTA_REGISTER ,Cpy_u8PinNo ); break;
				case DIO_U8_PORT_B : SET_BIT(PORTB_REGISTER ,Cpy_u8PinNo ); break;
				case DIO_U8_PORT_C : SET_BIT(PORTC_REGISTER ,Cpy_u8PinNo ); break;
				case DIO_U8_PORT_D : SET_BIT(PORTD_REGISTER ,Cpy_u8PinNo ); break;
				default : /*NO thing */ break;
			}
		}
		else if(Cpy_u8PinLevel == DIO_U8_LOW)
		{
			switch(Cpy_u8PortID)
			{
				case DIO_U8_PORT_A : CLR_BIT(PORTA_REGISTER ,Cpy_u8PinNo ); break;
				case DIO_U8_PORT_B : CLR_BIT(PORTB_REGISTER ,Cpy_u8PinNo ); break;
				case DIO_U8_PORT_C : CLR_BIT(PORTC_REGISTER ,Cpy_u8PinNo ); break;
				case DIO_U8_PORT_D : CLR_BIT(PORTD_REGISTER ,Cpy_u8PinNo ); break;
				default : /*NO thing */ break;
			}
		}
	}
}
/**************************************************************************************/
/* Description    :  This Function Set The Pin value in The Run Time                  */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PinNo] 			                          */
/* return         : u8 Pin_Value High Or Low					                                  */
/**************************************************************************************/
u8 Dio_u8GetPinValue(u8 Cpy_u8PortID ,u8 Cpy_u8PinNo )
{
	/* Defiine the Local variable to get the Bit value*/
	u8 u8ResultLocal = 0x00;

	if((Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
	   &&(Cpy_u8PinNo >= DIO_U8_PIN_0  && Cpy_u8PinNo  <=DIO_U8_PIN_7))
	{
		switch(Cpy_u8PortID)
		{
			case DIO_U8_PORT_A : u8ResultLocal = GET_BIT(PINA_REGISTER , Cpy_u8PinNo); break;
			case DIO_U8_PORT_B : u8ResultLocal = GET_BIT(PINB_REGISTER , Cpy_u8PinNo); break;
			case DIO_U8_PORT_C : u8ResultLocal = GET_BIT(PINC_REGISTER , Cpy_u8PinNo); break;
			case DIO_U8_PORT_D : u8ResultLocal = GET_BIT(PIND_REGISTER , Cpy_u8PinNo); break;
			default            : 						   break;
		}
	}
	else
	{
		/*in this case Return Error or portD */
		u8ResultLocal = 0xFF;
	}
	return u8ResultLocal;
}

/**************************************************************************************/
/* Description    :  This Function Set The Port Direction in The Run Time             */
/* Inputs         : [ Cpy_u8PortID,  Cpy_u8PortDirection]                 		      */
/* return         : void						                                      */
/**************************************************************************************/
 void Dio_VoidSetPortDirecton(u8 Cpy_u8PortID , u8 Cpy_u8PortDirection)
  {
	  if(Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
	  {
		  if(Cpy_u8PortDirection == DIO_U8_OUTPUT)
		  {
			  switch(Cpy_u8PortID)
			  {
			  	 case DIO_U8_PORT_A :SET_BYTE(DDRA_REGISTER); break;
			  	 case DIO_U8_PORT_B :SET_BYTE(DDRB_REGISTER); break;
			  	 case DIO_U8_PORT_C :SET_BYTE(DDRC_REGISTER); break;
			  	 case DIO_U8_PORT_D :SET_BYTE(DDRD_REGISTER); break;
			  	 default            : 						   break;
			  }
		  }
		  else if(Cpy_u8PortDirection == DIO_U8_INPUT)
		  {
			  switch(Cpy_u8PortID)
			  {
			  	 case DIO_U8_PORT_A :CLEAR_BYTE(DDRA_REGISTER); break;
			  	 case DIO_U8_PORT_B :CLEAR_BYTE(DDRB_REGISTER); break;
			  	 case DIO_U8_PORT_C :CLEAR_BYTE(DDRC_REGISTER); break;
			  	 case DIO_U8_PORT_D :CLEAR_BYTE(DDRD_REGISTER); break;
	     		 default            : 						   break;
			  }
		  }
	  }
  }


  void Dio_VoidSetPortValue(u8 Cpy_u8PortID , u8 Cpy_u8PortValue)
  {
	  if(Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
	  {
		  if(Cpy_u8PortValue == DIO_U8_LOW)
		  {
			  switch(Cpy_u8PortID)
			  {
			  	 case DIO_U8_PORT_A : CLEAR_BYTE(PORTA_REGISTER); break;
			  	 case DIO_U8_PORT_B : CLEAR_BYTE(PORTB_REGISTER); break;
			  	 case DIO_U8_PORT_C : CLEAR_BYTE(PORTC_REGISTER); break;
			  	 case DIO_U8_PORT_D : CLEAR_BYTE(PORTD_REGISTER); break;
			     default            : 						   break;
			  }
		  }
		  else if(Cpy_u8PortValue == DIO_U8_HIGH)
		  {
			  switch(Cpy_u8PortID)
			  {
			  	 case DIO_U8_PORT_A :SET_BYTE(PORTA_REGISTER); break;
			  	 case DIO_U8_PORT_B :SET_BYTE(PORTB_REGISTER); break;
			  	 case DIO_U8_PORT_C :SET_BYTE(PORTC_REGISTER); break;
			  	 case DIO_U8_PORT_D :SET_BYTE(PORTD_REGISTER); break;
				 default            : 						   break;

			  }
		  }
		  else{ /* NO Thing*/}
	  }
	  else
	  {
		  /* NO Thing */
	  }

  }

 void Dio_VoidWritePortValue(u8 Cpy_u8PortID , u8 Cpy_u8PortValue)
 {
	 if(Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
	 	{
		  switch(Cpy_u8PortID)
		  {
		  	 case DIO_U8_PORT_A : PORTA_REGISTER = Cpy_u8PortValue; break;
		  	 case DIO_U8_PORT_B : PORTB_REGISTER = Cpy_u8PortValue; break;
		  	 case DIO_U8_PORT_C : PORTC_REGISTER = Cpy_u8PortValue; break;
		  	 case DIO_U8_PORT_D : PORTD_REGISTER = Cpy_u8PortValue; break;
			 default            : 						   break;

		  }
	 	}
 }



void Dio_voidWriteBitsInPort(u8 Cpy_u8PortID ,  u8 Cpy_u8Mask , u8 Cpy_u8Value )
{
	switch(Cpy_u8PortID)
	{
		case DIO_U8_PORT_A : CLEAR_BITS_REG(PORTA_REGISTER , Cpy_u8Mask);
							 SET_BITS_REG(PORTA_REGISTER , Cpy_u8Mask & Cpy_u8Value);

		break;

		case DIO_U8_PORT_B : CLEAR_BITS_REG(PORTB_REGISTER , Cpy_u8Mask);
							 SET_BITS_REG(PORTB_REGISTER , Cpy_u8Mask & Cpy_u8Value);

		break;

		case DIO_U8_PORT_C : CLEAR_BITS_REG(PORTC_REGISTER , Cpy_u8Mask);
							 SET_BITS_REG(PORTC_REGISTER , Cpy_u8Mask & Cpy_u8Value);

		break;

		case DIO_U8_PORT_D : CLEAR_BITS_REG(PORTD_REGISTER , Cpy_u8Mask);
							 SET_BITS_REG(PORTD_REGISTER , Cpy_u8Mask & Cpy_u8Value);

		break;

	}
}




  /**************************************************************************************/
  /* Description    :  This Function Set The Port Value in The Run Time                 */
  /* Inputs         : [ Cpy_u8PortID]             					    		      */
  /* return         : u8 Port_Value High Or Low				                          */
  /**************************************************************************************/
  u8 Dio_u8GetPortValue(u8 Cpy_u8PortID)
  {
	  u8 u8ResultLocal = 0x00;
	  if(Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
	  {
		  switch(Cpy_u8PortID)
		  {
		  	    case DIO_U8_PORT_A : u8ResultLocal = PORTA_REGISTER; break;
				case DIO_U8_PORT_B : u8ResultLocal = PORTB_REGISTER; break;
				case DIO_U8_PORT_C : u8ResultLocal = PORTC_REGISTER; break;
				case DIO_U8_PORT_D : u8ResultLocal = PORTD_REGISTER; break;
				default            : 								 break;
		  }
	  }
	  return u8ResultLocal;
  }
  void Dio_vidTogglePort(u8 Cpy_u8PortID)
  {
	  if(Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
	  {
		  switch(Cpy_u8PortID)
		  {
		  	  case DIO_U8_PORT_A : PORTA_REGISTER = ~PORTA_REGISTER; break;
		  	  case DIO_U8_PORT_B : PORTA_REGISTER = ~PORTB_REGISTER; break;
		  	  case DIO_U8_PORT_C : PORTA_REGISTER = ~PORTC_REGISTER; break;
		  	  case DIO_U8_PORT_D : PORTA_REGISTER = ~PORTD_REGISTER; break;
		  	  default: /*NO Thing */ break;
		  }

      }
  }
  void Dio_VoidTogglePinValue(u8 Cpy_u8PortID ,u8 Cpy_u8PinNo)
  {
		if((Cpy_u8PortID >= DIO_U8_PORT_A && Cpy_u8PortID <= DIO_U8_PORT_D)
		   &&(Cpy_u8PinNo >= DIO_U8_PIN_0  && Cpy_u8PinNo  <=DIO_U8_PIN_7))
		{
		  switch(Cpy_u8PortID)
		  {
		  	  case DIO_U8_PORT_A : TOGGEL_BIT(PORTA_REGISTER ,Cpy_u8PinNo ); break;
		  	  case DIO_U8_PORT_B : TOGGEL_BIT(PORTB_REGISTER ,Cpy_u8PinNo ); break;
		  	  case DIO_U8_PORT_C : TOGGEL_BIT(PORTC_REGISTER ,Cpy_u8PinNo ); break;
		  	  case DIO_U8_PORT_D : TOGGEL_BIT(PORTD_REGISTER ,Cpy_u8PinNo ); break;
		  	  default: /*NO Thing */ break;
		  }

      }
		else
		{
			/* no thing*/
		}

  }
