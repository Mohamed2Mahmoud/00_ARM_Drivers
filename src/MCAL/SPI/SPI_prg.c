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

const MSPI_Config_t MSPI_DefaultConfig = {
    .Mode      = MSPI_DEFAULT_MODE,
    .BaudRate  = MSPI_DEFAULT_BAUDRATE,
    .SPI_CPOL  = MSPI_DEFAULT_CPOL,
    .SPI_CPHA  = MSPI_DEFAULT_CPHA,
    .DataOrder = MSPI_DEFAULT_DATA_ORDER
};

void MSPI_vInit(u8 A_u8SPIx, MSPI_Config_t *A_pxConfig)
{
    const MSPI_Config_t *pxConfig;

    if (A_pxConfig == NULL) {
        pxConfig = &MSPI_DefaultConfig;
    } else {
        pxConfig = A_pxConfig;
    }

    switch (A_u8SPIx) {
    #if MSPI1_ENABLE
        case MSPI1:

            break;
    #endif

    #if MSPI2_ENABLE
        case MSPI2:

            break;
    #endif

    #if MSPI3_ENABLE
        case MSPI3:

            break;
    #endif

    #if MSPI4_ENABLE
        case MSPI4:

            break;
    #endif

        default:

            break;
    }
}

void MSPI_vEnable(u8 A_u8SPIx)
{

}

void MSPI_vDisable(u8 A_u8SPIx)
{

}

void MSPI_vSendData(u8 A_u8SPIx, u16 A_u16Data)
{

}

u16 MSPI_u16ReceiveData(u8 A_u8SPIx)
{
    return 0;
}

u16 MSPI_u16Transceive(u8 A_u8SPIx, u16 A_u16Data)
{
    return 0;
}

void MSPI_vEnableInterrupt(u8 A_u8SPIx, MSPI_Interrupt_t A_IntType)
{

}

void MSPI_vDisableInterrupt(u8 A_u8SPIx, MSPI_Interrupt_t A_IntType)
{

}

void MSPI_vSetCallBack(u8 A_u8SPIx, void (*A_pvCallBackFunc)(void))
{

}

void MSPI_vSetClockPolarity(u8 A_u8SPIx, MSPI_ClockPolarity_t A_Polarity)
{

}

void MSPI_vSetClockPhase(u8 A_u8SPIx, MSPI_ClockPhase_t A_Phase)
{

}

void MSPI_vSetDataOrder(u8 A_u8SPIx, MSPI_DataOrder_t A_Order)
{

}

void MSPI_vSetBaudRate(u8 A_u8SPIx, MSPI_BaudRate_t A_Prescaler)
{

}

void MSPI_vSetMode(u8 A_u8SPIx, MSPI_Mode_t A_Mode)
{

}
