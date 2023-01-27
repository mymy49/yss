////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.1
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CAPTURE__H_
#define YSS_DRV_CAPTURE__H_

#include "mcu.h"

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4) ||  defined(STM32F7)

typedef volatile uint32_t	YSS_CAPTURE_Peri;

#else

#define YSS_DRV_CAPTURE_UNSUPPORTED
typedef volatile uint32_t	YSS_CAPTURE_Peri;

#endif

#include "Drv.h"

class Capture : public Drv
{
  public:
	struct Config
	{
		YSS_CAPTURE_Peri *peri;
		uint64_t *updateCnt;
	};

	enum
	{
		RISING_EDGE = 0x01,
		FALLING_EDGE = 0x02
	};

	Capture(const Drv::Config &drvConfig, const Config &config);
	
	// Capture 장치를 초기화 한다.
	// Capture 장치에 공급되는 주파수의 분주비와 감지되는 엣지의 설정이 가능하다.
	//
	// uint32_t psc
	//		장치에 공급되는 주파수의 분주비를 설정한다.
	// uint8_t option
	//		감지되는 엣지를 설정한다.
	void init(uint32_t psc, uint8_t option = RISING_EDGE);
	
	// Capture를 시작한다.
	void start(void);

	// Capture를 중단한다.
	void stop(void);
	
	// Capture 인터럽트 서비스 루틴을 등록한다.
	// ISR에서는 문맥전환 함수를 유발하는 함수를 호출하면 안된다.
	virtual void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt)) = 0;

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	void isrUpdate(void);
	void isrCapture(int32_t ccr, bool update);
	uint32_t getSourceFrequency(void);
	virtual void isrCapture(bool update) = 0;

  protected:
	YSS_CAPTURE_Peri *mPeri;
	void (*mIsr)(uint32_t cnt, uint64_t accCnt);
	uint64_t *mUpdateCnt, mLastUpdateCnt;
	uint32_t mLastCcr;

	virtual void initChannel(uint8_t option) = 0;
};

// 아래 정의된 클래스는 하나의 Capture 장치에서 각각의 채널을 대응하기 위해 만든 클래스이다.
class CaptureCh1 : public Capture
{
  protected :
  	void initChannel(uint8_t option);

  public:
	CaptureCh1(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void isrCapture(bool update);
	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));
};

class CaptureCh2 : public Capture
{
  protected :
  	void initChannel(uint8_t option);

  public:
	CaptureCh2(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void isrCapture(bool update);
	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));
};

class CaptureCh3 : public Capture
{
  protected :
	void initChannel(uint8_t option);

  public:
	CaptureCh3(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void isrCapture(bool update);
	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));
};

class CaptureCh4 : public Capture
{
  protected :
	void initChannel(uint8_t option);

  public:
	CaptureCh4(const Drv::Config &drvConfig, const Capture::Config &config);
	
	void isrCapture(bool update);
	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));
};

#endif

// 초기화 방법
//		- GPIO의 setAsAltFunc()함수를 사용해 관련된 포트를  Capture(Timer) 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- 