/*
 * Scheduler_prg.c
 *
 *  Created on: Aug 24, 2025
 *      Author: Koshok
 */
#include "Scheduler_int.h"
#include "Scheduler_cfg.h"
#include "Scheduler_prv.h"

Task Sys_Task[MAX_NO_TASKS] = { { 0 } };
u32 TimingTask[MAX_NO_TASKS];

static void OS_schedular(void);

void OS_vStart(void) {

}

void OS_schedular(void) {

	for (u8 i = 0; i < MAX_NO_TASKS; i++) {
		if (Sys_Task[i].State == Running) {
			if (TimingTask[i] == 0 || TimingTask > Sys_Task[i].Periodicity) {
				Sys_Task[i].Fptr();
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
	if (Priority >= 0 && Priority < MAX_NO_TASKS) {

		if (Sys_Task[Priority].Fptr == 0) {
			Sys_Task[Priority].Fptr = _xFptr;
			Sys_Task[Priority].Periodicity = A_32Periodicity;
			TimingTask[Priority] = A_32Periodicity;
			Sys_Task[Priority].State = Running;

		} else {
			Error_state = 1;
		}

	}
	return Error_state;

}

ERR_STATE OS_SuspendTask(u8 Priority) {
	u8 Error_state;
	if (Sys_Task[Priority].State == Running) {
		Sys_Task[Priority].State = Suspended;
	} else {
		Error_state = NO_TASK_ERROR
		;
	}
	return Error_state;
}

ERR_STATE OS_ResumeTask(u8 Priority) {
	u8 Error_state;
	if (Sys_Task[Priority].State == Suspended) {
		Sys_Task[Priority].State = Running;
	} else {
		Error_state = NO_TASK_ERROR
		;
	}
	return Error_state;
}

ERR_STATE OS_DeleteTask(u8 Priority) {
	u8 Error_state;
	if (Sys_Task[Priority].Fptr != 0) {
		Sys_Task[Priority] = (void ) { 0 };
	} else {
		Error_state = NO_TASK_ERROR
		;
	}
	return Error_state;
}

