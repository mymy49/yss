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

#include <drv/peripheral.h>

#if defined(NRF52840_XXAA)

#include <drv/Timer.h>
#include <yss/reg.h>
#include <cmsis/mcu/nordic/nrf52840_bitfields.h>

Timer::Timer(YSS_TIMER_Peri *peri, const Drv::Config drvConfig) : Drv(drvConfig)
{
	mPeri = peri;
	mIsrUpdate = 0;
	mTimeUpdateCnt = 0;
}

void Timer::initSystemTime(void)
{
	mPeri->MODE = 0;			// Timer Mode
	mPeri->BITMODE = 3;			// 32bit
	mPeri->PRESCALER = 4;		// 1 MHz
	mPeri->SHORTS = 0x01;		// CC[0] 설정
	mPeri->CC[0] = 0xFFFFFFFF;
	enableUpdateInterrupt();
}

void Timer::init(uint32_t psc, uint32_t arr)
{
	mPeri->MODE = 0;			// Timer Mode
	mPeri->BITMODE = 3;			// 32bit
	mPeri->PRESCALER = 0;		// 16 MHz
	mPeri->CC[0] = arr;
	mPeri->SHORTS = 0x01;		// CC[0] 설정
}

void Timer::init(uint32_t freq)
{
	uint32_t psc, arr, clk = 16000000;

	arr = clk / freq;

	mPeri->MODE = 0;			// Timer Mode
	mPeri->BITMODE = 3;			// 32bit
	mPeri->PRESCALER = 0;		// 16 MHz
	mPeri->CC[0] = arr;
	mPeri->SHORTS = 0x01;		// CC[0] 설정
}

void Timer::enableUpdateInterrupt(bool en)
{
	if(en)
		mPeri->INTENSET = TIMER_INTENSET_COMPARE0_Msk;	// CC[0] 활성화
	else
		mPeri->INTENCLR = TIMER_INTENCLR_COMPARE0_Msk;	// CC[0] 비활성화
}

void Timer::start(void)
{
	mPeri->TASKS_START = 1;
}

void Timer::stop(void)
{
	mPeri->TASKS_STOP = 1;
}

uint32_t Timer::getCounterValue(void)
{
	mPeri->TASKS_CAPTURE[1] = 1;
	return mPeri->CC[1];
}

uint32_t Timer::getOverFlowCount(void)
{
	return 0xFFFFFFFF;
}

void Timer::setUpdateIsr(void (*isr)(void))
{
	mIsrUpdate = isr;
}

void Timer::isrUpdate(void)
{
	if (mIsrUpdate)
		mIsrUpdate();
	mTimeUpdateCnt++;
}

#endif