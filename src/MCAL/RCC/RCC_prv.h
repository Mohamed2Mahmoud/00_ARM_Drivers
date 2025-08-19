/*
 * RCC_prv.h
 *
 *  Created on: Aug 14, 2025
 *      Author: Mohamed Ismail
 */

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_


/* Base address for RCC */
#define RCC_BASE_ADDR    0x40023800U


typedef struct {
    u32 CR;
    u32 PLLCFGR;
    u32 CFGR;
    u32 CIR;
    u32 AHB1RSTR;
    u32 AHB2RSTR;
    u32 RESERVED0[2];
    u32 APB1RSTR;
    u32 APB2RSTR;
    u32 RESERVED1[2];
    u32 AHB1ENR;
    u32 AHB2ENR;
    u32 RESERVED2[2];
    u32 APB1ENR;
    u32 APB2ENR;
    u32 RESERVED3[2];
    u32 AHB1LPENR;
    u32 AHB2LPENR;
    u32 RESERVED4[2];
    u32 APB1LPENR;
    u32 APB2LPENR;
    u32 RESERVED5[2];
    u32 BDCR;
    u32 CSR;
    u32 RESERVED6[2];
    u32 SSCGR;
    u32 PLLI2SCFGR;
    u32 DCKCFGR;
} RCC_MemMap_t;

#define RCC ((volatile RCC_MemMap_t *) RCC_BASE_ADDR)

/* ECC_SYS_CLK ----OPTIONS------ */
#define HSE_CLK 0
#define HSI_CLK 1
#define PLL_CLK 2

/* HSE_BYPASS ----OPTIONS------ */
#define RC_CLK 0
#define MECHANICAL_CLK 1

/*CR->BITS*/
#define HSEBYP 18
#define HSEON 16
#define HSERDY 17
#define HSION 0
#define HSIRDY 1

/* AHB1ENR Bits */
#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2
#define GPIODEN 3
#define GPIOEEN 4
#define GPIOFEN 5
#define GPIOGEN 6
#define GPIOHEN 7
#define CRCEN   12
#define DMA1EN  21
#define DMA2EN  22

/* AHB2ENR Bits */
#define OTGFSEN 7

/* APB1ENR Bits */
#define TIM2EN   0
#define TIM3EN   1
#define TIM4EN   2
#define TIM5EN   3
#define WWDGEN   11
#define SPI2EN   14
#define SPI3EN   15
#define USART2EN 17
#define I2C1EN   21
#define I2C2EN   22
#define I2C3EN   23
#define PWREN    28

/* APB2ENR Bits */
#define TIM1EN    0
#define USART1EN  4
#define USART6EN  5
#define ADC1EN    8
#define SDIOEN    11
#define SPI1EN    12
#define SPI4EN    13
#define SYSCFGEN  14
#define TIM9EN    16
#define TIM10EN   17
#define TIM11EN   18




#endif /* MCAL_RCC_RCC_PRV_H_ */
