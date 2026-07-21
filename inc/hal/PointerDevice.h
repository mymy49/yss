/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file PointerDevice.h
 * @brief Hardware Abstraction Layer (HAL) interface for pointing input devices.
 */

#ifndef	YSS_HAL_POINTER_DEVICE__H_
#define	YSS_HAL_POINTER_DEVICE__H_

#include <stdint.h>
#include <yss/scheduler.h>
#include <yss/Mutex.h>

/**
 * @class PointerDevice
 * @brief Hardware abstraction base class for pointing devices (touchscreens, mice, touchpads).
 *
 * This class provides thread-safe event buffering and GUI trigger notifications
 * for pointing devices such as capacitive or resistive touchscreens. Derived driver
 * classes push hardware touch events (Down, Drag, Up), which are queued and retrieved
 * by the system's GUI framework.
 */
class PointerDevice
{
public :
	/**
	 * @enum eventType_t
	 * @brief Enumeration of supported pointer touch event types.
	 */
	typedef enum
	{
		EVENT_NOTTING = 0,  /**< No pointer event currently active. */
		EVENT_TOUCH_DOWN,   /**< Touch screen press/down event. */
		EVENT_TOUCH_DRAG,   /**< Touch drag/motion event. */
		EVENT_TOUCH_UP      /**< Touch screen release/up event. */
	}eventType_t;
	
	/**
	 * @struct event_t
	 * @brief Structure containing pointer coordinates and event type.
	 */
	typedef struct
	{
		int16_t x;          /**< Horizontal (X) coordinate of the touch event. */
		int16_t y;          /**< Vertical (Y) coordinate of the touch event. */
		eventType_t event;  /**< Type of pointing event. */
	}event_t;
	
	/**
	 * @brief Constructor for PointerDevice.
	 *
	 * Initializes internal event structures, clears pending flags, and sets default trigger ID to -1.
	 */
	PointerDevice(void);

	/**
	 * @brief Sets the trigger ID for system GUI event notification.
	 *
	 * Used internally by the system to associate this pointer device with a GUI event trigger.
	 *
	 * @param[in] id Trigger identifier used to notify the GUI event loop.
	 */
	void setTriggerId(triggerId_t id);

	/**
	 * @brief Clears the registered system GUI trigger ID.
	 */
	void clearTriggerId(void);

	/**
	 * @brief Resets all pending pointer events and clears internal event buffers.
	 */
	void clearEvent(void);

	/**
	 * @brief Retrieves the highest-priority pending touch event.
	 *
	 * Checks pending event flags in order (Down > Drag > Up) and returns the highest-priority event,
	 * clearing its pending flag. Returns an event with type EVENT_NOTTING if no event is pending.
	 *
	 * @return Current active pointer event structure.
	 */
	event_t getCurrentEvent(void);
	
protected :
	/**
	 * @brief Registers a touch down event at the specified coordinates.
	 *
	 * Intended to be called by derived touchscreen driver classes when a touch press is detected.
	 * Thread-safe.
	 *
	 * @param[in] x X coordinate of touch down.
	 * @param[in] y Y coordinate of touch down.
	 */
	void pushDownEvent(int16_t x, int16_t y);

	/**
	 * @brief Registers a touch drag event at the specified coordinates.
	 *
	 * Intended to be called by derived touchscreen driver classes during touch motion/drag.
	 * Thread-safe.
	 *
	 * @param[in] x X coordinate of touch drag.
	 * @param[in] y Y coordinate of touch drag.
	 */
	void pushDragEvent(int16_t x, int16_t y);

	/**
	 * @brief Registers a touch up event at the specified coordinates.
	 *
	 * Intended to be called by derived touchscreen driver classes when a touch release is detected.
	 * Thread-safe.
	 *
	 * @param[in] x X coordinate of touch up.
	 * @param[in] y Y coordinate of touch up.
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

