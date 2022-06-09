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

#ifndef YSS_MOD_CPUTFT_RX035H_19__H_
#define YSS_MOD_CPUTFT_RX035H_19__H_

#include <sac/CpuTft.h>
#include <yss/instance.h>

#if !defined(SPI_NOT_DEFINED)

namespace mod
{
namespace cputft
{
class RX035H_19 : public sac::CpuTft
{
  public:
	struct Config
	{
		void (*sendCmd)(unsigned char cmd);
		void (*sendData)(unsigned short data);
		void (*drawDot)(unsigned short x, unsigned short y, unsigned short color);
		void (*drawDots)(unsigned short x, unsigned short y, unsigned short color, unsigned short size);
		void (*drawDotsImg)(unsigned short x, unsigned short y, unsigned short *color, unsigned short size);
	};

	RX035H_19(void);
	void (*sendCmd_)(unsigned char cmd);
	void (*sendData_)(unsigned short data);
	void (*drawDot_)(unsigned short x, unsigned short y, unsigned short color);
	void (*drawDots_)(unsigned short x, unsigned short y, unsigned short color, unsigned short size);
	void (*drawDotsImg_)(unsigned short x, unsigned short y, unsigned short *color, unsigned short size);
	void gotoXy(unsigned short x, unsigned short y);

	bool init(const Config config);

	void drawDot(signed short x, signed short y);
	void drawDot(signed short x, signed short y, unsigned short color);
	void drawDot(signed short x, signed short y, unsigned int color);
	void drawDots(unsigned short x, unsigned short y, unsigned short color, unsigned short size);
	void drawDots(unsigned short x, unsigned short y, unsigned short *src, unsigned short size);
	void drawFontDot(signed short x, signed short y, unsigned char color);
	void eraseDot(Pos pos);
	void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
	void setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
	void setBgColor(unsigned char red, unsigned char green, unsigned char blue);
};
}
}

#endif

#endif

/*
// 설정 예제 코드
// 아래와 같은 동작을 하는 코드를 생성하라.

#define LCD_CS_ON setGpioB12()
#define LCD_CS_OFF resetGpioB12()

#define LCD_RS_ON setGpioB13()
#define LCD_RS_OFF resetGpioB13()

#define LCD_WR_ON setGpioB14()
#define LCD_WR_OFF resetGpioB14()

#define LCD_RD_ON setGpioB15()
#define LCD_RD_OFF resetGpioB15()

#define LCD_DAT(x) setGpioC(x)

void sendCmd(unsigned char cmd)
{
	LCD_CS_OFF;
	LCD_RS_OFF;
	LCD_DAT(cmd);
	LCD_WR_OFF;
	LCD_WR_ON;
	LCD_CS_ON;
}

void sendData(unsigned short data)
{
	LCD_CS_OFF;
	LCD_RS_ON;
	LCD_DAT(data);
	LCD_WR_OFF;
	LCD_WR_ON;
	LCD_CS_ON;
}

void drawDot(unsigned short x, unsigned short y, unsigned short color)
{
	LCD_CS_OFF;

	LCD_RS_OFF;
	LCD_DAT(0x2A);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	LCD_DAT(x >> 8);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(x & 0x00ff);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x01);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0xDF);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_OFF;
	LCD_DAT(0x2B);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	LCD_DAT(y >> 8);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(y & 0x00ff);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x01);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x3F);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_OFF;
	LCD_DAT(0x2C);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	LCD_DAT(color);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_CS_ON;
}

void drawDots(unsigned short x, unsigned short y, unsigned short color, unsigned short size)
{
	LCD_CS_OFF;

	LCD_RS_OFF;
	LCD_DAT(0x2A);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	LCD_DAT(x >> 8);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(x & 0x00ff);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x01);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0xDF);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_OFF;
	LCD_DAT(0x2B);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	LCD_DAT(y >> 8);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(y & 0x00ff);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x01);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x3F);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_OFF;
	LCD_DAT(0x2C);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	LCD_DAT(color);
	for(int i=0;i<size;i++)
	{
		LCD_WR_OFF;
		LCD_WR_ON;
	}

	LCD_CS_ON;
}

void drawDotsImg(unsigned short x, unsigned short y, unsigned short *color, unsigned short size)
{
	LCD_CS_OFF;

	LCD_RS_OFF;
	LCD_DAT(0x2A);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	LCD_DAT(x >> 8);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(x & 0x00ff);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x01);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0xDF);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_OFF;
	LCD_DAT(0x2B);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	LCD_DAT(y >> 8);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(y & 0x00ff);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x01);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_DAT(0x3F);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_OFF;
	LCD_DAT(0x2C);
	LCD_WR_OFF;
	LCD_WR_ON;

	LCD_RS_ON;
	for(int i=0;i<size;i++)
	{
		LCD_DAT(*color++);
		LCD_WR_OFF;
		LCD_WR_ON;
	}

	LCD_CS_ON;
}

mod::cputft::RX035H_19 lcd;

void init(void)
{
	using namespace define::gpio;

	// TFT LCD 초기화
	gpioB.setAsOutput(12, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsOutput(13, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsOutput(14, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsOutput(15, ospeed::FAST, otype::PUSH_PULL);

	gpioC.setAsOutput(0, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(1, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(2, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(3, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(4, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(5, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(6, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(7, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(8, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(9, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(10, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(11, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(12, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(13, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(14, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsOutput(15, ospeed::FAST, otype::PUSH_PULL);

	LCD_RD_ON;

	const mod::cputft::RX035H_19::Config gLcdConfig{
		sendCmd,
		sendData,
		drawDot,
		drawDots,
		drawDotsImg};

	lcd.init(gLcdConfig);
	lcd.setBgColor(0x00, 0x00, 0x00);
	lcd.clear();
}

*/
