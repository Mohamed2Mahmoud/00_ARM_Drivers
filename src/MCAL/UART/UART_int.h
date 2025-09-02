/*
 * UART_int.h
 *
 *  Created on: Aug 31, 2025
 *      Author: drago
 */

#ifndef APP_MCAL_UART_UART_INT_H_
#define APP_MCAL_UART_UART_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

//================= USART Bitfield Macros =================//

// CR1
#define USART_OVER8        15   // Oversampling mode
#define USART_M            12   // Word length
#define USART_PCE          10   // Parity control enable
#define USART_PS           9    // Parity selection
#define USART_TE           3    // Transmitter enable
#define USART_RE           2    // Receiver enable
#define USART_UE           13   // USART enable

// CR2
#define USART_STOP_BITS_POS    12    // Stop bits position [13:12]

// SR
#define USART_TXE_FLAG     7
#define USART_TC_FLAG      6
#define USART_RXNE_FLAG    5

#define USART1_BRR_VALUE   2500

#define USART_STOPBITS_1        (0x0U << USART_STOP_BITS_POS)  // 00
#define USART_STOPBITS_0_5      (0x1U << USART_STOP_BITS_POS)  // 01
#define USART_STOPBITS_2        (0x2U << USART_STOP_BITS_POS)  // 10
#define USART_STOPBITS_1_5      (0x3U << USART_STOP_BITS_POS)  // 11

#define USART_PARITY_NONE       (0U)
#define USART_PARITY_EVEN       (1U << USART_PCE)
#define USART_PARITY_ODD        ((1U << USART_PCE) | (1U << USART_PS))

#define USART_WORDLEN_8         (0U << USART_M)
#define USART_WORDLEN_9         (1U << USART_M)

#define USART_OVERSAMPLE_16     (0U << USART_OVER8)
#define USART_OVERSAMPLE_8      (1U << USART_OVER8)

void USART_vInit(void);
void USART_vSendData(u8 A_u8Data);
u8 USART_u8ReiceiveData();



#endif /* APP_MCAL_UART_UART_INT_H_ */
