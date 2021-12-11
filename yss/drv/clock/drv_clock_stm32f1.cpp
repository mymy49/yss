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

#include <drv/peripheral.h>

#if defined(STM32F1)

#include <__cross_studio_io.h>

#include <drv/clock/register_clock_stm32f1.h>

#include <drv/Clock.h>

namespace drv
{
unsigned int Clock::mHseFreq __attribute__((section(".non_init")));
unsigned int Clock::mPllFreq __attribute__((section(".non_init")));
unsigned int Clock::mLseFreq __attribute__((section(".non_init")));

static const unsigned int gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const unsigned int gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(unsigned int hseHz, bool useOsc)
{
	mHseFreq = hseHz;

	if (hseHz < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hseHz)
		return false;

	if (useOsc)
		RCC->CR |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;
	else
		RCC->CR |= RCC_CR_HSEON_Msk;

	for (unsigned int i = 0; i < 10000; i++)
	{
		if (RCC->CR & RCC_CR_HSERDY_Msk)
			return true;
	}

	return false;
}

bool Clock::enableMainPll(unsigned char src, unsigned char xtpre, unsigned char mul)
{
	unsigned int pll;

	using namespace define::clock::sysclk;
	if (getRccSysclkSw() == src::PLL)
		goto error;

	using namespace ec::clock::pll;
	if (src > PLL_SRC_MAX)
		goto error;

	if (xtpre > PLL_XTPRE_MAX)
		goto error;

	if (mul > PLL_MUL_MAX)
		goto error;

	if (src == src::HSE)
	{
		if (getRccHseReady() == true)
			pll = mHseFreq;
		else
			goto error;

		if (xtpre == define::clock::pll::xtpre::DIV2)
			pll >>= 1;
	}
	else
		pll = ec::clock::hsi::FREQ / 2;

	if (pll < PLL_IN_MIN_FREQ || PLL_IN_MAX_FREQ < pll)
		goto error;

	if (mul > 14)
		mul = 14;

	pll *= (mul + 2);
	if (pll < PLL_OUT_MIN_FREQ || PLL_OUT_MAX_FREQ < pll)
		goto error;

	setRccPllMul(mul);
	setRccPllXtpre(xtpre);
	setRccPllSrc(src);

	setRccMainPllOn(true);

	for (unsigned short i = 0; i < 10000; i++)
	{
		if (getRccMainPllReady())
		{
			mPllFreq = pll;
			return true;
		}
	}

error:
	mPllFreq = 0;
	return false;
}

bool Clock::setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2, unsigned char vcc)
{
	unsigned int clk, ahbClk, apb1Clk, apb2Clk, adcClk;

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case HSE:
		if (getRccHseReady() == false)
			return false;
		clk = mHseFreq * 1000000;
		break;
	case PLL:
		if (getRccMainPllReady() == false)
			return false;
		clk = mPllFreq;
		break;
	default:
		return false;
	}

	ahbClk = clk / gHpreDiv[ahb];
	if (ahbClk > ec::clock::sysclk::MAX_FREQ)
		return false;

	apb1Clk = ahbClk / gPpreDiv[apb1];
	if (apb1Clk > ec::clock::apb1::MAX_FREQ)
		return false;

	apb2Clk = ahbClk / gPpreDiv[apb2];
	if (apb2Clk > ec::clock::apb2::MAX_FREQ)
		return false;

	adcClk = apb2Clk / (ec::clock::adc::MAX_FREQ / 1000);
	if (adcClk >= 1000)
	{
		adcClk /= 1000;
		adcClk += 1;
		if (adcClk <= 2)
			setRccAdcpre(0);
		else if (adcClk <= 4)
			setRccAdcpre(1);
		else if (adcClk <= 6)
			setRccAdcpre(2);
		else if (adcClk <= 8)
			setRccAdcpre(3);
		else
			return false;
	}

	setRccHpre(ahb);
	setRccPpre1(apb1);
	setRccPpre2(apb2);

	setLatency(ahbClk);
	setRccSysclkSw(sysclkSrc);

	return true;
}

unsigned int Clock::getSysClkFreq(void)
{
	unsigned int clk;

	switch ((RCC->CFGR & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos)
	{
	case define::clock::sysclk::src::HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case define::clock::sysclk::src::HSE:
		clk = mHseFreq;
		break;
	case define::clock::sysclk::src::PLL:
		clk = mPllFreq;
		break;
	}

	clk /= gHpreDiv[getRccHpre()];

	return clk;
}

unsigned int Clock::getApb1ClkFreq(void)
{
	unsigned int clk = getSysClkFreq() / gPpreDiv[getRccPpre1()];
	return clk;
}

unsigned int Clock::getApb2ClkFreq(void)
{
	unsigned int clk = getSysClkFreq() / gPpreDiv[getRccPpre2()];
	return clk;
}

unsigned int Clock::getTimerApb1ClkFreq(void)
{
	unsigned char pre = getRccPpre1();
	unsigned int clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

unsigned int Clock::getTimerApb2ClkFreq(void)
{
	unsigned char pre = getRccPpre2();
	unsigned int clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

void Clock::setLatency(unsigned int freq, unsigned char vcc)
{
	register unsigned int reg;

	if (freq < 24000000)
		FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
	else if (freq < 48000000)
	{
		reg = FLASH->ACR;
		reg = (reg & ~FLASH_ACR_LATENCY_Msk) | (1 << FLASH_ACR_LATENCY_Pos);
		FLASH->ACR = reg;
	}
	else
	{
		reg = FLASH->ACR;
		reg = (reg & ~FLASH_ACR_LATENCY_Msk) | (2 << FLASH_ACR_LATENCY_Pos);
		FLASH->ACR = reg;
	}
}

}

#endif