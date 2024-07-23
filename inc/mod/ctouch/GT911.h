/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_CTOUCH_GT911__H_
#define YSS_MOD_CTOUCH_GT911__H_

#include <yss/instance.h>
#include <sac/Touch.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class GT911 : public sac::Touch
{
public :
	struct config_t
	{
		I2c &peri;
		pin_t isrPin;
		pin_t resetPin;
		Size_t size;
	};

	error_t initialize(const config_t config);

	int8_t getByte(uint16_t addr);

	error_t setByte(uint16_t addr, uint8_t data);

	error_t getMultiByte(uint16_t addr, void *des, uint8_t size);

	error_t setMultiByte(uint16_t addr, void *src, uint8_t size);

	error_t setCommand(uint8_t cmd);

	uint8_t getCommand(void);

	void isr(void);

private :
	I2c *mPeri;
	pin_t mIsr;
	int32_t mTriggerId;

	uint8_t calculateChksum(void *src);
};

#endif

#endif
