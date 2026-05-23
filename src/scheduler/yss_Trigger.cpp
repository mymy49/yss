/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

error_t Trigger::activateTrigger(uint32_t stackSize)
{
	if(mId == 0)
		mId = trigger::add(thread_thread, this, stackSize);

	if(mId <= 0)
		return error_t::FAILED_TRIGGER_ADDING;
	else
		return error_t::ERROR_NONE;
}

void Trigger::deactivateTriger(void)
{
	if(mId > 0)
	{
		trigger::remove(mId);
		mId = 0;
	}
}

void Trigger::runTrigger(void)
{
	if(mId > 0)
		trigger::run(mId);
}

triggerId_t Trigger::getTriggerId(void)
{
	return mId;
}

