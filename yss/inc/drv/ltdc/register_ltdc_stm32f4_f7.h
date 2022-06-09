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

#ifndef YSS_DRV_LTDC_ST_TYPE_A_REG__H_
#define YSS_DRV_LTDC_ST_TYPE_A_REG__H_

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
	defined(STM32F429xx) || defined(STM32F439xx)

#include <yss/reg.h>

#define setLtdcHsw(x) setRegField(LTDC->SSCR, 0xFFFUL, x, 16)
#define setLtdcVsh(x) setRegField(LTDC->SSCR, 0x7FFUL, x, 0)
#define setLtdcAhbp(x) setRegField(LTDC->BPCR, 0xFFFUL, x, 16)
#define setLtdcAvbp(x) setRegField(LTDC->BPCR, 0x7FFUL, x, 0)
#define setLtdcAaw(x) setRegField(LTDC->AWCR, 0xFFFUL, x, 16)
#define setLtdcAah(x) setRegField(LTDC->AWCR, 0x7FFUL, x, 0)
#define setLtdcTotalw(x) setRegField(LTDC->TWCR, 0xFFFUL, x, 16)
#define setLtdcTotalh(x) setRegField(LTDC->TWCR, 0x7FFUL, x, 0)
#define setLtdcImediateReload() setRegBit(LTDC->SRCR, 1, 0)

#define setLtdcHspol(x) setRegBit(LTDC->GCR, x, 31)
#define setLtdcVspol(x) setRegBit(LTDC->GCR, x, 30)
#define setLtdcDepol(x) setRegBit(LTDC->GCR, x, 29)
#define setLtdcPcpol(x) setRegBit(LTDC->GCR, x, 28)
#define setLtdcDitherEn(x) setRegBit(LTDC->GCR, x, 16)
#define setLtdcEnable(x) setRegBit(LTDC->GCR, x, 0)
#define getLtdcEnable() getRegBit(LTDC->GCR, 0)

#define setLtdcBcRed(x) setRegField(LTDC->BCCR, 0xFFUL, x, 16)
#define setLtdcBcGreen(x) setRegField(LTDC->BCCR, 0xFFUL, x, 8)
#define setLtdcBcBlue(x) setRegField(LTDC->BCCR, 0xFFUL, x, 0)

#define getLtdcLif() getRegBit(LTDC->ISR, 0)
#define getLtdcFuif() getRegBit(LTDC->ISR, 1)
#define getLtdcTerrif() getRegBit(LTDC->ISR, 2)
#define getLtdcRrif() getRegBit(LTDC->ISR, 3)

#define setLtdcLie(x) setRegBit(LTDC->IER, x, 0)
#define setLtdcClif() setRegBit(LTDC->ICR, 1, 0)

#define setLtdcLipos(x) setRegField(LTDC->LIPCR, 0x7FFUL, x, 0)

#define setLtdcLayerPixelFormat(addr, x) setRegField(addr->PFCR, 0x7UL, x, 0)
#define setLtdcLayerConstAlpha(addr, x) setRegField(addr->CACR, 0xFFUL, x, 0)
#define setLtdcLayerFrameBuffer(addr, x) addr->CFBAR = x;
#define setLtdcLayerFrameBufferLineNumber(addr, x) addr->CFBLNR = (x & 0x7FFUL);
#define setLtdcLayerEn(addr, x) setRegBit(addr->CR, x, 0)

#endif

#endif