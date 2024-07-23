/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_BMP565_BUFFER__H_
#define YSS_GUI_BMP565_BUFFER__H_

#include <gui/Bmp565.h>
#include <gui/BrushRgb565.h>
#include <gui/Color.h>

class Bmp565Buffer : public BrushRgb565
{
protected :
	uint32_t mBufferSize;
	bool mOkFlag;
	Bitmap_t mBmp565;

public :
	Bmp565Buffer(uint32_t pointSize);

	~Bmp565Buffer(void);

	virtual error_t setSize(uint16_t width, uint16_t height);

	virtual error_t setSize(Size_t size);

	Bitmap_t *getBitmap(void);

	uint32_t getBufferSize(void);

	void drawStringToCenterAligned(const char *str);
};

#endif