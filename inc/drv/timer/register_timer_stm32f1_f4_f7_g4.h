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

#ifndef YSS_DRV_TIMER_ST_TYPE_A_REG__H_
#define YSS_DRV_TIMER_ST_TYPE_A_REG__H_

#include <drv/mcu.h>

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)

#include <yss/reg.h>

#define setTimDiv(addr, x) setRegField(addr->CR1, 0x3, x, 8)
#define setTimDir(addr, x) setRegBit(addr->CR1, x, 4)
#define setTimOnePulse(addr, x) setRegBit(addr->CR1, x, 3)
#define setTimEn(addr, x) setRegBit(addr->CR1, x, 0)

#define TIM_ETP_RISING 0
#define TIM_ETP_FALLING 1

#define setTimEtf(addr, x) setRegField(addr->SMCR, 0xf, x, 8)
#define setTimEtps(addr, x) setRegField(addr->SMCR, 0x3, x, 12)
#define setTimEtp(addr, x) setRegBit(addr->SMCR, x, 15)
#define setTimEce(addr, x) setRegBit(addr->SMCR, x, 14)

#define setTimUie(addr, x) setRegBit(addr->DIER, x, 0)
#define getTimUie(addr) getRegBit(addr->DIER, 0)

#define clrTimUif(addr) setRegBit(addr->SR, 0, 0)
#define getTimUif(addr) getRegBit(addr->SR, 0)

#define setTimCc1g(addr, x) setRegBit(addr->EGR, x, 1)
#define setTimCc2g(addr, x) setRegBit(addr->EGR, x, 2)
#define setTimCc3g(addr, x) setRegBit(addr->EGR, x, 3)
#define setTimCc4g(addr, x) setRegBit(addr->EGR, x, 4)

#define setTimCc1s(addr, x) setRegField(addr->CCMR1, 0x3, x, 0)
#define setTimCc2s(addr, x) setRegField(addr->CCMR1, 0x3, x, 8)
#define setTimCc3s(addr, x) setRegField(addr->CCMR2, 0x3, x, 0)
#define setTimCc4s(addr, x) setRegField(addr->CCMR2, 0x3, x, 8)
#define setTimOc1m(addr, x) setRegField(addr->CCMR1, 0x7, x, 4)
#define setTimOc2m(addr, x) setRegField(addr->CCMR1, 0x7, x, 12)
#define setTimOc3m(addr, x) setRegField(addr->CCMR2, 0x7, x, 4)
#define setTimOc4m(addr, x) setRegField(addr->CCMR2, 0x7, x, 12)
#define setTimOc1pe(addr, x) setRegBit(addr->CCMR1, x, 3)
#define setTimOc2pe(addr, x) setRegBit(addr->CCMR1, x, 11)
#define setTimOc3pe(addr, x) setRegBit(addr->CCMR2, x, 3)
#define setTimOc4pe(addr, x) setRegBit(addr->CCMR2, x, 11)
#define setTimOc1fe(addr, x) setRegBit(addr->CCMR1, x, 2)
#define setTimOc2fe(addr, x) setRegBit(addr->CCMR1, x, 10)
#define setTimOc3fe(addr, x) setRegBit(addr->CCMR2, x, 2)
#define setTimOc4fe(addr, x) setRegBit(addr->CCMR2, x, 10)
#define setTimOc1ce(addr, x) setRegBit(addr->CCMR1, x, 7)
#define setTimOc2ce(addr, x) setRegBit(addr->CCMR1, x, 15)
#define setTimOc3ce(addr, x) setRegBit(addr->CCMR2, x, 7)
#define setTimOc4ce(addr, x) setRegBit(addr->CCMR2, x, 15)

#define setTimMainOutputEn(addr, x) setRegBit(addr->BDTR, x, 15)

#define setTimCc1e(addr, x) setRegBit(addr->CCER, x, 0)
#define setTimCc2e(addr, x) setRegBit(addr->CCER, x, 4)
#define setTimCc3e(addr, x) setRegBit(addr->CCER, x, 8)
#define setTimCc4e(addr, x) setRegBit(addr->CCER, x, 12)
#define setTimCc1ne(addr, x) setRegBit(addr->CCER, x, 2)
#define setTimCc2ne(addr, x) setRegBit(addr->CCER, x, 6)
#define setTimCc3ne(addr, x) setRegBit(addr->CCER, x, 10)

#define getTimCnt(addr) (addr->CNT)
#define setTimCnt(addr, x) addr->CNT = (uint32_t)x

#define setTimPsc(addr, x) addr->PSC = (uint16_t)x

#define setTimArr(addr, x) addr->ARR = (uint32_t)x
#define getMcuTimArr(addr) (uint32_t)addr->ARR

#define setTimCcr1(addr, x) addr->CCR1 = (uint16_t)x
#define setTimCcr2(addr, x) addr->CCR2 = (uint16_t)x
#define setTimCcr3(addr, x) addr->CCR3 = (uint16_t)x
#define setTimCcr4(addr, x) addr->CCR4 = (uint16_t)x

#define setTimMoe(addr, x) setRegBit(addr->BDTR, x, 15)

inline void setTimCh1PwmDuty(TIM_TypeDef *addr, float duty)
{
	uint16_t ccr = (uint16_t)((float)getMcuTimArr(addr) * duty);
	setTimCcr1(addr, ccr);
}

inline void setTimCh2PwmDuty(TIM_TypeDef *addr, float duty)
{
	uint16_t ccr = (uint16_t)((float)getMcuTimArr(addr) * duty);
	setTimCcr2(addr, ccr);
}

inline void setTimCh3PwmDuty(TIM_TypeDef *addr, float duty)
{
	uint16_t ccr = (uint16_t)((float)getMcuTimArr(addr) * duty);
	setTimCcr3(addr, ccr);
}

inline void setTimCh4PwmDuty(TIM_TypeDef *addr, float duty)
{
	uint16_t ccr = (uint16_t)((float)getMcuTimArr(addr) * duty);
	setTimCcr4(addr, ccr);
}

#endif

#endif