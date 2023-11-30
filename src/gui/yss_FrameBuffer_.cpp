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

#if USE_GUI

#include <std_ext/malloc.h>
#include <gui/FrameBuffer_.h>
#include <yss/instance.h>

FrameBuffer_::FrameBuffer_(void)
{
	mFrameBuffer = 0;
	mMemAllocFlag = false;
}

error FrameBuffer_::setColorMode(uint8_t colorMode)
{
	switch(colorMode)
	{
	case COLOR_MODE_RGB888 :
		mDotSize  = 3;
		mColorMode = colorMode;
		return error::ERROR_NONE;
	case COLOR_MODE_RGB565 :
		mDotSize  = 2;
		mColorMode = colorMode;
		return error::ERROR_NONE;
	case COLOR_MODE_ARGB1555 :
		mDotSize  = 2;
		mColorMode = colorMode;
		return error::ERROR_NONE;		

	default :
		return error::NOT_SUPPORTED_FORMAT;
	}
}

FrameBuffer_::~FrameBuffer_(void)
{
	if(mMemAllocFlag && mFrameBuffer)
#if YSS_L_HEAP_USE
		lfree(mFrameBuffer);
#else
		delete mFrameBuffer;
#endif
}

error FrameBuffer_::setSize(Size_t size)
{
	return setSize(size.width, size.height);
}

error FrameBuffer_::setSize(uint16_t width, uint16_t height)
{
	if(width == 0 || height == 0)
		return error::WRONG_CONFIG;

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

	return error::ERROR_NONE;
}

Size_t FrameBuffer_::getSize(void)
{
	return mSize;
}

void FrameBuffer_::enableMemoryAlloc(bool en)
{
	mMemAllocFlag = en;
}

void FrameBuffer_::setFrameBuffer(void *frameBuffer)
{
	if(!mMemAllocFlag)
		mFrameBuffer = (uint8_t*)frameBuffer;		
}

void* FrameBuffer_::getFrameBuffer(void)
{
	return mFrameBuffer;	
}

uint8_t FrameBuffer_::getColorMode(void)
{
	return mColorMode;
}

uint8_t FrameBuffer_::getDotSize(void)
{
	return mDotSize;
}

#endif

