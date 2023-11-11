////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

