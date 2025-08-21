/*
 * LEDMATRIX_cfg.c
 *
 *  Created on: Aug 21, 2025
 *      Author: drago
 */

#include "LEDMATRIX_cfg.h"
#include "LEDMATRIX_int.h"
#include "../../MCAL/GPIO/GPIO_int.h"

/* Example: Rows on PORTA, Cols on PORTB */
const LEDMATRIX_Config_t LEDMATRIX_cfg = {
    .RowPort = GPIO_PORTA,
    .RowPins = {PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7},

    .ColPort = GPIO_PORTB,
    .ColPins = {PIN0, PIN1, PIN2, PIN5, PIN6, PIN7, PIN8, PIN9}
};
