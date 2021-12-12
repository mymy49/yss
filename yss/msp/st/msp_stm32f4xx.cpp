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

#include <__cross_studio_io.h>

#include <drv/mcu.h>

#if defined(STM32F4)

#include <config.h>

#include <yss/instance.h>

void __attribute__((weak)) initSystem(void)
{
	clock.enableHse(HSE_CLOCK_FREQ);

	using namespace define::clock;
	
	// Main PLL 클럭 설정
	// inputVCO = inputClock / m;	1~2 MHz를 만들어야 함
	// VCO = inputVCO * n;			192~432 MHz를 만들어야 함
	// P(PLLCLK) = VCO / pDiv;		180 MHz를 넘어선 안됨
	// Q(PLL48CK) = VCO / qDiv;		적정 클럭은 48 MHz, 75MHz를 넘어선 안됨
	// R은 사용 안함

	// SAI PLL 클럭 설정
	// inputVCO = inputClock / m;	Main PLL에서 설정된 값을 그대로 적용 받음
	// VCO = inputVCO * n;			192~432 MHz를 만들어야 함
	// P는 사용 안함
	// Q(PLLSAICLK) = VCO / qDiv;	45 MHz를 넘어선 안됨
	// R(PLLLCDCLK) = VCO / rDiv;	42 MHz를 넘어선 안됨

#if HSE_CLOCK_FREQ == 8000000
#define PLL_ENABLED
	
	// Main PLL 설정
	clock.enableMainPll(
		pll::src::HSE,	 // unsigned char src
		8,				 // unsigned char m
		360,			 // unsigned short n
		pll::pdiv::DIV2, // unsigned char pDiv
		pll::qdiv::DIV8, // unsigned char qDiv
		0				 // unsigned char rDiv
	);
	
	// SAI PLL 설정
	clock.enableSaiPll(
		192,                                // unsigned short n
		0,                                  // unsigned char pDiv
		saipll::qdiv::DIV15, // unsigned char qDiv
		saipll::rdiv::DIV7   // unsigned char rDiv
	);
# elif HSE_CLOCK_FREQ == 12000000
#define PLL_ENABLED

	// Main PLL 설정
	clock.enableMainPll(
		pll::src::HSE,	 // unsigned char src
		12,				 // unsigned char m
		360,			 // unsigned short n
		pll::pdiv::DIV2, // unsigned char pDiv
		pll::qdiv::DIV7, // unsigned char qDiv
		0				 // unsigned char rDiv
	);

	// SAI PLL 설정
	clock.enableSaiPll(
		192,                                // unsigned short n
		0,                                  // unsigned char pDiv
		saipll::qdiv::DIV15, // unsigned char qDiv
		saipll::rdiv::DIV7   // unsigned char rDiv
	);
#endif

#if defined(PLL_ENABLED)
	clock.setSysclk(
		sysclk::src::PLL,		// unsigned char sysclkSrc;
		divFactor::ahb::NO_DIV, // unsigned char ahb;
		divFactor::apb::DIV4,	// unsigned char apb1;
		divFactor::apb::DIV2,	// unsigned char apb2;
		33						// unsigned char vcc
	);
#endif
	flash.setPrefetchEn(true);
	flash.setDCacheEn(true);
	flash.setICacheEn(true);
	
	clock.peripheral.setGpioAEn(true);
	clock.peripheral.setGpioBEn(true);
	clock.peripheral.setGpioCEn(true);
	clock.peripheral.setGpioDEn(true);
	clock.peripheral.setGpioEEn(true);
	clock.peripheral.setGpioFEn(true);
	clock.peripheral.setGpioGEn(true);
	clock.peripheral.setGpioHEn(true);
	clock.peripheral.setGpioIEn(true);
#if defined(GPIOJ)
	clock.peripheral.setGpioJEn(true);
#endif
#if defined(GPIOK)
	clock.peripheral.setGpioKEn(true);
#endif

	clock.peripheral.setPwrEn(true);
}

#endif