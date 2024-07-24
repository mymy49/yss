/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SPI_TFT_LCD_MSP3218__H_
#define YSS_MOD_SPI_TFT_LCD_MSP3218__H_

#include <mod/tft_lcd_driver/ILI9341_spi_with_Brush.h>

// 구매처 : https://ko.aliexpress.com/item/1005003120684423.html

class MSP3218 : public ILI9341_spi_with_Brush
{
  public:
	MSP3218(void);
	
	// TftLcdDriver
	virtual error_t initialize(void); // pure

	virtual Size_t getLcdSize(void); // pure
};

#endif

