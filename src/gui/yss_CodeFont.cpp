/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <gui/CodeFont.h>

CodeFont::CodeFont(const codeFontInfo_t *info)
{
	mInfo = info;
	mSize = info->size;
	mSpaceWidth = mSize / 3;
}

Font::fontInfo_t *CodeFont::getFontInfo(uint32_t ch)
{
	uint8_t group = ch & 0x7;
	uint32_t loop = mInfo->numOfChar[group];
	Font::fontInfo_t *info = (Font::fontInfo_t*)mInfo->fontInfo[group];

	for(uint32_t i = 0; i < loop; i++)
	{
		if(info[i].utf8Code == ch)
			return &info[i];
	}

	return 0;
}

#endif

