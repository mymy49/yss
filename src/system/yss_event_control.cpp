////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.1
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <std_ext/malloc.h>
#include <yss/PointerEvent.h>
#include <sac/Rtouch.h>
#include <yss.h>
#include <yss/debug.h>

#if USE_EVENT

namespace event
{
	void trigger_handleEvent(void);

	PointerEvent gPointerEvent(TOUCH_EVENT_MEMORY_DEPTH);
	static triggerId gTriggerId;

	void init(void)
	{
		gTriggerId = trigger::add(trigger_handleEvent, TOUCH_EVENT_HANDLER_STACK_SIZE);
	}

	void trigger_handleEvent(void)
	{
		PointerEvent::PointerEventData data;
		while(gPointerEvent.getMessageCount())
		{
			data = gPointerEvent.pop();
			setEvent(Position{data.x, data.y}, data.event);
//			debug_printf("%d, %d, %d\n", data.x, data.y, data.event);
		}
	}

	void setPointerDevice(sac::Touch &dev)
	{
		dev.setInterface(gPointerEvent, gTriggerId);
	}
/*
void trigger_eventHandler(void);

Position *gPos;
uint16_t gHead, gTail;
uint8_t *gEvent;
int32_t gId;
bool enableFlag = false, gRunningFlag = false;
Position gLastPos;
Mutex gMutex;

void init(void)
{
	
#if YSS_L_HEAP_USE == true
	gPos = (Position *)lmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(Position));
	gEvent = (uint8_t *)lmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(uint8_t));
#else
	//gX = (uint16_t*)hmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(uint16_t));
	//gY = (uint16_t*)hmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(uint16_t));
	gEvent = (uint8_t *)hmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(uint8_t));
#endif
	gHead = gTail = 0;

	gId = trigger::add(trigger_eventHandler, TOUCH_EVENT_HANDLER_STACK_SIZE);
}

void add(uint16_t x, uint16_t y, uint8_t event)
{
	gMutex.lock();
	gPos[gHead].x = x;
	gPos[gHead].y = y;
	gEvent[gHead] = event;
	gHead++;
	if (gHead >= TOUCH_EVENT_MEMORY_DEPTH)
		gHead = 0;

	if (enableFlag)
		trigger::run(gId);
	gMutex.unlock();
}

void add(Position pos, uint8_t event)
{
	gMutex.lock();
	gPos[gHead] = pos;
	gEvent[gHead] = event;
	gHead++;
	if (gHead >= TOUCH_EVENT_MEMORY_DEPTH)
		gHead = 0;
	gMutex.unlock();
}

void trigger(void)
{
	if (gRunningFlag == false)
	{
		gRunningFlag = true;
		trigger::run(gId);
	}
}

void trigger_eventHandler(void)
{
	while (true)
	{
		gMutex.lock();
		if (gHead == gTail)
		{
			gMutex.unlock();
			gRunningFlag = false;
			return;
		}
		gMutex.unlock();

		gLastPos = gPos[gTail];

		yss::setEvent(gLastPos, gEvent[gTail]);

		gTail++;
		if (gTail >= TOUCH_EVENT_MEMORY_DEPTH)
			gTail = 0;
	}
}

void flush(void)
{
	gHead = gTail = 0;
}

Position getLastTouchPos(void)
{
	return gLastPos;
}
*/
};
#endif