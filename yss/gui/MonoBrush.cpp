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
//  Copyright 2021.yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2021.02.23 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <gui/MonoBrush.h>

MonoBrush::MonoBrush(void)
{
	mSize.width = 0;
	mSize.height = 0;
}

void MonoBrush::setFont(Font font)
{
    mFont = font;
}

unsigned char MonoBrush::drawChar(Pos pos, unsigned int utf8)
{
    if (mFont.setChar(utf8))
        return 0;

    YssFontInfo *fontInfo = mFont.getFontInfo();
    unsigned char *fontFb = mFont.getFrameBuffer(), color;
    int index = 0;
    unsigned short width = fontInfo->width, height = fontInfo->height, offset = 0;
    signed short xs = pos.x, ys = pos.y;// + (signed char)fontInfo->ypos;

    if (xs + width > 127)
    {
        width = 127 - xs;
        offset = fontInfo->width - width;
    }
    if (ys + height > 31)
        height = 31 - ys;

    width += xs;
    height += ys;

    for (int y = ys; y < height; y++)
    {
        for (int x = xs; x < width; x++, index++)
        {
            if (index % 2 == 0)
            {
                color = fontFb[index / 2] & 0x0f;
                if (color > 5)
					drawDot(x, y, true);
                else
					drawDot(x, y, false);
            }
            else
            {
                color = (fontFb[index / 2] >> 4) & 0x0f;
                if (color > 5)
					drawDot(x, y, true);
                else
					drawDot(x, y, false);
            }
        }
        index += offset;
    }

    return fontInfo->width;
}
