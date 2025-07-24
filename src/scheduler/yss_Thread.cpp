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

void Thread::runThread(uint32_t stackSize)
{
	if(mId == 0)
		mId = thread::add(thread_thread, this, stackSize);
}

void Thread::stopThread(void)
{
	if(mId)
	{
		thread::remove(mId);
		mId = 0;
	}
}

