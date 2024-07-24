/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_GLCD_TM0027__H_
#define YSS_MOD_GLCD_TM0027__H_

#include <config.h>

#if USE_GUI

#include <gui/Font.h>
#include <gui/util.h>
#include <sac/MonoLcd.h>
#include <yss/instance.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

// 구매처 : https://findlcd.com/?act=shop.goods_view&GS=41

namespace mod
{
namespace glcd
{
class TM0027 : public sac::MonoLcd
{
	Spi *mPeri;
	pin_t mCs, mA0, mRst;

	void sendCmd(uint8_t cmd);
	void sendData(void *data, uint32_t size);

  public:
	TM0027(void);
	bool initialize(Spi &spi, pin_t &cs, pin_t &A0, pin_t &rst);
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

