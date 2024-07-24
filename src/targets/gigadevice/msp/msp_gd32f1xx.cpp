/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(GD32F1)

#include <config.h>
#include <yss/instance.h>
#include <targets/st/bitfield_stm32f103xx.h>

extern "C"
{
void __WEAK SystemCoreClockUpdate(void)
{

}
}

void __WEAK initializeSystem(void)
{
	// Power Control 장치 활성화
	clock.enableApb1Clock(RCC_APB1ENR_PWREN_Pos);

	// 외부 고속 클럭 활성화
	clock.enableHse(HSE_CLOCK_FREQ);

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
		7				// uint8_t mul;
	); 
#define PLL_ENABLED
#endif

#if defined(PLL_ENABLED)
	// 시스템 클럭 설정
	clock.setSysclk(
		sysclk::src::PLL,		// uint8_t sysclkSrc;
		divFactor::ahb::NO_DIV, // uint8_t ahb;
		divFactor::apb::DIV2,	// uint8_t apb1;
		divFactor::apb::NO_DIV	// uint8_t apb2;
	);
#endif
	
	// GPIO 활성화
	clock.enableApb2Clock(RCC_APB2ENR_AFIOEN_Pos);
	clock.enableApb2Clock(RCC_APB2ENR_IOPAEN_Pos);
	clock.enableApb2Clock(RCC_APB2ENR_IOPBEN_Pos);
	clock.enableApb2Clock(RCC_APB2ENR_IOPCEN_Pos);
	clock.enableApb2Clock(RCC_APB2ENR_IOPDEN_Pos);
	clock.enableApb2Clock(RCC_APB2ENR_IOPEEN_Pos);
#if defined(RCC_APB2ENR_IOPFEN_Pos)
	clock.enableApb2Clock(RCC_APB2ENR_IOPFEN_Pos);
#endif
#if defined(RCC_APB2ENR_IOPGEN_Pos)
	clock.enableApb2Clock(RCC_APB2ENR_IOPGEN_Pos);
#endif
	
	// SWD 단자 외의 JTAG단자는 일반 포트로 전환
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_NOJNTRST;
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

#if defined(DMA2)
	// DMA2
#if defined(DMA2_Channel1)
	dmaChannel8.enableClock();
	dmaChannel8.initialize();
	dmaChannel8.enableInterrupt();
#endif
#if defined(DMA2_Channel2)
	dmaChannel9.initialize();
	dmaChannel9.enableInterrupt();
#endif
#if defined(DMA2_Channel3)
	dmaChannel10.initialize();
	dmaChannel10.enableInterrupt();
#endif
#if defined(DMA2_Channel4)
	dmaChannel11.initialize();
	dmaChannel11.enableInterrupt();
#endif
#if defined(DMA2_Channel4)
	dmaChannel12.initialize();
	dmaChannel12.enableInterrupt();
#endif
#endif
}

#endif
