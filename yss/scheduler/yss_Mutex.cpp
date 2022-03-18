////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/Mutex.h>
#include <drv/peripheral.h>
#include <yss/thread.h>

bool Mutex::mInit = false;

void Mutex::init(void)
{
	mInit = true;
}

Mutex::Mutex(void)
{
	mWaitNum = 0;
	mCurrentNum = 0;
}

unsigned int Mutex::lock(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	thread::protect();
	__disable_irq();
	unsigned int num = mWaitNum;
	mWaitNum++;
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

void Mutex::unlock(void)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	__disable_irq();
	mCurrentNum++;
	__enable_irq();
	thread::unprotect();
	if (mInit && mWaitNum != mCurrentNum)
		thread::yield();
#endif
}

void Mutex::unlock(unsigned short num)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	__disable_irq();
	mCurrentNum++;
	__enable_irq();
#endif
}

void Mutex::wait(unsigned int key)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
	while (key >= mCurrentNum)
	{
		thread::yield();
	}
#endif
}

unsigned int Mutex::getCurrentNum(void)
{
	return mCurrentNum;
}