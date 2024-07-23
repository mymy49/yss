/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_LOGIC_SN74LV166A__H_
#define YSS_MOD_LOGIC_SN74LV166A__H_

#include <yss/instance.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class SN74LV166A
{
	Spi *mPeri;
	pin_t mShLd, mClkInh, mClr;
	uint8_t mDepth;
	uint8_t *mData;

  public:
	struct Config
	{
		Spi &spi;
		uint8_t depth;
		pin_t CLK_INH;
		pin_t SH_LD;
		pin_t CLR;
	};

	SN74LV166A(void);
	bool initialize(const Config config);
	bool refresh(void);
	uint8_t get(uint8_t index);
	void reset(void);
};

#endif

#endif