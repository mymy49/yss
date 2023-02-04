////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_GUI_FONT__H_
#define YSS_GUI_FONT__H_

#define NUM_OF_ASCII_CODE 96
#define YSS_FONT_MAX_SUB_HEADER 8
#define NUM_OF_GROUP 8

#include <stdint.h>

struct YssFontInfo
{
	uint32_t offset;
	uint8_t width;
	uint8_t height;
	uint8_t ypos;
} __attribute__((packed));

struct YssFontHeaderPartUnicode
{
	int8_t yssFontStr[10];
	uint8_t subHeaderType = 1;
	YssFontInfo asciiFontInfo[NUM_OF_ASCII_CODE];
	uint8_t numOfGroup = NUM_OF_GROUP;
	uint16_t numOfChar[NUM_OF_GROUP];
	uint32_t offsetOfCode[NUM_OF_GROUP];
	uint32_t offsetOfFontInfo[NUM_OF_GROUP];
} __attribute__((packed));

struct YssFontHeaderAscii
{
	uint8_t subHeaderType = 0;
	YssFontInfo fontInfo[NUM_OF_ASCII_CODE];
} __attribute__((packed));

class Font
{
	uint8_t *mData, *mFb, mKind;
	bool mFaultFlag;
	YssFontInfo *mFontInfo;
	uint8_t mSpaceWidth, mCharWidth;

  public:
	Font(YssFontHeaderPartUnicode *font);
	Font(void);
	bool isAble(void);
	void setChar(int8_t ch);
	bool setChar(uint32_t utf8);
	void setFont(YssFontHeaderAscii *font);
	void setFont(YssFontHeaderPartUnicode *font);
	YssFontInfo *getFontInfo(void);
	uint8_t *getFrameBuffer(void);
	uint8_t getSpaceWidth(void);
	void setSpaceWidth(uint8_t width);
	uint8_t getCharWidth(void);
	void setCharWidth(uint8_t width);
	uint32_t getUtf8(const char **src);
	uint16_t getStringWidth(const char *str);
	uint16_t getStringHeight(const char *str);
};

#endif

