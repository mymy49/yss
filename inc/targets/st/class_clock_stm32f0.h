/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_CLOCK_STM32F1__H_
#define YSS_CLASS_CLOCK_STM32F1__H_

#include <yss/error.h>
#include <drv/mcu.h>

#if defined(STM32F446xx)
#include "define_stm32f446xx.h"
#elif defined(STM32F446xx)
#include "define_stm32f429xx.h"
#endif

#if defined(STM32F429xx)
#define PLL_P_USE
#define PLL_Q_USE

#define I2SPLL_Q_USE
#define I2SPLL_R_USE

#define SAIPLL_Q_USE
#define SAIPLL_R_USE
#elif defined(STM32F446xx)
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
#endif

class Clock : public ClockBase
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

	// AHB1 버스 장치의 클럭을 활성화 합니다.
	// uint32_t position
	//		AHB1 버스의 활성화할 비트필드의 비트 번호를 설정합니다.
	// bool en = true
	//		AHB1 버스의 position에서 설정한 장치를 켜거(true)나 끕(false)니다.
	void enableAhb1Clock(uint32_t position, bool en = true);

	bool enableLsi(bool useBypass = false);
	bool enableLse(bool en = true);
	bool setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc = 33);

	void enableAhb2Clock(uint32_t position, bool en = true);
	void enableAhb3Clock(uint32_t position, bool en = true);
	void enableApb1Clock(uint32_t position, bool en = true);
	void enableApb1_1Clock(uint32_t position, bool en = true);
	void enableApb1_2Clock(uint32_t position, bool en = true);
	void enableApb2Clock(uint32_t position, bool en = true);

	void resetAhb1(uint32_t position);
	void resetAhb2(uint32_t position);
	void resetAhb3(uint32_t position);
	void resetApb1(uint32_t position);
	void resetApb2(uint32_t position);

	uint32_t getSystemClockFrequency(void);
	uint32_t getAhbClockFrequency(void);
	uint32_t getApb1ClockFrequency(void);
	uint32_t getApb2ClockFrequency(void);

	bool enableMainPll(uint8_t src, uint8_t xtpre, uint8_t mul);
	uint32_t getMainPllFrequency(void);

	// I2SPLL 관련
#if defined(I2SPLL_USE)

	bool enableI2sPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv);

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
	void enableSdram(bool enable = true);

	// Clock
	virtual uint32_t getCoreClockFrequency(void); // virtual 0

private:
};

#endif