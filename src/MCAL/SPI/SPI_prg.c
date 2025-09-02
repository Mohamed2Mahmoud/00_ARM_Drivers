/*
 * SPI_prg.c
 *
 *  Created on: Sep 1, 2025
 *      Author: drago
 */

#include "SPI_cfg.h"
#include "SPI_prv.h"
#include "SPI_int.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void MSPI_vInit(MSPI_Config_t *A_pxConfig) {
	const MSPI_Config_t *pxConfig;

	/*
	 if (A_pxConfig == NULL) {
	 pxConfig = &MSPI_DefaultConfig;
	 } else {
	 pxConfig = A_pxConfig;
	 }*/

	SPIx_MemMap_t *SPIx;   // pointer, not object

	switch (A_pxConfig->SPIx) {
	case MSPI1:
		SPIx = (SPIx_MemMap_t*) SPI1_BASE_ADDR;
		break;
	case MSPI2:
		SPIx = (SPIx_MemMap_t*) SPI2_BASE_ADDR;
		break;
	case MSPI3:
		SPIx = (SPIx_MemMap_t*) SPI3_BASE_ADDR;
		break;
	case MSPI4:
		SPIx = (SPIx_MemMap_t*) SPI4_BASE_ADDR;
		break;
	default:
		;  // invalid peripheral
	}

	SET_BIT(SPIx->CR1, SSM);
	SET_BIT(SPIx->CR1, SSI);

	CLR_BIT(SPIx->CR1, DFF);

	CLR_BIT(SPIx->CR1, LSBFIRST);

	SPIx->CR1 &= ~(0b111 << 3);
	SPIx->CR1 |= (0b110 << 3);

	SET_BIT(SPIx->CR1, SPI_CR1_CPOL);
	SET_BIT(SPIx->CR1, SPI_CR1_CPHA);
	SET_BIT(SPIx->CR1, SPE);

}

void MSPI_vEnable(u8 A_u8SPIx) {

}

void MSPI_vDisable(u8 A_u8SPIx) {

}

void MSPI_vSendData(u8 A_u8SPIx, u16 A_u16Data) {

}

u16 MSPI_u16ReceiveData(u8 A_u8SPIx) {
	return 0;
}

u8 MSPI_u8Transceive(MSPI_Config_t *A_pxConfig, u8 A_u16Data) {

	SPIx_MemMap_t *SPIx;

	switch (A_pxConfig->SPIx) {
	case MSPI1:
		SPIx = (SPIx_MemMap_t*) SPI1_BASE_ADDR;
		break;
	case MSPI2:
		SPIx = (SPIx_MemMap_t*) SPI2_BASE_ADDR;
		break;
	case MSPI3:
		SPIx = (SPIx_MemMap_t*) SPI3_BASE_ADDR;
		break;
	case MSPI4:
		SPIx = (SPIx_MemMap_t*) SPI4_BASE_ADDR;
		break;
	default:
		;  // invalid peripheral
	}

	while (GET_BIT(SPIx->SR,TXE) == 0)
		;
	SPIx->DR = A_u16Data;
	while (GET_BIT(SPIx->SR,RXNE) == 0)
		;
	return SPIx->DR;

	return 0;
}

void MSPI_vEnableInterrupt(u8 A_u8SPIx, MSPI_Interrupt_t A_IntType) {

}

void MSPI_vDisableInterrupt(u8 A_u8SPIx, MSPI_Interrupt_t A_IntType) {

}

void MSPI_vSetCallBack(u8 A_u8SPIx, void (*A_pvCallBackFunc)(void)) {

}

void MSPI_vSetClockPolarity(u8 A_u8SPIx, MSPI_ClockPolarity_t A_Polarity) {

}

void MSPI_vSetClockPhase(u8 A_u8SPIx, MSPI_ClockPhase_t A_Phase) {

}

void MSPI_vSetDataOrder(u8 A_u8SPIx, MSPI_DataOrder_t A_Order) {

}

void MSPI_vSetBaudRate(u8 A_u8SPIx, MSPI_BaudRate_t A_Prescaler) {

}

void MSPI_vSetMode(u8 A_u8SPIx, MSPI_Mode_t A_Mode) {

}
