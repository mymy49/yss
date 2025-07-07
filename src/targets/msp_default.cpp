/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss.h>
#include <cmsis/cmsis_compiler.h>

void initializeSystem(void);
void initializeSdram(void);

void initializeLheap(void);
void initializeCheap(void);

extern uint32_t gCoreClockFrequency;
extern uint32_t gAhbClockFrequency;
extern uint32_t gApb1ClockFrequency;
extern uint32_t gApb2ClockFrequency;

#ifndef DEFAULT_CLOCK_SPEED
#define DEFAULT_CLOCK_SPEED 1000000
#endif

extern "C"
{
#if defined(CPU_MIMXRT1011DAE5A)
	void SystemInitHook(void)
#else
	void SystemInit(void)
#endif
	{
		// STM32 Cube IDE에서 FPU 초기화에 사용됩니다.
#if defined(ST_CUBE_IDE) && (__FPU_PRESENT == 1) && (__FPU_USED == 1)
		SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
#endif
		// 시스템 클럭 및 외부 메모리를 초기화 한다.
		// 각 MCU마다 initializeSystem() 함수가 정의되어 있다.
		// 현재 파일의 하위 폴더에 제조사 별로 구분되어 작성되어 있다.
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE)
		initializeSystem();
#endif

#if YSS_L_HEAP_USE == true
		// 사용자가 정의한 SDRAM 설정 함수 호출
		initializeSdram();

		// SDRAM의 Heap 영역 메모리 관리 변수 초기화
		initializeLheap();
#endif
#if YSS_C_HEAP_USE == true
		// Core Coupled Memory의 Heap 영역 메모리 관리 변수 초기화
		yss::initializeCheap();
#endif
	}

	void __WEAK SystemCoreClockUpdate(void)
	{

	}
}

#if YSS_L_HEAP_USE == true
void __WEAK initializeSdram(void)
{
}
#endif

void __WEAK initDma(void)
{
}
