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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_DMA_ST_TYPE_C_REG__H_
#define YSS_DRV_DMA_ST_TYPE_C_REG__H_

#include <yss/mcu.h>

#if defined(STM32L0) || defined (STM32G4) || defined (STM32F0)

#include <yss/reg.h>

#define setDmaStreamPar(addr, par) addr->CPAR = par
#define setDmaStreamMar(addr, mar) addr->CMAR = mar
#define setDmaStreamNdtr(addr, ndtr) addr->CNDTR = ndtr
#define getDmaStreamNdtr(addr) (unsigned short)addr->NDTR
#define getDmaStreamEn(addr) getRegBit(addr->CCR, 0)
#define setDmaStreamEn(addr, x) setRegBit(addr->CCR, x, 0)
#define setDmaStreamDir(addr, x) setRegBit(addr->CCR, x, 4)
#define setDmaStreamCirc(addr, x) setRegBit(addr->CCR, x, 5)
#define setDmaStreamPinc(addr, x) setRegBit(addr->CCR, x, 6)
#define setDmaStreamMinc(addr, x) setRegBit(addr->CCR, x, 7)
#define setDmaStreamPsize(addr, x) setRegField(addr->CCR, 0x3UL, x, 8)
#define setDmaStreamMsize(addr, x) setRegField(addr->CCR, 0x3UL, x, 10)
#define setDmaStreamPriorityLevel(addr, x) setRegField(addr->CCR, 0x3UL, x, 12)

#define setDmaStreamTcie(addr, x) setRegBit(addr->CCR, x, 1)
#define setDmaStreamTeie(addr, x) setRegBit(addr->CCR, x, 3)

#define getDmaStream1Sr(addr) getRegField(addr->ISR, 0xFUL, 0)
#define clrDmaStream1Sr(addr, x) setRegField(addr->IFCR, 0xFUL, x, 0)
#define getDmaStream2Sr(addr) getRegField(addr->ISR, 0xFUL, 4)
#define clrDmaStream2Sr(addr, x) setRegField(addr->IFCR, 0xFUL, x, 4)
#define getDmaStream3Sr(addr) getRegField(addr->ISR, 0xFUL, 8)
#define clrDmaStream3Sr(addr, x) setRegField(addr->IFCR, 0xFUL, x, 8)
#define getDmaStream4Sr(addr) getRegField(addr->ISR, 0xFUL, 12)
#define clrDmaStream4Sr(addr, x) setRegField(addr->IFCR, 0xFUL, x, 12)
#define getDmaStream5Sr(addr) getRegField(addr->ISR, 0xFUL, 16)
#define clrDmaStream5Sr(addr, x) setRegField(addr->IFCR, 0xFUL, x, 16)
#define getDmaStream6Sr(addr) getRegField(addr->ISR, 0xFUL, 20)
#define clrDmaStream6Sr(addr, x) setRegField(addr->IFCR, 0xFUL, x, 20)
#define getDmaStream7Sr(addr) getRegField(addr->ISR, 0xFUL, 24)
#define clrDmaStream7Sr(addr, x) setRegField(addr->IFCR, 0xFUL, x, 24)

#endif

#endif