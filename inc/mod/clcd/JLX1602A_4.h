/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_CLCD_JLX1602A_4__H_
#define YSS_MOD_CLCD_JLX1602A_4__H_

#include <sac/Clcd.h>
#include <yss/instance.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

namespace mod
{
namespace clcd
{
class JLX1602A_4 : public sac::Clcd
{
	I2c *mPeri;
	pin_t mBL;
	bool mDetectedFlag;

  public:
	JLX1602A_4(void);
	bool init(I2c &peri, pin_t backLight);

	void setBlackLight(bool en);
	bool isConnected(void);
	void write(uint8_t line, uint8_t column, void *src);
	bool refresh(void);
};
}
}

#endif

#endif

