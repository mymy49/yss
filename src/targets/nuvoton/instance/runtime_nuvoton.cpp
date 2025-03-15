/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <config.h>
#include <yss/instance.h>
#include <util/runtime.h>
#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include <targets/nuvoton/bitfield_m4xx.h>
#elif defined(__M2xx_FAMILY)
#include <targets/nuvoton/bitfield_m2xx.h>
#endif

#define TOP				0xFFFFFF

#if YSS_TIMER == RUNTIME_TIMER0
#define ISR_RUNTIME		TMR0_IRQHandler
#define RUNTIME_DEV		TIMER0
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR0SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR0CKEN_Msk
#define RUNTIME_IRQ		TMR0_IRQn
#elif YSS_TIMER == RUNTIME_TIMER1
#define ISR_RUNTIME		TMR1_IRQHandler
#define RUNTIME_DEV		TIMER1
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR1SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR1CKEN_Msk
#define RUNTIME_IRQ		TMR1_IRQn
#elif YSS_TIMER == RUNTIME_TIMER2
#define ISR_RUNTIME		TMR2_IRQHandler
#define RUNTIME_DEV		TIMER2
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR2SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR2CKEN_Msk
#define RUNTIME_IRQ		TMR2_IRQn
#elif YSS_TIMER == RUNTIME_TIMER3
#define ISR_RUNTIME		TMR3_IRQHandler
#define RUNTIME_DEV		TIMER3
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR3SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR3CKEN_Msk
#define RUNTIME_IRQ		TMR3_IRQn
#endif

static uint64_t gYssTimeSum;
static bool gUpdateFlag = true;

extern "C"
{
	void ISR_RUNTIME(void) __attribute__((optimize("-O1")));
	void ISR_RUNTIME(void)
	{
		RUNTIME_DEV->INTSTS = TIMER_INTSTS_TIF_Msk;

		if(gUpdateFlag)
		{
			gUpdateFlag = false;
			RUNTIME_DEV->CMP = (TOP * 7 / 8);
		}
		else
		{
			gUpdateFlag = true;
			RUNTIME_DEV->CMP = (TOP * 6 / 8);
			gYssTimeSum += TOP;
		}
	}
}

void initializeSystemTime(void) __attribute__((optimize("-O1")));
void initializeSystemTime(void)
{
	uint32_t clk, reg;

#if defined(HSE_CLOCK_FREQ)

	// 타이머 클럭 소스를 HXT로 전환
	reg = CLK->CLKSEL1;
	reg &= ~CLK_CLKSEL_Msk;
	CLK->CLKSEL1 = reg;
	clk = clock.getHxtFrequency();
#else

	// 타이머 클럭 소스를 HIRC로 전환
	reg = CLK->CLKSEL1;
	reg |= CLK_CLKSEL_Msk;
	CLK->CLKSEL1 = reg;
	clk = clock.getHircFrequency();
#endif

	CLK->APBCLK0 |= CLK_TMR_EN_Msk;
	reg = RUNTIME_DEV->CTL;
	reg &= ~TIMER_CTL_PSC_Msk;
	reg |= ((clk / 1000000 - 1) << TIMER_CTL_PSC_Pos) | TIMER_CTL_CNTEN_Msk | (3 << TIMER_CTL_OPMODE_Pos) | TIMER_CTL_INTEN_Msk;
	RUNTIME_DEV->CTL = reg;

	RUNTIME_DEV->CMP = (TOP * 6 / 8);
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
	register uint32_t cnt, iflag;
	register uint64_t acc;

	__disable_irq();
	cnt = RUNTIME_DEV->CNT;
	acc = gYssTimeSum;
	iflag = gUpdateFlag;
	__enable_irq();
	
	if(iflag == true && cnt > (TOP * 6 / 8))
		return cnt + acc - TOP;
	else
		return cnt + acc;
}

void start(void)
{
	RUNTIME_DEV->CTL |= TIMER_CTL_CNTEN_Msk;
}

void stop(void)
{
	RUNTIME_DEV->CTL &= ~TIMER_CTL_CNTEN_Msk;
}
}

#endif

