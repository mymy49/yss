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

#ifndef YSS_GUI_PAINTER__H_
#define YSS_GUI_PAINTER__H_

#include "util.h"
#include "Object.h"
#include "Color.h"

namespace Painter
{
// yss_painter.cpp
void drawArea(Object &des, Position areaPos, Size areaSize, Object &src);
void draw(Object &des, Object &src);

// yss_painter_rgb565.cpp
void drawArea(Rgb565 &des, Position areaPos, Size areaSize, Rgb565 &src, Position srcPos);
void draw(Rgb565 &des, Rgb565 &src, Position pos);
void fill(Rgb565 &obj, Color color);
void fillRectangle(Rgb565 &obj, Position pos, Size size, Color color);
uint8_t drawChar(Rgb565 &des, Font *font, uint32_t utf8, Position pos, Color color);
void draw(Rgb565 &des, const Bmp565 *bmp, Position pos);

// yss_painter_rgb888.cpp
void drawArea(Rgb888 &des, Position areaPos, Size areaSize, Rgb888 &src, Position srcPos);
void draw(Rgb888 &des, Rgb888 &src, Position pos);
void fill(Rgb888 &obj, Color color);
void fillRectangle(Rgb888 &obj, Position pos, Size size, Color color);
uint8_t drawChar(Rgb888 &des, Font *font, uint32_t utf8, Position pos, Color color);
void draw(Rgb888 &des, const Bmp888 *bmp, Position pos);
void draw(Rgb888 &des, const Bmp565 *bmp, Position pos);
}

#endif

