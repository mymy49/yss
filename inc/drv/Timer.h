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

#ifndef YSS_DRV_TIMER__H_
#define YSS_DRV_TIMER__H_

#include "peripheral.h"

#if defined(STM32F1) || defined(STM32F4) || defined(GD32F4) || defined(STM32F7) || defined(STM32L1) || defined(STM32F0) || defined(STM32G4)

typedef volatile uint32_t	YSS_TIMER_Dev;

#elif defined(NRF52840_XXAA)

typedef NRF_TIMER_Type		YSS_TIMER_Dev;

#elif defined(EFM32PG22) || defined(EFR32BG22)

typedef TIMER_TypeDef		YSS_TIMER_Dev;

#elif defined(STM32F4_N) || defined(STM32F7_N) || defined(STM32F0_N) || defined(GD32F1) || defined(STM32F1_N)

typedef TIM_TypeDef			YSS_TIMER_Dev;

#else

typedef volatile uint32_t YSS_TIMER_Dev;

#define YSS_DRV_TIMER_UNSUPPORTED

#endif

#include "Drv.h"

class Timer : public Drv
{
public:
	void initialize(uint32_t freq);

	void initialize(uint32_t psc, uint32_t arr);

	void initializeAsSystemRuntime(void);

	void setUpdateIsr(void (*isr)(void));

	void setOnePulse(bool en);

	void start(void);

	void stop(void);

	uint32_t getClockFreq(void);

	void changeFrequency(uint32_t freq);

	// usec 또는 msec 단위의 카운트 값을 얻는다.
	// 시스템의 시계를 관리하기 위한 목적으로 만들어진 함수로 사용자 호출에 특별한 의미는 없다.
	//
	// 반환
	//		usec 또는 msec 단위의 타이머 카운트 값
	uint32_t getCounterValue(void);

	uint32_t getOverFlowCount(void);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	enum BIT
	{
		BIT_16,
		BIT_32
	};

	struct Setup
	{
		YSS_TIMER_Dev *dev;
		uint8_t bit;
	};

	Timer(YSS_TIMER_Dev *config, const Drv::Config drvConfig);

	Timer(const Drv::Setup drvSetup, const Setup setup);

	void isrUpdate(void);

private :
	YSS_TIMER_Dev *mDev;
	uint8_t mBit;
	uint64_t mTimeUpdateCnt;
	void (*mIsrUpdate)(void);

	void isrInputCapture(void);
};

#define setUpdateIntEn		enableInterrupt

#endif
