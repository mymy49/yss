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

#include <config.h>
#include <yss/reg.h>

#include <yss/instance.h>

void __WEAK initSystem(void)
{
	// Power Control 장치 활성화
	clock.peripheral.setPwrEn(true);

	// 외부 고속 클럭 활성화
	clock.enableHse(HSE_CLOCK_FREQ);

	using namespace define::clock;

	// 주 PLL 활성화
	// Core, AHB clock = n / pDiv [MHz]
	// USB clock = n / qDiv [MHz] # 필요한 경우 48[MHz]에 맞춰야 함
	clock.enableMainPll(
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
		360,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv
		pll::qdiv::DIV8,			// uint8_t qDiv
		0							// uint8_t rDiv
	);

	// LCD 분주 설정 (lcdDiv)
	RCU_CFG1 |= 0 << 16;	// 0 : 2분주, 1 : 4분주, 2 : 8분주, 3 : 16분주
	
	// SAI PLL 할성화
	// GD32F4xx에는 SAI 장치가 실제로 없음
	// 48MHz USB Clock과 TFT-LCD Controller clock만 유효함
	// USB clock = n / pDiv [MHz]
	// TFT LCD clock = n / rDiv / lcdDiv [MHz]
	clock.enableSaiPll(
		192,						// uint16_t n
		saipll::pdiv::DIV4,			// uint8_t pDiv
		0,							// uint8_t qDiv
		saipll::rdiv::DIV7			// uint8_t rDiv
	);

	// 시스템 클럭 설정
	clock.setSysclk(
		sysclk::src::PLL,		// uint8_t sysclkSrc;
		divFactor::ahb::NO_DIV, // uint8_t ahb;
		divFactor::apb::DIV4,	// uint8_t apb1;
		divFactor::apb::DIV2	// uint8_t apb2;
	);

	// GPIO 활성화
	clock.peripheral.setGpioAEn(true);
	clock.peripheral.setGpioBEn(true);
	clock.peripheral.setGpioCEn(true);
	clock.peripheral.setGpioDEn(true);
	clock.peripheral.setGpioEEn(true);
	clock.peripheral.setGpioFEn(true);
	clock.peripheral.setGpioGEn(true);
	clock.peripheral.setGpioHEn(true);
	clock.peripheral.setGpioIEn(true);
}

extern "C"
{
void SystemCoreClockUpdate(void)
{

}
}

#endif