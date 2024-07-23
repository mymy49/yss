/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9341_WITH_BRUSH__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9341_WITH_BRUSH__H_

#include "ILI9341.h"
#include <gui/BrushRgb565.h>
#include <gui/Bmp565Buffer.h>

class ILI9341_with_Brush : public ILI9341, public BrushRgb565
{
  protected:
	Bmp565Buffer *mBmpBrush;
	uint32_t mBmpBufferSize;

  public:
	ILI9341_with_Brush(void);

	void setBmp565Buffer(Bmp565Buffer &obj);

	// Brush
	virtual void drawDot(int16_t x, int16_t y); // pure

	virtual void drawDot(int16_t x, int16_t y, uint32_t color); // pure

	virtual void drawDot(int16_t x, int16_t y, Color color); // pure

	virtual void updateLcdSize(void); // pure

	virtual void fillRectBase(Position_t pos, Size_t size, uint32_t color);

	virtual void drawBitmapBase(Position_t pos, const Bitmap_t &bitmap);
};

#endif

