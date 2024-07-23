/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_DAC_DAC7574__H_
#define YSS_MOD_DAC_DAC7574__H_

#include <yss/instance.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

namespace mod
{
namespace dac
{
class DAC8311
{
  public:
	struct Config
	{
		Spi &peri;
		pin_t chipSelect;
	};

	enum
	{
		PD_NORMAL = 0x0000,
		PD_1KOHM_PULL_DOWN = 0x4000,
		PD_100KOHM_PULL_DOWN = 0x8000,
		PD_HIGH_Z = 0xC000
	};

	DAC8311(void);
	bool initialize(const Config config);
	bool setValue(uint16_t value);
	void setPowerDown(uint16_t mode);

  private:
	Spi *mPeri;
	pin_t mCs;
	uint16_t mPowerDown;
	uint16_t mValue;

	bool send(void);
};
}
}

#endif

#endif
