////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MOD_SPI_TFT_LCD_MSP2402__H_
#define YSS_MOD_SPI_TFT_LCD_MSP2402__H_

#include <config.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

#include <mod/tft_lcd_driver/ILI9341.h>
#include <gui/Brush.h>
#include <yss/Mutex.h>
#include <gui/Bmp565Buffer.h>

class MSP2402 : public ILI9341, public Brush
{

  protected:
	RGB888_union mBrushColor, mBgColor;
	Bmp565Buffer *mBmpBuffer;
	uint32_t mBmpBufferSize;

  public:
	MSP2402(void);
	void setDirection(bool xMirror, bool yMirror, bool rotate); // virtual
	void setBmp565Buffer(Bmp565Buffer &obj);

	// Brush
	void drawDot(int16_t x, int16_t y); // virtual 0
	void drawDot(int16_t x, int16_t y, uint16_t color); // virtual 0
	void drawDot(int16_t x, int16_t y, uint32_t color); // virtual 0
	void drawFontDot(int16_t x, int16_t y, uint8_t color); // virtual 0
	void eraseDot(Position pos); // virtual 0
	void setBrushColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255); // virtual 0
	void setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255); // virtual 0
	void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue); // virtual 0
	void clear(void); // virtual
	void fillRect(Position p1, Position p2);
	void fillRect(Position pos, Size size);
	void drawBmp(Position pos, const Bmp565 *image);
};

#endif

#endif

