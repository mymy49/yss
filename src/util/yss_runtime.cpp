////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <yss/instance.h>

#include <drv/peripheral.h>

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1_N) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)
static uint64_t gYssTimeSum = (uint64_t)-60000;
static uint32_t gOverFlowCnt = 60000;
#else
static uint64_t gYssTimeSum;
static uint32_t gOverFlowCnt;
#endif

static Mutex gMutex;

static void isr(void)
{
	gYssTimeSum += gOverFlowCnt;
}

void initializeSystemTime(void)
{
#ifndef YSS_DRV_TIMER_UNSUPPORTED
	YSS_TIMER.enableClock();
	YSS_TIMER.initializeAsSystemRuntime();
	gOverFlowCnt = YSS_TIMER.getOverFlowCount();
	YSS_TIMER.setUpdateIsr(isr);
	YSS_TIMER.start();
	YSS_TIMER.enableUpdateInterrupt();
	YSS_TIMER.enableInterrupt();
#endif
}

namespace runtime
{
uint64_t gLastRequestTime;

uint32_t getSec(void)
{
#ifndef YSS_DRV_TIMER_UNSUPPORTED
	__disable_irq();
	uint64_t time = gYssTimeSum + YSS_TIMER.getCounterValue();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if (time < gLastRequestTime)
		time += gOverFlowCnt;
	gLastRequestTime = time;

	return time / 1000000;
#else
	return 0;
#endif
}

uint64_t getMsec(void)
{
#ifndef YSS_DRV_TIMER_UNSUPPORTED
	uint64_t time = gYssTimeSum + YSS_TIMER.getCounterValue();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if (time < gLastRequestTime)
		time += gOverFlowCnt;
	gLastRequestTime = time;

	return time / 1000;
#else
	return 0;
#endif
}

uint64_t getUsec(void)
{
#ifndef YSS_DRV_TIMER_UNSUPPORTED
	uint64_t time = gYssTimeSum + YSS_TIMER.getCounterValue();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if (time < gLastRequestTime)
		time += gOverFlowCnt;
	gLastRequestTime = time;

	return time;
#else
	return 0;
#endif
}
}

