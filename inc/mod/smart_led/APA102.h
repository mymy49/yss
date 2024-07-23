/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SMART_LED_APA102__H_
#define YSS_MOD_SMART_LED_APA102__H_

#include <yss/instance.h>
#include <yss/error.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

// 데이터시트 : http://www.szledcolor.com/download/APA102%20LED.pdf

class APA102
{
  public:
	struct Config
	{
		Spi &spi;
		uint16_t ledCount;
	};

	APA102(void);

	error_t initialize(Config config);

	error_t setRgb(uint16_t index, uint8_t r, uint8_t g, uint8_t b);

	error_t setRgb(uint8_t r, uint8_t g, uint8_t b);

	error_t setBrightness(uint16_t index, uint8_t brightness);

	error_t setBrightness(uint8_t brightness);

	void refresh(void);

  private:
	Spi *mPeri;
	uint8_t *mData;
	uint16_t mLedCount;
	uint32_t mDataCount;
};

#endif

#endif
