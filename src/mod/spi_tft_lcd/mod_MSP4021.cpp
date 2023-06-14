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

#include <config.h>

#if USE_GUI

#include <mod/spi_tft_lcd/MSP4021.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

#include <std_ext/string.h>

MSP4021::MSP4021(void)
{
	Brush::setSize(Size{320, 480});
}

error MSP4021::initialize(void)
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

	return error::ERROR_NONE;
}

#endif

#endif



