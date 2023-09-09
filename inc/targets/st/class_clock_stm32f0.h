////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
	bool enableHse(uint32_t hseHz = 0, bool useBypass = false);
	bool enableLsi(bool useBypass = false);
	bool enableLse(bool en = true);
	bool setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc = 33);

	void enableAhb1Clock(uint32_t position, bool en = true);
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

#if defined(GD32F4) || defined(STM32F429xx) || defined(STM32F7)
	void setLtdcDivisionFactor(uint8_t div);
	uint32_t getLtdcClockFrequency(void);
#endif

	// Clock
	virtual uint32_t getCoreClockFrequency(void); // virtual 0

private:
};

#endif