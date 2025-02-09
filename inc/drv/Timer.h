/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_TIMER__H_
#define YSS_DRV_TIMER__H_

#include "peripheral.h"

#if defined(NRF52840_XXAA)

typedef NRF_TIMER_Type		YSS_TIMER_Dev;

#elif defined(EFM32PG22) || defined(EFR32BG22)

typedef TIMER_TypeDef		YSS_TIMER_Dev;

#elif defined(STM32F4) || defined(STM32F7) || defined(STM32F0) || defined(GD32F1) || defined(STM32F1) || defined(STM32G4)

typedef TIM_TypeDef			YSS_TIMER_Dev;

#elif defined(W7500)

typedef PWM_TypeDef			YSS_TIMER_Dev;

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

typedef TIMER_T				YSS_TIMER_Dev;

#else

typedef volatile uint32_t YSS_TIMER_Dev;

#define YSS_DRV_TIMER_UNSUPPORTED

#endif

#include "Drv.h"
#include <yss/error.h>

/*
	MCU의 기본 타이머를 사용하는 장치의 드라이버 입니다.
	MCU의 내장 장치로 향상된 타이머가 별도로 있는 경우 이 Timer에 포함되지 않습니다.
	향상된 타이머라고 하지만 타이머 기능에 대한 레지스터 맵이 동일할 경우는 포함될 수 있습니다.
*/
class Timer : public Drv
{
public:
	/*
		타이머를 주파수 기반으로 설정합니다.
		.
		@ freq : 타이머의 동작 주파수를 설정합니다. 타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
	*/
	error_t initialize(uint32_t freq) __attribute__((optimize("-O1")));

	/*
		타이머를 직접 분주비와 카운터의 TOP 값을 기반으로 설정합니다.
		.
		@ psc : 타이머의 분주비를 설정합니다. 
		@ top : 타이머 카운터의 TOP 값을 설정합니다.
		.
		STM32 : psc(0 ~ 65535), top(해당 타이머의 비트수의 최대 값).
		Wiznet W7500x : psc(0 ~ 63), top(0x00000000 ~ 0xFFFFFFFF).
		Nuvoton M4xx : psc(0 ~ 255), top(0x000000 ~ 0xFFFFFF).
	*/
	error_t initialize(uint32_t psc, uint32_t top) __attribute__((optimize("-O1")));
	
	/*
		타이머의 ISR 함수를 등록합니다.
		ISR 함수에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
		yss.h 파일에서 문맥전환을 유발하는 함수 유형의 설명을 참고하세요.
		yss.h 파일에서 ISR 함수와 Callback 함수에 대한 구분 설명을 참고하세요. 
		.
		@ * isr : ISR 함수의 포인터를 설정합니다.
	*/
	void setUpdateIsr(void (*isr)(void)) __attribute__((optimize("-O1")));

	/*
		타이머를 1회만 동작하도록 설정합니다.
		initialize() 함수를 호출하기 전에 이 함수를 호출할 경우 효과가 무시 될 수 있습니다.
		그러므로 반드시 initialize() 함수를 호출하고 이후에 호출되야 합니다.
		initialize() 함수 호출후 기본값은 false 입니다.
		.
		@ en : 타이머를 1회 동작하도록 설정 할 경우 true를, 연속해서 계속 실행하게 할 경우 false를 설정합니다.
	*/
	void setOnePulse(bool en) __attribute__((optimize("-O1")));
	
	/*
		타이머의 카운터를 시작합니다.
	*/
	void start(void) __attribute__((optimize("-O1")));
	
	/*
		타이머의 카운터를 정지합니다.
	*/
	void stop(void) __attribute__((optimize("-O1")));
	
	/*
		타이머의 동작 주파수를 변경합니다.
		타이머가 동작중에 주파수 변경이 가능합니다.
		MCU에 따라 일시적으로 함수 내부에서 장치를 멈추게 하는 경우도 있습니다.
		.
		@ freq : 타이머의 동작 주파수를 설정합니다. 타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
	*/
	error_t changeFrequency(uint32_t freq) __attribute__((optimize("-O1")));

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	enum BIT
	{
		BIT_16,
		BIT_32
	};

	struct setup_t
	{
		YSS_TIMER_Dev *dev;
#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7) || defined(STM32G4) || defined(STM32F0)
		uint8_t bit;
#endif
#if defined(W7500)
		uint8_t index;
#endif
	};

	Timer(YSS_TIMER_Dev *config, const Drv::setup_t drvConfig) __attribute__((optimize("-O1")));

	Timer(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isrUpdate(void) __attribute__((optimize("-O1")));

	void initializeAsSystemRuntime(void) __attribute__((optimize("-O1")));

	uint32_t getCounterValue(void) __attribute__((optimize("-O1")));

	uint32_t getOverFlowCount(void) __attribute__((optimize("-O1")));

private :
	YSS_TIMER_Dev *mDev;
	void (*mIsrUpdate)(void);

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7) || defined(STM32G4) || defined(STM32F0)
	uint8_t mBit;
#endif
#if defined(W7500)
	uint8_t mIndex;
#endif
};

#endif

