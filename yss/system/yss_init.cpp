////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>

#include <config.h>
#include <internal/malloc.h>
#include <internal/scheduler.h>
#include <internal/system.h>
#include <internal/systick.h>
#include <internal/time.h>
#include <yss/event.h>
#include <yss/instance.h>
#include <yss/malloc.h>
#include <drv/peripheral.h>

#include <yss/instance.h>

#define YSS_L_HEAP_TOTAL_CLUSTER_SIZE (YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE / 32)

namespace yss
{
	static int gSystemClockFrequency;
	
	int getSystemClockFrequency(void)
	{
		return gSystemClockFrequency;
	}

	void setSystemClockFrequency(int clock)
	{
		gSystemClockFrequency = clock;
	}

void initLheap(void)
{
#if YSS_L_HEAP_USE == true
	unsigned int *sdram = (unsigned int *)YSS_SDRAM_ADDR;

	while ((unsigned int)sdram < YSS_L_HEAP_BASE_ADDR)
		*sdram++ = 0;
#endif
}

void initCheap(void)
{
#if YSS_C_HEAP_USE == true && defined(CCMDATARAM_BASE)
	unsigned long *ccm = (unsigned long *)CCMDATARAM_BASE;

	while ((unsigned long)ccm < YSS_C_HEAP_BASE_ADDR)
		*ccm++ = 0;
#endif
}

void init(void)
{
#if defined(ERROR_MCU_NOT_ABLE) == false
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	Mutex mutex;
	mutex.init();

	// 문맥전환 활성화
	NVIC_SetPriority(PendSV_IRQn, 15);
	initScheduler();
	SysTick_Config(THREAD_GIVEN_CLOCK);
#endif
#ifndef YSS_DRV_TIMER_UNSUPPORTED
	initSystemTime();
#endif

#if defined(DMA1) && !defined(YSS_DRV_DMA_UNSUPPORTED)

	// DMA 활성화
	//dma.setClockEn(true);
	//dma.init();
	//dma.setIntEn(true);

#if defined(STM32F7) || defined(STM32F4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F1) || defined(STM32F0)

#if defined(DMA1_Channel1)
	dma1Stream1.init();
#endif

#if defined(DMA1_Channel2)
	dma1Stream2.init();
#endif

#if defined(DMA1_Channel3)
	dma1Stream3.init();
#endif

#if defined(DMA1_Channel4)
	dma1Stream4.init();
#endif

#if defined(DMA1_Channel5)
	dma1Stream5.init();
#endif

#if defined(DMA1_Channel6)
	dma1Stream6.init();
#endif

#if defined(DMA1_Channel7)
	dma1Stream7.init();
#endif

#if defined(DMA2_Channel1)
	dma2Stream1.init();
#endif

#if defined(DMA2_Channel2)
	dma2Stream2.init();
#endif

#if defined(DMA2_Channel3)
	dma2Stream3.init();
#endif

#if defined(DMA2_STREAM4_ENABLE) && defined(DMA2_Channel4)
	dma2Stream4.init();
#endif

#if defined(DMA2_STREAM5_ENABLE) && defined(DMA2_Channel5)
	dma2Stream5.init();
#endif

#endif

#endif

#if defined(DMA2D) && USE_GUI == true && !defined(YSS_DRV_DMA2D_UNSUPPORTED)

#endif

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE && USE_EVENT && !defined(YSS_DRV_DMA2D_UNSUPPORTED)
	event::init();
#endif

#if defined(SYSCFG) && !defined(YSS_DRV_SYSCFG_UNSUPPORTED)
	syscfg.setClockEn(true);
#endif

#if (defined(EXTI) || defined(EIC)) && !defined(YSS_DRV_EXTI_UNSUPPORTED)
	exti.setClockEn(true);
	exti.setIntEn(true);
#if defined(EIC)
	exti.init();
#endif
#endif
#endif
}
}