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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
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
}

#endif
