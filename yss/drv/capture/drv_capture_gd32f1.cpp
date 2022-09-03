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

#if defined(GD32F1)

#include <drv/Capture.h>
#include <yss/reg.h>

enum
{
	CTLR1 = 0, CTLR2, SMC, DIE,
	STR, EVG, CHCTLR1, CHCTLR2,
	CHE, CNT, PSC, CARL,
	CREP, CHCC1, CHCC2, CHCC3,
	CHCC4, BKDT, DCTLR, DTRSF
};

Capture::Capture(const Drv::Config &drvConfig, const Config &config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mIsr = 0;
	mUpdateCnt = config.updateCnt;
	mLastUpdateCnt = 0;
	mLastCcr = 0;
}

void Capture::init(uint32_t psc, uint8_t option)
{
	mPeri[PSC] = (uint16_t)psc;
	mPeri[CARL] = (uint16_t)0xFFFF;
	setBitData(mPeri[DIE], true, 0);	// Update Interrupt Enable

	initChannel(option);
}

uint32_t Capture::getSourceFrequency(void)
{
	return getClockFrequency() / (mPeri[PSC] + 1);
}

void Capture::start(void)
{
	setBitData(mPeri[CTLR1], true, 0);	// Timer Enable
}

void Capture::stop(void)
{
	setBitData(mPeri[CTLR1], false, 0);	// Timer Diable
}

void Capture::isrUpdate(void)
{
	(*mUpdateCnt)++;
}

void Capture::isrCapture(int32_t ccr, bool update)
{
	int32_t cnt;
	uint64_t  accCnt;

	cnt = (int32_t)(*mUpdateCnt - mLastUpdateCnt);

	if (update)
	{
		if ((uint32_t)ccr > 0x7FFF)
		{
			mLastUpdateCnt = *mUpdateCnt - 1;
			cnt--;
		}
		else
			mLastUpdateCnt = *mUpdateCnt;
	}
	else
		mLastUpdateCnt = *mUpdateCnt;

	cnt = cnt * 65536;
	cnt += ccr - mLastCcr;
	mLastCcr = ccr;

	accCnt = mLastUpdateCnt * 65536 + ccr;

	if (mIsr)
		mIsr(cnt, accCnt);
}

CaptureCh1::CaptureCh1(const Drv::Config &drvConfig, const Capture::Config &config) : Capture(drvConfig, config)
{
	
}

void CaptureCh1::initChannel(uint8_t option)
{
	mPeri[CHCTLR1] &= ~(TIMER_CHCTLR1_CH1M | TIMER_CHCTLR1_CH1ICF);
	mPeri[CHCTLR1] |= (1 << 0) | (2 << 4);

	if (option & RISING_EDGE)
		mPeri[CHE] &= ~TIMER_CHE_CH1P;
	else
		mPeri[CHE] |= TIMER_CHE_CH1P;

	mPeri[CHE] |= TIMER_CHE_CH1E;
	mPeri[DIE] |= TIMER_DIE_CH1IE;
}

void CaptureCh1::isrCapture(bool update)
{
	Capture::isrCapture((int32_t)mPeri[CHCC1], update);
}

void CaptureCh1::setIsr(void (*isr)(uint32_t cnt, uint64_t  accCnt))
{
	mIsr = isr;
}



CaptureCh2::CaptureCh2(const Drv::Config &drvConfig, const Capture::Config &config) : Capture(drvConfig, config)
{
	
}

void CaptureCh2::initChannel(uint8_t option)
{
	mPeri[CHCTLR1] &= ~(TIMER_CHCTLR1_CH2M | TIMER_CHCTLR1_CH2ICF);
	mPeri[CHCTLR1] |= (1 << 8) | (2 << 12);

	if (option & RISING_EDGE)
		mPeri[CHE] &= ~TIMER_CHE_CH2P;
	else
		mPeri[CHE] |= TIMER_CHE_CH2P;

	mPeri[CHE] |= TIMER_CHE_CH2E;
	mPeri[DIE] |= TIMER_DIE_CH2IE;
}

void CaptureCh2::isrCapture(bool update)
{
	Capture::isrCapture((int32_t)mPeri[CHCC2], update);
}

void CaptureCh2::setIsr(void (*isr)(uint32_t cnt, uint64_t  accCnt))
{
	mIsr = isr;
}



CaptureCh3::CaptureCh3(const Drv::Config &drvConfig, const Capture::Config &config) : Capture(drvConfig, config)
{
	
}

void CaptureCh3::initChannel(uint8_t option)
{
	mPeri[CHCTLR2] &= ~(TIMER_CHCTLR2_CH3M | TIMER_CHCTLR2_CH3ICF);
	mPeri[CHCTLR2] |= (1 << 0) | (2 << 4);

	if (option & RISING_EDGE)
		mPeri[CHE] &= ~TIMER_CHE_CH3P;
	else
		mPeri[CHE] |= TIMER_CHE_CH3P;

	mPeri[CHE] |= TIMER_CHE_CH3E;
	mPeri[DIE] |= TIMER_DIE_CH3IE;
}

void CaptureCh3::isrCapture(bool update)
{
	Capture::isrCapture((int32_t)mPeri[CHCC3], update);
}

void CaptureCh3::setIsr(void (*isr)(uint32_t cnt, uint64_t  accCnt))
{
	mIsr = isr;
}

CaptureCh4::CaptureCh4(const Drv::Config &drvConfig, const Capture::Config &config) : Capture(drvConfig, config)
{
	
}

void CaptureCh4::initChannel(uint8_t option)
{
	mPeri[CHCTLR2] &= ~(TIMER_CHCTLR2_CH4M | TIMER_CHCTLR2_CH4ICF);
	mPeri[CHCTLR2] |= (1 << 8) | (2 << 12);

	if (option & RISING_EDGE)
		mPeri[CHE] &= ~TIMER_CHE_CH4P;
	else
		mPeri[CHE] |= TIMER_CHE_CH4P;

	mPeri[CHE] |= TIMER_CHE_CH4E;
	mPeri[DIE] |= TIMER_DIE_CH4IE;
}

void CaptureCh4::isrCapture(bool update)
{
	Capture::isrCapture((int32_t)mPeri[CHCC4], update);
}

void CaptureCh4::setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt))
{
	mIsr = isr;
}

#endif

