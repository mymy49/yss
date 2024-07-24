/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/instance.h>
#include <gui/FrameBufferRgb888.h>
#include <std_ext/malloc.h>
/*
FrameBufferRgb888::FrameBufferRgb888(void)
{

}

FrameBufferRgb888::~FrameBufferRgb888(void)
{

}

uint8_t FrameBufferRgb888::getDotSize(void)
{
	return 3;
}

uint8_t FrameBufferRgb888::getColorMode(void)
{
	return define::dma2d::colorMode::RGB888;
}

void FrameBufferRgb888::drawDot(int16_t x, int16_t y, uint32_t color)
{
	uint8_t *des = &((uint8_t*)(mFrameBuffer))[y * FrameBuffer::mSize.width * 3 + x * 3];
	uint8_t *src = (uint8_t*)&color;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;	
}

void FrameBufferRgb888::drawDot(int16_t x, int16_t y)
{

}

void FrameBufferRgb888::drawDot(int16_t x, int16_t y, Color color)
{

}

void FrameBufferRgb888::eraseDot(Position pos)
{
	uint8_t *des = &((uint8_t*)(mFrameBuffer))[pos.y * FrameBuffer::mSize.width * 3 + pos.x * 3];
	uint32_t color = FrameBuffer::mBgColor.getRgb888Code();
	uint8_t *src = (uint8_t*)&color;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

uint8_t FrameBufferRgb888::drawChar(Position pos, uint32_t utf8)
{
	//if (mFrameBuffer)
	//	return Painter::drawChar(*this, &FrameBuffer::mFont, utf8, pos, FrameBuffer::mFontColor);
	//else
		return 0;
}

void FrameBufferRgb888::drawBmp(Position pos, const Bmp565 *image)
{

}

void FrameBufferRgb888::drawBmp(Position pos, const Bmp565 &image)
{
	Painter::drawBmp(*this, &image, pos);
}

void FrameBufferRgb888::drawBmp(Position pos, const Bmp1555 *image)
{

}

void FrameBufferRgb888::drawBmp(Position pos, const Bmp1555 &image)
{

}

void FrameBufferRgb888::drawBmp(Position pos, const Bmp888 *image)
{

}

void FrameBufferRgb888::drawBmp(Position pos, const Bmp888 &image)
{

}

void FrameBufferRgb888::updateFontColor(void)
{
	for(uint8_t i=0;i<16;i++)
		mFontColorTable[i] = FrameBuffer::mFontColor.calculateFontColorLevel(FrameBuffer::mBgColor, i).getRgb888Code();
}
*/
/*
error FrameBufferRgb888::setSize(uint16_t width, uint16_t height)
{
	if(width == FrameBuffer::mSize.width && width === FrameBuffer::mSize.height)
		return error::ERROR_NONE;

	FrameBuffer::mSize = Size{width, height};

	if (mFrameBuffer)
		lfree(mFrameBuffer);

	//if (height == 0 || width == 0)
	//	mFrameBuffer = 0;
	//else
	//	mFrameBuffer = lmalloc(width * height * mDotSize);

	//Brush::setSize(mSize);
}
*/
#endif

