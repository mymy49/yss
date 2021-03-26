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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/mcu.h>

#if defined(DMA2D)

#include <drv/dma2d/drv_st_dma2d_type_A.h>
#include <drv/dma2d/drv_st_dma2d_type_A_register.h>
#include <yss/thread.h>

namespace drv
{
inline void swapPos(signed short &startPos, signed short &endPos)
{
    unsigned short buf;

    if (startPos > endPos)
    {
        buf = startPos;
        startPos = endPos;
        endPos = buf;
    }
}

void Dma2d::fill(Rgb565 &obj, RGB565_union color)
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

    mMutex.lock();

    setDma2dMode(define::dma2d::mode::REG_TO_MEM);
    setDma2dOutputColorMode(define::dma2d::colorMode::RGB565);
    setDma2dOutputColor(color.halfword);
    setDma2dOmar(fb);
    setDma2dNumOfLine(size.height);
    setDma2dNumOfPixel(size.width);
    setDma2dOutputLineOffset(0);
    setDma2dStart();

    while (getDma2dTcif() == false)
        thread::yield();
    clrDma2dTcif();

    mMutex.unlock();
}

void Dma2d::fillRectangle(Rgb565 &obj, Pos sp, Pos ep, RGB565_union color)
{
    unsigned char *desAddr;

    swapPos(sp.x, ep.x);
    swapPos(sp.y, ep.y);

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

    mMutex.lock();
    setDma2dMode(define::dma2d::mode::REG_TO_MEM);
    setDma2dOutputColorMode(define::dma2d::colorMode::RGB565);
    setDma2dOutputColor(color.halfword);
    setDma2dOmar(desAddr);
    setDma2dNumOfLine(srcSize.height);
    setDma2dNumOfPixel(srcSize.width);
    setDma2dOutputLineOffset(desSize.width - srcSize.width);
    setDma2dStart();

    while (getDma2dTcif() == false)
        thread::yield();

    clrDma2dTcif();

    mMutex.unlock();
}

void Dma2d::fillRectangle(Rgb565 &obj, Pos pos, Size size, RGB565_union color)
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

    mMutex.lock();
    setDma2dMode(define::dma2d::mode::REG_TO_MEM);
    setDma2dOutputColorMode(define::dma2d::colorMode::RGB565);
    setDma2dOutputColor(color.halfword);
    setDma2dOmar(desAddr);
    setDma2dNumOfLine(size.height);
    setDma2dNumOfPixel(size.width);
    setDma2dOutputLineOffset(desSize.width - size.width);
    setDma2dStart();

    while (getDma2dTcif() == false)
        thread::yield();
    clrDma2dTcif();

    mMutex.unlock();
}

unsigned char Dma2d::drawChar(Rgb565 &des, Font *font, unsigned int utf8, Pos pos, unsigned int color, unsigned char alpha)
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

    mMutex.lock();
    DMA2D->FGMAR = (unsigned int)srcAddr;
    DMA2D->BGMAR = (unsigned int)desAddr;
    DMA2D->OMAR = (unsigned int)desAddr;
    DMA2D->FGCOLR = color;
    DMA2D->FGPFCCR = define::dma2d::colorMode::A4 | alpha << DMA2D_FGPFCCR_ALPHA_Pos;
    DMA2D->BGPFCCR = define::dma2d::colorMode::RGB565 | des.getAlpha() << DMA2D_FGPFCCR_ALPHA_Pos;
    DMA2D->OPFCCR = define::dma2d::colorMode::RGB565;
    DMA2D->NLR = srcSize.height << DMA2D_NLR_NL_Pos | srcSize.width << DMA2D_NLR_PL_Pos;
    DMA2D->FGOR = srcOffset;
    DMA2D->BGOR = desOffset;
    DMA2D->OOR = desOffset;
    DMA2D->CR = DMA2D_CR_START_Msk | (define::dma2d::mode::MEM_TO_MEM_BLENDING << DMA2D_CR_MODE_Pos);

    while (!(DMA2D->ISR & DMA2D_ISR_TCIF_Msk))
        thread::yield();

    DMA2D->IFCR |= DMA2D_IFCR_CTCIF_Msk;

    mMutex.unlock();

    return srcSize.width;
}

