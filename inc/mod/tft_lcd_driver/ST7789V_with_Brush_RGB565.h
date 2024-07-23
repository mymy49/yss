/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ST7796__H_
#define YSS_MOD_TFT_LCD_DRIVER_ST7796__H_

#include <gui/BrushRgb565.h>
#include <gui/Bmp565Buffer.h>
#include "ST7789V.h"

class ST7789V_with_Brush_RGB565 : public ST7789V, public BrushRgb565
{
  protected:
	Bmp565Buffer *mBmp565Buffer;
	uint32_t mBmp565BufferSize, mBrushColorCode;

  public:
	ST7789V_with_Brush_RGB565(void);
	void setBmp565Buffer(Bmp565Buffer &obj);

	// Brush
	virtual void drawDot(int16_t x, int16_t y); // virtual 0

	virtual void drawDot(int16_t x, int16_t y, uint32_t color); // virtual 0

	virtual void drawDot(int16_t x, int16_t y, Color color); // virtual 0

	virtual void drawBitmapBase(Position_t pos, const Bitmap_t &bitmap);

	virtual void eraseDot(Position_t pos); // virtual 0
	virtual void clear(void); // virtual
	virtual void fillRect(Position_t p1, Position_t p2);
	virtual void fillRect(Position_t pos, Size_t size);
	virtual void drawBmp(Position_t pos, const Bmp565 *image);
	virtual void setBrushColor(Color color);
	virtual void setBrushColor(uint8_t red, uint8_t green, uint8_t blue);
};

#endif