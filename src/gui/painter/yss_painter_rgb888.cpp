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

#if USE_GUI && defined(DMA2D_ENABLE)

#include <yss/instance.h>

#if !defined(YSS_DRV_DMA2D_UNSUPPORTED)

#include <gui/Rgb565.h>
#include <gui/Rgb888.h>
#include <gui/Bmp888.h>
#include <gui/Bmp565.h>
#include <yss/thread.h>

namespace Painter
{
inline void swapStartPosition(int16_t &startPos, int16_t &endPos)
{
	int16_t buf;

	if (startPos > endPos)
	{
		buf = startPos;
		startPos = endPos;
		endPos = buf;
	}
}

void fill(Rgb888 &obj, Color color)
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
		color.getRgb888Code(),	//uint32_t color;
		colorMode::RGB888,		//uint8_t colorMode;
		0,						//int16_t destinationOffset;
		size					//Size size;
	};
	
	dma2d.lock();
	dma2d.fill(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void fillRectangle(Rgb888 &obj, Position sp, Position ep, Color color)
{
	uint8_t *desAddr;

	swapStartPosition(sp.x, ep.x);
	swapStartPosition(sp.y, ep.y);

	Size desSize = obj.getSize();

	if (sp.x >= desSize.width || sp.y >= desSize.height)
		return;

	if (desSize.width <= ep.x)
		ep.x = desSize.width;
	if (desSize.height <= ep.y)
		ep.y = desSize.height;

	Size srcSize = {(uint16_t)(ep.x - sp.x), (uint16_t)(ep.y - sp.y)};

	desAddr = (uint8_t *)obj.getFrameBuffer();
	if (desAddr == 0)
		return;

	desAddr = &desAddr[desSize.width * sp.y * 3 + sp.x * 3];

	//mMutex.lock();
	//setDma2dMode(define::dma2d::mode::REG_TO_MEM);
	//setDma2dOutputColorMode(define::dma2d::colorMode::RGB565);
	//setDma2dOutputColor(color.halfword);
	//setDma2dOmar(desAddr);
	//setDma2dNumOfLine(srcSize.height);
	//setDma2dNumOfPixel(srcSize.width);
	//setDma2dOutputLineOffset(desSize.width - srcSize.width);
	//setDma2dStart();

	//while (getDma2dTcif() == false)
	//	thread::yield();

	//clrDma2dTcif();

	//mMutex.unlock();
}

void fillRectangle(Rgb888 &obj, Position pos, Size size, Color color)
{
	uint8_t *desAddr;

	if (size.width == 0 || size.height == 0)
		return;

	Size desSize = obj.getSize();

	if (pos.x >= desSize.width || pos.y >= desSize.height)
		return;

	if (pos.x + size.width >= desSize.width)
		size.width = desSize.width - pos.x;
	if (pos.y + size.height >= desSize.height)
		size.height = desSize.height - pos.y;

	desAddr = (uint8_t *)obj.getFrameBuffer();
	if (desAddr == 0)
		return;

	desAddr = &desAddr[desSize.width * pos.y * 3 + pos.x * 3];

	using namespace define::dma2d;
	Dma2d::FillConfig config = 
	{
		(void*)desAddr,				//void *address;
		color.getRgb888Code(),		//uint32_t color;
		colorMode::RGB888,			//uint8_t colorMode;
		desSize.width - size.width,	//int16_t destinationOffset;
		size						//Size size;
	};
	
	dma2d.lock();
	dma2d.fill(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

uint8_t drawChar(Rgb888 &des, Font *font, uint32_t utf8, Position pos, Color color)
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
		colorMode::RGB888,		//uint8_t destinationColorMode;

		Size{srcSize},			//Size size;
		color.getRgb888Code()	//uint32_t color;
	};
	
	dma2d.lock();
	dma2d.drawCharacter(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();

	return srcSize.width;
}

void draw(Rgb888 &des, Rgb888 &src, Position pos)
{
	uint16_t desOffset, srcOffset, buf;
	uint8_t *desAddr, *srcAddr;
	Size desSize, srcSize;

	desSize = des.getSize();
	srcSize = src.getSize();

	if (pos.x >= desSize.width || pos.y >= desSize.height)
		return;

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
		return;
	desAddr = &desAddr[pos.y * desSize.width * 3 + pos.x * 3];

	srcAddr = (uint8_t *)src.getFrameBuffer();
	if (srcAddr == 0)
		return;

	using namespace define::dma2d;
	Dma2d::CopyConfig config = 
	{
		(void*)srcAddr,		//void *sourceAddress;
		(uint16_t)srcOffset,			//uint16_t sourceOffset;
		colorMode::RGB888,	//uint8_t sourceColorMode;

		(void*)desAddr,		//void *destinationAddress;
		(uint16_t)desOffset,			//uint16_t destinationOffset;
		colorMode::RGB888,	//uint8_t destinationColorMode;

		Size{srcSize}		//Size size;
	};
	
	dma2d.lock();
	dma2d.copy(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void drawArea(Rgb888 &des, Position areaPos, Size areaSize, Rgb888 &src, Position srcPos)
{
	Size desSize = des.getSize(), srcSize = src.getSize();
	uint16_t height = srcSize.height, width, srcOffset = 0, desOffset = 0;
	int16_t buf;
	uint8_t *desAddr, *srcAddr;

	desAddr = (uint8_t *)des.getFrameBuffer();
	if (desAddr == 0)
		return;

	srcAddr = (uint8_t *)src.getFrameBuffer();
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
		srcAddr += srcSize.width * buf * 3;
		height -= buf;
	}
	else
	{
		desAddr -= desSize.width * buf * 3;
	}

	buf = (srcPos.y + srcSize.height) - (areaPos.y + areaSize.height);
	if (buf > 0)
	{
		height -= buf;
	}

	buf = areaPos.x - srcPos.x;
	if (srcPos.x < areaPos.x)
	{
		srcAddr += buf * 3;
		srcOffset += buf;
	}
	else
	{
		desAddr -= buf * 3;
	}

	buf = (srcPos.x + srcSize.width) - (areaPos.x + areaSize.width);
	if (buf > 0)
	{
		srcOffset += buf;
	}

	width = srcSize.width - srcOffset;
	desOffset = desSize.width - width;
	desAddr += areaPos.y * desSize.width * 3 + areaPos.x * 3;

	if (width == 0 || height == 0)
		return;

	using namespace define::dma2d;
	Dma2d::CopyConfig config = 
	{
		(void*)srcAddr,		//void *sourceAddress;
		(uint16_t)srcOffset,			//uint16_t sourceOffset;
		colorMode::RGB888,	//uint8_t sourceColorMode;

		(void*)desAddr,		//void *destinationAddress;
		(uint16_t)desOffset,			//uint16_t destinationOffset;
		colorMode::RGB888,	//uint8_t destinationColorMode;

		Size{width, height}	//Size size;
	};
	
	dma2d.lock();
	dma2d.copy(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void draw(Rgb888 &des, const Bmp888 *bmp, Position pos)
{
	uint16_t desOffset, srcOffset, buf;
	uint8_t *desAddr, *srcAddr;
	Size desSize, srcSize;

	desSize = des.getSize();
	srcSize = Size{bmp->width, bmp->height};

	if (pos.x >= desSize.width || pos.y >= desSize.height)
		return;

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
		return;
	desAddr = &desAddr[pos.y * desSize.width * 3 + pos.x * 3];

	srcAddr = (uint8_t *)bmp->data;
	if (srcAddr == 0)
		return;

	//mMutex.lock();
	//setDma2dFgmar(srcAddr);
	//setDma2dFgColorMode(define::dma2d::colorMode::RGB565);
	//setDma2dFgLineOffset(srcOffset);
	//setDma2dFgAlphaMode(1);

	//setDma2dBgmar(desAddr);
	//setDma2dBgColorMode(define::dma2d::colorMode::RGB565);
	//setDma2dBgLineOffset(desOffset);

	//setDma2dMode(define::dma2d::mode::MEM_TO_MEM);

	//setDma2dOmar(desAddr);
	//setDma2dOutputColorMode(define::dma2d::colorMode::RGB565);
	//setDma2dNumOfLine(srcSize.height);
	//setDma2dNumOfPixel(srcSize.width);
	//setDma2dOutputLineOffset(desOffset);
	//setDma2dStart();

	//while (getDma2dTcif() == false)
	//	thread::yield();
	//clrDma2dTcif();

	//mMutex.unlock();
}

void draw(Rgb888 &des, const Bmp565 *bmp, Position pos)
{
	uint16_t desOffset, srcOffset, buf;
	uint8_t *desAddr;
	uint16_t *srcAddr, width, height;
	Size desSize, srcSize;

	desSize = des.getSize();
	srcSize = Size{bmp->width, bmp->height};

	if (pos.x >= desSize.width || pos.y >= desSize.height)
		return;

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
		return;
	desAddr = &desAddr[pos.y * desSize.width * 3 + pos.x * 3];

	srcAddr = (uint16_t *)bmp->data;
	if (srcAddr == 0)
		return;

	using namespace define::dma2d;
	Dma2d::BlendConfig config = 
	{
		(void*)srcAddr,		//void *sourceAddress;
		(uint16_t)srcOffset,//uint16_t sourceOffset;
		colorMode::RGB565,	//uint8_t sourceColorMode;

		(void*)desAddr,		//void *destinationAddress;
		(uint16_t)desOffset,//uint16_t destinationOffset;
		colorMode::RGB888,	//uint8_t destinationColorMode;

		srcSize	//Size size;
	};
	
	dma2d.lock();
	dma2d.blend(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

}

#endif

#endif


