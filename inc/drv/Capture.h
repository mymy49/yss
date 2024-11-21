/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CAPTURE__H_
#define YSS_DRV_CAPTURE__H_

#include "peripheral.h"

#if defined(STM32F7) || defined(GD32F1) || defined(STM32F1) || defined(STM32F4) 

typedef TIM_TypeDef			YSS_CAPTURE_Peri;

#else

#define YSS_DRV_CAPTURE_UNSUPPORTED
typedef volatile uint32_t	YSS_CAPTURE_Peri;

#endif

#include "Drv.h"

class Capture : public Drv
{
public:
	typedef enum
	{
		EDGE_RISING = 0,
		EDGE_FALLING
	}edge_t;

	// Capture 장치를 초기화 한다.
	// Capture 장치에 공급되는 주파수의 분주비와 감지되는 엣지의 설정이 가능하다.
	//
	// uint32_t psc
	//		장치에 공급되는 주파수의 분주비를 설정한다.
	// uint8_t option
	//		감지되는 엣지를 설정한다.
	void initialize(uint32_t psc, edge_t option = EDGE_RISING);
	
	// Capture를 시작한다.
	void start(void);

	// Capture를 중단한다.
	void stop(void);
	
	// Capture 인터럽트 서비스 루틴을 등록한다.
	// ISR에서는 문맥전환을 유발하는 함수를 호출하면 안된다.
	virtual void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt)) = 0;

	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	void isrUpdate(void);

	void isrCapture(int32_t ccr, bool update);

	uint32_t getSourceFrequency(void);

	virtual void isrCapture(bool update) = 0;

	typedef struct
	{
		YSS_CAPTURE_Peri *peri;
		uint64_t *updateCnt;
	}setup_t;

	Capture(const Drv::setup_t &drvSetup, const setup_t &setup);

protected:
	YSS_CAPTURE_Peri *mPeri;

	void (*mIsr)(uint32_t cnt, uint64_t accCnt);

	uint64_t *mUpdateCnt, mLastUpdateCnt;

	uint32_t mLastCcr;

	virtual void initializeChannel(uint8_t option) = 0;
};

// 아래 정의된 클래스는 하나의 Capture 장치에서 각각의 채널을 대응하기 위해 만든 클래스이다.
class CaptureCh1 : public Capture
{
public:
	CaptureCh1(const Drv::setup_t &drvSetup, const Capture::setup_t &setup);
	
	void isrCapture(bool update);

	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));

protected :
  	virtual void initializeChannel(uint8_t option); // virtual 0
};

class CaptureCh2 : public Capture
{
  public:
	CaptureCh2(const Drv::setup_t &drvSetup, const Capture::setup_t &setup);
	
	void isrCapture(bool update);

	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));

protected :
  	virtual void initializeChannel(uint8_t option); // virtual 0
};

class CaptureCh3 : public Capture
{
  public:
	CaptureCh3(const Drv::setup_t &drvSetup, const Capture::setup_t &setup);
	
	void isrCapture(bool update);

	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));

protected :
  	virtual void initializeChannel(uint8_t option); // virtual 0
};

class CaptureCh4 : public Capture
{
  public:
	CaptureCh4(const Drv::setup_t &drvSetup, const Capture::setup_t &setup);
	
	void isrCapture(bool update);

	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));

protected :
  	virtual void initializeChannel(uint8_t option); // virtual 0
};

#endif

// 초기화 방법
//		- GPIO의 setAsAltFunc() 함수를 사용해 관련된 포트를  Capture(Timer) 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 분주비와 감지 엣지를 설정하고 장치를 초기화 한다.
//		- setIsr() 함수를 사용해 캡쳐에 대한 인터럽트 서비스 루틴을 등록한다.
//		- start() 함수를 사용해 카운터를 동작 시킨다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다.

// 사용 방법
//		- setIsr()을 통해 등록된 인터럽트 서비스 루틴은 Capture 포트에 설정된 엣지가 감지 되면 호출된다.
//		- uint32_t cnt는 직전 감지가 된 후부터 이번 감지된 때까지 증가된 카운트의 양이다.
//		- 직전 감지된 엣지와 이번에 감지된 엣지 사이의 증가된 카운트 값을 직접 목적하는 계산에 활용하면 된다.
//		- uint64_t accCnt는 현재까지 누적된 전체 카운트 값을 나타낸다. 필요에 따라 해당 값을 활용하면 된다.
