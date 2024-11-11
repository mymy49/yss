/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9488_WITH_BRUSH__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9488_WITH_BRUSH__H_

#include "ILI9488.h"
#include <gui/BrushRgb888.h>
#include <gui/Bmp888Buffer.h>
#include <gui/Color.h>

class ILI9488_with_Brush_RGB888 : public ILI9488, public BrushRgb888
{
  public:
	ILI9488_with_Brush_RGB888(void);

	void setBmp888Buffer(Bmp888Buffer &obj);

	// Brush
	virtual void drawDot(int16_t x, int16_t y); // pure

	virtual void drawDot(int16_t x, int16_t y, uint32_t color); // pure

	virtual void drawDot(int16_t x, int16_t y, Color color); // pure

	virtual void updateLcdSize(void); // pure

	virtual void fillRectBase(Position_t pos, Size_t size, uint32_t color);

	virtual void drawBitmapBase(Position_t pos, const Bitmap_t &bitmap);

  protected:
	Bmp888Buffer *mBmp888Brush;
	uint32_t mBmp888BufferSize;
};

#endif