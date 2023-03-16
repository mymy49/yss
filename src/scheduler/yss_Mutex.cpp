////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

