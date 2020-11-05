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

#ifndef YSS_DRV_DMA_ST_TYPE_A_REG__H_
#define YSS_DRV_DMA_ST_TYPE_A_REG__H_

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <yss/reg.h>

#define setDmaStreamPar(addr, par)			addr->PAR = par
#define setDmaStreamMar0(addr, mar)			addr->M0AR = mar
#define setDmaStreamMar1(addr, mar)			addr->M1AR = mar
#define setDmaStreamNdtr(addr, ndtr)		addr->NDTR = ndtr
#define getDmaStreamNdtr(addr)				(unsigned short)addr->NDTR
#define getDmaStreamEn(addr)				getRegBit(addr->CR, 0)
#define setDmaStreamEn(addr, x)				setRegBit(addr->CR, x, 0)
#define setDmaStreamPfctrl(addr, x)			setRegBit(addr->CR, x, 5)
#define setDmaStreamDir(addr, x)			setRegField(addr->CR, 0x3UL, x, 6)
#define setDmaStreamCirc(addr, x)			setRegBit(addr->CR, x, 8)
#define setDmaStreamPinc(addr, x)			setRegBit(addr->CR, x, 9)
#define setDmaStreamMinc(addr, x)			setRegBit(addr->CR, x, 10)
#define setDmaStreamPsize(addr, x)			setRegField(addr->CR, 0x3UL, x, 11)
#define setDmaStreamMsize(addr, x)			setRegField(addr->CR, 0x3UL, x, 13)
#define setDmaStreamPriorityLevel(addr, x)	setRegField(addr->CR, 0x3UL, x, 16)
#define setDmaStreamPburst(addr, x)			setRegField(addr->CR, 0x3UL, x, 21)
#define setDmaStreamMburst(addr, x)			setRegField(addr->CR, 0x3UL, x, 23)
#define setDmaStreamChSel(addr, ch)			setRegField(addr->CR, 0x7UL, ch, 25)

#define setDmaStreamTeie(addr, x)			setRegBit(addr->CR, x, 2)
#define setDmaStreamTcie(addr, x)			setRegBit(addr->CR, x, 4)

#define setDmaStreamFifoEn(addr, x)			setRegBit(addr->FCR, x, 2)
#define setDmaStreamFth(addr, x)			setRegField(addr->FCR, 0x3UL, x, 0)

#define getDmaStream0Sr(addr)				getRegField(addr->LISR, 0x3FUL, 0)
#define clrDmaStream0Sr(addr, x)			setRegField(addr->LIFCR, 0x3FUL, x, 0)
#define getDmaStream1Sr(addr)				getRegField(addr->LISR, 0x3FUL, 6)
#define clrDmaStream1Sr(addr, x)			setRegField(addr->LIFCR, 0x3FUL, x, 6)
#define getDmaStream2Sr(addr)				getRegField(addr->LISR, 0x3FUL, 16)
#define clrDmaStream2Sr(addr, x)			setRegField(addr->LIFCR, 0x3FUL, x, 16)
#define getDmaStream3Sr(addr)				getRegField(addr->LISR, 0x3FUL, 22)
#define clrDmaStream3Sr(addr, x)			setRegField(addr->LIFCR, 0x3FUL, x, 22)
#define getDmaStream4Sr(addr)				getRegField(addr->HISR, 0x3FUL, 0)
#define clrDmaStream4Sr(addr, x)			setRegField(addr->HIFCR, 0x3FUL, x, 0)
#define getDmaStream5Sr(addr)				getRegField(addr->HISR, 0x3FUL, 6)
#define clrDmaStream5Sr(addr, x)			setRegField(addr->HIFCR, 0x3FUL, x, 6)
#define getDmaStream6Sr(addr)				getRegField(addr->HISR, 0x3FUL, 16)
#define clrDmaStream6Sr(addr, x)			setRegField(addr->HIFCR, 0x3FUL, x, 16)
#define getDmaStream7Sr(addr)				getRegField(addr->HISR, 0x3FUL, 22)
#define clrDmaStream7Sr(addr, x)			setRegField(addr->HIFCR, 0x3FUL, x, 22)

#endif

#endif
