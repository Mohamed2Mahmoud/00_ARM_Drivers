
/*
 * main.c
 * Test LED Matrix (8x8) using 2 chained 74HC595 chips
 * Author: Mohamed Ismail
 */
#include "Includes_int.h"

u8 Letter_M[8] = {
    0b10000001,
    0b11000011,
    0b10100101,
    0b10011001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001
};

u8 Heart[8] = {
    0b00000000,
    0b01100110,
    0b11111111,
    0b11111111,
    0b11111111,
    0b01111110,
    0b00111100,
    0b00011000
};

/**int main(void)
{
	MRCC_vInit();
		MRCC_vEnableClk(RCC_AHB1, GPIO_PORTA);

    LEDMATRIX_vInit();

    while (1)
    {
        LEDMATRIX_vDisplayFrame(Letter_M, 100);
    }
}**/



/*
#include "sound.h"
void DAC_Handler(void);
DAC_Config_t DAC = { .Port = GPIO_PORTA, .pin = { PIN0, PIN1, PIN2, PIN3, PIN4,
		PIN5, PIN6, PIN7 } };

int main(void) {
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1, GPIO_PORTA);

	HDAC_vInit(&DAC);
	MSYSTICK_vSetInterval_Multi(391, DAC_Handler);

	while (1) {

	}

}

void DAC_Handler (void)
{

	static u32 iterator = 0;
	HDAC_vSend(&DAC,new_raw, iterator);

	if (iterator < new_raw_len)
	{
		iterator++;
	}else
	{
		iterator = 0;
	}

}*/

