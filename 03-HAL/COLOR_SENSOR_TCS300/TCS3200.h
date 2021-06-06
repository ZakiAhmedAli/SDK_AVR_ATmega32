/*
 * TCS3200.h
 *
 * Created: 12/20/2020 10:41:19 PM
 *  Author: Ahmed Basheer
 */ 
#ifndef TCS3200_H_
#define TCS3200_H_

#define F_CPU 8000000UL

#include "StdTypes.h"
#include "Utils.h"

#include "DIO_Interface.h"
#include "Timers.h"

/*
S2  -> PINC0
S3  -> PINC1
OUT -> PINC2
LED -> PINC3
*/

//TSC PORT Connection
#define TCS_PORT	    PD
//S0 Connection
#define TCS_S0  		PIND4
//S1 Connection
#define TCS_S1 		    PIND5
//S2 Connection
#define TCS_S2 		    PIND0
//S3 Connection
#define TCS_S3 		    PIND1
//OUTPUT PIN Connection
#define TCS_OUT  		PIND2
//LED PIN Connection
#define TCS_LED  		PIND3

typedef enum
{
	POWER_DOWN=0,
	SCALE_2,
	SCALE_20,
	SCALE_100
}TCS3200_Scale_t;

typedef enum
{
	NO_COLOR,
	WHITE,
	BLACK,
	GREEN_N,
	RED_N,
	YELLOW,
	BLUE_N	
}TCS3200_Color_t;

extern void TCS3200_Init(void);
extern void TCS3200_FrequencyScaling(TCS3200_Scale_t scale);
extern void TCS_SelectRed(void);
extern void TCS_SelectGreen(void);
extern void TCS_SelectBlue (void);
extern void TCS_SelectClear(void);
extern float32_t TCS_Measure(void);
extern uint32_t TCS_MeasureRED(void);
extern uint32_t TCS_MeasureGREEN(void);
extern uint32_t TCS_MeasureBLUE(void);
extern uint32_t TCS_MeasureCLEAR(void);
extern TCS3200_Color_t TCS3200_MapColor(uint8_t red,uint8_t grn,uint8_t blu);
extern TCS3200_Color_t TCS3200_GetColor(void);

#endif /* TCS3200_H_ */
