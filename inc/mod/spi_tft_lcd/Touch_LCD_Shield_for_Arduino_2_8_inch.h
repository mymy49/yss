/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SPI_TFT_LCD_TOUCH_LCD_SHIELD_FOR_ARDUINO_2_8_INCH__H_
#define YSS_MOD_SPI_TFT_LCD_TOUCH_LCD_SHIELD_FOR_ARDUINO_2_8_INCH__H_

#include <mod/tft_lcd_driver/ST7789V_spi_with_Brush_RGB565.h>

// 구매처 : https://www.eleparts.co.kr/goods/view?no=3216739
// 구매처 : https://www.waveshare.com/2.8inch-TFT-Touch-Shield.htm

// 현재 이 장치는 정상 동작이 확인되지 않았습니다.
class Touch_LCD_Shield_for_Arduino_2_8_inch : public ST7789V_spi_with_Brush_RGB565
{
  public:
	Touch_LCD_Shield_for_Arduino_2_8_inch(void);
	
	// TftLcdDriver
	virtual error_t initialize(void); // pure

	virtual Size_t getLcdSize(void); // pure
};

#endif

