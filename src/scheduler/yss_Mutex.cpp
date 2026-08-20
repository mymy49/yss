/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/Mutex.h>
#include <drv/peripheral.h>
#include <yss/scheduler.h>
#include <config.h>
#include <util/runtime.h>

bool Mutex::mInit = false;

/// @brief Default watchdog handler called when a mutex acquisition times out.
/// @details This weak symbol can be overridden by the application to implement a
///          custom recovery strategy.  The default implementation performs a system
///          reset via NVIC_SystemReset() to recover from a detected deadlock condition.

void  __attribute__((weak)) mutexWatchdogHandler(void)
{
#if __CM4_CMSIS_VERSION_MAIN == 3
	NVIC_SystemReset();
#else
	__NVIC_SystemReset();
#endif
}

void Mutex::initializeMutex(void)
{
	mInit = true;
}

Mutex::Mutex(void)
{
	mWaitNum = 0;
	mCurrentNum = 0;
	mIrqNum = (IRQn_Type)-1;
}

uint32_t Mutex::lock(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	thread::protect(); // Prevent thread removal while waiting for or holding the mutex[cite: 2, 6].

#if THREAD_WATCHDOG_ENABLE
	// Capture the deadline timestamp before entering the wait loop.
	uint64_t timeout = runtime::getMsec() + THREAD_WATCHDOG_OVERFLOW_TIME;
#endif

	// 1. Atomically issue a ticket number using PRIMASK preservation.
	uint32_t primask = __get_PRIMASK();
	__disable_irq();
	uint32_t num = mWaitNum++;
	__set_PRIMASK(primask);

	// 2. Wait until the service counter matches our ticket number[cite: 2].
	while (num != mCurrentNum)
	{
#if THREAD_WATCHDOG_ENABLE
		// Trigger watchdog recovery if acquisition deadline is exceeded[cite: 2].
		if (timeout < runtime::getMsec())
			mutexWatchdogHandler();
#endif
		thread::yield(); // Relinquish remaining time slice to allow other threads to run[cite: 2].
	}

	// 3. Disable the associated peripheral IRQ only after acquiring ownership[cite: 2, 6].
	// This prevents earlier unlock() calls from prematurely re-enabling the IRQ.
	if (mIrqNum >= 0)
		NVIC_DisableIRQ(mIrqNum);

	return num;
#else
	return 0;
#endif
}

void Mutex::unlock(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	// 1. Re-enable peripheral IRQ and advance service counter atomically[cite: 2].
	uint32_t primask = __get_PRIMASK();
	__disable_irq();

	if (mIrqNum >= 0)
		NVIC_EnableIRQ(mIrqNum); // Restore the peripheral IRQ as lock ownership is released[cite: 2, 6].

	mCurrentNum++; // Advance ticket counter to hand over ownership to the next waiter[cite: 2, 6].
	__set_PRIMASK(primask);

	// 2. Allow thread removal operations to resume[cite: 2].
	thread::unprotect();

	// 3. Yield immediately if other threads are waiting for this mutex[cite: 2, 6].
	if (mInit && mWaitNum != mCurrentNum)
		thread::yield();
#endif
}

void Mutex::setIrq(IRQn_Type irq)
{
	mIrqNum = irq;
}
