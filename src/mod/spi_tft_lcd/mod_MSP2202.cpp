/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <mod/spi_tft_lcd/MSP2202.h>

error_t MSP2202::initialize(void)
{
	enable();

	reset();

	sendCmd(DISPLAY_OFF);

	const uint8_t powerB[3] = {0x00, 0xc1, 0x30};
	sendCmd(POWER_B, (int8_t *)powerB, sizeof(powerB));

	const uint8_t powerSeq[4] = {0x64, 0x03, 0x12, 0x81};
	sendCmd(POWER_SEQ, (int8_t *)powerSeq, sizeof(powerSeq));

	const uint8_t dtca[3] = {0x85, 0x10, 0x7A};
	sendCmd(DTCA, (int8_t *)dtca, sizeof(dtca));

	const uint8_t powerA[5] = {0x39, 0x2c, 0x00, 0x34, 0x02};
	sendCmd(POWER_A, (int8_t *)powerA, sizeof(powerA));

	sendCmd(ADJUST_CTRL3, 0x02);

	const uint8_t dtcb[2] = {0x00, 0x00};
	sendCmd(DTCB, (int8_t *)dtcb, sizeof(dtcb));

	const uint8_t frameRate[2] = {0x00, 0x1A};
	sendCmd(FRAME_RATE, (int8_t *)frameRate, sizeof(frameRate));

	const uint8_t displayCtrl1[2] = {0x0A, 0xA2};
	sendCmd(DISPLAY_CTRL, (int8_t *)displayCtrl1, sizeof(displayCtrl1));

	sendCmd(POWER_CTRL1, 0x1B);

	sendCmd(POWER_CTRL2, 0x01);

	const uint8_t vcomCtrl1[2] = {0x30, 0x30};
	sendCmd(VCOM_CTRL1, (int8_t *)vcomCtrl1, sizeof(vcomCtrl1));

	sendCmd(VCOM_CTRL2, 0xB7);

	sendCmd(MEMORY_ACCESS_CONTROL, 0x48);

	sendCmd(COLMOD_PIXEL_FORMAT_SET, 0x55);

	sendCmd(GAMMA3_FUNC_DIS, 0x00);

	sendCmd(GAMMA_SET, 0x01);

	const uint8_t posGamma[15] = {0x0F, 0x29, 0x24, 0x0c, 0x0E, 0x09, 0x4E, 0x78, 0x3C, 0x09, 0x13, 0x05, 0x17, 0x11, 0x00};
	sendCmd(POS_GAMMA, (int8_t *)posGamma, sizeof(posGamma));

	const uint8_t negGamma[15] = {0x00, 0x16, 0x1B, 0x04, 0x11, 0x07, 0x31, 0x33, 0x42, 0x05, 0x0C, 0x0A, 0x28, 0x2F, 0x0F};
	sendCmd(NEG_GAMMA, (int8_t *)negGamma, sizeof(negGamma));

	sendCmd(SLEEP_OUT);
	thread::delay(200);

	sendCmd(DISPLAY_ON);
	sendCmd(MEMORY_WRITE);
	
	disable();

	return error_t::ERROR_NONE;
}

Size_t MSP2202::getLcdSize(void)
{
	return Size_t{240, 320};
}

MSP2202::MSP2202(void)
{
	setSize({240, 320});
	setColorMode(COLOR_MODE_RGB565);
}

#endif



