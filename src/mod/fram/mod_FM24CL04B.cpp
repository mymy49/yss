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

#include <mod/fram/FM24CL04B.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

#define ADDR	0xa0

namespace mod
{
namespace fram
{
	uint32_t FM24CL04B::getSize(void)
	{
		return 512;
	}

	bool FM24CL04B::writeBytes(uint32_t addr, void *src, uint32_t size)
	{
		int8_t data[9], sendingSize, taddr = ADDR, *cSrc = (int8_t*)src;
		bool rt = true;

		if(mInitFlag == false)
			return false;

		mPeri->lock();
		mWpPort.port->setOutput(mWpPort.pin, false);
		thread::delay(1);
		while(size)
		{
			if(addr >= 0x100)
			{
				taddr |= 0x2;
				addr -= 0x100;
			}

			data[0] = addr;

			if(size > 8)
			{
				sendingSize = 8;
				size -= 8;
			}
			else
			{
				sendingSize = size;
				size = 0;
			}

			for(uint8_t i=0;i<sendingSize;i++)
			{
				data[i+1] = *cSrc++;
			}

			rt = mPeri->send(taddr, data, sendingSize+1, 300);
			mPeri->stop();

			if(rt == false)
				goto error;

			addr += sendingSize;
		}

error:
		mWpPort.port->setOutput(mWpPort.pin, true);
		mPeri->unlock();

		return rt;
	}

	bool FM24CL04B::readBytes(uint32_t addr, void *des, uint32_t size)
	{
		int8_t taddr = ADDR;
		bool rt = true;
	
		if(mInitFlag == false)
			return false;

		if(addr >= 0x100)
		{
			taddr |= 0x2;
			addr -= 0x100;
		}

		rt = mPeri->send(taddr, (int8_t*)&addr, 1, 300);
		if(rt)
		{
			rt = mPeri->receive(taddr, (int8_t*)des, size, 300);
		}
		mPeri->stop();
		mPeri->unlock();

		return rt;
	}

	bool FM24CL04B::init(I2c &peri, Gpio::Pin writeProtection)
	{
		bool rt = true;
		mPeri = &peri;
		mWpPort.port = writeProtection.port;
		mWpPort.pin = mWpPort.pin;
		mInitFlag = rt;

		return rt;
	}
}
}

#endif

