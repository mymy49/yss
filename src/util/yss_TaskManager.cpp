#include <util/TaskManager.h>
#include <yss/hmalloc.h>

TaskManager::TaskManager(int16_t maxCount)
{
	mWorker = new worker_t[maxCount];
	mWorker1Id = mWorker2Id = mWorker3Id = 0;
	mMaxCount = maxCount;
	mCount = 0;
	mUpdateIndex = 0;
	mResetter = nullptr;

	activateTrigger(512);
}

TaskManager::~TaskManager()
{
	delete[] mWorker;
}

int16_t TaskManager::add(void (*worker)(void*), uint32_t workerStackSize)
{
	int16_t id;

	if(mCount < mMaxCount)
	{
		lock();
		id = mCount++;
		mWorker[id].count = 1;
		mWorker[id].worker1 = worker;
		mWorker[id].worker1StackSize = workerStackSize;
		unlock();
		return id;
	}
	else
		return -1;
}

int16_t TaskManager::add(void (*worker1)(void*), void (*worker2)(void*), uint32_t worker1StackSize, uint32_t worker2StackSize)
{
	int16_t id;

	if(mCount < mMaxCount)
	{
		lock();
		id = mCount++;
		mWorker[id].count = 2;
		mWorker[id].worker1 = worker1;
		mWorker[id].worker1StackSize = worker1StackSize;
		mWorker[id].worker2 = worker2;
		mWorker[id].worker2StackSize = worker2StackSize;
		unlock();
		return id;
	}
	else
		return -1;
}

int16_t TaskManager::add(void (*worker1)(void*), void (*worker2)(void*), void (*worker3)(void*), uint32_t worker1StackSize, uint32_t worker2StackSize, uint32_t worker3StackSize)
{
	int16_t id;

	if(mCount < mMaxCount)
	{
		lock();
		id = mCount++;
		mWorker[id].count = 3;
		mWorker[id].worker1 = worker1;
		mWorker[id].worker1StackSize = worker1StackSize;
		mWorker[id].worker2 = worker2;
		mWorker[id].worker2StackSize = worker2StackSize;
		mWorker[id].worker3 = worker3;
		mWorker[id].worker3StackSize = worker3StackSize;
		unlock();
		return id;
	}
	else
		return -1;
}

void TaskManager::play(int16_t id, void *var1, void *var2, void *var3)
{
	lock();
	mUpdateIndex = id;
	mVar1 = var1;
	mVar2 = var2;
	mVar3 = var3;
	runTrigger();
	unlock();
}

void TaskManager::setResetter(void (*resetter)())
{
	mResetter = resetter;
}

void TaskManager::trigger(void)
{
	lock();
	if(mResetter != nullptr)
		mResetter();

	if(mWorker1Id > 0)
	{
		thread::remove(mWorker1Id);
		mWorker1Id = 0;
	}
	if(mWorker[mUpdateIndex].count > 0)
		mWorker1Id = thread::add(mWorker[mUpdateIndex].worker1, mVar1, mWorker[mUpdateIndex].worker1StackSize);
	unlock();

	lock();
	if(mWorker2Id > 0)
	{
		thread::remove(mWorker2Id);
		mWorker2Id = 0;
	}
	if(mWorker[mUpdateIndex].count > 1)
		mWorker2Id = thread::add(mWorker[mUpdateIndex].worker2, mVar2, mWorker[mUpdateIndex].worker2StackSize);
	unlock();

	lock();
	if(mWorker3Id > 0)
	{
		thread::remove(mWorker3Id);
		mWorker3Id = 0;
	}
	if(mWorker[mUpdateIndex].count > 2)
		mWorker3Id = thread::add(mWorker[mUpdateIndex].worker3, mVar3, mWorker[mUpdateIndex].worker3StackSize);
	unlock();
}
