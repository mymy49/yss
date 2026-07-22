/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_EVENT__H_
#define YSS_EVENT__H_

/**
 * @file event.h
 * @brief GUI event handling definitions.
 */

#if 0

#include <gui/util.h>
#include <sac/Rtouch.h>

/**
 * @namespace event
 * @brief Namespace containing touchscreen event helper definitions and functions.
 */
namespace event
{
	enum
	{
		TOUCH_DOWN = 0,             ///< Touch down event.
		TOUCH_DRAG,                 ///< Touch drag event.
		TOUCH_UP                    ///< Touch up event.
	};

	void init(void);
	void setPointerDevice(sac::Touch &dev);
	void add(uint16_t x, uint16_t y, uint8_t event);
	void add(Position_t pos, uint8_t event);
	void trigger(void);
	void flush(void);
};

#endif

#endif

