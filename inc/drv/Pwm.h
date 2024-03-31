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

#ifndef YSS_DRV_PWM__H_
#define YSS_DRV_PWM__H_

#include "peripheral.h"

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F7) || defined(STM32F4) || defined(STM32G4)

typedef TIM_TypeDef			YSS_PWM_Peri;

#elif defined(W7500)

typedef PWM_TypeDef			YSS_PWM_Peri;

#else

#define YSS_DRV_PWM_UNSUPPORTED

#endif

#ifndef YSS_DRV_PWM_UNSUPPORTED

#include "Drv.h"
#include <yss/error.h>

class Pwm : public Drv
{
public:
	// PWM의 출력 주기를 주파수 기반으로 설정합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// uint32_t freq
	//		PWM 출력 주기의 주파수를 설정합니다.
	//		타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
	error_t initialize(uint32_t freq, bool risingAtMatch = false) __attribute__((optimize("-O1")));

	// PWM을 직접 분주비와 카운터의 TOP 값을 기반으로 설정합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// uint32_t psc
	//		PWM의 분주비를 설정합니다.
	//		STM32의 분주비는 1 ~ 65536까지 설정 가능합니다. (CLK / psc)
	//		Wiznet W7500x의 경우 0 ~ 63까지 설정 가능합니다. (CLK / (psc+1))
	// uint32_t top
	//		PWM 카운터의 TOP 값을 설정합니다.
	//		STM32의 TOP 값은 해당 타이머의 지원 비트에 따라 다릅니다.
	//		Wiznet W7500x의 경우 0xFFFFFFFF 까지 지원 됩니다.
	error_t initialize(uint32_t psc, uint32_t top, bool risingAtMatch = false) __attribute__((optimize("-O1")));

	// PWM의 출력 주기의 주파수를 변경합니다.
	// PWM이 동작중에 주파수 변경이 가능합니다.
	// MCU에 따라 일시적으로 함수 내부에서 장치를 멈추게 하는 경우도 있습니다.
	//
	// uint32_t freq
	//		PWM 출력 주기의 주파수를 설정합니다.
	//		타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
	void changeFrequency(uint32_t freq) __attribute__((optimize("-O1")));

	// PWM의 펄스를 1회만 생성하도록 설정합니다.
	// initialize() 함수를 호출하기 전에 이 함수를 호출할 경우 효과가 무시 될 수 있습니다.
	// 그러므로 반드시 initialize() 함수를 호출하고 이후에 호출되야 합니다.
	// 
	// bool en
	//		타이머를 1회만 설정하게 할 경우 true를 계속 실행하게 할 경우 false를 설정합니다.
	void setOnePulse(bool en) __attribute__((optimize("-O1")));

	// PWM의 카운터를 시작합니다.
	void start(void) __attribute__((optimize("-O1")));

	// PWM의 카운터를 정지합니다.
	void stop(void) __attribute__((optimize("-O1")));
	
	// PWM 카운터의 TOP 값을 얻습니다.
	//
	// 반환
	//		PWM 카운터의 TOP 값을 반환합니다.
	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1"))) = 0;
	
	// PWM의 출력 비율을 설정합니다.
	//
	// float ratio
	//		PWM의 출력 비율을 설정합니다.
	virtual void setRatio(float ratio) __attribute__((optimize("-O1"))) = 0;

	// PWM의 출력 비교 레지스터의 값을 직접 설정합니다.
	// getTopValue() 함수를 통해 최대값을 구하고 직접 출력 비교 레지스터를 설정하여 PWM의 출력 비를 설정합니다. 
	//
	// int32_t counter
	//		PWM의 출력 비교 레지스터 값을 설정합니다.
	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1"))) = 0 ;

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	struct setup_t
	{
		YSS_PWM_Peri *dev;
#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7) || defined(STM32G4) || defined(STM32F0)
		uint8_t bit;
#endif
#if defined(W7500)
		uint8_t index;
#endif
	};

	Pwm(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	Pwm(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

  protected:
	YSS_PWM_Peri *mDev;

#if defined(W7500)
	uint8_t mIndex;
	bool mRisingAtMatch;
#endif

	virtual error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1"))) = 0;
};

class PwmCh1 : public Pwm
{
  public:
	error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1")));

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1")));

	virtual void setRatio(float ratio) __attribute__((optimize("-O1")));

	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1")));

	PwmCh1(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	PwmCh1(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1"))) __attribute__((optimize("-O1")));
};

class PwmCh2 : public Pwm
{
  public:
	error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1")));

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1")));

	virtual void setRatio(float ratio) __attribute__((optimize("-O1")));

	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1")));

	PwmCh2(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	PwmCh2(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));
};

class PwmCh3 : public Pwm
{
  public:
	error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1")));

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1")));

	virtual void setRatio(float ratio) __attribute__((optimize("-O1")));

	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1")));

	PwmCh3(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	PwmCh3(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));
};

class PwmCh4 : public Pwm
{
  public:
	error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1")));

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1")));

	virtual void setRatio(float ratio) __attribute__((optimize("-O1")));

	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1")));

	PwmCh4(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	PwmCh4(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));
};

#endif

#endif

