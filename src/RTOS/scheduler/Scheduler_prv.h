/*
 * Scheduler_prv.h
 *
 *  Created on: Aug 24, 2025
 *      Author: Koshok
 */

#ifndef RTOS_SCHEDULER_SCHEDULER_PRV_H_
#define RTOS_SCHEDULER_SCHEDULER_PRV_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
typedef enum{
	Running,
	Suspended,

}TaskState;
typedef struct{
	void (*Fptr)(void);
	u32 Periodicity;
	u32 FirstDealy;
	u8 Priority;

	TaskState State;

}Task;

#define PRiorty 0;
#define RESERVED 1;
#define NO_TASK_ERROR 2;

#endif /* RTOS_SCHEDULER_SCHEDULER_PRV_H_ */
