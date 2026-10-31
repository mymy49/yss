/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_TOUCH_EVENT_DISPATCHER__H_
#define YSS_UTIL_TOUCH_EVENT_DISPATCHER__H_

#include <yss/Trigger.h>
#include <yss/Area.h>
#include <hal/PointerDevice.h>

class TouchEventDispatcher : private Trigger
{
public :
	TouchEventDispatcher(uint32_t depth, uint32_t stackSize);

	~TouchEventDispatcher();

	error_t add(Area area, void (*callback)(PointerDevice::event_t));

	void setPointerDevice(PointerDevice &dev);

	void clear();

private :
	struct eventMap_t
	{
		Area area;
		void (*callback)(PointerDevice::event_t);
	};

	eventMap_t *mEventMap;
	uint32_t mDepth;
	uint32_t mCount;
	int32_t mSelectedIndex;
	PointerDevice *mPointerDev;

	void trigger() override;
};

#endif

