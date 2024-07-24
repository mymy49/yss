/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_FONT__H_
#define YSS_GUI_FONT__H_

#define NUM_OF_ASCII_CODE 96
#define YSS_FONT_MAX_SUB_HEADER 8
#define NUM_OF_CHAR_GROUP 8

#include <stdint.h>

class Font
{
public:
	struct fontInfo_t
	{
		uint32_t utf8Code;
		uint8_t width;
		uint8_t height;
		uint8_t xpos;
		uint8_t ypos;
		uint8_t *data;
	} __attribute__((packed));

	Font(void);

	virtual fontInfo_t* getFontInfo(uint32_t ch) = 0;

	uint8_t getSpaceWidth(void);

	void setSpaceWidth(uint8_t width);

	uint8_t getCharWidth(void);

	void setCharWidth(uint8_t width);

	uint16_t getStringWidth(const char *str);

	uint16_t getStringHeight(void);

	uint32_t getUtf8(const char **src);

protected:
	uint8_t mSpaceWidth, mCharWidth, mSize;
};

#endif

