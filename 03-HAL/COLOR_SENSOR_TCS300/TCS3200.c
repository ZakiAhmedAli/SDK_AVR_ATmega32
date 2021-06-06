/*
 * TCS3200.c
 *
 * Created: 12/20/2020 10:41:31 PM
 *  Author: Ahmed Basheer
 */ 
#include "TCS3200.h"
#include "LCD.h"

void TCS3200_Init(void)
{
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_1,OCRA_DISCONNECTED,OCRB_DISCONNECTED);
	DIO_InitPin(TCS_S0 , OUTPUT);
	DIO_InitPin(TCS_S1 , OUTPUT);
	DIO_InitPin(TCS_S2 , OUTPUT);
	DIO_InitPin(TCS_S3 , OUTPUT);
	DIO_InitPin(TCS_OUT , FREE);
}
void TCS3200_FrequencyScaling(TCS3200_Scale_t scale)
{
	switch(scale)
	{
		case POWER_DOWN:
		DIO_WritePin(TCS_S0 , LOW);
		DIO_WritePin(TCS_S1 , LOW);
		break;
		case SCALE_2:
		DIO_WritePin(TCS_S0 , LOW);
		DIO_WritePin(TCS_S1 , HIGH);
		break;
		case SCALE_20:
		DIO_WritePin(TCS_S0 , HIGH);
		DIO_WritePin(TCS_S1 , LOW);
		break;
		case SCALE_100:
		DIO_WritePin(TCS_S0 , HIGH);
		DIO_WritePin(TCS_S1 , HIGH);
		break;
	}
}
void TCS_SelectRed	(void)
{
	DIO_WritePin(TCS_S2 , LOW);
	DIO_WritePin(TCS_S3 , LOW);
}
void TCS_SelectGreen(void)
{
	DIO_WritePin(TCS_S2 , HIGH);
	DIO_WritePin(TCS_S3 , HIGH);
}
void TCS_SelectBlue (void)
{
	DIO_WritePin(TCS_S2 , LOW);
	DIO_WritePin(TCS_S3 , HIGH);
}
void TCS_SelectClear(void)
{
	DIO_WritePin(TCS_S2 , HIGH);
	DIO_WritePin(TCS_S3 , LOW);
}
float32_t TCS_Measure(void)
{
	//If the function is entered when the level on OUT line was low
	//Then wait for it to become high.
	if(!(DIO_ReadPin(TCS_OUT)))
	{
		while(!(DIO_ReadPin(TCS_OUT)));   //Wait for rising edge
	}
	while((DIO_ReadPin(TCS_OUT)));   //Wait for falling edge
	TCNT1=0;//Reset Counter
	TCCR1B=(1<<CS10); //Prescaller = F_CPU/1 (Start Counting)
	while(!(DIO_ReadPin(TCS_OUT)));   //Wait for rising edge
	//Stop Timer
	TCCR1B=0x00;
	return ((float32_t)8000000UL/TCNT1);
}
uint32_t TCS_MeasureRED(void)
{
	TCS_SelectRed();
	uint32_t r;
	
	_delay_ms(10);
	r=TCS_Measure();
	
	_delay_ms(10);
	r+=TCS_Measure();
	
	_delay_ms(10);
	r+=TCS_Measure();
	
	return r/3.3;
	
}
uint32_t TCS_MeasureGREEN(void)
{
	TCS_SelectGreen();
	uint32_t r;
	
	_delay_ms(10);
	r=TCS_Measure();
	
	_delay_ms(10);
	r+=TCS_Measure();
	
	_delay_ms(10);
	r+=TCS_Measure();
	
	return r/3;
	
}
uint32_t TCS_MeasureBLUE(void)
{
	TCS_SelectBlue();
	uint32_t r;
	
	_delay_ms(10);
	r=TCS_Measure();
	
	_delay_ms(10);
	r+=TCS_Measure();
	
	_delay_ms(10);
	r+=TCS_Measure();
	
	return r/4;
	
}
uint32_t TCS_MeasureCLEAR(void)
{
	TCS_SelectClear();
	uint32_t r;
	
	_delay_ms(10);
	r=TCS_Measure();
	
	_delay_ms(10);
	r+=TCS_Measure();
	
	_delay_ms(10);
	r+=TCS_Measure();
	
	return r/3;
}
/* Based on RGB components ==> Determine color */
TCS3200_Color_t TCS3200_MapColor(uint8_t red,uint8_t grn,uint8_t blu)
{
	TCS3200_Color_t color ;
	if ( (red > 9 && red < 16) && (grn > 9 && grn < 30) && (blu > 9 && blu < 15) ) color = WHITE;
	else if ( (red==10) && (grn > 10 && grn < 14) && (blu > 9 && blu < 12) ) color = BLACK;
	else if (red > 12 && red < 30 && grn > 40 && grn < 70 && blu > 33 && blu < 70) color = RED_N;
	else if (red > 50 && red < 95 && grn > 35 && grn < 70 && blu > 45 && blu < 85) color = GREEN_N;
	else if (red > 13 && red < 45 && grn > 12 && grn < 35 && blu > 9 && blu < 13) color = YELLOW;
	else if (red > 65 && red < 125 && grn > 65 && grn < 115 && blu > 32 && blu < 65) color = BLUE_N;
	return color;
}

TCS3200_Color_t TCS3200_GetColor(void)
{
	TCS3200_Color_t color ;
	DIO_SetPin(TCS_LED);
	uint32_t v1=TCS_MeasureCLEAR();
	_delay_ms(100);
	uint32_t v2=TCS_MeasureCLEAR();
	//Show
	uint32_t r,g,b;
	r=TCS_MeasureRED();
	g=TCS_MeasureGREEN();
	b=TCS_MeasureBLUE();
	uint32_t smallest;
	if(r<b)
	{
		if(r<g)
		smallest=r;
		else
		smallest=g;
	}
	else
	{
		if(b<g)
		smallest=b;
		else
		smallest=g;
	}
	uint32_t _r,_g,_b;
	smallest=smallest/10;
	_r=r/smallest;
	_g=g/smallest;
	_b=b/smallest;

	LCD_GoTo(1,0);
	LCD_WriteStr("R=");
	LCD_PrintNum2D(_r);

	LCD_GoTo(1,7);
	LCD_WriteStr("G=");
	LCD_PrintNum2D(_g);

	LCD_GoTo(1,12);

	LCD_WriteStr("B=");
	LCD_PrintNum2D(_b);

	color=(TCS3200_MapColor(_r,_g,_b));
	//End Show
	return color;
}
