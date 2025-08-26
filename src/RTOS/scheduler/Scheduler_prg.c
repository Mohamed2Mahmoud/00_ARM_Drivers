/*
 * Scheduler_prg.c

 *
 *  Created on: Aug 24, 2025
 *      Author: Koshok
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/SYSTICK/SYSTICK_int.h"

#include "Scheduler_int.h"
#include "Scheduler_cfg.h"
#include "Scheduler_prv.h"

Task Sys_Task[MAX_NO_TASKS] = { { 0 } };
u32 TimingTask[MAX_NO_TASKS];

static void OS_schedular(void);

void OS_vStart(void) {
	MSYSTICK_Config_t STK_cfg = { .InterruptEnable = INT_ENABLE, .CLK_SRC =
			CLK_SRC_AHB_8 };
	MSYSTICK_vInit(&STK_cfg);

	MSYSTICK_vSetInterval_Multi(TICKTIME, OS_schedular);

}

void OS_schedular(void) {

	for (u8 i = 0; i < MAX_NO_TASKS; i++) {
		if (Sys_Task[i].State == Running) {
			if (TimingTask[i] == 0 || TimingTask > Sys_Task[i].Periodicity) {
				Sys_Task[i].Fptr();
				TimingTask[i] = Sys_Task[i].Periodicity;

			} else {
				TimingTask[i]--;
			}

		} else {

		}
	}

}

ERR_STATE OS_CreateTask(void (*_xFptr)(void), u32 A_32Periodicity,
		u32 FirstDealy, u8 Priority) {

	u8 Error_state = 0;
	if ((Priority >= 0) && (Priority < MAX_NO_TASKS)) {

		if (Sys_Task[Priority].Fptr == 0) {
			Sys_Task[Priority].Fptr = _xFptr;
			Sys_Task[Priority].Periodicity = A_32Periodicity;
			TimingTask[Priority] = FirstDealy;
			Sys_Task[Priority].State = Running;

		} else {
			Error_state = RESERVED_PRIORITY_ERROR;
		}

	}
	else {
		Error_state = OUT_OF_RANGE_ERROR;
	}
	return Error_state;

}

ERR_STATE OS_SuspendTask(u8 Priority) {
	u8 Error_state;
	if (Sys_Task[Priority].State == Running) {
		Sys_Task[Priority].State = Suspended;
	} else {
		Error_state = NO_TASK_ERROR;
	}
	return Error_state;
}

ERR_STATE OS_ResumeTask(u8 Priority) {
	u8 Error_state;
	if (Sys_Task[Priority].State == Suspended) {
		Sys_Task[Priority].State = Running;
	} else {
		Error_state = NO_TASK_ERROR;
	}
	return Error_state;
}

ERR_STATE OS_DeleteTask(u8 Priority) {
	u8 Error_state;
	if (Sys_Task[Priority].Fptr != 0) {
		Sys_Task[Priority] = (Task){ 0 };
	} else {
		Error_state = NO_TASK_ERROR;
	}
	return Error_state;
}

