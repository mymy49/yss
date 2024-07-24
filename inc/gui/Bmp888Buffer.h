/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_BMP888_BUFFER__H_
#define YSS_GUI_BMP888_BUFFER__H_

#include <gui/Bmp888.h>
#include <gui/BrushRgb888.h>
#include <gui/Color.h>

class Bmp888Buffer : public BrushRgb888
{
protected :
	uint32_t mBufferSize;
	bool mOkFlag;
	Bitmap_t mBmp888;

public :
	Bmp888Buffer(uint32_t pointSize);

	~Bmp888Buffer(void);

	virtual error_t setSize(uint16_t width, uint16_t height);

	virtual error_t setSize(Size_t size);

	Bitmap_t *getBitmap(void);

	uint32_t getBufferSize(void);

	void drawStringToCenterAligned(const char *str);
};

#endif

