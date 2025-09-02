/*
 * UART_prv.h
 *
 *  Created on: Aug 31, 2025
 *      Author: Ahmed
 */

#ifndef APP_MCAL_UART_UART_PRV_H_
#define APP_MCAL_UART_UART_PRV_H_

#define USART1_BASE_ADDR 0x40011000U
#define USART2_BASE_ADDR 0x40004400U
#define USART6_BASE_ADDR 0x40011400U

typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}USARTx_MemMap_t;

#define USART1 ((volatile USARTx_MemMap_t*)(USART1_BASE_ADDR))
#define USART2 ((volatile USARTx_MemMap_t*)(USART2_BASE_ADDR))
#define USART6 ((volatile USARTx_MemMap_t*)(USART6_BASE_ADDR))

#define OVER8 15

#endif /* APP_MCAL_UART_UART_PRV_H_ */
