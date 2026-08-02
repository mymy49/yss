/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>
#include "core_cm4.h"

#if defined(__MAX32665_FAMILY)

#include <config.h>
#include <yss/reg.h>

#include <yss/instance.h>
#include <yss/scheduler.h>
#include <string.h>

void mainCore1(void);

static uint32_t gCpu1Msp[4096] __attribute__((aligned(8)));
static uint32_t gCpu1Psp[512] __attribute__((aligned(8)));

uint32_t g_cpu1_vector_table[512] __attribute__((aligned(2048))) = 
{
    (uint32_t)&gCpu1Msp[4096], // 0: CPU1 Initial Main Stack Pointer (MSP)
    (uint32_t)mainCore1, // 1: CPU1 Reset Handler (진입점 함수 주소)
};


void initializeSystem(void)
{
	clock.enableHirc8m();

	clock.enableHirc96m();

	clock.setHclkClockSource(Clock::HCLK_SRC_HIRC96, 0);

	clock.enableCache0();
}

void mainCore1(void)
{
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));
    __DSB();
    __ISB();
#endif

	SCB->VTOR = (uint32_t)g_cpu1_vector_table;
	__asm volatile ("dsb \n isb");

	__set_PSP((uint32_t)&gCpu1Psp[512]);
    __set_CONTROL(__get_CONTROL() | (1U << 1));
    __ISB();

	clock.enableCache1();

	NVIC_SetPriority(PendSV_IRQn, 15);
	SysTick_Config(THREAD_GIVEN_CLOCK);
	__enable_irq();

    while (1)
    {
		thread::yield();
    }
}

void initializeMultiCore(void)
{
	uint32_t *src = &((uint32_t*)SCB->VTOR)[2], *des = (uint32_t*)&g_cpu1_vector_table[2];

	memcpy(des, src, 2040);
	__DSB();

	clock.enableSemaphore();
	clock.enableCpu1(g_cpu1_vector_table);
}

namespace semaphore
{
uint32_t getId()
{
	return (uint32_t)g_cpu1_vector_table == (uint32_t)SCB->VTOR;
}

uint32_t lockSchedule()
{
	while ((MXC_SEMA->semaphores[0] & 0x01U) != 0U)
	{
		__asm volatile ("nop");
	}

	return (uint32_t)g_cpu1_vector_table == (uint32_t)SCB->VTOR;
}

void unlockSchedule()
{
	MXC_SEMA->semaphores[0] = 0;
}
}

void __WEAK initializeDma(void)
{

}

extern "C"
{
void __WEAK SystemCoreClockUpdate(void)
{

}
}

#endif