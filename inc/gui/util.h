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

#ifndef YSS_GUI_UTIL__H_
#define YSS_GUI_UTIL__H_

#include <stdint.h>
#include <config.h>

struct Position
{
	int16_t x, y;
};

struct Size
{
	uint16_t width, height;
};

#if (RGB_ORDER_REVERSE == true)
struct RGB565_struct
{
	unsigned red : 5;
	unsigned green : 6;
	unsigned blue : 5;
};
#else
struct RGB565_struct
{
	unsigned blue : 5;
	unsigned green : 6;
	unsigned red : 5;
};
#endif

union RGB565_union
{
	RGB565_struct color;
	uint16_t halfword;
	uint8_t byte[2];
};

struct RGB888_struct
{
	unsigned blue : 8;
	unsigned green : 8;
	unsigned red : 8;
};

union RGB888_union
{
	RGB888_struct color;
	uint8_t byte[3];
};

class Font;

struct FontSize
{
	uint8_t width;
	uint8_t height;
};

struct FontInfo
{
	FontSize *size;
	int8_t *yPos;
	uint32_t *pointer;
	uint8_t *base;
};

extern "C"
{
	void copyRgb888DotPattern(void *des, uint32_t pattern, uint32_t count);
}

#endif

