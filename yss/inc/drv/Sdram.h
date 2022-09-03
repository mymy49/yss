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

#ifndef YSS_DRV_SDRAM__H_
#define YSS_DRV_SDRAM__H_

#include <drv/mcu.h>

#if defined(STM32F7) || defined(STM32F4)

#include "sdram/define_sdram_stm32f4_f7.h"

#elif defined(GD32F4)

#include "sdram/define_sdram_gd32f4.h"

#endif

#include "sdram/config_sdram.h"
#include <drv/Drv.h>
#include <stdint.h>

class Sdram : public Drv
{
  public:
	struct Specification
	{
		uint8_t columnAddress;
		uint8_t rowAddress;
		uint8_t dbusWidth;
		uint8_t internalBank;
		uint8_t casLatency;
		uint32_t maxFrequency;
		uint32_t tMrd;
		uint32_t tXsr;
		uint32_t tRas;
		uint32_t tRc;
		uint32_t tWr;
		uint32_t tRp;
		uint32_t tRcd;
		uint32_t tOh;
		uint32_t tAc;
		uint32_t tRefresh;
		uint16_t numOfRow;
		bool writeProtection;
		bool burstRead;
		uint16_t mode;
	};

	Sdram(void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
	Sdram(const Drv::Config drvConfig);
	bool init(uint8_t bank, const Specification &spec);

  private:
	Specification *mSpec;
	uint32_t (*mGetClockFrequencyFunc)(void);
};


#endif