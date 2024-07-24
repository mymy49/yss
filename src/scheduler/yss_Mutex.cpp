/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/Mutex.h>
#include <drv/peripheral.h>
#include <yss/thread.h>
#include <cmsis/cmsis_compiler.h>

bool Mutex::mInit = false;

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
	thread::protect();
	__disable_irq();
	uint32_t num = mWaitNum;
	mWaitNum++;
	if(mIrqNum >= 0)
		NVIC_DisableIRQ(mIrqNum);
	__enable_irq();

	while (num != mCurrentNum)
	{
		thread::yield();
	}

	return num;
#else
	return 0;
#endif
}

bool Mutex::check(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	thread::protect();
	__disable_irq();
	uint32_t num = mWaitNum;

	if(num != mCurrentNum)
	{
		__enable_irq();
		return false;
	}

	mWaitNum++;
	if(mIrqNum >= 0)
		NVIC_DisableIRQ(mIrqNum);
	__enable_irq();

	return true;
#else
	return true;
#endif
}

void Mutex::unlock(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	__disable_irq();
	mCurrentNum++;
	if(mIrqNum >= 0)
		NVIC_EnableIRQ(mIrqNum);
	__enable_irq();
	thread::unprotect();
	if (mInit && mWaitNum != mCurrentNum)
		thread::yield();
#endif
}

void Mutex::setIrq(IRQn_Type irq)
{
	mIrqNum = irq;
}

