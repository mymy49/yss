/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <mod/spi_tft_lcd/MSP3520.h>

error_t MSP3520::initialize(void)
{
	reset();

	enable();

	sendCmd(DISPLAY_OFF);

	const uint8_t adjCtr3[] = {0xA9, 0x51, 0x2C, 0x82};
	sendCmd(ADJUST_CTRL3, (int8_t *)adjCtr3, sizeof(adjCtr3));

	const uint8_t powerCtrl1[] = {0x11, 0x09};
	sendCmd(POWER_CTRL1, (int8_t *)powerCtrl1, sizeof(powerCtrl1));

	const uint8_t powerCtrl2[] = {0x41};
	sendCmd(POWER_CTRL2, (int8_t *)powerCtrl2, sizeof(powerCtrl2));

	const uint8_t vcomCtrl1[] = {0x00, 0x0A, 0x80};
	sendCmd(VCOM_CTRL1, (int8_t *)vcomCtrl1, sizeof(vcomCtrl1));

	const uint8_t frameRate[] = {0xB0, 0x11};
	sendCmd(FRAME_RATE, (int8_t *)frameRate, sizeof(frameRate));

	const uint8_t dispInvCtrl[] = {0x02};
	sendCmd(DISPLAY_INVERSION_CTRL, (int8_t *)dispInvCtrl, sizeof(dispInvCtrl));

	const uint8_t displayCtrl1[] = {0x02, 0x42};
	sendCmd(DISPLAY_CTRL, (int8_t *)displayCtrl1, sizeof(displayCtrl1));

	const uint8_t etyModSet[] = {0xC6};
	sendCmd(ENTRY_MODE_SET, (int8_t *)etyModSet, sizeof(etyModSet));

	const uint8_t hsLanesCtrl[] = {0x00, 0x04};
	sendCmd(HS_LANES_CTRL, (int8_t *)hsLanesCtrl, sizeof(hsLanesCtrl));

	const uint8_t setImgFunc[] = {0x00};
	sendCmd(SET_IMAGE_FUNC, (int8_t *)setImgFunc, sizeof(setImgFunc));

	uint8_t memAccCtrl[] = {0x00};
	sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));

	const uint8_t fixelFormat[] = {0x66};
	sendCmd(COLMOD_PIXEL_FORMAT_SET, (int8_t *)fixelFormat, sizeof(fixelFormat));

	const uint8_t posGamma[15] = {0x00, 0x07, 0x10, 0x09, 0x17, 0x0B, 0x41, 0x89, 0x4B, 0x0A, 0x0C, 0x0E, 0x18, 0x1B, 0x0F};
	sendCmd(POS_GAMMA, (int8_t *)posGamma, sizeof(posGamma));

	const uint8_t negGamma[15] = {0x00, 0x17, 0x1A, 0x04, 0x0E, 0x06, 0x2F, 0x45, 0x43, 0x02, 0x0A, 0x09, 0x32, 0x36, 0x0F};
	sendCmd(NEG_GAMMA, (int8_t *)negGamma, sizeof(negGamma));

	sendCmd(SLEEP_OUT);
	thread::delay(200);

	sendCmd(DISPLAY_ON);
	sendCmd(MEMORY_WRITE);
	
	disable();

	return error_t::ERROR_NONE;
}

MSP3520::MSP3520(void)
{
	setSize({320, 480});
	setColorMode(COLOR_MODE_RGB888);
}

Size_t MSP3520::getLcdSize(void)
{
	return Size_t{320, 480};
}

#endif



