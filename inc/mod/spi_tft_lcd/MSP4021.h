/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SPI_TFT_LCD_MSP4021__H_
#define YSS_MOD_SPI_TFT_LCD_MSP4021__H_

#include <mod/tft_lcd_driver/ST7796S_spi_with_Brush_RGB888.h>

// 구매처 : https://ko.aliexpress.com/item/1005003067055683.html

class MSP4021 : public ST7796S_spi_with_Brush_RGB888
{
  public:
	MSP4021(void);

	// TftLcdDriver
	error_t initialize(void); // virtual 0
};

#endif

