/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <mod/spi_tft_lcd/MSP4021.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

#include <std_ext/string.h>

MSP4021::MSP4021(void)
{
	Brush::setSize(Size_t{320, 480});
}

error_t MSP4021::initialize(void)
{
	reset();
	
	thread::delay(500);
	enable();

	const uint8_t cscon1[] = {0xC3};
	sendCmd(SET_CONFIG, (int8_t *)cscon1, sizeof(cscon1));

	const uint8_t cscon2[] = {0x96};
	sendCmd(SET_CONFIG, (int8_t *)cscon2, sizeof(cscon2));

	uint8_t memAccCtrl[] = {0x00};
	sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));

	const uint8_t fixelFormat[] = {0x06};
	sendCmd(COLMOD_PIXEL_FORMAT_SET, (int8_t *)fixelFormat, sizeof(fixelFormat));

	const uint8_t interfaceModeCon[] = {0x80};
	sendCmd(INTERFACE_MODE_CON, (int8_t *)interfaceModeCon, sizeof(interfaceModeCon));

	const uint8_t displayCtrl[] = {0x00, 0x02};
	sendCmd(DISPLAY_CTRL, (int8_t *)displayCtrl, sizeof(displayCtrl));
	
	const uint8_t blankingPorchCon[] = {0x02, 0x03, 0x00, 0x04};
	sendCmd(BLANKING_PORCH_CON, (int8_t *)blankingPorchCon, sizeof(blankingPorchCon));

	const uint8_t frameRate[] = {0x80, 0x10};
	sendCmd(FRAME_RATE, (int8_t *)frameRate, sizeof(frameRate));

	const uint8_t displayInvCon[] = {0x00};
	sendCmd(DISPLAY_INVERSION_CON, (int8_t *)displayInvCon, sizeof(displayInvCon));

	const uint8_t entryModeSet[] = {0xC6};
	sendCmd(ENTRY_MODE_SET, (int8_t *)entryModeSet, sizeof(entryModeSet));
	
	const uint8_t vcomCtrl1[] = {0x24};
	sendCmd(VCOM_CTRL1, (int8_t *)vcomCtrl1, sizeof(vcomCtrl1));

	const uint8_t unknown[] = {0x31};
	sendCmd(0xE4, (int8_t *)unknown, sizeof(unknown));

	const uint8_t dtca[] = {0x40, 0x8A, 0x00, 0x00, 0x29, 0x19, 0xA5, 0x33};
	sendCmd(DTCA, (int8_t *)dtca, sizeof(dtca));

	const uint8_t posGamma[] = {0xF0, 0x09, 0x13, 0x12, 0x12, 0x2B, 0x3C, 0x44, 0x4B, 0x1B, 0x18, 0x17, 0x1D, 0x21};
	sendCmd(POS_GAMMA, (int8_t *)posGamma, sizeof(posGamma));

	const uint8_t negGamma[] = {0xF0, 0x09, 0x13, 0x0C, 0x0D, 0x27, 0x3B, 0x44, 0x4D, 0x0B, 0x17, 0x17, 0x1D, 0x21};
	sendCmd(NEG_GAMMA, (int8_t *)negGamma, sizeof(negGamma));

	sendCmd(NORMAL_DISP_MODE_ON);
	
	sendCmd(SLEEP_OUT);
	thread::delay(100);

	sendCmd(DISPLAY_ON);
	thread::delay(50);

	disable();

	return error_t::ERROR_NONE;
}

#endif

#endif



