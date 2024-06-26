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

#if defined(STM32F1)

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
	// Power Control 장치 활성화
	clock.enableApb1Clock(RCC_APB1ENR_PWREN_Pos);

	// 외부 고속 클럭 활성화
#if defined(HSE_CLOCK_FREQ)
	clock.enableHse(HSE_CLOCK_FREQ);
#endif

	using namespace define::clock;
	
	// 주 PLL 활성화
	// pllClock = SRC_FREQ * (mul + 2) / (1 + xtpre);
	// mul은 0 ~ 14까지 설정 가능합니다.
	// xtpre는 0 ~ 1까지 설정 가능합니다.
#if HSE_CLOCK_FREQ == 8000000
	// 
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
		4				// uint8_t mul;
	); 
#define PLL_ENABLED
#elif !defined(HSE_CLOCK_FREQ)
	// 36 MHz로 설정
	clock.enableMainPll(
		pll::src::HSI_DIV2,	// uint8_t src;
		0,					// uint8_t xtpre;
		7					// uint8_t mul;
	); 
#define PLL_ENABLED
#endif

#if defined(PLL_ENABLED)
	flash.setLatency(36000000);

	// 시스템 클럭 설정
	clock.setSysclk(
		sysclk::src::PLL,		// uint8_t sysclkSrc;
		divFactor::ahb::NO_DIV, // uint8_t ahb;
		divFactor::apb::DIV2,	// uint8_t apb1;
		divFactor::apb::NO_DIV	// uint8_t apb2;
	);
#endif
	
	// 플래시 메모리 prefetch 기능 활성화
	flash.setPrefetchEn(true);
	flash.setHalfCycleAccessEn(true);
	
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
