////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <gui/Font.h>

Font::Font(YssFontHeaderPartUnicode *font)
{
	setFont(font);
	mFaultFlag = true;
	mSpaceWidth = 0;
	mCharWidth = 0;
}

Font::Font(void)
{
	mData = 0;
	mSpaceWidth = 0;
	mCharWidth = 0;
	mFaultFlag = true;
}

bool Font::setChar(unsigned int utf8)
{
	YssFontHeaderPartUnicode *header = (YssFontHeaderPartUnicode *)mData;

	if (mData == 0)
		goto error;

	if (utf8 < 0xFF)
	{
		if (utf8 == 0x20)
		{
			goto error;
		}
		else if (utf8 > 0x20 && utf8 < 0x80)
		{
			utf8 -= 0x21;
			mFaultFlag = false;
			mFontInfo = &header->asciiFontInfo[utf8];
			mFb = &mData[mFontInfo->offset];
			return mFaultFlag;
		}
		else
			goto error;
	}
	else
	{
		if (header->numOfGroup != NUM_OF_GROUP)
		{
			mFaultFlag = false;
			return false;
		}
		unsigned int group = utf8 % header->numOfGroup, numOfChar, *code;
		YssFontInfo *info = (YssFontInfo *)&mData[header->offsetOfFontInfo[group]];
		code = (unsigned int *)&mData[header->offsetOfCode[group]];
		numOfChar = header->numOfChar[group];

		for (int i = 0; i < numOfChar; i++)
		{
			if (code[i] == utf8)
			{
				mFaultFlag = false;
				mFontInfo = &info[i];
				mFb = &mData[info[i].offset];
				return mFaultFlag;
			}
		}
	}

error:
	mFaultFlag = true;
	return mFaultFlag;
}

YssFontInfo *Font::getFontInfo(void)
{
	if (mFaultFlag)
		return 0;
	else
		return mFontInfo;
}

bool Font::isAble(void)
{
	if (mData)
		return true;
	else
		return false;
}

unsigned char *Font::getFrameBuffer(void)
{
	if (mFaultFlag)
		return 0;
	else
		return mFb;
}

void Font::setFont(YssFontHeaderPartUnicode *font)
{
	mData = (unsigned char *)font;
}

unsigned char Font::getSpaceWidth(void)
{
	YssFontHeaderPartUnicode *header = (YssFontHeaderPartUnicode *)mData;

	if (mSpaceWidth)
		return mSpaceWidth;
	else if (mCharWidth)
		return mCharWidth;
	else
		return header->asciiFontInfo['I' - 0x21].width;
}

void Font::setSpaceWidth(unsigned char width)
{
	mSpaceWidth = width;
}

unsigned char Font::getCharWidth(void)
{
	return mCharWidth;
}

void Font::setCharWidth(unsigned char width)
{
	mCharWidth = width;
}

unsigned int Font::getUtf8(const char **src)
{
	unsigned int code = 0;

	if (*(*src) >= 0xe0)
	{
		return ((unsigned int)*(*src)++ << 16) | ((unsigned int)*(*src)++ << 8) | *(*src)++;
	}
	else if (*(*src) >= 0xc0)
	{
		return ((unsigned int)*(*src)++ << 8) | *(*src)++;
	}
	else if (*(*src) < 0x80)
	{
		return *(*src)++;
	}

	(*src)++;
	return 0;
}

unsigned short Font::getStringWidth(const char *str)
{
	unsigned short width = 0;
	unsigned int utf8;

	while (*str)
	{
		utf8 = getUtf8(&str);
		if (utf8 == 0x20)
		{
			width += getSpaceWidth();
		}
		else
		{
			setChar(utf8);
			if (mFaultFlag == false)
				width += getFontInfo()->width;
		}
	}

	return width;
}

unsigned short Font::getStringHeight(const char *str)
{
	unsigned short height = 0, tmp;
	unsigned int utf8;

	while (*str)
	{
		utf8 = getUtf8(&str);
		setChar(utf8);
		tmp = getFontInfo()->height;
		if (height < tmp)
			height = tmp;
	}

	return height;
}