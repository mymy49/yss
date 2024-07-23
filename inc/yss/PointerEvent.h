/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_POINTER_EVENT__H_
#define YSS_POINTER_EVENT__H_

#include <gui/util.h>
#include <util/Fifo.h>

class PointerEvent
{
	Fifo mFifo;
	Mutex mMutex;
public :
	struct PointerEventData
	{
		uint16_t x, y;
		uint8_t event;
	}__PACKED;

	PointerEvent(uint32_t bufferSize);
	void push(PointerEventData &data);
	PointerEventData pop(void);
	uint32_t getMessageCount(void);
	void flush(void);
};

#endif
