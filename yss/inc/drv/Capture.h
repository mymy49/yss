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

#ifndef YSS_DRV_CAPTURE__H_
#define YSS_DRV_CAPTURE__H_

#include "mcu.h"

#if defined(GD32F10X_XD) || defined(GD32F10X_HD)

typedef TIMER_TypeDef		YSS_PWM_Peri;

#elif defined(STM32F1) || defined(STM32F4)

typedef TIM_TypeDef			YSS_PWM_Peri;

#else

#define YSS_DRV_CAPTURE_UNSUPPORTED

#endif

#ifndef YSS_DRV_CAPTURE_UNSUPPORTED

#include <drv/Drv.h>

namespace drv
{
class Capture : public Drv
{
  protected:
	YSS_PWM_Peri *mPeri;
	unsigned int (*mGetClockFreq)(void);
	void (*mIsr)(unsigned int cnt, unsigned long long accCnt);
	unsigned long long mUpdateCnt, mLastUpdateCnt;
	unsigned int mLastCcr;

	virtual void initChannel(unsigned char option) = 0;

  public:
	struct Config
	{
		YSS_PWM_Peri *peri;
		unsigned int (*getClockFreq)(void);
	};

	enum
	{
		RISING_EDGE = 0x01,
		FALLING_EDGE = 0x02
	};

	Capture(const Drv::Config &drvConfig, const Config &config);

	void init(unsigned int psc, unsigned char option = RISING_EDGE);

	void start(void);
	void stop(void);
	void isrUpdate(void);
	unsigned int getSourceFrequency(void);

	virtual void isrCapture(bool update) = 0;
	virtual void setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt)) = 0;
};

class CaptureCh1 : public Capture
{
  protected :
  	void initChannel(unsigned char option);

  public:
	CaptureCh1(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void isrCapture(bool update);
	void setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
};

class CaptureCh2 : public Capture
{
  public:
	CaptureCh2(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void initChannel(unsigned char option);
	void isrCapture(bool update);
	void setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
};

class CaptureCh3 : public Capture
{
  public:
	CaptureCh3(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void initChannel(unsigned char option);
	void isrCapture(bool update);
	void setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
};

class CaptureCh4 : public Capture
{
  public:
	CaptureCh4(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void initChannel(unsigned char option);
	void isrCapture(bool update);
	void setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
};

}

#endif

#endif
