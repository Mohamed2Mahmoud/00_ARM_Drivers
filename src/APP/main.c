#include "Includes_int.h"

int main(void)
{
    /* ------------------- System Init ------------------- */
    MRCC_vInit();
    MRCC_vEnableClk(RCC_AHB1, RCC_GPIOA);

    /* ------------------- LED Pins ------------------- */
    GPIOx_PinConfig_t ledPins[3] = {
        {GPIO_PORTA, PIN0, GPIO_MODE_OUTPUT, GPIO_PUSHPULL, GPIO_LOW_SPEED, GPIO_NOPULL, 0},
        {GPIO_PORTA, PIN1, GPIO_MODE_OUTPUT, GPIO_PUSHPULL, GPIO_LOW_SPEED, GPIO_NOPULL, 0},
        {GPIO_PORTA, PIN2, GPIO_MODE_OUTPUT, GPIO_PUSHPULL, GPIO_LOW_SPEED, GPIO_NOPULL, 0}
    };

    for (u8 i = 0; i < 3; i++) {
        MGPIO_vPinInit(&ledPins[i]);
    }

    /* ------------------- Button Pins ------------------- */
    BTN_Init_t buttons[3] = {
        {GPIO_PORTA, PIN3, GPIO_PULLDOWN},
        {GPIO_PORTA, PIN4, GPIO_PULLDOWN},
        {GPIO_PORTA, PIN5, GPIO_PULLDOWN}
    };

    for (u8 i = 0; i < 3; i++) {
        BTN_Init(&buttons[i]);
    }

    /* ------------------- Button Flags ------------------- */
    u8 btnFlags[3] = {0, 0, 0};

    /* ------------------- Main Loop ------------------- */
    while (1)
    {
        if (BTN_State(&buttons[0]) == 1) {
            btnFlags[0] ^= 1;
            DELAY_ms(200);
        }
        else if (BTN_State(&buttons[1]) == 1) {
            btnFlags[1] ^= 1;
            DELAY_ms(200);
        }
        else if (BTN_State(&buttons[2]) == 1) {
            btnFlags[2] ^= 1;
            DELAY_ms(200);
        }
        for (u8 i = 0; i < 3; i++) {
            MGPIO_vSetPinValue(GPIO_PORTA, ledPins[i].pin, btnFlags[i] ? GPIO_HIGH : GPIO_LOW);
        }

        /* Example for RGB usage */
        /*
        RGB_Color(&rgbConfig, GPIO_HIGH, GPIO_LOW, GPIO_LOW);
        DelayMs(500);
        RGB_Color(&rgbConfig, GPIO_LOW, GPIO_HIGH, GPIO_HIGH);
        DelayMs(500);
        */
    }

    return 0;
}
