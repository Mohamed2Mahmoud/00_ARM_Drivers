#include "Includes_int.h"


volatile s8 counter = 0;

void IncrementBtn_Handler(void)
{
    counter++;
    if (counter > 9) counter = 0;
}

void DecrementBtn_Handler(void)
{
    counter--;
    if (counter < 0) counter = 9;
}

// ------------ MAIN ------------
int main(void)
{
    /* --- System Init --- */
    MRCC_vInit();
    MRCC_vEnableClk(RCC_AHB1, RCC_GPIOA);
    MRCC_vEnableClk(RCC_AHB1, RCC_GPIOB);

    Segment_Init_t SEG1 = {
        .Port = GPIO_PORTB,
        .PinNo = {PIN0, PIN1, PIN2, PIN5, PIN6, PIN7, PIN8, PIN9}
    };


    _7_Segment_Init(&SEG1);
        _7_Segment_Write(&SEG1, counter);


    GPIOx_PinConfig_t btn1 = {
        .port = GPIO_PORTA,
        .pin = PIN0,
        .mode = GPIO_MODE_INPUT,
        .outputType = GPIO_PUSHPULL,
        .speed = GPIO_LOW_SPEED,
        .pull = GPIO_PULLUP,
        .altFunc = 0
    };

    MGPIO_vPinInit(&btn1);

    GPIOx_PinConfig_t btn2 = {
        .port = GPIO_PORTA,
        .pin = PIN1,
        .mode = GPIO_MODE_INPUT,
        .outputType = GPIO_PUSHPULL,
        .speed = GPIO_LOW_SPEED,
        .pull = GPIO_PULLUP,
        .altFunc = 0
    };
    MGPIO_vPinInit(&btn2);

    MEXTI_vEnableINT(EXTI_LINE0, EXTI_FALLING_EDGE);
	MEXTI_vSetCallBack(IncrementBtn_Handler, EXTI_LINE0);
	MNVIC_vEnable_Peripheral_INT(6);

	MEXTI_vEnableINT(EXTI_LINE1, EXTI_FALLING_EDGE);
	MEXTI_vSetCallBack(DecrementBtn_Handler, EXTI_LINE1);
	MNVIC_vEnable_Peripheral_INT(7);


    while (1)
    {
    	_7_Segment_Write(&SEG1, counter);
    }
    return 0 ;
}
