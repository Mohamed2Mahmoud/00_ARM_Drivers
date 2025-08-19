/*
 * Delay_prv.h
 *
 *  Created on: Aug 18, 2025
 *      Author: drago
 */

#ifndef LIB_DELAY_DELAY_PRV_H_
#define LIB_DELAY_DELAY_PRV_H_

#include "Delay_cfg.h"

#define SEC_DELAY_FACTOR  4000000u
#define MS_DELAY_FACTOR  4000u
#define US_DELAY_FACTOR  4u

#define NOP()  __asm volatile ("nop")

#endif /* LIB_DELAY_DELAY_PRV_H_ */
