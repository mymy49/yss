/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_RGB565__H_
#define YSS_GUI_RGB565__H_

#include "FrameBuffer.h"
class Bmp565;

class Rgb565 : public FrameBuffer
{
protected:
	uint16_t mFontColorTable[16];
	uint16_t mBrushColorCode, mBgColorCode;

public:
	Rgb565(void);

	uint8_t drawChar(Position_t pos, uint32_t utf8);

	void setColorLevel(uint8_t level);

	void drawBmp565(Position_t pos, const Bmp565 *image);

	void drawBmp565(Position_t pos, const Bmp565 &image);

	void clearRectangle(Position_t pos, Size_t size);

	// Brush
	virtual void clear(void);

	virtual void drawDot(int16_t x, int16_t y); // virtual 0

	virtual void drawDot(int16_t x, int16_t y, Color color); // virtual 0

	virtual void eraseDot(Position_t pos); // virtual 0

	virtual void setBrushColor(Color color);
	
	virtual void setBrushColor(uint8_t red, uint8_t green, uint8_t blue);
	
	virtual void setBackgroundColor(Color color);
	
	virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);
};

#endif

