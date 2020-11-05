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

#ifndef YSS_COMMON_DMA2D_REG__H_
#define YSS_COMMON_DMA2D_REG__H_

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <yss/reg.h>

#define setDma2dFgmar(x)					DMA2D->FGMAR = (unsigned long)x;
#define setDma2dFgAlpha(x)					setRegField(DMA2D->FGPFCCR, 0xFFUL, x, 24)
#define setDma2dFgAlphaMode(x)				setRegField(DMA2D->FGPFCCR, 0x3UL, x, 16)
#define setDma2dFgColorMode(x)				setRegField(DMA2D->FGPFCCR, 0xFUL, x, 0)
#define setDma2dFgLineOffset(x)				setRegField(DMA2D->FGOR, 0x3FFFUL, x, 0)
#define setDma2dFgColor(r, g, b)			setRegField3(DMA2D->FGCOLR, 0xff, r, 16, 0xff, g, 8, 0xff, b, 0)

#define setDma2dBgmar(x)					DMA2D->BGMAR = (unsigned long)x;
#define setDma2dBgAlpha(x)					setRegField(DMA2D->BGPFCCR, 0xFFUL, x, 24)
#define setDma2dBgAlphaMode(x)				setRegField(DMA2D->BGPFCCR, 0x3UL, x, 16)
#define setDma2dBgColorMode(x)				setRegField(DMA2D->BGPFCCR, 0xFUL, x, 0)
#define setDma2dBgLineOffset(x)				setRegField(DMA2D->BGOR, 0x3FFFUL, x, 0)

#define setDma2dOmar(x)						DMA2D->OMAR = (unsigned long)x
#define setDma2dOutputColorMode(x)			setRegField(DMA2D->OPFCCR, 0x7UL, x, 0)
#define setDma2dOutputColor(x)				DMA2D->OCOLR = (unsigned long)x
#define setDma2dOutputColorRgb565(r, g, b)	setRegField3(DMA2D->OCOLR, 0xFF, r, 11, 0xFF, g, 5, 0xFF, b, 0)

#define setDma2dNumOfLine(x)				setRegField(DMA2D->NLR, 0xFFFFUL, x, 0)
#define setDma2dNumOfPixel(x)				setRegField(DMA2D->NLR, 0x3FFFUL, x, 16)
#define setDma2dOutputLineOffset(x)			setRegField(DMA2D->OOR, 0x3FFFUL, x, 0)

#define setDma2dStart()						setRegBit(DMA2D->CR, 1, 0)
#define setDma2dMode(x)						setRegField(DMA2D->CR, 0x3UL, x, 16)

#define setDma2dTcie(x)						setRegBit(DMA2D->CR, x, 9)
#define getDma2dTcif()						getRegBit(DMA2D->ISR, 1)
#define clrDma2dTcif()						setRegBit(DMA2D->IFCR, 1, 1)

#endif

#endif
