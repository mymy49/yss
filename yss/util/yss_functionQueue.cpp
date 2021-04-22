////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>

#include <util/fq.h>
#include <yss/malloc.h>
#include <config.h>

FunctionQueue::FunctionQueue(unsigned short depth, int stackSize)
{
	mTaskMaxSize = depth;
#if YSS_L_HEAP_USE
	mTaskFunc = (int (**)(FunctionQueue*, int))lmalloc(4*depth);
	mFactor = (int*)lmalloc(depth);
#elif YSS_C_HEAP_USE
	mTaskFunc = (int (**)(FunctionQueue*, int))cmalloc(4*depth);
	mFactor = (int*)cmalloc(depth);
#else
	mTaskFunc = (int (**)(FunctionQueue*, int))hmalloc(4*depth);
	mFactor = (int*)hmalloc(depth);
#endif
	mDelayTime = 0;
	mThreadId = 0;
	mTaskHead = mTaskTail = 0;
	mBusyFlag = false;
	mProcessingFlag = false;
	mStackSize = stackSize;
}

void FunctionQueue::add(int (*func)(FunctionQueue*, int), int factor)
{
	mMutex.lock();
	mTaskFunc[mTaskHead] = (int (*)(FunctionQueue*, int))func;
	mFactor[mTaskHead] = factor;
	mTaskHead++;
	if(mTaskHead >= mTaskMaxSize)
		mTaskHead = 0;
	mBusyFlag = true;
	mMutex.unlock();
}

void FunctionQueue::add(signed int (*func)(FunctionQueue*), signed int factor)
{
	mMutex.lock();
	mTaskFunc[mTaskHead] = (signed int (*)(FunctionQueue*, signed int))func;
	mFactor[mTaskHead] = factor;
	mTaskHead++;
	if(mTaskHead >= mTaskMaxSize)
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

int FunctionQueue::task(void)
{
	unsigned int tail;

	if(mTaskTail != mTaskHead)
	{
		if(mDelayTime)
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
		if(mTaskTail >= mTaskMaxSize)
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
	int error = ERROR_CODE::NO_ERROR;
	task->setError(ERROR_CODE::NO_ERROR);
	task->setStatus(STATUS_CODE::READY);

	while(1)
	{
		if(task->isComplete())
		{
			task->setStatus(STATUS_CODE::READY);
			thread::yield();
		}
		else
		{
			error = task->task();
		}

		if(error != ERROR_CODE::NO_ERROR)
		{
			task->clear();
		}
	}
}

void FunctionQueue::start(void)
{
	mMutex.lock();
	if(mThreadId == 0)
		mThreadId = thread::add((void (*)(void*))thread_run, this, mStackSize);
	mMutex.unlock();
}

void FunctionQueue::stop(void)
{
	mMutex.lock();
	if(mThreadId)
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
