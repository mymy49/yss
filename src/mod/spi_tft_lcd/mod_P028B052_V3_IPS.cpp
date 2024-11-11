/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss/debug.h>

#if USE_GUI

#include <mod/spi_tft_lcd/P028B052_V3_IPS.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

#include <std_ext/string.h>

P028B052_V3_IPS::P028B052_V3_IPS(void)
{
	Brush::setSize(Size_t{240, 320});
}

error_t P028B052_V3_IPS::initialize(void)
{
	Color color;

	reset();
	
	thread::delay(500);
	enable();

	uint8_t des;
	read(0x04, des);

	sendCmd(MADCTL, 0x08);

	sendCmd(COLMOD, 0x55);

	sendCmd(GATE_CTRL, 0x35);

	sendCmd(VCOMS, 0x2B);

	sendCmd(VRHS, 0x11);
	
	sendCmd(VDVS, 0x20);
	
	sendCmd(FRCTRL2, 0x0F);

	const uint8_t pwctrl1[] = {0xA4, 0xA1};
	sendCmd(PWCTRL1, (int8_t *)pwctrl1, sizeof(pwctrl1));

	const uint8_t pvgamctrl[] = {0xD0, 0x01, 0x08, 0x0F, 0x11, 0x2A, 0x36, 0x55, 0x44, 0x3A, 0x0B, 0x06, 0x11, 0x20};
	sendCmd(PVGAMCTRL, (int8_t *)pvgamctrl, sizeof(pvgamctrl));
	
	const uint8_t nvgamctrl[] = {0xD0, 0x02, 0x07, 0x0A, 0x0B, 0x18, 0x34, 0x43, 0x4A, 0x2B, 0x1B, 0x1C, 0x22, 0x1F};
	sendCmd(NVGAMCTRL, (int8_t *)nvgamctrl, sizeof(nvgamctrl));
	
	sendCmd(WRCACE, 0xB0);
	
	sendCmd(DISP_INVERSION_ON);
	thread::delay(100);

	sendCmd(SLPOUT);
	thread::delay(100);

	sendCmd(DISPON);
	thread::delay(50);

	disable();

	return error_t::ERROR_NONE;
}

Size_t P028B052_V3_IPS::getLcdSize(void)
{
	return Size_t{240, 320};
}


#endif

#endif



