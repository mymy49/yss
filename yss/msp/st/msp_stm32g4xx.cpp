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

#include <__cross_studio_io.h>

#if defined(STM32G431xx) || defined(STM32G441xx) || \
	defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#include <config.h>

#if YSS_USE_DEFAULT_MSP == true

#include <yss/instance.h>

void __attribute__((weak)) initSystem(void)
{
	clock.setVoltageScale(define::clock::voltageScale::RANGE1_NORMAL);
	clock.enableHse(HSE_CLOCK_FREQ);

	using namespace define::clock;

#if USE_LSI_CLOCK == true
	clock.enableLsi();
#endif

	clock.pll.enable(
		pll::src::HSE,    // unsigned char src
		288,              // unsigned long vcoMhz
		pll::pdiv::DIV31, // unsigned char pDiv
		pll::qdiv::DIV8,  // unsigned char qDiv
		pll::rdiv::DIV2   // unsigned char rDiv
	);

	clock.pll.setPEn(true);
	clock.pll.setQEn(true);
	clock.pll.setREn(true);
	clock.peripheral.setAdc12ClkSrc(adc::src::PLL);
	clock.peripheral.setCan1ClkSrc(can::src::PCLK1);
	clock.peripheral.setI2c1ClkSrc(i2c::src::HSI16);
	clock.peripheral.setI2c2ClkSrc(i2c::src::HSI16);
	clock.peripheral.setI2c3ClkSrc(i2c::src::HSI16);

	clock.setSysclk(
		sysclk::src::PLL,       // unsigned char sysclkSrc;
		divFactor::ahb::NO_DIV, // unsigned char ahb;
		divFactor::apb::DIV4,   // unsigned char apb1;
		divFactor::apb::DIV2,   // unsigned char apb2;
		33                      // unsigned char vcc
	);

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
}

#endif

#endif