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

#if defined(GD32F450)

#include <__cross_studio_io.h>

#include <drv/Clock.h>
#include <yss/reg.h>

namespace drv
{
unsigned int Clock::mHseFreq __attribute__((section(".non_init")));
unsigned int Clock::mPllFreq __attribute__((section(".non_init")));
unsigned int Clock::mSaiPllFreq __attribute__((section(".non_init")));
unsigned int Clock::mLcdPllFreq __attribute__((section(".non_init")));

static const unsigned int gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const unsigned int gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(unsigned int hseHz, bool useOsc)
{
	mHseFreq = hseHz;

	if (hseHz < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hseHz)
		return false;
		
	if (useOsc)
		RCU_CTL |= RCU_CTL_HXTALEN | RCU_CTL_HXTALBPS;
	else
		RCU_CTL |= RCU_CTL_HXTALEN;

	for (unsigned int i = 0; i < 10000; i++)
	{
		if (RCU_CTL & RCU_CTL_HXTALSTB)
			return true;
	}

	return false;
}

bool Clock::enableMainPll(unsigned char src, unsigned char m, unsigned short n, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv)
{
	unsigned int vco, pll, pll48, buf;

	using namespace define::clock::sysclk;
	
	// 현재 SysClk 소스가 PLL인이 확인
	if (getFieldData(RCU_CTL, 0x3 << 2, 2) == src::PLL)
		goto error;

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
	case define::clock::pll::src::HSI :
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (~RCU_CTL & RCU_CTL_HXTALSTB)
			goto error;
		buf = (unsigned int)mHseFreq;
		break;
	default:
		goto error;
	}

	using namespace define::clock::sysclk;
	if (RCU_CTL & RCU_CTL_PLLSTB && (RCU_CFG0 & RCU_CFG0_SCSS) >> 2 == src::PLL)
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
	
	RCU_PLL = (qDiv << 24) | (src << 22) | (pDiv << 16) | (n << 6) | m;
	RCU_CTL |= RCU_CTL_PLLEN;

	for (unsigned short i = 0; i < 10000; i++)
	{
		// PLL 활성화 확인
		if (RCU_CTL & RCU_CTL_PLLSTB)
		{
			mPllFreq = pll;
			return true;
		}
	}

error:
	mPllFreq = 0;
	return false;
}

/*
bool Clock::setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2, unsigned char vcc)
{
	unsigned int clk, ahbClk, apb1Clk, apb2Clk, adcClk;
	unsigned char buf;

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case HSE:
		// HSE 활성화 점검
		if (getBitData(RCC->GCCR, 16) == false)
			return false;
		clk = mHseFreq * 1000000;
		break;
	case PLL:
		// PLL 활성화 점검
		if (getBitData(RCC->GCCR, 24) == false)
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
		buf = adcClk / 2 - 1;
		
		// ADC 프리스케일러 설정
		if(buf & 0x04)
			setBitData(RCC->GCFGR, true, 28);
		else
			setBitData(RCC->GCFGR, false, 28);
		
		setFieldData(RCC->GCFGR, 0x3 << 14, buf, 14);
	}
	
	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(RCC->GCFGR, 0x7 << 11, apb2, 11, 0x7 << 8, apb1, 8, 0xF << 4, ahb, 4);
	
	// 클럭 소스 변경
	setFieldData(RCC->GCFGR, 0x3 << 0, sysclkSrc, 0);

	return true;
}
*/

unsigned int Clock::getSysClkFreq(void)
{
	unsigned int clk;

	//switch (getFieldData(RCC->GCFGR, 0x3 << 2, 2))
	//{
	//case define::clock::sysclk::src::HSI:
	//	clk = ec::clock::hsi::FREQ;
	//	break;
	//case define::clock::sysclk::src::HSE:
	//	clk = mHseFreq;
	//	break;
	//case define::clock::sysclk::src::PLL:
	//	clk = mPllFreq;
	//	break;
	//}

//	return clk / gHpreDiv[getFieldData(RCC->GCFGR, 0xF << 4, 4)];
	return 0;
}
/*
unsigned int Clock::getApb1ClkFreq(void)
{
	return getSysClkFreq() / gPpreDiv[getFieldData(RCC->GCFGR, 0x7 << 8, 8)];
} 

unsigned int Clock::getApb2ClkFreq(void)
{
	return getSysClkFreq() / gPpreDiv[getFieldData(RCC->GCFGR, 0x7 << 11, 11)];
}

unsigned int Clock::getTimerApb1ClkFreq(void)
{
	unsigned char pre = getFieldData(RCC->GCFGR, 0x7 << 8, 8);
	unsigned int clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

unsigned int Clock::getTimerApb2ClkFreq(void)
{
	unsigned char pre = getFieldData(RCC->GCFGR, 0x7 << 11, 11);
	unsigned int clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

void Clock::setLatency(unsigned int freq, unsigned char vcc)
{
	//if (freq < 24000000)
	//	FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
	//else if (freq < 48000000)
	//{
	//	reg = FLASH->ACR;
	//	reg = (reg & ~FLASH_ACR_LATENCY_Msk) | (1 << FLASH_ACR_LATENCY_Pos);
	//	FLASH->ACR = reg;
	//}
	//else
	//{
	//	reg = FLASH->ACR;
	//	reg = (reg & ~FLASH_ACR_LATENCY_Msk) | (2 << FLASH_ACR_LATENCY_Pos);
	//	FLASH->ACR = reg;
	//}
}
*/
}

#endif