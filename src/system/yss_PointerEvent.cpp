/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/PointerEvent.h>

PointerEvent::PointerEvent(uint32_t bufferSize) : mFifo(bufferSize * sizeof(PointerEvent::PointerEventData))
{
	
}

void PointerEvent::push(PointerEventData &data)
{
	mMutex.lock();
	mFifo.push(&data, sizeof(data));
	mMutex.unlock();
}

uint32_t PointerEvent::getMessageCount(void)
{
	return mFifo.getStoredSize() / sizeof(PointerEventData);
}

PointerEvent::PointerEventData PointerEvent::pop(void)
{
	PointerEventData data;
	mMutex.lock();
	mFifo.pop(&data, sizeof(data));
	mMutex.unlock();
	return data;
}

void PointerEvent::flush(void)
{
	mFifo.flush();
}

