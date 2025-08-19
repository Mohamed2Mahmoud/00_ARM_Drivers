/*
 * NVIC_prv.h
 *
 *  Created on: Aug 18, 2025
 *      Author: drago
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_

#include "../../LIB/STD_TYPES.h"

#define NVIC_BASE_ADDR 0xE000E100U



/* -------------------- NVIC Registers -------------------- */
typedef struct{
	u32 ISER[8];
	u32 RESERVED0[24];
	u32 ISPR[8];
	u32 RESERVED1[24];
	u32 ICPR[8];
	u32 RESERVED2[24];
	u32 IABR[8];
	u32 RESERVED3[56];
	u8 IPR[240];
	u32 RESERVED4[644];
	u32 STIR;
}NVIC_MemMap_t;


#define NVIC   ((volatile NVIC_MemMap_t*) NVIC_BASE_ADDR)


#endif /* MCAL_NVIC_NVIC_PRV_H_ */
