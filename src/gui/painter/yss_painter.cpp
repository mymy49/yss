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
/*
#include <yss/instance.h>

#include <gui/Rgb565.h>
#include <gui/Rgb888.h>
#include <gui/Bmp565.h>
#include <gui/painter.h>
#include <yss/thread.h>

namespace Painter
{
void fill(FrameBuffer &obj, uint32_t color)
{
	uint32_t fb = (uint32_t)obj.getFrameBuffer();

	if (fb == 0)
	{
		return;
	}

	Size size = obj.getSize();
	if (size.height == 0 || size.width == 0)
	{
		return;
	}
	
	using namespace define::dma2d;
	Dma2d::FillConfig config = 
	{
		(void*)fb,				//void *address;
		color,					//uint32_t color;
		obj.getColorMode(),		//uint8_t colorMode;
		0,						//int16_t destinationOffset;
		size					//Size size;
	};
	
	dma2d.lock();
	dma2d.fill(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void drawArea(Object &des, Position areaPos, Size areaSize, Object &src)
{
//	drawArea(*des.getFrameBuffer(), areaPos, areaSize, *src.getFrameBuffer(), src.getPos());
	Position srcPos = src.getPosition();
	Size desSize = des.getSize(), srcSize = src.getSize();
	uint16_t height = srcSize.height, width, srcOffset = 0, desOffset = 0;
	int32_t buf;
	uint8_t *desAddr, *srcAddr;
	Brush *desFb = des.getFrameBuffer(), *srcFb = src.getFrameBuffer();
	int32_t desDotSize = desFb->getDotSize(), srcDotSize = srcFb->getDotSize();

	desAddr = (uint8_t *)desFb->getFrameBuffer();
	if (desAddr == 0)
		return;

	srcAddr = (uint8_t *)srcFb->getFrameBuffer();
	if (srcAddr == 0)
		return;

	if (
		srcPos.x > areaPos.x + areaSize.width ||
		srcPos.y > areaPos.y + areaSize.height ||
		srcPos.x + srcSize.width < areaPos.x ||
		srcPos.y + srcSize.height < areaPos.y)
		return;

	buf = areaPos.y - srcPos.y;
	if (buf > 0)
	{
		srcAddr += srcSize.width * buf * srcDotSize;
		height -= buf;
	}
	else
	{
		desAddr -= desSize.width * buf * desDotSize;
	}

	buf = (srcPos.y + srcSize.height) - (areaPos.y + areaSize.height);
	if (buf > 0)
	{
		height -= buf;
	}

	buf = areaPos.x - srcPos.x;
	if (srcPos.x < areaPos.x)
	{
		srcAddr += buf * srcDotSize;
		srcOffset += buf;
	}
	else
	{
		desAddr -= buf * desDotSize;
	}

	buf = (srcPos.x + srcSize.width) - (areaPos.x + areaSize.width);
	if (buf > 0)
	{
		srcOffset += buf;
	}

	width = srcSize.width - srcOffset;
	desOffset = desSize.width - width;
	desAddr += areaPos.y * desSize.width * desDotSize + areaPos.x * desDotSize;

	if (width == 0 || height == 0)
		return;

	using namespace define::dma2d;
	Dma2d::CopyConfig config = 
	{
		(void*)srcAddr,			//void *sourceAddress;
		(uint16_t)srcOffset,	//uint16_t sourceOffset;
		srcFb->getColorMode(),	//uint8_t sourceColorMode;

		(void*)desAddr,			//void *destinationAddress;
		(uint16_t)desOffset,	//uint16_t destinationOffset;
		desFb->getColorMode(),		//uint8_t destinationColorMode;

		Size{width, height}		//Size size;
	};
	
	dma2d.lock();
	dma2d.copy(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void drawBitmap(Brush &des, const Bitmap *bitmap, Position pos)
{
	using namespace define::dma2d;

	Size desSize = des.getSize(), srcSize = {bitmap->width, bitmap->height};
	uint16_t height = srcSize.height, width = srcSize.width, srcOffset = 0, desOffset = 0;
	int32_t buf;
	uint8_t *desAddr, *srcAddr, bitmapColorMode;
	int32_t desDotSize = des.getDotSize(), srcDotSize = 2;
	
	desAddr = (uint8_t *)des.getFrameBuffer();
	if (desAddr == 0)
		return;

	srcAddr = (uint8_t *)bitmap->data;
	if (srcAddr == 0)
		return;
	
	// 좌표가 대상 밖이면 리턴
	if (pos.x > desSize.width ||
		pos.y > desSize.height ||
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
		desAddr += desSize.width * pos.y * desDotSize;
	}
	
	// 소스 이미지의 크기가 대상보다 크면 대상에 맞게 크기 조정 
	buf = (pos.y + height) - desSize.height;
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
		desAddr += pos.x * desDotSize;
	}
	
	srcOffset = srcSize.width - width;
	desOffset = desSize.width - width;

	if (width == 0 || height == 0)
		return;

	switch(bitmap->type)
	{
	case 0 : // RGB565
		bitmapColorMode = colorMode::RGB565;
		break;
	
	case 1 : // RGB888
		bitmapColorMode = colorMode::RGB888;
		break;
	
	default :
		return;
	}

	Dma2d::BlendConfig config = 
	{
		(void*)srcAddr,			//void *sourceAddress;
		(uint16_t)srcOffset,	//uint16_t sourceOffset;
		bitmapColorMode,		//uint8_t sourceColorMode;

		(void*)desAddr,			//void *destinationAddress;
		(uint16_t)desOffset,	//uint16_t destinationOffset;
		des.getColorMode(),		//uint8_t destinationColorMode;

		{width, height}			//Size size;
	};
	
	dma2d.lock();
	dma2d.blend(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

uint8_t drawChar(FrameBuffer &des, Font *font, uint32_t utf8, Position pos, Color color)
{
	if (font->setChar(utf8))
		return 0;

	YssFontInfo *fontInfo = font->getFontInfo();
	uint16_t desOffset, srcOffset, buf;
	uint8_t *desAddr, *srcAddr;
	Size desSize, srcSize;

	desSize = des.getSize();
	srcSize = Size{fontInfo->width, fontInfo->height};

	if (pos.x >= desSize.width || pos.y >= desSize.height)
		return 0;

	if (pos.x + srcSize.width > desSize.width)
	{
		buf = srcSize.width;
		srcSize.width = desSize.width - pos.x;
		srcOffset = buf - srcSize.width;
	}
	else
		srcOffset = 0;

	if (pos.y + srcSize.height > desSize.height)
		srcSize.height = desSize.height - pos.y;

	desOffset = desSize.width - srcSize.width;

	desAddr = (uint8_t *)des.getFrameBuffer();
	if (desAddr == 0)
		return 0;

	desAddr += desSize.width * (pos.y + fontInfo->ypos) * 3 + pos.x *3;

	srcAddr = (uint8_t *)font->getFrameBuffer();
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
		des.getColorMode(),		//uint8_t destinationColorMode;

		Size{srcSize},			//Size size;
		color.getRgb888Code()	//uint32_t color;
	};
	
	dma2d.lock();
	dma2d.drawCharacter(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();

	return srcSize.width;
}

void draw(Object &des, Object &src)
{
//	draw(*des.getFrameBuffer(), *src.getFrameBuffer(), src.getPos());
}

}
*/
#endif

