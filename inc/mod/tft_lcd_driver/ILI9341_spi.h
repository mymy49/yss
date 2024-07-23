/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9341_SPI__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9341_SPI__H_

#include "ILI9341.h"
#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <drv/Gpio.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class ILI9341_spi : public ILI9341
{
  protected:
	Spi *mPeri;
	pin_t mCsPin;
	pin_t mDcPin;
	pin_t mRstPin;

  public:
	struct Config 
	{
		Spi &peri;
		pin_t chipSelect;
		pin_t dataCommand;
		pin_t reset;
	};

	ILI9341_spi(void);

	void setConfig(const Config &config);

	void reset(void); // virtual 0
	void sendCmd(uint8_t cmd); // virtual 0
	void sendCmd(uint8_t cmd, void *data, uint32_t len); // virtual 0
	void enable(void); // virtual 0
	void disable(void); // virtual 0
};

#endif

#endif

