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

#if defined(STM32F4)

#include <drv/Clock.h>
#include <drv/clock/register_clock_stm32f4.h>
#include <drv/clock/ec_clock_stm32f4.h>

int32_t  Clock::mHseFreq __attribute__((section(".non_init")));
int32_t  Clock::mPllFreq __attribute__((section(".non_init")));
int32_t  Clock::mSaiPllFreq __attribute__((section(".non_init")));
int32_t  Clock::mLcdPllFreq __attribute__((section(".non_init")));
int32_t  Clock::mMainPllUsbFreq __attribute__((section(".non_init")));

static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const uint32_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	mHseFreq = hseHz;

	if (hseHz < ec::clock::hse::HSE_MIN_FREQ || ec::clock::hse::HSE_MAX_FREQ < hseHz)
		return false;

	setRccHseEn(true);

	for (uint32_t i = 0; i < 100000; i++)
	{
		if (getRccHseReady())
			return true;
	}

	return false;
}

bool Clock::enableMainPll(uint8_t src, uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, pll, pll48, buf;

	using namespace ec::clock::pll;
	if (M_MIN > m || m > M_MAX)
		goto error;

	if (N_MIN > n || n > N_MAX)
		goto error;

	if (pDiv > P_MAX)
		goto error;

	if (Q_MIN > qDiv || qDiv > Q_MAX)
		goto error;

	switch (src)
	{
	case define::clock::pll::src::HSI:
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (getRccHseReady() == false)
			goto error;
		buf = (uint32_t)mHseFreq;
		break;
	default:
		goto error;
	}

	using namespace define::clock::sysclk;
	if (getRccMainPllReady() == true && getRccSysclkSw() == src::PLL)
		goto error;

	vco = buf / m * n;
	using namespace ec::clock::pll;
	if (vco < VCO_MIN_FREQ || VCO_MAX_FREQ < vco)
		goto error;

	pll = vco / (2 << pDiv);

	using namespace ec::clock;
	if (pll > sysclk::MAX_FREQ)
		goto error;

	pll48 = vco / qDiv;
	if (pll48 > pll::USB48_MAX_FREQ)
		goto error;

	setRccMainPllSrc(src);
	setRccMainPllm(m);
	setRccMainPlln(n);
	setRccMainPllp(pDiv);
	setRccMainPllq(qDiv);

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
		clk = mHseFreq;
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

#if defined(STM32F42_F43)
	if (ahbClk > ec::clock::sysclk::OVER_DRIVE_FREQ)
	{
		setRegBit(RCC->APB1ENR, 1, RCC_APB1ENR_PWREN_Pos);
		setRegBit(PWR->CR, 1, PWR_CR_ODEN_Pos);
		while (!getRegBit(PWR->CR, PWR_CR_ODEN_Pos))
			;
		
		setRegBit(PWR->CR, 1, PWR_CR_ODSWEN_Pos);
		while (!getRegBit(PWR->CR, PWR_CR_ODSWEN_Pos))
			;
	}
#endif

	setRccHpre(ahb);
	setRccPpre1(apb1);
	setRccPpre2(apb2);

	setLatency(ahbClk, vcc);
	setRccSysclkSw(sysclkSrc);

	return true;
}

void Clock::setLatency(uint32_t freq, uint8_t vcc)
{
	register uint32_t div, wait;

	if (vcc > 27)
	{
		div = 30;
	}
	else if (vcc > 24)
	{
		div = 24;
	}
	else if (vcc > 21)
	{
		div = 22;
	}
	else
	{
		div = 20;
	}

	freq /= 1000000;
	wait = freq / div;
	if (!(freq % div))
		wait--;
	
	FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_LATENCY_Msk) | (wait & 0xFUL << FLASH_ACR_LATENCY_Pos);
}

int32_t  Clock::getSysClkFreq(void)
{
	uint32_t clk;

	switch (getRccSysclkSw())
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
	return getSysClkFreq() / gPpreDiv[getRccPpre1()];
}

int32_t  Clock::getApb2ClkFreq(void)
{
	return getSysClkFreq() / gPpreDiv[getRccPpre2()];
}

int32_t  Clock::getTimerApb1ClkFreq(void)
{
	int8_t pre = getRccPpre1();
	int32_t  clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

int32_t  Clock::getTimerApb2ClkFreq(void)
{
	int8_t pre = getRccPpre2();
	int32_t  clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

#if defined(STM32F42_F43)

bool Clock::enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, q, r, sai, lcd, buf, m;
	bool able = getRccMainPllReady();

	using namespace ec::clock;

	if (!able)
		goto error;

	if (saipll::N_MIN > n || n > saipll::N_MAX)
		goto error;

	if (saipll::Q_MIN > qDiv || qDiv > saipll::Q_MAX)
		goto error;

	if (saipll::R_MIN > rDiv || rDiv > saipll::R_MAX)
		goto error;

	switch (getRegBit(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Pos))
	{
	case define::clock::pll::src::HSI:
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (getRccHseReady() == false)
			goto error;
		buf = (uint32_t)mHseFreq;
		break;
	default:
		goto error;
	}

	vco = buf / getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLM_Msk, RCC_PLLCFGR_PLLM_Pos) * n;
	using namespace ec::clock;
	if (vco < saipll::VCO_MIN_FREQ || saipll::VCO_MAX_FREQ < vco)
		goto error;

	sai = vco / qDiv;
	if (saipll::SAI_MAX_FREQ < sai)
		goto error;

	lcd = vco / rDiv;
	if (saipll::LCD_MAX_FREQ < lcd)
		goto error;

	setRccSaiPlln(n);
	setRccSaiPllq(qDiv);
	setRccSaiPllr(rDiv);

	setRccSaiPllOn(true);

	for (uint16_t i = 0; i < 10000; i++)
	{
		if (getRccSaiPllReady())
		{
			mLcdPllFreq = lcd;
			mSaiPllFreq = sai;
			return true;
		}
	}

error:
	mLcdPllFreq = 0;
	mSaiPllFreq = 0;
	return false;
}

#endif

#endif

