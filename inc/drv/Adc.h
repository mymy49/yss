/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_ADC__H_
#define YSS_DRV_ADC__H_

#include "Drv.h"
#include <yss/error.h>

#include <drv/Drv.h>
#include <yss/error.h>

/*
	ADC 장치의 드라이버 입니다.
	하나의 ADC로 시분할 하여 각 채널을 ADC 합니다.
	입력 채널의 해상도와 Low Pass Filter 레벨 설정이 가능합니다.
	Low Pass Filter 레벨은 정량적이지 않습니다. MCU 실행 성능에 큰 영향을 미치지 않도록 하기 위한 조치입니다.
	상대적으로 동작 상태를 보고 적당한 레벨로 선택해서 사용합니다.
	Low Pass Filter가 적용되어 있을 경우 물리적인 ADC 해상도 보다 높은 해상도를 근사치로 만들어 냅니다.
*/
class Adc : public Drv
{
public :
	typedef enum
	{
		LPF_LV0 = 0,
		LPF_LV1,
		LPF_LV2,
		LPF_LV3,
		LPF_LV4,
		LPF_LV5,
		LPF_LV6,
		LPF_LV7,
		LPF_LV8,
		LPF_LV9,
		LPF_LV10,
		LPF_LV11,
		LPF_LV12,
		LPF_LV13,
		LPF_LV14,
		LPF_LV15,
		LPF_LV16,
		LPF_LV17,
		LPF_LV18,
		LPF_LV19,
		LPF_LV20
	}lpfLv_t;

	typedef enum
	{
		RES_BIT12 = 19,
		RES_BIT13 = 18,
		RES_BIT14 = 17,
		RES_BIT15 = 16,
		RES_BIT16 = 15,
	}bit_t;

	typedef struct
	{
		int32_t result;
		lpfLv_t lpfLevel;
		bit_t bit;
	}channel_t;

	/*
		ADC 장치를 초기화 합니다. 초기화만 했을 뿐, 장치는 정상적인 활성화가 되어 있지 않습니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ numOfChannel : 동작할 ADC 채널의 개수를 설정합니다. 설정된 개수만큼 heap에서 메모리를 할당합니다.
	*/
	virtual error_t initialize(uint8_t numOfChannel) = 0;

	/*
		ADC 입력 채널을 추가합니다. 한번에 하나의 입력 채널이 추가됩니다.
		.
		@ ch : 동작시킬 채널의 설정입니다.
	*/
	virtual error_t add(uint8_t ch, lpfLv_t lpflv, bit_t bit) = 0;
	
	/*
		ADC 변환을 동작하거나 중단하게 만듭니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ en : true일 경우 변환 동작, false일 경우 변환 중지됩니다.
	*/
	virtual error_t convert(bool en) = 0;

	/*
		설정된 channel의 ADC 결과 값을 반환합니다.
		.
		@ return : ADC 결과 값을 반환합니다.
		.
		@ index : ADC 결과값을 가져올 채널의 등록 순번을 설정합니다.
	*/
	int32_t getResult(uint8_t index);


	Adc(const Drv::setup_t drvSetup);

protected :
	channel_t *mChannel;
	uint8_t mConvertingIndex;
	uint8_t mChCount, mMaxChCount;

	error_t malloc(uint8_t numOfCh);
};

#endif

// ##### 초기화 방법 #####
//		- GPIO의 setAsAnalog()함수를 사용해 관련된 포트를 아날로그 포트로 변경합니다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급합니다.
//		- initialize() 함수를 사용해 장치의 설정을 초기화 합니다.
//		- add() 함수를 사용해 ADC 입력 채널을 등록합니다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 합니다.
//		- convert() 함수를 사용해 컨버팅 동작을 실행합니다.

// ##### 초기화 예시 #####
/*
	gpioA.setAsAnalog(4); // GPIOA_4번 핀을 아닐로그 핀으로 설정
	
	adc1.enableClock();
	adc1.initialize();

	adc1.add(define::gpio::analog::PA4_ADC_IN4); // GPIOA_4번 핀을 등록

	adc1.enableInterrupt();
	convert(true);
*/

// ##### ADC 결과 취득 방법 #####
//		- get() 함수를 사용해 언제든 ADC Result를 얻어올 수 있다.

// ##### ADC 결과 취득 예시 #####
/*
	uint16_t result = adc1.get(4);
*/

// ##### 장치에 대한 기반 사항 #####
//		ADC 장치는 인터럽트로 동작을 한다. ADC 변환을 마치고 매 인터럽트 시마다 인터럽트 벡터에서 등록된 ADC 채널을 한번씩 순환 설정한다.
//		그러므로 각 채널의 ADC 샘플 주기는 전체 ADC 순환 주기와 같다. 샘플 주기 시간을 낮추기 위해서는 등록된 입력들에 대해 전부 샘플 시간을 줄여야 효과적이다.
//		ADC 샘플 주기에 민감한 입력의 경우 ADC 장치를 분리하는 것이 좋다. 
//		가령 저속으로 동작하는 채널은 ADC1에 다수를 넣고, 고속으로 동작하는 채널은 ADC2에 한개 또는 복수개의 소량을 넣는다.
//		ADC 결과는 add() 함수의 lpfLv 파라메터 영향을 받는다. 여기서 설정된 Low Pass Filter Level에 따라 Low Pass Filter가 적용되고 
//		설정 값에 따라 실제 값에 수렴하는 속도가 달라진다. 설정을 주파수가 아닌 레벨로 하는 이유는 처리 속도를 우선하기 위해서이다.

