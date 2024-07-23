/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>
#include <yss/Mutex.h>

static Mutex gMutex;

OutputFrameBuffer::OutputFrameBuffer(void)
{
	mFrame = 0;
	mFrameBuffer = new YSS_OUTPUT_FRAME_BUFFER;
}

OutputFrameBuffer::~OutputFrameBuffer(void)
{
	delete mFrameBuffer;
}

void OutputFrameBuffer::setLcdSize(Size_t size)
{
	mFrameBuffer->setSize(size);
}

void OutputFrameBuffer::update(Position_t pos, Size_t size)
{
	mFrameBuffer->drawObjectToPartialArea(pos, size, mFrame);	
}

void OutputFrameBuffer::update(Position_t beforePos, Size_t beforeSize, Position_t currentPos, Size_t currentSize)
{
	mFrameBuffer->drawObjectToPartialArea(beforePos, beforeSize, mFrame);	
	mFrameBuffer->drawObjectToPartialArea(currentPos, currentSize, mFrame);	
}

void OutputFrameBuffer::update(void)
{
	mFrameBuffer->drawObjectToPartialArea({0, 0}, mFrame->getSize(), mFrame);
}

void OutputFrameBuffer::setFrame(Frame *frame)
{
	mFrame = frame;
}

uint8_t* OutputFrameBuffer::getFrameBuffer(void)
{
	return (uint8_t*)mFrameBuffer->getFrameBuffer();
}

#endif

