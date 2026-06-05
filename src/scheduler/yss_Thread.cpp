/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
 
#include <yss/Thread.h>

/**
 * @brief Thread entry function used by the scheduler.
 *
 * This function is called by the scheduler to execute the thread loop.
 * It repeatedly invokes the virtual thread() method of the Thread object.
 *
 * @param var Pointer to the Thread object.
 */
static void thread_thread(void *var)
{
	Thread *obj = (Thread*)var;

	while (true)
		obj->thread();
}

/**
 * @brief Construct a new Thread object.
 */
Thread::Thread(void)
{
	mId = 0;
}

/**
 * @brief Destroy the Thread object.
 *
 * The thread is stopped and removed from the scheduler if it is still running.
 */
Thread::~Thread(void)
{
	stopThread();
}

/**
 * @brief Start the thread and add it to the scheduler.
 *
 * If the thread is not already running, this method requests a new scheduler
 * thread and stores the returned thread ID.
 *
 * @param stackSize Stack size allocated for the thread, in bytes.
 * @return error_t Returns ERROR_NONE on success or FAILED_THREAD_ADDING on failure.
 */
error_t Thread::runThread(uint32_t stackSize)
{
	if (mId == 0)
		mId = thread::add(thread_thread, this, stackSize);

	if (mId <= 0)
		return error_t::FAILED_THREAD_ADDING;
	else
		return error_t::ERROR_NONE;
}

/**
 * @brief Stop the running thread and remove it from the scheduler.
 */
void Thread::stopThread(void)
{
	if (mId)
	{
		thread::remove(mId);
		mId = 0;
	}
}

