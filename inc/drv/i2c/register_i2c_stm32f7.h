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

#ifndef YSS_DRV_I2C_ST_TYPE_A_REG__H_
#define YSS_DRV_I2C_ST_TYPE_A_REG__H_

#include <drv/mcu.h>

#if	defined(STM32F7) || defined(STM32F0)

#include <yss/reg.h>

#define setI2cEn(addr, en)			setRegBit(addr->CR1, en, 0)
#define getI2cEn(addr)				getRegBit(addr->CR1, 0)
#define setI2cTxDmaEn(addr, x)		setRegBit(addr->CR1, x, 14)
#define setI2cRxDmaEn(addr, x)		setRegBit(addr->CR1, x, 15)

#define setI2cSaddr(addr, x)		setRegField(addr->CR2, 0x3FFUL, x, 0)
#define setI2cReadWrite(addr, x)	setRegBit(addr->CR2, x, 10)
#define setI2cAddr10(addr, x)		setRegBit(addr->CR2, x, 11)
#define setI2cStart(addr)			setRegBit(addr->CR2, 1, 13)
#define setI2cStop(addr)			setRegBit(addr->CR2, 1, 14)
#define setI2cNbytes(addr, x)		setRegField(addr->CR2, 0xFFUL, x, 16)

#define setI2cScll(addr, x)			setRegField(addr->TIMINGR, 0xFFUL, x, 0)
#define setI2cSclh(addr, x)			setRegField(addr->TIMINGR, 0xFFUL, x, 8)
#define setI2cSdaDel(addr, x)		setRegField(addr->TIMINGR, 0xFUL, x, 16)
#define setI2cSclDel(addr, x)		setRegField(addr->TIMINGR, 0xFUL, x, 20)
#define setI2cPresc(addr, x)		setRegField(addr->TIMINGR, 0xFUL, x, 28)

#endif

#endif
