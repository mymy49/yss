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

#ifndef YSS_MOD_TFT_LCD_DRIVER_ST7796S__H_
#define YSS_MOD_TFT_LCD_DRIVER_ST7796S__H_

#include <sac/TftLcdDriver.h>

class ST7796S : public TftLcdDriver
{
  protected:
	enum
	{
		NOP = 0x00,
		SOFTWARE_RESET = 0x01,
		READ_DISP_ID = 0x04,
		READ_DISP_STATUS = 0x09,
		READ_DISP_MADCTRL = 0x0B,
		READ_DISP_PIXEL_FORMAT = 0x0C,
		READ_DISP_IMAGE_FORMAT = 0x0D,
		READ_DISP_SIGNAL_MODE = 0x0E,
		READ_DISP_SELF_DIAGNOSTIC = 0x0F,
		ENTER_SLEEP_MODE = 0x10,
		SLEEP_OUT = 0x11,
		PARTIAL_MODE_ON = 0x12,
		NORMAL_DISP_MODE_ON = 0x13,
		DISP_INVERSION_OFF = 0x20,
		DISP_INVERSION_ON = 0x21,
		GAMMA_SET = 0x26,
		DISPLAY_OFF = 0x28,
		DISPLAY_ON = 0x29,
		COLUMN_ADDRESS_SET = 0x2A,
		PAGE_ADDRESS_SET = 0x2B,
		MEMORY_WRITE = 0x2C,
		COLOR_SET = 0x2D,
		MEMORY_READ = 0x2E,
		PARTIAL_AREA = 0x30,
		VERT_SCROLL_DEFINITION = 0x33,
		TEARING_EFFECT_LINE_OFF = 0x34,
		TEARING_EFFECT_LINE_ON = 0x35,
		MEMORY_ACCESS_CONTROL = 0x36,
		VERT_SCROLL_START_ADDRESS = 0x37,
		IDLE_MODE_OFF = 0x38,
		IDLE_MODE_ON = 0x39,
		COLMOD_PIXEL_FORMAT_SET = 0x3A,
		WRITE_MEMORY_CONTINUE = 0x3C,
		READ_MEMORY_CONTINUE = 0x3E,
		SET_TEAR_SCANLINE = 0x44,
		GET_SCANLINE = 0x45,
		WRITE_DISPLAY_BRIGHTNESS = 0x51,
		READ_DISPLAY_BRIGHTNESS = 0x52,
		WRITE_CTRL_DISPLAY = 0x53,
		READ_CTRL_DISPLAY = 0x54,
		WRITE_CONTENT_ADAPT_BRIGHTNESS = 0x55,
		READ_CONTENT_ADAPT_BRIGHTNESS = 0x56,
		WRITE_MIN_CAB_LEVEL = 0x5E,
		READ_MIN_CAB_LEVEL = 0x5F,
		INTERFACE_MODE_CON = 0xB0,
		FRAME_RATE = 0xB1,
		DISPLAY_INVERSION_CON = 0xB4,
		BLANKING_PORCH_CON = 0xB5,
		DISPLAY_CTRL = 0xB6,
		ENTRY_MODE_SET = 0xB7,
		POWER_CTRL1 = 0xc0,
		POWER_CTRL2 = 0xc1,
		POWER_CTRL3 = 0xC2,
		VCOM_CTRL1 = 0xC5,
		VCOM_CTRL2 = 0xc7,
		POWER_A = 0xcb,
		POWER_B = 0xcf,
		READ_ID1 = 0xDA,
		READ_ID2 = 0xDB,
		READ_ID3 = 0xDC,
		POS_GAMMA = 0xE0,
		NEG_GAMMA = 0xE1,
		DTCA = 0xE8,
		DTCB = 0xea,
		POWER_SEQ = 0xed,
		SET_CONFIG = 0xF0,
		GAMMA3_FUNC_DIS = 0xf2,
		PRC = 0xf7
	};

	bool mRotateFlag;

  public:
	ST7796S(void);

	void setDirection(bool xMirror, bool yMirror, bool rotate);
	void setWindows(uint16_t x, uint16_t y, uint16_t width = 1, uint16_t height = 1);
};

#endif