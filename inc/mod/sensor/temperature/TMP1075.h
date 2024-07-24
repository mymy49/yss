/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SENSOR_TEMPERATURE_TMP1075__H_
#define YSS_MOD_SENSOR_TEMPERATURE_TMP1075__H_

#include <sac/Temperature.h>
#include <yss/instance.h>
#include <yss/error.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class TMP1075 : public Temperature
{
public :
	struct config_t
	{
		I2c &peri;
		uint8_t addr;
	};

	error_t initialize(const config_t config);

	virtual float getTemperature(void); // pure

	TMP1075(void);

private :
	I2c *mPeri;
	uint8_t mAddr;
};

#endif

#endif

