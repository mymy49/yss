/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M251_SUBFAMILY) || defined(__M46x_SUBFAMILY)

#include <config.h>
#include <yss/instance.h>
#include <util/runtime.h>
#include <drv/peripheral.h>

#pragma GCC optimize("O1")

#if YSS_DELAY_TIMER == YSS_RUNTIME_TIMER
#error "You must select different timers for the Runtime timer and the Delay timer."
#endif

#if YSS_DELAY_TIMER == RUNTIME_TIMER0
#define ISR_DELAY_TIME	TMR0_IRQHandler
#define RUNTIME_DEV		TIMER0
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR0SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR0CKEN_Msk
#define RUNTIME_IRQ		TMR0_IRQn
#elif YSS_DELAY_TIMER == RUNTIME_TIMER1
#define ISR_DELAY_TIME	TMR1_IRQHandler
#define RUNTIME_DEV		TIMER1
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR1SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR1CKEN_Msk
#define RUNTIME_IRQ		TMR1_IRQn
#elif YSS_DELAY_TIMER == RUNTIME_TIMER2
#define ISR_DELAY_TIME	TMR2_IRQHandler
#define RUNTIME_DEV		TIMER2
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR2SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR2CKEN_Msk
#define RUNTIME_IRQ		TMR2_IRQn
#elif YSS_DELAY_TIMER == RUNTIME_TIMER3
#define ISR_DELAY_TIME	TMR3_IRQHandler
#define RUNTIME_DEV		TIMER3
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR3SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR3CKEN_Msk
#define RUNTIME_IRQ		TMR3_IRQn
#endif

static volatile uint64_t gSleepTime;
static volatile threadId_t gSleepId;

extern "C"
{
	void ISR_DELAY_TIME(void)
	{
		RUNTIME_DEV->INTSTS = TIMER_INTSTS_TIF_Msk;

		if(gSleepTime)
		{
			if(gSleepTime > 0xFFFFFFFF)
			{
				gSleepTime -= 0xFFFFFFFF;
				RUNTIME_DEV->CMP = 0xFFFFFFFF;
			}
			else
			{
				RUNTIME_DEV->CMP = gSleepTime;
				gSleepTime = 0;
			}
			RUNTIME_DEV->CNT = 0;
			RUNTIME_DEV->CTL |= TIMER_CTL_CNTEN_Msk;
		}
		else
		{
			__disable_irq();
			thread::signal(gSleepId);
			__enable_irq();
		}
	}
}

void initializeDelayTimer(void)
{
	uint32_t clk, reg;

#if defined(HSE_CLOCK_FREQ)

	// Switch timer clock source to HXT
	reg = CLK->CLKSEL1;
	reg &= ~CLK_CLKSEL_Msk;
	CLK->CLKSEL1 = reg;
	clk = clock.getHxtFrequency();
#else

	// Switch timer clock source to HIRC
	reg = CLK->CLKSEL1;
	reg |= CLK_CLKSEL_Msk;
	CLK->CLKSEL1 = reg;
	clk = clock.getHircFrequency();
#endif

	CLK->APBCLK0 |= CLK_TMR_EN_Msk;
	reg = RUNTIME_DEV->CTL;
	reg &= ~TIMER_CTL_PSC_Msk;
	reg |= ((clk / 1000000 - 1) << TIMER_CTL_PSC_Pos) | TIMER_CTL_CNTEN_Msk | (0 << TIMER_CTL_OPMODE_Pos) | TIMER_CTL_INTEN_Msk;
	RUNTIME_DEV->CTL = reg;
	NVIC_EnableIRQ(RUNTIME_IRQ);
}

void setDelayTimer(threadId_t id, uint64_t sleepTime)
{
	RUNTIME_DEV->CTL &= ~TIMER_CTL_CNTEN_Msk;
	RUNTIME_DEV->INTSTS = TIMER_INTSTS_TIF_Msk;
	RUNTIME_DEV->CNT = 0;

	if(sleepTime == 0)
		sleepTime = 1;

	gSleepId = id;

	if(sleepTime > 0xFFFFFFFF)
	{
		gSleepTime -= 0xFFFFFFFF;
		RUNTIME_DEV->CMP = 0xFFFFFFFF;
	}
	else
	{
		RUNTIME_DEV->CMP = sleepTime;
		gSleepTime = 0;
	}

	RUNTIME_DEV->CTL |= TIMER_CTL_CNTEN_Msk;
}

#endif

