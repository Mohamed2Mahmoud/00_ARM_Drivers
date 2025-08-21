/*
 * Seven_Segment.c
 *
 *  Created on: Aug 18, 2025
 *      Author: drago
 */


#include "Seven_Segment_int.h"



u16 NumberConfig[] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b01110111, // A
    0b01111100, // b
    0b00111001, // C
    0b01011110, // d
    0b01111001, // E
    0b01110001  // F
};


void _7_Segment_Init(Segment_Init_t* SEG){
    for(int i = 0; i < 8 ; i++){
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






void DisplayHexNumber(u8 hexValue, Segment_Init_t *LCD1, Segment_Init_t *LCD2) {
    u8 highNibble = (hexValue >> 4) & 0x0F;
    u8 lowNibble  = hexValue & 0x0F;

    _7_Segment_Write(LCD1, highNibble);
    _7_Segment_Write(LCD2, lowNibble);
}

void _7_Segment_Write(Segment_Init_t* SEG, u16 value) {
    for(int i = 0; i < 8; i++ ){
        u16 pinState = (NumberConfig[value] >> i) & 0x01;
        MGPIO_vSetPinValue(SEG->Port, SEG->PinNo[i], pinState);
    }
}
