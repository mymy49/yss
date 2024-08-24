/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_CTOUCH_FT5336__H_
#define YSS_MOD_CTOUCH_FT5336__H_

#include <yss/instance.h>
#include <sac/Touch.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class FT5336 : public sac::Touch
{
public :
	typedef struct
	{
		I2c &peri;
		pin_t isrPin;
		pin_t resetPin;
	}config_t;

	error_t initialize(const config_t config);

	int8_t getByte(int8_t addr);

	error_t getMultiByte(int8_t addr, uint8_t *des, uint8_t size);

	void isr(void);

private :
	I2c *mPeri;
	pin_t mIsr;
	int32_t mTriggerId;
};

#endif

#endif
