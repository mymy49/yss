////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI

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

bool Font::setChar(uint32_t utf8)
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
		uint32_t group = utf8 % header->numOfGroup, numOfChar, *code;
		YssFontInfo *info = (YssFontInfo *)&mData[header->offsetOfFontInfo[group]];
		code = (uint32_t *)&mData[header->offsetOfCode[group]];
		numOfChar = header->numOfChar[group];

		for (uint32_t  i = 0; i < numOfChar; i++)
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

uint8_t *Font::getFrameBuffer(void)
{
	if (mFaultFlag)
		return 0;
	else
		return mFb;
}

void Font::setFont(YssFontHeaderPartUnicode *font)
{
	mData = (uint8_t *)font;
}

uint8_t Font::getSpaceWidth(void)
{
	YssFontHeaderPartUnicode *header = (YssFontHeaderPartUnicode *)mData;

	if (mSpaceWidth)
		return mSpaceWidth;
	else if (mCharWidth)
		return mCharWidth;
	else
		return header->asciiFontInfo['I' - 0x21].width;
}

void Font::setSpaceWidth(uint8_t width)
{
	mSpaceWidth = width;
}

uint8_t Font::getCharWidth(void)
{
	return mCharWidth;
}

void Font::setCharWidth(uint8_t width)
{
	mCharWidth = width;
}

uint32_t Font::getUtf8(const char **src)
{
	uint32_t utf8;

	if (*(*src) >= 0xe0)
	{
		utf8 = (uint32_t)*(*src)++ << 16;
		utf8 |= (uint32_t)*((*src)++) << 8;
		utf8 |= *(*src)++;
		return utf8; 
	}
	else if (*(*src) >= 0xc0)
	{
		utf8 = (uint32_t)*((*src)++) << 8;
		utf8 |= *(*src)++;
		return utf8; 
	}
	else if (*(*src) < 0x80)
	{
		return *(*src)++;
	}

	(*src)++;
	return 0;
}

uint16_t Font::getStringWidth(const char *str)
{
	uint16_t width = 0, buf;
	uint32_t utf8;

	if(mCharWidth)
	{
		while (*str)
		{
			utf8 = getUtf8(&str);
			if (utf8 == 0x20)
			{
				buf = getSpaceWidth();
			}
			else
			{
				setChar(utf8);
				if (mFaultFlag == false)
					buf = getFontInfo()->width;
			}

			if(buf > mCharWidth)
				width += buf;
			else
				width += mCharWidth;
		}
	}
	else
	{
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
	}

	return width;
}

uint16_t Font::getStringHeight(const char *str)
{
	uint16_t height = 0, tmp;
	uint32_t utf8;
	YssFontInfo *info;

	while (*str)
	{
		utf8 = getUtf8(&str);
		if(utf8 != 0x20)
		{
			setChar(utf8);
			info = getFontInfo();
			tmp = info->height + info->ypos;
			if (height < tmp)
			{
				height = tmp;
			}
		}
	}

	return height;
}

#endif

