////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F7_N)

#include <config.h>
#include <yss/instance.h>
#include <yss/reg.h>

#if defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#endif

void __WEAK initializeSystem(void)
{
	// 외부 클럭 활성화
	clock.enableHse(HSE_CLOCK_FREQ);

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
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
		360,						// uint16_t n
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

	//// I2S PLL 설정
	//clock.enableI2sPll(
	//	192,                 // uint32_t n
	//	i2spll::pdiv::DIV4,  // uint8_t pDiv
	//	i2spll::qdiv::DIV15, // uint8_t qDiv
	//	i2spll::rdiv::DIV7   // uint8_t rDiv
	//);
	
	// 시스템 클럭 설정
	flash.setLatency(180000000, 33);
	clock.setSysclk(
		define::clock::sysclk::src::PLL,       // uint8_t sysclkSrc;
		define::clock::divisionFactor::ahb::NO_DIV, // uint8_t ahb;
		define::clock::divisionFactor::apb::DIV4,   // uint8_t apb1;
		define::clock::divisionFactor::apb::DIV2,   // uint8_t apb2;
		33                                     // uint8_t vcc
	);

//	flash.setBank(define::flash::bank::DUAL_BANK);
	
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
