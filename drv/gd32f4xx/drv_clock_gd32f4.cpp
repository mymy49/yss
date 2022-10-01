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

#if defined(GD32F4)

#include <drv/Clock.h>
#include <yss/reg.h>

extern uint32_t gCoreClockFrequency;
extern uint32_t gAhbClockFrequency;
extern uint32_t gApb1ClockFrequency;
extern uint32_t gApb2ClockFrequency;

static int32_t gHseFreq __attribute__((section(".non_init")));
static int32_t gPllFreq __attribute__((section(".non_init")));
static int32_t gSaiPllFreq __attribute__((section(".non_init")));
static int32_t gLcdPllFreq __attribute__((section(".non_init")));
static int32_t gI2sPllFreq __attribute__((section(".non_init")));
static int32_t gMainPllUsbFreq __attribute__((section(".non_init")));

static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const uint32_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	gHseFreq = hseHz;

	if (hseHz < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hseHz)
		return false;

	if (useOsc)
		RCU_CTL |= RCU_CTL_HXTALEN | RCU_CTL_HXTALBPS;
	else
		RCU_CTL |= RCU_CTL_HXTALEN;

	for (uint32_t i = 0; i < 10000; i++)
	{
		if (RCU_CTL & RCU_CTL_HXTALSTB)
			return true;
	}

	return false;
}

bool Clock::enableMainPll(uint8_t src, uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv)
{
	uint32_t vco, pll, pll48, buf;

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
		buf = (uint32_t)gHseFreq;
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

	for (uint16_t i = 0; i < 10000; i++)
	{
		// PLL 활성화 확인
		if (RCU_CTL & RCU_CTL_PLLSTB)
		{
			gPllFreq = pll;
			return true;
		}
	}

error:
	gPllFreq = 0;
	return false;
}

bool Clock::enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t rDiv)
{
	uint32_t vco, q, r, usb, lcd, buf, m;

	using namespace ec::clock;

	if (~RCU_CTL & RCU_CTL_PLLSTB)
		goto error;

	if (saipll::N_MIN > n || n > saipll::N_MAX)
		goto error;

	if (pDiv > saipll::P_MAX)
		goto error;

	if (saipll::R_MIN > rDiv || rDiv > saipll::R_MAX)
		goto error;

	switch (RCU_PLL >> 22 & 0x01)
	{
	case define::clock::pll::src::HSI:
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (~RCU_CTL & RCU_CTL_HXTALSTB)
			goto error;
		buf = (uint32_t)gHseFreq;
		break;
	default:
		goto error;
	}
	
	vco = buf / (RCU_PLL & 0x3F) * n;
	using namespace ec::clock;
	if (vco < saipll::VCO_MIN_FREQ || saipll::VCO_MAX_FREQ < vco)
		goto error;

	usb = vco / (2 << pDiv);
	if (saipll::USB48_MAX_FREQ < usb)
		goto error;

	lcd = vco / rDiv;
	if (saipll::LCD_MAX_FREQ < lcd)
		goto error;
	
	RCU_PLLSAI = rDiv << 28 | pDiv << 16 | n << 6;
	RCU_CTL |= RCU_CTL_PLLSAIEN;

	for (uint16_t i = 0; i < 10000; i++)
	{
		if (RCU_CTL & RCU_CTL_PLLSAISTB)
		{
			gLcdPllFreq = lcd;
			gMainPllUsbFreq = usb;
			return true;
		}
	}

error:
	gLcdPllFreq = 0;
	gMainPllUsbFreq = 0;
	return false;
}

