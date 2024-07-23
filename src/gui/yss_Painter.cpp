/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <gui/Painter.h>
#include <gui/Object.h>
#include <yss/thread.h>
#include <yss/instance.h>

void Painter::updateFontColor(void)
{
	mFontColorCode = mFontColor.getRgb888Code();
}

void Painter::drawBitmapBase(Position_t pos, const Bitmap_t &bitmap)
{
	using namespace define::dma2d;

	if(mFrameBuffer == 0)
		return;
	
	Size_t srcSize = {bitmap.width, bitmap.height};
	uint16_t height = srcSize.height, width = srcSize.width, srcOffset = 0, desOffset = 0;
	int32_t buf;
	uint8_t *desAddr, *srcAddr, bitmapColorMode;
	int32_t srcDotSize;

	switch(bitmap.type)
	{
	case 0 : // RGB565
		bitmapColorMode = colorMode::RGB565;
		srcDotSize = 2;
		break;

	case 1 : // RGB888
		bitmapColorMode = colorMode::RGB888;
		srcDotSize = 3;
		break;
	
	case 2 : // ARGB1555
		bitmapColorMode = colorMode::ARGB1555;
		srcDotSize = 2;
		break;

	default :
		return;
	}

	desAddr = (uint8_t *)mFrameBuffer;
	if (desAddr == 0)
		return;

	srcAddr = (uint8_t *)bitmap.data;
	if (srcAddr == 0)
		return;

	// 좌표가 대상 밖이면 리턴
	if (pos.x > mSize.width ||
		pos.y > mSize.height ||
		pos.x + srcSize.width < 0 ||
		pos.y + srcSize.height < 0)
		return;

	// Y 좌표에 따른 대상의 이미지 시작 주소 계산
	if (pos.y < 0)
	{
		buf = pos.y * -1;
		srcAddr += srcSize.width * buf * srcDotSize;
		height -= buf;
	}
	else
	{
		desAddr += mSize.width * pos.y * mDotSize;
	}

	// 소스 이미지의 크기가 대상보다 크면 대상에 맞게 크기 조정 
	buf = (pos.y + height) - mSize.height;
	if (buf > 0)
	{
		height -= buf;
	}

	// X 좌표에 따른 대상의 이미지 시작 주소 계산
	if (pos.x < 0)
	{
		buf = pos.x * -1;
		srcAddr += buf * srcDotSize;
		width -= buf;
	}
	else
	{
		desAddr += pos.x * mDotSize;
	}

	srcOffset = srcSize.width - width;
	desOffset = mSize.width - width;

	if (width == 0 || height == 0)
		return;

	Dma2d::BlendConfig config = 
	{
		(void*)srcAddr,			//void *sourceAddress;
		(uint16_t)srcOffset,	//uint16_t sourceOffset;
		bitmapColorMode,		//uint8_t sourceColorMode;

		(void*)desAddr,			//void *destinationAddress;
		(uint16_t)desOffset,	//uint16_t destinationOffset;
		mColorMode,				//uint8_t destinationColorMode;

		{width, height}			//Size_t size;
	};

	dma2d.lock();
	dma2d.blend(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void Painter::drawBitmapFileBase(Position_t pos, const BitmapFile_t &bitmap)
{
	using namespace define::dma2d;

	if(mFrameBuffer == 0)
		return;
	
	Size_t srcSize = {bitmap.width, bitmap.height};
	uint16_t height = srcSize.height, width = srcSize.width, srcOffset = 0, desOffset = 0;
	int32_t buf;
	uint8_t *desAddr, *srcAddr, bitmapColorMode;
	int32_t srcDotSize;

	switch(bitmap.type)
	{
	case 0 : // RGB565
		bitmapColorMode = colorMode::RGB565;
		srcDotSize = 2;
		break;

	case 1 : // RGB888
		bitmapColorMode = colorMode::RGB888;
		srcDotSize = 3;
		break;
	
	case 2 : // ARGB1555
		bitmapColorMode = colorMode::ARGB1555;
		srcDotSize = 2;
		break;

	default :
		return;
	}

	desAddr = (uint8_t *)mFrameBuffer;
	if (desAddr == 0)
		return;

	srcAddr = (uint8_t *)&bitmap.data;
	if (srcAddr == 0)
		return;

	// 좌표가 대상 밖이면 리턴
	if (pos.x > mSize.width ||
		pos.y > mSize.height ||
		pos.x + srcSize.width < 0 ||
		pos.y + srcSize.height < 0)
		return;

	// Y 좌표에 따른 대상의 이미지 시작 주소 계산
	if (pos.y < 0)
	{
		buf = pos.y * -1;
		srcAddr += srcSize.width * buf * srcDotSize;
		height -= buf;
	}
	else
	{
		desAddr += mSize.width * pos.y * mDotSize;
	}

	// 소스 이미지의 크기가 대상보다 크면 대상에 맞게 크기 조정 
	buf = (pos.y + height) - mSize.height;
	if (buf > 0)
	{
		height -= buf;
	}

	// X 좌표에 따른 대상의 이미지 시작 주소 계산
	if (pos.x < 0)
	{
		buf = pos.x * -1;
		srcAddr += buf * srcDotSize;
		width -= buf;
	}
	else
	{
		desAddr += pos.x * mDotSize;
	}

	srcOffset = srcSize.width - width;
	desOffset = mSize.width - width;

	if (width == 0 || height == 0)
		return;

	Dma2d::BlendConfig config = 
	{
		(void*)srcAddr,			//void *sourceAddress;
		(uint16_t)srcOffset,	//uint16_t sourceOffset;
		bitmapColorMode,		//uint8_t sourceColorMode;

		(void*)desAddr,			//void *destinationAddress;
		(uint16_t)desOffset,	//uint16_t destinationOffset;
		mColorMode,				//uint8_t destinationColorMode;

		{width, height}			//Size_t size;
	};

	dma2d.lock();
	dma2d.blend(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void Painter::fillRectBase(Position_t pos, Size_t size, uint32_t color)
{
	using namespace define::dma2d;
	int16_t offset;
	uint8_t *fb = mFrameBuffer;

	if(mFrameBuffer == 0 || mSize.height <= 0 || mSize.width <= 0 || size.width <= 0 || size.height <= 0)
		return;
	
	offset = mSize.width - size.width;
	fb += (pos.y * mSize.width + pos.x) * mDotSize;

	Dma2d::FillConfig config = 
	{
		(void*)fb,		//void *address;
		color,			//uint32_t color;
		mColorMode,		//uint8_t colorMode;
		offset,			//int16_t destinationOffset;
		size			//Size_t size;
	};
	
	dma2d.lock();
	dma2d.fill(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

uint8_t Painter::drawChar(Position_t pos, uint32_t utf8)
{
	if (mFont == 0)
		return 0;

	Font::fontInfo_t *fontInfo = mFont->getFontInfo(utf8);
	uint16_t desOffset, srcOffset, buf, xoffset;
	uint8_t *desAddr, *srcAddr;
	Size_t srcSize;
	
	if(fontInfo == 0)
		return 0;

	srcSize = Size_t{fontInfo->width, fontInfo->height};
	if(srcSize.width & 0x01)
		srcSize.width += 1;
	
	xoffset = fontInfo->xpos;
	if(xoffset == 0)
		xoffset = 1;

	pos.x += xoffset;

	if (pos.x >= mSize.width || pos.y >= mSize.height)
		return 0;

	if (pos.x + srcSize.width > mSize.width)
	{
		buf = srcSize.width;
		srcSize.width = mSize.width - pos.x;
		srcOffset = buf - srcSize.width;
	}
	else
		srcOffset = 0;

	if (pos.y + srcSize.height > mSize.height)
		srcSize.height = mSize.height - pos.y;

	desOffset = mSize.width - srcSize.width;

	desAddr = mFrameBuffer;
	if (desAddr == 0)
		return 0;

	desAddr += (mSize.width * (pos.y + fontInfo->ypos) + (pos.x + xoffset)) * mDotSize;

	srcAddr = (uint8_t *)fontInfo->data;
	if (srcAddr == 0)
		return 0;

	using namespace define::dma2d;
	Dma2d::DrawCharConfig config = 
	{
		(void*)srcAddr,			//void *sourceAddress;
		(uint16_t)srcOffset,	//uint16_t sourceOffset;
		colorMode::A4,			//uint8_t sourceColorMode;

		(void*)desAddr,			//void *destinationAddress;
		(uint16_t)desOffset,	//uint16_t destinationOffset;
		mColorMode,				//uint8_t destinationColorMode;

		srcSize,				//Size_t size;
		mFontColorCode			//uint32_t color;
	};
	
	dma2d.lock();
	dma2d.drawCharacter(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();

	return fontInfo->width + xoffset;
}

void Painter::drawObjectToPartialArea(Position_t pos, Size_t size, Object *src)
{
	Position_t srcPos = src->getPosition();
	Size_t srcSize = src->getSize();
	Brush *srcFb = src->getFrameBuffer();
	uint16_t height = srcSize.height, width, srcOffset = 0, desOffset = 0;
	int32_t buf;
	uint8_t *desAddr, *srcAddr;
	int32_t srcDotSize = srcFb->getDotSize();

	desAddr = (uint8_t *)mFrameBuffer;
	srcAddr = (uint8_t *)srcFb->getFrameBuffer();

	// 데이터 유효성 검사
	if (desAddr == 0 || 
		srcAddr == 0 ||
		srcPos.x > pos.x + size.width ||
		srcPos.y > pos.y + size.height ||
		srcPos.x + srcSize.width < pos.x ||
		srcPos.y + srcSize.height < pos.y)
		return;

	// Y 좌표에 따른 대상의 이미지 시작 주소 계산
	buf = pos.y - srcPos.y;
	if (buf > 0)
	{
		srcAddr += srcSize.width * buf * srcDotSize;
		height -= buf;
	}
	else
	{
		desAddr -= mSize.width * buf * mDotSize;
	}

	// 소스 이미지의 크기가 대상보다 크면 대상에 맞게 크기 조정 
	buf = (srcPos.y + srcSize.height) - (pos.y + size.height);
	if (buf > 0)
	{
		height -= buf;
	}

	// X 좌표에 따른 대상의 이미지 시작 주소 계산
	buf = pos.x - srcPos.x;
	if (srcPos.x < pos.x)
	{
		srcAddr += buf * srcDotSize;
		srcOffset += buf;
	}
	else
	{
		desAddr -= buf * mDotSize;
	}

	buf = (srcPos.x + srcSize.width) - (pos.x + size.width);
	if (buf > 0)
	{
		srcOffset += buf;
	}

	width = srcSize.width - srcOffset;
	desOffset = mSize.width - width;
	desAddr += (pos.y * mSize.width + pos.x) * mDotSize;

	if (width == 0 || height == 0)
		return;

	using namespace define::dma2d;
	Dma2d::BlendConfig config = 
	{
		(void*)srcAddr,			//void *sourceAddress;
		(uint16_t)srcOffset,	//uint16_t sourceOffset;
		srcFb->getColorMode(),	//uint8_t sourceColorMode;

		(void*)desAddr,			//void *destinationAddress;
		(uint16_t)desOffset,	//uint16_t destinationOffset;
		mColorMode,				//uint8_t destinationColorMode;

		{width, height}			//Size_t size;
	};
	
	dma2d.lock();
	dma2d.blend(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void Painter::drawPainter(Position_t pos, Painter *src)
{
	using namespace define::dma2d;

	if(mFrameBuffer == 0 || src == 0)
		return;
	
	Size_t srcSize = src->getSize();
	uint16_t height = srcSize.height, width = srcSize.width, srcOffset = 0, desOffset = 0;
	int32_t buf;
	uint8_t *desAddr, *srcAddr;
	int32_t srcDotSize = src->getDotSize();

	desAddr = (uint8_t *)mFrameBuffer;
	if (desAddr == 0)
		return;

	srcAddr = (uint8_t *)src->getFrameBuffer();
	if (srcAddr == 0)
		return;

	// 좌표가 대상 밖이면 리턴
	if (pos.x > mSize.width ||
		pos.y > mSize.height ||
		pos.x + srcSize.width < 0 ||
		pos.y + srcSize.height < 0)
		return;

	// Y 좌표에 따른 대상의 이미지 시작 주소 계산
	if (pos.y < 0)
	{
		buf = pos.y * -1;
		srcAddr += srcSize.width * buf * srcDotSize;
		height -= buf;
	}
	else
	{
		desAddr += mSize.width * pos.y * mDotSize;
	}

	// 소스 이미지의 크기가 대상보다 크면 대상에 맞게 크기 조정 
	buf = (pos.y + height) - mSize.height;
	if (buf > 0)
	{
		height -= buf;
	}

	// X 좌표에 따른 대상의 이미지 시작 주소 계산
	if (pos.x < 0)
	{
		buf = pos.x * -1;
		srcAddr += buf * srcDotSize;
		width -= buf;
	}
	else
	{
		desAddr += pos.x * mDotSize;
	}

	srcOffset = srcSize.width - width;
	desOffset = mSize.width - width;

	if (width == 0 || height == 0)
		return;

	Dma2d::BlendConfig config = 
	{
		(void*)srcAddr,			//void *sourceAddress;
		(uint16_t)srcOffset,	//uint16_t sourceOffset;
		src->getColorMode(),	//uint8_t sourceColorMode;

		(void*)desAddr,			//void *destinationAddress;
		(uint16_t)desOffset,	//uint16_t destinationOffset;
		mColorMode,				//uint8_t destinationColorMode;

		{width, height}			//Size_t size;
	};

	dma2d.lock();
	dma2d.blend(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

#endif

