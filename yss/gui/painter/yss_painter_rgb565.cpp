////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <drv/peripheral.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <gui/Rgb565.h>
#include <yss/instance.h>
#include <yss/thread.h>

namespace Painter
{
inline void swapStartPosition(short &startPos, short &endPos)
{
	short buf;

	if (startPos > endPos)
	{
		buf = startPos;
		startPos = endPos;
		endPos = buf;
	}
}

void fill(Rgb565 &obj, RGB565_union color)
{
	unsigned int fb = (unsigned int)obj.getFrameBuffer();

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
		(void*)fb,			//void *address;
		color.halfword,		//unsigned int color;
		colorMode::RGB565,	//unsigned char colorMode;
		size				//Size size;
	};
	
	dma2d.lock();
	dma2d.fill(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void fillRectangle(Rgb565 &obj, Position sp, Position ep, RGB565_union color)
{
	unsigned char *desAddr;

	swapStartPosition(sp.x, ep.x);
	swapStartPosition(sp.y, ep.y);

	Size desSize = obj.getSize();

	if (sp.x >= desSize.width || sp.y >= desSize.height)
		return;

	if (desSize.width <= ep.x)
		ep.x = desSize.width;
	if (desSize.height <= ep.y)
		ep.y = desSize.height;

	Size srcSize = {(unsigned short)(ep.x - sp.x), (unsigned short)(ep.y - sp.y)};

	desAddr = (unsigned char *)obj.getFrameBuffer();
	if (desAddr == 0)
		return;

	desAddr = &desAddr[desSize.width * sp.y * 2 + sp.x * 2];

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

void fillRectangle(Rgb565 &obj, Position pos, Size size, RGB565_union color)
{
	unsigned char *desAddr;

	if (size.width == 0 || size.height == 0)
		return;

	Size desSize = obj.getSize();

	if (pos.x >= desSize.width || pos.y >= desSize.height)
		return;

	if (pos.x + size.width >= desSize.width)
		size.width = desSize.width - pos.x;
	if (pos.y + size.height >= desSize.height)
		size.height = desSize.height - pos.y;

	desAddr = (unsigned char *)obj.getFrameBuffer();
	if (desAddr == 0)
		return;

	desAddr = &desAddr[desSize.width * pos.y * 2 + pos.x * 2];

	using namespace define::dma2d;
	Dma2d::FillConfig config = 
	{
		(void*)desAddr,		//void *address;
		color.halfword,		//unsigned int color;
		colorMode::RGB565,	//unsigned char colorMode;
		size				//Size size;
	};
	
	dma2d.lock();
	dma2d.fill(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

unsigned char drawChar(Rgb565 &des, Font *font, unsigned int utf8, Position pos, unsigned int color, unsigned char alpha)
{
	if (font->setChar(utf8))
		return 0;

	YssFontInfo *fontInfo = font->getFontInfo();
	unsigned short desOffset, srcOffset, buf;
	unsigned short *desAddr, *srcAddr;
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

	desAddr = (unsigned short *)des.getFrameBuffer();
	if (desAddr == 0)
		return 0;

	desAddr += desSize.width * (pos.y + fontInfo->ypos) + pos.x;

	srcAddr = (unsigned short *)font->getFrameBuffer();
	if (srcAddr == 0)
		return 0;

	using namespace define::dma2d;
	Dma2d::DrawCharConfig config = 
	{
		(void*)srcAddr,				//void *sourceAddress;
		(unsigned short)srcOffset,	//unsigned short sourceOffset;
		colorMode::A4,				//unsigned char sourceColorMode;

		(void*)desAddr,				//void *destinationAddress;
		(unsigned short)desOffset,	//unsigned short destinationOffset;
		colorMode::RGB565,			//unsigned char destinationColorMode;

		Size{srcSize}				//Size size;
	};
	
	dma2d.lock();
	dma2d.drawCharacter(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();

	return srcSize.width;
}

void draw(Rgb565 &des, Rgb565 &src, Position pos)
{
	unsigned short desOffset, srcOffset, buf;
	unsigned short *desAddr, *srcAddr;
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

	desAddr = (unsigned short *)des.getFrameBuffer();
	if (desAddr == 0)
		return;
	desAddr = &desAddr[pos.y * desSize.width + pos.x];

	srcAddr = (unsigned short *)src.getFrameBuffer();
	if (srcAddr == 0)
		return;

	using namespace define::dma2d;
	Dma2d::CopyConfig config = 
	{
		(void*)srcAddr,		//void *sourceAddress;
		(unsigned short)srcOffset,			//unsigned short sourceOffset;
		colorMode::RGB565,	//unsigned char sourceColorMode;

		(void*)desAddr,		//void *destinationAddress;
		(unsigned short)desOffset,			//unsigned short destinationOffset;
		colorMode::RGB565,	//unsigned char destinationColorMode;

		Size{srcSize}		//Size size;
	};
	
	dma2d.lock();
	dma2d.copy(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void drawArea(Rgb565 &des, Position areaPos, Size areaSize, Rgb565 &src, Position srcPos)
{
	Size desSize = des.getSize(), srcSize = src.getSize();
	short height = srcSize.height, width, srcOffset = 0, desOffset = 0;
	signed short buf;
	unsigned short *desAddr, *srcAddr;

	desAddr = (unsigned short *)des.getFrameBuffer();
	if (desAddr == 0)
		return;

	srcAddr = (unsigned short *)src.getFrameBuffer();
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
		srcAddr += srcSize.width * buf;
		height -= buf;
	}
	else
	{
		desAddr -= desSize.width * buf;
	}

	buf = (srcPos.y + srcSize.height) - (areaPos.y + areaSize.height);
	if (buf > 0)
	{
		height -= buf;
	}

	buf = areaPos.x - srcPos.x;
	if (srcPos.x < areaPos.x)
	{
		srcAddr += buf;
		srcOffset += buf;
	}
	else
	{
		desAddr -= buf;
	}

	buf = (srcPos.x + srcSize.width) - (areaPos.x + areaSize.width);
	if (buf > 0)
	{
		srcOffset += buf;
	}

	width = srcSize.width - srcOffset;
	desOffset = desSize.width - width;
	desAddr += areaPos.y * desSize.width + areaPos.x;

	if (width == 0 || height == 0)
		return;

	using namespace define::dma2d;
	Dma2d::CopyConfig config = 
	{
		(void*)srcAddr,		//void *sourceAddress;
		(unsigned short)srcOffset,			//unsigned short sourceOffset;
		colorMode::RGB565,	//unsigned char sourceColorMode;

		(void*)desAddr,		//void *destinationAddress;
		(unsigned short)desOffset,			//unsigned short destinationOffset;
		colorMode::RGB565,	//unsigned char destinationColorMode;

		Size{width, height}	//Size size;
	};
	
	dma2d.lock();
	dma2d.copy(config);
	dma2d.waitUntilComplete();
	dma2d.unlock();
}

void draw(Rgb565 &des, const Bmp565 *bmp, Position pos)
{
	unsigned short desOffset, srcOffset, buf;
	unsigned short *desAddr, *srcAddr;
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

	desAddr = (unsigned short *)des.getFrameBuffer();
	if (desAddr == 0)
		return;
	desAddr = &desAddr[pos.y * desSize.width + pos.x];

	srcAddr = (unsigned short *)bmp->data;
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
}

#endif

