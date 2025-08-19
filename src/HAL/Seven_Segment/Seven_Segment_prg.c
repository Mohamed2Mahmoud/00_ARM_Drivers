/*
 * Seven_Segment.c
 *
 *  Created on: Aug 18, 2025
 *      Author: drago
 */


#include "Seven_Segment_int.h"



u8 NumberConfig[] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

void _7_Segment_Init(Segment_Init_t* SEG){
    for(int i = 0; i < 8; i++){
        GPIOx_PinConfig_t SevenSegmentPins = {
            .port = SEG->Port,
            .pin = SEG->PinNo[i],
            .mode = GPIO_MODE_OUTPUT,
            .outputType = GPIO_PUSHPULL,
            .speed = GPIO_LOW_SPEED,
            .pull = GPIO_NOPULL,
            .altFunc = 0
        };
        MGPIO_vPinInit(&SevenSegmentPins);
    }
}

void _7_Segment_Write(Segment_Init_t* SEG, u8 value) {
    for(int i = 0; i < 8; i++ ){
        u8 pinState = (NumberConfig[value] >> i) & 0x01;
        MGPIO_vSetPinValue(SEG->Port, SEG->PinNo[i], pinState);
    }
}
