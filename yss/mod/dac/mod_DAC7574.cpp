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

	bool DAC7574::init(drv::I2c *peri, unsigned char addr)
	{
		mPeri = peri;
		mAddr |= (addr & 0x6);
		mInitFlag = true;

		return true;
	}

	bool DAC7574::set(unsigned char channel, unsigned short value)
	{
		char buf[3] = {0x10, 0, 0};
		bool rt;

		if(channel > 3)
			return false;

		if(value > 4095)
			value = 4095;
		
		mOutputValue[channel] = value;

		buf[0] |= channel << 1;
		buf[1] = (char)(value >> 4);
		buf[2] = (char)(value << 4);

		mPeri->lock();
		rt = mPeri->send(mAddr, buf, 3, 1000);
		mPeri->stop();
		mPeri->unlock();
		
		return rt;
	}

}
}

#endif

