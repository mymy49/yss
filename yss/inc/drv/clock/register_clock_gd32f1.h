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

#ifndef YSS_DRV_CLOCK_GD32F1_REG__H_
#define YSS_DRV_CLOCK_GD32F1_REG__H_

#include <yss/reg.h>
/*
#define setRccHseEn(x) setRegBit(RCC->CR, x, 16)
#define getRccHseReady() getRegBit(RCC->CR, 17)
#define setRccMainPllOn(x) setRegBit(RCC->CR, x, 24)
#define getRccMainPllReady() getRegBit(RCC->CR, 25)

#define setRccSysclkSw(x) setRegField(RCC->CFGR, 0x3UL, x, 0)
#define getRccSysclkSw() getRegField(RCC->CFGR, 0x3UL, 2)
#define setRccHpre(x) setRegField(RCC->CFGR, 0xFUL, x, 4)
#define getRccHpre() getRegField(RCC->CFGR, 0xFUL, 4)
#define setRccPpre1(x) setRegField(RCC->CFGR, 0x7UL, x, 8)
#define getRccPpre1() getRegField(RCC->CFGR, 0x7UL, 8)
#define setRccPpre2(x) setRegField(RCC->CFGR, 0x7UL, x, 11)
#define getRccPpre2() getRegField(RCC->CFGR, 0x7UL, 11)
#define setRccAdcpre(x) setRegField(RCC->CFGR, 0x3UL, x, 14)
#define getRccAdcpre() getRegField(RCC->CFGR, 0x3UL, 14)
#define setRccPllSrc(x) setRegBit(RCC->CFGR, x, 16)
#define setRccPllXtpre(x) setRegBit(RCC->CFGR, x, 17)
#define setRccPllMul(x) setRegField(RCC->CFGR, 0xfUL, x, 18)

#define setRccLseEn(x) setRegBit(RCC->BDCR, x, 0)
#define getRccLseReady(x) getRegBit(RCC->BDCR, 1)

#define setRccLsiEn(x) setRegBit(RCC->CSR, x, 0)
#define getRccLsiReady(x) getRegBit(RCC->CSR, 1)

#define setRccDma1En(x) setRegBit(RCC->AHBENR, x, 0)
#define setRccDma2En(x) setRegBit(RCC->AHBENR, x, 1)

#define resetRccI2c1(x) setRegBit(RCC->APB1RSTR, x, 21)
#define resetRccI2c2(x) setRegBit(RCC->APB1RSTR, x, 22)
#define resetRccCan1(x) setRegBit(RCC->APB1RSTR, x, 25)
#define resetRccCan2(x) setRegBit(RCC->APB1RSTR, x, 26)

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
#define setRccI2c1En(x) setRegBit(RCC->APB1ENR, x, 21)
#define setRccI2c2En(x) setRegBit(RCC->APB1ENR, x, 22)
#define setRccCan1En(x) setRegBit(RCC->APB1ENR, x, 25)
#define setRccCan2En(x) setRegBit(RCC->APB1ENR, x, 26)
#define setRccDacEn(x) setRegBit(RCC->APB1ENR, x, 29)

#define setRccAfioEn(x) setRegBit(RCC->APB2ENR, x, 0)
#define setRccGpioAEn(x) setRegBit(RCC->APB2ENR, x, 2)
#define setRccGpioBEn(x) setRegBit(RCC->APB2ENR, x, 3)
#define setRccGpioCEn(x) setRegBit(RCC->APB2ENR, x, 4)
#define setRccGpioDEn(x) setRegBit(RCC->APB2ENR, x, 5)
#define setRccGpioEEn(x) setRegBit(RCC->APB2ENR, x, 6)
#define setRccGpioFEn(x) setRegBit(RCC->APB2ENR, x, 7)
#define setRccGpioGEn(x) setRegBit(RCC->APB2ENR, x, 8)
#define setRccAdc1En(x) setRegBit(RCC->APB2ENR, x, 9)
#define setRccAdc2En(x) setRegBit(RCC->APB2ENR, x, 10)
#define setRccTim1En(x) setRegBit(RCC->APB2ENR, x, 11)
#define setRccSpi1En(x) setRegBit(RCC->APB2ENR, x, 12)
#define setRccTim8En(x) setRegBit(RCC->APB2ENR, x, 13)
#define setRccUsart1En(x) setRegBit(RCC->APB2ENR, x, 14)
#define setRccTim9En(x) setRegBit(RCC->APB2ENR, x, 19)
#define setRccTim10En(x) setRegBit(RCC->APB2ENR, x, 20)
#define setRccTim11En(x) setRegBit(RCC->APB2ENR, x, 21)
*/
#endif