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

// Stacks allocated for Core 1 (CPU1)
static uint32_t gCpu1Msp[4096] __attribute__((aligned(8)));
static uint32_t gCpu1Psp[512] __attribute__((aligned(8)));

// Vector table for CPU1. Core 0 and Core 1 share peripheral interrupts,
// but need separate Reset handler and initial Stack Pointer entries.
uint32_t g_cpu1_vector_table[512] __attribute__((aligned(2048))) = 
{
    (uint32_t)&gCpu1Msp[4096], // 0: CPU1 Initial Main Stack Pointer (MSP)
    (uint32_t)mainCore1,       // 1: CPU1 Reset Handler (Entry point function address)
};


void initializeSystem(void)
{
	clock.enableHirc8m();

	clock.enableHirc96m();

	clock.setHclkClockSource(Clock::HCLK_SRC_HIRC96, 0);

	clock.enableCache0();
}

/**
 * @brief Main entry function (Reset Handler) for Core 1 (CPU1).
 * 
 * Sets up the VTOR, PSP stack pointer, configures Core 1 caches,
 * sets the PendSV interrupt priority, starts the scheduler's SysTick,
 * and enters the scheduler loop.
 */
void mainCore1(void)
{
	// Enable FPU coprocessor for Core 1 if supported
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));
    __DSB();
    __ISB();
#endif

	// Set VTOR to CPU1's specific vector table
	SCB->VTOR = (uint32_t)g_cpu1_vector_table;
	__asm volatile ("dsb \n isb");

	// Set up Process Stack Pointer (PSP) and switch to thread mode with PSP
	__set_PSP((uint32_t)&gCpu1Psp[512]);
    __set_CONTROL(__get_CONTROL() | (1U << 1));
    __ISB();

	// Enable cache for Core 1
	clock.enableCache1();

	// Configure PendSV for lowest priority thread switching
	NVIC_SetPriority(PendSV_IRQn, 15);
	// Start SysTick timer to tick the scheduler on Core 1
	SysTick_Config(THREAD_GIVEN_CLOCK);
	__enable_irq();

	// Core 1 enters scheduling loop, immediately yielding to the first thread
    while (1)
    {
		thread::yield();
    }
}

/**
 * @brief Initializes dual-core execution by copying vector tables,
 * enabling the hardware semaphore, and booting CPU1.
 */
void initializeMultiCore(void)
{
	// Copy interrupt vector pointers from Core 0 to Core 1 vector table
	uint32_t *src = &((uint32_t*)SCB->VTOR)[2], *des = (uint32_t*)&g_cpu1_vector_table[2];

	memcpy(des, src, 2040);
	__DSB();

	// Enable hardware semaphore and start Core 1 execution
	clock.enableSemaphore();
	clock.enableCpu1(g_cpu1_vector_table);
}

namespace semaphore
{
uint32_t getId()
{
	// Identify core by checking the active Vector Table Offset Register
	return (uint32_t)g_cpu1_vector_table == (uint32_t)SCB->VTOR;
}

uint32_t lockSchedule()
{
	// Spin lock using MAX32665 Hardware Semaphore 0.
	// Reading this hardware register returns 0 on success (setting it to locked),
	// or 1 if it is already locked by the other core.
	while ((MXC_SEMA->semaphores[0] & 0x01U) != 0U)
	{
		__asm volatile ("nop");
	}

	return (uint32_t)g_cpu1_vector_table == (uint32_t)SCB->VTOR;
}

void unlockSchedule()
{
	// Release the hardware semaphore 0 lock
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