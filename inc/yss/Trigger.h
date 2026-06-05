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
	 * @brief Construct a new Trigger object.
	 */
	Trigger(void);
	
	/**
	 * @brief One-shot trigger action.
	 *
	 * Derived classes implement this method to perform the trigger action.
	 * The method is invoked once by runTrigger() after the trigger has been
	 * activated.
	 */
	virtual void trigger(void) = 0;

	/**
	 * @brief Activate the trigger in the scheduler.
	 *
	 * @param stackSize Stack size to allocate for the trigger, in bytes.
	 * @return error_t Returns ERROR_NONE on success or an error code on failure.
	 */
	error_t activateTrigger(uint32_t stackSize = 512);

	/**
	 * @brief Deactivate the trigger and remove it from the scheduler.
	 */
	void deactivateTriger(void);

	/**
	 * @brief Execute the trigger once.
	 *
	 * This function runs the previously activated trigger and invokes the
	 * derived class trigger() method.
	 */
	void runTrigger(void);

	/**
	 * @brief Get the trigger identifier assigned by the scheduler.
	 *
	 * @return triggerId_t Trigger ID, or 0 if the trigger is not active.
	 */
	triggerId_t getTriggerId(void);

private:
	triggerId_t mId;
};

#endif