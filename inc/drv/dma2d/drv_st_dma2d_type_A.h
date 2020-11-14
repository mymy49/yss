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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_DMA2D_ST_TYPE_A__H_
#define YSS_DRV_DMA2D_ST_TYPE_A__H_

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <yss/mcu.h>
#include <config.h>

#include "drv_st_dma2d_type_A_define.h"
#include <yss/thread.h>
#include <yss/gui.h>
#include <drv/Drv.h>

class Font;

struct FontSize
{
	unsigned char width;
	unsigned char height;
};

struct FontInfo
{
	FontSize *size;
	signed char *yPos;
	unsigned long *pointer;
	unsigned char *base;
};

namespace drv
{
	class Dma2d : public Drv
	{
		FontInfo mFontInfo;
		Mutex mMutex;
	public :
		Dma2d(DMA2D_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
		void init(void);
		void setFontColor(unsigned char red, unsigned char green, unsigned char blue);
		void draw(Object &des, Object &src);
		void drawArea(Object &des, Pos areaPos, Size areaSize, Object &src);
		Size calculateStringSize(char *str);
		unsigned short convertUtf8ToUtf16(char *ch);
		unsigned char getFontSize(void);

		unsigned char drawChar(Rgb565 &des, Font *font, unsigned int utf8, Pos pos, unsigned int color, unsigned char alpha = 0xff);
		void fill(Rgb565 &obj, RGB565_union color);
		void fillRectangle(Rgb565 &obj, Pos pos, Size size, RGB565_union color);
		void fillRectangle(Rgb565 &obj, Pos sp, Pos ep, RGB565_union color);
		void draw(Rgb565 &des, Rgb565 &src, Pos pos);
		void draw(Rgb565 &des, const Bmp565 *bmp, Pos pos);
		void drawArea(Rgb565 &des, Pos areaPos, Size areaSize, Rgb565 &src, Pos srcPos);

		unsigned char drawChar(Rgb888 &des, Font *font, unsigned int utf8, Pos pos, unsigned int color, unsigned char alpha = 0xff);
		void fill(Rgb888 &obj, RGB888_union color);
		void fillRectangle(Rgb888 &obj, Pos pos, Size size, RGB888_union color);
		void fillRectangle(Rgb888 &obj, Pos sp, Pos ep, RGB888_union color);
		void draw(Rgb888 &des, Rgb888 &src, Pos pos);
		void draw(Rgb888 &des, const Bmp565 *bmp, Pos pos);
		void drawArea(Rgb888 &des, Pos areaPos, Size areaSize, Rgb888 &src, Pos srcPos);

//		char drawChar(Argb1555 &des, char *ch, Pos pos);
//		char drawChar(Argb1555 &des, char ch, Pos pos);


//		void fill(Argb1555 &obj, ARGB1555_union color);

//		void fillRectangle(Argb1555 &obj, Pos sp, Pos ep, ARGB1555_union color);
//		void fillRectangle(Argb1555 &obj, Pos pos, Size size, ARGB1555_union color);

//		void draw(Argb1555 &des, Argb1555 &src, Pos pos);

//		void draw(Argb1555 &des, Rgb565 &src, Pos pos);
//		void draw(Argb1555 &des, Rgb888 &src, Pos pos);
//		void draw(Rgb565 &des, Argb1555 &src, Pos pos);
//		void draw(Rgb565 &des, Rgb888 &src, Pos pos);
//		void draw(Rgb888 &des, Argb1555 &src, Pos pos);
//		void draw(Rgb888 &des, Rgb565 &src, Pos pos);
//		void drawArea(Rgb888 &des, Pos areaPos, Size areaSize, Rgb888 &src, Pos srcPos);


	};
}

#if	defined(DMA2D) && USE_GUI
extern  drv::Dma2d dma2d;
#endif

#endif
#endif
