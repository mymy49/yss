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

#include <config.h>
#include <yss.h>

void initSystem(void);
void initSdram(void);

void initLheap(void);
void initCheap(void);

extern uint32_t gCoreClockFrequency;
extern uint32_t gAhbClockFrequency;
extern uint32_t gApb1ClockFrequency;
extern uint32_t gApb2ClockFrequency;

#ifndef DEFAULT_CLOCK_SPEED
#define DEFAULT_CLOCK_SPEED 1000000
#endif

extern "C"
{
	void SystemInit(void)
	{
		// 클럭 저장 변수에 MCU의 부팅시 기본 클럭을 설정
		gCoreClockFrequency = DEFAULT_CLOCK_SPEED;
		gAhbClockFrequency = DEFAULT_CLOCK_SPEED;
		gApb1ClockFrequency = DEFAULT_CLOCK_SPEED;
		gApb2ClockFrequency = DEFAULT_CLOCK_SPEED;

		// 시스템 클럭 및 외부 메모리를 초기화 한다.
		// 각 MCU마다 initSystem() 함수가 정의되어 있다.
		// 현재 파일의 하위 폴더에 제조사 별로 구분되어 작성되어 있다.
		initSystem();

#if YSS_L_HEAP_USE == true
		// 사용자가 정의한 SDRAM 설정 함수 호출
		initSdram();

		// SDRAM의 Heap 영역 메모리 관리 변수 초기화
		initLheap();
#endif
#if YSS_C_HEAP_USE == true
		// Core Coupled Memory의 Heap 영역 메모리 관리 변수 초기화
		yss::initCheap();
#endif
	}
}

void __WEAK initSdram(void)
{
}

