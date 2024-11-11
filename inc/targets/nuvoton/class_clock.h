/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_CLOCK_M48X__H_
#define YSS_CLASS_CLOCK_M48X__H_

#include <yss/error.h>
#include <drv/mcu.h>
#include <yss/Mutex.h>
#include <stdint.h>

class Clock : public Mutex
{
public:
	// External High Speed Crystal Oscilator를 활성화 합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// uint32_t hseHz
	//		외부 크리스털의 주파수를 HZ 단위로 입력합니다.
	// useBypass = false
	//		입력이 크리스탈일 경우에는 false로 설정합니다.
	//		입력이 오실레이터일 경우나 클럭 소스를 직접 입력 받을 경우 bypass를 true로 설정합니다.
	error_t enableHxt(uint32_t hseHz) __attribute__((optimize("-O1")));
	
	// High Internal speed Osilator의 주파수를 얻습니다.
	// 
	// 반환
	//		Hirc 오실레이터의 주파수를 반환 합니다.
	uint32_t getHircFrequency(void) __attribute__((optimize("-O1")));

	// External High Speed Crystal Oscilator의 주파수를 얻습니다.
	// 
	// 반환
	//		외부 오실레이터의 주파수를 반환 합니다.
	uint32_t getHxtFrequency(void) __attribute__((optimize("-O1")));

	// Internal High speed Osilator의 주파수를 얻습니다.
	// 
	// 반환
	//		Hirc 오실레이터의 주파수를 반환 합니다.
	uint32_t getLircFrequency(void) __attribute__((optimize("-O1")));

	// PLL의 주파수를 얻습니다.
	// 
	// 반환
	//		PLL의 주파수를 반환 합니다.
	uint32_t getPllFrequency(void) __attribute__((optimize("-O1")));

	// HCLK 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		HCLK 클럭의 주파수를 반환합니다.
	uint32_t getHclkClockFrequency(void) __attribute__((optimize("-O1")));

	// APB0 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		APB0 클럭의 주파수를 반환합니다.
	uint32_t getApb0ClockFrequency(void) __attribute__((optimize("-O1")));

	// APB1 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		APB1 클럭의 주파수를 반환합니다.
	uint32_t getApb1ClockFrequency(void) __attribute__((optimize("-O1")));

	// PLL 클럭 소스
	typedef enum
	{
		PLL_SRC_HXT = 0,
		PLL_SRC_HIRC,
	}pllSrc_t;
	
	// PLL을 활성화 합니다. 출력 주파수는 아래의 식과 같습니다.
	// FOUT = FIN x (2 x (fbdiv + 2)) / NO
	// 위 식에서 NO는 아래와 같이 outdiv의 값에 의해 결정 됩니다.
	// outdiv == 0, NO = 1
	// outdiv == 1 또는 outdiv == 2, NO = 2
	// outdiv == 3, NO = 4
	//
	// 반환
	//		에러를 반환합니다.
	// uint8_t indiv
	//		입력 클럭 분주기입니다. (0 ~ 63)
	// uint16_t fbdiv
	//		PLL 배수기입니다. (0 ~ 512)
	// uint8_t outdiv
	//		출력 클럭 분주기 입니다. (0~3)
	error_t enablePll(pllSrc_t src, uint8_t indiv, uint16_t fbdiv, uint8_t outdiv) __attribute__((optimize("-O1")));

	// HCLK 클럭 소스
	typedef enum
	{
		HCLK_SRC_HXT = 0,
		HCLK_SRC_LXT,
		HCLK_SRC_PLL,
		HCLK_SRC_LRIC,
		HCLK_SRC_HIRC,
	}hclkSrc_t;

	// HCLK의 클럭 소스를 선택합니다. 이 함수 내부에서 Flash의 Access Cycle 설정이 자동으로 이뤄집니다. 
	//
	// 반환
	//		에러를 반환합니다.
	// hclkSrc_t src
	//		HCLK의 클럭럭 소스를 설정합니다.
	// uint8_t hclkDiv
	//		HCLK의 분주비를 설정합니다. PLL이 소스일 경우 반드시 0으로 설정해야 합니다. 
	// uint8_t pclk0Div
	//		PCLK0의 분주비를 설정합니다. HCLK의 주파수로 부터 분주됩니다. 
	//		M483에서 주파수가 96MHz를 넘으면 안됩니다.
	// uint8_t pclk1Div
	//		PCLK1의 분주비를 설정합니다. HCLK의 주파수로 부터 분주됩니다.
	//		M483에서 주파수가 96MHz를 넘으면 안됩니다.
	error_t setHclkClockSource(hclkSrc_t src, uint8_t hclkDiv, uint8_t pclk0Div, uint8_t pclk1Div) __attribute__((optimize("-O1")));

	// AHB 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		AHB 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		AHB 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableAhbClock(uint32_t position, bool en = true) __attribute__((optimize("-O1")));

	// APB0 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		APB0 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		APB0 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableApb0Clock(uint32_t position, bool en = true) __attribute__((optimize("-O1")));

	// APB1 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		APB1 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		APB1 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableApb1Clock(uint32_t position, bool en = true) __attribute__((optimize("-O1")));

private:
};

#endif