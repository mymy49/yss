////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CLOCK__H_
#define YSS_DRV_CLOCK__H_

#include "mcu.h"

#if defined(STM32F1)
#include <targets/st_gigadevice/ec_clock_stm32f1 .h>
#include <targets/st_gigadevice/define_clock_stm32f1.h>
#elif defined(STM32F4)
#include <targets/st_gigadevice/ec_clock_stm32f4.h>
#include <targets/st_gigadevice/define_clock_stm32f4.h>
#elif defined(STM32F7)
#include <targets/st_gigadevice/ec_clock_stm32f7.h>
#include <targets/st_gigadevice/define_clock_stm32f7.h>
#elif defined(STM32G4)
#include "clock/ec_clock_stm32g4.h"
#include "clock/define_clock_stm32g4.h"
#elif defined(GD32F1)
#include "clock/ec_clock_gd32f1.h"
#include "clock/define_clock_gd32f1.h"
#elif defined(GD32F4)
#include <targets/st_gigadevice/ec_clock_gd32f4.h>
#include <targets/st_gigadevice/define_clock_gd32f4.h>
#elif defined(NRF52840_XXAA)
#include <targets/nordic/ec_clock_nrf52840.h>
#include <targets/nordic/define_clock_nrf52840.h>
#elif defined(STM32L1)
#include <targets/st_gigadevice/define_clock_stm32l1.h>
#include <targets/st_gigadevice/ec_clock_stm32l1.h>
#elif defined(STM32F0)
#include <targets/st_gigadevice/ec_clock_stm32f0.h>
#include <targets/st_gigadevice/define_clock_stm32f0.h>
#else
#define YSS_DRV_CLOCK_UNSUPPORTED
#endif

#ifndef YSS_DRV_CLOCK_UNSUPPORTED

#include <yss/Mutex.h>
#include <yss/error.h>

class Clock : public Mutex
{
#if defined(STM32F1) || defined(GD32F1)
	static int32_t  mHseFreq;
	static int32_t  mLseFreq;
#endif

  public:
	// 기본 사양
	bool enableHse(uint32_t hseHz = 0, bool useBypass = false);
	bool enableLsi(bool useBypass = false);
	bool enableLse(bool en = true);
	bool setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc = 33);

	void enableAhb1Clock(uint32_t position, bool en = true);
	void enableAhb2Clock(uint32_t position, bool en = true);
	void enableAhb3Clock(uint32_t position, bool en = true);
	void enableApb1Clock(uint32_t position, bool en = true);
	void enableApb2Clock(uint32_t position, bool en = true);

	void resetAhb1(uint32_t position);
	void resetAhb2(uint32_t position);
	void resetAhb3(uint32_t position);
	void resetApb1(uint32_t position);
	void resetApb2(uint32_t position);

	uint32_t getSystemClockFrequency(void);
	uint32_t getCoreClockFrequency(void);
	uint32_t getAhbClockFrequency(void);
	uint32_t getApb1ClockFrequency(void);
	uint32_t getApb2ClockFrequency(void);
	
	// MCU별 옵션 사양
#if defined(STM32F1) || defined(GD32F1) || defined(STM32F0)
	bool enableMainPll(uint8_t src, uint8_t xtpre, uint8_t mul);
	uint32_t getMainPllFrequency(void);
#elif defined(GD32F4) || defined(STM32F4) || defined(STM32F7)
	bool enableMainPll(uint8_t src, uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv);
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

#if defined(GD32F4) || defined(STM32F4) || defined(STM32F7)
	void enableSdram(bool en = true);
#endif

#if defined(GD32F4) || defined(STM32F4) || defined(STM32F7)
	void setLtdcDivisionFactor(uint8_t div);
	uint32_t getLtdcClockFrequency(void);
#endif

#if defined(GD32F4) || defined(STM32F429xx) || defined(STM32F7)
	bool enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv);
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
};

#endif

#endif

