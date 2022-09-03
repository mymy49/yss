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

#if defined(STM32F1)

#include <drv/clock/register_clock_stm32f1.h>

#include <drv/Clock.h>

int32_t  Clock::mHseFreq __attribute__((section(".non_init")));
int32_t  Clock::mPllFreq __attribute__((section(".non_init")));
int32_t  Clock::mLseFreq __attribute__((section(".non_init")));

static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const uint32_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	mHseFreq = hseHz;

	if (hseHz < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hseHz)
		return false;

	if (useOsc)
		RCC->CR |= RCC_CR_HSEON | RCC_CR_HSEBYP;
	else
		RCC->CR |= RCC_CR_HSEON;

	for (uint32_t i = 0; i < 10000; i++)
	{
		if (RCC->CR & RCC_CR_HSERDY)
			return true;
	}

	return false;
}

bool Clock::enableMainPll(uint8_t src, uint8_t xtpre, uint8_t mul)
{
	uint32_t pll;

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

	for (uint16_t i = 0; i < 10000; i++)
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

bool Clock::setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc)
{
	uint32_t clk, ahbClk, apb1Clk, apb2Clk, adcClk;

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

int32_t  Clock::getSysClkFreq(void)
{
	uint32_t clk;

	switch ((RCC->CFGR & RCC_CFGR_SWS) >> 2)
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

int32_t  Clock::getApb1ClkFreq(void)
{
	uint32_t clk = getSysClkFreq() / gPpreDiv[getRccPpre1()];
	return clk;
}

int32_t  Clock::getApb2ClkFreq(void)
{
	uint32_t clk = getSysClkFreq() / gPpreDiv[getRccPpre2()];
	return clk;
}

int32_t  Clock::getTimerApb1ClkFreq(void)
{
	uint8_t pre = getRccPpre1();
	uint32_t clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

int32_t  Clock::getTimerApb2ClkFreq(void)
{
	uint8_t pre = getRccPpre2();
	uint32_t clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

void Clock::setLatency(uint32_t freq, uint8_t vcc)
{
	register uint32_t reg;

	if (freq < 24000000)
		FLASH->ACR &= ~FLASH_ACR_LATENCY;
	else if (freq < 48000000)
	{
		reg = FLASH->ACR;
		reg = (reg & ~FLASH_ACR_LATENCY) | (1 << 0);
		FLASH->ACR = reg;
	}
	else
	{
		reg = FLASH->ACR;
		reg = (reg & ~FLASH_ACR_LATENCY) | (2 << 0);
		FLASH->ACR = reg;
	}
}

#endif

