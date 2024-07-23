/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F7)

#include <config.h>
#include <yss/instance.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

void __WEAK initializeSystem(void)
{
	// 외부 클럭 활성화
#if defined(HSE_CLOCK_FREQ)
	clock.enableHse(HSE_CLOCK_FREQ);
#endif

	// Power Controller 활성화
	clock.enableApb1Clock(RCC_APB1ENR_PWREN_Pos);

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

	// Main PLL 설정
	clock.enableMainPll(
#if defined(HSE_CLOCK_FREQ)
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
#else
		pll::src::HSI,				// uint8_t src
		16000000 / 1000000,			// uint8_t m
#endif
		432,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv
		pll::qdiv::DIV9,			// uint8_t qDiv
		pll::rdiv::DIV7				// uint8_t rDiv
	);
	
	// SAI PLL 설정
	clock.enableSaiPll(
		192,                 // uint32_t n
		saipll::pdiv::DIV4,  // uint8_t pDiv
		saipll::qdiv::DIV15, // uint8_t qDiv
		saipll::rdiv::DIV7   // uint8_t rDiv
	);

	// 시스템 클럭 설정
	flash.setLatency(216000000, 33);
	clock.setSysclk(
		define::clock::sysclk::src::PLL,		// uint8_t sysclkSrc;
		define::clock::sysclk::ahbDiv::NO_DIV,	// uint8_t ahb;
		define::clock::sysclk::apbDiv::DIV4,	// uint8_t apb1;
		define::clock::sysclk::apbDiv::DIV2,	// uint8_t apb2;
		33										// uint8_t vcc
	);

	// 명령어 캐쉬 활성화
	SCB_EnableICache();
	
	// Flash Prefetch, ART Accelerator 활성화
	flash.enableArtAccelerator();
	flash.enablePrefetch();
	
	// SDRAM 주소 Remap
	clock.enableApb2Clock(RCC_APB2ENR_SYSCFGEN_Pos);
	setFieldData(SYSCFG->MEMRMP, SYSCFG_MEMRMP_SWP_FMC_Msk, 1, SYSCFG_MEMRMP_SWP_FMC_Pos);

	// GPIO 클럭 활성화
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOAEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOBEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOCEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIODEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOEEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOFEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOGEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOHEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOIEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOJEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOKEN_Pos);
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

extern "C"
{
	void __WEAK SystemCoreClockUpdate(void)
	{

	}
}

#endif
