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

#ifndef YSS_DRV_SDRAM__H_
#define YSS_DRV_SDRAM__H_

#include "peripheral.h"

#if defined(STM32F7) || defined(STM32F4) || defined(GD32F4)

#include <targets/st_gigadevice/define_sdram_stm32_gd32f4_f7.h>

typedef volatile uint32_t	YSS_SDRAM_Peri;

#elif defined(STM32F446xx) || defined(STM32F429xx) || defined(STM32F767xx) || defined(STM32F746xx)

typedef FMC_Bank5_6_TypeDef	YSS_SDRAM_Peri;

#else

#define YSS_DRV_SDRAM_UNSUPPORTED

#endif

#ifndef YSS_DRV_SDRAM_UNSUPPORTED

#include "Drv.h"
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

	Sdram(const Drv::Config drvConfig);
	bool initialize(uint8_t bank, const Specification &spec, uint32_t freq);

  private:
	Specification *mSpec;
	YSS_SDRAM_Peri *mDev;
	uint32_t (*mGetClockFrequencyFunc)(void);
};

#endif

#endif