void Dma2d::draw(Rgb565 &des, Rgb565 &src, Pos pos)
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

    mMutex.lock();
    setDma2dFgmar(srcAddr);
    setDma2dFgColorMode(define::dma2d::colorMode::RGB565);
    setDma2dFgLineOffset(srcOffset);
    setDma2dFgAlphaMode(1);

    setDma2dBgmar(desAddr);
    setDma2dBgColorMode(define::dma2d::colorMode::RGB565);
    setDma2dBgLineOffset(desOffset);

    if (src.getAlpha() == 0xff)
    {
        setDma2dMode(define::dma2d::mode::MEM_TO_MEM);
    }
    else
    {
        setDma2dMode(define::dma2d::mode::MEM_TO_MEM_BLENDING);
        setDma2dFgAlpha(src.getAlpha());
    }

    setDma2dOmar(desAddr);
    setDma2dOutputColorMode(define::dma2d::colorMode::RGB565);
    setDma2dNumOfLine(srcSize.height);
    setDma2dNumOfPixel(srcSize.width);
    setDma2dOutputLineOffset(desOffset);
    setDma2dStart();

    while (getDma2dTcif() == false)
        thread::yield();
    clrDma2dTcif();

    mMutex.unlock();
}

void Dma2d::drawArea(Rgb565 &des, Pos areaPos, Size areaSize, Rgb565 &src, Pos srcPos)
{
    Size desSize = des.getSize(), srcSize = src.getSize();
    unsigned short height = srcSize.height, width, srcOffset = 0, desOffset = 0;
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

    mMutex.lock();
    setDma2dFgmar(srcAddr);
    setDma2dFgColorMode(define::dma2d::colorMode::RGB565);
    setDma2dFgLineOffset(srcOffset);
    setDma2dFgAlphaMode(1);

    if (src.getAlpha() == 0xff)
    {
        setDma2dMode(define::dma2d::mode::MEM_TO_MEM);
    }
    else
    {
        setDma2dBgmar(desAddr);
        setDma2dBgColorMode(define::dma2d::colorMode::RGB565);
        setDma2dBgLineOffset(desOffset);
        setDma2dMode(define::dma2d::mode::MEM_TO_MEM_BLENDING);
        setDma2dFgAlpha(0xff);
    }

    setDma2dOmar(desAddr);
    setDma2dOutputColorMode(define::dma2d::colorMode::RGB565);
    setDma2dNumOfLine(height);
    setDma2dNumOfPixel(width);
    setDma2dOutputLineOffset(desOffset);
    setDma2dStart();

    while (getDma2dTcif() == false)
        thread::yield();
    clrDma2dTcif();

    mMutex.unlock();
}

void Dma2d::draw(Rgb565 &des, const Bmp565 *bmp, Pos pos)
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

    mMutex.lock();
    setDma2dFgmar(srcAddr);
    setDma2dFgColorMode(define::dma2d::colorMode::RGB565);
    setDma2dFgLineOffset(srcOffset);
    setDma2dFgAlphaMode(1);

    setDma2dBgmar(desAddr);
    setDma2dBgColorMode(define::dma2d::colorMode::RGB565);
    setDma2dBgLineOffset(desOffset);

    setDma2dMode(define::dma2d::mode::MEM_TO_MEM);

    setDma2dOmar(desAddr);
    setDma2dOutputColorMode(define::dma2d::colorMode::RGB565);
    setDma2dNumOfLine(srcSize.height);
    setDma2dNumOfPixel(srcSize.width);
    setDma2dOutputLineOffset(desOffset);
    setDma2dStart();

    while (getDma2dTcif() == false)
        thread::yield();
    clrDma2dTcif();

    mMutex.unlock();
}
}

#endif