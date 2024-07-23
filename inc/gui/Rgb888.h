/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_RGB888__H_
#define YSS_GUI_RGB888__H_

#include "Painter.h"

class Rgb888 : public Painter
{
  public:
	Rgb888(void);

	virtual ~Rgb888(void);

	// Brush
	virtual void drawDot(int16_t x, int16_t y);
	
	virtual void drawDot(int16_t x, int16_t y, Color color);

	virtual void drawDot(int16_t x, int16_t y, uint32_t color);
};

#endif

