/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_EEPROM_CAT24C256__H_
#define YSS_MOD_EEPROM_CAT24C256__H_

#include <sac/Memory.h>
#include <yss/instance.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class CAT24C256 : public Memory
{
	I2c *mPeri;
	pin_t mWp;
	bool mInitFlag;
	uint8_t mAddr;
	uint64_t mLastWritingTime;
	uint64_t mThisTime;

  protected:
	uint32_t getSize(void);

  public:
	enum
	{
		ADDR0 = 0x2,
		ADDR1 = 0x4,
		ADDR2 = 0x8
	};

	CAT24C256(void);

	struct Config
	{
		I2c &peri;
		pin_t writeProtectPin;
		uint8_t addr;
	};

	bool init(const Config config);
	error_t writeBytes(uint32_t addr, void *src, uint32_t size);
	error_t readBytes(uint32_t addr, void *des, uint32_t size);
};

#endif

#endif

