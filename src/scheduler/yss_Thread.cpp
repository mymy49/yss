/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
 
#include <yss/Thread.h>

/// @brief Internal scheduler thread function that drives the Thread object's main loop.
/// @details This static adapter bridges the scheduler's C-style callback interface to the
///          C++ virtual method dispatch of the Thread class.  It is passed to thread::add()
///          as the entry function with @p var set to the owning Thread object.
///
///          The function loops indefinitely, calling the derived class's thread() method on
///          each iteration.  This means the virtual thread() implementation does not need to
///          contain its own infinite loop; a single pass through the method body is sufficient.
///          The loop terminates only when thread::remove() frees the scheduler slot from the
///          outside, or when the Thread destructor calls stopThread().
///
/// @param var Pointer to the owning Thread object, cast to void* by the caller.
static void thread_thread(void *var)
{
	Thread *obj = (Thread*)var;

	// Repeatedly invoke the derived class thread() to keep the thread alive.
	while (true)
		obj->thread();
}

Thread::Thread(void)
{
	mId = 0;
}

Thread::~Thread(void)
{
	stopThread();
}

error_t Thread::runThread(uint32_t stackSize)
{
	// Skip registration if the thread is already running.
	if (mId == 0)
		mId = thread::add(thread_thread, this, stackSize);

	// A non-positive ID means that either no free slot exists or stack allocation failed.
	if (mId <= 0)
		return error_t::FAILED_THREAD_ADDING;
	else
		return error_t::ERROR_NONE;
}

void Thread::stopThread(void)
{
	// Only attempt removal if the thread is currently registered with the scheduler.
	if (mId)
	{
		thread::remove(mId);
		mId = 0;  // Invalidate the stored ID to mark the thread as stopped.
	}
}

