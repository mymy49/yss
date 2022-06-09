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

#ifndef YSS_DRV_PWM__H_
#define YSS_DRV_PWM__H_

#include "mcu.h"

#if defined(GD32F10X_XD) || defined(GD32F10X_HD)

typedef TIMER_TypeDef		YSS_PWM_Peri;

#elif defined(STM32F1) || defined(STM32F4) || defined(STM32F7)

typedef TIM_TypeDef			YSS_PWM_Peri;

#else

#define YSS_DRV_PWM_UNSUPPORTED

#endif

#ifndef YSS_DRV_PWM_UNSUPPORTED

#include <drv/Drv.h>

namespace drv
{
class Pwm : public Drv
{
  protected:
	YSS_PWM_Peri *mPeri;
	unsigned int (*mGetClockFreq)(void);

  protected :
	virtual void initChannel(bool risingAtMatch = false) = 0;

  public:
	struct Config
	{
		YSS_PWM_Peri *peri;
		unsigned int (*getClockFreq)(void);
	};

	Pwm(const Drv::Config &drvConfig, const Config &config);

	void init(unsigned int freq, bool risingAtMatch = false);
	void init(unsigned int psc, unsigned int arr, bool risingAtMatch = false);
	void setOnePulse(bool en);

	void start(void);
	void stop(void);

	virtual unsigned int getTop(void) = 0;
	virtual void setRatio(float ratio) = 0;
	virtual void setCounter(int counter) = 0;
};

class PwmCh1 : public Pwm
{
  public:
	PwmCh1(const Drv::Config &drvConfig, const Pwm::Config &config);

	void initChannel(bool risingAtMatch = false);
	unsigned int getTop(void);
	void setRatio(float ratio);
	void setCounter(int counter);
};

class PwmCh2 : public Pwm
{
  public:
	PwmCh2(const Drv::Config &drvConfig, const Pwm::Config &config);

	void initChannel(bool risingAtMatch = false);
	unsigned int getTop(void);
	void setRatio(float ratio);
	void setCounter(int counter);
};

class PwmCh3 : public Pwm
{
  public:
	PwmCh3(const Drv::Config &drvConfig, const Pwm::Config &config);

	void initChannel(bool risingAtMatch = false);
	unsigned int getTop(void);
	void setRatio(float ratio);
	void setCounter(int counter);
};

class PwmCh4 : public Pwm
{
  public:
	PwmCh4(const Drv::Config &drvConfig, const Pwm::Config &config);

	void initChannel(bool risingAtMatch = false);
	unsigned int getTop(void);
	void setRatio(float ratio);
	void setCounter(int counter);
};

}

#endif

#endif
