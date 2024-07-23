/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_SAC_TOUCH__H_
#define	YSS_SAC_TOUCH__H_

#include <gui/util.h>
#include <yss/thread.h>

class PointerEvent;

namespace sac
{
	class Touch
	{
	public :
		Touch(void);
		void setInterface(PointerEvent &pointerEvent, triggerId_t id);
		void push(uint32_t x, uint32_t y, uint8_t event);

	protected :

	private :
		triggerId_t mTriggerId;
		PointerEvent *mPointerEvent;
	};
}

#endif
