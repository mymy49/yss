/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_OLED_UG_2832HSWEG04__H_
#define YSS_MOD_OLED_UG_2832HSWEG04__H_

#include <config.h>

#if USE_GUI

#include <yss/instance.h>
#include <gui/Font.h>
#include <gui/util.h>
#include <sac/MonoLcd.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

namespace mod
{
namespace oled
{
class UG_2832HSWEG04 : public sac::MonoLcd
{
	Spi *mPeri;
	pin_t mCs, mDc, mRst;

	void sendCmd(uint8_t cmd);
	void sendData(void *data, uint32_t size);

  public:
	UG_2832HSWEG04(void);
	bool initialize(Spi &spi, pin_t &cs, pin_t &dc, pin_t &rst);
	void clear(void);
	void refresh(void);
	void fill(void);
	void drawDot(uint16_t x, uint16_t y, bool data = true);
};
}
}

#endif

#endif

#endif

