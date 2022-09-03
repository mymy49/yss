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

#ifndef YSS_DRV_CAPTURE__H_
#define YSS_DRV_CAPTURE__H_

#include "mcu.h"

#if defined(GD32F1)

typedef volatile unsigned int		YSS_CAPTURE_Peri;

#elif defined(STM32F1) || defined(STM32F4)

typedef TIM_TypeDef			YSS_PWM_Peri;

#else

#define YSS_DRV_CAPTURE_UNSUPPORTED

#endif

#ifndef YSS_DRV_CAPTURE_UNSUPPORTED

#include <drv/Drv.h>

class Capture : public Drv
{
  protected:
	YSS_CAPTURE_Peri *mPeri;
	void (*mIsr)(unsigned int cnt, unsigned long long accCnt);
	unsigned long long *mUpdateCnt, mLastUpdateCnt;
	unsigned int mLastCcr;

	virtual void initChannel(unsigned char option) = 0;

  public:
	struct Config
	{
		YSS_CAPTURE_Peri *peri;
		unsigned long long *updateCnt;
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
	void isrCapture(signed int ccr, bool update);
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
  protected :
  	void initChannel(unsigned char option);

  public:
	CaptureCh2(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void isrCapture(bool update);
	void setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
};

class CaptureCh3 : public Capture
{
  protected :
	void initChannel(unsigned char option);

  public:
	CaptureCh3(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void isrCapture(bool update);
	void setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
};

class CaptureCh4 : public Capture
{
  protected :
	void initChannel(unsigned char option);

  public:
	CaptureCh4(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void isrCapture(bool update);
	void setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
};

#endif

#endif
