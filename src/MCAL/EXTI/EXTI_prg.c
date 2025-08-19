/*
 * EXTI_prg.c
 *
 *  Created on: Aug 19, 2025
 *      Author: Koshok
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_cfg.h"
#include "EXTI_prv.h"

void EXTI_EnableInterrupt(u8 line) {
    SET_BIT(EXTI->IMR, line);
}

void EXTI_DisableInterrupt(u8 line) {
    CLR_BIT(EXTI->IMR, line);
}

void EXTI_EnableEvent(u8 line) {
    SET_BIT(EXTI->EMR, line);
}

void EXTI_DisableEvent(u8 line) {
    CLR_BIT(EXTI->EMR, line);
}

void EXTI_EnableRisingTrigger(u8 line) {
    SET_BIT(EXTI->RTSR, line);
}

void EXTI_EnableFallingTrigger(u8 line) {
    SET_BIT(EXTI->FTSR, line);
}

void EXTI_DisableRisingTrigger(u8 line) {
    CLR_BIT(EXTI->RTSR, line);
}

void EXTI_DisableFallingTrigger(u8 line) {
    CLR_BIT(EXTI->FTSR, line);
}

void EXTI_GenerateSWInterrupt(u8 line) {
    SET_BIT(EXTI->SWIER, line);
}

void EXTI_ClearPending(u8 line) {
    SET_BIT(EXTI->PR, line);
}

u8 EXTI_GetPending(u8 line) {
    return GET_BIT(EXTI->PR, line);
}
