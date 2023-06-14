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

#include <mod/spi_tft_lcd/MSP2402.h>

error MSP2402::initialize(void)
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

	const uint8_t prc[1] = {0x20};
	sendCmd(ADJUST_CTRL3, (int8_t *)prc, sizeof(prc));

	const uint8_t dtcb[2] = {0x00, 0x00};
	sendCmd(DTCB, (int8_t *)dtcb, sizeof(dtcb));

	const uint8_t frameRate[2] = {0x00, 0x1A};
	sendCmd(FRAME_RATE, (int8_t *)frameRate, sizeof(frameRate));

	const uint8_t displayCtrl1[2] = {0x0A, 0xA2};
	sendCmd(DISPLAY_CTRL, (int8_t *)displayCtrl1, sizeof(displayCtrl1));

	const uint8_t powerCtrl1[1] = {0x1B};
	sendCmd(POWER_CTRL1, (int8_t *)powerCtrl1, sizeof(powerCtrl1));

	const uint8_t powerCtrl2[1] = {0x01};
	sendCmd(POWER_CTRL2, (int8_t *)powerCtrl2, sizeof(powerCtrl2));

	const uint8_t vcomCtrl1[2] = {0x30, 0x30};
	sendCmd(VCOM_CTRL1, (int8_t *)vcomCtrl1, sizeof(vcomCtrl1));

	const uint8_t vcomCtrl2[1] = {0xB7};
	sendCmd(VCOM_CTRL2, (int8_t *)vcomCtrl2, sizeof(vcomCtrl2));

	uint8_t memAccCtrl[] = {0x48};
	sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));

	const uint8_t fixelFormat[1] = {0x55};
	sendCmd(COLMOD_PIXEL_FORMAT_SET, (int8_t *)fixelFormat, sizeof(fixelFormat));

	const uint8_t gammaFuncDis[1] = {0x00};
	sendCmd(GAMMA3_FUNC_DIS, (int8_t *)gammaFuncDis, sizeof(gammaFuncDis));

	const uint8_t gammaSet4[1] = {0x01};
	sendCmd(GAMMA_SET, (int8_t *)gammaSet4, sizeof(gammaSet4));

	const uint8_t posGamma[15] = {0x0F, 0x29, 0x24, 0x0c, 0x0E, 0x09, 0x4E, 0x78, 0x3C, 0x09, 0x13, 0x05, 0x17, 0x11, 0x00};
	sendCmd(POS_GAMMA, (int8_t *)posGamma, sizeof(posGamma));

	const uint8_t negGamma[15] = {0x00, 0x16, 0x1B, 0x04, 0x11, 0x07, 0x31, 0x33, 0x42, 0x05, 0x0C, 0x0A, 0x28, 0x2F, 0x0F};
	sendCmd(NEG_GAMMA, (int8_t *)negGamma, sizeof(negGamma));

	sendCmd(SLEEP_OUT);
	thread::delay(200);

	sendCmd(DISPLAY_ON);
	sendCmd(MEMORY_WRITE);
	
	disable();

	return error::ERROR_NONE;
}

MSP2402::MSP2402(void)
{

}

#endif


