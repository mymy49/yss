////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
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
	clock.peripheral.setDmaEn(true);
#if defined(YSS_NVIC_DMA_CHANNEL_1)
	nvic.setDmaChannel1En(true);
	dmaChannel1.setClockEn(true);
	dmaChannel1.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_2)
	nvic.setDmaChannel2En(true);
	dmaChannel2.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_3)
	nvic.setDmaChannel3En(true);
	dmaChannel3.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_4)
	nvic.setDmaChannel4En(true);
	dmaChannel4.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_5)
	nvic.setDmaChannel5En(true);
	dmaChannel5.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_6)
	nvic.setDmaChannel6En(true);
	dmaChannel6.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_7)
	nvic.setDmaChannel7En(true);
	dmaChannel7.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_8)
	nvic.setDmaChannel8En(true);
	dmaChannel8.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_9)
	nvic.setDmaChannel9En(true);
	dmaChannel9.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_10)
	nvic.setDmaChannel10En(true);
	dmaChannel10.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_11)
	nvic.setDmaChannel11En(true);
	dmaChannel11.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_12)
	nvic.setDmaChannel12En(true);
	dmaChannel12.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_13)
	nvic.setDmaChannel13En(true);
	dmaChannel13.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_14)
	nvic.setDmaChannel14En(true);
	dmaChannel14.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_15)
	nvic.setDmaChannel15En(true);
	dmaChannel15.init();
#endif
#if defined(YSS_NVIC_DMA_CHANNEL_16)
	nvic.setDmaChannel16En(true);
	dmaChannel16.init();
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)

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