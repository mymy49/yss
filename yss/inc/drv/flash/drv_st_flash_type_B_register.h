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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef	YSS_DRV_FLASH_ST_TYPE_B_REG__H_
#define	YSS_DRV_FLASH_ST_TYPE_B_REG__H_

#if	defined(STM32F100xB) || defined(STM32F100xE) || \
	defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
	defined(STM32F102x6) || defined(STM32F102xB) || \
	defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) || \
    defined(STM32F107xC)

#include <yss/reg.h>

#define	setFlashLatency(x)			setRegField(FLASH->ACR,	0x7UL, x, 0)
#define	setFlashHlfcyaEn(x)			setRegBit(FLASH->ACR, x, 3)
#define	setFlashPrefetchEn(x)		setRegBit(FLASH->ACR, x, 4)

#define	setFlashKey(x)				FLASH->KEYR = x
#define	setFlashKey2(x)				FLASH->KEYR2 = x

#define	setFlashSectorNumber(x)		FLASH->AR = x

#define	getFlashBusy()				getRegBit(FLASH->SR, 0)

#define	setFlashProgramming(x)		setRegBit(FLASH->CR, x, 0)
#define	setFlashSectorErase(x)		setRegBit(FLASH->CR, x, 1)
#define	setFlashEraseStart()		setRegBit(FLASH->CR, 1, 6)
#define	setFlashLock()				setRegBit(FLASH->CR, 1, 7)
#define	getFlashLock()				getRegBit(FLASH->CR, 7)

#define	setFlashSectorNumber2(x)	FLASH->AR2 = x

#define	getFlashBusy2()				getRegBit(FLASH->SR2, 0)

#define	setFlashProgramming2(x)		setRegBit(FLASH->CR2, x, 0)
#define	setFlashSectorErase2(x)		setRegBit(FLASH->CR2, x, 1)
#define	setFlashEraseStart2()		setRegBit(FLASH->CR2, 1, 6)
#define	setFlashLock2()				setRegBit(FLASH->CR2, 1, 7)
#define	getFlashLock2()				getRegBit(FLASH->CR2, 7)
#endif

#endif