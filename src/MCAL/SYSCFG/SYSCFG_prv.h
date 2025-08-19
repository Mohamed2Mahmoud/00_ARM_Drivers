/*
 * SYSCFG_prv.h
 *
 *  Created on: Aug 19, 2025
 *      Author: Koshok
 */
#include "../../LIB/STD_TYPES.h"

#ifndef MCAL_SYSCFG_SYSCFG_PRV_H_
#define MCAL_SYSCFG_SYSCFG_PRV_H_

#define SYSCFG_BASE_ADDR 0x40013800U

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}SYSCFG_MemMap_t;

#define SYSCFG   ((volatile SYSCFG_MemMap_t*) SYSCFG_BASE_ADDR)

#endif /* MCAL_SYSCFG_SYSCFG_PRV_H_ */
