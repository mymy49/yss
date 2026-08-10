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
#if defined(YSS__MULTI_CORE)
void  __WEAK mutexWatchdogHandler(void)
{
	__NVIC_SystemReset();
}
#endif

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
	thread::protect(); // Prevent scheduler changes while queueing.
	__disable_irq();   // Disable interrupts during the atomic ticket-number fetch.
#if THREAD_WATCHDOG_ENABLE
	// Capture the deadline as an absolute millisecond timestamp.
	uint64_t timeout = runtime::getMsec() + THREAD_WATCHDOG_OVERFLOW_TIME;
#endif
	// Take the next available ticket; mWaitNum acts as the ticket dispenser.
	uint32_t num = mWaitNum;
	mWaitNum++;
	if(mIrqNum >= 0)
		NVIC_DisableIRQ(mIrqNum); // Disable the mutex-associated IRQ if configured.
	__enable_irq();    // Re-enable interrupts after the ticket has been issued.

	// Wait until the mutex service counter reaches our ticket number.
	while (num != mCurrentNum)
	{
#if THREAD_WATCHDOG_ENABLE
		// If the deadline has passed without acquiring the lock, invoke the watchdog.
		if(timeout < runtime::getMsec())
			mutexWatchdogHandler();
#endif
		thread::yield(); // Yield the CPU while waiting for earlier holders to unlock.
	}

	return num;
#else
	return 0;
#endif
}

bool Mutex::check(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	thread::protect(); // Protect scheduler state while checking lock availability.
	__disable_irq();   // Disable interrupts during the lock check.
	uint32_t num = mWaitNum;

	if(num != mCurrentNum)
	{
		__enable_irq();
		return false; // Mutex is already held by another thread; do not block.
	}

	// The mutex is free: claim the next ticket and disable the associated IRQ.
	mWaitNum++;
	if(mIrqNum >= 0)
		NVIC_DisableIRQ(mIrqNum); // Disable any associated IRQ for the new lock holder.
	__enable_irq();   // Re-enable interrupts after successfully acquiring the lock.

	return true;
#else
	return true;
#endif
}

void Mutex::unlock(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	__disable_irq(); // Disable interrupts while updating the service counter.
	mCurrentNum++;   // Advance the service counter so the next ticket holder can proceed.
	if(mIrqNum >= 0)
		NVIC_EnableIRQ(mIrqNum); // Re-enable the IRQ that was disabled while locking.
	__enable_irq();
	thread::unprotect(); // Allow scheduler operations (e.g., preemption) to resume.
	if (mInit && mWaitNum != mCurrentNum)
		thread::yield(); // Yield if there are threads waiting for this mutex.
#endif
}

void Mutex::setIrq(IRQn_Type irq)
{
	mIrqNum = irq;
}
