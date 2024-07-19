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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <config.h>
#include <yss/instance.h>
#include <targets/nuvoton/bitfield_m48x.h>

#if defined(__M480_FAMILY)
#define FBDIV_VALUE		46
#elif defined(__M43x_FAMILY)
#define FBDIV_VALUE		34
#endif

void __WEAK initializeSystem(void)
{
	uint32_t srcClk, reg;

	// 외부 고속 클럭 활성화
#if defined(HSE_CLOCK_FREQ)
	clock.enableHxt(HSE_CLOCK_FREQ);
	srcClk = HSE_CLOCK_FREQ;
#else
	srcClk = clock.getHircFrequency();
#endif

	clock.enablePll(
#if defined(HSE_CLOCK_FREQ)
		Clock::PLL_SRC_HXT,
#else
		Clock::PLL_SRC_HIRC,
#endif
		srcClk / 4000000 - 1,
		FBDIV_VALUE,
		1);

	clock.setHclkClockSource(Clock::HCLK_SRC_PLL, 0, 1, 1); 
	
	// UART0, UART1의 클럭 소스를 PLL로 변경
	reg = CLK->CLKSEL1;
	reg &= ~(CLK_CLKSEL1_UART0SEL_Msk | CLK_CLKSEL1_UART1SEL_Msk);
	reg |= (1 << CLK_CLKSEL1_UART0SEL_Pos) | (1 << CLK_CLKSEL1_UART1SEL_Pos);
	CLK->CLKSEL1 = reg;

	// SPI0, SPI1, SPI2, SPI3의 클럭 소스를 PLL로 변경
	reg = CLK->CLKSEL2;
	reg &= ~(CLK_CLKSEL2_SPI0SEL_Msk | CLK_CLKSEL2_SPI1SEL_Msk | CLK_CLKSEL2_SPI2SEL_Msk | CLK_CLKSEL2_SPI3SEL_Msk);
	reg |= (1 << CLK_CLKSEL2_SPI0SEL_Pos) | (1 << CLK_CLKSEL2_SPI1SEL_Pos) | (1 << CLK_CLKSEL2_SPI2SEL_Pos) | (1 << CLK_CLKSEL2_SPI3SEL_Pos);
	CLK->CLKSEL2 = reg;
}

void initializeDma(void)
{
	// DMA1
	dmaChannel1.enableClock();
	dmaChannel1.initialize();
	dmaChannel1.enableInterrupt();
}

extern "C"
{
	void SystemCoreClockUpdate(void)
	{

	}
}

#endif
