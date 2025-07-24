#include <yss/Trigger.h>

static void thread_thread(void *var)
{
	Trigger *obj = (Trigger*)var;
	
	obj->trigger();
}

Trigger::Trigger(void)
{
	mId = 0;
}

void Trigger::activateTrigger(uint32_t stackSize)
{
	if(mId == 0)
		mId = trigger::add(thread_thread, this, stackSize);
}

void Trigger::deactivateTriger(void)
{
	if(mId)
	{
		trigger::remove(mId);
		mId = 0;
	}
}

void Trigger::runTrigger(void)
{
	trigger::run(mId);
}

