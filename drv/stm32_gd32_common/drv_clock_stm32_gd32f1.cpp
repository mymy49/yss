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

#if defined(GD32F1) || defined(STM32F1)

#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/reg.h>

extern uint32_t gCoreClockFrequency;
extern uint32_t gAhbClockFrequency;
extern uint32_t gApb1ClockFrequency;
extern uint32_t gApb2ClockFrequency;

enum
{
	CR = 0, CFGR, CIR, APB2RSTR,
	APB1RSTR, AHBENR, APB2ENR, APB1ENR,
	BDCR, CSR, AHBRSTR
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
		peri[CR] |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;
	else
		peri[CR] |= RCC_CR_HSEON_Msk;

	for (uint32_t i = 0; i < 10000; i++)
	{
		if (peri[CR] & RCC_CR_HSERDY_Msk)
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
	if (getFieldData(peri[CFGR], RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos) == src::PLL)
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
		if (getBitData(peri[CR], RCC_CR_HSERDY_Pos))
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
#if defined(GD32F1)
#if defined(GD32F10X_CL)
	if(mul & 0x10)
		setBitData(peri[CFGR], true, 29);
	else
		setBitData(peri[CFGR], false, 29);
#else
	if(mul & 0x10)
		setBitData(peri[CFGR], true, 27);
	else
		setBitData(peri[CFGR], false, 27);
#endif
#endif

	setFieldData(peri[CFGR], RCC_CFGR_PLLMULL_Msk, mul, RCC_CFGR_PLLMULL_Pos);

	setBitData(peri[CFGR], xtpre, RCC_CFGR_PLLXTPRE_Pos);
	setBitData(peri[CFGR], src, RCC_CFGR_PLLSRC_Pos);

	// PLL 활성화
	setBitData(peri[CR], true, RCC_CR_PLLON_Pos);
	for (uint16_t i = 0; i < 10000; i++)
	{
		// PLL 활성화 확인
		if (getBitData(peri[CR], RCC_CR_PLLRDY_Pos))
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
		if (getBitData(peri[CR], RCC_CR_HSERDY_Pos) == false)
			return false;
		clk = mHseFreq * 1000000;
		break;
	case PLL:
		// PLL 활성화 점검
		if (getBitData(peri[CR], RCC_CR_PLLRDY_Pos) == false)
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
#if defined(GD32F1)
		if(buf & 0x04)
			setBitData(peri[CFGR], true, RCC_CFGR_ADCPRE2_Pos);
		else
			setBitData(peri[CFGR], false, RCC_CFGR_ADCPRE2_Pos);
#endif
		setFieldData(peri[CFGR], RCC_CFGR_ADCPRE_Msk, buf, RCC_CFGR_ADCPRE_Pos);
	}
	
	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(peri[CFGR], RCC_CFGR_PPRE2_Msk, apb2, RCC_CFGR_PPRE2_Pos, RCC_CFGR_PPRE1_Msk, apb1, RCC_CFGR_PPRE1_Pos, RCC_CFGR_HPRE_Msk, ahb, RCC_CFGR_HPRE_Pos);
	
	// 클럭 소스 변경
	setFieldData(peri[CFGR], RCC_CFGR_SW_Msk, sysclkSrc, RCC_CFGR_SW_Pos);

	gCoreClockFrequency = ahbClk;
	gAhbClockFrequency = ahbClk;
	gApb1ClockFrequency = apb1Clk;
	gApb2ClockFrequency = apb2Clk;

	return true;
}

void Clock::enableAhb1Clock(uint32_t position, bool en)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[AHBENR], en, position);
}

void Clock::enableApb1Clock(uint32_t position, bool en)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[APB1ENR], en, position);
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[APB2ENR], en, position);
}

void Clock::resetAhb1(uint32_t position)
{
#if defined(GD32F1)
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[AHBRSTR], true, position);
	setBitData(peri[AHBRSTR], false, position);
#endif
}

void Clock::resetApb1(uint32_t position)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[APB1RSTR], true, position);
	setBitData(peri[APB1RSTR], false, position);
}

void Clock::resetApb2(uint32_t position)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[APB2RSTR], true, position);
	setBitData(peri[APB2RSTR], false, position);
}

#endif

