/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Trigger.h
 * @brief Trigger base class for scheduler-managed one-shot execution.
 */

#ifndef YSS_TRIGGER_CLASS__H_
#define YSS_TRIGGER_CLASS__H_

#include "scheduler.h"
#include <yss/error.h>

/**
 * @brief Abstract base class for a trigger object.
 *
 * A Trigger executes a user-defined trigger() method once when runTrigger()
 * is called. The trigger must be activated with activateTrigger() before
 * it can be run, and it is removed from the scheduler with
 * deactivateTriger() when it is no longer needed.
 */
class Trigger
{
public:
	/**
	 * @brief Construct a new Trigger object with an inactive trigger ID.
	 *
	 * @details Initializes mId to 0 (invalid) so that activateTrigger() knows
	 *          the trigger has not yet been registered with the scheduler.
	 */
	Trigger(void);
	
	/**
	 * @brief One-shot trigger action.
	 *
	 * @details Derived classes implement this method to perform the trigger action.
	 *          The method is invoked once by the internal adapter after the trigger has
	 *          been activated and trigger::run() has been called.  After trigger()
	 *          returns, the trigger becomes dormant again until the next runTrigger().
	 */
	virtual void trigger(void) = 0;

	/**
	 * @brief Activate the trigger in the scheduler.
	 *
	 * @details Registers the trigger with the scheduler via trigger::add(), passing an
	 *          internal adapter function and @c this as the argument.  If the trigger
	 *          is already active (mId != 0), the registration is skipped to prevent
	 *          duplicate entries.  The stack is allocated but the trigger remains dormant
	 *          until runTrigger() is called.
	 *
	 * @param stackSize Stack size to allocate for the trigger, in bytes.
	 * @return error_t Returns ERROR_NONE on success or FAILED_TRIGGER_ADDING on failure.
	 */
	error_t activateTrigger(uint32_t stackSize = 512);

	/**
	 * @brief Deactivate the trigger and remove it from the scheduler.
	 *
	 * @details Calls trigger::remove() to free the scheduler slot and its associated
	 *          stack memory, then resets mId to 0 so that activateTrigger() can be
	 *          called again if the trigger needs to be re-registered later.
	 *          Has no effect if the trigger was never activated (mId == 0).
	 */
	void deactivateTriger(void);

	/**
	 * @brief Execute the trigger once.
	 *
	 * @details Calls trigger::run() to rebuild the trigger's initial exception frame and
	 *          enqueue it in the scheduler's pending-signal queue.  The trigger will
	 *          execute the derived class trigger() method the next time the scheduler
	 *          selects it.  Has no effect if the trigger has not been activated (mId <= 0).
	 */
	void runTrigger(void);

	/**
	 * @brief Get the trigger identifier assigned by the scheduler.
	 *
	 * @details Returns the raw trigger ID stored in mId.  The value is 0 if the trigger
	 *          has not been activated, or negative if activation failed.
	 *
	 * @return triggerId_t Trigger ID, or 0 if the trigger is not active.
	 */
	triggerId_t getTriggerId(void);

private:
	triggerId_t mId;
};

#endif