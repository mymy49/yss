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

#ifndef YSS_MOD_RGB_TFT_LCD_GD32_RGB_LCD__H_
#define YSS_MOD_RGB_TFT_LCD_GD32_RGB_LCD__H_

#include <yss/instance.h>
#include <mod/tft_lcd_driver/ILI9488.h>
#include <sac/RgbBusTftLcd.h>

#if !(defined(YSS_DRV_LTDC_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class GD32_RGB_LCD : public ILI9488, public RgbBusTftLcd
{
	Gpio::Pin mCsPin;
	Gpio::Pin mDcPin;
	Gpio::Pin mRstPin;
	Gpio::Pin mMosiPin;
	Gpio::Pin mSckPin;

  public:
	struct Config 
	{
		Gpio::Pin mosi;
		Gpio::Pin sck;
		Gpio::Pin chipSelect;
		Gpio::Pin dataCommand;
		Gpio::Pin reset;
	};

	GD32_RGB_LCD(void);
	void setConfig(const Config &config);

	error initialize(void); // virtual 0
	const Ltdc::Specification* getSpecification(void); // virtual 0

protected :
	void sendData(uint8_t data);

	// virtual 함수 정의
	void sendCmd(uint8_t cmd); // virtual 0
	void sendCmd(uint8_t cmd, void *data, uint32_t len); // virtual 0
	void enable(void); // virtual 0
	void disable(void); // virtual 0
	void reset(void); // virtual 0
};

#endif

#endif