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

#ifndef YSS_DRV_TIMER__H_
#define YSS_DRV_TIMER__H_

#include "mcu.h"

#if false

#include "timer/define_timer_stm32f1_f4_f7_g4.h"

typedef TIM_TypeDef		YSS_TIMER_Peri;

#elif defined(GD32F1) || defined(STM32F1) || defined(STM32F4) || defined(GD32F4) || defined(STM32F7)

typedef volatile uint32_t YSS_TIMER_Peri;

#elif defined(NRF52840_XXAA)

typedef NRF_TIMER_Type		YSS_TIMER_Peri;

#else

#define YSS_DRV_TIMER_UNSUPPORTED

#endif

#ifndef YSS_DRV_TIMER_UNSUPPORTED

#include "Drv.h"

class Timer : public Drv
{
	YSS_TIMER_Peri *mPeri;
	uint64_t mTimeUpdateCnt;
	void (*mIsrUpdate)(void);

	void isrInputCapture(void);

  public:
	Timer(YSS_TIMER_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), uint32_t (*getClockFreq)(void));
	Timer(YSS_TIMER_Peri *peri, const Drv::Config drvConfig);

	void init(uint32_t freq);
	void init(uint32_t psc, uint32_t arr);
	void initSystemTime(void);

	void setUpdateIsr(void (*isr)(void));
	void enableUpdateInterrupt(bool en = true);
	void setOnePulse(bool en);

	void start(void);
	void stop(void);

	uint32_t getClockFreq(void);
	uint32_t getCounterValue(void);
	uint32_t getOverFlowCount(void);

	void isrUpdate(void);
};

#define setUpdateIntEn		enableInterrupt

#endif

#endif
