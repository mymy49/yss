/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_RTOUCH_STMPE811__H_
#define YSS_MOD_RTOUCH_STMPE811__H_

#include <sac/Rtouch.h>
#include <yss/instance.h>
#include <util/ElapsedTime.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

class STMPE811 : public sac::Rtouch
{
	I2c *mPeri;
	pin_t mIsrPin;
	bool mFirstFlag, mDetectedFlag;
	int32_t mX, mY;
	threadId_t mThreadId;
	ElapsedTime mLastUpdateTime;

  public:
	struct Config
	{
		I2c &peri;
		pin_t isrPin;
	};

	STMPE811(void);
	~STMPE811(void);

	bool init(const Config &config);
	void sendByte(uint8_t addr, uint8_t data);
	uint8_t receiveByte(uint8_t addr);
	void readGroup(void);
	void isr(void);
};

#endif

#endif

