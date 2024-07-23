/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <std_ext/malloc.h>
#include <gui/FrameBuffer.h>
#include <yss/instance.h>

FrameBuffer::FrameBuffer(void)
{
	mFrameBuffer = 0;
	mMemAllocFlag = false;
}

error_t FrameBuffer::setColorMode(uint8_t colorMode)
{
	switch(colorMode)
	{
	case COLOR_MODE_RGB888 :
		mDotSize  = 3;
		mColorMode = colorMode;
		return error_t::ERROR_NONE;
	case COLOR_MODE_RGB565 :
		mDotSize  = 2;
		mColorMode = colorMode;
		return error_t::ERROR_NONE;
	case COLOR_MODE_ARGB1555 :
		mDotSize  = 2;
		mColorMode = colorMode;
		return error_t::ERROR_NONE;		

	default :
		return error_t::NOT_SUPPORTED_FORMAT;
	}
}

FrameBuffer::~FrameBuffer(void)
{
	if(mMemAllocFlag && mFrameBuffer)
#if YSS_L_HEAP_USE
		lfree(mFrameBuffer);
#else
		delete mFrameBuffer;
#endif
}

error_t FrameBuffer::setSize(Size_t size)
{
	return setSize(size.width, size.height);
}

error_t FrameBuffer::setSize(uint16_t width, uint16_t height)
{
	if(width == 0 || height == 0)
		return error_t::WRONG_CONFIG;

	mSize.width = width;
	mSize.height = height;
	
	// 메모리가 할당가능하고 이전에 이미 할당 받았다면 메모리를 해제한다.
	if(mMemAllocFlag && mFrameBuffer)
#if YSS_L_HEAP_USE
		lfree(mFrameBuffer);
#else
		delete mFrameBuffer;
#endif
	
	// 메모리가 할당가능하다면 새로 메모리를 할당 받는다.
	if(mMemAllocFlag)
#if YSS_L_HEAP_USE
		mFrameBuffer = (uint8_t *)lmalloc(width * height * mDotSize);
#else
		mFrameBuffer = new uint8_t[width * height * mDotSize];
#endif

	return error_t::ERROR_NONE;
}

Size_t FrameBuffer::getSize(void)
{
	return mSize;
}

void FrameBuffer::enableMemoryAlloc(bool en)
{
	mMemAllocFlag = en;
}

void FrameBuffer::setFrameBuffer(void *frameBuffer)
{
	if(!mMemAllocFlag)
		mFrameBuffer = (uint8_t*)frameBuffer;		
}

void* FrameBuffer::getFrameBuffer(void)
{
	return mFrameBuffer;	
}

uint8_t FrameBuffer::getColorMode(void)
{
	return mColorMode;
}

uint8_t FrameBuffer::getDotSize(void)
{
	return mDotSize;
}

#endif

