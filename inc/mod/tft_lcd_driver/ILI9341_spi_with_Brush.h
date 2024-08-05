/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9341_SPI__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9341_SPI__H_

#include "ILI9341_with_Brush.h"
#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <drv/Gpio.h>

class ILI9341_spi_with_Brush : public ILI9341_with_Brush
{
public:
	typedef struct
	{
		Spi &peri;
		pin_t chipSelect;
		pin_t dataCommand;
		pin_t reset;
	}config_t;

	const Spi::specification_t *mSpec;

	ILI9341_spi_with_Brush(void);

	void setConfig(const config_t &config);

	void setSpiSpecification(const Spi::specification_t &spec);

	// TftLcdDriver
	void reset(void); // pure

	void sendCmd(uint8_t cmd); // pure

	void sendCmd(uint8_t cmd, uint8_t data); // pure

	void sendCmd(uint8_t cmd, void *data, uint32_t len); // pure

	void enable(void); // pure

	void disable(void); // pure

protected:
	Spi *mPeri;
	pin_t mCsPin;
	pin_t mDcPin;
	pin_t mRstPin;
};

#endif

