/*
 * Delay_prg.c
 *
 *  Created on: Aug 18, 2025
 *      Author: drago
 */

#include "../../LIB/STD_TYPES.h"
#include "Delay_cfg.h"
#include "Delay_prv.h"
#include "Delay_int.h"

void DELAY_sec(u8 sec) {
        volatile unsigned int i = sec * SEC_DELAY_FACTOR;
        while (i--) { NOP(); }
}

void DELAY_ms(u8 ms) {
        volatile unsigned int i = ms * MS_DELAY_FACTOR;
        while (i--) { NOP(); }
}

void DELAY_us(u8 us) {
        volatile unsigned int i = us * US_DELAY_FACTOR;
        while (i--) { NOP(); }
}

