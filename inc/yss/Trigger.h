/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_TRIGGER_CLASS__H_
#define YSS_TRIGGER_CLASS__H_

#include "scheduler.h"
#include <yss/error.h>

/*
	This class is an abstract class that allows inherited child classes to operate as trigger.
	.
	A trigger is a feature that executes a specified trigger function once as a separate thread when the run() function is called. 
	When the run() function is first called, it has the highest priority, and if it loses the current CPU occupancy before returning, 
	it is allocated time using the standard round-robin method.
*/
class Trigger
{
public:
	/*	
		▣ It is a function called from within the system.
	*/
	Trigger(void);
	
	/*
		This is a function that normally does not perform any actions, but operates as a one-time thread function when the runTrigger() function is called.
		Pre-allocation work is required through the activateTrigger() function before calling the runTrigger() function.
	*/
	virtual void trigger(void) = 0;

	/*
		This is a function that assigns a trigger to the scheduler.
		.
		@ return : Returns errors that occurred during processing.
		.
		@ stackSize : Sets the stack size of the trigger to be created.
	*/
	error_t activateTrigger(uint32_t stackSize = 512);

	/*
		This function releases a trigger from the scheduler.
	*/
	void deactivateTriger(void);

	/*
		This is a trigger function that executes the trigger() function once.
	*/
	void runTrigger(void);

	/*
		Get the ID of the currently assigned trigger.
		.
		@ return : Returns the ID of the currently assigned trigger.
	*/
	triggerId_t getTriggerId(void);

private:
	triggerId_t mId;
};

#endif