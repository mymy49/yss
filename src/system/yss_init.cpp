/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss/malloc.h>
#include <yss/event.h>
#include <yss/instance.h>
#include <std_ext/malloc.h>
#include <drv/peripheral.h>
#include <string.h>
#include <yss/instance.h>

#define YSS_L_HEAP_TOTAL_CLUSTER_SIZE		(YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE / 32)
#define YSS_L_HEAP_CLUSTER_BASE_ADDR		(YSS_SDRAM_ADDR)
#define YSS_L_HEAP_TABLE_BASE_ADDR			(YSS_L_HEAP_CLUSTER_BASE_ADDR + YSS_L_HEAP_TOTAL_CLUSTER_SIZE * sizeof(int32_t))
#define YSS_L_HEAP_BASE_ADDR				(YSS_L_HEAP_TABLE_BASE_ADDR + YSS_L_MAX_NUM_OF_MALLOC * 12)

void initializeDma(void);

void initializeDmaCopy(void);

void initializeSystemTime(void);

void initializeLheap(void)
{
#if YSS_L_HEAP_USE == true
	uint32_t *sdram = (uint32_t *)YSS_SDRAM_ADDR;
	
	memset(sdram, 0x00, YSS_L_HEAP_BASE_ADDR - YSS_SDRAM_ADDR);
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
#if !defined(YSS_DRV_TIMER_UNSUPPORTED) || defined(YSS__RUNTIME_SUPPORT)
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
#if !defined(YSS_DRV_DMA_UNSUPPORTED)
	initializeDma();

#if defined(YSS__DMA_ALLOCATION)
	initializeDmaCopy();
#endif
#endif

#if USE_GUI == true && !defined(YSS_DRV_DMA2D_UNSUPPORTED) && defined(DMA2D_ENABLE)
	dma2d.enableClock(true);
	dma2d.initialize();
	dma2d.enableInterrupt(true);
#endif

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE && USE_EVENT && !defined(YSS_DRV_DMA2D_UNSUPPORTED)
	event::init();
#endif

#if defined(EXTI)
	exti.enableClock(true);
	exti.enableInterrupt(true);
#elif defined(__M46x_SUBFAMILY)
#if defined(PA) && defined(PA_EXIST)
	gpioA.enableInterrupt();
#endif
#if defined(PB) && defined(PB_EXIST)
	gpioB.enableInterrupt();
#endif
#if defined(PC) && defined(PC_EXIST)
	gpioC.enableInterrupt();
#endif
#if defined(PD) && defined(PD_EXIST)
	gpioD.enableInterrupt();
#endif
#if defined(PE) && defined(PE_EXIST)
	gpioE.enableInterrupt();
#endif
#if defined(PF) && defined(PF_EXIST)
	gpioF.enableInterrupt();
#endif
#if defined(PG) && defined(PG_EXIST)
	gpioG.enableInterrupt();
#endif
#if defined(PH) && defined(PH_EXIST)
	gpioH.enableInterrupt();
#endif
#if defined(PI) && defined(PI_EXIST)
	gpioI.enableInterrupt();
#endif
#if defined(PJ) && defined(PJ_EXIST)
	gpioJ.enableInterrupt();
#endif
#endif

#endif
}

