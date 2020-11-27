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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.06.07 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/gui.h>
#include <gui/CpuFrameBuffer.h>
#include <config.h>
#include <yss/malloc.h>
#include <yss/stdlib.h>

CpuFrameBuffer::CpuFrameBuffer(void)
{
	mLcd = 0;
    mFrameBuffer = 0;
    mBufferSize = 0;
    return;
}

bool CpuFrameBuffer::init(sac::CpuTft *obj)
{
	unsigned int buffSize = obj->getWidth() * obj->getHeight() * 2;
	mLcd = obj;
#if YSS_L_HEAP_USE == true
	mFrameBuffer = (unsigned char*)lmalloc(buffSize);
#elif YSS_C_HEAP_USE == true
	mFrameBuffer = (unsigned char*)cmalloc(buffSize);
#else
	mFrameBuffer = (unsigned char*)hmalloc(buffSize);
#endif
	if(mFrameBuffer == 0)
	{
        return false;
	}

	mBufferSize = buffSize;
	
    setSize(Size{obj->getWidth(), obj->getHeight()});
    return true;
}

void CpuFrameBuffer::refresh(void)
{
	mLcd->fillFrameBuffer(mFrameBuffer);
}

void CpuFrameBuffer::refresh(signed short x, signed short y, unsigned short width, unsigned short height)
{
	mLcd->fillFrameBuffer(mFrameBuffer, x, y, width, height);
}

void CpuFrameBuffer::fill(void)
{
	memsethw(mFrameBuffer, mLcd->getColor(), mBufferSize);
}

void CpuFrameBuffer::clear(void)
{
	memsethw(mFrameBuffer, mLcd->getBgColor(), mBufferSize);
}

void CpuFrameBuffer::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mLcd->setColor(red, green, blue);
}

void CpuFrameBuffer::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mLcd->setFontColor(red, green, blue);
}

void CpuFrameBuffer::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mLcd->setBgColor(red, green, blue);
}

void CpuFrameBuffer::eraseDot(Pos pos)
{
	mLcd->eraseDot(pos);
}

void CpuFrameBuffer::drawDot(signed short x, signed short y)
{
	unsigned short *fb = (unsigned short*)mFrameBuffer;
	fb[y*mSize.width+x] = mLcd->getColor();
}

void CpuFrameBuffer::drawDot(signed short x, signed short y, unsigned short color)
{
	unsigned short *fb = (unsigned short*)mFrameBuffer;
	fb[y*mSize.width+x] = color;	
}

void CpuFrameBuffer::drawDot(signed short x, signed short y, unsigned int color)
{
}

void CpuFrameBuffer::fillRect(Pos p1, Pos p2)
{
	signed short sx, ex, sy, ey;
    unsigned short color = mLcd->getColor(), width;
	unsigned short *des = (unsigned short*)mFrameBuffer;

	if(p1.x < p2.x)
	{
		sx = p1.x;
		ex = p2.x;
	}
	else
	{
		sx = p2.x;
		ex = p1.x;
	}

	if(p1.y < p2.y)
	{
		sy = p1.y;
		ey = p2.y;
	}
	else
	{
		sy = p2.y;
		ey = p1.y;
	}

	if(ey > mSize.height-1)
		ey = mSize.height-1;
	if(ex > mSize.width-1)
		ex = mSize.width-1;

    width = (ex - sx + 1)*2;
	des += sx + sy * mSize.width;
	for(signed short y=sy;y<=ey;y++)
    {
		memsethw(des, color, width);
        des += mSize.width;
	}
}

void CpuFrameBuffer::fillRect(Pos pos, Size size)
{
	signed short sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;
	unsigned short *des = (unsigned short*)mFrameBuffer;
    unsigned short color = mLcd->getColor(), width;

	if(ey > mSize.height-1)
		ey = mSize.height-1;
	if(ex > mSize.width-1)
		ex = mSize.width-1;

    width = (ex - sx + 1)*2;
	des += sx + sy * mSize.width;
	for(signed short y=sy;y<=ey;y++)
    {
		memsethw(des, color, width);
        des += mSize.width;
	}
}

void CpuFrameBuffer::eraseRect(Pos p1, Pos p2)
{
	signed short sx, ex, sy, ey;
    unsigned short color = mLcd->getBgColor(), width;
	unsigned short *des = (unsigned short*)mFrameBuffer;

	if(p1.x < p2.x)
	{
		sx = p1.x;
		ex = p2.x;
	}
	else
	{
		sx = p2.x;
		ex = p1.x;
	}

	if(p1.y < p2.y)
	{
		sy = p1.y;
		ey = p2.y;
	}
	else
	{
		sy = p2.y;
		ey = p1.y;
	}

	if(ey > mSize.height-1)
		ey = mSize.height-1;
	if(ex > mSize.width-1)
		ex = mSize.width-1;

    width = (ex - sx + 1)*2;
	des += sx + sy * mSize.width;
	for(signed short y=sy;y<=ey;y++)
    {
		memsethw(des, color, width);
        des += mSize.width;
	}
}

void CpuFrameBuffer::eraseRect(Pos pos, Size size)
{
	signed short sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;
	unsigned short *des = (unsigned short*)mFrameBuffer;
    unsigned short color = mLcd->getBgColor(), width;

	if(ey > mSize.height-1)
		ey = mSize.height-1;
	if(ex > mSize.width-1)
		ex = mSize.width-1;

    width = (ex - sx + 1)*2;
	des += sx + sy * mSize.width;
	for(signed short y=sy;y<=ey;y++)
    {
		memsethw(des, color, width);
        des += mSize.width;
	}
}

void CpuFrameBuffer::drawFontDot(signed short x, signed short y, unsigned char color)
{
	unsigned short *fb = (unsigned short*)mFrameBuffer;
	fb[y*mSize.width+x] = mLcd->getFontColor(color, fb[y*mSize.width+x]);
}

void CpuFrameBuffer::eraseDot(Pos pos);

CpuFrameBuffer::~CpuFrameBuffer(void)
{

}

void CpuFrameBuffer::drawBmp565(Pos pos, const Bmp565 &image)
{
	drawBmp565(pos, &image);
}

void CpuFrameBuffer::drawBmp565(Pos pos, const Bmp565 *image)
{
	signed short sx = pos.x, ex = pos.x + image->width, sy = pos.y, ey = pos.y + image->height;
	unsigned short *des = (unsigned short*)mFrameBuffer, width, *src = (unsigned short*)image->data;
    unsigned short color = mLcd->getBgColor();

	if(ey > mSize.height-1)
		ey = mSize.height-1;
	if(ex > mSize.width-1)
		ex = mSize.width-1;

	width = (ex - sx + 1)*2;
	des += sx + sy * mSize.width;
	for(signed short y=sy;y<ey;y++)
    {
		memcpy(des, src, width);
        des += mSize.width;
        src += image->width;
	}
}
