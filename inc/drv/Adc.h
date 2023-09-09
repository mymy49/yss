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

#ifndef YSS_DRV_ADC__H_
#define YSS_DRV_ADC__H_

#include "peripheral.h"

#if defined(STM32F4) || defined(STM32F7) || defined(GD32F4)

#include <targets/st_gigadevice/define_adc_stm32_gd32f4_f7.h>

#define YSS_DRV_ADC_MAX_CH	18
typedef volatile uint32_t	YSS_ADC_Dev;

#elif defined(STM32F1)

#include <targets/st_gigadevice/define_adc_stm32_gd32f1.h>

#define YSS_DRV_ADC_MAX_CH	18
typedef volatile uint32_t	YSS_ADC_Dev;

#elif defined(GD32F1)

#define YSS_DRV_ADC_MAX_CH	18
typedef ADC_TypeDef			YSS_ADC_Dev;

#elif defined(STM32F4_N) || defined(STM32F7_N) || defined(STM32F0_N) || defined(STM32F1_N)

#define YSS_DRV_ADC_MAX_CH	18
typedef ADC_TypeDef			YSS_ADC_Dev;

#else

#define YSS_DRV_ADC_UNSUPPORTED
#define YSS_DRV_ADC_MAX_CH	0
typedef volatile uint32_t	YSS_ADC_Dev;

#endif

#include <drv/Drv.h>
#include <targets/common/define_adc_common.h>
#include <yss/error.h>

class Adc : public Drv
{
  public :
	// ADC 장치를 초기화 한다. 초기화만 했을 뿐, 장치는 정상적인 활성화 되어 있지 않다.
	// 
	// 반환
	//		에러를 반환한다.
	error initialize(void);

	// ADC 입력 채널을 추가한다. 단일 ADC 입력 채널을 추가한다.
	// 입력 채널의 해상도와 Low Pass Filter 레벨 설정이 가능하다.
	// 
	// uint8_t pin
	//		ADC 입력 핀의 고유번호를 설정한다.
	// uint8_t lpfLv
	//		Low Pass Filter 레벨을 설정한다. (define::adc::lpfLv::LV0 ~ LV20)
	// uint8_t bit
	//		ADC의 해상도를 설정한다. (define::adc::bit::BIT12 ~ BIT16)
	void add(uint8_t pin, uint8_t lpfLv = define::adc::lpfLv::LV0, uint8_t bit = define::adc::bit::BIT12);

	// ADC 결과 값을 얻어온다.
	// ADC는 설정된 샘플 시간과 Low Pass Filter 레벨에 의해 계속적으로 업데이트되며
	// 이 함수를 호출하는 시점의 마지막 ADC 결과 값이 반환된다.
	//
	// 반환
	//		설정된 pin의 ADC 결과값을 반환한다.
	// uint8_t pin
	//		결과값을 가져올 ADC Pin을 설정한다.
	uint16_t get(uint8_t pin);

#if defined(STM32F0_N)
	// 샘플 시간을 설정한다.
	// 
	// uint8_t sampleTime
	//		샘플 시간을 설정한다. 설정 값은 MCU의 개별 설정에 따라 각기 다르다.
	void setSampleTime(uint8_t sampleTime);
#elif defined(STM32F1_N) || defined(STM32F4_N) || defined(STM32F7_N) || defined(GD32F1)
	// 샘플 시간을 설정한다.
	// 
	// uint8_t pin
	//		샘플 시간을 설정할 ADC Pin을 설정한다. 
	// uint8_t sampleTime
	//		샘플 시간을 설정한다. 설정 값은 MCU의 개별 설정에 따라 각기 다르다.
	void setSampleTime(uint8_t pin, uint8_t sampleTime);
#endif

	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	struct Setup
	{
		YSS_ADC_Dev *dev;
	};

	Adc(YSS_ADC_Dev *dev, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void));

	Adc(const Drv::Setup drvSetup, const Setup setup);

	void isr(void);

private :
	YSS_ADC_Dev *mDev;
	int32_t mResult[YSS_DRV_ADC_MAX_CH];
	uint8_t mIndex;
	uint8_t mLpfLv[YSS_DRV_ADC_MAX_CH];
	uint8_t mChannel[YSS_DRV_ADC_MAX_CH];
	uint8_t mBit[YSS_DRV_ADC_MAX_CH];
	uint8_t mNumOfCh;
};

#endif
// ##### 초기화 방법 #####
//		- GPIO의 setAsAnalog()함수를 사용해 관련된 포트를 아날로그 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 장치의 설정을 초기화 한다.
//		- add() 함수를 사용해 ADC 입력 채널을 등록한다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다.

// ##### 초기화 예시 #####
/*
	gpioA.setAsAnalog(4); // GPIOA_4번 핀을 아닐로그 핀으로 설정
	
	adc1.enableClock();
	adc1.initialize();

	adc1.add(define::gpio::analog::PA4_ADC_IN4); // GPIOA_4번 핀을 등록

	adc1.enableInterrupt();
*/

// ##### ADC 결과 취득 방법 #####
//		- get() 함수를 사용해 언제든 ADC Result를 얻어올 수 있다.

// ##### ADC 결과 취득 예시 #####
/*
	uint16_t result = adc1.get(define::gpio::analog::PA4_ADC_IN4);
*/

// ##### 장치에 대한 기반 사항 #####
//		ADC 장치는 인터럽트로 동작을 한다. ADC 변환을 마치고 매 인터럽트 시마다 인터럽트 벡터에서 등록된 ADC 채널을 한번씩 순환 설정한다.
//		그러므로 각 채널의 ADC 샘플 주기는 전체 ADC 순환 주기와 같다. 샘플 주기 시간을 낮추기 위해서는 등록된 입력들에 대해 전부 샘플 시간을 줄여야 효과적이다.
//		ADC 샘플 주기에 민감한 입력의 경우 ADC 장치를 분리하는 것이 좋다. 
//		가령 저속으로 동작하는 채널은 ADC1에 다수를 넣고, 고속으로 동작하는 채널은 ADC2에 한개 또는 복수개의 소량을 넣는다.
//		ADC 결과는 add() 함수의 lpfLv 파라메터 영향을 받는다. 여기서 설정된 Low Pass Filter Level에 따라 Low Pass Filter가 적용되고 
//		설정 값에 따라 실제 값에 수렴하는 속도가 달라진다. 설정을 주파수가 아닌 레벨로 하는 이유는 처리 속도를 우선하기 위해서이다.

