/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <util/FunctionQueue.h>
#include <std_ext/malloc.h>

FunctionQueue::FunctionQueue(uint16_t depth, int32_t  stackSize)
{
	mTaskMaxSize = depth;
	lockHmalloc();
	mTaskFunc = (error_t (**)(FunctionQueue *, void*))hmalloc(4 * depth);
	mVariable = (void **)hmalloc(4 * depth);
	unlockHmalloc();
	mThreadId = 0;
	mTaskHead = mTaskTail = 0;
	mBusyFlag = false;
	mProcessingFlag = false;
	mStackSize = stackSize;
	mCallbackErrorHandler = 0;
}

FunctionQueue::~FunctionQueue(void)
{
	hfree(mTaskFunc);
	hfree(mVariable);
}

void FunctionQueue::add(error_t (*func)(FunctionQueue *, void *), void *var)
{
	mMutex.lock();
	mTaskFunc[mTaskHead] = (error_t (*)(FunctionQueue *, void * ))func;
	mVariable[mTaskHead] = var;
	mTaskHead++;
	if (mTaskHead >= mTaskMaxSize)
		mTaskHead = 0;
	mBusyFlag = true;
	mMutex.unlock();
}

void FunctionQueue::add(error_t (*func)(FunctionQueue *))
{
	mMutex.lock();
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
	mTaskFunc[mTaskHead] = (error_t (*)(FunctionQueue *, void *))func;
#pragma GCC diagnostic pop
	mVariable[mTaskHead] = 0;
	mTaskHead++;
	if (mTaskHead >= mTaskMaxSize)
		mTaskHead = 0;
	mBusyFlag = true;
	mMutex.unlock();
}

bool FunctionQueue::isComplete(void)
{
	bool rt;
	mMutex.lock();
	rt = !mBusyFlag;
	mMutex.unlock();
	return rt;
}

error_t FunctionQueue::task(void)
{
	uint32_t tail;

	if (mTaskTail != mTaskHead)
	{
		mMutex.lock();
		tail = mTaskTail;
		mProcessingFlag = true;
		mMutex.unlock();
		mError = mTaskFunc[tail](this, mVariable[tail]);
		mMutex.lock();
		mProcessingFlag = false;
		mTaskTail++;
		if (mTaskTail >= mTaskMaxSize)
			mTaskTail = 0;
		mMutex.unlock();
	}
	else
	{
		mMutex.lock();
		mBusyFlag = false;
		mMutex.unlock();
	}

	return mError;
}

void thread_run(FunctionQueue *task)
{
	error_t result = error_t::ERROR_NONE;

	while (1)
	{
		if (task->isComplete())
		{
			thread::yield();
		}
		else
		{
			result = task->task();
		}

		if (result != error_t::ERROR_NONE)
		{
			task->clear();
			task->callErrorHandler(result);
			result = error_t::ERROR_NONE;
		}
	}
}

error_t FunctionQueue::start(void)
{
	error_t result = error_t::ERROR_NONE;

	mMutex.lock();
	mError = error_t::ERROR_NONE;
	if (mThreadId == 0)
		mThreadId = thread::add((void (*)(void *))thread_run, this, mStackSize);
	if(mThreadId < 0)
		result = error_t::FAILED_THREAD_ADDING;
	mMutex.unlock();

	return result;
}

void FunctionQueue::stop(void)
{
	mMutex.lock();
	if (mThreadId)
	{
		thread::remove(mThreadId);
		mThreadId = 0;
	}
	
	mTaskTail = mTaskHead = 0;

	mMutex.unlock();
}

void FunctionQueue::clear(void)
{
	mMutex.lock();

	if(mProcessingFlag)
	{
		mTaskTail = 0;
		mTaskHead = 1;
	}
	else
		mTaskTail = mTaskHead = 0;

	mMutex.unlock();
}

void FunctionQueue::setCallbackErrorHandler(void (*callback)(FunctionQueue *fq, error_t errorCode))
{
	mCallbackErrorHandler = callback;
}

void FunctionQueue::callErrorHandler(error_t errorCode)
{
	if(mCallbackErrorHandler)
		mCallbackErrorHandler(this, errorCode);
}

