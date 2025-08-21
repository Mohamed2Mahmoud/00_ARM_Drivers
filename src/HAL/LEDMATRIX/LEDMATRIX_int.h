/*
 * LEDMATRIX_int.h
 *
 *  Created on: Aug 21, 2025
 *      Author: drago
 */

#ifndef HAL_LEDMATRIX_LEDMATRIX_INT_H_
#define HAL_LEDMATRIX_LEDMATRIX_INT_H_

#include "../../LIB/STD_TYPES.h"

/* ----------------- Configuration Struct ----------------- */
typedef struct
{
    u8 RowPort;             // Port ID for all row pins
    u8 RowPins[8];          // Pins for the 8 rows
    u8 ColPort;             // Port ID for all column pins
    u8 ColPins[8];          // Pins for the 8 columns
} LEDMATRIX_Config_t;

/* ----------------- Public Functions ----------------- */

/**
 * @brief Initialize LED Matrix
 *
 * @param cfg Pointer to LED matrix configuration struct
 */
void HLEDMATRIX_vInit(const LEDMATRIX_Config_t *cfg);

/**
 * @brief Display a frame on the LED matrix
 *
 * @param cfg          Pointer to configuration (can be NULL to use global cfg)
 * @param A_u8Frame    Frame data (8 bytes = 8 columns)
 * @param A_u8FrameDelay How many refresh cycles to repeat
 */
void HLEDMATRIX_vDisplayFrame(const LEDMATRIX_Config_t *cfg, u8 A_u8Frame[8], u8 A_u8FrameDelay);

/**
 * @brief Display a frame using global config
 *
 * @param A_u8Frame      Frame data (8 bytes = 8 columns)
 * @param A_u32FrameDelay Delay in cycles (max 255)
 */
void HLEDMATRIX_DisplayFrame(u8 A_u8Frame[], u32 A_u32FrameDelay);

#endif /* HAL_LEDMATRIX_LEDMATRIX_INT_H_ */
