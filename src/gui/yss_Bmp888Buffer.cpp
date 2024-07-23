/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <drv/peripheral.h>
#include <gui/Bmp888Buffer.h>
#include <std_ext/string.h>

Bmp888Buffer::Bmp888Buffer(uint32_t pointSize)
{
	mBufferSize = pointSize * 3;
	mFrameBuffer = new uint8_t[mBufferSize];

	mBmp888.width = 0;
	mBmp888.height = 0;
	mBmp888.data = mFrameBuffer;
	mBmp888.type = 1;
}

Bmp888Buffer::~Bmp888Buffer(void)
{
	if (mFrameBuffer)
		delete mFrameBuffer;
}

error_t Bmp888Buffer::setSize(uint16_t width, uint16_t height)
{
	if (mBufferSize < width * height * 3)
		return error_t::OVERSIZE;

	mOkFlag = true;
	mBmp888.width = width;
	mBmp888.height = height;
	mSize = Size_t{width, height};

	return error_t::ERROR_NONE;
}

error_t Bmp888Buffer::setSize(Size_t size)
{
	mBmp888.width = size.width;
	mBmp888.height = size.height;
	mSize = size;

	return error_t::ERROR_NONE;
}

Bitmap_t *Bmp888Buffer::getBitmap(void)
{
	return &mBmp888;
}

uint32_t Bmp888Buffer::getBufferSize(void)
{
	return mBufferSize;
}

void Bmp888Buffer::drawStringToCenterAligned(const char *str)
{
	Position_t pos;
	Size_t size = calculateStringSize(str);

	pos.x = (mSize.width - size.width) / 2;
	if (pos.x < 0)
		pos.x = 0;
	pos.y = (mSize.height - size.height) / 2;
	if (pos.y < 0)
		pos.y = 0;
	Brush::drawString(pos, str);
}

#endif

