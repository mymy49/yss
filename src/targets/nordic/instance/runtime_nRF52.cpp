/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <config.h>
#include <yss/instance.h>
#include <util/runtime.h>
#include <drv/peripheral.h>
#include <nrf52840_bitfields.h>

#if YSS_RUNTIME_TIMER == RUNTIME_TIMER0
#define ISR_RUNTIME			TIMER0_IRQHandler
#define RUNTIME_DEV			NRF_TIMER0
#define RUNTIME_IRQ			TIMER0_IRQn
#elif YSS_RUNTIME_TIMER == RUNTIME_TIMER1
#define ISR_RUNTIME			TIMER1_IRQHandler
#define RUNTIME_DEV			NRF_TIMER1
#define RUNTIME_IRQ			TIMER1_IRQn
#elif YSS_RUNTIME_TIMER == RUNTIME_TIMER2
#define ISR_RUNTIME			TIMER2_IRQHandler
#define RUNTIME_DEV			NRF_TIMER2
#define RUNTIME_IRQ			TIMER2_IRQn
#elif YSS_RUNTIME_TIMER == RUNTIME_TIMER3
#define ISR_RUNTIME			TIMER3_IRQHandler
#define RUNTIME_DEV			NRF_TIMER3
#define RUNTIME_IRQ			TIMER3_IRQn
#elif YSS_RUNTIME_TIMER == RUNTIME_TIMER4
#define ISR_RUNTIME			TIMER4_IRQHandler
#define RUNTIME_DEV			NRF_TIMER4
#define RUNTIME_IRQ			TIMER4_IRQn
#endif

static uint64_t gYssTimeSum;
static uint32_t gDiv = 1;
static uint32_t gTop = 0xFFFFFFFF;
static uint32_t gHalf = gTop / 2;

extern "C"
{
	void ISR_RUNTIME(void) __attribute__((optimize("-O1")));
	void ISR_RUNTIME(void)
	{
		RUNTIME_DEV->EVENTS_COMPARE[0] = 0;
		gYssTimeSum += gTop;
	}
}

void initializeSystemTime(void) __attribute__((optimize("-O1")));
void initializeSystemTime(void)
{
	RUNTIME_DEV->MODE = 0;			// Timer Mode
	RUNTIME_DEV->BITMODE = 3;		// 32bit
	RUNTIME_DEV->PRESCALER = 4;		// 1 MHz
	RUNTIME_DEV->SHORTS = 0x01;		// CC[0] 설정
	RUNTIME_DEV->CC[0] = gTop;
	RUNTIME_DEV->INTENSET = TIMER_INTENSET_COMPARE0_Msk;
	RUNTIME_DEV->TASKS_START = 1;
	NVIC_EnableIRQ(RUNTIME_IRQ);
}

namespace runtime
{
uint64_t gLastRequestTime;

uint32_t getSec(void) __attribute__((optimize("-O1")));
uint32_t getSec(void)
{
	return getUsec() / 1000000;
}

uint64_t getMsec(void) __attribute__((optimize("-O1")));
uint64_t getMsec(void)
{
	return getUsec() / 1000;
}

uint64_t getUsec(void) __attribute__((optimize("-O1")));
uint64_t getUsec(void)
{
	register uint32_t cnt;
	register uint32_t iflag1;
	register uint32_t iflag2;
	register uint64_t acc;
	register uint32_t primask = __get_PRIMASK();

	__disable_irq();
	iflag1 = RUNTIME_DEV->EVENTS_COMPARE[0];
	RUNTIME_DEV->TASKS_CAPTURE[1] = 1;
	cnt = RUNTIME_DEV->CC[1];
	iflag2 = RUNTIME_DEV->EVENTS_COMPARE[0];
	acc = gYssTimeSum;
	__set_PRIMASK(primask);
	
	if(iflag1 != iflag2 && cnt < gHalf)
		return (cnt + acc + gTop) / gDiv;
	else if(iflag1 && iflag2 && cnt < gHalf)
		return (cnt + acc + gTop) / gDiv;
	else
		return (cnt + acc) / gDiv;
}
}

#endif

