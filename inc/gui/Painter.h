/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_PAINTER__H_
#define YSS_GUI_PAINTER__H_

#include "Brush.h"

class Object;

class Painter : public Brush
{
public :
	void updateFontColor(void);

	virtual void drawBitmapBase(Position_t pos, const Bitmap_t &bitmap);

	virtual void drawBitmapFileBase(Position_t pos, const BitmapFile_t &bitmap);

	virtual void fillRectBase(Position_t pos, Size_t size, uint32_t color);

	virtual uint8_t drawChar(Position_t pos, uint32_t utf8);

	virtual void drawObjectToPartialArea(Position_t pos, Size_t size, Object *src);

	virtual void drawPainter(Position_t pos, Painter *src);

private :
	uint32_t mFontColorCode;
};

#endif

