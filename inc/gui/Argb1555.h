/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_ARGB1555__H_
#define YSS_GUI_ARGB1555__H_

#include "Painter.h"

class Argb1555 : public Painter
{
public:
	Argb1555(void);

	virtual ~Argb1555(void);

	// Brush
	virtual void drawDot(int16_t x, int16_t y);
	
	virtual void drawDot(int16_t x, int16_t y, Color color);

	virtual void drawDot(int16_t x, int16_t y, uint32_t color);
};

#endif

