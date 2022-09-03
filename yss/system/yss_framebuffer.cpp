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

#include <yss/gui.h>
#include <config.h>
#include <gui/SerialFrameBuffer.h>
#include <yss/event.h>
#include <yss/gui.h>
#include <yss/thread.h>
#include <yss/instance.h>

#if USE_GUI && YSS_L_HEAP_USE

namespace yss
{
SerialFrameBuffer *gFrameBuf;
Frame *gCurrentFrame;
Object *gLastSelectedObj;

void initFrameBuffer(void)
{
	gFrameBuf = new SerialFrameBuffer();
	ltdc.setFrameBuffer(gFrameBuf);
}

void setFrame(Frame &obj)
{
	//ltdc.setFrameBuffer(obj);
	//      return;

	if (gFrameBuf == 0)
		initFrameBuffer();
	gFrameBuf->flush();
	obj.setSerialFrameBuffer(gFrameBuf);
	gFrameBuf->add(obj);
	gCurrentFrame = &obj;
}

void setFrame(Frame *obj)
{
	//ltdc.setFrameBuffer(obj);
	//	return;

	if (gFrameBuf == 0)
		initFrameBuffer();
	gFrameBuf->flush();
	obj->setSerialFrameBuffer(gFrameBuf);
	gFrameBuf->add(obj);
	gCurrentFrame = obj;
}

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE && USE_EVENT
void setEvent(Position pos, uint8_t event)
{
	static Position lastPos;
	int16_t buf;
	bool flag = false;
	//		debug_printf("frm %d, %d, %d\n", event, pos.x, pos.y);
	switch (event)
	{
	case event::PUSH:
		lastPos = pos;
		gLastSelectedObj = gCurrentFrame->Container::handlerPush(pos);
		if (gLastSelectedObj)
			lastPos = gLastSelectedObj->getAbsolutePos();
		break;
	case event::DRAG:
		if (gLastSelectedObj)
		{
			pos.x -= lastPos.x;
			pos.y -= lastPos.y;
			gLastSelectedObj->handlerDrag(pos);
		}
		break;
	case event::UP:
		if (gLastSelectedObj)
		{
			gLastSelectedObj->handlerUp();
			gLastSelectedObj = 0;
		}
		break;
	}
}
#endif
}
#endif