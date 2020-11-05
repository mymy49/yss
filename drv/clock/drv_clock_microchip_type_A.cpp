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
//	이전 주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 2020.04.26
//  주담당자 : 맨틀코어 (tttwwuu@naver.com) 2020.04.26 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if	defined (__SAML21E15A__) || defined (__SAML21E15B__) || defined (__SAML21E16A__) || defined (__SAML21E16B__) || \
	defined (__SAML21E17A__) || defined (__SAML21E17B__) || defined (__SAML21E18B__) || defined (__SAML21G16A__) || \
	defined (__SAML21G16B__) || defined (__SAML21G17A__) || defined (__SAML21G17B__) || defined (__SAML21G18A__) || \
	defined (__SAML21G18B__) || defined (__SAML21J16A__) || defined (__SAML21J16B__) || defined (__SAML21J17A__) || \
	defined (__SAML21J17B__) || defined (__SAML21J18A__) || defined (__SAML21J18B__)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
//#include <drv/clock/drv_st_clock_type_A_register.h>
//#include <drv/clock/drv_st_power_type_A_register.h>

drv::Clock clock;

namespace drv
{
	unsigned long gHseFreq __attribute__ ((section (".non_init")));
	unsigned long gPllFreq __attribute__ ((section (".non_init")));

	bool Clock::enableHse(unsigned char hseMhz)
	{
		unsigned long hse = (unsigned long)hseMhz * 1000000;
		gHseFreq = hseMhz;
		
		if(hse < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hse)
			return false;
		
		if(hseMhz <= 2)
			OSCCTRL->XOSCCTRL.bit.GAIN = 0;
		else if(hseMhz <= 4)
			OSCCTRL->XOSCCTRL.bit.GAIN = 1;
		else if(hseMhz <= 8)
			OSCCTRL->XOSCCTRL.bit.GAIN = 2;
		else if(hseMhz <= 16)
			OSCCTRL->XOSCCTRL.bit.GAIN = 3;
		else if(hseMhz <= 32)
			OSCCTRL->XOSCCTRL.bit.GAIN = 4;
		OSCCTRL->XOSCCTRL.bit.ENABLE = true;

		return true;
	}

	bool Clock::enableLse(void)
	{
		OSC32KCTRL->XOSC32K.bit.XTALEN = true;
		OSC32KCTRL->XOSC32K.bit.ONDEMAND = false;
		OSC32KCTRL->XOSC32K.bit.ENABLE = true;

		for(int i=0;i<10000;i++)
			if(OSC32KCTRL->STATUS.bit.XOSC32KRDY == true)
				return true;

		return false;
	}

