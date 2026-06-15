/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#include <hal/PointerDevice.h>

PointerDevice::PointerDevice(void)
{
	mStep = 0;
	mTriggerId = -1;

	// Initialize pointer event state to no-event.
	clearEvent();
}

void PointerDevice::pushDownEvent(int16_t x, int16_t y)
{
	mMutex.lock();

	// Only record a down event if no up or drag event is already pending.
	if(!upEnventFlag && !dragEnventFlag)
	{
		downEnventFlag = true;
		mDownEvent.x = x;
		mDownEvent.y = y;
	}

	mMutex.unlock();
}

void PointerDevice::pushDragEvent(int16_t x, int16_t y)
{
	mMutex.lock();

	// Queue a drag event only if an up event is not already pending.
	if(!upEnventFlag)
	{
		dragEnventFlag = true;
		mDragEvent.x = x;
		mDragEvent.y = y;
	}

	mMutex.unlock();
}

void PointerDevice::pushUpEvent(int16_t x, int16_t y)
{
	mMutex.lock();

	// Record the up event only once until it is consumed.
	if(!upEnventFlag)
	{
		upEnventFlag = true;
		mUpEvent.x = x;
		mUpEvent.y = y;
	}

	mMutex.unlock();
}

void PointerDevice::clearEvent(void)
{
	mMutex.lock();

	// Reset all event coordinates and pending flags.
	mNothingEvent.x = 0;
	mNothingEvent.y = 0;
	downEnventFlag = dragEnventFlag = upEnventFlag = false;

	// Initialize all event structures to the default no-event state.
	mUpEvent = mDragEvent = mDownEvent = mNothingEvent;

	mNothingEvent.event = EVENT_NOTTING;
	mDownEvent.event = EVENT_TOUCH_DOWN;
	mDragEvent.event = EVENT_TOUCH_DRAG;
	mUpEvent.event = EVENT_TOUCH_UP;

	mMutex.unlock();
}

void PointerDevice::setTriggerId(triggerId_t id)
{
	// Store the trigger id only if the provided id is valid.
	if(id > 0)
	{
		mTriggerId = id;
	}
}


PointerDevice::event_t PointerDevice::getCurrentEvent(void)
{
	// If no event has been queued, return the default no-event.
	if(!downEnventFlag && !dragEnventFlag && !upEnventFlag)
		return mNothingEvent;

	// Return the highest-priority pending event and clear its flag.
	if(downEnventFlag)
	{
		downEnventFlag = false;
		return mDownEvent;
	}
	else if(dragEnventFlag)
	{
		dragEnventFlag = false;
		return mDragEvent;
	}
	else if(upEnventFlag)
	{
		upEnventFlag = false;
		return mUpEvent;
	}
	else 
	{
		return mNothingEvent;
	}
}

