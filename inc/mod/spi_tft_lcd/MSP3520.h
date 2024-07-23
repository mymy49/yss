/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SPI_TFT_LCD_MSP3520__H_
#define YSS_MOD_SPI_TFT_LCD_MSP3520__H_

#include <drv/Spi.h>
#include <drv/Gpio.h>

#include <mod/tft_lcd_driver/ILI9488_spi_with_Brush_RGB888.h>

// 구매처 : https://ko.aliexpress.com/item/32985467436.html

class MSP3520 : public ILI9488_spi_with_Brush_RGB888
{
  public:
	MSP3520(void);
	
	// TftLcdDriver
	virtual error_t initialize(void); // pure

	virtual Size_t getLcdSize(void); // pure

};

#endif

