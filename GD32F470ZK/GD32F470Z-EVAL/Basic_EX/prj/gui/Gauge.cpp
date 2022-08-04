#include <__cross_studio_io.h>
#include <config.h>
#include <yss/gui.h>
#include "Gauge.h"
#include <string.h>
#include <yss/instance.h>
#include <math.h>
#include <stdio.h>
#include <util/time.h>
#include <gui/painter.h>

#if USE_GUI && YSS_L_HEAP_USE

#define calculateToRadian(x)	(x / 180.f * 3.141592654f)

Gauge::Gauge(void)
{
	mBg = new Rgb565();
	mInitFlag = false;
	mTopValue = 100;
	mValue = 0;
	mTitleStr = 0;
}

Gauge::~Gauge(void)
{
	delete mBg;
}

void Gauge::destroy(void)
{
	delete mBg;
}

void Gauge::makeBg(void)
{
	unsigned int r;
	Position p1, p2;
	mBg->setSize(mSize);

	if(mSize.width > mSize.height)
		r = mSize.height / 2 - 1;
	else
		r = mSize.width / 2 - 1;
	
	mCenter.x = r;
	mCenter.y = r;

	mBg->setBackgroundColor(mBgColor);
	mBg->clear();

	mBg->setBrushColor(0x00, 0x00, 0x00);
	mBg->fillCircle(mCenter, r);
	r -= 5;
	mBg->setBrushColor(0xFF, 0xFF, 0xFF);
	mBg->fillCircle(mCenter, r);
		
	mBg->setBrushColor(0x00, 0x00, 0x00);
	p1.x = mCenter.x + sin(5.5) * r;
	p1.y = mCenter.y + cos(5.5) * r;
	mBg->drawLine(mCenter, p1);
	p1.y += 1;
	p1.x += 1;
	mBg->drawLine(mCenter, p1);
	p1.y -= 2;
	p1.x -= 2;
	mBg->drawLine(mCenter, p1);

	p1.x = mCenter.x + sin(0.79) * r;
	p1.y = mCenter.y + cos(0.79) * r;
	mBg->drawLine(mCenter, p1);
	p1.y += 1;
	p1.x -= 1;
	mBg->drawLine(mCenter, p1);
	p1.y -= 2;
	p1.x += 2;
	mBg->drawLine(mCenter, p1);

	r = r * 0.8f;
	mBg->setBrushColor(0xFF, 0xFF, 0xFF);
	mBg->fillCircle(mCenter, r);
	
	if(mTitleStr)
	{
		p1 = mCenter;
		p1.y /= 2;
		p1.x -= mFont.getStringWidth(mTitleStr) / 2;
		mBg->setFont(mFont);
		mBg->setBackgroundColor(0xFF, 0xFF, 0xFF);
		mBg->setFontColor(0x00, 0x00, 0x00);
		mBg->drawString(p1, mTitleStr);
	}

	mNeedleLen = r;
	mInitFlag = true;
}

void Gauge::paint(void)
{
	Painter::draw(*this, *mBg, Position{0, 0});

	if(mInitFlag)
	{
		drawNeedle((1.f-mValue / mTopValue) * 270.f + 45.f);
	}
}

void Gauge::setTopValue(float value)
{
	mTopValue = value;
	paint();
	update();
}

void Gauge::setTitle(const char *str)
{
	mTitleStr = str;
}

void Gauge::setValue(float value)
{
	if(value > mTopValue)
		value = mTopValue;

	if(mValue != value)
	{
		mValue = value;
		paint();
		update();
	}
}

void Gauge::drawNeedle(float angle)
{
	float radian = calculateToRadian(angle);
	float r1, r2 = mNeedleLen;
	r1 = r2 * 0.1f;
	Position p1, p2, p3;

	p1.x = sin(radian+calculateToRadian(90.f)) * r1 + mCenter.x;
	p1.y = cos(radian+calculateToRadian(90.f)) * r1 + mCenter.y;

	p2.x = sin(radian-calculateToRadian(90.f)) * r1 + mCenter.x;
	p2.y = cos(radian-calculateToRadian(90.f)) * r1 + mCenter.y;

	p3.x = sin(radian) * r2 + mCenter.x;
	p3.y = cos(radian) * r2 + mCenter.y;
	
	setBrushColor(0xFF, 0x00, 0x00);
	fillTriangle(p1, p2, p3);

	setBrushColor(0x80, 0x80, 0x80);
	drawLine(p3, mCenter);

	setBrushColor(0x00, 0x00, 0x00);
	drawLine(p3, p1);
	drawLine(p3, p2);
	fillCircle(mCenter, (unsigned short)(r1 * 1.5f));
}

void Gauge::setFont(Font font)
{
	mFont = font;
}

#endif