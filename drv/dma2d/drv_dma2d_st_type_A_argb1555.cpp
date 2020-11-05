////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripherals.h>

#if defined(DMA2D) && USE_GUI == true
/*
#include <yss/thread.h>
#include <yss/gui.h>
#include <drv/dma2d/drv_st_dma2d_type_A_register.h>

extern const unsigned char yssSysFont[1161152];

namespace drv
{
	extern Mutex gMutex;

	extern FontSize *gFontSize;
	extern signed char *gFontYPos;
	extern unsigned long *gFontPointer;
	extern unsigned char *gFontBase;

	inline void swapPos(signed short &startPos, signed short &endPos)
	{
		unsigned short buf;

		if(startPos > endPos)
		{
			buf = startPos;
			startPos = endPos;
			endPos = buf;
		}
	}

	void Dma2d::fill(Argb1555 &obj, ARGB1555_union color)
	{
		unsigned long key = gMutex.lock();
		unsigned long fb = (unsigned long)obj.getFrameBuffer();

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
		unsigned long key = gMutex.lock();
		unsigned short buf;

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

		Size srcSize = {(unsigned short)(ep.x-sp.x), (unsigned short)(ep.y-sp.y)};

		unsigned char *desAddr = (unsigned char*)obj.getFrameBuffer();
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
		unsigned long key = gMutex.lock();
		unsigned short buf;

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

		unsigned char *desAddr = (unsigned char*)obj.getFrameBuffer();
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

	signed char inner_drawChar(Argb1555 &des, unsigned short code, Pos pos)
	{
		unsigned long key = gMutex.lock();
		signed char fontWidth = (signed char)gFontSize[code].width;
		unsigned char *desAddr;
		unsigned short desOffset, srcOffset;
		unsigned long srcAddr;

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

		desAddr = (unsigned char*)des.getFrameBuffer();
		if(desAddr == 0)
		{
			gMutex.unlock();
			return 0;
		}
		desAddr = &desAddr[desSize.width*pos.y*2+pos.x*2];

		desOffset = desSize.width - srcSize.width;
		srcAddr = (unsigned long)&yssSysFont[gFontPointer[code]];

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

	char Dma2d::drawChar(Argb1555 &des, char *ch, Pos pos)
	{
		return inner_drawChar(des, convertUtf8ToUtf16(ch), pos);
	}

	char Dma2d::drawChar(Argb1555 &des, char ch, Pos pos)
	{
		return inner_drawChar(des, convertUtf8ToUtf16(&ch), pos);
	}

	void Dma2d::draw(Argb1555 &des, Argb1555 &src, Pos pos)
	{
		unsigned long key = gMutex.lock();
		unsigned short desOffset, srcOffset, buf;
		unsigned short *desAddr, *srcAddr;
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

		desAddr = (unsigned short*)des.getFrameBuffer();
		if(desAddr == 0)
		{
			gMutex.unlock();
			return;
		}

		desAddr = &desAddr[pos.y*desSize.width+pos.x];

		srcAddr = (unsigned short*)src.getFrameBuffer();
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
