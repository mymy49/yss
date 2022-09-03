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

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F7)
/*
#include <drv/dma2d/drv_st_dma2d_type_A.h>
#include <drv/dma2d/drv_st_dma2d_type_A_register.h>
#include <yss/thread.h>

extern const uint8_t yssSysFont[1161152];

namespace drv
{
	extern Mutex gMutex;

	extern FontSize *gFontSize;
	extern int8_t *gFontYPos;
	extern uint32_t *gFontPointer;
	extern uint8_t *gFontBase;

	inline void swapPos(int16_t &startPos, int16_t &endPos)
	{
		uint16_t buf;

		if(startPos > endPos)
		{
			buf = startPos;
			startPos = endPos;
			endPos = buf;
		}
	}

	void Dma2d::fill(Argb1555 &obj, ARGB1555_union color)
	{
		uint32_t key = gMutex.lock();
		uint32_t fb = (uint32_t)obj.getFrameBuffer();

		if(fb == 0)
		{
			gMutex.unlock();
			return;
		}

		Size size = obj.getSize();
		if(size.height == 0 || size.width == 0)
		{
			gMutex.unlock();
			return;
		}

		setDma2dMode(define::dma2d::mode::REG_TO_MEM);
		setDma2dOutputColorMode(define::dma2d::colorMode::ARGB1555);
		setDma2dOutputColor(color.data);
		setDma2dOmar(fb);
		setDma2dNumOfLine(size.height);
		setDma2dNumOfPixel(size.width);
		setDma2dOutputLineOffset(0);
		setDma2dStart();

		gMutex.wait(key);
	}

	void Dma2d::fillRectangle(Argb1555 &obj, Pos sp, Pos ep, ARGB1555_union color)
	{
		uint32_t key = gMutex.lock();
		uint16_t buf;

		swapPos(sp.x, ep.x);
		swapPos(sp.y, ep.y);

		Size desSize = obj.getSize();

		if(sp.x >= desSize.width || sp.y >= desSize.height)
		{
			gMutex.unlock();
			return;
		}

		if(desSize.width <= ep.x)
			ep.x = desSize.width;
		if(desSize.height <= ep.y)
			ep.y = desSize.height;

		Size srcSize = {(uint16_t)(ep.x-sp.x), (uint16_t)(ep.y-sp.y)};

		uint8_t *desAddr = (uint8_t*)obj.getFrameBuffer();
		if(desAddr == 0)
		{
			gMutex.unlock();
			return;
		}

		desAddr = &desAddr[desSize.width*sp.y*2+sp.x*2];

		setDma2dMode(define::dma2d::mode::REG_TO_MEM);
		setDma2dOutputColorMode(define::dma2d::colorMode::ARGB1555);
		setDma2dOutputColor(color.data);
		setDma2dOmar(desAddr);
		setDma2dNumOfLine(srcSize.height);
		setDma2dNumOfPixel(srcSize.width);
		setDma2dOutputLineOffset(desSize.width - srcSize.width);
		setDma2dStart();

		gMutex.wait(key);
	}

	void Dma2d::fillRectangle(Argb1555 &obj, Pos pos, Size size, ARGB1555_union color)
	{
		uint32_t key = gMutex.lock();
		uint16_t buf;

		Size desSize = obj.getSize();

		if(pos.x >= desSize.width || pos.y >= desSize.height)
		{
			gMutex.unlock();
			return;
		}

		if(pos.x + size.width >= desSize.width)
			size.width = desSize.width - pos.x;
		if(pos.y + size.height >= desSize.height)
			size.height = desSize.height - pos.y;

		uint8_t *desAddr = (uint8_t*)obj.getFrameBuffer();
		if(desAddr == 0)
		{
			gMutex.unlock();
			return;
		}

		desAddr = &desAddr[desSize.width*pos.y*2+pos.x*2];

		setDma2dMode(define::dma2d::mode::REG_TO_MEM);
		setDma2dOutputColorMode(define::dma2d::colorMode::ARGB1555);
		setDma2dOutputColor(color.data);
		setDma2dOmar(desAddr);
		setDma2dNumOfLine(size.height);
		setDma2dNumOfPixel(size.width);
		setDma2dOutputLineOffset(desSize.width - size.width);
		setDma2dStart();

		gMutex.wait(key);
	}

	int8_t inner_drawChar(Argb1555 &des, uint16_t code, Pos pos)
	{
		uint32_t key = gMutex.lock();
		int8_t fontWidth = (int8_t)gFontSize[code].width;
		uint8_t *desAddr;
		uint16_t desOffset, srcOffset;
		uint32_t srcAddr;

		if(!fontWidth)
		{
			gMutex.unlock();
			return yssSysFont[0] * (float)0.3;
		}
		fontWidth += 1;

		Size desSize = des.getSize(), srcSize;

		if(pos.x >= desSize.width || pos.y >= desSize.height)
		{
			gMutex.unlock();
			return 0;
		}

		if(pos.x + gFontSize[code].width > desSize.width)
		{
			srcSize.width = desSize.width - pos.x;
			if(srcSize.width %2)
			{
				srcSize.width--;
				if(srcSize.width == 0)
				{
					gMutex.unlock();
					return 0;
				}
			}
			srcOffset = gFontSize[code].width - srcSize.width;
		}
		else
		{
			srcSize.width = gFontSize[code].width;
			srcOffset = 0;
		}

		pos.y -= gFontYPos[code];
		if(pos.y < 0)
			pos.y = 0;

		if(pos.y + gFontSize[code].height > desSize.height)
		{
			srcSize.height = desSize.height - pos.y;
		}
		else
		{
			srcSize.height = gFontSize[code].height;
		}

		desAddr = (uint8_t*)des.getFrameBuffer();
		if(desAddr == 0)
		{
			gMutex.unlock();
			return 0;
		}
		desAddr = &desAddr[desSize.width*pos.y*2+pos.x*2];

		desOffset = desSize.width - srcSize.width;
		srcAddr = (uint32_t)&yssSysFont[gFontPointer[code]];

		setDma2dMode(define::dma2d::mode::MEM_TO_MEM_BLENDING);
		setDma2dFgmar(srcAddr);
		setDma2dBgmar(desAddr);
		setDma2dOmar(desAddr);

		setDma2dFgAlpha(0xff);
		setDma2dFgAlphaMode(0);
		setDma2dFgColorMode(define::dma2d::colorMode::A4);
		setDma2dBgAlpha(0xff);
		setDma2dBgAlphaMode(0);
		setDma2dBgColorMode(define::dma2d::colorMode::ARGB1555);
		setDma2dOutputColorMode(define::dma2d::colorMode::ARGB1555);

		setDma2dNumOfLine(srcSize.height);
		setDma2dNumOfPixel(srcSize.width);

		setDma2dFgLineOffset(srcOffset);
		setDma2dBgLineOffset(desOffset);
		setDma2dOutputLineOffset(desOffset);
		setDma2dStart();

		gMutex.wait(key);

		return fontWidth;
	}

	int8_t Dma2d::drawChar(Argb1555 &des, int8_t *ch, Pos pos)
	{
		return inner_drawChar(des, convertUtf8ToUtf16(ch), pos);
	}

	int8_t Dma2d::drawChar(Argb1555 &des, int8_t ch, Pos pos)
	{
		return inner_drawChar(des, convertUtf8ToUtf16(&ch), pos);
	}

	void Dma2d::draw(Argb1555 &des, Argb1555 &src, Pos pos)
	{
		uint32_t key = gMutex.lock();
		uint16_t desOffset, srcOffset, buf;
		uint16_t *desAddr, *srcAddr;
		Size desSize, srcSize;

		desSize = des.getSize();
		srcSize = src.getSize();

		if(pos.x >= desSize.width || pos.y >= desSize.height)
		{
			gMutex.unlock();
			return;
		}

		if(pos.x + srcSize.width > desSize.width)
		{
			buf = srcSize.width;
			srcSize.width = desSize.width - pos.x;
			srcOffset = buf - srcSize.width;
		}
		else
		{
			srcOffset = 0;
		}

		if(pos.y + srcSize.height > desSize.height)
		{
			srcSize.height = desSize.height - pos.y;
		}

		desOffset = desSize.width - srcSize.width;

		desAddr = (uint16_t*)des.getFrameBuffer();
		if(desAddr == 0)
		{
			gMutex.unlock();
			return;
		}

		desAddr = &desAddr[pos.y*desSize.width+pos.x];

		srcAddr = (uint16_t*)src.getFrameBuffer();
		if(srcAddr == 0)
		{
			gMutex.unlock();
			return;
		}

		setDma2dFgmar(srcAddr);
		setDma2dFgColorMode(define::dma2d::colorMode::ARGB1555);
		setDma2dFgLineOffset(srcOffset);
		setDma2dFgAlphaMode(1);

		setDma2dBgmar(desAddr);
		setDma2dBgColorMode(define::dma2d::colorMode::ARGB1555);
		setDma2dBgLineOffset(desOffset);

		setDma2dMode(define::dma2d::mode::MEM_TO_MEM_BLENDING);
		setDma2dFgAlpha(src.getAlpha());

		setDma2dOmar(desAddr);
		setDma2dOutputColorMode(define::dma2d::colorMode::ARGB1555);
		setDma2dNumOfLine(srcSize.height);
		setDma2dNumOfPixel(srcSize.width);
		setDma2dOutputLineOffset(desOffset);
		setDma2dStart();

		gMutex.wait(key);
	}
}
*/
#endif