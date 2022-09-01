////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <util/FunctionQueue.h>
#include <yss/malloc.h>

FunctionQueue::FunctionQueue(unsigned short depth, int stackSize)
{
	mTaskMaxSize = depth;
	lockHmalloc();
	mTaskFunc = (int (**)(FunctionQueue *, int))hmalloc(4 * depth);
	mFactor = (int *)hmalloc(depth);
	unlockHmalloc();
	mDelayTime = 0;
	mThreadId = 0;
	mTaskHead = mTaskTail = 0;
	mBusyFlag = false;
	mProcessingFlag = false;
	mStackSize = stackSize;
}

FunctionQueue::~FunctionQueue(void)
{
	hfree(mTaskFunc);
	hfree(mFactor);
}


void FunctionQueue::add(int (*func)(FunctionQueue *, int), int factor)
{
	mMutex.lock();
	mTaskFunc[mTaskHead] = (int (*)(FunctionQueue *, int))func;
	mFactor[mTaskHead] = factor;
	mTaskHead++;
	if (mTaskHead >= mTaskMaxSize)
		mTaskHead = 0;
	mBusyFlag = true;
	mMutex.unlock();
}

void FunctionQueue::add(signed int (*func)(FunctionQueue *), signed int factor)
{
	mMutex.lock();
	mTaskFunc[mTaskHead] = (signed int (*)(FunctionQueue *, signed int))func;
	mFactor[mTaskHead] = factor;
	mTaskHead++;
	if (mTaskHead >= mTaskMaxSize)
		mTaskHead = 0;
	mBusyFlag = true;
	mMutex.unlock();
}

void FunctionQueue::setStatus(int status)
{
	mStatus = status;
}

int FunctionQueue::getStatus(void)
{
	return mStatus;
}

void FunctionQueue::setError(int error)
{
	mError = error;
}

int FunctionQueue::getError(void)
{
	return mError;
}

void FunctionQueue::setDelayTime(int time)
{
	mDelayTime = time;
}

bool FunctionQueue::isComplete(void)
{
	bool rt;
	mMutex.lock();
	rt = !mBusyFlag;
	mMutex.unlock();
	return rt;
}

error FunctionQueue::task(void)
{
	unsigned int tail;

	if (mTaskTail != mTaskHead)
	{
		if (mDelayTime)
		{
			thread::delay(mDelayTime);
			mDelayTime = 0;
		}

		mMutex.lock();
		tail = mTaskTail;
		mProcessingFlag = true;
		mMutex.unlock();
		mError = mTaskFunc[tail](this, mFactor[tail]);
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

void FunctionQueue::setThreadId(int id)
{
	mThreadId = id;
}

void thread_run(FunctionQueue *task)
{
	int result = Error::NONE;
	task->setError(Error::NONE);
	task->setStatus(STATUS_CODE::READY);

	while (1)
	{
		if (task->isComplete())
		{
			task->setStatus(STATUS_CODE::READY);
			thread::yield();
		}
		else
		{
			result = task->task();
		}

		if (result != Error::NONE)
		{
			task->clear();
		}
	}
}

void FunctionQueue::start(void)
{
	mMutex.lock();
	if (mThreadId == 0)
		mThreadId = thread::add((void (*)(void *))thread_run, this, mStackSize);
	mMutex.unlock();
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
	mTaskTail = mTaskHead = 0;
	mMutex.unlock();
}

void FunctionQueue::lock(void)
{
	mExternalMutex.lock();
}

void FunctionQueue::unlock(void)
{
	mExternalMutex.unlock();
}

