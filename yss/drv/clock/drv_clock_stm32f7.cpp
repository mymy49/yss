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

#if defined(STM32F7)

#include <drv/Clock.h>
#include <drv/clock/register_clock_stm32f7.h>

namespace drv
{
unsigned int gHseFreq __attribute__((section(".non_init")));
unsigned int gPllFreq __attribute__((section(".non_init")));
unsigned int gSaiPllFreq __attribute__((section(".non_init")));
unsigned int gLcdPllFreq __attribute__((section(".non_init")));

static const unsigned int gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const unsigned int gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(unsigned int hseHz, bool useOsc)
{
	gHseFreq = hseHz;
	
	using namespace ec::clock::hse;
	if (hseHz < HSE_MIN_FREQ || HSE_MAX_FREQ < hseHz)
		return false;

	setRccHseEn(true);

	for (unsigned int i = 0; i < 100000; i++)
	{
		if (getRccHseReady())
			return true;
	}

	return false;
}

bool Clock::enableLsi(void)
{
	setRccLsiEn(true);
	for (unsigned short i = 0; i < 10000; i++)
	{
		if (getRccLsiReady())
			return true;
	}

	return false;
}

bool Clock::setUsbClkSrc(unsigned char src)
{
	if (src < 0 || src > 1)
		return false;

	setRccUsbClkSel(src);
	return true;
}

bool Clock::enableLse(bool en)
{
	setRccLseEn(en);
	if (en == true)
	{
		for (unsigned short i = 0; i < 10000; i++)
		{
			if (getRccLseReady())
				return true;
		}
	}
	else
	{
		return true;
	}

	return false;
}

bool Mainpll::enable(unsigned char src, unsigned char m, unsigned short n, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv)
{
	unsigned int vco, pll, pll48, buf;

	if (ec::clock::pll::M_MIN > m || m > ec::clock::pll::M_MAX)
		goto error;

	if (ec::clock::pll::N_MIN > n || n > ec::clock::pll::N_MAX)
		goto error;

	if (pDiv > ec::clock::pll::P_MAX)
		goto error;

	if (ec::clock::pll::Q_MIN > qDiv || qDiv > ec::clock::pll::Q_MAX)
		goto error;

	switch (src)
	{
	case define::clock::pll::src::HSI:
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (getRccHseReady() == false)
			goto error;
		buf = (unsigned int)gHseFreq;
		break;
	default:
		goto error;
	}

	if (getRccMainPllReady() == true && getRccSysclkSw() == define::clock::sysclk::src::PLL)
		goto error;

	vco = buf / m * n;
	if (vco < ec::clock::pll::VCO_MIN_FREQ || ec::clock::pll::VCO_MAX_FREQ < vco)
		goto error;

	pll = vco / (2 << pDiv);

	if (pll > ec::clock::sysclk::MAX_FREQ)
		goto error;

	pll48 = vco / qDiv;
	if (pll48 > ec::clock::pll::USB48_MAX_FREQ)
		goto error;

	setRccMainPllSrc(src);
	setRccMainPllm(m);
	setRccMainPlln(n);
	setRccMainPllp(pDiv);
	setRccMainPllq(qDiv);

	setRccMainPllOn(true);

	for (unsigned short i = 0; i < 10000; i++)
	{
		if (getRccMainPllReady())
		{
			gPllFreq = pll;
			return true;
		}
	}

error:
	gPllFreq = 0;
	return false;
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

unsigned int Clock::getApb1ClkFreq(void)
{
	return (unsigned int)(getSysClkFreq() / gPpreDiv[getRccPpre1()]);
}

unsigned int Clock::getApb2ClkFreq(void)
{
	return (unsigned int)(getSysClkFreq() / gPpreDiv[getRccPpre2()]);
}

void Clock::setLatency(unsigned int freq, unsigned char vcc)
{
	unsigned int div, wait;

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
	
	FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_LATENCY_Msk) | ((wait << FLASH_ACR_LATENCY_Pos) & FLASH_ACR_LATENCY_Msk);
}

unsigned int Clock::getSysClkFreq(void)
{
	unsigned int clk;

	switch (getRccSysclkSw())
	{
	case define::clock::sysclk::src::HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case define::clock::sysclk::src::HSE:
		clk = gHseFreq;
		break;
	case define::clock::sysclk::src::PLL:
		clk = gPllFreq;
		break;
	}

	clk /= gHpreDiv[getRccHpre()];

	return clk;
}

bool Saipll::enable(unsigned short n, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv)
{
	unsigned int vco, q, r, sai, pll48, lcd, buf, m;
	bool able = getRccMainPllReady();

	using namespace ec::clock;

	if (!able)
		goto error;

	if (saipll::N_MIN > n || n > saipll::N_MAX)
		goto error;

	if (pDiv > saipll::P_MAX)
		goto error;

	if (saipll::Q_MIN > qDiv || qDiv > saipll::Q_MAX)
		goto error;

	if (saipll::R_MIN > rDiv || rDiv > saipll::R_MAX)
		goto error;

	switch (getBitData(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Pos))
	{
	case define::clock::pll::src::HSI:
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (getRccHseReady() == false)
			goto error;
		buf = (unsigned int)gHseFreq;
		break;
	default:
		goto error;
	}

	vco = buf / getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLM_Msk, RCC_PLLCFGR_PLLM_Pos) * n ;
	if (vco < saipll::VCO_MIN_FREQ || saipll::VCO_MAX_FREQ < vco)
		goto error;

	pll48 = vco / (2 << pDiv);

	sai = vco / qDiv;
	if (saipll::SAI_MAX_FREQ < sai)
		goto error;

	lcd = vco / rDiv;
	if (saipll::LCD_MAX_FREQ < lcd)
		goto error;

	setRccSaiPlln(n);
	setRccSaiPllp(pDiv);
	setRccSaiPllq(qDiv);
	setRccSaiPllr(rDiv);

	setRccSaiPllOn(true);

	for (unsigned short i = 0; i < 10000; i++)
	{
		if (getRccSaiPllReady())
		{
			gLcdPllFreq = lcd;
			gSaiPllFreq = sai;
			return true;
		}
	}

error:
	gLcdPllFreq = 0;
	gSaiPllFreq = 0;
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

		clk = gHseFreq;
		break;
	case PLL:
		if (getRccMainPllReady() == false)
			return false;

		clk = gPllFreq;
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

	if (ahbClk > ec::clock::sysclk::OVER_DRIVE_FREQ)
	{
		setRegBit(RCC->APB1ENR, 1, RCC_APB1ENR_PWREN_Pos);
		setRegBit(PWR->CR1, 1, PWR_CR1_ODEN_Pos);
		while (!getRegBit(PWR->CR1, PWR_CR1_ODEN_Pos))
			;
		
		setRegBit(PWR->CR1, 1, PWR_CR1_ODSWEN_Pos);
		while (!getRegBit(PWR->CR1, PWR_CR1_ODSWEN_Pos))
			;
	}

	setRccHpre(ahb);
	setRccPpre1(apb1);
	setRccPpre2(apb2);

	setLatency(ahbClk, vcc);
	setRccSysclkSw(sysclkSrc);

	return true;
}
}

#endif