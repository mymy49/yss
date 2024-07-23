/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_EVENT__H_
#define YSS_EVENT__H_

#include <gui/util.h>
#include <sac/Rtouch.h>

namespace event
{
	enum
	{
		TOUCH_DOWN = 0,
		TOUCH_DRAG,
		TOUCH_UP
	};

	void init(void);
	void setPointerDevice(sac::Touch &dev);
	void add(uint16_t x, uint16_t y, uint8_t event);
	void add(Position_t pos, uint8_t event);
	void trigger(void);
	void flush(void);
};

#endif
