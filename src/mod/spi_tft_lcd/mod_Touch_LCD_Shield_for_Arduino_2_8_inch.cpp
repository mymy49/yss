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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <yss/debug.h>

#if USE_GUI

#include <mod/spi_tft_lcd/Touch_LCD_Shield_for_Arduino_2_8_inch.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

#include <std_ext/string.h>

Touch_LCD_Shield_for_Arduino_2_8_inch::Touch_LCD_Shield_for_Arduino_2_8_inch(void)
{
	Brush::setSize(Size_t{320, 480});
}

error_t Touch_LCD_Shield_for_Arduino_2_8_inch::initialize(void)
{
	reset();
	
	thread::delay(500);
	enable();

	uint8_t des;
	read(0x04, des);

	sendCmd(MADCTL, 0xA0);

	sendCmd(COLMOD, 0x65);

	const uint8_t porctl[] = {0x0C, 0x0C, 0x00, 0x33, 0x33};
	sendCmd(PORCTL, (int8_t *)porctl, sizeof(porctl));

	sendCmd(GATE_CTRL, 0x35);

	sendCmd(VCOMS, 0x2B);

	sendCmd(LCMCTLR, 0x2C);

	const uint8_t vdvvrhen[] = {0x01, 0xFF};
	sendCmd(VDVVRHEN, (int8_t *)vdvvrhen, sizeof(vdvvrhen));

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

	sendCmd(SLPOUT);
	thread::delay(100);

	sendCmd(DISPON);
	thread::delay(50);

	disable();

	return error_t::ERROR_NONE;
}

Size_t Touch_LCD_Shield_for_Arduino_2_8_inch::getLcdSize(void)
{
	return Size_t{320, 480};
}


#endif

#endif



