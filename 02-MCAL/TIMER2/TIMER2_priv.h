
#ifndef TIMER2_PRIV_H_
#define TIMER2_PRIV_H_

#define TIMER2_u8_NORMAL          1
#define TIMER2_u8_CTC             2
#define TIMER2_u8_FAST_PWM        3
#define TIMER2_u8_PHASE_CORRECT   4


#define TIMER2_u8_DIV_BY_1        1
#define TIMER2_u8_DIV_BY_8        2
#define TIMER2_u8_DIV_BY_32       3
#define TIMER2_u8_DIV_BY_64       4
#define TIMER2_u8_DIV_BY_128      5
#define TIMER2_u8_DIV_BY_256      6
#define TIMER2_u8_DIV_BY_1024     7

#define TIMER2_u8_NO_ACTION      1
#define TIMER2_u8_TOGGLE         2
#define TIMER2_u8_SET            3
#define TIMER2_u8_CLEAR          4

#define  OCR2   (*(volatile u8 *)0x43)
#define  TCCR2  (*(volatile u8 *)0x45)
#define  TCNT2  (*(volatile u8 *)0x44)

#define  TIFR   (*(volatile u8 *)0x58)
#define  TIMSK  (*(volatile u8 *)0x59)

#endif /* TIMER2_PRIV_H_ */
