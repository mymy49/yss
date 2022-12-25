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

#ifndef YSS_DRV_ADC__H_
#define YSS_DRV_ADC__H_

#include "mcu.h"
#include <stdint.h>

#if defined(STM32F4) || defined(STM32F7) || defined(GD32F4)

#include <targets/st_gigadevice/define_adc_stm32_gd32f4_f7.h>

#define YSS_DRV_ADC_MAX_CH	18
typedef volatile uint32_t	YSS_ADC_Peri;

#elif defined(GD32F1) || defined(STM32F1)

#include <targets/st_gigadevice/define_adc_stm32_gd32f1.h>

#define YSS_DRV_ADC_MAX_CH	18
typedef volatile uint32_t	YSS_ADC_Peri;

#else

#define YSS_DRV_ADC_UNSUPPORTED
#define YSS_DRV_ADC_MAX_CH	0
typedef volatile uint32_t	YSS_ADC_Peri;

#endif

#include <drv/Drv.h>
#include <targets/common/define_adc_common.h>

class Adc : public Drv
{
	YSS_ADC_Peri *mPeri;
	int32_t mResult[YSS_DRV_ADC_MAX_CH];
	uint8_t mIndex;
	uint8_t mLpfLv[YSS_DRV_ADC_MAX_CH];
	uint8_t mChannel[YSS_DRV_ADC_MAX_CH];
	uint8_t mBit[YSS_DRV_ADC_MAX_CH];
	uint8_t mNumOfCh;

  public:
	Adc(YSS_ADC_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void));

	// ADC 장치를 초기화 한다. 초기화만 했을 뿐, 장치는 정상적인 활성화 되어 있지 않다.
	// 
	// 반환
	//		초기화 성공 유무를 반환한다. 초기화 성공시 true를 반환한다.
	bool init(void);

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
	uint16_t get(uint8_t pin);
	void setSampleTime(uint8_t pin, uint8_t sampleTime);

	void isr(void);
};

#endif

