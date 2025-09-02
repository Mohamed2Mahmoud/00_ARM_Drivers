#include "Includes_int.h"





int main(void){
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1,RCC_GPIOA);
	MRCC_vEnableClk(RCC_APB2,12);

	GPIOx_PinConfig_t MISO = {
			.port = GPIO_PORTA,
			.pin = PIN6,
			.mode = GPIO_MODE_ALTFUNC,
			.altFunc = GPIO_AF5_SPI1_SPI2
	};

	GPIOx_PinConfig_t MOSI = {
			.port = GPIO_PORTA,
			.pin = PIN7,
			.mode = GPIO_MODE_ALTFUNC,
			.altFunc = GPIO_AF5_SPI1_SPI2
	};
	GPIOx_PinConfig_t SCK = {
			.port = GPIO_PORTA,
			.pin = PIN5,
			.mode = GPIO_MODE_ALTFUNC,
			.altFunc = GPIO_AF5_SPI1_SPI2
	};

	GPIOx_PinConfig_t led = {
			.port = GPIO_PORTA,
			.pin = PIN1,
			.mode = GPIO_MODE_OUTPUT,
			.speed = GPIO_LOW_SPEED,
			.outputType = GPIO_PUSHPULL,
			.pull = GPIO_PULLDOWN
	};

	MSPI_Config_t SPI1x = {
			.SPIx = SPI1
	};


	MSPI_vInit(&SPI1x);

	MGPIO_vPinInit(&MISO);
	MGPIO_vPinInit(&MOSI);
	MGPIO_vPinInit(&SCK);
	MGPIO_vPinInit(&led);




	u16 data = 0;

	data = MSPI_u8Transceive(&SPI1x, 'n');
	if(data ==	'n'){
		MGPIO_vSetPinValue(GPIO_PORTA,PIN1,1);
	}



	while(1){

	}
  return 0;
}


/*
volatile u8 currentNum = 0;

Segment_Init_t SEG1 = {
    .Port = GPIO_PORTA,
    .PinNo = {1,2,3,4,5,6,7,8}   // Example pins, adjust to your wiring
};

Segment_Init_t SEG2 = {
    .Port = GPIO_PORTB,
    .PinNo = {0,1,2,3,4,5,6,7}   // Example pins, adjust to your wiring
};

static void onIrCode(u8 code)
{
    switch(code)
    {
        case IR_CODE_0: currentNum = 0; break;
        case IR_CODE_1: currentNum = 1; break;
        case IR_CODE_2: currentNum = 2; break;
        case IR_CODE_3: currentNum = 3; break;
        case IR_CODE_4: currentNum = 4; break;
        case IR_CODE_5: currentNum = 5; break;
        case IR_CODE_6: currentNum = 6; break;
        case IR_CODE_7: currentNum = 7; break;
        case IR_CODE_8: currentNum = 8; break;
        case IR_CODE_9: currentNum = 9; break;

        case IR_CODE_PLUS:
            currentNum = (currentNum + 1) % 10;
            break;

        case IR_CODE_MINUS:
            currentNum = (currentNum == 0) ? 9 : currentNum - 1;
            break;
    }

    _7_Segment_Write(&SEG1, currentNum);
}

int main(void)
{
    MRCC_vInit();
    MRCC_vEnableClk(RCC_AHB1, GPIO_PORTA);
    MRCC_vEnableClk(RCC_AHB1, GPIO_PORTB);
    MRCC_vEnableClk(RCC_APB2, 14);


    _7_Segment_Init(&SEG1);
    _7_Segment_Init(&SEG2);

    MSYSTICK_Config_t stk = {.InterruptEnable = INT_ENABLE, .CLK_SRC = CLK_SRC_AHB_8};
    MSYSTICK_vInit(&stk);

    IR_Init(onIrCode);

    _7_Segment_Write(&SEG1, currentNum);

    while(1) { }
}


*/




