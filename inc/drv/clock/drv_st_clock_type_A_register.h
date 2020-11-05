////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//	이전 주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 2020.04.26
//  주담당자 : 맨틀코어 (tttwwuu@naver.com) 2020.04.26 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////


#ifndef YSS_DRV_CLOCK_ST_TYPE_A_REG__H_
#define YSS_DRV_CLOCK_ST_TYPE_A_REG__H_

#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx)

#include <yss/reg.h>

#define setRccHseEn(x)			setRegBit(RCC->CR, x, 16)
#define getRccHseReady()		getRegBit(RCC->CR, 17)
#define setRccMainPllOn(x)		setRegBit(RCC->CR, x, 24)
#define getRccMainPllReady()	getRegBit(RCC->CR, 25)
#define setRccSaiPllOn(x)		setRegBit(RCC->CR, x, 28)
#define getRccSaiPllReady()		getRegBit(RCC->CR, 29)

#define setRccMainPllm(x)		setRegField(RCC->PLLCFGR, 0x3FUL, x, 0)
#define getRccMainPllm()		getRegField(RCC->PLLCFGR, 0x3FUL, 0)
#define setRccMainPlln(x)		setRegField(RCC->PLLCFGR, 0x1FFUL, x, 6)
#define getRccMainPlln(x)		getRegField(RCC->PLLCFGR, 0x1FFUL, 6)
#define setRccMainPllp(x)		setRegField(RCC->PLLCFGR, 0x3UL, x, 16)
#define getRccMainPllp(x)		getRegField(RCC->PLLCFGR, 0x3UL, 16)
#define setRccMainPllSrc(x)		setRegBit(RCC->PLLCFGR, x, 22)
#define getRccMainPllSrc()		getRegBit(RCC->PLLCFGR, 22)
#define setRccMainPllq(x)		setRegField(RCC->PLLCFGR, 0xFUL, x, 24)
#define getRccMainPllq(x)		getRegField(RCC->PLLCFGR, 0xFUL, 24)

#define setRccSysclkSw(x)		setRegField(RCC->CFGR, 0x3UL, x, 0)
#define	getRccSysclkSw()		getRegField(RCC->CFGR, 0x3UL, 2)
#define setRccHpre(x)			setRegField(RCC->CFGR, 0xFUL, x, 4)
#define getRccHpre()			getRegField(RCC->CFGR, 0xFUL, 4)
#define setRccPpre2(x)			setRegField(RCC->CFGR, 0x7UL, x, 13)
#define setRccPpre1(x)			setRegField(RCC->CFGR, 0x7UL, x, 10)
#define getRccPpre2()			getRegField(RCC->CFGR, 0x7UL, 13)
#define getRccPpre1()			getRegField(RCC->CFGR, 0x7UL, 10)

#define setRccResetDma1(x)		setRegBit(RCC->AHB1RSTR, x, 21)
#define setRccResetDma2(x)		setRegBit(RCC->AHB1RSTR, x, 22)


#define setRccResetUart2(x)		setRegBit(RCC->APB1RSTR, x, 17)

#define setRccGpioAEn(x)		setRegBit(RCC->AHB1ENR, x, 0)
#define setRccGpioBEn(x)		setRegBit(RCC->AHB1ENR, x, 1)
#define setRccGpioCEn(x)		setRegBit(RCC->AHB1ENR, x, 2)
#define setRccGpioDEn(x)		setRegBit(RCC->AHB1ENR, x, 3)
#define setRccGpioEEn(x)		setRegBit(RCC->AHB1ENR, x, 4)
#define setRccGpioFEn(x)		setRegBit(RCC->AHB1ENR, x, 5)
#define setRccGpioGEn(x)		setRegBit(RCC->AHB1ENR, x, 6)
#define setRccGpioHEn(x)		setRegBit(RCC->AHB1ENR, x, 7)
#define setRccGpioIEn(x)		setRegBit(RCC->AHB1ENR, x, 8)
#define setRccGpioJEn(x)		setRegBit(RCC->AHB1ENR, x, 9)
#define setRccGpioKEn(x)		setRegBit(RCC->AHB1ENR, x, 10)
#define setRccDma1En(x)			setRegBit(RCC->AHB1ENR, x, 21)
#define setRccDma2En(x)			setRegBit(RCC->AHB1ENR, x, 22)
#define setRccDma2dEn(x)		setRegBit(RCC->AHB1ENR, x, 23)
#define setRccOtgHsEn(x)		setRegBit(RCC->AHB1ENR, x, 29)

