////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(GD32F4)

#include <config.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/rcc_stm32_gd32f4_f7.h>

#include <yss/instance.h>

void __WEAK initializeSystem(void)
{
	// Power Control 장치 활성화
	clock.enableApb1Clock(RCC_APB1ENR_PWREN_Pos);

	// SYSCFG 클럭 활성화
	clock.enableApb2Clock(RCC_APB2ENR_SYSCFGEN_Pos);

	// 외부 고속 클럭 활성화
	clock.enableHse(HSE_CLOCK_FREQ);

	using namespace define::clock;

	// 주 PLL 활성화
	// m 값 설정으로 입력 주파수를 분주하고 PLL의 n 값과 곱해서 VCO 클럭이 주파수가 결정된다.
	// Core, AHB clock = n / pDiv [MHz]
	// USB clock = n / qDiv [MHz] # 필요한 경우 48[MHz]에 맞춰야 함
	clock.enableMainPll(
		pll::src::HSE,				// uint8_t src
		HSE_CLOCK_FREQ / 1000000,	// uint8_t m
		360,						// uint16_t n
		pll::pdiv::DIV2,			// uint8_t pDiv
		pll::qdiv::DIV8,			// uint8_t qDiv
		0							// uint8_t rDiv <- 사용되지 않음
	);

	// LCD 분주 설정 (lcdDiv)
	clock.setLtdcDivisionFactor(divisionFactor::ltdc::DIV2);
	
	// SAI PLL 할성화
	// GD32F4xx에는 SAI 장치가 실제로 없음
	// 48MHz USB Clock과 TFT-LCD Controller clock만 유효함
	// USB clock = n / pDiv [MHz]
	// TFT LCD clock = n / rDiv / lcdDiv [MHz]
	clock.enableSaiPll(
		192,				// uint16_t n
		pll::pdiv::DIV4,	// uint8_t pDiv
		0,					// uint8_t qDiv <- 사용되지 않음
		pll::rdiv::DIV7		// uint8_t rDiv
	);

	// I2S Clock Source 선택
	//RCU_CFG0 |= 0 << 23;	// 0 : PLLI2S, 1 : 외부 I2S_CKIN

	// I2S PLL 할성화
	// VCO 클럭은 100 ~ 500 [MHz]까지 설정 가능하다.
	// I2S PLL 클럭은 최대 240[MHz]까지 설정 가능하다.
	// I2S clock = n / rDiv [MHz]
	//clock.enableI2sPll(
	//	100,						// uint16_t n
	//	0,							// uint8_t pDiv
	//	0,							// uint8_t qDiv
	//	i2spll::rdiv::DIV7			// uint8_t rDiv
	//);

	// 시스템 클럭 설정
	clock.setSysclk(
		sysclk::src::PLL,				// uint8_t sysclkSrc;
		divisionFactor::ahb::NO_DIV,	// uint8_t ahb;
		divisionFactor::apb::DIV4,		// uint8_t apb1;
		divisionFactor::apb::DIV2		// uint8_t apb2;
	);

	// GPIO 활성화
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

void initDma(void)
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

extern "C"
{
void __WEAK SystemCoreClockUpdate(void)
{

}
}

#endif