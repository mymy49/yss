/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <sac/MonoLcd.h>
#include <std_ext/malloc.h>

namespace sac
{
MonoLcd::MonoLcd(void)
{
	mFrameBuffer = 0;
}

void MonoLcd::setSize(uint16_t width, uint16_t height)
{
	if (mFrameBuffer)
		delete mFrameBuffer;

	mFrameBuffer = new uint8_t[width * height / 8];

	MonoBrush::setSize(width, height);
}
}

#endif

