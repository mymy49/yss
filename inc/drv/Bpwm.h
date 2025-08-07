/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_BPWM__H_
#define YSS_DRV_BPWM__H_

#include "peripheral.h"

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

typedef BPWM_T				YSS_BPWM_Peri;

#else

#define YSS_DRV_BPWM_UNSUPPORTED

#endif

#ifndef YSS_DRV_BPWM_UNSUPPORTED

#include "Drv.h"
#include <yss/error.h>

/*
	Nuvoton MCU의 BPWM 장치 지원 드라이버 입니다.
*/
class Bpwm : public Drv
{
public:
	/*
		BPWM의 출력 주기를 주파수 기반으로 설정합니다.
		타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ freq : PWM 출력 주기의 주파수를 설정합니다. 
	*/
	error_t initialize(uint32_t freq) __attribute__((optimize("-O1")));

	/*
		BPWM의 출력 주기의 주파수를 변경합니다.
		BPWM이 동작중에 주파수 변경이 가능합니다.
		MCU에 따라 일시적으로 함수 내부에서 장치를 멈추게 하는 경우도 있습니다.
		타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ freq : BPWM 출력 주기의 주파수를 설정합니다.
	*/
	error_t changeFrequency(uint32_t freq) __attribute__((optimize("-O1")));
	
	/*
		BPWM의 카운터를 시작합니다.
	*/
	void start(void) __attribute__((optimize("-O1")));
	
	/*
		BPWM의 카운터를 정지합니다.
	*/
	void stop(void) __attribute__((optimize("-O1")));

	/*
		BPWM 카운터의 TOP 값을 얻습니다.
		.
		@ return : PWM 카운터의 TOP 값을 반환합니다.
	*/
	uint32_t getTopValue(void) __attribute__((optimize("-O1")));
	
	/*	
		BPWM의 출력 비율을 설정합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ ch (0 ~ 5) : 변경할 채널을 설정합니다.
		@ ratio : PWM의 출력 비율을 설정합니다.
	*/
	error_t setDutyRatio(uint8_t ch, float ratio) __attribute__((optimize("-O1")));
	
	/*
		BPWM의 출력 비교 레지스터의 값을 직접 설정합니다.
		getTopValue() 함수를 통해 최대값을 구하고 직접 출력 비교 레지스터를 설정하여 PWM의 출력 비를 설정합니다. 
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ ch (0 ~ 5) : 변경할 채널을 설정합니다.
		@ counter : PWM의 출력 비교 레지스터 값을 설정합니다.
	*/
	error_t setCompareValue(uint8_t ch, int16_t  counter) __attribute__((optimize("-O1")));

	/*
		BPWM의 채널을 일반 PWM 출력으로 설정합니다. UP Count를 기반으로 Zero에 High, Match에 Low로 전환하는 출력을 생성합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ ch (0 ~ 5) : 변경할 채널을 설정합니다.
		@ inverse : true로 설정시 Match에 High로 전환하는 파형을 설정합니다. (반전)
	*/
	error_t setAsPwmOutput(uint8_t ch, bool inverse = false);

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	struct setup_t
	{
		YSS_BPWM_Peri *dev;
	};

	Bpwm(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

  protected:
	YSS_BPWM_Peri *mDev;
};

/* BPWM0 초기화 예제 코드
	// bpwm0 초기화
	gpioA.setAsAltFunc(11, Gpio::PA11_BPWM0_CH0);	// PA11을 BPWM0 CH0으로 설정
	gpioA.setAsAltFunc(10, Gpio::PA10_BPWM0_CH1);	// PA10을 BPWM0 CH1으로 설정
	gpioA.setAsAltFunc(9, Gpio::PA9_BPWM0_CH2);		// PA9을 BPWM0 CH2으로 설정
	gpioA.setAsAltFunc(8, Gpio::PA8_BPWM0_CH3);		// PA8을 BPWM0 CH3으로 설정

	bpwm0.enableClock();							// BPWM0의 클럭 활성화
	bpwm0.initialize(1000);							// BPWM0의 출력 주기를 1kHz로 초기화
	bpwm0.setAsPwmOutput(0, true);					// BPWM0의 CH0을 PWM 반전 출력으로 설정
	bpwm0.setAsPwmOutput(1);						// BPWM0의 CH1을 PWM 비반전 출력으로 설정
	bpwm0.setAsPwmOutput(2);						// BPWM0의 CH2을 PWM 비반전 출력으로 설정
	bpwm0.setAsPwmOutput(3);						// BPWM0의 CH3을 PWM 비반전 출력으로 설정
	bpwm0.start();									// 타이머 카운터 시작

	bpwm0.setDutyRatio(0, 0.1);						// BPWM0 CH0의 출력 듀티비를 10%로 설정
	bpwm0.setDutyRatio(1, 0.2);						// BPWM0 CH0의 출력 듀티비를 20%로 설정
	bpwm0.setDutyRatio(2, 0.3);						// BPWM0 CH0의 출력 듀티비를 30%로 설정
	bpwm0.setDutyRatio(3, 0.4);						// BPWM0 CH0의 출력 듀티비를 40%로 설정
*/
#endif

#endif