#define setRccOtgFsEn(x)		setRegBit(RCC->AHB2ENR, x, 7)

#define setRccQuadspiEn(x)		setRegBit(RCC->AHB3ENR, x, 1)
#define setRccFmcEn(x)			setRegBit(RCC->AHB3ENR, x, 0)

#define setRccTim2En(x)			setRegBit(RCC->APB1ENR, x, 0)
#define setRccTim3En(x)			setRegBit(RCC->APB1ENR, x, 1)
#define setRccTim4En(x)			setRegBit(RCC->APB1ENR, x, 2)
#define setRccTim5En(x)			setRegBit(RCC->APB1ENR, x, 3)
#define setRccTim6En(x)			setRegBit(RCC->APB1ENR, x, 4)
#define setRccTim7En(x)			setRegBit(RCC->APB1ENR, x, 5)
#define setRccTim12En(x)		setRegBit(RCC->APB1ENR, x, 6)
#define setRccTim13En(x)		setRegBit(RCC->APB1ENR, x, 7)
#define setRccTim14En(x)		setRegBit(RCC->APB1ENR, x, 8)
#define setRccSpi2En(x)			setRegBit(RCC->APB1ENR, x, 14)
#define setRccSpi3En(x)			setRegBit(RCC->APB1ENR, x, 15)
#define setRccUsart2En(x)		setRegBit(RCC->APB1ENR, x, 17)
#define setRccUsart3En(x)		setRegBit(RCC->APB1ENR, x, 18)
#define setRccUart4En(x)		setRegBit(RCC->APB1ENR, x, 19)
#define setRccUart5En(x)		setRegBit(RCC->APB1ENR, x, 20)
#define setRccI2c1En(x)			setRegBit(RCC->APB1ENR, x, 21)
#define setRccI2c2En(x)			setRegBit(RCC->APB1ENR, x, 22)
#define setRccI2c3En(x)			setRegBit(RCC->APB1ENR, x, 23)
#define setRccI2c4En(x)			setRegBit(RCC->APB1ENR, x, 24)
#define setRccCan1En(x)			setRegBit(RCC->APB1ENR, x, 25)
#define setRccCan2En(x)			setRegBit(RCC->APB1ENR, x, 26)
#define setRccPwrEn(x)			setRegBit(RCC->APB1ENR, x, 28)
#define setRccDacEn(x)			setRegBit(RCC->APB1ENR, x, 29)
#define setRccUart7En(x)		setRegBit(RCC->APB1ENR, x, 30)
#define setRccUart8En(x)		setRegBit(RCC->APB1ENR, x, 31)

