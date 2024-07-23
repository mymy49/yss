/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/dac/DAC7574.h>
#include <string.h>

#ifndef YSS_DRV_I2C_UNSUPPORTED

#define ADDR	0x98

namespace mod
{
namespace dac
{
	DAC7574::DAC7574(void)
	{
		mInitFlag = false;
		mAddr = ADDR;
		mPeri = 0;
		memset(mOutputValue, 0, sizeof(mOutputValue));
	}

	bool DAC7574::init(I2c *peri, uint8_t addr)
	{
		mPeri = peri;
		mAddr |= (addr & 0x6);
		mInitFlag = true;

		return true;
	}

	bool DAC7574::set(uint8_t channel, uint16_t value)
	{
		int8_t buf[3] = {0x10, 0, 0};
		bool rt;

		if(channel > 3)
			return false;

		if(value > 4095)
			value = 4095;
		
		mOutputValue[channel] = value;

		buf[0] |= channel << 1;
		buf[1] = (int8_t)(value >> 4);
		buf[2] = (int8_t)(value << 4);

		mPeri->lock();
		rt = mPeri->send(mAddr, buf, 3, 1000);
		mPeri->stop();
		mPeri->unlock();
		
		return rt;
	}

}
}

#endif

