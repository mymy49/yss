/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F0)

#include <config.h>
#include <yss/instance.h>
#include <targets/st/bitfield.h>

void __WEAK initializeSystem(void)
{
	// Power Control 장치 활성화
	clock.enableApb1Clock(RCC_APB1ENR_PWREN_Pos);

	// 외부 고속 클럭 활성화
#if defined(HSE_CLOCK_FREQ)
	clock.enableHse(HSE_CLOCK_FREQ);
#endif

	using namespace define::clock;

	// 주 PLL 활성화
	// pllClock = HSE_CLOCK_FREQ * (mul + 2) / (1 + xtpre);
#if HSE_CLOCK_FREQ == 8000000
	clock.enableMainPll(
		pll::src::HSE,	// uint8_t src;
		0,				// uint8_t xtpre;
		7				// uint8_t mul;
	);
#define PLL_ENABLED
# elif HSE_CLOCK_FREQ == 12000000
	clock.enableMainPll(
		pll::src::HSE,	// uint8_t src;
		0,				// uint8_t xtpre;
		2				// uint8_t mul;
	); 
#define PLL_ENABLED
#endif

#if defined(PLL_ENABLED)
	flash.setLatency(48000000);

	// 시스템 클럭 설정
	clock.setSysclk(
		sysclk::src::PLL,		// uint8_t sysclkSrc;
		divFactor::ahb::NO_DIV, // uint8_t ahb;
		divFactor::apb::NO_DIV,	// uint8_t apb1;
		divFactor::apb::NO_DIV	// <- 사용 안됨
	);
#endif

	flash.setPrefetchEn(true);

	// GPIO 활성화
	clock.enableAhb1Clock(RCC_AHBENR_GPIOAEN_Pos);
	clock.enableAhb1Clock(RCC_AHBENR_GPIOBEN_Pos);
	clock.enableAhb1Clock(RCC_AHBENR_GPIOCEN_Pos);
	clock.enableAhb1Clock(RCC_AHBENR_GPIODEN_Pos);
	clock.enableAhb1Clock(RCC_AHBENR_GPIOFEN_Pos);
}

void initializeDma(void)
{
	// DMA1
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
}


#endif