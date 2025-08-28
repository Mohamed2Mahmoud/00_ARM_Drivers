// ../APP/main.c



#include "Includes_int.h"
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

}

