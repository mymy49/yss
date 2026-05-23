/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_HAL_POINTER_DEVICE__H_
#define	YSS_HAL_POINTER_DEVICE__H_

#include <stdint.h>
#include <yss/scheduler.h>
#include <yss/Mutex.h>

/*
	This is a hardware abstraction layer that pointing device modules (capacitive touchscreens, resistive touchscreens, etc.) must inherit.
*/
class PointerDevice
{
public :
	/*
		EVENT_NOTTING = 0,
		EVENT_TOUCH_DOWN,
		EVENT_TOUCH_DRAG,
		EVENT_TOUCH_UP
	*/
	typedef enum
	{
		EVENT_NOTTING = 0,
		EVENT_TOUCH_DOWN,
		EVENT_TOUCH_DRAG,
		EVENT_TOUCH_UP
	}eventType_t;
	
	/*
		int16_t x;
		int16_t y;
		eventType_t event;
	*/
	typedef struct
	{
		int16_t x;
		int16_t y;
		eventType_t event;
	}event_t;
	
	/*	▣ It is a function called from within the system.
	*/
	PointerDevice(void);

	/*	▣ It is a function called from within the system.
		.
		Receive the ID of the corresponding trigger to notify the system's GUI library that an event has occurred.
		.
		@ id : Passes the ID of the trigger to notify the event.
	*/
	void setTriggerId(triggerId_t id);

	/*	▣ It is a function called from within the system.
		.
		Removes the currently connected trigger ID.

		.
		@ id : Passes the ID of the trigger to notify the event.
	*/
	void clearTriggerId(void);

	/*
		Clears all events that have occurred.
	*/
	void clearEvent(void);

	/*
		This is a function that receives valid events currently occurring on the pointer device.
		.
		@ return : Returns an event.
	*/
	event_t getCurrentEvent(void);
	
protected :
	/*	▣ It is a function called from within the system.
		.
		The child class is a function that notifies the parent class, Pointer Device, that a Down event has occurred when a Down event occurs on the touch screen.
		.
		@ x : Passes the X coordinate where the event occurred.
		@ y : Passes the Y coordinate where the event occurred.
	*/
	void pushDownEvent(int16_t x, int16_t y);

	/*	▣ It is a function called from within the system.
		.
		The child class is a function that notifies the parent class, Pointer Device, that a Drag event has occurred when a Drag event occurs on the touch screen.
		.
		@ x : Passes the X coordinate where the event occurred.
		@ y : Passes the Y coordinate where the event occurred.
	*/
	void pushDragEvent(int16_t x, int16_t y);

	/*	▣ It is a function called from within the system.
		.
		The child class is a function that notifies the parent class, Pointer Device, that a Up event has occurred when a Up event occurs on the touch screen.
		.
		@ x : Passes the X coordinate where the event occurred.
		@ y : Passes the Y coordinate where the event occurred.
	*/
	void pushUpEvent(int16_t x, int16_t y);

private :
	uint8_t mStep;
	event_t mDownEvent, mDragEvent, mUpEvent, mNothingEvent;
	bool downEnventFlag, dragEnventFlag, upEnventFlag;
	triggerId_t mTriggerId;
	Mutex mMutex;
};

#endif

