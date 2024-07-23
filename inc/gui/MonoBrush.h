/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_MONO_BRUSH__H_
#define YSS_GUI_MONO_BRUSH__H_

#include "util.h"
#include <gui/Font.h>

class MonoBrush
{
  protected:
	Size_t mSize;
	Font *mFont;

	void setSize(Size_t size);
	void setSize(uint16_t width, uint16_t height);

  public:
	MonoBrush(void);

	void setFont(Font &font);
	uint8_t drawChar(Position_t pos, uint32_t utf8, bool data = true);
	uint8_t drawString(Position_t pos, const char *str, bool data = true);
	void clear(void);
	void fill(void);
	void drawLine(int16_t sx, int16_t sy, int16_t ex, int16_t ey, bool data = true);
	void drawLine(Position_t start, Position_t end, bool data = true);
	void drawRect(Position_t p1, Position_t p2, bool data = true);
	void drawRect(Position_t p1, Size_t size, bool data = true);
	void drawCircle(Position_t pos, uint16_t radius, bool data = true);
	void fillRect(Position_t p1, Position_t p2, bool data = true);
	void fillRect(Position_t pos, Size_t size, bool data = true);

	virtual void drawDot(uint16_t x, uint16_t y, bool data = true) = 0;
};

#endif


