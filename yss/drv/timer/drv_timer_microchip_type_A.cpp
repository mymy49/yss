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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
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

static unsigned int getTimerClkFreq(void)
{
	return 4000000;
//	return clock.getApbClkFreq();
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

drv::Timer timer0(MXC_TMR0, setTim0ClockEn, setTim0IntEn, getTimerClkFreq);

extern "C"
{
	void TMR0_IRQHandler(void)
	{
		MXC_TMR0->intr = MXC_F_TMR_INTR_IRQ_CLR;
		timer0.isrUpdate();
	}
}
#endif

//********** Timer1 구성 설정 및 변수 선언 **********
#if defined(TIM1_ENABLE) && defined(TC1)
static void setTim1ClockEn(bool en)
{
//	clock.peripheral.setTimer1En(en);
} 

static void setTim1IntEn(bool en)
{
//	nvic.setTimer1En(en);
}

drv::Timer timer1(TC1, setTim1ClockEn, setTim1IntEn, getTimerClkFreq);

extern "C"
{
	void TMR1_IRQHandler(void)
	{
		//MXC_TMR1->intr = MXC_F_TMR_INTR_IRQ_CLR;
		timer1.isrUpdate();
	}
}
#endif


//********** Timer2 구성 설정 및 변수 선언 **********
#if defined(TIM2_ENABLE) && defined(TC2)
static void setTim2ClockEn(bool en)
{
//	clock.peripheral.setTimer2En(en);
}

static void setTim2IntEn(bool en)
{
//	nvic.setTimer2En(en);
}

drv::Timer timer2(TC2, setTim2ClockEn, setTim2IntEn, getTimerClkFreq);

extern "C"
{
	void TMR2_IRQHandler(void)
	{
		//MXC_TMR2->intr = MXC_F_TMR_INTR_IRQ_CLR;
		//timer2.isrUpdate();
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
		return 1000000;
	}

	void Timer::initSystemTime(void)
	{
		TcCount32 *peri = (TcCount32*)mPeri;
		unsigned int reg;

//		peri->CTRLA.bit.ENABLE = true;
		reg = peri->CTRLA.reg;
		reg &= TC_CTRLA_MODE_Msk;
		reg |= TC_CTRLA_MODE_COUNT32 | TC_CTRLA_RUNSTDBY;
		peri->CTRLA.reg = reg;

		peri->CTRLBCLR.bit.CMD = TC_CTRLBSET_CMD_RETRIGGER;
		
		peri->EVCTRL.bit.EVACT = TC_EVCTRL_EVACT_START;
		peri->EVCTRL.bit.EVACT = TC_EVCTRL_EVACT_COUNT;

		peri->CTRLA.bit.ENABLE = true;
		
		
		//unsigned int clk = mGetClockFreq();
		//mDiv = clk / 1000000;
		//mPeri->cn &= ~(MXC_F_TMR_CN_PRES | MXC_F_TMR_CN_TEN | MXC_F_TMR_CN_TMODE);
		//mPeri->cn |= (1 << MXC_F_TMR_CN_TMODE_POS);
		//mPeri->cmp = clk;
	}

	void Timer::init(unsigned int psc, unsigned int arr)
	{
		//mPeri->cn &= ~(MXC_F_TMR_CN_PRES | MXC_F_TMR_CN_TEN | MXC_F_TMR_CN_TMODE);
		//mPeri->cn |= (1 << MXC_F_TMR_CN_TMODE_POS);
		//mPeri->cmp = arr;
	}

	void Timer::init(unsigned int freq)
	{
		//unsigned int clk = mGetClockFreq();

		//mPeri->cn &= ~(MXC_F_TMR_CN_PRES | MXC_F_TMR_CN_TEN | MXC_F_TMR_CN_TMODE);
		//mPeri->cn |= (1 << MXC_F_TMR_CN_TMODE_POS);
		//mPeri->cmp = clk / freq ;
	}

	void Timer::setUpdateIntEn(bool en)
	{
	}

	void Timer::start(void)
	{
		//mPeri->cn |= MXC_F_TMR_CN_TEN;
	}

	void Timer::stop(void)
	{
		//mPeri->cn &= ~MXC_F_TMR_CN_TEN;
	}

	void drv::Timer::setUpdateIsr(void (*isr)(void))
	{
		mIsrUpdate = isr;
	}

	void drv::Timer::isrUpdate(void)
	{
		//if(mIsrUpdate)
		//	mIsrUpdate();
	}

	unsigned int Timer::getCounterValue(void)
	{
		//return mPeri->cnt / mDiv;
	}
}
#endif
