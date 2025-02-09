/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/eeprom/CAT24C256.h>
#include <string.h>
#include <util/runtime.h>
#include <yss/error.h>

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

error_t CAT24C256::writeBytes(uint32_t addr, void *src, uint32_t size)
{
	volatile uint8_t i, k, num;
	uint8_t *cSrc = (uint8_t *)src, buf[66];
	error_t rt;

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

			if (rt != error_t::ERROR_NONE)
			{
				return rt;
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

		if (rt != error_t::ERROR_NONE)
		{
			return rt;
		}
	}

	return error_t::ERROR_NONE;
}

error_t CAT24C256::readBytes(uint32_t addr, void *des, uint32_t size)
{
	int8_t buf[2];
	int8_t *pAddr = (int8_t *)&addr;
	error_t rt = error_t::ERROR_NONE;

	mThisTime = runtime::getMsec();
	while (mThisTime < mLastWritingTime + 5)
	{
		thread::yield();
		mThisTime = runtime::getMsec();
	}

	if (addr + size > getSize())
		return error_t::OUT_OF_RANGE;

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