	bool Clock::setGenericClock(unsigned char num, bool en, unsigned short div, unsigned char src)
	{
		if(num >= sizeof(GCLK->GENCTRL) / 4)
			return false;

		unsigned int reg = GCLK->GENCTRL[num].reg;

		reg &= ~(GCLK_GENCTRL_DIV_Msk | GCLK_GENCTRL_GENEN | GCLK_GENCTRL_SRC_Msk);
		reg |= (div << GCLK_GENCTRL_DIV_Pos & GCLK_GENCTRL_DIV_Msk) | (en << GCLK_GENCTRL_GENEN_Pos) | (src << GCLK_GENCTRL_SRC_Pos & GCLK_GENCTRL_SRC_Msk);
		GCLK->GENCTRL[num].reg = reg;

		return true;
	}

/*
	static const unsigned long gPpreDiv[8] = {1, 1,	1, 1, 2, 4, 8, 16};
	static const unsigned long gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

	bool System::enableHse(unsigned long hse, bool en)
	{
		OSCCTR->INTENSET
		gHseFreq = hse;

		if(hse < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hse)
			return false;

		setRccHseEn(en);

		if(en)
		{
			for(unsigned short i=0;i<10000;i++)
			{
				if(getRccHseReady())
					return true;
			}
		}
		else
		{
			return true;
		}

		return false;
	}

	bool System::enableLsi(bool en)
	{
		setRccLsiEn(en);
		if(en == true)
		{
			for(unsigned short i=0;i<10000;i++)
			{
				if(getRccLsiReady())
					return true;
			}
		}
		else
		{
			return true;
		}

		return false;
	}

	bool System::enableLse(bool en)
	{
		setRccLseEn(en);
		if(en == true)
		{
			for(unsigned short i=0;i<10000;i++)
			{
				if(getRccLseReady())
					return true;
			}
		}
		else
		{
			return true;
		}

		return false;
	}

	bool MainPll::enable(config::clock::Pll &config, bool en)
	{
		unsigned long vco, pll, pll48;

		using namespace define::clock::sysclk;
		if(getRccSysclkSw()	== src::PLL)
			goto error;

		if(en == false)
		{
			setRccMainPllOn(false);
			gPllFreq = 0;
			return true;
		}

		using namespace ec::clock::pll;
		if(PLL_M_MIN > config.m || config.m > PLL_M_MAX)
			goto error;

		if(PLL_N_MIN > config.n || config.n > PLL_N_MAX)
			goto error;

		if(config.p > PLL_P_MAX)
			goto error;

		if(PLL_Q_MIN > config.q || config.q > PLL_Q_MAX)
			goto error;

		if(config.src == src::HSE)
		{
			if(getRccHseReady() == true)
				vco = gHseFreq;
			else
				goto error;
		}
		else
			vco = ec::clock::hsi::FREQ;


		vco /= config.m;
		vco *= config.n;

		if(	vco < VCO_MIN_FREQ && VCO_MAX_FREQ < vco)
			goto error;

		using namespace ec::clock;
		pll = vco / (2 << config.p);
		if(pll > sysclk::MAX_FREQ)
			goto error;

		pll48 = vco / config.q;
		if(pll48 > pll::USB48_MAX_FREQ)
			goto error;

		setRccMainPllSrc(config.src);
		setRccMainPllm(config.m);
		setRccMainPlln(config.n);
		setRccMainPllp(config.p);
		setRccMainPllq(config.q);

		setRccMainPllOn(true);

		for(unsigned short i=0;i<10000;i++)
		{
			if(getRccMainPllReady())
			{
				gPllFreq = pll;
				return true;
			}
		}

error:
		gPllFreq = 0;
		return false;
	}

	unsigned long MainPll::getFreq(void)
	{
		if(getRccMainPllReady()	== false)
			return 0;

		return 0;
	}

	bool SaiPll::enable(config::clock::Saipll &config, bool en)
	{
		unsigned long vco, pll, usb, sai, lcd;

		if(en == false)
		{
			setRccSaiPllOn(false);
			return true;
		}

		if(getRccMainPllReady() == false)
			return false;

		using namespace ec::clock::saiPll;
		if(PLL_N_MIN > config.n || config.n > PLL_N_MAX)
			return false;

		if(config.p > PLL_P_MAX)
			return false;

		if(PLL_Q_MIN > config.pllq || config.pllq > PLL_Q_MAX)
			return false;

		if(config.saiq > SAI_Q_MAX)
			return false;

		if(PLL_R_MIN > config.pllr || config.pllr > PLL_R_MAX)
			return false;

		if(config.lcdr > LCD_R_MAX)
			return false;

		if(getRccMainPllSrc() == define::clock::pll::src::HSE)
		{
			if(getRccHseReady() == true)
				vco = gHseFreq;
			else
				return false;

			vco = gHseFreq;
		}
		else
			vco = ec::clock::hsi::FREQ;


		vco /= getRccMainPllm();
		vco *= config.n;

		using namespace ec::clock::saiPll;
		if(	vco < VCO_MIN_FREQ && VCO_MAX_FREQ < vco)
			return false;

		usb = vco / (2 * (config.p + 1));
		if(usb > USB48_MAX_FREQ)
			return false;

		pll = vco / config.pllq;
		if(pll > SAI_PLL_MAX_FREQ)
			return false;

		sai = pll / (config.saiq+1);
		if(sai > SAI_MAX_FREQ)
			return false;

		lcd = vco / config.pllr;
		if(lcd > LCD_PLL_MAX_FREQ)
			return false;

		lcd = lcd / (2 << config.lcdr);
		if(lcd > LCD_PLL_MAX_FREQ)
			return false;

		setRccSaiPlln(config.n);
		setRccSaiPllp(config.p);
		setRccSaiPllq(config.pllq);
		setRccSaiDivq(config.saiq);
		setRccSaiPllr(config.pllr);
		setRccSaiDivr(config.lcdr);

		setRccSaiPllOn(true);

		for(unsigned short i=0;i<10000;i++)
		{
			if(getRccSaiPllReady())
				return true;
		}

		return false;
	}

	bool System::setUsbClkSrc(unsigned char src)
	{
		if(src < 0 || src > 1)
			return false;
		setRccUsbClkSel(src);
		return true;
	}

	bool System::setSdmmcClkSrc(unsigned char src)
	{
		if(src < 0 || src > 1)
			return false;
		setRccSdmmc1ClkSel(src);
		return true;
	}

	bool System::setSysclk(config::clock::Sysclk &config)
	{
		unsigned long clk, ahb,	apb1, apb2;

		using namespace define::clock::sysclk::src;
		switch(config.sysclkSrc)
		{
		case HSI :
			clk = ec::clock::hsi::FREQ;
			break;
		case HSE :
			if(getRccHseReady() == false)
				return false;
			clk = gHseFreq;
			break;
		case PLL :
			if(getRccMainPllReady()	== false)
				return false;
			clk = gPllFreq;
			break;
		default :
			return false;
		}

		ahb = clk / gHpreDiv[config.ahb];
		if(ahb > ec::clock::sysclk::MAX_FREQ)
			return false;

		apb1 = ahb / gPpreDiv[config.apb1];
		if(apb1	> ec::clock::apb1::MAX_FREQ)
			return false;

		apb2 = ahb / gPpreDiv[config.apb2];
		if(apb2	> ec::clock::apb2::MAX_FREQ)
			return false;

		if(ahb > ec::clock::sysclk::OVER_DRIVE_FREQ)
		{
			setRccPwrEn(true);
			setPwrOverdriveEn(true);
			while(!getPwrOverdriveReady());
			setPwrOverdriveSwitchEn(true);
			while(!getPwrOverdriveSwitchReady());
		}

		setRccHpre(config.ahb);
		setRccPpre1(config.apb1);
		setRccPpre2(config.apb2);

		flash.setLatency(ahb, config.vcc);
		setRccSysclkSw(config.sysclkSrc);

		return true;
	}

	unsigned long System::getSysClkFreq(void)
	{
		unsigned long clk;

		switch(getRccSysclkSw())
		{
		case define::clock::sysclk::src::HSI :
			clk = ec::clock::hsi::FREQ;
			break;
		case define::clock::sysclk::src::HSE :
			clk = gHseFreq;
			break;
		case define::clock::sysclk::src::PLL :
			clk = gPllFreq;
			break;
		}

		clk /= gHpreDiv[getRccHpre()];

		return clk;
	}

	unsigned long System::getApb1ClkFreq(void)
	{
		return (unsigned long)(getSysClkFreq() / gPpreDiv[getRccPpre1()]);
	}

	unsigned long System::getApb2ClkFreq(void)
	{
		return (unsigned long)(getSysClkFreq() / gPpreDiv[getRccPpre2()]);
	}

	unsigned long System::getTimerApb1ClkFreq(void)
	{
		unsigned char pre = getRccPpre1();
		unsigned long clk = clock.system.getSysClkFreq() / gPpreDiv[pre];
		if(gPpreDiv[pre] > 1)
			clk <<= 1;
		return clk;
	}

	unsigned long System::getTimerApb2ClkFreq(void)
	{
		unsigned char pre = getRccPpre2();
		unsigned long clk = clock.system.getSysClkFreq() / gPpreDiv[pre];
		if(gPpreDiv[pre] > 1)
			clk <<= 1;
		return clk;
	}
*/
}

#endif
