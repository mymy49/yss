/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_CLOCK_STM32G4__H_
#define YSS_CLASS_CLOCK_STM32G4__H_

#include <yss/error.h>
#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/Mutex.h>

#if defined(STM32G474xx)
#define PLL_USE
#define PLL_P_USE
#define PLL_Q_USE
#define PLL_R_USE
#elif defined(STM32G431xx)
#define PLL_USE
#define PLL_P_USE
#define PLL_Q_USE
#define PLL_R_USE
#endif

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
	error enableHse(uint32_t hseHz, bool useBypass = false);
	
	// 전원 스케일 설정 값을 읽어옵니다.
	// 이 설정은 MCU의 최대 동작 속도에 중요한 설정 값입니다.
	// 반환
	//		설정된 전원 스케일 값을 반환합니다.
	uint8_t getPowerScale(void);

	// 전원 스케일 설정 값을 읽어옵니다.
	// 이 설정은 MCU의 최대 동작 속도에 중요한 설정 값입니다.
	// 반환
	//		에러를 반환합니다.
	error setPowerScale(uint8_t scale);
	
	// SYSCLK 클럭을 읽어옵니다.
	//
	// 반환
	//		SYSCLK 클럭을 읽어옵니다.
	uint32_t getSystemClockFrequency(void);

	// AHB1 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		AHB1 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		AHB1 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableAhb1Clock(uint32_t position, bool en = true);
	
	// AHB1 버스 장치를 리셋합니다.
	//
	// uint32_t position
	//		AHB2 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetAhb1(uint32_t position);

	// AHB2 버스의 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		AHB2 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		AHB2 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableAhb2Clock(uint32_t position, bool en = true);

	// AHB2 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		AHB2 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetAhb2(uint32_t position);

	// AHB3 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		AHB3 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		AHB3 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableAhb3Clock(uint32_t position, bool en = true);

	// AHB3 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		AHB3 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetAhb3(uint32_t position);

	// AHB 클럭을 읽어옵니다.
	//
	// 반환
	//		SYSCLK 클럭을 읽어옵니다.
	uint32_t getAhbClockFrequency(void);

	// APB1_1 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		APB1_1 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		APB1_1 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableApb1_1Clock(uint32_t position, bool en = true);

	// APB1_1 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		APB1_1 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetApb1_1(uint32_t position);

	// APB1_2 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		APB1_2 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		APB1_2 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableApb1_2Clock(uint32_t position, bool en = true);

	// APB1_2 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		APB1_2 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetApb1_2(uint32_t position);

	// APB1 버스 클럭을 읽어옵니다.
	//
	// 반환
	//		APB1 버스의 클럭을 반환합니다.
	uint32_t getApb1ClockFrequency(void);

	// APB2 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		APB2 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		APB2 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableApb2Clock(uint32_t position, bool en = true);

	// APB2 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		APB2 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetApb2(uint32_t position);

	// APB2 버스 클럭을 읽어옵니다.
	//
	// 반환
	//		APB2 버스의 클럭을 반환합니다.
	uint32_t getApb2ClockFrequency(void);

#if defined(PLL_USE)
	// 주 PLL을 활성화 합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// uint8_t pllsrc
	//		PLL 입력 클럭의 소스를 설정합니다. 설정 가능한 항목은 "define::clock::pll::src"를 참고하세요. 
	// uint8_t m
	//		PLL 입력 클럭의 분주비를 설정합니다. 
	//		STM32G474xx에서 설정 가능한 범위는 1 ~ 16입니다. 
	// uint16_t n
	//		PLL 클럭의 증폭 배율을 설정합니다. 
	//		STM32G474xx에서 설정 가능한 범위는 8 ~ 127입니다. 
	// uint8_t pdiv
	//		PLL_P 클럭의 출력 분주비를 설정합니다. 설정 가능한 항목은 "define::clock::pll::pdiv"를 참고하세요. 
	// uint8_t qDiv
	//		PLL_Q 클럭의 출력 분주비를 설정합니다. 설정 가능한 항목은 "define::clock::pll::qdiv"를 참고하세요. 
	// uint8_t rDiv
	//		PLL_R 클럭의 출력 분주비를 설정합니다. 설정 가능한 항목은 "define::clock::pll::rdiv"를 참고하세요. 
	error enableMainPll(uint8_t pllsrc, uint8_t m, uint16_t n, uint8_t pdiv, uint8_t qDiv, uint8_t rDiv);

#if defined(PLL_P_USE)
	// 주 PLL의 PLLP 클럭 주파수를 읽어옵니다.
	//
	// 반환
	//		주 PLL의 PLLP 클럭 주파수를 반환합니다.
	uint32_t getMainPllPFrequency(void);
#endif

#if defined(PLL_Q_USE)
	// 주 PLL의 PLLQ 클럭 주파수를 읽어옵니다.
	//
	// 반환
	//		주 PLL의 PLLQ 클럭 주파수를 반환합니다.
	uint32_t getMainPllQFrequency(void);
#endif

#if defined(PLL_R_USE)
	// 주 PLL의 PLLR 클럭 주파수를 읽어옵니다.
	//
	// 반환
	//		주 PLL의 PLLR 클럭 주파수를 반환합니다.
	uint32_t getMainPllRFrequency(void);
#endif
#endif

	// SysClk의 클럭 소스와 AHB, APB의 분주비를 설정합니다.
	// 
	// 반환
	//		발생한 에러를 반환합니다.
	// uint8_t sysclkSrc
	//		SysClk의 클럭 소스를 설정합니다.
	//		설정 가능한 항목은 "define::clock::sysclk::ahb"를 참고하세요. 
	// uint8_t ahbDiv
	//		AHB의 분주비를 설정합니다.
	//		설정 가능한 항목은 "define::clock::sysclk::ahbDiv"를 참고하세요. 
	// uint8_t apb1Div
	//		APB1의 분주비를 설정합니다.
	//		설정 가능한 항목은 "define::clock::sysclk::apbDiv"를 참고하세요. 
	// uint8_t apb2Div
	//		APB2의 분주비를 설정합니다.
	//		설정 가능한 항목은 "define::clock::sysclk::apbDiv"를 참고하세요. 
	error setSysclk(uint8_t sysclkSrc, uint8_t ahbDiv, uint8_t apb1Div, uint8_t apb2Div);

private:
};

#endif