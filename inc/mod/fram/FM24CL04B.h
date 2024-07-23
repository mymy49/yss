/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_FRAM_FM24CL04B__H_
#define YSS_MOD_FRAM_FM24CL04B__H_

#include <sac/Memory.h>
#include <yss/instance.h>
#include <yss/error.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class FM24CL04B : public Memory
{
public :
	enum
	{
		ADDR1 = 0x4,
		ADDR2 = 0x8
	};

	struct config_t
	{
		I2c &peri;
		pin_t writeProtectPin;
		uint8_t addr;
	};

	FM24CL04B(void);

	error_t initialize(const config_t config);

	error_t writeBytes(uint32_t addr, void *src, uint32_t size);

	error_t readBytes(uint32_t addr, void *des, uint32_t size);

protected :
	uint32_t getSize(void);

private :
	I2c *mPeri;
	pin_t mWp;
};

#endif

#endif

