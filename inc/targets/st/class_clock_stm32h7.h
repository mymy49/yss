/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_CLOCK_STM32H7__H_
#define YSS_CLASS_CLOCK_STM32H7__H_

#include <yss/error.h>
#include <drv/peripheral.h>
#include <yss/Mutex.h>

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
	error_t enableHse(uint32_t hseHz, bool useBypass = false) __attribute__((optimize("-O1")));
	
	typedef enum
	{
		VOS_SCALE_0 = 0,
		VOS_SCALE_3,
		VOS_SCALE_2,
		VOS_SCALE_1,
	}vos_t;
	
	// Voltage scaling 값을 변경합니다.
	// 이 설정은 MCU의 최대 동작 클럭 주파수에 영향을 미칩니다.
	//
	// 반환
	//		에러를 반환합니다.
	// vos_t vos
	//		Voltage Scaling의 값을 설정합니다.
	error_t setVoltageScaling(vos_t vos) __attribute__((optimize("-O1")));

	typedef enum
	{
		PLL_SRC_HSI = 0,
		PLL_SRC_CSI,
		PLL_SRC_HSE,
	}pllsrc_t;
	
	// 전체 PLL의 소스 클럭을 설정합니다.
	// PLL1, PLL2, PLL3을 설정하기 전에 반드시 올바른 클럭 소스를 설정해야 합니다.
	//
	// 반환
	//		에러를 반환합니다.
	// pllsrc_t pllsrc
	//		PLL 입력 클럭의 소스를 설정합니다.
	error_t setPllSource(pllsrc_t pllsrc);

	// PLL1을 활성화 합니다. 
	// PLL2, PLL3을 활성화 하기 전에 반드시 PLL1이 먼저 활성화 되어야 합니다.
	// PLL의 VCOSEL 설정은 내부에서 자동으로 설정 됩니다.
	//
	// 반환
	//		에러를 반환합니다.
	// uint8_t m
	//		PLL 입력 클럭의 분주비를 설정합니다. 
	//		STM32H723xx에서 설정 가능한 범위는 0 ~ 63입니다. 
	//		만약 0일 경우 prescaler가 비활성화 되고, 그 외의 경우는 clk / m 이 됩니다.
	// uint16_t n
	//		PLL 클럭의 증폭 배율을 설정합니다. 
	//		STM32H723xx에서 설정 가능한 범위는 3 ~ 511입니다.
	// uint8_t pdiv
	//		PLL_P 클럭의 출력 분주비를 설정합니다. 
	//		STM32H723xx에서 설정 가능한 범위는 0 ~ 127입니다.
	//		PLL_P의 출력 주파수 계산 : pll_p = f_src / m * (n + 1) / (pDiv + 1)
	// uint8_t qDiv
	//		PLL_Q 클럭의 출력 분주비를 설정합니다.
	//		STM32H723xx에서 설정 가능한 범위는 0 ~ 127입니다.
	//		PLL_Q의 출력 주파수 계산 : pll_q = f_src / m * (n + 1) / (qDiv + 1)
	// uint8_t rDiv
	//		PLL_R 클럭의 출력 분주비를 설정합니다. 설정 가능한 항목은 "define::clock::pll::rdiv"를 참고하세요. 
	//		STM32H723xx에서 설정 가능한 범위는 0 ~ 127입니다.
	//		PLL_R의 출력 주파수 계산 : pll_r = f_src / m * (n + 1) / (rDiv + 1)
	error_t enablePll1(uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv) __attribute__((optimize("-O1")));

private:
	static uint32_t mHseFreq __attribute__((section(".non_init")));

};

#endif