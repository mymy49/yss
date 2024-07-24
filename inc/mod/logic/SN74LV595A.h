/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_LOGIC_SN74LV595A__H_
#define YSS_MOD_LOGIC_SN74LV595A__H_

#include <yss/instance.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class SN74LV595A
{
	Spi *mPeri;
	pin_t mOe, mRclk, mSrclr;

	void reset(void);

  public:
	struct Config
	{
		Spi &spi;
		pin_t OE;
		pin_t RCLK;
		pin_t SRCLR;
	};

	SN74LV595A(void);
	bool initialize(Config config);
	void set(uint8_t data);
	void set(uint8_t *data, uint8_t size);
	void setOutputEn(bool en);
};

#endif

#endif