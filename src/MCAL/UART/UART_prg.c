/*
 * UART_prg.c
 *
 *  Created on: Aug 31, 2025
 *      Author: drago
 */

#include "UART_cfg.h"
#include "UART_int.h"
#include "UART_prv.h"

//================= USART1 Functions =================//

void USART1_vInit(void)
{
    // 1) Oversampling = 16
    CLR_BIT(USART1->CR1, USART_OVER8);

    // 2) Word length = 8 bits
    CLR_BIT(USART1->CR1, USART_M);

    // 3) Parity = None
    CLR_BIT(USART1->CR1, USART_PCE);

    // 4) Baud rate
    USART1->BRR = USART1_BRR_VALUE;

    // 5) Stop bits = 1
    USART1->CR2 &= ~(0x3U << USART_STOP_BITS_POS);  // clear
    USART1->CR2 |= USART_STOPBITS_1;

    // 6) Enable transmitter, receiver
    SET_BIT(USART1->CR1, USART_TE);
    SET_BIT(USART1->CR1, USART_RE);

    // 7) Enable USART
    SET_BIT(USART1->CR1, USART_UE);
}

void USART1_vSendData(u8 A_u8Data)
{
    // Wait until TXE flag is set
    while (!GET_BIT(USART1->SR, USART_TXE_FLAG));

    // Load data into DR
    USART1->DR = A_u8Data;

    // Wait until transmission complete (TC flag)
    while (!GET_BIT(USART1->SR, USART_TC_FLAG));

    // Clear TC flag (optional, some HALs do this automatically)
    CLR_BIT(USART1->SR, USART_TC_FLAG);
}

u8 USART1_u8ReceiveData(void)
{
    // Wait until RXNE flag is set
    while (!GET_BIT(USART1->SR, USART_RXNE_FLAG));

    // Return received data
    return (u8)USART1->DR;
}
