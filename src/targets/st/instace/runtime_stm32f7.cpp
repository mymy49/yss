/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F7)

#include <config.h>
#include <yss/instance.h>
#include <util/runtime.h>
#include <drv/peripheral.h>
#include <targets/st/bitfield.h>

#if defined(STM32F7)
#if YSS_TIMER == RUNTIME_TIM1
#error "RUNTIME_TIM1은 사용이 불가능합니다."
#elif YSS_TIMER == RUNTIME_TIM2
#define ISR_RUNTIME		TIM2_IRQHandler
#define RUNTIME_DEV		TIM2
#define RUNTIME_IRQ		TIM2_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM2EN_Msk
#define TOP				0x7FFFFFFF
#elif YSS_TIMER == RUNTIME_TIM3
#define ISR_RUNTIME		TIM3_IRQHandler
#define RUNTIME_DEV		TIM3
#define RUNTIME_IRQ		TIM3_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM3EN_Msk
#define TOP				0xFFFF
#elif YSS_TIMER == RUNTIME_TIM4
#define ISR_RUNTIME		TIM4_IRQHandler
#define RUNTIME_DEV		TIM4
#define RUNTIME_IRQ		TIM4_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM4EN_Msk
#define TOP				0xFFFF
#elif YSS_TIMER == RUNTIME_TIM5
#define ISR_RUNTIME		TIM5_IRQHandler
#define RUNTIME_DEV		TIM5
#define RUNTIME_IRQ		TIM5_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM5EN_Msk
#define TOP				0xFFFFFFFF
#elif YSS_TIMER == RUNTIME_TIM6
#define ISR_RUNTIME		TIM6_DAC_IRQHandler
#define RUNTIME_DEV		TIM6
#define RUNTIME_IRQ		TIM6_DAC_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM6EN_Msk
#define TOP				0xFFFF
#elif YSS_TIMER == RUNTIME_TIM7
#define ISR_RUNTIME		TIM7_IRQHandler
#define RUNTIME_DEV		TIM7
#define RUNTIME_IRQ		TIM7_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM7EN_Msk
#define TOP				0xFFFF
#elif YSS_TIMER == RUNTIME_TIM8
#error "RUNTIME_TIM8은 사용이 불가능합니다."
#elif YSS_TIMER == RUNTIME_TIM9
#define ISR_RUNTIME		TIM1_BRK_TIM9_IRQHandler
#define RUNTIME_DEV		TIM9
#define RUNTIME_IRQ		TIM1_BRK_TIM9_IRQn
#define RUNTIME_CLK_APB2
#define RUNTIME_RCC_ENR	RCC->APB2ENR
#define RUNTIME_ENR_MSK	RCC_APB2ENR_TIM9EN_Msk
#define TOP				0xFFFF
#elif YSS_TIMER == RUNTIME_TIM10
#error "RUNTIME_TIM10은 사용이 불가능합니다."
#elif YSS_TIMER == RUNTIME_TIM11
#define ISR_RUNTIME		TIM1_TRG_COM_TIM11_IRQHandler
#define RUNTIME_DEV		TIM11
#define RUNTIME_IRQ		TIM1_TRG_COM_TIM11_IRQn
#define RUNTIME_CLK_APB2
#define RUNTIME_RCC_ENR	RCC->APB2ENR
#define RUNTIME_ENR_MSK	RCC_APB2ENR_TIM11EN_Msk
#define TOP				0xFFFF
#elif YSS_TIMER == RUNTIME_TIM12
#define ISR_RUNTIME		TIM8_BRK_TIM12_IRQHandler
#define RUNTIME_DEV		TIM12
#define RUNTIME_IRQ		TIM8_BRK_TIM12_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM12EN_Msk
#define TOP				0xFFFF
#elif YSS_TIMER == RUNTIME_TIM13
#error "RUNTIME_TIM13은 사용이 불가능합니다."
#elif YSS_TIMER == RUNTIME_TIM14
#define ISR_RUNTIME		TIM8_TRG_COM_TIM14_IRQHandler
#define RUNTIME_DEV		TIM14
#define RUNTIME_IRQ		TIM8_TRG_COM_TIM14_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM14EN_Msk
#define TOP				0xFFFF
#endif
#endif

static uint64_t gYssTimeSum = (int64_t)(TOP) * -1;

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);


uint32_t getClockFrequency(void) __attribute__((optimize("-O1")));
uint32_t getClockFrequency(void)
{
#if defined (RUNTIME_CLK_APB1)
	return getApb1TimerClockFrequency();	
#elif defined (RUNTIME_CLK_APB2)
	return getApb2TimerClockFrequency();
#else
	return 0;
#endif
}

extern "C"
{
	void ISR_RUNTIME(void) __attribute__((optimize("-O1")));
	void ISR_RUNTIME(void)
	{
		RUNTIME_DEV->SR = ~TIM_SR_UIF_Msk;
		gYssTimeSum += TOP;
	}
}

void initializeSystemTime(void) __attribute__((optimize("-O1")));
void initializeSystemTime(void)
{
	RUNTIME_RCC_ENR |= RUNTIME_ENR_MSK;

	RUNTIME_DEV->PSC = (uint16_t)(getClockFrequency() / 1000000) - 1;
	RUNTIME_DEV->ARR = TOP;
	RUNTIME_DEV->CNT = TOP;
	RUNTIME_DEV->DIER |= TIM_DIER_UIE_Msk;
	RUNTIME_DEV->CR1 |= TIM_CR1_CEN_Msk | TIM_CR1_ARPE_Msk | TIM_CR1_UIFREMAP_Msk;	

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
	__disable_irq();
	uint32_t cnt = RUNTIME_DEV->CNT;
	uint64_t sum = gYssTimeSum;
	__enable_irq();

	if(cnt & 0x80000000)
		return (cnt & 0x7FFFFFFF) + TOP + sum;
	else
		return cnt + sum;
}
}

#endif

