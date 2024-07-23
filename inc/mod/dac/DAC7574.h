/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_DAC_DAC7574__H_
#define YSS_MOD_DAC_DAC7574__H_

#include <yss/instance.h>

#ifndef YSS_DRV_I2C_UNSUPPORTED

namespace mod
{
namespace dac
{
class DAC7574
{
	I2c *mPeri;
	bool mInitFlag;
	uint8_t mAddr;
	uint16_t mOutputValue[4];

  public:
	enum
	{
		ADDR0 = 0x2,
		ADDR1 = 0x4
	};

	DAC7574(void);
	bool init(I2c *peri, uint8_t addr);
	bool set(uint8_t channel, uint16_t value);
};
}
}

#endif

#endif
