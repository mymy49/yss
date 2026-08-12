/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__MAX32665_FAMILY)

#include <config.h>
#include <yss/instance.h>
#include <util/runtime.h>
#include <drv/peripheral.h>

#if YSS_TIMER == RUNTIME_TMR0
#define ISR_RUNTIME			TMR0_IRQHandler
#define RUNTIME_DEV			MXC_TMR0
#define CLK_TMR_EN_Msk		MXC_F_GCR_PERCKCN0_T0D
#define RUNTIME_IRQ			TMR0_IRQn
#elif YSS_TIMER == RUNTIME_HTMR1
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
static uint32_t gDiv = 1;
static uint32_t gTop = 0xFFFFFFFF;
static uint32_t gHalf = gTop / 2;
static bool gUpdateFlag = true;

extern "C"
{
	void ISR_RUNTIME(void) __attribute__((optimize("-O1")));
	void ISR_RUNTIME(void)
	{
		RUNTIME_DEV->intr = MXC_F_TMR_INTR_IRQ_CLR;
		gYssTimeSum += gTop;
	}
}

void initializeSystemTime(void) __attribute__((optimize("-O1")));
void initializeSystemTime(void)
{
	uint32_t reg;
	uint32_t clk = clock.getApbClockFrequency();

	MXC_GCR->perckcn0 &= ~CLK_TMR_EN_Msk;
	
	gDiv = clk / 1000000;
	RUNTIME_DEV->cmp = gTop =  gDiv * 10000000;
	gHalf = gTop / 2;

	setFieldData(RUNTIME_DEV->cn, MXC_F_TMR_CN_TMODE, MXC_V_TMR_CN_TMODE_CONTINUOUS, MXC_F_TMR_CN_TMODE_POS);
	RUNTIME_DEV->cn |= MXC_F_TMR_CN_TEN;

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

	__disable_irq();
	iflag1 = RUNTIME_DEV->intr;
	cnt = RUNTIME_DEV->cnt;
	iflag2 = RUNTIME_DEV->intr;
	acc = gYssTimeSum;
	__enable_irq();
	
	if(iflag1 != iflag2 && cnt < gHalf)
		return (cnt + acc + gTop) / gDiv;
	else if(iflag1 && iflag2 && cnt < gHalf)
		return (cnt + acc + gTop) / gDiv;
	else
		return (cnt + acc) / gDiv;
}
}

#endif

