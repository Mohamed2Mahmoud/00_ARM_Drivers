/*
 * EXTI_prv.h
 *
 *  Created on: Aug 19, 2025
 *      Author: Koshok
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#include "../../LIB/STD_TYPES.h"

#define EXTI_BASE_ADDR 0x40013C00U

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_MemMap_t;

#define EXTI   ((volatile EXTI_MemMap_t*) EXTI_BASE_ADDR)


#endif /* MCAL_EXTI_EXTI_PRV_H_ */
