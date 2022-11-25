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

#if USE_GUI

#include <drv/peripheral.h>
#include <config.h>
#include <yss/gui.h>
#include <gui/CpuFrameBuffer.h>
#include <yss/malloc.h>
#include <yss/string.h>

CpuFrameBuffer::CpuFrameBuffer(void)
{
	mLcd = 0;
	mFrameBuffer = 0;
	mBufferSize = 0;
	return;
}

bool CpuFrameBuffer::init(sac::SerialTft *obj)
{
	uint32_t buffSize = obj->getWidth() * obj->getHeight() * 2;
	mLcd = obj;
#if YSS_L_HEAP_USE == true
	mFrameBuffer = (uint8_t *)lmalloc(buffSize);
#elif YSS_C_HEAP_USE == true
	mFrameBuffer = (uint8_t *)cmalloc(buffSize);
#else
	mFrameBuffer = (uint8_t *)hmalloc(buffSize);
#endif
	if (mFrameBuffer == 0)
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

void CpuFrameBuffer::refresh(int16_t x, int16_t y, uint16_t width, uint16_t height)
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

void CpuFrameBuffer::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mLcd->setColor(red, green, blue);
}

void CpuFrameBuffer::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mLcd->setFontColor(red, green, blue);
}

void CpuFrameBuffer::setBgColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mLcd->setBgColor(red, green, blue);
}

void CpuFrameBuffer::eraseDot(Position pos)
{
	mLcd->eraseDot(pos);
}

void CpuFrameBuffer::drawDot(int16_t x, int16_t y)
{
	uint16_t *fb = (uint16_t *)mFrameBuffer;
	fb[y * mSize.width + x] = mLcd->getColor();
}

void CpuFrameBuffer::drawDot(int16_t x, int16_t y, uint16_t color)
{
	uint16_t *fb = (uint16_t *)mFrameBuffer;
	fb[y * mSize.width + x] = color;
}

void CpuFrameBuffer::drawDot(int16_t x, int16_t y, uint32_t color)
{
}

void CpuFrameBuffer::fillRect(Position p1, Position p2)
{
	int16_t sx, ex, sy, ey;
	uint16_t color = mLcd->getColor(), width;
	uint16_t *des = (uint16_t *)mFrameBuffer;

	if (p1.x < p2.x)
	{
		sx = p1.x;
		ex = p2.x;
	}
	else
	{
		sx = p2.x;
		ex = p1.x;
	}

	if (p1.y < p2.y)
	{
		sy = p1.y;
		ey = p2.y;
	}
	else
	{
		sy = p2.y;
		ey = p1.y;
	}

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	width = (ex - sx + 1) * 2;
	des += sx + sy * mSize.width;
	for (int16_t y = sy; y <= ey; y++)
	{
		memsethw(des, color, width);
		des += mSize.width;
	}
}

void CpuFrameBuffer::fillRect(Position pos, Size size)
{
	int16_t sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;
	uint16_t *des = (uint16_t *)mFrameBuffer;
	uint16_t color = mLcd->getColor(), width;

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	width = (ex - sx + 1) * 2;
	des += sx + sy * mSize.width;
	for (int16_t y = sy; y <= ey; y++)
	{
		memsethw(des, color, width);
		des += mSize.width;
	}
}

void CpuFrameBuffer::eraseRect(Position p1, Position p2)
{
	int16_t sx, ex, sy, ey;
	uint16_t color = mLcd->getBgColor(), width;
	uint16_t *des = (uint16_t *)mFrameBuffer;

	if (p1.x < p2.x)
	{
		sx = p1.x;
		ex = p2.x;
	}
	else
	{
		sx = p2.x;
		ex = p1.x;
	}

	if (p1.y < p2.y)
	{
		sy = p1.y;
		ey = p2.y;
	}
	else
	{
		sy = p2.y;
		ey = p1.y;
	}

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	width = (ex - sx + 1) * 2;
	des += sx + sy * mSize.width;
	for (int16_t y = sy; y <= ey; y++)
	{
		memsethw(des, color, width);
		des += mSize.width;
	}
}

void CpuFrameBuffer::eraseRect(Position pos, Size size)
{
	int16_t sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;
	uint16_t *des = (uint16_t *)mFrameBuffer;
	uint16_t color = mLcd->getBgColor(), width;

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	width = (ex - sx + 1) * 2;
	des += sx + sy * mSize.width;
	for (int16_t y = sy; y <= ey; y++)
	{
		memsethw(des, color, width);
		des += mSize.width;
	}
}

void CpuFrameBuffer::drawFontDot(int16_t x, int16_t y, uint8_t color)
{
	uint16_t *fb = (uint16_t *)mFrameBuffer;
	fb[y * mSize.width + x] = mLcd->getFontColor(color, fb[y * mSize.width + x]);
}

void CpuFrameBuffer::eraseDot(Position pos);

CpuFrameBuffer::~CpuFrameBuffer(void)
{
}

void CpuFrameBuffer::drawBmp565(Position pos, const Bmp565 &image)
{
	drawBmp565(pos, &image);
}

void CpuFrameBuffer::drawBmp565(Position pos, const Bmp565 *image)
{
	int16_t sx = pos.x, ex = pos.x + image->width, sy = pos.y, ey = pos.y + image->height;
	uint16_t *des = (uint16_t *)mFrameBuffer, width, *src = (uint16_t *)image->data;
	uint16_t color = mLcd->getBgColor();

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	width = (ex - sx + 1) * 2;
	des += sx + sy * mSize.width;
	for (int16_t y = sy; y < ey; y++)
	{
		memcpy(des, src, width);
		des += mSize.width;
		src += image->width;
	}
}

#endif

