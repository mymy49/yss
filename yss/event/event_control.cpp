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

#ifdef DEBUG
#include <__cross_studio_io.h>
#endif

#include <config.h>
#include <yss/malloc.h>
#include <yss/yss.h>

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE && USE_EVENT

namespace event
{
void trigger_eventHandler(void);

Pos *gPos;
unsigned short gHead, gTail;
unsigned char *gEvent;
signed long gId;
bool enableFlag = false, gRunningFlag = false;
Pos gLastPos;
Mutex gMutex;

void init(void)
{
#if YSS_L_HEAP_USE == true
	gPos = (Pos *)lmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(Pos));
	gEvent = (unsigned char *)lmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(unsigned char));
#else
	//gX = (unsigned short*)hmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(unsigned short));
	//gY = (unsigned short*)hmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(unsigned short));
	gEvent = (unsigned char *)hmalloc(TOUCH_EVENT_MEMORY_DEPTH * sizeof(unsigned char));
#endif
	gHead = gTail = 0;

	gId = trigger::add(trigger_eventHandler, TOUCH_EVENT_HANDLER_STACK_SIZE);
}

void add(unsigned short x, unsigned short y, unsigned char event)
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

void add(Pos pos, unsigned char event)
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

Pos getLastTouchPos(void)
{
	return gLastPos;
}
};

#endif