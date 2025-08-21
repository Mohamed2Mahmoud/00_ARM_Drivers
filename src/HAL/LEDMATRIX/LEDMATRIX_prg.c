/*
 * LEDMATRIX_prg.c
 *
 *  Created on: Aug 21, 2025
 *      Author: drago
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"
#include "../LEDMATRIX/LEDMATRIX_cfg.h"
#include "../LEDMATRIX/LEDMATRIX_int.h"

static const LEDMATRIX_Config_t *g_cfg = NULL;

static void HLEDMATRIX_vEnableCurrentCol(u8 colNo);
static void HLEDMATRIX_vDisableAllCol(void);
static void HLEDMATRIX_SetRowValue(u8 rowValue);

static void prv_init_output_pin(u8 port, u8 pin)
{
    GPIOx_PinConfig_t p = {
        .port       = port,
        .pin        = pin,
        .mode       = GPIO_MODE_OUTPUT,
        .outputType = GPIO_PUSHPULL,
        .speed      = GPIO_LOW_SPEED,
        .pull       = GPIO_NOPULL,
        .altFunc    = 0
    };
    MGPIO_vPinInit(&p);
}

void HLEDMATRIX_vInit(const LEDMATRIX_Config_t *cfg)
{
    if (cfg == NULL) return;
    g_cfg = cfg;

    // Initialize Rows (active HIGH)
    for (u8 i = 0; i < NO_ROWS; i++)
    {
        prv_init_output_pin(g_cfg->RowPort, g_cfg->RowPins[i]);
        MGPIO_vSetPinValue(g_cfg->RowPort, g_cfg->RowPins[i], GPIO_LOW);
    }

    // Initialize Cols (active LOW)
    for (u8 i = 0; i < NO_COLS; i++)
    {
        prv_init_output_pin(g_cfg->ColPort, g_cfg->ColPins[i]);
        MGPIO_vSetPinValue(g_cfg->ColPort, g_cfg->ColPins[i], GPIO_HIGH);
    }

    MSYSTICK_Config_t STK_cfg = { .InterruptEnable = INT_DISABLE, .CLK_SRC = CLK_SRC_AHB_8 };
    MSYSTICK_vInit(&STK_cfg);
}

void HLEDMATRIX_vDisplayFrame(const LEDMATRIX_Config_t *cfg, u8 A_u8Frame[8], u8 A_u8FrameDelay)
{
    const LEDMATRIX_Config_t *use = (cfg != NULL) ? cfg : g_cfg;
    if (use == NULL) return;

    g_cfg = use;

    for (u8 repeat = 0; repeat < A_u8FrameDelay; repeat++)
    {
        for (u8 col = 0; col < NO_COLS; col++)
        {
            HLEDMATRIX_SetRowValue(A_u8Frame[col]);

            HLEDMATRIX_vEnableCurrentCol(col);

            MSYSTICK_vSetDelay_ms(SCAN_TIME);

            HLEDMATRIX_vDisableAllCol();
        }
    }
}

void HLEDMATRIX_DisplayFrame(u8 A_u8Frame[], u32 A_u32FrameDelay)
{
    if (g_cfg == NULL) return;
    u8 repeats = (A_u32FrameDelay > 255u) ? 255u : (u8)A_u32FrameDelay;
    HLEDMATRIX_vDisplayFrame(g_cfg, A_u8Frame, repeats);
}

static void HLEDMATRIX_vEnableCurrentCol(u8 colNo)
{
    if (g_cfg == NULL) return;
    // Active LOW  enable col by driving LOW
    MGPIO_vSetPinValue(g_cfg->ColPort, g_cfg->ColPins[colNo], GPIO_LOW);
}

static void HLEDMATRIX_vDisableAllCol(void)
{
    if (g_cfg == NULL) return;
    // Disable all cols by driving HIGH
    for (u8 i = 0; i < NO_COLS; i++)
        MGPIO_vSetPinValue(g_cfg->ColPort, g_cfg->ColPins[i], GPIO_HIGH);
}

static void HLEDMATRIX_SetRowValue(u8 rowValue)
{
    if (g_cfg == NULL) return;
    // Active HIGH  row=1 lights LED
    for (u8 i = 0; i < NO_ROWS; i++)
    {
        u8 bit = GET_BIT(rowValue, i);
        MGPIO_vSetPinValue(g_cfg->RowPort, g_cfg->RowPins[i], bit ? GPIO_HIGH : GPIO_LOW);
    }
}

