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

#if defined(W7500)

#include <config.h>
#include <yss/instance.h>
#include <util/runtime.h>
#include <drv/peripheral.h>
#include <targets/wiznet/bitfield_w7500x.h>

#define TOP				0xFFFFFFFF

#if YSS_TIMER == RUNTIME_PWM0
#define ISR_RUNTIME		PWM0_IRQHandler
#define RUNTIME_DEV		PWM0
#define RUNTIME_SSR		PWM0CLK_SSR
#define RUNTIME_PVSR	PWM0CLK_PVSR
#define RUNTIME_IRQ		PWM0_IRQn
#elif YSS_TIMER == RUNTIME_PWM1
#define ISR_RUNTIME		PWM1_IRQHandler
#define RUNTIME_DEV		PWM1
#define RUNTIME_SSR		PWM1CLK_SSR
#define RUNTIME_PVSR	PWM1CLK_PVSR
#define RUNTIME_IRQ		PWM1_IRQn
#elif YSS_TIMER == RUNTIME_PWM2
#define ISR_RUNTIME		PWM2_IRQHandler
#define RUNTIME_DEV		PWM2
#define RUNTIME_SSR		PWM2CLK_SSR
#define RUNTIME_PVSR	PWM2CLK_PVSR
#define RUNTIME_IRQ		PWM2_IRQn
#elif YSS_TIMER == RUNTIME_PWM3
#define ISR_RUNTIME		PWM3_IRQHandler
#define RUNTIME_DEV		PWM3
#define RUNTIME_SSR		PWM3CLK_SSR
#define RUNTIME_PVSR	PWM3CLK_PVSR
#define RUNTIME_IRQ		PWM3_IRQn
#elif YSS_TIMER == RUNTIME_PWM4
#define ISR_RUNTIME		PWM4_IRQHandler
#define RUNTIME_DEV		PWM4
#define RUNTIME_SSR		PWM4CLK_SSR
#define RUNTIME_PVSR	PWM4CLK_PVSR
#define RUNTIME_IRQ		PWM4_IRQn
#elif YSS_TIMER == RUNTIME_PWM5
#define ISR_RUNTIME		PWM5_IRQHandler
#define RUNTIME_DEV		PWM5
#define RUNTIME_SSR		PWM5CLK_SSR
#define RUNTIME_PVSR	PWM5CLK_PVSR
#define RUNTIME_IRQ		PWM5_IRQn
#elif YSS_TIMER == RUNTIME_PWM6
#define ISR_RUNTIME		PWM6_IRQHandler
#define RUNTIME_DEV		PWM6
#define RUNTIME_SSR		PWM6CLK_SSR
#define RUNTIME_PVSR	PWM6CLK_PVSR
#define RUNTIME_IRQ		PWM6_IRQn
#elif YSS_TIMER == RUNTIME_PWM7
#define ISR_RUNTIME		PWM7_IRQHandler
#define RUNTIME_DEV		PWM7
#define RUNTIME_SSR		PWM7CLK_SSR
#define RUNTIME_PVSR	PWM7CLK_PVSR
#define RUNTIME_IRQ		PWM7_IRQn
#endif

static uint64_t gYssTimeSum;
static bool gUpdateFlag;

uint32_t getClockFrequency(void) __attribute__((optimize("-O1")));
uint32_t getClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->RUNTIME_SSR & CRG_PWMCLK_SSR_PCSS)
	{
	case 1 :
		clk = clock.getMclkFrequency();
		break;
	
	case 2 :
		clk = clock.getRclkFrequency();
		break;
	
	case 3 :
		clk = clock.getOclkFrequency();
		break;

	default :
		return 0;
	}

	return clk >> (CRG->RUNTIME_PVSR & CRG_PWMCLK_PVSR_PCPS);
}

extern "C"
{
	void ISR_RUNTIME(void) __attribute__((optimize("-O1")));
	void ISR_RUNTIME(void)
	{
		if(RUNTIME_DEV->IR & PWM_CHn_IR_MI)
		{
			RUNTIME_DEV->ICR = PWM_CHn_ICR_MIC;
			gUpdateFlag = false;
		}
		else
		{
			RUNTIME_DEV->ICR = PWM_CHn_ICR_OIC;
			gYssTimeSum += TOP;
			gUpdateFlag = true;
		}
	}
}

void initializeSystemTime(void) __attribute__((optimize("-O1")));
void initializeSystemTime(void)
{
	uint32_t clk = getClockFrequency();

	RUNTIME_DEV->PDMR = PWM_CHn_PDMR_PDM;
	RUNTIME_DEV->MR = TOP/2;
	RUNTIME_DEV->LR = TOP;
	RUNTIME_DEV->PR = clk / 1000000 - 1;
	RUNTIME_DEV->IER = PWM_CHn_IER_MIE | PWM_CHn_IER_OIE;

	PWM->SSR |= 1 << YSS_TIMER;
	PWM->IER |= 1 << YSS_TIMER;

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
	uint32_t cnt, flag, iflag;
	uint64_t acc;

	__disable_irq();
	cnt = RUNTIME_DEV->TCR;
	acc = gYssTimeSum;
	flag = RUNTIME_DEV->IR & PWM_CHn_IR_OI;
	iflag = gUpdateFlag;
	__enable_irq();
	
	if(flag && !iflag && cnt < (TOP / 2))
		return cnt + acc + TOP;
	else if(flag && iflag && cnt > (TOP / 2))
		return cnt + acc - TOP;
	else
		return cnt + acc;
}

}

#endif

