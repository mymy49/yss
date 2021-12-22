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
//  Copyright 2021.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_UART_ST_TYPE_B_REG__H_
#define YSS_DRV_UART_ST_TYPE_B_REG__H_

#include <yss/reg.h>

#define getUsartTxEmpty(addr) getRegBit(addr->SR, 7)

#define setUsartDr(addr, x) addr->DR = (char)x

#define setUsartBrr(addr, man, fra)        \
	setRegField(addr->BRR, 0xfff, man, 4); \
	setRegField(addr->BRR, 0xf, fra, 0)

#define setUsartRxEn(addr, x) setRegBit(addr->CR1, x, 2)
#define setUsartTxEn(addr, x) setRegBit(addr->CR1, x, 3)
#define setUsartRxneiEn(addr, x) setRegBit(addr->CR1, x, 5)
#define setUsartTxeiEn(addr, x) setRegBit(addr->CR1, x, 7)
#define setUsartEn(addr, x) setRegBit(addr->CR1, x, 13)
#define getUsartEn(addr) getRegBit(addr->CR1, 13)
#define setUsartOver8(addr, x) setRegBit(addr->CR1, x, 15)
#define setUsartDmaRxEn(addr, x) setRegBit(addr->CR3, x, 6)
#define setUsartDmaTxEn(addr, x) setRegBit(addr->CR3, x, 7)

#endif
