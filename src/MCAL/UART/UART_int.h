/*
 * UART_int.h
 *
 *  Created on: Aug 31, 2025
 *      Author: Ahmed
 */

#ifndef APP_MCAL_UART_UART_INT_H_
#define APP_MCAL_UART_UART_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void USART_vInit(void);
void USART_vSendData(u8 A_u8Data);
u8 USART_u8ReiceiveData();



#endif /* APP_MCAL_UART_UART_INT_H_ */
