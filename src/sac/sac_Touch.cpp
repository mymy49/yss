/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#include <sac/Touch.h>
#include <yss/event.h>
#include <yss/PointerEvent.h>
#include <yss/debug.h>

namespace  sac
{
	Touch::Touch(void)
	{
		mTriggerId = -1;
		mPointerEvent = 0;
	}
	
	void Touch::push(uint32_t x, uint32_t y, uint8_t event)
	{
		PointerEvent::PointerEventData data;

		if(mPointerEvent)
		{
			data.x = x;
			data.y = y;
			data.event = event;
			
			mPointerEvent->push(data);
			if(mTriggerId > 0)
				trigger::run(mTriggerId);
		}
	}

	void Touch::setInterface(PointerEvent &pointerEvent, triggerId_t id)
	{
		mPointerEvent = &pointerEvent;
		mTriggerId = id;
	}
}

