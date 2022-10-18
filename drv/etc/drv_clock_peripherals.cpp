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
/*
#include <yss/instance.h>

#ifndef YSS_DRV_CLOCK_UNSUPPORTED

#include <yss/reg.h>

#if defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
#include "flc_regs.h"
#include "gcr_regs.h"
#include "pwrseq_regs.h"
#endif

extern uint8_t gHseFreq __attribute__((section(".non_init")));
extern uint32_t gPllQFreq __attribute__((section(".non_init")));

#if defined(DMA1)
void PeripheralClock::setDmaEn(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA1EN_Msk;
#if defined(DMA2)
	if (en)
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN_Msk;
	else
		RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN_Msk;
#endif
#elif defined(STM32F1)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_DMA1EN;
	else
		RCC->AHBENR &= ~RCC_AHBENR_DMA1EN;
#if defined(DMA2) && defined(RCC_AHBENR_DMA2EN)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_DMA2EN;
	else
		RCC->AHBENR &= ~RCC_AHBENR_DMA2EN;
#endif
#elif defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->AHBENR |= RCC_AHBENR_DMAEN_Msk;
	else
		RCC->AHBENR &= ~RCC_AHBENR_DMAEN_Msk;
#elif defined(GD32F1)
	setBitData(RCC->AHBCCR, en, 0);
	setBitData(RCC->AHBCCR, en, 1);
#elif defined(GD32F4)
#endif
}

void PeripheralClock::resetDma(void)
{
#if defined(STM32F7) || defined(STM32F4)
#if defined(DMA2)
	RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2RST_Msk;
	RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA2RST_Msk;
#endif
#elif defined(STM32F1)
	// 기능 없음
#endif
}
#endif

#if defined(DMA2D) || defined(IPA)
void PeripheralClock::setDma2d(bool en)
{
#if defined(STM32F7) || defined(STM32F4)
#elif defined(GD32F4)
#endif
}

void PeripheralClock::resetDma2d(void)
{
#if defined(STM32F7) || defined(STM32F4)
#elif defined(GD32F4)
	RCU_AHB1RST |= RCU_AHB1RST_IPARST;
	RCU_AHB1RST &= ~RCU_AHB1RST_IPARST;
#endif
}
#endif

#if defined(FMC_Bank1) || defined(EXMC)
void PeripheralClock::setFmcEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	if (en)
		RCC->AHB3ENR |= RCC_AHB3ENR_FMCEN_Msk;
	else
		RCC->AHB3ENR &= ~RCC_AHB3ENR_FMCEN_Msk;
#elif defined(GD32F4)
#endif
}

void PeripheralClock::resetFmc(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	RCC->AHB3RSTR |= RCC_AHB3RSTR_FMCRST_Msk;
	RCC->AHB3RSTR &= ~RCC_AHB3RSTR_FMCRST_Msk;
#elif defined(GD32F4)
		RCU_AHB3RST |= RCU_AHB3RST_EXMCRST;
		RCU_AHB3RST &= ~RCU_AHB3RST_EXMCRST;
#endif
}
#endif

#if defined(TC0) || defined(MXC_TMR0)
void PeripheralClock::setTimer0En(bool en)
{
#if defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC0_GCLK_ID].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_T0D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_T0D;
#endif
}
#endif

#if defined(SAI1)
void PeripheralClock::setSai1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setBitData(RCC->APB2ENR, en, RCC_APB2ENR_SAI1EN_Pos);
#endif
}

void PeripheralClock::resetSai1(void)
{
#if defined(STM32F4) || defined(STM32F7)
	setBitData(RCC->APB2RSTR, true, RCC_APB2RSTR_SAI1RST_Pos);
#endif
}
#endif

#if defined(SAI2)
void PeripheralClock::setSai2En(bool en)
{
#if defined(STM32F7)
	setBitData(RCC->APB2ENR, en, RCC_APB2ENR_SAI2EN_Pos);
#endif
}

void PeripheralClock::resetSai2(void)
{
}
#endif


#if defined(TIM1) || defined(TC1) || defined(MXC_TMR1) || defined(TIMER1)
void PeripheralClock::setTimer1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC1_GCLK_ID].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_T1D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_T1D;
#elif defined(GD32F1)
	setBitData(RCC->APB2CCR, en, 11);
#elif defined(GD32F4)
	setBitData(RCU_APB1EN, en, 0);
#endif
}

void PeripheralClock::resetTimer1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
	setBitData(RCC->APB2RCR, true, 11);
	setBitData(RCC->APB2RCR, false, 11);
#endif
}
#endif

#if defined(TIM2) || defined(TC2) || defined(MXC_TMR2) || defined(TIMER2)
void PeripheralClock::setTimer2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM2EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC2_GCLK_ID].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_T2D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_T2D;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 0);
#endif
}

void PeripheralClock::resetTimer2(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM2RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM2RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 0);
	setBitData(RCC->APB1RCR, false, 0);
#endif
}
#endif

#if defined(TIM3) || defined(TC3) || defined(TIMER3)
void PeripheralClock::setTimer3En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM3EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC3_GCLK_ID].bit.CHEN = en;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 1);
#endif
}

void PeripheralClock::resetTimer3(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM3RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM3RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 1);
	setBitData(RCC->APB1RCR, false, 1);
#endif
}
#endif

#if defined(TIM4) || defined(TC4) || defined(TIMER4)
void PeripheralClock::setTimer4En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM4EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[TC4_GCLK_ID].bit.CHEN = en;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 2);
#endif
}

void PeripheralClock::resetTimer4(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM4RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM4RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 2);
	setBitData(RCC->APB1RCR, false, 2);

#endif
}
#endif

#if defined(TIM5) || defined(TIMER5)
void PeripheralClock::setTimer5En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)) && defined(RCC_APB1ENR_TIM5EN)
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM5EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM5EN_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 3);
#endif
}

void PeripheralClock::resetTimer5(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)) && defined(RCC_APB1RSTR_TIM5RST)
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM5RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM5RST_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 3);
	setBitData(RCC->APB1RCR, false, 3);
#endif
}
#endif

#if defined(TIM6) || defined(TIMER6)
void PeripheralClock::setTimer6En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)) && defined(RCC_APB1ENR_TIM6EN)
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM6EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM6EN_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 4);
#endif
}

void PeripheralClock::resetTimer6(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)) && defined(RCC_APB1RSTR_TIM6RST)
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM6RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM6RST_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 4);
	setBitData(RCC->APB1RCR, false, 4);
#endif
}
#endif

#if defined(TIM7) || defined(TIMER7)
void PeripheralClock::setTimer7En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)) && defined(RCC_APB1ENR_TIM7EN)
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_TIM7EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM7EN_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 5);
#endif
}

void PeripheralClock::resetTimer7(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)) && defined(RCC_APB1RSTR_TIM7RST)
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM7RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM7RST_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 5);
	setBitData(RCC->APB1RCR, false, 5);
#endif
}
#endif

#if defined(TIM8) || defined(TIMER8)
void PeripheralClock::setTimer8En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2ENR_TIM8EN)
#elif defined(GD32F1)
	setBitData(RCC->APB2CCR, en, 13);
#endif
}

void PeripheralClock::resetTimer8(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2RSTR_TIM8RST)
#elif defined(GD32F1)
	setBitData(RCC->APB2RCR, true, 13);
	setBitData(RCC->APB2RCR, false, 13);
#endif
}
#endif

#if defined(TIM9) || defined(TIMER9)
void PeripheralClock::setTimer9En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2ENR_TIM9EN)
#endif
}

void PeripheralClock::resetTimer9(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2RSTR_TIM9RST)
#endif
}
#endif

#if defined(TIM10) || defined(TIMER10)
void PeripheralClock::setTimer10En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2ENR_TIM10EN)
#endif
}

void PeripheralClock::resetTimer10(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2RSTR_TIM10RST)
#endif
}
#endif

#if defined(TIM11) || defined(TIMER11)
void PeripheralClock::setTimer11En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2ENR_TIM11EN)
#endif
}

void PeripheralClock::resetTimer11(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2RSTR_TIM11RST)
#endif
}
#endif

#if defined(TIM12) || defined(TIMER12)
void PeripheralClock::setTimer12En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB1ENR_TIM12EN)
#endif
}

void PeripheralClock::resetTimer12(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB1RSTR_TIM12RST)
#endif
}
#endif

#if defined(TIM13) || defined(TIMER13)
void PeripheralClock::setTimer13En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB1ENR_TIM13EN)
#endif
}

void PeripheralClock::resetTimer13(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB1RSTR_TIM13RST)
#endif
}
#endif

#if defined(TIM14) || defined(TIMER14)
void PeripheralClock::setTimer14En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB1ENR_TIM14EN)
#endif
}

void PeripheralClock::resetTimer14(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB1RSTR_TIM14RST)
#endif
}
#endif

#if defined(TIM15) || defined(TIMER15)
void PeripheralClock::setTimer15En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2ENR_TIM15EN)
#endif
}

void PeripheralClock::resetTimer15(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2RSTR_TIM15RST)
#endif
}
#endif

#if defined(TIM16) || defined(TIMER16)
void PeripheralClock::setTimer16En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2ENR_TIM16EN)
#endif
}

void PeripheralClock::resetTimer16(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2ENR_TIM16EN)
#endif
}
#endif

#if defined(TIM17) || defined(TIMER17)
void PeripheralClock::setTimer17En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2ENR_TIM17EN)
#endif
}

void PeripheralClock::resetTimer17(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32F0)) && defined(RCC_APB2RSTR_TIM17RST)
#endif
}
#endif

#if defined(WWDG)
void PeripheralClock::setWindowWatchdogEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_WWDGEN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_WWDGEN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_WWDGEN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_WWDGEN_Msk;
#endif
}

void PeripheralClock::resetWindowWatchdog(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	RCC->APB1RSTR |= RCC_APB1RSTR_WWDGRST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_WWDGRST;
#elif defined(STM32G4)
	// 기능 없음
#endif
}
#endif

#if defined(SERCOM0)
void PeripheralClock::setSpi0En(bool en)
{
#if defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM0_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void PeripheralClock::resetSpi0(void)
{
#if defined(__SAM_L_FAMILY)

#endif
}
#endif

#if defined(SPI0) || defined(SERCOM0)
void PeripheralClock::setSpi0En(bool en)
{
#if defined(GD32F4)
	if(en)
		RCU_APB2EN |= RCU_APB2EN_SPI0EN;
	else
		RCU_APB2EN &= ~RCU_APB2EN_SPI0EN;
#endif
}

void PeripheralClock::resetSpi0(void)
{
#if defined(GD32F4)
	RCU_APB2RST |= RCU_APB2RST_SPI0RST;
	RCU_APB2RST &= ~RCU_APB2RST_SPI0RST;
#endif
}
#endif

#if defined(SPI1) || defined(SERCOM1)
void PeripheralClock::setSpi1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM1_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F1)
	setBitData(RCC->APB2CCR, en, 12);
#endif
}

void PeripheralClock::resetSpi1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0)
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI1RST;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
	setBitData(RCC->APB2RCR, true, 12);
	setBitData(RCC->APB2RCR, false, 12);
#endif
}
#endif

#if defined(SPI2) || defined(SERCOM2)
void PeripheralClock::setSpi2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_SPI2EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_SPI2EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM2_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 14);
#endif
}

void PeripheralClock::resetSpi2(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	RCC->APB1RSTR |= RCC_APB1RSTR_SPI2RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI2RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_SPI2RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_SPI2RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 14);
	setBitData(RCC->APB1RCR, false, 14);
#endif
}
#endif

#if defined(SPI3) || defined(SERCOM3)
void PeripheralClock::setSpi3En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)) && defined(RCC_APB1ENR_SPI3EN)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_SPI3EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_SPI3EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 15);
#endif
}

void PeripheralClock::resetSpi3(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)) && defined(RCC_APB1RSTR_SPI3RST)
	RCC->APB1RSTR |= RCC_APB1RSTR_SPI3RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI3RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_SPI3RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_SPI3RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 15);
	setBitData(RCC->APB1RCR, false, 15);
#endif
}
#endif

#if defined(SPI4) || defined(SERCOM4)
void PeripheralClock::setSpi4En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SPI4EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI4EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM4_GCLK_ID_CORE].bit.CHEN = en;
#endif
}

void PeripheralClock::resetSpi4(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI4RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI4RST_Msk;
#elif defined(__SAM_L_FAMILY)

#endif
}
#endif

#if defined(SPI5) || defined(SERCOM5)
void PeripheralClock::setSpi5En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SPI5EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI5EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM5_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F4)
	if (en)
		RCU_APB2EN |= RCU_APB2EN_SPI5EN;
	else
		RCU_APB2EN &= ~RCU_APB2EN_SPI5EN;
#endif
}

void PeripheralClock::resetSpi5(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI5RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI5RST_Msk;
#elif defined(__SAM_L_FAMILY)

#endif
}
#endif

#if defined(SPI6)
void PeripheralClock::setSpi6En(bool en)
{
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SPI6EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI6EN_Msk;
}

void PeripheralClock::resetSpi6(void)
{
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI6RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI6RST_Msk;
}
#endif

#if defined(USART0) || defined(SERCOM0) || defined(MXC_UART0)
void PeripheralClock::setUart0En(bool en)
{
#if defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM0_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_UART0D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_UART0D;
#elif defined(GD32F4)
#endif
}

void PeripheralClock::resetUart0(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)

#elif defined(__SAM_L_FAMILY)

#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)

#elif defined(GD32F4)
	setBitData(RCU_APB2RST, true, 4);
	setBitData(RCU_APB2RST, false, 4);
#endif
}
#endif

#if defined(USART1) || defined(SERCOM1) || defined(MXC_UART1)
void PeripheralClock::setUart1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM1_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(YSS_DRV_CLOCK_MAXIM_TYPE_A__H_)
	if (en)
		MXC_GCR->perckcn0 &= ~MXC_F_GCR_PERCKCN0_UART1D;
	else
		MXC_GCR->perckcn0 |= MXC_F_GCR_PERCKCN0_UART1D;
#elif defined(GD32F1)
#endif
}

void PeripheralClock::resetUart1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
#endif
}
#endif

#if defined(USART2) || defined(SERCOM2)
void PeripheralClock::setUart2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_USART2EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM2_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F1)
#endif
}

void PeripheralClock::resetUart2(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_USART2RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_USART2RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)

#endif
}
#endif

#if defined(USART3) || defined(SERCOM3)
void PeripheralClock::setUart3En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_USART3EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_USART3EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_USART3EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F1)
#endif
}

void PeripheralClock::resetUart3(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_USART3RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_USART3RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)

#endif
}
#endif

#if defined(UART4) || defined(SERCOM4)
void PeripheralClock::setUart4En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4)) && defined(RCC_APB1ENR_UART4EN)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_UART4EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_UART4EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_UART4EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM4_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F1)
#endif
}

void PeripheralClock::resetUart4(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4)) && defined(RCC_APB1RSTR_UART4RST)
	RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_UART4RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_UART4RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_UART4RST_Msk;
#elif defined(GD32F1)
#endif
}
#endif

#if defined(UART5) || defined(SERCOM5)
void PeripheralClock::setUart5En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4)) && defined(RCC_APB1ENR_UART5EN)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_UART5EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_UART5EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_UART5EN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[SERCOM5_GCLK_ID_CORE].bit.CHEN = en;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 20);
#endif
}

void PeripheralClock::resetUart5(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4)) && defined(RCC_APB1RSTR_UART5RST)
	RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_UART5RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_UART5RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_UART5RST_Msk;
#elif defined(__SAM_L_FAMILY)
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 20);
	setBitData(RCC->APB1RCR, false, 20);

#endif

}
#endif

#if defined(USART6)
void PeripheralClock::setUart6En(bool en)
{
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_USART6EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_USART6EN_Msk;
}

void PeripheralClock::resetUart6(void)
{
	RCC->APB2RSTR |= RCC_APB2RSTR_USART6RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_USART6RST_Msk;
}
#endif

#if defined(UART7)
void PeripheralClock::setUart7En(bool en)
{
#if defined(GD32F4)

#else
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_UART7EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_UART7EN_Msk;
#endif
}

void PeripheralClock::resetUart7(void)
{
#if defined(GD32F4)

#else
	RCC->APB1RSTR |= RCC_APB1RSTR_UART7RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_UART7RST_Msk;
#endif
}
#endif

#if defined(UART8)
void PeripheralClock::setUart8En(bool en)
{
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_UART8EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_UART8EN_Msk;
}

void PeripheralClock::resetUart8(void)
{
	RCC->APB1RSTR |= RCC_APB1RSTR_UART8RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_UART8RST_Msk;
}
#endif

#if defined(I2C1)
void PeripheralClock::setI2c1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_I2C1EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C1EN_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 21);
#endif
}

void PeripheralClock::resetI2c1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C1RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C1RST_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 21);
	setBitData(RCC->APB1RCR, false, 21);
#endif
}

#if defined(STM32G4)
bool PeripheralClock::setI2c1ClkSrc(uint8_t src)
{
	switch (src)
	{
	case define::clock::i2c::src::PCLK1:
	case define::clock::i2c::src::SYSCLK:
	case define::clock::i2c::src::HSI16:
		RCC->CCIPR &= ~RCC_CCIPR_I2C1SEL_Msk;
		RCC->CCIPR |= src <<= RCC_CCIPR_I2C1SEL_Pos;
		return true;
	default:
		return false;
	}
}
#endif
#endif

#if defined(I2C2)
void PeripheralClock::setI2c2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_I2C2EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C2EN_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 22);
#endif
}

void PeripheralClock::resetI2c2(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C2RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C2RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C2RST_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 22);
	setBitData(RCC->APB1RCR, false, 22);
#endif
}

#if defined(STM32G4)
bool PeripheralClock::setI2c2ClkSrc(uint8_t src)
{
	switch (src)
	{
	case define::clock::i2c::src::PCLK1:
	case define::clock::i2c::src::SYSCLK:
	case define::clock::i2c::src::HSI16:
		RCC->CCIPR &= ~RCC_CCIPR_I2C2SEL_Msk;
		RCC->CCIPR |= src <<= RCC_CCIPR_I2C2SEL_Pos;
		return true;
	default:
		return false;
	}
}
#endif
#endif

#if defined(I2C3)
void PeripheralClock::setI2c3En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C3EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C3EN_Msk;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_I2C3EN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_I2C3EN_Msk;
#endif
}

void PeripheralClock::resetI2c3(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C3RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C3RST_Msk;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C3RST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C3RST_Msk;
#endif
}

#if defined(STM32G4)
bool PeripheralClock::setI2c3ClkSrc(uint8_t src)
{
	switch (src)
	{
	case define::clock::i2c::src::PCLK1:
	case define::clock::i2c::src::SYSCLK:
	case define::clock::i2c::src::HSI16:
		RCC->CCIPR &= ~RCC_CCIPR_I2C3SEL_Msk;
		RCC->CCIPR |= src <<= RCC_CCIPR_I2C3SEL_Pos;
		return true;
	default:
		return false;
	}
}
#endif
#endif

#if defined(I2C4)
void PeripheralClock::setI2c4En(bool en)
{
#if defined(STM32G4)
	if (en)
		RCC->APB1ENR2 |= RCC_APB1ENR2_I2C4EN_Msk;
	else
		RCC->APB1ENR2 &= ~RCC_APB1ENR2_I2C4EN_Msk;
#else
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C4EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C4EN_Msk;
#endif
}

void PeripheralClock::resetI2c4(void)
{
#if defined(STM32G4)
	RCC->APB1RSTR2 |= RCC_APB1RSTR2_I2C4RST_Msk;
	RCC->APB1RSTR2 &= ~RCC_APB1RSTR2_I2C4RST_Msk;
#else
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C4RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C4RST_Msk;
#endif
}
#endif

#if defined(CAN1) || defined(FDCAN1)
void PeripheralClock::setCan1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_CAN1EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_CAN1EN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_FDCANEN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_FDCANEN_Msk;
#elif defined(GD32F1)
#endif
}

void PeripheralClock::resetCan1(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	RCC->APB1RSTR |= RCC_APB1RSTR_CAN1RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_FDCANRST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_FDCANRST_Msk;
#elif defined(GD32F1)
#endif
}

#if defined(STM32G4)
uint32_t PeripheralClock::getCan1ClkFreq(void)
{
	uint32_t src = (RCC->CCIPR & RCC_CCIPR_FDCANSEL_Msk) >> RCC_CCIPR_FDCANSEL_Pos;

	switch (src)
	{
	case 0: // HSE
		return (uint32_t)gHseFreq * 1000000;
	case 1: // PLLQ
		return gPllQFreq;
	case 2: // PCLK1
		return clock.getApb1ClkFreq();
	default:
		return 0;
	}
}

bool PeripheralClock::setCan1ClkSrc(uint8_t src)
{
	if (src > 2)
		return false;
	uint32_t ccipr = RCC->CCIPR;

	ccipr &= ~RCC_CCIPR_FDCANSEL_Msk;
	ccipr |= src << RCC_CCIPR_FDCANSEL_Pos;
	RCC->CCIPR = ccipr;

	return true;
}
#endif
#endif

#if defined(CAN2)
void PeripheralClock::setCan2En(bool en)
{
#if (defined(STM32F1) || defined(STM32F4) || defined(STM32F7)) && defined(RCC_APB1ENR_CAN2EN)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_CAN2EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_CAN2EN;
#elif defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 26);
#endif
}

void PeripheralClock::resetCan2(void)
{
#if (defined(STM32F1) || defined(STM32F4) || defined(STM32F7)) && defined(RCC_APB1RSTR_CAN2RST)
	RCC->APB1RSTR |= RCC_APB1RSTR_CAN2RST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST;
#elif defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 26);
	setBitData(RCC->APB1RCR, false, 26);
#endif
}
#endif

#if defined(PWR) || defined(PMU)
void PeripheralClock::setPwrEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;
#elif defined(STM32G4)
	if (en)
		RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN_Msk;
	else
		RCC->APB1ENR1 &= ~RCC_APB1ENR1_PWREN_Msk;
#elif defined(GD32F1)
	if (en)
		RCC->APB1CCR |= RCC_APB1CCR_PWREN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_PWREN;
#elif defined(GD32F4)
#endif
}

void PeripheralClock::resetPwr(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)
	RCC->APB1RSTR |= RCC_APB1RSTR_PWRRST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_PWRRST;
#elif defined(STM32G4)
	RCC->APB1RSTR1 |= RCC_APB1RSTR1_PWRRST_Msk;
	RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_PWRRST_Msk;
#endif
}
#endif

#if defined(DAC1) || defined(DAC)
void PeripheralClock::setDac1En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)) && defined(RCC_APB1ENR_DACEN)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_DACEN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_DACEN;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_DAC1EN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_DAC1EN_Msk;
#elif defined(GD32F1)
#endif
}

void PeripheralClock::resetDac1(void)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32L0)) && defined(RCC_APB1RSTR_DACRST)
	RCC->APB1RSTR |= RCC_APB1RSTR_DACRST;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_DACRST;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_DAC1RST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_DAC1RST_Msk;
#elif defined(GD32F1)
#endif
}
#endif

#if defined(ADC1) || defined(ADC)
void PeripheralClock::setAdc1En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_ADC12EN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC12EN_Msk;
#elif defined(STM32L0) || defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_ADCEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_ADCEN_Msk;
#elif defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[ADC_GCLK_ID].bit.CHEN = en;
#elif defined(GD32F1)
	setBitData(RCC->APB2CCR, en, 9);
#endif
}

void PeripheralClock::resetAdc1(void)
{
#if defined(STM32F7)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADC1RST;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC1RST;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_ADC12RST_Pos;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_ADC12RST_Pos;
#elif defined(STM32L0)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Pos;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Pos;
#elif defined(__SAM_L_FAMILY)

#elif defined(GD32F1)
	setBitData(RCC->APB2RCR, true, 9);
	setBitData(RCC->APB2RCR, false, 9);
#endif
}

#if defined(STM32G4)
void PeripheralClock::setAdc12ClkSrc(uint8_t src)
{
	uint32_t ccipr;
	switch (src)
	{
	case define::clock::adc::src::NO_CLK:
	case define::clock::adc::src::PLL:
	case define::clock::adc::src::SYSCLK:
		ccipr = RCC->CCIPR & ~RCC_CCIPR_ADC12SEL_Msk;
		ccipr |= src << RCC_CCIPR_ADC12SEL_Pos;
		RCC->CCIPR = ccipr;
		break;
	}
}
#endif
#endif

#if defined(ADC2)
void PeripheralClock::setAdc2En(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_ADC2EN;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_ADC12EN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC12EN_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB2CCR, en, 10);
#endif
}

void PeripheralClock::resetAdc2(void)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Msk;
#elif defined(STM32F1)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADC2RST;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC2RST;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_ADC12RST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_ADC12RST_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB2RCR, true, 10);
	setBitData(RCC->APB2RCR, false, 10);
#endif
}
#endif

#if defined(ADC3)
void PeripheralClock::setAdc3En(bool en)
{
#if (defined(STM32F7) || defined(STM32F1) || defined(STM32F4)) && defined(RCC_APB2ENR_ADC3EN)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_ADC3EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_ADC3EN;
#elif defined(STM32G4)
	if (en)
		RCC->AHB2ENR |= RCC_AHB2ENR_ADC345EN_Msk;
	else
		RCC->AHB2ENR &= ~RCC_AHB2ENR_ADC345EN_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB2CCR, en, 15);
#endif
}

void PeripheralClock::resetAdc3(void)
{
#if defined(STM32F1) && defined(RCC_APB2RSTR_ADC3RST)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADC3RST;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC3RST;
#elif defined(STM32F7) || defined(STM32F4)
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Msk;
#elif defined(STM32G4)
	RCC->AHB2RSTR |= RCC_AHB2RSTR_ADC345RST_Msk;
	RCC->AHB2RSTR &= ~RCC_AHB2RSTR_ADC345RST_Msk;
#elif defined(GD32F1)
	setBitData(RCC->APB2RCR, true, 15);
	setBitData(RCC->APB2RCR, false, 15);
#endif
}
#endif

#if defined(SDMMC1) || defined(SDIO)
void PeripheralClock::setSdmmcEn(bool en)
{
#if defined(STM32F7)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SDMMC1EN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SDMMC1EN_Msk;
#elif defined(STM32F4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SDIOEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SDIOEN_Msk;
#elif defined(GD32F1)
	if (en)
		RCC->AHBCCR |= RCC_AHBCCR_SDIOEN;
	else
		RCC->AHBCCR &= ~RCC_AHBCCR_SDIOEN;
#endif
}

void PeripheralClock::resetSdmmc(void)
{
#if defined(STM32F4)
	RCC->APB2RSTR |= RCC_APB2RSTR_SDIORST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SDIORST_Msk;
#elif defined(STM32F7)
	RCC->APB2RSTR |= RCC_APB2RSTR_SDMMC1RST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SDMMC1RST_Msk;
#elif defined(GD32F1)
#endif
}
#endif

#if defined(SYSCFG)
void PeripheralClock::setSyscfgEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN_Msk;
#elif defined(STM32F0)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_SYSCFGCOMPEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGCOMPEN_Msk;
#endif
}

void PeripheralClock::resetSyscfg(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4) || defined(STM32L0)
	RCC->APB2RSTR |= RCC_APB2RSTR_SYSCFGRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SYSCFGRST_Msk;
#endif
}
#endif


#if defined(LTDC) || defined(TLI)
void PeripheralClock::setLtdcEn(bool en)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	if (en)
		RCC->APB2ENR |= RCC_APB2ENR_LTDCEN_Msk;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_LTDCEN_Msk;
#elif defined(GD32F4)
#endif
}

void PeripheralClock::resetLtdc(void)
{
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32G4)
	RCC->APB2RSTR |= RCC_APB2RSTR_LTDCRST_Msk;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_LTDCRST_Msk;
#elif defined(GD32F4)
	RCU_APB2RST |= RCU_APB2RST_TLIRST;
	RCU_APB2RST &= ~RCU_APB2RST_TLIRST;
#endif
}
#endif

#if defined(RTC)

void PeripheralClock::setRtcEn(bool en)
{
#if defined(STM32F1)
	PWR->CR |= PWR_CR_DBP;
	RCC->BDCR |= RCC_BDCR_BDRST;
	RCC->BDCR &= ~RCC_BDCR_BDRST;
	PWR->CR &= ~PWR_CR_DBP;
#endif
}

void PeripheralClock::resetRtc(void)
{
#if defined(STM32F7)
	PWR->CR1 |= PWR_CR1_DBP_Msk;
	RCC->BDCR |= RCC_BDCR_BDRST_Msk;
	__NOP();
	__NOP();
	RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
	PWR->CR1 &= ~PWR_CR1_DBP_Msk;
#elif defined(STM32F4)
	PWR->CR |= PWR_CR_DBP_Msk;
	RCC->BDCR |= RCC_BDCR_BDRST_Msk;
	__NOP();
	__NOP();
	RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
	PWR->CR &= ~PWR_CR_DBP_Msk;
#elif defined(STM32L0)
	PWR->CR |= PWR_CR_DBP_Msk;
	RCC->CSR |= RCC_CSR_RTCRST_Msk;
	__NOP();
	__NOP();
	RCC->CSR &= ~RCC_CSR_RTCRST_Msk;
	PWR->CR &= ~PWR_CR_DBP_Msk;
#endif
}
#endif

#if defined(EIC)

void PeripheralClock::setExtiEn(bool en)
{
#if defined(__SAM_L_FAMILY)
	GCLK->PCHCTRL[EIC_GCLK_ID].bit.CHEN = en;
#endif
}

void PeripheralClock::resetExti(void)
{
#if defined(__SAM_L_FAMILY)
#endif
}
#endif

#if defined(USB)

void PeripheralClock::setUsb1En(bool en)
{
#if defined(STM32F1)
	if (en)
		RCC->APB1ENR |= RCC_APB1ENR_USBEN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_USBEN_Msk;
#endif
}

void PeripheralClock::resetUsb1(void)
{
#if defined(STM32F1)
	RCC->APB1RSTR |= RCC_APB1RSTR_USBRST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_USBRST_Msk;
#endif
}
#endif

#endif
*/