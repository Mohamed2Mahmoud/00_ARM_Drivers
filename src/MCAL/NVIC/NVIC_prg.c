/*
 * NVIC_prg.c
 *
 *  Created on: Aug 18, 2025
 *      Author: Mohamed Ismail
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "NVIC_int.h"
#include "NVIC_cfg.h"
#include "NVIC_prv.h"

void NVIC_EnableIRQ(IRQn_Type IRQn) {
    SET_BIT(NVIC->ISER[IRQn >> 5], IRQn);
}

void NVIC_DisableIRQ(IRQn_Type IRQn) {
    SET_BIT(NVIC->ICER[IRQn >> 5], IRQn);
}

void NVIC_SetPendingIRQ(IRQn_Type IRQn) {
    SET_BIT(NVIC->ISPR[IRQn >> 5], IRQn);
}

void NVIC_ClearPendingIRQ(IRQn_Type IRQn) {
    SET_BIT(NVIC->ICPR[IRQn >> 5], IRQn);
}

u32 NVIC_GetPendingIRQ(IRQn_Type IRQn) {
    return GET_BIT(NVIC->ISPR[IRQn >> 5], IRQn);
}

void NVIC_SetPriority(IRQn_Type IRQn, u32 priority) {
    NVIC->IPR[IRQn] = (priority & 0xFF);
}

u32 NVIC_GetPriority(IRQn_Type IRQn) {
    return NVIC->IPR[IRQn] & 0xFF;
}
