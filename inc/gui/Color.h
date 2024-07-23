/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_COLOR__H_
#define YSS_GUI_COLOR__H_

#include <stdint.h>

class Color
{
public :
	Color(void);

	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);

	void setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);

	void setColor(Color color);

	void setColorCodeRgb888(uint32_t code);

	void setColorCodeRgb565(uint16_t code);

	void getColor(uint8_t &red, uint8_t &green, uint8_t &blue, uint8_t &alpha);

	void setToRed(void);

	void setToGreen(void);

	void setToBlue(void);

	void setToWhite(void);

	void setToBlack(void);

	void setReverseRgbOrder(bool reverse);

	void setLittleEndian(bool reverse);

	Color calculateFontColorLevel(Color &bgColor, uint8_t level);

	uint16_t getRgb565Code(void);

	uint16_t getArgb1555Code(void);

	uint32_t getRgb888Code(void);

	bool compare(Color color);

private :
	uint8_t mRed, mGreen, mBlue, mAlpha;
	static bool mReverseRgb, mLittleEndian;
};

#endif

