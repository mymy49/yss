/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
 
 #include <yss/Thread.h>

static void thread_thread(void *var)
{
	Thread *obj = (Thread*)var;

	while(true)
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

error_t  Thread::runThread(uint32_t stackSize)
{
	if(mId == 0)
		mId = thread::add(thread_thread, this, stackSize);
	
	if(mId <= 0)
		return error_t::FAILED_THREAD_ADDING;
	else
		return error_t::ERROR_NONE;
}

void Thread::stopThread(void)
{
	if(mId)
	{
		thread::remove(mId);
		mId = 0;
	}
}

