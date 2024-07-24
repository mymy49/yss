/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_CODE_FONT__H_
#define YSS_GUI_CODE_FONT__H_

#define NUM_OF_GROUP 8

#include <stdint.h>
#include "Font.h"

class CodeFont : public Font
{
public :
	struct codeFontInfo_t
	{
		uint8_t size;
		uint32_t numOfChar[NUM_OF_CHAR_GROUP];
		const Font::fontInfo_t *fontInfo[NUM_OF_CHAR_GROUP];
	} __attribute__((packed));
	
	CodeFont(const codeFontInfo_t *info);

	virtual fontInfo_t* getFontInfo(uint32_t ch);	// pure

private :
	const codeFontInfo_t *mInfo;
};

#endif

