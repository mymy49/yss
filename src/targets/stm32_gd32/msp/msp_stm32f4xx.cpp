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

#include <drv/mcu.h>

#if defined(STM32F4)

#include <config.h>

#include <yss/instance.h>
#include <targets/st_gigadevice/rcc_stm32_gd32f4_f7.h>

extern "C"
{
void __WEAK SystemCoreClockUpdate(void)
{

}
}

void __WEAK initSystem(void)
{
	// Power Controller 클럭 활성화
	clock.enableApb1Clock(RCC_APB1ENR_PWREN_Pos);

	// SYSCFG 클럭 활성화
	clock.enableApb2Clock(RCC_APB2ENR_SYSCFGEN_Pos);

	// 외부 고속 클럭 활성화
	clock.enableHse(HSE_CLOCK_FREQ);

	using namespace define::clock;
	
	// Main PLL 설정
	clock.enableMainPll(
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
#if defined(STM32F411xE)
		192,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv Sysclk
		pll::qdiv::DIV4,			// uint8_t qDiv
#elif defined(STM32F429xx)
		288,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv Sysclk
		pll::qdiv::DIV6,			// uint8_t qDiv
#endif
		0
	);
	
#if defined(STM32F429xx)
	clock.setLtdcDivisionFactor(divisionFactor::ltdc::DIV8);
#endif

	// SAI PLL 설정
#if defined(STM32F429xx)
	clock.enableSaiPll(
		192,				// uint16_t n
		0,					// uint8_t pDiv <- 사용되지 않음
		pll::qdiv::DIV15,	// uint8_t qDiv SAI Clock
		pll::rdiv::DIV7		// uint8_t rDiv TFT-LCD Clock
	);
#endif

#if defined(STM32F411xE)
	flash.setLatency(96000000, 33);
#elif defined(STM32F429xx)
	flash.setLatency(144000000, 33);
#endif
	clock.setSysclk(
		sysclk::src::PLL,				// uint8_t sysclkSrc;
		divisionFactor::ahb::NO_DIV,	// uint8_t ahb;
		divisionFactor::apb::DIV4,		// uint8_t apb1;
		divisionFactor::apb::DIV2,		// uint8_t apb2;
		33								// uint8_t vcc
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
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOIEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOJEN_Pos);
	clock.enableAhb1Clock(RCC_AHB1ENR_GPIOKEN_Pos);
}

void __WEAK initDma(void)
{
	// DMA1
	dmaChannel1.enableClock();
	dmaChannel1.init();
	dmaChannel1.enableInterrupt();
	dmaChannel2.init();
	dmaChannel2.enableInterrupt();
	dmaChannel3.init();
	dmaChannel3.enableInterrupt();
	dmaChannel4.init();
	dmaChannel4.enableInterrupt();
	dmaChannel5.init();
	dmaChannel5.enableInterrupt();
	dmaChannel6.init();
	dmaChannel6.enableInterrupt();
	dmaChannel7.init();
	dmaChannel7.enableInterrupt();
	dmaChannel8.init();
	dmaChannel8.enableInterrupt();

	// DMA2
	dmaChannel9.enableClock();
	dmaChannel9.init();
	dmaChannel9.enableInterrupt();
	dmaChannel10.init();
	dmaChannel10.enableInterrupt();
	dmaChannel11.init();
	dmaChannel11.enableInterrupt();
	dmaChannel12.init();
	dmaChannel12.enableInterrupt();
	dmaChannel13.init();
	dmaChannel13.enableInterrupt();
	dmaChannel14.init();
	dmaChannel14.enableInterrupt();
	dmaChannel15.init();
	dmaChannel15.enableInterrupt();
	dmaChannel16.init();
	dmaChannel16.enableInterrupt();
}

#endif