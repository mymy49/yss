/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_RGB_TFT_LCD_GD32_RGB_LCD__H_
#define YSS_MOD_RGB_TFT_LCD_GD32_RGB_LCD__H_

#include <yss/instance.h>
#include <mod/tft_lcd_driver/ILI9488.h>
#include <sac/RgbBusTftLcd.h>

#if !(defined(YSS_DRV_LTDC_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class GD32_RGB_LCD : public ILI9488, public RgbBusTftLcd
{
	pin_t mCsPin;
	pin_t mDcPin;
	pin_t mRstPin;
	pin_t mMosiPin;
	pin_t mSckPin;

  public:
	struct Config 
	{
		pin_t mosi;
		pin_t sck;
		pin_t chipSelect;
		pin_t dataCommand;
		pin_t reset;
	};

	GD32_RGB_LCD(void);
	void setConfig(const Config &config);

	error_t initialize(void); // virtual 0
	const Ltdc::specification_t* getSpecification(void); // virtual 0

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