////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
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
#endif

#include "clock/drv_clock_peripherals.h"

namespace drv
{
class Clock
{
#if defined(STM32F1)
	static unsigned int mHseFreq;
	static unsigned int mPllFreq;
	static unsigned int mLseFreq;
#elif defined(STM32F4) || defined(STM32F7)
	static unsigned int mHseFreq;
	static unsigned int mPllFreq;
	static unsigned int mSaiPllFreq;
	static unsigned int mLcdPllFreq;
#endif

  public:
#if defined(STM32F1)
	bool enableMainPll(unsigned char src, unsigned char xtpre, unsigned char mul);
#elif defined(STM32F4) || defined(STM32F7)
	bool enableMainPll(unsigned char src, unsigned char m, unsigned short n, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
	bool enableSaiPll(unsigned short n, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
#elif defined(STM32G4)
	bool enable(unsigned char src, unsigned int vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
	void setPEn(bool en);
	void setQEn(bool en);
	void setREn(bool en);
#endif
	Peripheral peripheral;
	
	bool enableHse(unsigned int hseHz, bool useOsc = false);
	bool enableLsi(void);
	bool enableLse(bool en);
	bool setUsbClkSrc(unsigned char src);
	bool setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2, unsigned char vcc = 33);
	void setLatency(unsigned int freq, unsigned char vcc = 33);

	unsigned int getSysClkFreq(void);
	unsigned int getApb1ClkFreq(void);
	unsigned int getApb2ClkFreq(void);
	unsigned int getTimerApb1ClkFreq(void);
	unsigned int getTimerApb2ClkFreq(void);

	bool setVoltageScale(unsigned char range);
	unsigned char getVoltageScale(void);
	unsigned char getAhbPrescale(void);
	void setAhbPrescale(unsigned char ahb);

};
}

#endif

