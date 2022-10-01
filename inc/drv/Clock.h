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
#include "clock/ec_clock_stm32f1 .h"
#include "clock/define_clock_stm32f1.h"
#elif defined(STM32F4)
#include "clock/ec_clock_stm32f4.h"
#include "clock/define_clock_stm32f4.h"
#elif defined(STM32F7)
#include "clock/ec_clock_stm32f7.h"
#include "clock/define_clock_stm32f7.h"
#elif defined(STM32G4)
#include "clock/ec_clock_stm32g4.h"
#include "clock/define_clock_stm32g4.h"
#elif defined(GD32F1)
#include "clock/ec_clock_gd32f1.h"
#include "clock/define_clock_gd32f1.h"
#elif defined(GD32F4)
#include "clock/ec_clock_gd32f4.h"
#include "clock/define_clock_gd32f4.h"
#elif defined(NRF52840_XXAA)
#include "clock/ec_clock_nrf52840.h"
#include "clock/define_clock_nrf52840.h"
#else
#define YSS_DRV_CLOCK_UNSUPPORTED
#endif

#ifndef YSS_DRV_CLOCK_UNSUPPORTED

#include "clock/drv_clock_peripherals.h"
#include <yss/Mutex.h>

class Clock : public Mutex
{
#if defined(STM32F1) || defined(GD32F1)
	static int32_t  mHseFreq;
	static int32_t  mPllFreq;
	static int32_t  mLseFreq;
#elif defined(STM32F4) || defined(STM32F7)
	static int32_t  mHseFreq;
	static int32_t  mPllFreq;
	static int32_t  mSaiPllFreq;
	static int32_t  mMainPllUsbFreq;
	static int32_t  mLcdPllFreq;
#endif

  public:
#if defined(STM32F1) || defined(GD32F1)
	bool enableMainPll(uint8_t src, uint8_t xtpre, uint8_t mul);
#elif defined(STM32F4) || defined(STM32F7)
	bool enableMainPll(uint8_t src, uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv);
	bool enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv);
	int32_t  getSdmmcClockFrequency(void);
	bool setUsbClockSource(uint8_t src);
	void setLatency(uint32_t freq, uint8_t vcc = 33);
#elif defined(GD32F4)
	bool enableMainPll(uint8_t src, uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv);
	bool enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t rDiv);
	bool enableI2sPll(uint16_t n, uint8_t rDiv);
	void enableSdram(bool en = true);
#elif defined(STM32G4)
	bool enable(uint8_t src, uint32_t vcoMhz, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv);
	void setPEn(bool en);
	void setQEn(bool en);
	void setREn(bool en);
#endif
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
};

#endif

#endif

