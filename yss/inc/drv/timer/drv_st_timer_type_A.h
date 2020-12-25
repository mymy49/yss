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

#ifndef	YSS_DRV_TIMER_ST_TYPE_A__H_
#define	YSS_DRV_TIMER_ST_TYPE_A__H_

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) ||                                                 \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                                                                 \
    defined(STM32F429xx) || defined(STM32F439xx) ||                                                                                                 \
    defined(STM32F100xB) || defined(STM32F100xE) ||                                                                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) ||                                                 \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) ||                                                 \
    defined(STM32F105xC) ||                                                                                                                         \
    defined(STM32F107xC) ||                                                                                                                         \
    defined(STM32G431xx) || defined(STM32G441xx) ||                                                                                                 \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB) || \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) ||                                                 \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                                                                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                                                                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                                                                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx) ||                                                                         \
    defined(STM32L412xx) || defined(STM32L422xx) ||                                                                                                 \
    defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx) ||                         \
    defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) ||                                                                         \
    defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) ||                         \
    defined(STM32L496xx) || defined(STM32L4A6xx) ||                                                                                                 \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx) ||                                                                                                 \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

#include <config.h>
#include <yss/mcu.h>
#include <drv/Drv.h>
#include "drv_st_timer_type_A_define.h"

namespace drv
{
	class Timer : public Drv
	{
		TIM_TypeDef *mPeri;
		unsigned long long mTimeUpdateCnt, mLastUpdateCnt1, mLastUpdateCnt2, mLastUpdateCnt3, mLastUpdateCnt4;
		unsigned int mLastCcr1, mLastCcr2, mLastCcr3, mLastCcr4;
		unsigned int (*mGetClockFreq)(void);
		void (*mIsrUpdate)(void);
		void (*mIsrInputCapture1)(unsigned int cnt, unsigned long long accCnt);
		void (*mIsrInputCapture2)(unsigned int cnt, unsigned long long accCnt);
		void (*mIsrInputCapture3)(unsigned int cnt, unsigned long long accCnt);
		void (*mIsrInputCapture4)(unsigned int cnt, unsigned long long accCnt);

		void isrInputCapture(void);

	public :
		Timer(TIM_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned int (*getClockFreq)(void));

		void setUpdateIsr(void (*isr)(void));
		void setInputCapture1Isr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
		void setInputCapture2Isr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
		void setInputCapture3Isr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
		void setInputCapture4Isr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
	
		void init(unsigned int freq);
		void init(unsigned int psc, unsigned int arr);
		void start(void);
		void stop(void);
		void setOnePulse(bool en);

		void setUpdateIntEn(bool en);
		void setCC1IntEn(bool en);
		void setCC2IntEn(bool en);
		void setCC3IntEn(bool en);
		void setCC4IntEn(bool en);

		void initInputCaptureCh1(unsigned char option = define::timer::inputCapture::RISING_EDGE);
		void initInputCaptureCh2(unsigned char option = define::timer::inputCapture::RISING_EDGE);
		void initInputCaptureCh3(unsigned char option = define::timer::inputCapture::RISING_EDGE);
		void initInputCaptureCh4(unsigned char option = define::timer::inputCapture::RISING_EDGE);

		void initPwmCh1(bool risingAtMatch = true);
		void initPwmCh2(bool risingAtMatch = true);
		void initPwmCh3(bool risingAtMatch = true);
		void initPwmCh4(bool risingAtMatch = true);

		void setPwmCh1(float ratio);
		void setPwmCh2(float ratio);
		void setPwmCh3(float ratio);
		void setPwmCh4(float ratio);

		unsigned long long getCaptureUpdateCntCh1(void);
		unsigned long long getCaptureUpdateCntCh2(void);
		unsigned long long getCaptureUpdateCntCh3(void);
		unsigned long long getCaptureUpdateCntCh4(void);

		void initSystemTime(void);
		unsigned int getClockFreq(void);

		void isrUpdate(void);
		void isrCC1(bool event);
		void isrCC2(bool event);
		void isrCC3(bool event);
		void isrCC4(bool event);

		unsigned int getCounterValue(void);
		unsigned int getOverFlowCount(void);
	};
}

#if defined(TIM1_ENABLE) && defined(TIM1)
extern drv::Timer timer1;
#endif

#if defined(TIM2_ENABLE) && defined(TIM2)
extern drv::Timer timer2;
#endif

#if defined(TIM3_ENABLE) && defined(TIM3)
extern drv::Timer timer3;
#endif

#if defined(TIM4_ENABLE) && defined(TIM4)
extern drv::Timer timer4;
#endif

#if defined(TIM5_ENABLE) && defined(TIM5)
extern drv::Timer timer5;
#endif

#if defined(TIM6_ENABLE) && defined(TIM6)
extern drv::Timer timer6;
#endif

#if defined(TIM7_ENABLE) && defined(TIM7)
extern drv::Timer timer7;
#endif

#if defined(TIM8_ENABLE) && defined(TIM8)
extern drv::Timer timer8;
#endif

#if defined(TIM9_ENABLE) && defined(TIM9)
extern drv::Timer timer9;
#endif

#if defined(TIM10_ENABLE) && defined(TIM10)
extern drv::Timer timer10;
#endif

#if defined(TIM11_ENABLE) && defined(TIM11)
extern drv::Timer timer11;
#endif

#if defined(TIM12_ENABLE) && defined(TIM12)
extern drv::Timer timer12;
#endif

#if defined(TIM13_ENABLE) && defined(TIM13)
extern drv::Timer timer13;
#endif

#if defined(TIM14_ENABLE) && defined(TIM14)
extern drv::Timer timer14;
#endif

#if defined(TIM15_ENABLE) && defined(TIM15)
extern drv::Timer timer15;
#endif

#if defined(TIM16_ENABLE) && defined(TIM16)
extern drv::Timer timer14;
#endif

#if defined(TIM17_ENABLE) && defined(TIM17)
extern drv::Timer timer17;
#endif

#endif

#endif
