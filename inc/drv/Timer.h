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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

#else

typedef volatile uint32_t YSS_TIMER_Dev;

#define YSS_DRV_TIMER_UNSUPPORTED

#endif

#include "Drv.h"

class Timer : public Drv
{
public:
	// 타이머를 주파수 기반으로 설정합니다.
	//
	// uint32_t freq
	//		타이머의 동작 주파수를 설정합니다.
	//		타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
	void initialize(uint32_t freq) __attribute__((optimize("-O1")));

	// 타이머를 직접 분주비와 카운터의 TOP 값을 기반으로 설정합니다.
	//
	// uint32_t psc
	//		타이머의 분주비를 설정합니다.
	//		STM32의 분주비는 1 ~ 65536까지 설정 가능합니다. (CLK / psc)
	//		Wiznet W7500x의 경우 0 ~ 63까지 설정 가능합니다. (CLK / (psc+1))
	// uint32_t top
	//		타이머 카운터의 TOP 값을 설정합니다.
	//		STM32의 TOP 값은 해당 타이머의 지원 비트에 따라 다릅니다.
	//		Wiznet W7500x의 경우 0xFFFFFFFF 까지 지원 됩니다.
	void initialize(uint32_t psc, uint32_t top) __attribute__((optimize("-O1")));
	
	// 타이머의 ISR 함수를 등록합니다.
	// ISR 함수에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
	// yss.h 파일에서 문맥전환을 유발하는 함수 유형의 설명을 참고하세요.
	// yss.h 파일에서 ISR 함수와 Callback 함수에 대한 구분 설명을 참고하세요. 
	//
	// void (*isr)(void)
	//		ISR 함수의 포인터를 설정합니다.
	void setUpdateIsr(void (*isr)(void)) __attribute__((optimize("-O1")));

	// 타이머를 1회만 동작하도록 설정합니다.
	// initialize() 함수를 호출하기 전에 이 함수를 호출할 경우 효과가 무시 될 수 있습니다.
	// 그러므로 반드시 initialize() 함수를 호출하고 이후에 호출되야 합니다.
	// 
	// bool en
	//		타이머를 1회만 설정하게 할 경우 true를 계속 실행하게 할 경우 false를 설정합니다.
	void setOnePulse(bool en) __attribute__((optimize("-O1")));
	
	// 타이머의 카운터를 시작합니다.
	void start(void) __attribute__((optimize("-O1")));
	
	// 타이머의 카운터를 정지합니다.
	void stop(void) __attribute__((optimize("-O1")));
	
	// 타이머의 동작 주파수를 변경합니다.
	// 타이머가 동작중에 주파수 변경이 가능합니다.
	// MCU에 따라 일시적으로 함수 내부에서 장치를 멈추게 하는 경우도 있습니다.
	//
	// uint32_t freq
	//		타이머의 동작 주파수를 설정합니다.
	//		타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
	void changeFrequency(uint32_t freq) __attribute__((optimize("-O1")));

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

