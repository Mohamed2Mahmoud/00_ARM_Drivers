/*
 * UART_prg.c
 *
 *  Created on: Aug 31, 2025
 *      Author: drago
 */

#include "UART_cfg.h"
#include "UART_int.h"
#include "UART_prv.h"

void USART_vInit(void){

	CLR_BIT(USART1->CR1,OVER8);

	CLR_BIT(USART1->CR1,12);

	CLR_BIT(USART1->CR1,10);

	USART1->BRR = 162<<4 | 13;

	CLR_BIT(USART1->CR2,12);

	CLR_BIT(USART1->CR2,13);

	SET_BIT(USART1->CR1,3);

	SET_BIT(USART1->CR1,2);

	SET_BIT(USART1->CR1,13);

}

void USART_vSendData(u8 A_u8Data){

	while(!GET_BIT(USART1->SR,7));

	USART1->DR = A_u8Data;

	while(!GET_BIT(USART1->SR,6));

	CLR_BIT(USART1->SR,6);
}

u8 USART_u8ReiceiveData(){
	while(!GET_BIT(USART1->SR,5));

	return USART1->DR;
}



