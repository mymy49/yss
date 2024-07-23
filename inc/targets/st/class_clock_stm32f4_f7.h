/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_CLOCK_STM32_GD32F4_F7__H_
#define YSS_CLASS_CLOCK_STM32_GD32F4_F7__H_

#include <yss/error.h>
#include <drv/peripheral.h>
#include <yss/Mutex.h>

#if defined(STM32F429xx)
#define OVER_DRVIE_USE
#define PLL_USE
#define PLL_P_USE
#define PLL_Q_USE

#define I2SPLL_Q_USE
#define I2SPLL_R_USE

#define SAIPLL_USE
#define SAIPLL_Q_USE
#define SAIPLL_R_USE
#define GET_SAI1A_FREQ_USE
#define GET_SAI1B_FREQ_USE
#elif defined(STM32F767xx)
#define OVER_DRVIE_USE
#define PLL_USE
#define PLL_P_USE
#define PLL_Q_USE
#define PLL_R_USE

#define I2SPLL_Q_USE
#define I2SPLL_R_USE

#define SAIPLL_USE
#define SAIPLL_P_USE
#define SAIPLL_Q_USE
#define SAIPLL_R_USE
#define GET_SAI1A_FREQ_USE
#define GET_SAI1B_FREQ_USE
#elif defined(STM32F746xx)
#define OVER_DRVIE_USE
#define PLL_USE
#define PLL_P_USE
#define PLL_Q_USE

#define I2SPLL_P_USE
#define I2SPLL_Q_USE
#define I2SPLL_R_USE

#define SAIPLL_USE
#define SAIPLL_P_USE
#define SAIPLL_Q_USE
#define SAIPLL_R_USE
#define GET_SAI1A_FREQ_USE
#define GET_SAI1B_FREQ_USE
#elif defined(STM32F446xx)
#define OVER_DRVIE_USE
#define PLL_USE
#define PLL_P_USE
#define PLL_Q_USE
#define PLL_R_USE

#define I2SPLL_USE
#define I2SPLL_P_USE
#define I2SPLL_Q_USE
#define I2SPLL_R_USE
#define GET_I2S1_FREQ_USE
#define GET_I2S2_FREQ_USE
#define SET_I2S_CKIN_FREQ_USE

#define SAIPLL_USE
#define SAIPLL_P_USE
#define SAIPLL_Q_USE
#define GET_SAI1_FREQ_USE
#define GET_SAI2_FREQ_USE
//#define SET_I2S_CKIN_FREQ_USE
#elif defined(STM32F407xx)
#define PLL_USE
#define PLL_P_USE
#define PLL_Q_USE
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
	bool enableHse(uint32_t hseHz, bool useBypass = false);

	// 전원 스케일 설정 값을 읽어옵니다.
	// 이 설정은 MCU의 최대 동작 속도에 중요한 설정 값입니다.
	// 반환
	//		설정된 전원 스케일 값을 반환합니다.
	uint8_t getPowerScale(void);

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

	// AHB2 버스 장치의 클럭을 활성화 합니다.
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
	
	// APB1 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		APB1 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		APB1 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableApb1Clock(uint32_t position, bool en = true);

	// APB1 버스의 장치를 리셋합니다.
	//
	// uint32_t position
	//		APB1 버스의 리셋할 장치의 비트필드의 비트 번호를 설정합니다.
	void resetApb1(uint32_t position);

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
	// uint8_t vcc
	//		VCC 전압을 설정합니다. 전원 전압의 곱하기 10을 한 값이 사용됩니다.
	//		3.3V의 경우 33입니다.
	error_t setSysclk(uint8_t sysclkSrc, uint8_t ahbDiv, uint8_t apb1Div, uint8_t apb2Div, uint8_t vcc = 33);

	uint32_t getSystemClockFrequency(void);
	uint32_t getAhbClockFrequency(void);
	uint32_t getApb1ClockFrequency(void);
	uint32_t getApb2ClockFrequency(void);

#if defined(PLL_USE)
	bool enableMainPll(uint8_t pllsrc, uint8_t m, uint16_t n, uint8_t pllPdiv, uint8_t qDiv, uint8_t rDiv);
#if defined(PLL_P_USE)
	uint32_t getMainPllPFrequency(void);
#endif
#if defined(PLL_Q_USE)
	uint32_t getMainPllQFrequency(void);
#endif
#if defined(PLL_R_USE)
	uint32_t getMainPllRFrequency(void);
#endif
#endif

	// I2SPLL 관련
#if defined(I2SPLL_USE)

	bool enableI2sPll(uint16_t n, uint8_t m, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv);

#if defined(SET_I2S_CKIN_FREQ_USE)
	uint32_t setI2sCkinClockFrequency(void);
#endif

#if defined(GET_I2S1_FREQ_USE)
	void setI2s1ClockSource(uint8_t src);
	uint32_t getI2s1ClockFrequency(void);
#endif

#if defined(GET_I2S2_FREQ_USE)
	void setI2s2ClockSource(uint8_t src);
	uint32_t getI2s2ClockFrequency(void);
#endif

#if defined(I2SPLL_P_USE)
	uint32_t getI2sPllPFrequency(void);
#endif

#if defined(I2SPLL_Q_USE)
	uint32_t getI2sPllQFrequency(void);
#endif

#if defined(I2SPLL_R_USE)
	uint32_t getI2sPllRFrequency(void);
#endif
#endif

	// SAIPLL 관련
#if defined(SAIPLL_USE)

	bool enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv);

#if defined(GET_SAI1_FREQ_USE)
	void setSai1ClockSource(uint8_t src);
	uint32_t getSai1ClockFrequency(void);
#endif

#if defined(GET_SAI2_FREQ_USE)
	void setSai2ClockSource(uint8_t src);
	uint32_t getSai2ClockFrequency(void);
#endif

#if defined(GET_SAI1A_FREQ_USE)
	void setSai1AClockSource(uint8_t src);
	uint32_t getSai1AClockFrequency(void);
#endif

#if defined(GET_SAI1B_FREQ_USE)
	void setSai1BClockSource(uint8_t src);
	uint32_t getSai1BClockFrequency(void);
#endif

#if defined(SAIPLL_P_USE)
	uint32_t getSaiPllPFrequency(void);
#endif

#if defined(SAIPLL_Q_USE)
	uint32_t getSaiPllQFrequency(void);
#endif

#if defined(SAIPLL_R_USE)
	uint32_t getSaiPllRFrequency(void);
#endif
#endif
	
	// SDRAM 장치 클럭을 활성화 한다.
	//
	// bool enable
	//		활성화 여부를 설정한다. true를 설정시 활성화한다.
#if defined(FMC_Bank5_6)
	void enableSdram(bool enable = true);
#endif

#if defined(GD32F4) || defined(STM32F429xx) || defined(STM32F7)
	void setLtdcDivisionFactor(uint8_t div);
	uint32_t getLtdcClockFrequency(void);
#endif

	uint32_t getSdmmcClockFrequency(void);

#if defined(STM32F7)
	uint32_t getPll48ClkClockFrequency(void);

	void setSdmmcClockSrouce(bool src);
#endif

	// Clock
	virtual uint32_t getCoreClockFrequency(void); // virtual 0

private:
};

#endif