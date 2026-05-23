/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_THREAD_CLASS__H_
#define YSS_THREAD_CLASS__H_

#include "scheduler.h"
#include <yss/error.h>

/*
	This class is an abstract class that allows inherited child classes to operate as thread.
*/
class Thread
{
public:
	/*	
		▣ It is a function called from within the system.
	*/
	Thread(void);

	/*	
		▣ It is a function called from within the system.
	*/
	~Thread(void);

	/*
		This is a function that runs as a thread.
		.
		It runs when the runThread() function is called, and stops running when the stopThread() function is called.
	*/
	virtual void thread(void) = 0;

	/*
		This is a function that assigns a thread to the scheduler.
		.
		@ return : Returns errors that occurred during processing.
		.
		@ stackSize : Sets the stack size of the thread to be allocated.
	*/
	error_t runThread(uint32_t stackSize = 512);

	/*
		This function releases a thread from the scheduler.
	*/
	void stopThread(void);

private:
	threadId_t mId;
};

#endif