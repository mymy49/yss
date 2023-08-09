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

#include <config.h>

#if USE_GUI

#include <mod/spi_tft_lcd/MSP3520.h>

error MSP3520::initialize(void)
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

	return error::ERROR_NONE;
}

MSP3520::MSP3520(void)
{
	setSize({320, 480});
}

#endif



