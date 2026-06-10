/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
 
/**
 * @file Thread.h
 * @brief Thread base class for scheduler-managed thread objects.
 */

#ifndef YSS_THREAD_CLASS__H_
#define YSS_THREAD_CLASS__H_

#include "scheduler.h"
#include <yss/error.h>

/**
 * @brief Abstract base class for a scheduler-managed thread.
 *
 * Classes that inherit from Thread must implement the thread() method.
 * The scheduler executes thread() after runThread() is called and stops it when
 * stopThread() is called.
 */
class Thread
{
public:
	/**
	 * @brief Construct a new Thread object.
	 */
	Thread(void);

	/**
	 * @brief Destroy the Thread object.
	 */
	~Thread(void);

	/**
	 * @brief Main thread entry point for derived classes.
	 *
	 * This method is executed by the scheduler when the thread is started.
	 * Derived classes must override this method to implement thread behavior.
	 */
	virtual void thread(void) = 0;

	/**
	 * @brief Start the thread and register it with the scheduler.
	 *
	 * @param stackSize Stack size to allocate for the thread, in bytes.
	 * @return error_t Returns an error code if thread creation fails.
	 */
	error_t runThread(uint32_t stackSize = 512);

	/**
	 * @brief Stop the thread and remove it from the scheduler.
	 */
	void stopThread(void);

private:
	threadId_t mId;
};

#endif