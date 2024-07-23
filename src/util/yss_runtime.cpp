/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss/instance.h>

#include <drv/peripheral.h>

#if !defined(YSS_DRV_TIMER_UNSUPPORTED) && !defined(W7500) && !defined(STM32F446xx) && !defined(STM32F103xB) && !defined(STM32F7) && !defined(STM32F1) && !defined(STM32F0)
static uint64_t gYssTimeSum;
static uint32_t gOverFlowCnt;
#if !(defined(STM32F7) || defined(STM32G4))
static bool gPreUpdateFlag;
#endif

static void isr(void)
{
#if defined(STM32F7) || defined(STM32G4)
	gYssTimeSum += gOverFlowCnt;
#else
	if (!gPreUpdateFlag)
		gYssTimeSum += gOverFlowCnt;
	else
		gPreUpdateFlag = false;
#endif
}

void initializeSystemTime(void)
{
	YSS_TIMER.enableClock();
	YSS_TIMER.initializeAsSystemRuntime();
	gOverFlowCnt = YSS_TIMER.getOverFlowCount();
	YSS_TIMER.setUpdateIsr(isr);
	YSS_TIMER.start();
	YSS_TIMER.enableInterrupt();
}

namespace runtime
{
uint64_t gLastRequestTime;

uint32_t getSec(void)
{
#if defined(STM32F7) || defined(STM32G4)
	__disable_irq();
	register uint64_t sum = gYssTimeSum, time = YSS_TIMER.getCounterValue();
	__enable_irq();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if(time & 0x80000000)
		return ((time & 0x7FFFFFFF) + gOverFlowCnt + sum) / 1000000;
	else
		return (time + sum) / 1000000;
#elif !defined(YSS_DRV_TIMER_UNSUPPORTED)
	__disable_irq();
	register uint64_t time = gYssTimeSum + YSS_TIMER.getCounterValue();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if (time < gLastRequestTime)
	{
		gYssTimeSum += gOverFlowCnt;
		time += gOverFlowCnt;
		gPreUpdateFlag = true;
	}
	gLastRequestTime = time;
	__enable_irq();

	return time / 1000000;
#else
	return 0;
#endif
}

uint64_t getMsec(void)
{
#if defined(STM32F7) || defined(STM32G4)
	__disable_irq();
	register uint64_t sum = gYssTimeSum, time = YSS_TIMER.getCounterValue();
	__enable_irq();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if(time & 0x80000000)
		return ((time & 0x7FFFFFFF) + gOverFlowCnt + sum) / 1000;
	else
		return (time + sum) / 1000;
#elif !defined(YSS_DRV_TIMER_UNSUPPORTED)
	__disable_irq();
	register uint64_t time = gYssTimeSum + YSS_TIMER.getCounterValue();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if (time < gLastRequestTime)
	{
		gYssTimeSum += gOverFlowCnt;
		time += gOverFlowCnt;
		gPreUpdateFlag = true;
	}
	gLastRequestTime = time;
	__enable_irq();

	return time / 1000;
#else
	return 0;
#endif
}

uint64_t getUsec(void)
{
#if defined(STM32F7) || defined(STM32G4)
	__disable_irq();
	register uint64_t sum = gYssTimeSum, time = YSS_TIMER.getCounterValue();
	__enable_irq();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if(time & 0x80000000)
		return (time & 0x7FFFFFFF) + gOverFlowCnt + sum;
	else
		return time + sum;
#elif !defined(YSS_DRV_TIMER_UNSUPPORTED)
	__disable_irq();
	register uint64_t time = gYssTimeSum + YSS_TIMER.getCounterValue();

	// 타이머 인터럽트 지연으로 인한 시간 오류 발생 보완용
	if (time < gLastRequestTime)
	{
		gYssTimeSum += gOverFlowCnt;
		time += gOverFlowCnt;
		gPreUpdateFlag = true;
	}
	gLastRequestTime = time;
	__enable_irq();

	return time;
#else
	return 0;
#endif
}

}
#endif
