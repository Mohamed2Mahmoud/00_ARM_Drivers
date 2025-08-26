/*
 * GPIO_int.h
 *
 * Created on: Aug 16, 2025
 * Author: Mohamed Ismail
 */

#ifndef MCAL_GPIO_INT_H_
#define MCAL_GPIO_INT_H_

#include "../../LIB/STD_TYPES.h"

typedef struct {
    u8 port;
    u8 pin;
    u8 mode;
    u8 outputType;
    u8 speed;
    u8 pull;
    u16 altFunc;
} GPIOx_PinConfig_t;

/* ------------------- Port IDs ------------------- */
#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2
#define GPIO_PORTD   3
#define GPIO_PORTE   4
#define GPIO_PORTH   7

/* ------------------- Pin IDs ------------------- */
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15

/* ------------------- Pin Modes ------------------- */
#define GPIO_MODE_INPUT          0b00
#define GPIO_MODE_OUTPUT         0b01
#define GPIO_MODE_ALTFUNC        0b10
#define GPIO_MODE_ANALOG         0b11

/* ------------------- Output Types ------------------- */
#define GPIO_PUSHPULL       0
#define GPIO_OPENDRAIN      1

/* ------------------- Output Speed ------------------- */
#define GPIO_LOW_SPEED      0b00
#define GPIO_MED_SPEED      0b01
#define GPIO_HIGH_SPEED     0b10
#define GPIO_VHIGH_SPEED    0b11

/* ------------------- Pull-up / Pull-down ------------------- */
#define GPIO_NOPULL         0b00
#define GPIO_PULLUP         0b01
#define GPIO_PULLDOWN       0b10

/* ------------------- Pin Values ------------------- */
#define GPIO_LOW            0
#define GPIO_HIGH           1

/* ------------------- Functions Prototypes ------------------- */
void MGPIO_vSetPinMode(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8Mode);
void MGPIO_vSetPinOutputType(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8OutputType);
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8Speed);
void MGPIO_vSetPinPull(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PullType);
void MGPIO_vSetPinValue(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8Value);
u8   MGPIO_u8GetPinValue(u8 A_u8PortId, u8 A_u8PinNo);
void   MGPIO_vTogPinValue(u8 A_u8PortId, u8 A_u8PinNo);
void MGPIO_vSetAlt(u8 A_u8PortID, u8 A_u8PinNum, u16 A_u16AFx);
void MGPIO_vPinInit(GPIOx_PinConfig_t* A_xPinCfg);

#endif /* MCAL_GPIO_INT_H_ */
