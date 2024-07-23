/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4)

#include <config.h>
#include <yss/instance.h>
#include <targets/st/bitfield.h>

extern "C"
{
	void __WEAK SystemCoreClockUpdate(void)
	{

	}
}

void __WEAK initializeSystem(void)
{
	// Power Controller 클럭 활성화
	clock.enableApb1Clock(RCC_APB1ENR_PWREN_Pos);

	// SYSCFG 클럭 활성화
	clock.enableApb2Clock(RCC_APB2ENR_SYSCFGEN_Pos);

	// 외부 크리스탈 클럭 활성화
#if defined(HSE_CLOCK_FREQ)
	clock.enableHse(HSE_CLOCK_FREQ);
#endif

	using namespace define::clock;
	
#if defined(STM32F429xx)
	clock.setLtdcDivisionFactor(divisionFactor::ltdc::DIV8);

	clock.enableMainPll(
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
		288,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv Sysclk
		pll::qdiv::DIV6,			// uint8_t qDiv
		pll::rdiv::DIV7				// uint8_t rDiv	
	);

	clock.enableSaiPll(
		192,				// uint16_t n
		0,					// uint8_t pDiv <- 사용되지 않음
		pll::qdiv::DIV15,	// uint8_t qDiv SAI Clock
		pll::rdiv::DIV7		// uint8_t rDiv TFT-LCD Clock
	);

	flash.setLatency(144000000, 33);
#elif defined(STM32F407xx)
	clock.enableMainPll(
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
		288,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv Sysclk
		pll::qdiv::DIV6,			// uint8_t qDiv
		pll::rdiv::DIV7				// uint8_t rDiv	
	);

	flash.setLatency(144000000, 33);
#elif defined(STM32F446xx)
	clock.enableMainPll(
#if defined(HSE_CLOCK_FREQ)
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
#else
		pll::src::HSI,				// uint8_t src
		16000000 / 1000000,			// uint8_t m
#endif
		360,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv Sysclk
		pll::qdiv::DIV6,			// uint8_t qDiv
		pll::rdiv::DIV7				// uint8_t rDiv	
	);

	clock.enableSaiPll(
		192,				// uint16_t n
		pll::pdiv::DIV8,	// uint8_t pDiv SAI Clock
		pll::qdiv::DIV15,	// uint8_t qDiv SAI Clock
		pll::rdiv::DIV7		// uint8_t rDiv <- 사용되지 않음
	);

	clock.enableI2sPll(
#if defined(HSE_CLOCK_FREQ)
		192,						// uint16_t n
		HSE_CLOCK_FREQ / 1000000,	// uint16_t m
#else
		192,						// uint16_t n
		16000000 / 1000000,			// uint16_t m
#endif
		pll::pdiv::DIV8,			// uint8_t pDiv
		pll::qdiv::DIV15,			// uint8_t qDiv
		pll::rdiv::DIV7				// uint8_t rDiv	
	);

	flash.setLatency(180000000, 33);
#elif defined(STM32F411xE)
	clock.enableMainPll(
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
		192,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv Sysclk
		pll::qdiv::DIV4,			// uint8_t qDiv
		pll::rdiv::DIV7				// uint8_t rDiv	
	);

	flash.setLatency(96000000, 33);
#endif

	clock.setSysclk(
		sysclk::src::PLL,			// uint8_t sysclkSrc;
		sysclk::ahbDiv::NO_DIV,		// uint8_t ahb;
		sysclk::apbDiv::DIV4,		// uint8_t apb1;
		sysclk::apbDiv::DIV2,		// uint8_t apb2;
		33							// uint8_t vcc
	);
	
	// Flash Prefetch, D/I 캐시 활성화
	flash.enableDataCache();
	flash.enableInstructionCache();
	flash.enablePrefetch();
	
	// GPIO 클럭 활성화
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOAEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOBEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOCEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIODEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOEEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOFEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOGEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOHEN_Pos);
#if defined(RCC_AHB1ENR_GPIOIEN_Pos)
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOIEN_Pos);
#endif
#if defined(RCC_AHB1ENR_GPIOJEN_Pos)
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOJEN_Pos);
#endif
#if defined(RCC_AHB1ENR_GPIOKEN_Pos)
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOKEN_Pos);
#endif
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
	dmaChannel6.initialize();
	dmaChannel6.enableInterrupt();
	dmaChannel7.initialize();
	dmaChannel7.enableInterrupt();
	dmaChannel8.initialize();
	dmaChannel8.enableInterrupt();

	// DMA2
	dmaChannel9.enableClock();
	dmaChannel9.initialize();
	dmaChannel9.enableInterrupt();
	dmaChannel10.initialize();
	dmaChannel10.enableInterrupt();
	dmaChannel11.initialize();
	dmaChannel11.enableInterrupt();
	dmaChannel12.initialize();
	dmaChannel12.enableInterrupt();
	dmaChannel13.initialize();
	dmaChannel13.enableInterrupt();
	dmaChannel14.initialize();
	dmaChannel14.enableInterrupt();
	dmaChannel15.initialize();
	dmaChannel15.enableInterrupt();
	dmaChannel16.initialize();
	dmaChannel16.enableInterrupt();
}

#endif