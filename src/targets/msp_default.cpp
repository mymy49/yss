////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <yss.h>
#include <cmsis/cmsis_compiler.h>

void initializeSystem(void);
void initializeSdram(void);

void initializeLheap(void);
void initializeCheap(void);

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
		// 시스템 클럭 및 외부 메모리를 초기화 한다.
		// 각 MCU마다 initializeSystem() 함수가 정의되어 있다.
		// 현재 파일의 하위 폴더에 제조사 별로 구분되어 작성되어 있다.
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE)
		initializeSystem();
#endif

#if YSS_L_HEAP_USE == true
		// 사용자가 정의한 SDRAM 설정 함수 호출
		initializeSdram();

		// SDRAM의 Heap 영역 메모리 관리 변수 초기화
		initializeLheap();
#endif
#if YSS_C_HEAP_USE == true
		// Core Coupled Memory의 Heap 영역 메모리 관리 변수 초기화
		yss::initializeCheap();
#endif
	}
}

#if YSS_L_HEAP_USE == true
void __WEAK initializeSdram(void)
{
}
#endif

void __WEAK initDma(void)
{
}
