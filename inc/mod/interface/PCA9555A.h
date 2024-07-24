/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_INTERFACE_PCA9555A__H_
#define YSS_MOD_INTERFACE_PCA9555A__H_

#include <yss/instance.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED)

class PCA9555A
{
public:
	struct config_t
	{
		I2c &dev;
		uint8_t addr;
	};

	enum
	{
		NONE = 0x0,
		ADDR0 = 0x2,
		ADDR1 = 0x4,
		ADDR2 = 0x8
	};

	error_t initialize(const config_t config);

	uint8_t read(uint8_t port);

	void write(uint8_t port, uint8_t data);

	void config(uint8_t port, uint8_t config);

	void polarity(uint8_t port, uint8_t polarity);

	PCA9555A(void);

private :
	I2c *mDev;
	bool mInitFlag;
	uint8_t mAddr;
};

#endif

#endif

