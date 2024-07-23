/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ST7796__H_
#define YSS_MOD_TFT_LCD_DRIVER_ST7796__H_

#include <gui/BrushRgb888.h>
#include <gui/Bmp888Buffer.h>
#include <mod/tft_lcd_driver/ST7796S.h>

class ST7796S_with_Brush_RGB888 : public ST7796S, public BrushRgb888
{
  protected:
	Bmp888Buffer *mBmp888Buffer;
	uint32_t mBmp888BufferSize, mBrushColorCode;

  public:
	ST7796S_with_Brush_RGB888(void);
	void setBmp888Buffer(Bmp888Buffer &obj);

	// Brush
	virtual void drawDot(int16_t x, int16_t y); // virtual 0
	virtual void drawDot(int16_t x, int16_t y, uint32_t color); // virtual 0
	virtual void drawDot(int16_t x, int16_t y, Color color); // virtual 0

	virtual void eraseDot(Position_t pos); // virtual 0
	virtual void clear(void); // virtual
	virtual void fillRect(Position_t p1, Position_t p2);
	virtual void fillRect(Position_t pos, Size_t size);
	virtual void drawBmp(Position_t pos, const Bmp888 *image);
	virtual void setBrushColor(Color color);
	virtual void setBrushColor(uint8_t red, uint8_t green, uint8_t blue);
};

#endif