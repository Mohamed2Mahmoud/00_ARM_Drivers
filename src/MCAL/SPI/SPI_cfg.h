/*
 * SPI_cfg.h
 *
 *  Created on: Sep 1, 2025
 *      Author: drago
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

#include "SPI_int.h"


/* Set 1 to enable, 0 to disable */
#define MSPI1_ENABLE   1
#define MSPI2_ENABLE   0
#define MSPI3_ENABLE   0
#define MSPI4_ENABLE   0

#define MSPI_DEFAULT_MODE         SPI_MODE_MASTER
#define MSPI_DEFAULT_BAUDRATE     SPI_BAUD_DIV16
#define MSPI_DEFAULT_CPOL         SPI_CPOL_LOW
#define MSPI_DEFAULT_CPHA         SPI_CPHA_FIRST
#define MSPI_DEFAULT_DATA_ORDER   SPI_MSB_FIRST

/* 0 = Disable all interrupts, 1 = Enable  */
#define MSPI_INT_ENABLE           0


extern const MSPI_Config_t MSPI_DefaultConfig;


#endif /* MCAL_SPI_SPI_CFG_H_ */
