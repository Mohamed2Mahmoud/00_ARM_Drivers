/*
 * SPI_int.h
 *
 *  Created on: Sep 1, 2025
 *      Author: drago
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define MSPI1   1
#define MSPI2   2
#define MSPI3   3
#define MSPI4   4

typedef enum {
    SPI_BAUD_DIV2 = 0,
    SPI_BAUD_DIV4,
    SPI_BAUD_DIV8,
    SPI_BAUD_DIV16,
    SPI_BAUD_DIV32,
    SPI_BAUD_DIV64,
    SPI_BAUD_DIV128,
    SPI_BAUD_DIV256
} MSPI_BaudRate_t;

typedef enum {
    SPI_CPOL_LOW = 0,
    SPI_CPOL_HIGH
} MSPI_ClockPolarity_t;

typedef enum {
    SPI_CPHA_FIRST = 0,
    SPI_CPHA_SECOND
} MSPI_ClockPhase_t;

typedef enum {
    SPI_MSB_FIRST = 0,
    SPI_LSB_FIRST
} MSPI_DataOrder_t;

typedef enum {
    SPI_MODE_SLAVE = 0,
    SPI_MODE_MASTER
} MSPI_Mode_t;

typedef enum {
    SPI_INT_RXNE = 0,
    SPI_INT_TXE,
    SPI_INT_ERR
} MSPI_Interrupt_t;
typedef enum{
	SPI1=0,
	SPI2,
	SPI3,
	SPI4,
}MSPI_No_t;
typedef struct {
	MSPI_No_t SPIx;
	MSPI_Mode_t Mode;
    MSPI_BaudRate_t BaudRate;
    MSPI_ClockPolarity_t SPI_CPOL;
    MSPI_ClockPhase_t SPI_CPHA;
    MSPI_DataOrder_t DataOrder;
} MSPI_Config_t;

void MSPI_vInit(MSPI_Config_t *A_pxConfig);
void MSPI_vEnable(u8 A_u8SPIx);
void MSPI_vDisable(u8 A_u8SPIx);

void MSPI_vSendData(u8 A_u8SPIx, u16 A_u16Data);
u16  MSPI_u16ReceiveData(u8 A_u8SPIx);
u8  MSPI_u8Transceive(MSPI_Config_t *A_pxConfig, u8 A_u16Data);

void MSPI_vEnableInterrupt(u8 A_u8SPIx, MSPI_Interrupt_t A_IntType);
void MSPI_vDisableInterrupt(u8 A_u8SPIx, MSPI_Interrupt_t A_IntType);
void MSPI_vSetCallBack(u8 A_u8SPIx, void (*A_pvCallBackFunc)(void));

void MSPI_vSetClockPolarity(u8 A_u8SPIx, MSPI_ClockPolarity_t A_Polarity);
void MSPI_vSetClockPhase(u8 A_u8SPIx, MSPI_ClockPhase_t A_Phase);
void MSPI_vSetDataOrder(u8 A_u8SPIx, MSPI_DataOrder_t A_Order);
void MSPI_vSetBaudRate(u8 A_u8SPIx, MSPI_BaudRate_t A_Prescaler);
void MSPI_vSetMode(u8 A_u8SPIx, MSPI_Mode_t A_Mode);



#endif /* MCAL_SPI_SPI_INT_H_ */
