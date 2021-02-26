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

    if (utf8 > 0x1F && utf8 < 0x80)
    {
        utf8 -= 0x21;
        mFaultFlag = false;
        mFontInfo = &header->asciiFontInfo[utf8];
        mFb = &mData[mFontInfo->offset];
        return mFaultFlag;
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

bool Font::isHaveSpaceWidth(void)
{
    if (mSpaceWidth)
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

void Font::setFont(YssFontHeaderAscii *font)
{
    //	mData = (unsigned char*)font;
    //	mMainHeader = (YssFontMainHeader*)font;
    //
    //	for(int i=0;i<mMainHeader->numOfLanguage;i++)
    //	{
    //		switch(mData[mMainHeader->offsetOfsubHeader[i]])
    //		{
    //		case 0 : // Ascii
    //			mAsciiHeader = (YssFontSubHeaderAscii*)&mData[mMainHeader->offsetOfsubHeader[i]];
    //			break;
    //		}
    //	}
}

unsigned int Font::getUtf8(char **src)
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

    *(src++);
    return 0;
}

unsigned short Font::getStringWidth(char *str)
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
            width += getFontInfo()->width;
        }
    }

    return width;
}

unsigned short Font::getStringHeight(char *str)
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