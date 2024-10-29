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
#include "ST7789V_with_Brush_RGB565.h"

class ST7789V_spi_with_Brush_RGB565 : public ST7789V_with_Brush_RGB565
{
  public:
	typedef struct 
	{
		Spi &peri;
		pin_t chipSelect;
		pin_t dataCommand;
		pin_t reset;
	}config_t;

	ST7789V_spi_with_Brush_RGB565(void);

	void setConfig(const config_t &config);

	void setSpiSpecification(const Spi::specification_t &spec);

	void reset(void); // virtual 0

  protected:
	Spi *mPeri;
	pin_t mCsPin;
	pin_t mDcPin;
	pin_t mRstPin;
	const Spi::specification_t *mSpec;

	// TftLcdDriver
	virtual void sendCmd(uint8_t cmd); // pure
	
	virtual void sendCmd(uint8_t cmd, uint8_t data); // pure
	
	virtual void sendCmd(uint8_t cmd, void *data, uint32_t len); // pure
	
	void enable(void); // pure
	
	void disable(void); // pure

	void read(uint8_t cmd, uint8_t &des);
};

#endif

