/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_CLOCK_W7500__H_
#define YSS_CLASS_CLOCK_W7500__H_

#include <yss/error.h>
#include <drv/mcu.h>
#include <yss/Mutex.h>
#include "define_w7500x.h"

class Clock : public Mutex
{
public:
	// 외부 HSE 크리스탈을 활성화 합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// uint32_t hseHz
	//		외부 크리스털의 주파수를 HZ 단위로 입력합니다.
	// useBypass = false
	//		입력이 크리스탈일 경우에는 false로 설정합니다.
	//		입력이 오실레이터일 경우나 클럭 소스를 직접 입력 받을 경우 bypass를 true로 설정합니다.
	error_t enableOsc(uint32_t hseHz) __attribute__((optimize("-O1")));
	
	// 내부 RC 오실레이터의 주파수를 얻습니다.
	// 
	// 반환
	//		RC 오실레이터의 주파수를 반환 합니다.
	uint32_t getRclkFrequency(void) __attribute__((optimize("-O1")));

	// 외부 오실레이터의 주파수를 얻습니다.
	// 
	// 반환
	//		외부 오실레이터의 주파수를 반환 합니다.
	uint32_t getOclkFrequency(void) __attribute__((optimize("-O1")));

	// PLL의 출력 주파수(MCLK)를 얻습니다.
	// 
	// 반환
	//		MCLK 주파수를 반환 합니다.
	uint32_t getMclkFrequency(void) __attribute__((optimize("-O1")));

	// System Clock 주파수(FCLK)를 얻습니다.
	// 
	// 반환
	//		FCLK 주파수를 반환 합니다.
	uint32_t getFclkFrequency(void) __attribute__((optimize("-O1")));

	// 
	typedef enum
	{
		PLL_SRC_RCLK = 0,
		PLL_SRC_OCLK,
	}pllSrc_t;

	error_t setPllFrequency(pllSrc_t src, uint8_t m, uint8_t n, uint8_t od) __attribute__((optimize("-O1")));

private:
};

#endif