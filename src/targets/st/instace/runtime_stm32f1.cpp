/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F103xE) || defined(STM32F103xB)

#include <config.h>
#include <yss/instance.h>
#include <util/runtime.h>
#include <drv/peripheral.h>
#include <targets/st/bitfield.h>

#if defined(STM32F103xE)
#if YSS_TIMER == RUNTIME_TIM1
#error "RUNTIME_TIM1은 사용이 불가능합니다."
#elif YSS_TIMER == RUNTIME_TIM2
#define ISR_RUNTIME		TIM2_IRQHandler
#define RUNTIME_DEV		TIM2
#define RUNTIME_IRQ		TIM2_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM2EN_Msk
#define TOP				0xFFFF
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
#define TOP				0xFFFF
#elif YSS_TIMER == RUNTIME_TIM6
#error "RUNTIME_TIM6은 사용이 불가능합니다."
#elif YSS_TIMER == RUNTIME_TIM7
#error "RUNTIME_TIM7은 사용이 불가능합니다."
#elif YSS_TIMER == RUNTIME_TIM8
#error "RUNTIME_TIM8은 사용이 불가능합니다."
#endif
#elif defined(STM32F103xB)
#if YSS_TIMER == RUNTIME_TIM1
#error "RUNTIME_TIM1은 사용이 불가능합니다."
#elif YSS_TIMER == RUNTIME_TIM2
#define ISR_RUNTIME		TIM2_IRQHandler
#define RUNTIME_DEV		TIM2
#define RUNTIME_IRQ		TIM2_IRQn
#define RUNTIME_CLK_APB1
#define RUNTIME_RCC_ENR	RCC->APB1ENR
#define RUNTIME_ENR_MSK	RCC_APB1ENR_TIM2EN_Msk
#define TOP				0xFFFF
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
#else
#error "RUNTIME_TIM4 이상은 지원되지 않습니다."
#endif
#endif

static uint64_t gYssTimeSum = (int64_t)(TOP) * -1;
static bool gUpdateFlag;

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
		uint32_t dier = RUNTIME_DEV->DIER, sr = RUNTIME_DEV->SR;

		if (dier & TIM_DIER_UIE_Msk && sr & TIM_SR_UIF_Msk)
		{
			RUNTIME_DEV->SR = ~TIM_SR_UIF_Msk;
			gYssTimeSum += TOP;
			gUpdateFlag = true;
		}
		else if (dier & TIM_DIER_CC1IE_Msk && sr & TIM_SR_CC1IF_Msk)
		{
			RUNTIME_DEV->SR = ~TIM_SR_CC1IF_Msk;
			gUpdateFlag = false;
		}
	}
}

void initializeSystemTime(void) __attribute__((optimize("-O1")));
void initializeSystemTime(void)
{
	RUNTIME_RCC_ENR |= RUNTIME_ENR_MSK;

	RUNTIME_DEV->PSC = (uint16_t)(getClockFrequency() / 1000000) - 1;
	RUNTIME_DEV->ARR = TOP;
	RUNTIME_DEV->CNT = TOP;
	RUNTIME_DEV->CCR1 = TOP / 2;
	RUNTIME_DEV->DIER |= TIM_DIER_UIE_Msk | TIM_DIER_CC1IE_Msk;
	RUNTIME_DEV->CR1 |= TIM_CR1_CEN_Msk | TIM_CR1_ARPE_Msk;

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
	cnt = RUNTIME_DEV->CNT;
	acc = gYssTimeSum;
	flag = RUNTIME_DEV->SR & TIM_SR_UIF_Msk;
	iflag = gUpdateFlag;
	__enable_irq();
	
	if(flag && !iflag && cnt < (TOP / 2))
		return (uint64_t)cnt + acc + TOP;
	else if(flag && iflag && cnt > (TOP / 2))
		return (uint64_t)cnt + acc - TOP;
	else
		return (uint64_t)cnt + acc;
}

}

#endif

