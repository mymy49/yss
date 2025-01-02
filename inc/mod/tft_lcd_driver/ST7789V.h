/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ST7789V__H_
#define YSS_MOD_TFT_LCD_DRIVER_ST7789V__H_

#include <sac/TftLcdDriver.h>

class ST7789V : public TftLcdDriver
{
  protected:
	typedef enum
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
		SLPOUT = 0x11,
		PARTIAL_MODE_ON = 0x12,
		NORMAL_DISP_MODE_ON = 0x13,
		DISP_INVERSION_OFF = 0x20,
		DISP_INVERSION_ON = 0x21,
		GAMMA_SET = 0x26,
		DISPLAY_OFF = 0x28,
		DISPON = 0x29,
		COLUMN_ADDRESS_SET = 0x2A,
		PAGE_ADDRESS_SET = 0x2B,
		MEMORY_WRITE = 0x2C,
		COLOR_SET = 0x2D,
		MEMORY_READ = 0x2E,
		PARTIAL_AREA = 0x30,
		VERT_SCROLL_DEFINITION = 0x33,
		TEARING_EFFECT_LINE_OFF = 0x34,
		TEARING_EFFECT_LINE_ON = 0x35,
		MADCTL = 0x36,
		VERT_SCROLL_START_ADDRESS = 0x37,
		IDLE_MODE_OFF = 0x38,
		IDLE_MODE_ON = 0x39,
		COLMOD = 0x3A,
		WRITE_MEMORY_CONTINUE = 0x3C,
		READ_MEMORY_CONTINUE = 0x3E,
		SET_TEAR_SCANLINE = 0x44,
		GET_SCANLINE = 0x45,
		WRITE_DISPLAY_BRIGHTNESS = 0x51,
		READ_DISPLAY_BRIGHTNESS = 0x52,
		WRITE_CTRL_DISPLAY = 0x53,
		READ_CTRL_DISPLAY = 0x54,
		WRCACE = 0x55,
		READ_CONTENT_ADAPT_BRIGHTNESS = 0x56,
		WRITE_MIN_CAB_LEVEL = 0x5E,
		READ_MIN_CAB_LEVEL = 0x5F,
		INTERFACE_MODE_CON = 0xB0,
		FRAME_RATE = 0xB1,
		PORCTL = 0xB2,
		DISPLAY_INVERSION_CON = 0xB4,
		BLANKING_PORCH_CON = 0xB5,
		DISPLAY_CTRL = 0xB6,
		GATE_CTRL = 0xB7,
		VCOMS = 0xBB,
		LCMCTLR = 0xC0,
		POWER_CTRL2 = 0xC1,
		VDVVRHEN = 0xC2,
		VRHS = 0xC3,
		VDVS = 0xC4,
		VCOM_CTRL1 = 0xC5,
		FRCTRL2 = 0xC6,
		VCOM_CTRL2 = 0xc7,
		POWER_A = 0xcb,
		POWER_B = 0xcf,
		PWCTRL1 = 0xD0,
		READ_ID1 = 0xDA,
		READ_ID2 = 0xDB,
		READ_ID3 = 0xDC,
		PVGAMCTRL = 0xE0,
		NVGAMCTRL = 0xE1,
		DTCA = 0xE8,
		DTCB = 0xea,
		POWER_SEQ = 0xed,
		SET_CONFIG = 0xF0,
		GAMMA3_FUNC_DIS = 0xf2,
		PRC = 0xf7
	}cmd_t;

	bool mRotateFlag;

  public:
	ST7789V(void);

	void setDirection(bool xMirror, bool yMirror, bool rotate);

	void setWindows(uint16_t x, uint16_t y, uint16_t width = 1, uint16_t height = 1);
};

#endif