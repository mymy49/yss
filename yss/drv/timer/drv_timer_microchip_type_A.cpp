////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(__SAML21E15A__) || defined(__SAML21E15B__) || defined(__SAML21E16A__) || defined(__SAML21E16B__) || \
	defined(__SAML21E17A__) || defined(__SAML21E17B__) || defined(__SAML21E18B__) || defined(__SAML21G16A__) || \
	defined(__SAML21G16B__) || defined(__SAML21G17A__) || defined(__SAML21G17B__) || defined(__SAML21G18A__) || \
	defined(__SAML21G18B__) || defined(__SAML21J16A__) || defined(__SAML21J16B__) || defined(__SAML21J17A__) || \
	defined(__SAML21J17B__) || defined(__SAML21J18A__) || defined(__SAML21J18B__)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/timer/drv_st_timer_type_A_register.h>
#include <yss/instance.h>

static unsigned int getTimerClkFreq(void)
{
	return clock.getApbClkFrequency();
}

//********** Timer0 구성 설정 및 변수 선언 **********
#if defined(TIM0_ENABLE) && defined(TC0)
static void setTim0ClockEn(bool en)
{
	clock.peripheral.setTimer0En(en);
}

static void setTim0IntEn(bool en)
{
	nvic.setTimer0En(en);
}

drv::Timer timer0(TC0, setTim0ClockEn, setTim0IntEn, getTimerClkFreq);

extern "C"
{
	void TC0_Handler(void)
	{
		TcCount32 *peri = (TcCount32 *)TC0;
		peri->INTFLAG.reg = TC_INTFLAG_OVF;
		timer0.isrUpdate();
	}
}
#endif

//********** Timer1 구성 설정 및 변수 선언 **********
#if defined(TIM1_ENABLE) && defined(TC2)
static void setTim1ClockEn(bool en)
{
	clock.peripheral.setTimer2En(en);
}

static void setTim1IntEn(bool en)
{
	nvic.setTimer2En(en);
}

drv::Timer timer1(TC2, setTim1ClockEn, setTim1IntEn, getTimerClkFreq);

extern "C"
{
	void TC2_Handler(void)
	{
		TcCount32 *peri = (TcCount32 *)TC2;
		peri->INTFLAG.reg = TC_INTFLAG_OVF;
		timer1.isrUpdate();
	}
}
#endif

//********** Timer2 구성 설정 및 변수 선언 **********
#if defined(TIM2_ENABLE) && defined(TC4) && defined(TC5)
static void setTim2ClockEn(bool en)
{
	clock.peripheral.setTimer4En(en);
}

static void setTim2IntEn(bool en)
{
	nvic.setTimer4En(en);
}

drv::Timer timer2(TC4, setTim2ClockEn, setTim2IntEn, getTimerClkFreq);

extern "C"
{
	void TC4_Handler(void)
	{
		TcCount32 *peri = (TcCount32 *)TC4;
		peri->INTFLAG.reg = TC_INTFLAG_OVF;
		timer2.isrUpdate();
	}
}
#endif

namespace drv
{
Timer::Timer(Tc *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc)
{
	mPeri = peri;
	mGetClockFreq = getClockFreq;
}

unsigned int Timer::getOverFlowCount(void)
{
	return 1000;
}

void Timer::initSystemTime(void)
{
	TcCount32 *peri = (TcCount32 *)mPeri;
	unsigned int clk = mGetClockFreq();

	mDiv = clk / 1000;
	peri->CTRLA.bit.MODE = TC_CTRLA_MODE_COUNT32_Val;
	peri->CC[0].reg = clk;
	peri->INTENSET.bit.OVF = true;
	peri->WAVE.bit.WAVEGEN = TC_WAVE_WAVEGEN_MFRQ_Val;
}

void Timer::init(unsigned int psc, unsigned int arr)
{
	TcCount32 *peri = (TcCount32 *)mPeri;

	peri->CTRLA.bit.MODE = TC_CTRLA_MODE_COUNT32_Val;
	peri->CC[0].reg = psc * arr;
	peri->WAVE.bit.WAVEGEN = TC_WAVE_WAVEGEN_MFRQ_Val;
}

void Timer::init(unsigned int freq)
{
	TcCount32 *peri = (TcCount32 *)mPeri;
	unsigned int clk = mGetClockFreq();

	peri->CTRLA.bit.MODE = TC_CTRLA_MODE_COUNT32_Val;
	peri->CC[0].reg = clk / freq;
	peri->WAVE.bit.WAVEGEN = TC_WAVE_WAVEGEN_MFRQ_Val;
}

void Timer::setUpdateIntEn(bool en)
{
	TcCount32 *peri = (TcCount32 *)mPeri;

	peri->INTENSET.bit.OVF = en;
}

void Timer::start(void)
{
	TcCount32 *peri = (TcCount32 *)mPeri;

	peri->INTFLAG.reg = TC_INTFLAG_OVF;
	peri->CTRLA.bit.ENABLE = true;
}

void Timer::stop(void)
{
	TcCount32 *peri = (TcCount32 *)mPeri;

	peri->CTRLA.bit.ENABLE = false;
}

void drv::Timer::setUpdateIsr(void (*isr)(void))
{
	mIsrUpdate = isr;
}

void drv::Timer::isrUpdate(void)
{
	if (mIsrUpdate)
		mIsrUpdate();
}

unsigned int Timer::getCounterValue(void)
{
	TcCount32 *peri = (TcCount32 *)mPeri;

	peri->CTRLBSET.bit.CMD = TC_CTRLBSET_CMD_READSYNC_Val;
	while (peri->SYNCBUSY.bit.COUNT)
		;

	return peri->COUNT.reg / mDiv;
}
}
#endif