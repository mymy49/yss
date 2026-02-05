/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_EADC__H_
#define YSS_DRV_NUVOTON_EADC__H_

#include <drv/Adc.h>

class NuvotonEadc : public Adc
{
public :
	typedef struct
	{
		EADC_T *dev;
	}setup_t;

	NuvotonEadc(const Drv::setup_t drvSetup, const setup_t setup);

	virtual error_t initialize(uint8_t numOfChannel);
	
	virtual error_t add(uint8_t ch, lpfLv_t lpflv, bit_t bit);

	/*
		add() 함수를 통해 등록된 채널의 순서에 따른 index 번호를 지정하여 ADC의 컨버전이 시작에 대한 지연 클럭을 설정합니다.
		EADC의 SCTL 레지스터에서 div 인자는 TRGDLYDIV 필드에 count 인자는 TRGDLYCNT에 대응합니다. 정확한 설정 값은 데이터시트를 참고하시기 바랍니다.
		.
		@ index : add() 함수를 통해 등록된 채널 순서의 인덱스를 지정합니다.
		@ div : ADC 입력 클럭의 분주비를 설정합니다.
		@ count : Delay 카운트를 설정합니다.
	*/
	void setConversionStartDelay(uint8_t index, uint8_t div, uint8_t count);

	virtual error_t convert(bool en);

	void isr(void);

private :
	EADC_T *mDev;
	uint32_t mSwTrigger;
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

