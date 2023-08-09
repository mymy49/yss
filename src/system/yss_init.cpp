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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <internal/malloc.h>
#include <internal/system.h>
#include <internal/systick.h>
#include <internal/time.h>
#include <yss/event.h>
#include <yss/instance.h>
#include <std_ext/malloc.h>
#include <drv/peripheral.h>

#include <yss/instance.h>

#define YSS_L_HEAP_TOTAL_CLUSTER_SIZE		(YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE / 32)
#define YSS_L_HEAP_CLUSTER_BASE_ADDR		(YSS_SDRAM_ADDR)
#define YSS_L_HEAP_TABLE_BASE_ADDR			(YSS_L_HEAP_CLUSTER_BASE_ADDR + YSS_L_HEAP_TOTAL_CLUSTER_SIZE * sizeof(int32_t))
#define YSS_L_HEAP_BASE_ADDR				(YSS_L_HEAP_TABLE_BASE_ADDR + YSS_L_MAX_NUM_OF_MALLOC * 12)

void initializeDma(void);

void initializeLheap(void)
{
#if YSS_L_HEAP_USE == true
	uint32_t *sdram = (uint32_t *)YSS_SDRAM_ADDR;

	while ((uint32_t)sdram < YSS_L_HEAP_BASE_ADDR)
		*sdram++ = 0;
#endif
}

void initializeCheap(void)
{
#if YSS_C_HEAP_USE == true && defined(CCMDATARAM_BASE)
	uint32_t *ccm = (uint32_t *)CCMDATARAM_BASE;

	while ((uint32_t)ccm < YSS_C_HEAP_BASE_ADDR)
		*ccm++ = 0;
#endif
}

void initializeYss(void)
{
#ifndef YSS_DRV_TIMER_UNSUPPORTED
	// 내장 시계 활성화
	initializeSystemTime();
#endif

#if defined(ERROR_MCU_NOT_ABLE) == false
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	// 생성자에서 Mutex를 초기화 하기 전에 다른 인스턴스의 생성자가 mutex.lock()을 호출하면 시스템이 
	// 먹통되는 문제를가 발생함. 이를 수정하기 위해, 이 곳에서 초기화를 진행함. 
	Mutex mutex;
	mutex.initializeMutex();

	// SYSTICK 활성화
	NVIC_SetPriority(PendSV_IRQn, 15);
	SysTick_Config(THREAD_GIVEN_CLOCK);
#endif

	// DMA 활성화
	initializeDma();

#if USE_GUI == true && !defined(YSS_DRV_DMA2D_UNSUPPORTED) && defined(DMA2D_ENABLE)
	dma2d.enableClock(true);
	dma2d.initialize();
	dma2d.enableInterrupt(true);
#endif

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE && USE_EVENT && !defined(YSS_DRV_DMA2D_UNSUPPORTED)
	event::init();
#endif

#if !defined(YSS_DRV_EXTI_UNSUPPORTED)
	exti.enableClock(true);
	exti.enableInterrupt(true);
#endif

#endif
}

