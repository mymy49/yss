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

void  __WEAK mutexWatchdogHandler(void)
{
	__NVIC_SystemReset();
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
	thread::protect(); // Prevent scheduler changes while queueing.
	__disable_irq(); // Disable interrupts during queue update.
#if THREAD_WATCHDOG_ENABLE
	uint64_t timeout = runtime::getMsec() + THREAD_WATCHDOG_OVERFLOW_TIME;
#endif
	uint32_t num = mWaitNum;
	mWaitNum++;
	if(mIrqNum >= 0)
		NVIC_DisableIRQ(mIrqNum); // Disable the mutex-associated IRQ if configured.
	__enable_irq(); // Re-enable interrupts after queue update.

	while (num != mCurrentNum)
	{
#if THREAD_WATCHDOG_ENABLE
		if(timeout < runtime::getMsec())
			mutexWatchdogHandler();
#endif
		thread::yield(); // Yield until the current lock sequence reaches this thread.
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
	__disable_irq(); // Disable interrupts during the lock check.
	uint32_t num = mWaitNum;

	if(num != mCurrentNum)
	{
		__enable_irq();
		return false; // Mutex is already held by another thread.
	}

	mWaitNum++;
	if(mIrqNum >= 0)
		NVIC_DisableIRQ(mIrqNum); // Disable any associated IRQ for the new lock.
	__enable_irq(); // Re-enable interrupts after acquiring the lock.

	return true;
#else
	return true;
#endif
}

void Mutex::unlock(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	__disable_irq(); // Disable interrupts while updating lock state.
	mCurrentNum++;
	if(mIrqNum >= 0)
		NVIC_EnableIRQ(mIrqNum); // Re-enable the IRQ disabled while locking.
	__enable_irq();
	thread::unprotect(); // Allow scheduler operations again.
	if (mInit && mWaitNum != mCurrentNum)
		thread::yield(); // Yield if there are waiting threads.
#endif
}

void Mutex::setIrq(IRQn_Type irq)
{
	mIrqNum = irq;
}

