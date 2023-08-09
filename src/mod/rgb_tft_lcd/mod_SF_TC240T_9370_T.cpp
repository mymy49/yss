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

#include <mod/rgb_tft_lcd/SF_TC240T_9370_T.h>

#if !defined(YSS_DRV_LTDC_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED) && !defined(YSS_DRV_SPI_UNSUPPORTED)

SF_TC240T_9370_T::SF_TC240T_9370_T(void)
{
}

error SF_TC240T_9370_T::initialize(void)
{
	enable();

	sendCmd(DISPLAY_OFF);

	const uint8_t ca[3] = {0xC3, 0x08, 0x50};
	sendCmd(0xCA, (int8_t *)ca, sizeof(ca));

	const uint8_t powerB[3] = {0x00, 0xc1, 0x30};
	sendCmd(POWER_B, (int8_t *)powerB, sizeof(powerB));

	const uint8_t powerSeq[4] = {0x64, 0x03, 0x12, 0x81};
	sendCmd(POWER_SEQ, (int8_t *)powerSeq, sizeof(powerSeq));

	const uint8_t dtca[3] = {0x85, 0x00, 0x78};
	sendCmd(DTCA, (int8_t *)dtca, sizeof(dtca));

	const uint8_t powerA[5] = {0x39, 0x2c, 0x00, 0x34, 0x02};
	sendCmd(POWER_A, (int8_t *)powerA, sizeof(powerA));

	const uint8_t prc[1] = {0x20};
	sendCmd(ADJUST_CTRL3, (int8_t *)prc, sizeof(prc));

	const uint8_t dtcb[2] = {0x00, 0x00};
	sendCmd(DTCB, (int8_t *)dtcb, sizeof(dtcb));

	const uint8_t frameRate[2] = {0x00, 0x1F};
	sendCmd(FRAME_RATE, (int8_t *)frameRate, sizeof(frameRate));

	const uint8_t displayCtrl1[2] = {0x0A, 0xA2};
	sendCmd(DISPLAY_CTRL, (int8_t *)displayCtrl1, sizeof(displayCtrl1));

	const uint8_t powerCtrl1[1] = {0x10};
	sendCmd(POWER_CTRL1, (int8_t *)powerCtrl1, sizeof(powerCtrl1));

	const uint8_t powerCtrl2[1] = {0x10};
	sendCmd(POWER_CTRL2, (int8_t *)powerCtrl2, sizeof(powerCtrl2));

	const uint8_t vcomCtrl1[2] = {0x45, 0x15};
	sendCmd(VCOM_CTRL1, (int8_t *)vcomCtrl1, sizeof(vcomCtrl1));

	const uint8_t vcomCtrl2[1] = {0x90};
	sendCmd(VCOM_CTRL2, (int8_t *)vcomCtrl2, sizeof(vcomCtrl2));

	uint8_t memAccCtrl[] = {0x08};
	sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));

	const uint8_t fixelFormat[1] = {0x55};
	sendCmd(COLMOD_PIXEL_FORMAT_SET, (int8_t *)fixelFormat, sizeof(fixelFormat));

	const uint8_t gammaFuncDis[1] = {0x00};
	sendCmd(GAMMA3_FUNC_DIS, (int8_t *)gammaFuncDis, sizeof(gammaFuncDis));

	uint8_t rgbInterface[] = {0xC2};
	sendCmd(INTERFACE_MODE_CTRL, (int8_t *)rgbInterface, sizeof(rgbInterface));

	const uint8_t displayCtrl2[4] = {0x0A, 0xA7, 0x27, 0x04};	// 다름
	sendCmd(DISPLAY_CTRL, (int8_t *)displayCtrl2, sizeof(displayCtrl2));

	const uint8_t interfaceControl[3] = {0x01, 0x00, 0x06};
	sendCmd(INTERFACE_CONTROL, (int8_t *)interfaceControl, sizeof(interfaceControl));

	sendCmd(MEMORY_WRITE);
	thread::delay(200);

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

static const Ltdc::Specification gSpec =
	{
		240,                         // width
		320,                         // height
		2,                           // hsyncWidth
		1,                           // vsyncWidth
		2,                           // hbp
		1,                           // vbp
		2,                           // hfp
		3,                           // vfp
		define::ltdc::format::RGB565 // pixelFormat
};

const Ltdc::Specification* SF_TC240T_9370_T::getSpec(void)
{
	return &gSpec;
}

bool SF_TC240T_9370_T::getReverseRgbOrder(void)
{
	return true;
}

bool SF_TC240T_9370_T::getReverseEndian(void)
{
	return true;
}

#endif