/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_EPWM__H_
#define YSS_DRV_EPWM__H_

#include "peripheral.h"

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

typedef EPWM_T				YSS_EPWM_Peri;

#else

#define YSS_DRV_BPWM_UNSUPPORTED

#endif

#ifndef YSS_DRV_BPWM_UNSUPPORTED

#include "Drv.h"
#include <yss/error.h>

/*
	Nuvoton MCU의 EPWM 장치 지원 드라이버 입니다.
*/
class Epwm : public Drv
{
public:
	/*
		EPWM 채널의 출력 주기를 주파수 기반으로 설정합니다.
		타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ freq : PWM 출력 주기의 주파수를 설정합니다. 
	*/
	error_t initialize(uint8_t ch, uint32_t freq) __attribute__((optimize("-O1")));

	/*
		EPWM의 출력 주기의 주파수를 변경합니다.
		BPWM이 동작중에 주파수 변경이 가능합니다.
		MCU에 따라 일시적으로 함수 내부에서 장치를 멈추게 하는 경우도 있습니다.
		타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ freq : BPWM 출력 주기의 주파수를 설정합니다.
	*/
	error_t changeFrequency(uint8_t ch, uint32_t freq) __attribute__((optimize("-O1")));

	/*
		EPWM 채널의 클럭 주파수를 얻습니다.
		.
		@ return : EPWM의 채널 0, 1의 클럭 주파수를 반환합니다.
	*/
	uint32_t getClockFrequency01(void) __attribute__((optimize("-O1")));
	
	/*
		EPWM의 설정된 채널의 카운터를 시작합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ ch (0 ~ 5) : 시작할 채널을 설정합니다.
	*/
	error_t start(uint8_t ch) __attribute__((optimize("-O1")));
	
	/*
		EPWM의 카운터를 정지합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ ch (0 ~ 5) : 정지할 채널을 설정합니다.
	*/
	error_t stop(uint8_t ch) __attribute__((optimize("-O1")));

	/*
		EPWM 카운터의 TOP 값을 얻습니다.
		.
		@ return : PWM 카운터의 TOP 값을 반환합니다.
		.
		@ ch (0 ~ 5) : TOP 값을 얻을 채널을 설정합니다.
	*/
	uint32_t getTopValue(uint8_t ch) __attribute__((optimize("-O1")));
	
	/*	
		EPWM의 출력 비율을 설정합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ ch (0 ~ 5) : 변경할 채널을 설정합니다.
		@ ratio : PWM의 출력 비율을 설정합니다.
	*/
	error_t setDutyRatio(uint8_t ch, float ratio) __attribute__((optimize("-O1")));
	
	/*
		EPWM의 출력 비교 레지스터의 값을 직접 설정합니다.
		getTopValue() 함수를 통해 최대값을 구하고 직접 출력 비교 레지스터를 설정하여 PWM의 출력 비를 설정합니다. 
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ ch (0 ~ 5) : 변경할 채널을 설정합니다.
		@ counter : PWM의 출력 비교 레지스터 값을 설정합니다.
	*/
	error_t setCompareValue(uint8_t ch, int16_t  counter) __attribute__((optimize("-O1")));

	/*
		EPWM의 채널을 일반 PWM 출력으로 설정합니다. UP Count를 기반으로 Zero에 High, Match에 Low로 전환하는 출력을 생성합니다.
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
		YSS_EPWM_Peri *dev;
		uint32_t (*getClock01Func)(void);
		uint32_t (*getClock23Func)(void);
		uint32_t (*getClock45Func)(void);
	};

	Epwm(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

  protected:
	YSS_EPWM_Peri *mDev;
	uint32_t (*mGetClock01Func)(void);
	uint32_t (*mGetClock23Func)(void);
	uint32_t (*mGetClock45Func)(void);
};

/* EPWM0 초기화 예제 코드
	// EPWM0 초기화
	gpioA.setAsAltFunc(5, Gpio::PA5_EPWM0_CH0);
	gpioA.setAsAltFunc(4, Gpio::PA4_EPWM0_CH1);
	gpioA.setAsAltFunc(3, Gpio::PA3_EPWM0_CH2);
	gpioA.setAsAltFunc(2, Gpio::PA2_EPWM0_CH3);
	gpioA.setAsAltFunc(1, Gpio::PA1_EPWM0_CH4);
	gpioA.setAsAltFunc(0, Gpio::PA0_EPWM0_CH5);

	epwm0.enableClock();			// EPWM0의 클럭 활성화
	
	// CH0 초기화
	epwm0.initialize(0, 1000);		// EPWM0 채널0의 출력 주기를 1kHz로 초기화
	epwm0.setAsPwmOutput(0, true);	// EPWM0 채널0을 PWM 반전 출력으로 설정
	epwm0.start(0);					// EPWM0 채널0의 타이머 카운터 시작
	epwm0.setDutyRatio(0, 0.1);		// EPWM0 채널0의 출력 듀티비를 10%로 설정

	// CH1 초기화
	epwm0.initialize(1, 1000);		// EPWM0 채널1의 출력 주기를 1kHz로 초기화
	epwm0.setAsPwmOutput(1);		// EPWM0 채널1을 PWM 비반전 출력으로 설정
	epwm0.start(1);					// EPWM0 채널1의 타이머 카운터 시작
	epwm0.setDutyRatio(1, 0.2);		// EPWM0 채널1의 출력 듀티비를 20%로 설정

	// CH2 초기화
	epwm0.initialize(2, 1000);		// EPWM0 채널2의 출력 주기를 1kHz로 초기화
	epwm0.setAsPwmOutput(2);		// EPWM0 채널2를 PWM 비반전 출력으로 설정
	epwm0.start(2);					// EPWM0 채널2의 타이머 카운터 시작
	epwm0.setDutyRatio(2, 0.3);		// EPWM0 채널2의 출력 듀티비를 30%로 설정

	// CH3 초기화
	epwm0.initialize(3, 1000);		// EPWM0 채널3의 출력 주기를 1kHz로 초기화
	epwm0.setAsPwmOutput(3);		// EPWM0 채널3을 PWM 비반전 출력으로 설정
	epwm0.start(3);					// EPWM0 채널3의 타이머 카운터 시작
	epwm0.setDutyRatio(3, 0.4);		// EPWM0 채널3의 출력 듀티비를 40%로 설정

	// CH4 초기화
	epwm0.initialize(4, 1000);		// EPWM0 채널4의 출력 주기를 1kHz로 초기화
	epwm0.setAsPwmOutput(4);		// EPWM0 채널4를 PWM 비반전 출력으로 설정
	epwm0.start(4);					// EPWM0 채널4의 타이머 카운터 시작
	epwm0.setDutyRatio(4, 0.5);		// EPWM0 채널4의 출력 듀티비를 50%로 설정
	
	// CH5 초기화
	epwm0.initialize(5, 1000);		// EPWM0 채널5의 출력 주기를 1kHz로 초기화
	epwm0.setAsPwmOutput(5);		// EPWM0 채널5를 PWM 비반전 출력으로 설정
	epwm0.start(5);					// EPWM0 채널5의 타이머 카운터 시작
	epwm0.setDutyRatio(5, 0.6);		// EPWM0 채널5의 출력 듀티비를 60%로 설정
*/
#endif

#endif

