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
	 * @brief Construct a new Thread object with an inactive thread ID.
	 *
	 * @details Initializes mId to 0 (invalid / not yet registered) so that
	 *          runThread() knows the thread has not yet been added to the scheduler.
	 */
	Thread(void);

	/**
	 * @brief Destroy the Thread object and stop the associated scheduler thread.
	 *
	 * @details Calls stopThread() to ensure that the scheduler slot is freed and the
	 *          thread's stack memory is released before the object is destroyed.
	 *          Safe to call even if the thread was never started (mId == 0).
	 */
	~Thread(void);

	/**
	 * @brief Main thread entry point for derived classes.
	 *
	 * @details This method is executed repeatedly by the internal adapter loop as long
	 *          as the thread is running.  Derived classes must override this method to
	 *          implement thread behavior.  A single pass through the method body is
	 *          sufficient; there is no need to add an infinite loop inside thread().
	 */
	virtual void thread(void) = 0;

	/**
	 * @brief Start the thread and register it with the scheduler.
	 *
	 * @details Registers the thread with the scheduler via thread::add(), passing an
	 *          internal adapter function and @c this as the argument.  If the thread is
	 *          already running (mId != 0), the registration is skipped to prevent
	 *          duplicate scheduler entries.
	 *
	 *          On success the scheduler assigns a slot index to mId.  A slot index of
	 *          zero or negative indicates that no slot was available or stack allocation
	 *          failed, in which case FAILED_THREAD_ADDING is returned.
	 *
	 * @param stackSize Stack size to allocate for the thread, in bytes.
	 * @return error_t Returns ERROR_NONE on success, or FAILED_THREAD_ADDING on failure.
	 */
	error_t runThread(uint32_t stackSize = 512);

	/**
	 * @brief Stop the thread and remove it from the scheduler.
	 *
	 * @details Calls thread::remove() to free the scheduler slot and release the
	 *          thread's stack memory.  Resets mId to 0 after removal so that
	 *          runThread() can re-start the thread later if needed.
	 *          Has no effect if the thread was never started (mId == 0).
	 */
	void stopThread(void);

private:
	threadId_t mId;
};

#endif