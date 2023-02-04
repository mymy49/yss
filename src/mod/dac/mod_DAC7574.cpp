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

