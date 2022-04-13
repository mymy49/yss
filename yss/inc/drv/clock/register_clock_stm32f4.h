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

#ifndef YSS_DRV_CLOCK_ST_TYPE_C_REG__H_
#define YSS_DRV_CLOCK_ST_TYPE_C_REG__H_

#if defined(STM32F405xx) || defined(STM32F415xx) || \
	defined(STM32F407xx) || defined(STM32F417xx) || \
	defined(STM32F427xx) || defined(STM32F437xx) || \
	defined(STM32F429xx) || defined(STM32F439xx)

#include <yss/reg.h>

#define setRccHseEn(x) setRegBit(RCC->CR, x, 16)
#define getRccHseReady() getRegBit(RCC->CR, 17)
#define setRccMainPllOn(x) setRegBit(RCC->CR, x, 24)
#define getRccMainPllReady() getRegBit(RCC->CR, 25)
#define setRccSaiPllOn(x) setRegBit(RCC->CR, x, 28)
#define getRccSaiPllReady() getRegBit(RCC->CR, 29)

#define setRccHpre(x) setRegField(RCC->CFGR, 0xFUL, x, 4)
#define getRccHpre() getRegField(RCC->CFGR, 0xFUL, 4)
#define setRccPpre2(x) setRegField(RCC->CFGR, 0x7UL, x, 13)
#define setRccPpre1(x) setRegField(RCC->CFGR, 0x7UL, x, 10)
#define getRccPpre2() getRegField(RCC->CFGR, 0x7UL, 13)
#define getRccPpre1() getRegField(RCC->CFGR, 0x7UL, 10)
#define setRccSysclkSw(x) setRegField(RCC->CFGR, 0x3UL, x, 0)
#define getRccSysclkSw() getRegField(RCC->CFGR, 0x3UL, 2)

#define setRccMainPllm(x) setRegField(RCC->PLLCFGR, 0x3FUL, x, 0)
#define getRccMainPllm() getRegField(RCC->PLLCFGR, 0x3FUL, 0)
#define setRccMainPlln(x) setRegField(RCC->PLLCFGR, 0x1FFUL, x, 6)
#define getRccMainPlln(x) getRegField(RCC->PLLCFGR, 0x1FFUL, 6)
#define setRccMainPllp(x) setRegField(RCC->PLLCFGR, 0x3UL, x, 16)
#define getRccMainPllp(x) getRegField(RCC->PLLCFGR, 0x3UL, 16)
#define setRccMainPllSrc(x) setRegBit(RCC->PLLCFGR, x, 22)
#define getRccMainPllSrc() getRegBit(RCC->PLLCFGR, 22)
#define setRccMainPllq(x) setRegField(RCC->PLLCFGR, 0xFUL, x, 24)
#define getRccMainPllq(x) getRegField(RCC->PLLCFGR, 0xFUL, 24)

#define setRccGpioAEn(x) setRegBit(RCC->AHB1ENR, x, 0)
#define setRccGpioBEn(x) setRegBit(RCC->AHB1ENR, x, 1)
#define setRccGpioCEn(x) setRegBit(RCC->AHB1ENR, x, 2)
#define setRccGpioDEn(x) setRegBit(RCC->AHB1ENR, x, 3)
#define setRccGpioEEn(x) setRegBit(RCC->AHB1ENR, x, 4)
#define setRccGpioFEn(x) setRegBit(RCC->AHB1ENR, x, 5)
#define setRccGpioGEn(x) setRegBit(RCC->AHB1ENR, x, 6)
#define setRccGpioHEn(x) setRegBit(RCC->AHB1ENR, x, 7)
#define setRccGpioIEn(x) setRegBit(RCC->AHB1ENR, x, 8)
#define setRccGpioJEn(x) setRegBit(RCC->AHB1ENR, x, 9)
#define setRccGpioKEn(x) setRegBit(RCC->AHB1ENR, x, 10)
#define setRccDma1En(x) setRegBit(RCC->AHB1ENR, x, 21)
#define setRccDma2En(x) setRegBit(RCC->AHB1ENR, x, 22)
#define setRccDma2dEn(x) setRegBit(RCC->AHB1ENR, x, 23)
#define setRccOtgHsEn(x) setRegBit(RCC->AHB1ENR, x, 29)

