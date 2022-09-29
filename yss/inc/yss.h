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

#ifndef YSS_SYSTEM__H_
#define YSS_SYSTEM__H_

#include "yss/gui.h"
#include "yss/instance.h"
#include "yss/thread.h"
#include "yss/malloc.h"

// Core의 클럭 주파수를 반환한다.
uint32_t getCoreClockFrequency(void);

// AHB 버스 클럭 주파수를 반환한다.
uint32_t getAhbClockFrequency(void);

// APB1 버스 클럭 주파수를 반환한다.
uint32_t getApb1ClockFrequency(void);

// APB2 버스 클럭 주파수를 반환한다.
uint32_t getApb2ClockFrequency(void);

// 이순신 OS의 스케줄러, 뮤텍스와 MCU의 DMA, 외부 인터럽트 등을 활성화 한다.
void initYss(void);

#if defined(DMA2D) && USE_EVENT == true
void setEvent(Position pos, uint8_t event);
#endif

#if USE_GUI == true && YSS_L_HEAP_USE == true
void setSystemFrame(Frame &obj);
void setSystemFrame(Frame *obj);
Ltdc::Specification *getLcdSpec(void);
#endif

#endif