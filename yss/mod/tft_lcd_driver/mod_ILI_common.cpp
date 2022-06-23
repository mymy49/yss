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

#include <mod/tft_lcd_driver/ILI_common.h>

namespace CMD
{
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
	FRAME_RATE = 0xB1,
	DISPLAY_CTRL = 0xB6,
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
	DTCB = 0xEa,
	POWER_SEQ = 0xED,
	GAMMA3_FUNC_DIS = 0xF2,
	PRC = 0xF7
};
}

ILI_common::ILI_common(void)
{

}

void ILI_common::reset()
{
	sendCmd(CMD::SOFTWARE_RESET);
}

void ILI_common::setPowerVreg(unsigned char posRegVolt, unsigned char negRegVolt)
{
	unsigned char data[2];

	data[0] = posRegVolt & 0x1F;
	data[1] = negRegVolt & 0x1F;

	sendCmd(CMD::POWER_CTRL1, data, 2);
}

void ILI_common::setPowerStepupFactor(unsigned char bt)
{
	bt = 0x40 | (bt & 0x07);
	sendCmd(CMD::POWER_CTRL2, &bt, 1);
}

void ILI_common::setPowerVcomControl(unsigned char reg)
{
	unsigned char data[2] = {0, reg};

	sendCmd(CMD::VCOM_CTRL1, data, 1);
}

void ILI_common::setFrameRate(unsigned char reg)
{
	unsigned char data[2] = {0, reg};

	sendCmd(CMD::VCOM_CTRL1, data, 1);
}

void ILI_common::setSleep(bool en)
{
	if(en)
		sendCmd(CMD::SLEEP_IN);
	else
		sendCmd(CMD::SLEEP_OUT);
}

void ILI_common::setDisplayOn(bool en)
{
	if(en)
		sendCmd(CMD::DISPLAY_ON);
	else
		sendCmd(CMD::DISPLAY_OFF);
}

void ILI_common::setToNormalDisplay(void)
{
	sendCmd(CMD::NORMAL_DISP_MODE_ON);
}

void ILI_common::setWindows(unsigned short x, unsigned short y, unsigned short width, unsigned short height)
{
	unsigned char data[4];
	unsigned short end;

	end = x + width - 1;
	data[0] = x >> 8;
	data[1] = x & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(CMD::COLUMN_ADDRESS_SET, data, 4);
	
	end = y + height - 1;
	data[0] = y >> 8;
	data[1] = y & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(CMD::PAGE_ADDRESS_SET, data, 4);
}

void ILI_common::setPixelFormat(unsigned char format)
{
	sendCmd(CMD::VCOM_CTRL1, &format, 1);
}


