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

#if YSS_DELAY_TIMER == YSS_RUNTIME_TIMER
#error "You must select different timers for the Runtime timer and the Delay timer."
#endif

#if YSS_DELAY_TIMER == DELAY_TIMER0
#define ISR_DELAY_TIME			TIMER0_IRQHandler
#define DELAY_TIME_DEV			NRF_TIMER0
#define DELAY_TIME_IRQ			TIMER0_IRQn
#elif YSS_DELAY_TIMER == DELAY_TIMER1
#define ISR_DELAY_TIME			TIMER1_IRQHandler
#define DELAY_TIME_DEV			NRF_TIMER1
#define DELAY_TIME_IRQ			TIMER1_IRQn
#elif YSS_DELAY_TIMER == DELAY_TIMER2
#define ISR_DELAY_TIME			TIMER2_IRQHandler
#define DELAY_TIME_DEV			NRF_TIMER2
#define DELAY_TIME_IRQ			TIMER2_IRQn
#elif YSS_DELAY_TIMER == DELAY_TIMER3
#define ISR_DELAY_TIME			TIMER3_IRQHandler
#define DELAY_TIME_DEV			NRF_TIMER3
#define DELAY_TIME_IRQ			TIMER3_IRQn
#elif YSS_DELAY_TIMER == DELAY_TIMER4
#define ISR_DELAY_TIME			TIMER4_IRQHandler
#define DELAY_TIME_DEV			NRF_TIMER4
#define DELAY_TIME_IRQ			TIMER4_IRQn
#endif

static uint64_t gSleepTime;
static threadId_t gSleepId;

extern "C"
{
	void ISR_DELAY_TIME(void) __attribute__((optimize("-O1")));
	void ISR_DELAY_TIME(void)
	{
		DELAY_TIME_DEV->EVENTS_COMPARE[0] = 0;

		if(gSleepTime)
		{
			if(gSleepTime > 0xFFFFFFFF)
			{
				gSleepTime -= 0xFFFFFFFF;
				DELAY_TIME_DEV->CC[0] = 0xFFFFFFFF;
			}
			else
			{
				DELAY_TIME_DEV->CC[0] = gSleepTime;
				gSleepTime = 0;
			}
			DELAY_TIME_DEV->TASKS_START = 1;
		}
		else
			thread::signal(gSleepId);
	}
}

void initializeDelayTimer(void) __attribute__((optimize("-O1")));
void initializeDelayTimer(void)
{
	DELAY_TIME_DEV->MODE = 0;			// Timer Mode
	DELAY_TIME_DEV->BITMODE = 3;		// 32bit
	DELAY_TIME_DEV->PRESCALER = 4;		// 1 MHz
	DELAY_TIME_DEV->SHORTS = 0x100;		// CC[0] 설정
	DELAY_TIME_DEV->INTENSET = TIMER_INTENSET_COMPARE0_Msk;
	NVIC_EnableIRQ(DELAY_TIME_IRQ);
}

void setDelayTimer(threadId_t id, uint64_t sleepTime)
{
	DELAY_TIME_DEV->TASKS_STOP = 1;
	DELAY_TIME_DEV->TASKS_CLEAR = 1;
	DELAY_TIME_DEV->EVENTS_COMPARE[0] = 0;

	gSleepId = id;

	if(sleepTime > 0xFFFFFFFF)
	{
		gSleepTime = sleepTime - 0xFFFFFFFF;
		DELAY_TIME_DEV->CC[0] = 0xFFFFFFFF;
	}
	else
	{
		DELAY_TIME_DEV->CC[0] = sleepTime;
		gSleepTime = 0;
	}

	DELAY_TIME_DEV->TASKS_START = 1;
}

#endif

