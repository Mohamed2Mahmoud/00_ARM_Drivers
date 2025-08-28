/*
 * S2P_prg.c
 *
 *  Created on: Aug 28, 2025
 *      Author: Koshok
 */

#include "S2P_cfg.h"
#include "S2P_int.h"
#include "S2P_prv.h"




void S2P_vInit(S2P_Config_t* S2P_cfg){
	GPIOx_PinConfig_t Data_Pin = {
		        .port = S2P_cfg->DataPort,
		        .pin =	S2P_cfg->DataPin,
		        .mode = GPIO_MODE_OUTPUT,
		        .outputType = GPIO_PUSHPULL,
		        .speed = GPIO_LOW_SPEED,
		        .pull = GPIO_NOPULL,
		        .altFunc = 0
		    };
	MGPIO_vPinInit(&Data_Pin);
	GPIOx_PinConfig_t Shift_Pin = {
					.port = S2P_cfg->ShiftCLKPort,
					.pin =	S2P_cfg->ShiftCLKPin,
					.mode = GPIO_MODE_OUTPUT,
					.outputType = GPIO_PUSHPULL,
					.speed = GPIO_LOW_SPEED,
					.pull = GPIO_NOPULL,
					.altFunc = 0
				};
	MGPIO_vPinInit(&Shift_Pin);
	GPIOx_PinConfig_t Latch_Pin = {
					.port = S2P_cfg->LatchCLKPort,
					.pin =	S2P_cfg->LatchCLKPin,
					.mode = GPIO_MODE_OUTPUT,
					.outputType = GPIO_PUSHPULL,
					.speed = GPIO_LOW_SPEED,
					.pull = GPIO_NOPULL,
					.altFunc = 0
				};
	MGPIO_vPinInit(&Latch_Pin);





}
void S2P_ShiftData(S2P_Config_t* S2P_cfg,u32 A_u32Byte){

	MGPIO_vSetPinValue(S2P_cfg->ShiftCLKPort,S2P_cfg->ShiftCLKPin,GPIO_HIGH);
	MSYSTICK_vSetDelay_ms(1);
	MGPIO_vSetPinValue(S2P_cfg->ShiftCLKPort,S2P_cfg->ShiftCLKPin,GPIO_LOW);

}
void S2P_LatchData(S2P_Config_t* S2P_cfg,u32 A_u32Byte){

	MGPIO_vSetPinValue(S2P_cfg->LatchCLKPort,S2P_cfg->LatchCLKPin,GPIO_HIGH);
	MSYSTICK_vSetDelay_ms(1);
	MGPIO_vSetPinValue(S2P_cfg->LatchCLKPort,S2P_cfg->LatchCLKPin,GPIO_LOW);

}

void S2P_SendData(S2P_Config_t* S2P_cfg,u32 A_u32Byte){


}
