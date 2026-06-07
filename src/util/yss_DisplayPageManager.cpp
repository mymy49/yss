#include <util/DisplayPageManager.h>
#include <yss/hmalloc.h>

DisplayPageManager::DisplayPageManager(int16_t maxCount)
{
	lockHmalloc();
	mFunctionList = (void (**)(void*))hmalloc(sizeof(void (**)(void*)) * maxCount);
	unlockHmalloc();

	mMaxCount = maxCount;
	mCount = 0;
	mId = 0;
	mUpdateIndex = 0;

	activateTrigger(128);
}

DisplayPageManager::~DisplayPageManager()
{
	lockHmalloc();
	hfree(mFunctionList);
	unlockHmalloc();
}

int16_t DisplayPageManager::add(void (*func)(void*))
{
	int16_t id;

	if(mCount < mMaxCount)
	{
		lock();
		id = mCount++;
		mFunctionList[id] = func;
		unlock();
		return id;
	}
	else
		return -1;
}

void DisplayPageManager::play(int16_t id, uint32_t stackSize)
{
	lock();
	mStackSize = stackSize;
	mUpdateIndex = id;
	mVar = 0;
	runTrigger();
	unlock();
}

void DisplayPageManager::trigger(void)
{
	lock();
	if(mId > 0)
		thread::remove(mId);
	mId = thread::add(mFunctionList[mUpdateIndex], mVar, mStackSize);
	unlock();
}