bool Clock::enableI2sPll(uint16_t n, uint8_t rDiv)
{
	uint32_t vco, r, i2s, buf, m;

	using namespace ec::clock::i2spll;

	if (~RCU_CTL & RCU_CTL_PLLSTB)
		goto error;

	if (N_MIN > n || n > N_MAX)
		goto error;

	if (R_MIN > rDiv || rDiv > R_MAX)
		goto error;

	switch (RCU_PLL >> 22 & 0x01)
	{
	case define::clock::pll::src::HSI:
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (~RCU_CTL & RCU_CTL_HXTALSTB)
			goto error;
		buf = (uint32_t)gHseFreq;
		break;
	default:
		goto error;
	}
	
	vco = buf / (RCU_PLL & 0x3F) * n;
	using namespace ec::clock::i2spll;
	if (vco < VCO_MIN_FREQ || VCO_MAX_FREQ < vco)
		goto error;

	i2s = vco / rDiv;
	if (I2S_MAX_FREQ < i2s)
		goto error;
	
	RCU_PLLI2S = rDiv << 28 | n << 6;
	RCU_CTL |= RCU_CTL_PLLI2SEN;

	for (uint16_t i = 0; i < 10000; i++)
	{
		if (RCU_CTL & RCU_CTL_PLLI2SSTB)
		{
			gI2sPllFreq = i2s;
			return true;
		}
	}

error:
	gI2sPllFreq = 0;
	return false;
}

bool Clock::setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc)
{
	int32_t  clk, ahbClk, apb1Clk, apb2Clk, adcClk;
	int8_t buf;

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case HSE:
		// HSE 활성화 점검
		if (~RCU_CTL & RCU_CTL_HXTALSTB)
			return false;
		clk = gHseFreq;
		break;
	case PLL:
		// PLL 활성화 점검
		if (~RCU_CTL & RCU_CTL_PLLSTB)
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

	adcClk = apb2Clk / (ec::clock::adc::MAX_FREQ / 1000);
	if (adcClk >= 1000)
	{
		adcClk /= 1000;
		adcClk += 1;
		buf = adcClk / 2 - 1;
	}

	gCoreClockFrequency = ahbClk;
	gAhbClockFrequency = ahbClk;
	gApb1ClockFrequency = apb1Clk;
	gApb2ClockFrequency = apb2Clk;
	
	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(RCU_CFG0, 0x7 << 11, apb2, 11, 0x7 << 8, apb1, 8, 0xF << 4, ahb, 4);
	
	// 클럭 소스 변경
	setFieldData(RCU_CFG0, 0x3 << 0, sysclkSrc, 0);

	return true;
}

void Clock::enableAhb1Clock(uint32_t position, bool en)
{
	setBitData(RCU_AHB1EN, en, position);
}

void Clock::enableAhb2Clock(uint32_t position, bool en)
{
	setBitData(RCU_AHB2EN, en, position);
}

void Clock::enableAhb3Clock(uint32_t position, bool en)
{
	setBitData(RCU_AHB3EN, en, position);
}

void Clock::enableApb1Clock(uint32_t position, bool en)
{
	setBitData(RCU_APB1EN, en, position);
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
	setBitData(RCU_APB2EN, en, position);
}

void Clock::resetAhb1(uint32_t position)
{
	setBitData(RCU_AHB1RST, true, position);
	setBitData(RCU_AHB1RST, false, position);
}

void Clock::resetAhb2(uint32_t position)
{
	setBitData(RCU_AHB2RST, true, position);
	setBitData(RCU_AHB2RST, false, position);
}

void Clock::resetAhb3(uint32_t position)
{
	setBitData(RCU_AHB3RST, true, position);
	setBitData(RCU_AHB3RST, false, position);
}

void Clock::resetApb1(uint32_t position)
{
	setBitData(RCU_APB1RST, true, position);
	setBitData(RCU_APB1RST, false, position);
}

void Clock::resetApb2(uint32_t position)
{
	setBitData(RCU_APB2RST, true, position);
	setBitData(RCU_APB2RST, false, position);
}

void Clock::enableSdram(bool en)
{
	if(en)
		RCU_AHB3EN |= RCU_AHB3EN_EXMCEN;
	else
		RCU_AHB3EN &= ~RCU_AHB3EN_EXMCEN;
}

#endif

