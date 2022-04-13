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

#include <__cross_studio_io.h>

#include <drv/mcu.h>

#if defined(STM32F7)

#include <config.h>
#include <yss/instance.h>

inline void enableICache(void)
{
#if defined(__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
	if (SCB->CCR & SCB_CCR_IC_Msk)
		return; /* return if ICache is already enabled */

	__DSB();
	__ISB();
	SCB->ICIALLU = 0UL; /* invalidate I-Cache */
	__DSB();
	__ISB();
	SCB->CCR |= (uint32_t)SCB_CCR_IC_Msk; /* enable I-Cache */
	__DSB();
	__ISB();
#endif
}

void __attribute__((weak)) initSystem(void)
{
	clock.enableHse(HSE_CLOCK_FREQ);
	clock.enableLsi();
	clock.setUsbClkSrc(define::clock::usbclk::src::MAIN_PLL);

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

using namespace define::clock;
#if HSE_CLOCK_FREQ == 8000000
#define PLL_ENABLED

	// Main PLL 설정
	clock.enableMainPll(
		pll::src::HSE,	 // unsigned char src
		8,				 // unsigned char m
		432,			 // unsigned short n
		pll::pdiv::DIV2, // unsigned char pDiv
		pll::qdiv::DIV9, // unsigned char qDiv
		0				 // unsigned char rDiv
	);
#elif HSE_CLOCK_FREQ == 12000000
#define PLL_ENABLED

	// Main PLL 설정
	clock.enableMainPll(
		pll::src::HSE,	 // unsigned char src
		12,				 // unsigned char m
		432,			 // unsigned short n
		pll::pdiv::DIV2, // unsigned char pDiv
		pll::qdiv::DIV9, // unsigned char qDiv
		0				 // unsigned char rDiv
	);
#elif HSE_CLOCK_FREQ == 25000000
#define PLL_ENABLED

	// Main PLL 설정
	clock.enableMainPll(
		pll::src::HSE,	 // unsigned char src
		25,				 // unsigned char m
		432,			 // unsigned short n
		pll::pdiv::DIV2, // unsigned char pDiv
		pll::qdiv::DIV9, // unsigned char qDiv
		0				 // unsigned char rDiv
	);

	clock.enableSaiPll(
		192,                 // unsigned long n
		saipll::pdiv::DIV4,  // unsigned char pDiv
		saipll::qdiv::DIV15, // unsigned char qDiv
		saipll::rdiv::DIV7   // unsigned char rDiv
	);
#endif

	using namespace define::clock;

	clock.setSysclk(
		define::clock::sysclk::src::PLL,       // unsigned char sysclkSrc;
		define::clock::divFactor::ahb::NO_DIV, // unsigned char ahb;
		define::clock::divFactor::apb::DIV4,   // unsigned char apb1;
		define::clock::divFactor::apb::DIV2,   // unsigned char apb2;
		33                                     // unsigned char vcc
	);

	enableICache();
	flash.setPrefetchEn(true);
	flash.setArtEn(true);

	clock.peripheral.setGpioAEn(true);
	clock.peripheral.setGpioBEn(true);
	clock.peripheral.setGpioCEn(true);
	clock.peripheral.setGpioDEn(true);
	clock.peripheral.setGpioEEn(true);
	clock.peripheral.setGpioFEn(true);
	clock.peripheral.setGpioGEn(true);
	clock.peripheral.setGpioHEn(true);
	clock.peripheral.setGpioIEn(true);
	clock.peripheral.setGpioJEn(true);
	clock.peripheral.setGpioKEn(true);

	clock.peripheral.setSyscfgEn(true);
	syscfg.swapFmc(true);

	clock.peripheral.setPwrEn(true);
}

#endif
