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

void __attribute__((weak)) initSystem(void)
{
	clock.peripheral.setPwrEn(true);
	clock.enableHse(HSE_CLOCK_FREQ);

	using namespace define::clock;

	clock.enableMainPll(
		pll::src::HSE,				// unsigned char src
		HSE_CLOCK_FREQ / 1000000,	// unsigned char m
		360,						// unsigned short n
		pll::pdiv::DIV2,			// unsigned char pDiv
		pll::qdiv::DIV8,			// unsigned char qDiv
		0							// unsigned char rDiv
	);

	// LCD source 분주 설정
	RCU_CFG1 |= 0 << 16;	// 0 : 2분주, 1 : 4분주, 2 : 8분주, 3 : 16분주

	clock.enableSaiPll(
		192,						// unsigned short n
		saipll::pdiv::DIV4,			// unsigned char pDiv / 48 MHz Source
		0,							// unsigned char qDiv / 아무 효과 없음
		saipll::rdiv::DIV7			// unsigned char rDiv / LCD Source
	);

	clock.setSysclk(
		sysclk::src::PLL,		// unsigned char sysclkSrc;
		divFactor::ahb::NO_DIV, // unsigned char ahb;
		divFactor::apb::DIV4,	// unsigned char apb1;
		divFactor::apb::DIV2	// unsigned char apb2;
	);

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