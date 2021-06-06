  /***************************************************************************
  *     File        : LCD_interface.h								      	 *
  *     Auther      : Zaki Ahmed hamed                                       *
  *     Description : 16x2 Character LCD for chip LMB161A  LCD_INTERFACE.h   *
  *     Date        : 20 August 2020                                         *
  *     Version     : V04                                                    *
  ***************************************************************************/


   /*************************************************************************************
   *     Description : Guard to Protect this file from include more than one time       *
   *************************************************************************************/
#ifndef    _LCD_INTERFACE_H
#define    _LCD_INTERFACE_H


#define  LCD_FUNCTION_SET_8BIT  0x38  //set 8 bit data ,2 lines display 5x8 font
#define  LCD_FUNCTION_SET_4BIT  0x28  //set 4 bit data ,2 lines display 5x8 font

#define  LCD_CLEAR       		0x01  //Clear All Display By Writing a space
#define  LCD_RETURN_HOME     	0x02  //return cursor to the first position in the first Line
#define  LCD_ENTRY_MODE  		0x06  //shift cursor from left to right on read/write
#define  LCD_DISPLAY_OFF 		0x08  //display off, cursor off ,dont blink character
#define  LCD_DISPLAY_ON  		0X0C  //display ON, cursor off ,dont blink character
#define  LCD_SetCursor          0x80  // Set cursor position
#define  LCD_ShiftLeft          0x18  // Display shift left
#define  LCD_ShiftRight         0x1C  // Display shift right
#define  LCD_2ndLine            0xC0  // Move cursor to the beginning of second line

/************ Modes operations  ************/
#define LCD_8BIT_MODE			1
#define LCD_4BIT_MODE			0


/************for 4 bit separated pins  mode define pins   ************/
#define  D4  DIO_U8_PIN_4
#define  D5  DIO_U8_PIN_5
#define  D6  DIO_U8_PIN_6
#define  D7  DIO_U8_PIN_7

/*****for 4 bit same port mode define pins mask in port ****/
#define M_4BIT_MASK 0XF0


/*************************************************************************
 *********************     Function prototypes  ***************************
 *************************************************************************/


 /*************************************************************************************
  *  Description : This function used to initialize The  LCD 					       *
  *  Input       : Void                                                                *
  *  Return      : Void                                                                *
  **************************************************************************************/
void LCD_VoidInit(void);

  /*************************************************************************************
  *  Description : This function used to Write a character on LCD        			   *
  *  Input       : u8 Cpy_u8Data                                                       *
  *  Return      : Void                                                                *
  **************************************************************************************/
void LCD_VoidWriteChar(u8 Cpy_u8Char);


  /*******************************************************************
  *  Description : This function used to Write a command on LCD      *
  *  Input       : u8 Cpy_u8Data             						 *
  *  Return      : Void                                              *
  *******************************************************************/
//void LCD_VoidWriteCommand(u8 Cpy_u8Data);

  /**********************************************************************
  *  Description : This function used to Write a String on LCD        	*
  *  Input       : u8 *Cpy_u8Data                                       *
  *  Return      : Void                                                 *
  **********************************************************************/
void LCD_VoidWriteString(u8 *Cpy_u8String);

/***********************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD */
/* Input      !  Row position ,  Column position                                   */
/* Return     ! Nothing                                                            */
/***********************************************************************************/
void LCD_GoToXy(u8 cpy_u8Row , u8 Cpy_u8Coulmn);


/**************************************************************************/
/* Description! function used to Write numbers on the LCD     			  */
/* Input      ! Numbers you want entered                                  */
/* return     ! void                                                      */
/**************************************************************************/
void LCD_VoidWriteNum(u16 Copy_U16Number);

void LCD_voidClear(void);

#endif /* _LCD_INTERFACE_H*/
