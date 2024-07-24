/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_SDRAM__H_
#define YSS_DRV_SDRAM__H_

#include "peripheral.h"

#if defined(STM32F446xx) || defined(STM32F429xx) || defined(STM32F767xx) || defined(STM32F746xx)

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
	struct specification_t
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

	Sdram(const Drv::setup_t drvConfig);
	bool initialize(uint8_t bank, const specification_t &spec, uint32_t freq);

  private:
	specification_t *mSpec;
	YSS_SDRAM_Peri *mDev;
	uint32_t (*mGetClockFrequencyFunc)(void);
};

#endif

#endif

