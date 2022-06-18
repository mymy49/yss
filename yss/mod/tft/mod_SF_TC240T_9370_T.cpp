////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/Ltdc.h>

#if defined(LTDC)

#include <mod/tft/SF_TC240T_9370_T.h>

#define LCD_SLEEP_OUT 0x11     /* Sleep out register */
#define LCD_GAMMA 0x26         /* Gamma register */
#define LCD_DISPLAY_OFF 0x28   /* Display off register */
#define LCD_DISPLAY_ON 0x29    /* Display on register */
#define LCD_COLUMN_ADDR 0x2A   /* Colomn address register */
#define LCD_PAGE_ADDR 0x2B     /* Page address register */
#define LCD_GRAM 0x2C          /* GRAM register */
#define LCD_MAC 0x36           /* Memory Access Control register*/
#define LCD_PIXEL_FORMAT 0x3A  /* Pixel Format register */
#define LCD_WDB 0x51           /* Write Brightness Display register */
#define LCD_WCD 0x53           /* Write Control Display register*/
#define LCD_RGB_INTERFACE 0xB0 /* RGB Interface Signal Control */
#define LCD_FRC 0xB1           /* Frame Rate Control register */
#define LCD_BPC 0xB5           /* Blanking Porch Control register*/
#define LCD_DFC 0xB6           /* Display Function Control register*/
#define LCD_POWER1 0xC0        /* Power Control 1 register */
#define LCD_POWER2 0xC1        /* Power Control 2 register */
#define LCD_VCOM1 0xC5         /* VCOM Control 1 register */
#define LCD_VCOM2 0xC7         /* VCOM Control 2 register */
#define LCD_POWERA 0xCB        /* Power control A register */
#define LCD_POWERB 0xCF        /* Power control B register */
#define LCD_PGAMMA 0xE0        /* Positive Gamma Correction register*/
#define LCD_NGAMMA 0xE1        /* Negative Gamma Correction register*/
#define LCD_DTCA 0xE8          /* Driver timing control A */
#define LCD_DTCB 0xEA          /* Driver timing control B */
#define LCD_POWER_SEQ 0xED     /* Power on sequence register */
#define LCD_3GAMMA_EN 0xF2     /* 3 Gamma enable register */
#define LCD_INTERFACE 0xF6     /* Interface control register */
#define LCD_PRC 0xF7           /* Pump ratio control register */

namespace mod
{
namespace tft
{
SF_TC240T_9370_T::SF_TC240T_9370_T(void)
{
}

static config::spi::Config gSpiConfig =
	{
		define::spi::mode::MODE0,
		10000000};

void SF_TC240T_9370_T::sendCmd(unsigned char cmd)
{
	mPeri->lock();
	mPeri->setConfig(gSpiConfig);
	mPeri->enable(true);
	setDcx(false);
	setCs(false);
	mPeri->exchange(cmd);
	setCs(true);
	mPeri->enable(false);
	mPeri->unlock();
}

void SF_TC240T_9370_T::sendData(unsigned char data)
{
	mPeri->lock();
	mPeri->setConfig(gSpiConfig);
	mPeri->enable(true);
	setDcx(true);
	setCs(false);
	mPeri->exchange(data);
	setCs(true);
	mPeri->enable(false);
	mPeri->unlock();
}

void SF_TC240T_9370_T::setCs(bool val)
{
	if (mCs.port)
		mCs.port->setOutput(mCs.pin, val);
}

void SF_TC240T_9370_T::setDcx(bool val)
{
	if (mCs.port)
		mDcx.port->setOutput(mDcx.pin, val);
}

void SF_TC240T_9370_T::init(drv::Spi &spi, drv::Gpio::Pin &cs, drv::Gpio::Pin &dcx)
{
	mPeri = &spi;
	mCs = cs;
	mDcx = dcx;
	setCs(true);

	sendCmd(0xca);
	sendData(0xc3);
	sendData(0x08);
	sendData(0x50);

	sendCmd(LCD_POWERB);
	sendData(0x00);
	sendData(0xc1);
	sendData(0x30);

	sendCmd(LCD_POWER_SEQ);
	sendData(0x64);
	sendData(0x03);
	sendData(0x12);
	sendData(0x81);

	sendCmd(LCD_DTCA);
	sendData(0x85);
	sendData(0x00);
	sendData(0x78);

	sendCmd(LCD_POWERA);
	sendData(0x39);
	sendData(0x2c);
	sendData(0x00);
	sendData(0x34);
	sendData(0x02);

	sendCmd(LCD_PRC);
	sendData(0x20);

	sendCmd(LCD_DTCB);
	sendData(0x00);
	sendData(0x00);

	sendCmd(LCD_FRC);
	sendData(0x00);
	sendData(0x1b);

	sendCmd(LCD_DFC);
	sendData(0x0a);
	sendData(0xa2);

	sendCmd(LCD_POWER1);
	sendData(0x10);

	sendCmd(LCD_POWER2);
	sendData(0x10);

	sendCmd(LCD_VCOM1);
	sendData(0x45);
	sendData(0x15);

	sendCmd(LCD_VCOM2);
	sendData(0x90);

	sendCmd(LCD_MAC);
	sendData(0xc8);

	sendCmd(LCD_3GAMMA_EN);
	sendData(0x00);

	sendCmd(LCD_RGB_INTERFACE);
	sendData(0xc2);

	sendCmd(LCD_DFC);
	sendData(0x0a);
	sendData(0xa7);
	sendData(0x27);
	sendData(0x04);

	sendCmd(LCD_COLUMN_ADDR);
	sendData(0x00);
	sendData(0x00);
	sendData(0x00);
	sendData(0xef);

	sendCmd(LCD_PAGE_ADDR);
	sendData(0x00);
	sendData(0x00);
	sendData(0x01);
	sendData(0x3f);

	sendCmd(LCD_INTERFACE);
	sendData(0x01);
	sendData(0x00);
	sendData(0x06);

	sendCmd(LCD_GRAM);
	thread::delay(1);

	sendCmd(LCD_GAMMA);
	sendData(0x01);

	sendCmd(LCD_PGAMMA);
	sendData(0x0f);
	sendData(0x29);
	sendData(0x24);
	sendData(0x0c);
	sendData(0x0e);
	sendData(0x09);
	sendData(0x4e);
	sendData(0x78);
	sendData(0x3c);
	sendData(0x09);
	sendData(0x13);
	sendData(0x05);
	sendData(0x17);
	sendData(0x11);
	sendData(0x00);

	sendCmd(LCD_NGAMMA);
	sendData(0x00);
	sendData(0x16);
	sendData(0x1b);
	sendData(0x04);
	sendData(0x11);
	sendData(0x07);
	sendData(0x31);
	sendData(0x33);
	sendData(0x42);
	sendData(0x05);
	sendData(0x0c);
	sendData(0x0a);
	sendData(0x28);
	sendData(0x2f);
	sendData(0x0f);

	sendCmd(LCD_SLEEP_OUT);
	thread::delay(1);

	sendCmd(LCD_DISPLAY_ON);
	sendCmd(LCD_GRAM);
}

static config::ltdc::Config gConfig =
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

config::ltdc::Config *SF_TC240T_9370_T::getConfig(void)
{

	return &gConfig;
}
}
}

#endif