/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss/debug.h>

#if USE_GUI

#include <mod/spi_tft_lcd/Touch_LCD_Shield_for_Arduino_2_8_inch.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

#include <std_ext/string.h>

static const Spi::specification_t gLcdSpec =
{
	Spi::MODE_MODE1,	//uint8_t mode;
	36000000,			//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
};

Touch_LCD_Shield_for_Arduino_2_8_inch::Touch_LCD_Shield_for_Arduino_2_8_inch(void)
{
	Brush::setSize(Size_t{240, 320});
}

error_t Touch_LCD_Shield_for_Arduino_2_8_inch::initialize(void)
{
	Color color;

	color.setReverseRgbOrder(true);
	setSpiSpecification(gLcdSpec);

	reset();
	
	thread::delay(50);
	enable();

	uint8_t des;
	read(0x04, des);

	sendCmd(MADCTL, 0x00);

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
	thread::delay(50);

	sendCmd(SLPOUT);
	thread::delay(50);

	sendCmd(DISPON);
	thread::delay(50);

	disable();

	return error_t::ERROR_NONE;
}

Size_t Touch_LCD_Shield_for_Arduino_2_8_inch::getLcdSize(void)
{
	return Size_t{240, 320};
}


#endif

#endif



