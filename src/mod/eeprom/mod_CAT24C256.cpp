////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/eeprom/CAT24C256.h>
#include <string.h>
#include <util/runtime.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

#define ADDR 0xA0

CAT24C256::CAT24C256(void)
{
	mPeri = 0;
	mWp.port = 0;
	mWp.pin = 0;
	mInitFlag = false;
	mAddr = ADDR;
	mLastWritingTime = 0;
}

uint32_t CAT24C256::getSize(void)
{
	return 32 * 1024;
}

bool CAT24C256::init(const Config config)
{
	bool rt;
	int8_t buf[4] = {0, 0};

	mPeri = &(config.peri);
	mWp = config.writeProtectPin;
	mInitFlag = true;
	mAddr |= (config.addr & 0xe);

	if (mWp.port)
		mWp.port->setOutput(mWp.pin, true);

	mPeri->lock();
	mPeri->send(ADDR | 0x01, buf, 2, 300);
	mInitFlag = mPeri->receive(ADDR | 0x01, buf, 4, 500);
	mPeri->unlock();

	return mInitFlag;
}

bool CAT24C256::writeBytes(uint32_t addr, void *src, uint32_t size)
{
	volatile uint8_t i, j, k, num;
	uint8_t *cSrc = (uint8_t *)src, buf[66];
	bool rt;

	while (size)
	{
		if (size > 64)
		{
			num = 64;
			size -= 64;
		}
		else
		{
			num = size;
			size = 0;
		}

		k = 64 - (addr % 64);

		if (k < num)
		{
			buf[0] = addr >> 8;
			buf[1] = addr;

			for (i = 2; i < k + 2; i++)
				buf[i] = *cSrc++;

			for (int32_t  i = 0; i < 3; i++)
			{
				while (mThisTime < mLastWritingTime + 10)
				{
					thread::yield();
					mThisTime = runtime::getMsec();
				}

				mPeri->lock();
				if (mWp.port)
					mWp.port->setOutput(mWp.pin, false);
				rt = mPeri->send(mAddr, buf, k + 2, 500);
				mPeri->stop();
				if (mWp.port)
					mWp.port->setOutput(mWp.pin, true);
				mPeri->unlock();
				mLastWritingTime = runtime::getMsec();

				if (rt)
					break;
			}

			if (rt == false)
			{
				return false;
			}

			num -= k;
			addr += k;
		}

		buf[0] = addr >> 8;
		buf[1] = addr;

		for (i = 2; i < num + 2; i++)
			buf[i] = *cSrc++;

		for (int32_t  i = 0; i < 3; i++)
		{
			while (mThisTime < mLastWritingTime + 10)
			{
				thread::yield();
				mThisTime = runtime::getMsec();
			}

			mPeri->lock();
			if (mWp.port)
				mWp.port->setOutput(mWp.pin, false);
			rt = mPeri->send(mAddr, buf, num + 2, 500);
			mPeri->stop();
			if (mWp.port)
				mWp.port->setOutput(mWp.pin, true);
			mPeri->unlock();
			mLastWritingTime = runtime::getMsec();

			if (rt)
				break;
		}

		addr += num;

		if (rt == false)
		{
			return false;
		}
	}

	return true;
}

bool CAT24C256::readBytes(uint32_t addr, void *des, uint32_t size)
{
	int8_t buf[2];
	int8_t *pAddr = (int8_t *)&addr;
	bool rt = false;

	mThisTime = runtime::getMsec();
	while (mThisTime < mLastWritingTime + 5)
	{
		thread::yield();
		mThisTime = runtime::getMsec();
	}

	if (addr + size > getSize())
		return false;

	buf[0] = pAddr[1];
	buf[1] = pAddr[0];

	for (int32_t  i = 0; i < 3; i++)
	{
		mPeri->lock();
		mPeri->send(mAddr, buf, 2, 300);
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
		thread::delayUs(100);
#else
		thread::yield();
#endif
		rt = mPeri->receive(mAddr, (int8_t *)des, size, 10000);
		mPeri->unlock();

		if (rt)
			break;
	}

	return rt;
}

#endif

