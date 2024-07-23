/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>
#include <yss/event.h>
#include <yss/gui.h>
#include <yss/thread.h>
#include <yss/instance.h>
#include <yss/debug.h>
#include <gui/OutputFrameBuffer.h>
#include <yss.h>
#include <sac/TftLcdDriver.h>

static OutputFrameBuffer *gFrameBuf;
static Frame *gCurrentFrame;
static Object *gLastSelectedObj;
static TftLcdDriver *gTftLcd;

void initOutputFrameBuffer(void)
{
	gFrameBuf = new OutputFrameBuffer();
	gFrameBuf->setLcdSize(ltdc.getLcdSize());
	ltdc.setFrameBuffer(gFrameBuf->getFrameBuffer());
}

void setSystemTftLcd(TftLcdDriver &lcd)
{
	gTftLcd = &lcd;
}

TftLcdDriver* getSystemTftLcd(void)
{
	return gTftLcd;
}

void setActiveFrame(Frame *obj)
{
	if(gFrameBuf == 0)
		initOutputFrameBuffer();

	gCurrentFrame = obj;
	gFrameBuf->setFrame(obj);
	obj->setOutputFrameBuffer(gFrameBuf);
}

void clearActiveFrame(void)
{
	gLastSelectedObj = 0;
}

#if USE_GUI && USE_EVENT
void setEvent(Position_t pos, uint8_t event)
{
	static Position_t lastPos;

	if(gFrameBuf == 0)
		return;

	switch (event)
	{
	case event::TOUCH_DOWN:
		lastPos = pos;
		gLastSelectedObj = gCurrentFrame->Container::handlerPush(pos);
		if (gLastSelectedObj)
			lastPos = gLastSelectedObj->getAbsolutePos();
		break;
	case event::TOUCH_DRAG:
		if (gLastSelectedObj)
		{
			pos.x -= lastPos.x;
			pos.y -= lastPos.y;
			gLastSelectedObj->handlerDrag(pos);
		}
		break;
	case event::TOUCH_UP:
		if (gLastSelectedObj)
		{
			gLastSelectedObj->handlerUp();
			gLastSelectedObj = 0;
		}
		break;
	}
}
#endif

#endif

