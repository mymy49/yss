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

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9488__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9488__H_

#include <sac/TftLcdDriver.h>

class ILI9488 : public TftLcdDriver
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
		SLEEP_IN = 0x10,
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
		INTERFACE_MODE_CTRL = 0xB0,
		FRAME_RATE = 0xB1,
		DISPLAY_INVERSION_CTRL = 0xB4,
		DISPLAY_CTRL = 0xB6,
		ENTRY_MODE_SET = 0xB7,
		HS_LANES_CTRL = 0xBE,
		POWER_CTRL1 = 0xC0,
		POWER_CTRL2 = 0xc1,
		VCOM_CTRL1 = 0xC5,
		VCOM_CTRL2 = 0xC7,
		POWER_A = 0xCB,
		POWER_B = 0xCF,
		CMD_READ_ID1 = 0xDA,
		READ_ID2 = 0xDB,
		CMD_READ_ID3 = 0xDC,
		POS_GAMMA = 0xE0,
		NEG_GAMMA = 0xE1,
		DTCA = 0xE8,
		SET_IMAGE_FUNC = 0xE9,
		DTCB = 0xEA,
		POWER_SEQ = 0xED,
		GAMMA3_FUNC_DIS = 0xF2,
		ADJUST_CTRL3 = 0xF7
	};

	bool mRotateFlag;

  public:
	ILI9488(void);

	void setDirection(bool xMirror, bool yMirror, bool rotate);
	void setWindows(uint16_t x, uint16_t y, uint16_t width = 1, uint16_t height = 1);
};

#endif