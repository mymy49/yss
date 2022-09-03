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

#include <drv/mcu.h>

#if defined(GD32F1)

#include <drv/clock/register_clock_gd32f1.h>
#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/reg.h>

enum
{
	GCCR = 0, GCFGR, GCIR, APB2RCR,
	APB1RCR, AHBCCR, APB2CCR, APB1CCR,
	BDCR, GCSR, AHBRCR, GCFGR2,
	RCC_DEEPSLEEP_VC = 13
};

int32_t  Clock::mHseFreq __attribute__((section(".non_init")));
int32_t  Clock::mPllFreq __attribute__((section(".non_init")));
int32_t  Clock::mLseFreq __attribute__((section(".non_init")));

static const int16_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const int16_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	
	mHseFreq = hseHz;

	if (hseHz < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hseHz)
		return false;

	if (useOsc)
		peri[GCCR] |= RCC_GCCR_HSEEN | RCC_GCCR_HSEBPS;
	else
		peri[GCCR] |= RCC_GCCR_HSEEN;

	for (uint32_t i = 0; i < 10000; i++)
	{
		if (peri[GCCR] & RCC_GCCR_HSESTB)
			return true;
	}

	return false;
}

bool Clock::enableMainPll(uint8_t src, uint8_t xtpre, uint8_t mul)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;

	uint32_t pll;

	using namespace define::clock::sysclk;
	
	// 현재 SysClk 소스가 PLL인이 확인
	if (getFieldData(peri[GCFGR], 0x3 << 2, 2) == src::PLL)
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
		// HSE 활성화 확인
		if (getBitData(peri[GCCR], 16) == true)
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

	if (mul > PLL_MUL_MAX)
		mul = PLL_MUL_MAX;

	pll *= (mul + 2);
	if (pll < PLL_OUT_MIN_FREQ || PLL_OUT_MAX_FREQ < pll)
		goto error;
		
	// PLL Factor 설정	
#if defined(GD32F10X_CL)
	if(mul & 0x10)
		setBitData(peri[GCFGR], true, 29);
	else
		setBitData(peri[GCFGR], false, 29);
#else
	if(mul & 0x10)
		setBitData(peri[GCFGR], true, 27);
	else
		setBitData(peri[GCFGR], false, 27);
#endif

	setFieldData(peri[GCFGR], 0x0F << 18, mul, 18);

	setBitData(peri[GCFGR], xtpre, 17);
	setBitData(peri[GCFGR], src, 16);

	// PLL 활성화
	setBitData(peri[GCCR], true, 24);
	for (uint16_t i = 0; i < 10000; i++)
	{
		// PLL 활성화 확인
		if (getBitData(peri[GCCR], 24))
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
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	uint32_t clk, ahbClk, apb1Clk, apb2Clk, adcClk;
	uint8_t buf;

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case HSE:
		// HSE 활성화 점검
		if (getBitData(peri[GCCR], 16) == false)
			return false;
		clk = mHseFreq * 1000000;
		break;
	case PLL:
		// PLL 활성화 점검
		if (getBitData(peri[GCCR], 24) == false)
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
			setBitData(peri[GCFGR], true, 28);
		else
			setBitData(peri[GCFGR], false, 28);
		
		setFieldData(peri[GCFGR], 0x3 << 14, buf, 14);
	}
	
	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(peri[GCFGR], 0x7 << 11, apb2, 11, 0x7 << 8, apb1, 8, 0xF << 4, ahb, 4);
	
	// 클럭 소스 변경
	setFieldData(peri[GCFGR], 0x3 << 0, sysclkSrc, 0);

	return true;
}

int32_t  Clock::getSysClkFreq(void)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	int32_t  clk;

	switch (getFieldData(peri[GCFGR], 0x3 << 2, 2))
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

	return clk / gHpreDiv[getFieldData(peri[GCFGR], 0xF << 4, 4)];
}

int32_t  Clock::getApb1ClkFreq(void)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;

	return getSysClkFreq() / gPpreDiv[getFieldData(peri[GCFGR], 0x7 << 8, 8)];
} 

int32_t  Clock::getApb2ClkFreq(void)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;

	return getSysClkFreq() / gPpreDiv[getFieldData(peri[GCFGR], 0x7 << 11, 11)];
}

int32_t  Clock::getTimerApb1ClkFreq(void)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	int8_t pre = getFieldData(peri[GCFGR], 0x7 << 8, 8);
	int32_t  clk = getSysClkFreq() / gPpreDiv[pre];

	if (gPpreDiv[pre] > 1)
		clk <<= 1;

	return clk;
}

int32_t  Clock::getTimerApb2ClkFreq(void)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;

	int8_t pre = getFieldData(peri[GCFGR], 0x7 << 11, 11);
	int32_t  clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;

	return clk;
}

void Clock::setLatency(uint32_t freq, uint8_t vcc)
{
}

#endif

