////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////


#ifndef YSS_DRV_QUADSPI_ST_TYPE_A_REGISTER__H_
#define YSS_DRV_QUADSPI_ST_TYPE_A_REGISTER__H_

#if	defined(STM32F746xx) ||	defined(STM32F745xx) ||	\
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx)

#include <yss/reg.h>

#define setQuadspiEn(x)								setRegBit(QUADSPI->CR, x, 0)
#define getQuadspiEn()								getRegBit(QUADSPI->CR, 0)
#define setQuadspiDmaEn(x)							setRegBit(QUADSPI->CR, x, 2)
#define setQuadspiSampleShift(x)					setRegBit(QUADSPI->CR, x, 4)
#define setQuadspiFlashMemorySelect(x)				setRegBit(QUADSPI->CR, x, 7)
#define setQuadspiTransferCompleteInterruptEn(x)	setRegBit(QUADSPI->CR, x, 17)
#define setQuadspiAutomaticPollModeStop(x)			setRegBit(QUADSPI->CR, x, 22)
#define setQuadspiPollingMatchMode(x)				setRegBit(QUADSPI->CR, x, 23)
#define setQuadspiPrescaler(x)						setRegField(QUADSPI->CR, 0xff, x, 24)

#define setQuadspiChipSelectHighTime(x)				setRegField(QUADSPI->DCR, 0x1f, x, 8)
#define setQuadspiFlashMemorySize(x)				setRegField(QUADSPI->DCR, 0x1f, x, 16)
#define setQuadspiClockMode(x)						setRegBit(QUADSPI->DCR, x, 0)

#define getQuadspiTransferCompleteFlag()			getRegBit(QUADSPI->SR, 1)
#define clearQuadspiTransferCompleteFlag()			setRegBit(QUADSPI->FCR, 1, 1)
#define getQuadspiStatusMatchFlag()					getRegBit(QUADSPI->SR, 3)
#define clearQuadspiStatusMatchFlag()				setRegBit(QUADSPI->FCR, 1, 3)
#define getQuadspiBusyFlag()						getRegBit(QUADSPI->SR, 5)

#define setQuadspiDataLength(x)						QUADSPI->DLR = x

#define setQuadspiAddress(x)						QUADSPI->AR = x

#define setQuadspiPollingStatusMaskValue(x)			QUADSPI->PSMKR = x

#define setQuadspiPollingStatusMatchValue(x)		QUADSPI->PSMAR = x

#endif

#endif