#define setRccFmcEn(x) setRegBit(RCC->AHB3ENR, x, 0)

#define setRccTim2En(x) setRegBit(RCC->APB1ENR, x, 0)
#define setRccTim3En(x) setRegBit(RCC->APB1ENR, x, 1)
#define setRccTim4En(x) setRegBit(RCC->APB1ENR, x, 2)
#define setRccTim5En(x) setRegBit(RCC->APB1ENR, x, 3)
#define setRccTim6En(x) setRegBit(RCC->APB1ENR, x, 4)
#define setRccTim7En(x) setRegBit(RCC->APB1ENR, x, 5)
#define setRccTim12En(x) setRegBit(RCC->APB1ENR, x, 6)
#define setRccTim13En(x) setRegBit(RCC->APB1ENR, x, 7)
#define setRccTim14En(x) setRegBit(RCC->APB1ENR, x, 8)
#define setRccSpi2En(x) setRegBit(RCC->APB1ENR, x, 14)
#define setRccSpi3En(x) setRegBit(RCC->APB1ENR, x, 15)
#define setRccUsart2En(x) setRegBit(RCC->APB1ENR, x, 17)
#define setRccUsart3En(x) setRegBit(RCC->APB1ENR, x, 18)
#define setRccUart4En(x) setRegBit(RCC->APB1ENR, x, 19)
#define setRccUart5En(x) setRegBit(RCC->APB1ENR, x, 20)
#define setRccCan1En(x) setRegBit(RCC->APB1ENR, x, 25)
#define setRccCan2En(x) setRegBit(RCC->APB1ENR, x, 26)
#define setRccPwrEn(x) setRegBit(RCC->APB1ENR, x, 28)
#define setRccUart7En(x) setRegBit(RCC->APB1ENR, x, 30)
#define setRccUart8En(x) setRegBit(RCC->APB1ENR, x, 31)

#define setRccTim1En(x) setRegBit(RCC->APB2ENR, x, 0)
#define setRccTim8En(x) setRegBit(RCC->APB2ENR, x, 1)
#define setRccUsart1En(x) setRegBit(RCC->APB2ENR, x, 4)
#define setRccUsart6En(x) setRegBit(RCC->APB2ENR, x, 5)
#define setRccOtgFsEn(x) setRegBit(RCC->AHB2ENR, x, 7)
#define setRccSpi1En(x) setRegBit(RCC->APB2ENR, x, 12)
#define setRccSpi4En(x) setRegBit(RCC->APB2ENR, x, 13)
#define setRccSyscfgEn(x) setRegBit(RCC->APB2ENR, x, 14)
#define setRccTim9En(x) setRegBit(RCC->APB2ENR, x, 16)
#define setRccTim10En(x) setRegBit(RCC->APB2ENR, x, 17)
#define setRccTim11En(x) setRegBit(RCC->APB2ENR, x, 18)
#define setRccSpi5En(x) setRegBit(RCC->APB2ENR, x, 20)
#define setRccSpi6En(x) setRegBit(RCC->APB2ENR, x, 21)
#define setRccLtdcEn(x) setRegBit(RCC->APB2ENR, x, 26)

#define setRccSaiPlln(x) setRegField(RCC->PLLSAICFGR, 0x1FFUL, x, 6)
#define getRccSaiPlln(x) getRegField(RCC->PLLSAICFGR, 0x1FFUL, 6)
#define setRccSaiPllq(x) setRegField(RCC->PLLSAICFGR, 0xFUL, x, 24)
#define getRccSaiPllq(x) getRegField(RCC->PLLSAICFGR, 0xFUL, 24)
#define setRccSaiPllr(x) setRegField(RCC->PLLSAICFGR, 0x7UL, x, 28)
#define getRccSaiPllr(x) getRegField(RCC->PLLSAICFGR, 0x7UL, 28)

#endif

#endif