/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/Trigger.h>

#pragma GCC optimize("O1")

/// @brief Internal scheduler thread function that invokes the Trigger object's callback.
/// @details This static adapter is passed to trigger::add() as the entry function.
///          It casts the opaque @p var pointer back to a Trigger*, then calls the
///          virtual trigger() method on it.  The function is intentionally not a loop;
///          after trigger() returns, control passes to trigger::disable() (placed in
///          the LR slot of the exception frame) which keeps the trigger dormant until
///          the next trigger::run() call.
/// @param var Pointer to the owning Trigger object.
static void thread_thread(void *var)
{
	Trigger *obj = (Trigger*)var;
	
	// Invoke the derived class's one-shot trigger action.
	obj->trigger();
}

Trigger::Trigger(void)
{
	mId = 0;
}

error_t Trigger::activateTrigger(uint32_t stackSize)
{
	// Register the trigger only if it has not been previously activated.
	if(mId == 0)
		mId = trigger::add(thread_thread, this, stackSize);

	// A non-positive ID indicates that no scheduler slot was available or
	// stack allocation failed.
	if(mId <= 0)
		return error_t::FAILED_TRIGGER_ADDING;
	else
		return error_t::ERROR_NONE;
}

void Trigger::deactivateTriger(void)
{
	// Only attempt removal if the trigger was previously registered.
	if(mId > 0)
	{
		trigger::remove(mId);
		mId = 0;  // Invalidate the ID to mark the trigger as inactive.
	}
}

void Trigger::runTrigger(void)
{
	// Only schedule execution if the trigger is currently active.
	if(mId > 0)
		trigger::run(mId);
}

triggerId_t Trigger::getTriggerId(void)
{
	return mId;
}

