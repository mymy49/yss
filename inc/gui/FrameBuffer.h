/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_FRAME_BUFFER___H_
#define YSS_GUI_FRAME_BUFFER___H_

#include "util.h"
#include <yss/error.h>

class FrameBuffer
{
public :
	enum
	{
		COLOR_MODE_ARGB8888 = 0,
		COLOR_MODE_RGB888,
		COLOR_MODE_RGB565,
		COLOR_MODE_ARGB1555,
	};

	FrameBuffer(void);

	virtual ~FrameBuffer(void);
	
	error_t setColorMode(uint8_t colorMode);

	void enableMemoryAlloc(bool en = true);

	void setFrameBuffer(void *frameBuffer);

	void* getFrameBuffer(void);

	uint8_t getColorMode(void);

	uint8_t getDotSize(void);

	virtual error_t setSize(uint16_t width, uint16_t height);

	virtual error_t setSize(Size_t size);

	Size_t getSize(void);

protected :
	uint8_t mColorMode, mDotSize;
	uint8_t *mFrameBuffer;
	Size_t mSize;
	bool mMemAllocFlag;
};

#endif

