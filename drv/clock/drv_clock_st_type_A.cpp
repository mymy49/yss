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


#if	defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/clock/drv_st_clock_type_A_register.h>
#include <drv/clock/drv_st_power_type_A_register.h>

#if defined(RCC)
drv::Clock clock;
#endif

namespace drv
{
	unsigned char gHseFreq __attribute__ ((section (".non_init")));
	unsigned int gPllFreq __attribute__ ((section (".non_init")));
	unsigned int gSaiPllFreq __attribute__ ((section (".non_init")));
	unsigned int gLcdPllFreq __attribute__ ((section (".non_init")));

	static const unsigned int gPpreDiv[8] = {1, 1,	1, 1, 2, 4, 8, 16};
	static const unsigned int gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

	bool Clock::enableHse(unsigned char hseMhz)
	{
		unsigned int hse = (unsigned int)hseMhz * 1000000;
		gHseFreq = hseMhz;

#if defined(YSS_PERI_REPORT)
		debug_printf("\n########## HSE 장치 설정 ##########\n\n");
		debug_printf("외부 크리스탈 클럭 = %d MHz\n", hseMhz);
#endif
		
		if(hse < ec::clock::hse::HSE_MIN_FREQ || ec::clock::hse::HSE_MAX_FREQ < hse)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("HSE 클럭이 입력 허용 범위를 초과했습니다. %d kHz(min) < %d kHz(user) < %d kHz(max).\n", ec::clock::hse::HSE_MIN_FREQ / 1000, hse / 1000, ec::clock::hse::HSE_MAX_FREQ / 1000);
#endif
			return false;
		}

		setRccHseEn(true);

		for(unsigned int i=0;i<100000;i++)
		{
			if(getRccHseReady())
			{
#if defined(YSS_PERI_REPORT)
				debug_printf("장치 설정 완료.\n");
#endif
				return true;
			}
		}

#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif
		return false;
	}

	bool Clock::enableLsi(void)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("\n########## LSI 장치 설정 ##########\n\n");
		debug_printf("내부 LSI 크리스탈 클럭 = 32 kHz\n");
#endif

		setRccLsiEn(true);
		for(unsigned short i=0;i<10000;i++)
		{
			if(getRccLsiReady())
			{
#if defined(YSS_PERI_REPORT)
				debug_printf("장치 설정 완료.\n");
#endif
				return true;
			}
		}

#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif
		return false;
	}

	bool Clock::setUsbClkSrc(unsigned char src)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("\n########## USB 클럭 소스 변경 ##########\n\n");
#endif

		if(src < 0 || src > 1)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("입력 소스가 설점 범위를 벗어났습니다.\n");
#endif
			return false;
		}

#if defined(YSS_PERI_REPORT)
		char *srcName[] = 
		{
			(char*)"Main PLL",
            (char*)"SAI_PLL"
		};

		debug_printf("USB 클럭 소스 = %s\n", srcName[src]);
#endif

		setRccUsbClkSel(src);
		return true;
	}

	bool Clock::enableLse(bool en)
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

	unsigned long Clock::getTimerApb1ClkFreq(void)
	{
		unsigned char pre = getRccPpre1();
		unsigned long clk = clock.getSysClkFreq() / gPpreDiv[pre];
		if(gPpreDiv[pre] > 1)
			clk <<= 1;
		return clk;
	}

	unsigned long Clock::getTimerApb2ClkFreq(void)
	{
		unsigned char pre = getRccPpre2();
		unsigned long clk = clock.getSysClkFreq() / gPpreDiv[pre];
		if(gPpreDiv[pre] > 1)
			clk <<= 1;
		return clk;
	}

	unsigned long Clock::getApb1ClkFreq(void)
	{
		return (unsigned long)(getSysClkFreq() / gPpreDiv[getRccPpre1()]);
	}

	unsigned long Clock::getApb2ClkFreq(void)
	{
		return (unsigned long)(getSysClkFreq() / gPpreDiv[getRccPpre2()]);
	}

	unsigned long Clock::getSysClkFreq(void)
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

	unsigned long MainPll::getFreq(void)
	{
		if(getRccMainPllReady()	== false)
			return 0;

		return 0;
	}

/*

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

	bool Clock::setSdmmcClkSrc(unsigned char src)
	{
		if(src < 0 || src > 1)
			return false;
		setRccSdmmc1ClkSel(src);
		return true;
	}

	bool Clock::setSysclk(config::clock::Sysclk &config)
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
			clk = gHseFreq * 1000000;
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



*/
}

#endif
