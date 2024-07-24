/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <std_ext/malloc.h>
#include <yss/PointerEvent.h>
#include <sac/Rtouch.h>
#include <yss.h>
#include <yss/debug.h>

#if USE_EVENT

namespace event
{
	void trigger_handleEvent(void);

	PointerEvent gPointerEvent(TOUCH_EVENT_MEMORY_DEPTH);
	static triggerId_t gTriggerId;

	void init(void)
	{
		gTriggerId = trigger::add(trigger_handleEvent, TOUCH_EVENT_HANDLER_STACK_SIZE);
	}

	void trigger_handleEvent(void)
	{
		PointerEvent::PointerEventData data;
		while(gPointerEvent.getMessageCount())
		{
			data = gPointerEvent.pop();
			setEvent(Position_t{(int16_t)data.x, (int16_t)data.y}, data.event);
		}
	}

	void setPointerDevice(sac::Touch &dev)
	{
		dev.setInterface(gPointerEvent, gTriggerId);
	}
};
#endif