/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9488_SPI_WITH_BRUSH__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9488_SPI_WITH_BRUSH__H_

#include <drv/Gpio.h>
#include <drv/Spi.h>
#include "ILI9488_with_Brush_RGB888.h"

class ILI9488_spi_with_Brush_RGB888 : public ILI9488_with_Brush_RGB888
{
  protected:
	Spi *mPeri;
	pin_t mCsPin;
	pin_t mDcPin;
	pin_t mRstPin;
	const Spi::specification_t *mSpec;

	// TftLcdDriver
	void reset(void); // virtual 0
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

	ILI9488_spi_with_Brush_RGB888(void);

	void setConfig(const Config &config);

	void setSpiSpecification(const Spi::specification_t &spec);
};

#endif