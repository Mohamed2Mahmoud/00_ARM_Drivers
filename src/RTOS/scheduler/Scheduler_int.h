/*
 * Scheduler_int.h
 *
 *  Created on: Aug 24, 2025
 *      Author: Koshok
 */

#ifndef RTOS_SCHEDULER_SCHEDULER_INT_H_
#define RTOS_SCHEDULER_SCHEDULER_INT_H_

typedef u8 ERR_STATE;

void OS_vStart(void);
ERR_STATE OS_CreateTask(void (*Fptr)(void),u32 Periodicity,u32 FirstDealy,u8 Priority);
ERR_STATE OS_SuspendTask(u8 Priority);
ERR_STATE OS_ResumeTask(u8 Priority);
ERR_STATE OS_DeleteTask(u8 Priority);





#endif /* RTOS_SCHEDULER_SCHEDULER_INT_H_ */
