/*
 * EXTI_int.h
 *
 *  Created on: Aug 19, 2025
 *      Author: Koshok
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#include "../../LIB/STD_TYPES.h"

void EXTI_EnableInterrupt(u8 line);
void EXTI_DisableInterrupt(u8 line);

void EXTI_EnableEvent(u8 line);
void EXTI_DisableEvent(u8 line);

void EXTI_EnableRisingTrigger(u8 line);
void EXTI_EnableFallingTrigger(u8 line);
void EXTI_DisableRisingTrigger(u8 line);
void EXTI_DisableFallingTrigger(u8 line);

void EXTI_GenerateSWInterrupt(u8 line);

void EXTI_ClearPending(u8 line);
u8   EXTI_GetPending(u8 line);

#endif /* MCAL_EXTI_EXTI_INT_H_ */
