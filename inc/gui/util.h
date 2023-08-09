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

