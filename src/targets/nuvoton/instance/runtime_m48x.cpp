////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(__M480_FAMILY)

#include <config.h>
#include <yss/instance.h>
#include <util/runtime.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/bitfield_m48x.h>

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
#elif YSS_TIMER == RUNTIME_TIMER4
#define ISR_RUNTIME		TMR4_IRQHandler
#define RUNTIME_DEV		TIMER4
#define CLK_CLKSEL_Msk	CLK_CLKSEL1_TMR4SEL_Msk
#define CLK_TMR_EN_Msk	CLK_APBCLK0_TMR4CKEN_Msk
#define RUNTIME_IRQ		TMR4_IRQn
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
	reg |= (clk / 1000000 - 1) << TIMER_CTL_PSC_Pos | TIMER_CTL_CNTEN_Msk | 3 << TIMER_CTL_OPMODE_Pos | TIMER_CTL_INTEN_Msk;
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
}

#endif

