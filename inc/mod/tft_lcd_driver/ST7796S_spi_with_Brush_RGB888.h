/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ST7796_SPI__H_
#define YSS_MOD_TFT_LCD_DRIVER_ST7796_SPI__H_

#include <drv/Gpio.h>
#include <drv/Spi.h>
#include "ST7796S_with_Brush_RGB888.h"

class ST7796S_spi_with_Brush_RGB888 : public ST7796S_with_Brush_RGB888
{
	Spi *mPeri;
	pin_t mCsPin;
	pin_t mDcPin;
	pin_t mRstPin;

  protected:
	// TftLcdDriver
	void sendCmd(uint8_t cmd); // virtual 0
	void sendCmd(uint8_t cmd, void *data, uint32_t len); // virtual 0
	void enable(void); // virtual 0
	void disable(void); // virtual 0

  public:
	struct Config 
	{
		Spi &peri;
		pin_t chipSelect;
		pin_t dataCommand;
		pin_t reset;
	};

	ST7796S_spi_with_Brush_RGB888(void);

	void setConfig(const Config &config);

	void reset(void); // virtual 0
};

#endif