#define setRccTim1En(x)			setRegBit(RCC->APB2ENR, x, 0)
#define setRccTim8En(x)			setRegBit(RCC->APB2ENR, x, 1)
#define setRccAdc1En(x)			setRegBit(RCC->APB2ENR, x, 8)
#define setRccUsart1En(x)		setRegBit(RCC->APB2ENR, x, 4)
#define setRccUsart6En(x)		setRegBit(RCC->APB2ENR, x, 5)
#define setRccAdc2En(x)			setRegBit(RCC->APB2ENR, x, 9)
#define setRccAdc3En(x)			setRegBit(RCC->APB2ENR, x, 10)
#define setRccSdmmc1En(x)		setRegBit(RCC->APB2ENR, x, 11)
#define setRccSpi1En(x)			setRegBit(RCC->APB2ENR, x, 12)
#define setRccSpi4En(x)			setRegBit(RCC->APB2ENR, x, 13)
#define setRccSyscfgEn(x)		setRegBit(RCC->APB2ENR, x, 14)
#define setRccTim9En(x)			setRegBit(RCC->APB2ENR, x, 16)
#define setRccTim10En(x)		setRegBit(RCC->APB2ENR, x, 17)
#define setRccTim11En(x)		setRegBit(RCC->APB2ENR, x, 18)
#define setRccSpi5En(x)			setRegBit(RCC->APB2ENR, x, 20)
#define setRccSpi6En(x)			setRegBit(RCC->APB2ENR, x, 21)
#define setRccLtdcEn(x)			setRegBit(RCC->APB2ENR, x, 26)

#define setRccLseEn(x)				setRegBit(RCC->BDCR, x, 0)
#define setRccLseDrive(x)			setRegField(RCC->BDCR, 0x3UL, x, 3)
#define getRccLseReady(x)			getRegBit(RCC->BDCR, 1)
#define setRccBackupDomainRst(x)	setRegBit(RCC->BDCR, x, 16)
#define setRccRtcEn(x)				setRegBit(RCC->BDCR, x, 15)
#define getRccRtcEn()				getRegBit(RCC->BDCR, 15)
#define setRccRtcClockSrc(x)		setRegField(RCC->BDCR, 0x3UL, x, 8)

#define setRccLsiEn(x)			setRegBit(RCC->CSR, x, 0)
#define getRccLsiReady(x)		getRegBit(RCC->CSR, 1)

#define setRccSaiPlln(x)		setRegField(RCC->PLLSAICFGR, 0x1FFUL, x, 6)
#define getRccSaiPlln(x)		getRegField(RCC->PLLSAICFGR, 0x1FFUL, 6)
#define setRccSaiPllp(x)		setRegField(RCC->PLLSAICFGR, 0x3UL, x, 16)
#define getRccSaiPllp(x)		getRegField(RCC->PLLSAICFGR, 0x3UL, 16)
#define setRccSaiPllq(x)		setRegField(RCC->PLLSAICFGR, 0xFUL, x, 24)
#define getRccSaiPllq(x)		getRegField(RCC->PLLSAICFGR, 0xFUL, 24)
#define setRccSaiPllr(x)		setRegField(RCC->PLLSAICFGR, 0x7UL, x, 28)
#define getRccSaiPllr(x)		getRegField(RCC->PLLSAICFGR, 0x7UL, 28)

#define setRccSaiDivr(x)		setRegField(RCC->DCKCFGR1, 0x3UL, x, 16)
#define getRccSaiDivr(x)		getRegField(RCC->DCKCFGR1, 0x3UL, 16)
#define setRccSaiDivq(x)		setRegField(RCC->DCKCFGR1, 0x3UL, x, 8)
#define getRccSaiDivq(x)		getRegField(RCC->DCKCFGR1, 0x3UL, 8)

#define setRccSdmmc1ClkSel(x)	setRegBit(RCC->DCKCFGR2, x, 28)
#define setRccUsbClkSel(x)		setRegBit(RCC->DCKCFGR2, x, 27)
#define setRccI2c1Sel(x)		setRegField(RCC->DCKCFGR2, 0x3UL, x, 16)
#define setRccI2c2Sel(x)		setRegField(RCC->DCKCFGR2, 0x3UL, x, 18)
#define setRccI2c3Sel(x)		setRegField(RCC->DCKCFGR2, 0x3UL, x, 20)
#define setRccI2c4Sel(x)		setRegField(RCC->DCKCFGR2, 0x3UL, x, 22)

#define RCC_I2C_CLK_APB1		0
#define RCC_I2C_CLK_SYSCLK		1
#define RCC_I2C_CLK_HSI			2

#endif

#endif
