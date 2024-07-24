/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <drv/peripheral.h>
#include <gui/Bmp565Buffer.h>
#include <std_ext/string.h>
#include <yss/error.h>

Bmp565Buffer::Bmp565Buffer(uint32_t pointSize)
{
	mBufferSize = pointSize * 2;
	mFrameBuffer = new uint8_t[mBufferSize];

	mBmp565.width = 0;
	mBmp565.height = 0;
	mBmp565.data = (uint8_t *)mFrameBuffer;
	mBmp565.type = 0;
	mOkFlag = false;
}

Bmp565Buffer::~Bmp565Buffer(void)
{
	if (mFrameBuffer)
		delete mFrameBuffer;
}

error_t Bmp565Buffer::setSize(uint16_t width, uint16_t height)
{
	if (mBufferSize < width * height * 2)
		return error_t::OVERSIZE;

	mOkFlag = true;
	mBmp565.width = width;
	mBmp565.height = height;
	mSize = Size_t{width, height};

	return error_t::ERROR_NONE;
}

error_t Bmp565Buffer::setSize(Size_t size)
{
	mBmp565.width = size.width;
	mBmp565.height = size.height;
	mSize = size;

	return error_t::ERROR_NONE;
}

Bitmap_t *Bmp565Buffer::getBitmap(void)
{
	return &mBmp565;
}

uint32_t Bmp565Buffer::getBufferSize(void)
{
	return mBufferSize;
}

void Bmp565Buffer::drawStringToCenterAligned(const char *str)
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


