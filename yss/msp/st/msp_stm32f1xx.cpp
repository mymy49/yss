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

#include <config.h>

#include <yss/instance.h>

void __attribute__((weak)) initSystem(void)
{
	// Power Control 장치 활성화
	clock.peripheral.setPwrEn(true);

	// 외부 고속 클럭 활성화
	clock.enableHse(HSE_CLOCK_FREQ);

	using namespace define::clock;
	
	// 주 PLL 활성화
	// pllClock = HSE_CLOCK_FREQ * (mul + 2) / (1 + xtpre);
#if HSE_CLOCK_FREQ == 8000000
	clock.enableMainPll(
		pll::src::HSE,	// unsigned char src;
		0,				// unsigned char xtpre;
		7				// unsigned char mul;
	);
#define PLL_ENABLED
# elif HSE_CLOCK_FREQ == 12000000
	clock.enableMainPll(
		pll::src::HSE,	// unsigned char src;
		0,				// unsigned char xtpre;
		4				// unsigned char mul;
	); 
#define PLL_ENABLED
#endif

#if defined(PLL_ENABLED)
	// 시스템 클럭 설정
	clock.setSysclk(
		sysclk::src::PLL,		// unsigned char sysclkSrc;
		divFactor::ahb::NO_DIV, // unsigned char ahb;
		divFactor::apb::DIV2,	// unsigned char apb1;
		divFactor::apb::NO_DIV	// unsigned char apb2;
	);
#endif
	
	// 플래시 메모리 prefetch 기능 활성화
	flash.setPrefetchEn(true);
	
	// GPIO 활성화
	clock.peripheral.setGpioAEn(true);
	clock.peripheral.setGpioBEn(true);
	clock.peripheral.setGpioCEn(true);
	clock.peripheral.setGpioDEn(true);
	clock.peripheral.setAfioEn(true);
	
	// SWD 단자 외의 JTAG단자는 일반 포트로 전환
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_NOJNTRST_Msk;
}

#endif