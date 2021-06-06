/*
 * UART_private.h
 *
 *  Created on: Aug 13, 2020
 *      Author: zaki
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

//USART Control and Status Register A – UCSRA PINS

#define	RXC		7
#define	TXC		6
#define	UDRE	5
#define	FE 		4
#define	DOR		3
#define	PE 		2
#define	U2X 	1
#define	MPCM	0

//USART Control and Status Register B UCSRB PINS

#define	RXCIE	7
#define	TXCIE	6
#define	UDRIE	5
#define	RXEN 	4
#define	TXEN	3
#define	UCSZ2	2
#define	RXB8	1
#define	TXB8	0

//USART Control and Status Register C UCSRC PINS

#define	URSEL	7
#define	UMSEL	6
#define	UPM1 	5
#define	UPM0	4
#define	USBS	3
#define	UCSZ1 	2
#define	UCSZ0 	1
#define	UCPOL	0







#define UDR        *((volatile u8 *)(0x2C))

#define UCSRA      *((volatile u8 *)(0x2B))


#define UCSRB      *((volatile u8 *)(0x2A))

#define UCSRC      *((volatile u8 *)(0x40))

 //UBRRL USART Baud Rate Register HIGH Byte
#define UBRRH      *((volatile u8 *)(0x40))

//UBRRL USART Baud Rate Register Low Byte
#define UBRRL      *((volatile u8 *)(0x29))


#endif /* UART_PRIVATE_H_ */
