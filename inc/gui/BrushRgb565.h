/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_BRUSH_RGB565__H_
#define YSS_GUI_BRUSH_RGB565__H_

#include "Brush.h"
#include "Color.h"
#include "Font.h"

class BrushRgb565 : public Brush
{
public:
	BrushRgb565(void);

	~BrushRgb565(void);

	// Brush
	virtual void drawDot(int16_t x, int16_t y);
	
	virtual void drawDot(int16_t x, int16_t y, Color color);

	virtual void drawDot(int16_t x, int16_t y, uint32_t color);

	virtual void fillRectBase(Position_t pos, Size_t size, uint32_t color);
};

#endif

