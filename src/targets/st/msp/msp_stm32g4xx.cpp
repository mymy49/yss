/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32G4)

#include <config.h>
#include <yss/instance.h>
#include <targets/st/bitfield.h>

#if HSE_CLOCK_FREQ % 4000000
#error "STM32G474xx의 HSE의 클럭 주파수는 반드시 4MHz의 배수를 사용해야 합니다."
#endif

extern "C"
{
	void __WEAK SystemCoreClockUpdate(void)
	{

	}
}

void __WEAK initializeSystem(void)
{
	using namespace define::clock;

	// Power Controller 클럭 활성화
	clock.enableApb1_1Clock(RCC_APB1ENR1_PWREN_Pos);

	// Power Scale 설정
	clock.setPowerScale(powerScale::SCALE1_MODE);

	// 외부 크리스탈 클럭 활성화
#if defined(HSE_CLOCK_FREQ)
	clock.enableHse(HSE_CLOCK_FREQ);
#endif

	// Main PLL 설정
	clock.enableMainPll(
#if defined(HSE_CLOCK_FREQ)
		pll::src::HSE,					// uint8_t src
		HSE_CLOCK_FREQ / 4000000 - 1,	// uint8_t m
#else
		pll::src::HSI,					// uint8_t src
		16000000 / 4000000 - 1,			// uint8_t m
#endif
		85,								// uint16_t n
		2,								// uint8_t pDiv
		pll::qdiv::DIV2,				// uint8_t qDiv
		pll::rdiv::DIV2					// uint8_t rDiv
	);
	
	// SYSCLK 설정
	clock.setSysclk(
		sysclk::src::PLL,				// uint8_t sysclkSrc
		sysclk::ahbDiv::NO_DIV,	// uint8_t ahbDiv
		sysclk::apbDiv::DIV4,		// uint8_t apb1Div
		sysclk::apbDiv::DIV2		// uint8_t apb2Div
	);

	// FLASH 성능 도구 활성화
	flash.enableDataCache();
	flash.enableInstructionCache();
	flash.enablePrefetch();

	clock.enableAhb2Clock(RCC_AHB2ENR_GPIOAEN_Pos);
	clock.enableAhb2Clock(RCC_AHB2ENR_GPIOBEN_Pos);
	clock.enableAhb2Clock(RCC_AHB2ENR_GPIOCEN_Pos);
	clock.enableAhb2Clock(RCC_AHB2ENR_GPIODEN_Pos);
	clock.enableAhb2Clock(RCC_AHB2ENR_GPIOEEN_Pos);
	clock.enableAhb2Clock(RCC_AHB2ENR_GPIOFEN_Pos);
	clock.enableAhb2Clock(RCC_AHB2ENR_GPIOGEN_Pos);
}

void initializeDma(void)
{
	dmaChannel1.enableClock();
	dmaChannel1.initialize();
	dmaChannel1.enableInterrupt();
	dmaChannel2.initialize();
	dmaChannel2.enableInterrupt();
	dmaChannel3.initialize();
	dmaChannel3.enableInterrupt();
	dmaChannel4.initialize();
	dmaChannel4.enableInterrupt();
	dmaChannel5.initialize();
	dmaChannel5.enableInterrupt();
	dmaChannel6.initialize();
	dmaChannel6.enableInterrupt();
#if defined(STM32G431xx)
	dmaChannel7.enableClock();
#endif
	dmaChannel7.initialize();
	dmaChannel7.enableInterrupt();
	dmaChannel8.initialize();
	dmaChannel8.enableInterrupt();
#if defined(STM32G474xx)
	dmaChannel9.enableClock();
#endif
	dmaChannel9.initialize();
	dmaChannel9.enableInterrupt();
	dmaChannel10.initialize();
	dmaChannel10.enableInterrupt();
	dmaChannel11.initialize();
	dmaChannel11.enableInterrupt();
	dmaChannel12.initialize();
	dmaChannel12.enableInterrupt();
#if defined(STM32G474xx)
	dmaChannel13.initialize();
	dmaChannel13.enableInterrupt();
	dmaChannel14.initialize();
	dmaChannel14.enableInterrupt();
	dmaChannel15.initialize();
	dmaChannel15.enableInterrupt();
	dmaChannel16.initialize();
	dmaChannel16.enableInterrupt();
#endif
}

#endif