/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/fram/FM24CL04B.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

#define ADDR	0xa0

FM24CL04B::FM24CL04B(void)
{
	mPeri = nullptr;
}

error_t FM24CL04B::initialize(const config_t config)
{
	uint8_t data;
	error_t result;

	mPeri = &config.peri;
	mWp = config.writeProtectPin;

	result = readBytes(0, &data, 1);

	return result;
}

uint32_t FM24CL04B::getSize(void)
{
	return 512;
}

error_t FM24CL04B::writeBytes(uint32_t addr, void *src, uint32_t size)
{
	int8_t data[9], sendingSize, taddr = ADDR, *cSrc = (int8_t*)src;
	error_t rt = error_t::ERROR_NONE;

	if(mPeri == nullptr)
		return error_t::NOT_INITIALIZED;

	mPeri->lock();
	mWp.port->setOutput(mWp.pin, false);
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

		if(rt != error_t::ERROR_NONE)
			goto error_t;

		addr += sendingSize;
	}

error_t:
	mWp.port->setOutput(mWp.pin, true);
	mPeri->unlock();

	return rt;
}

error_t FM24CL04B::readBytes(uint32_t addr, void *des, uint32_t size)
{
	int8_t taddr = ADDR;
	error_t result;

	if(mPeri == nullptr)
		return error_t::NOT_INITIALIZED;

	if(addr >= 0x100)
	{
		taddr |= 0x2;
		addr -= 0x100;
	}

	mPeri->lock();
	
	result = mPeri->send(taddr, (int8_t*)&addr, 1, 300);
	if(result == error_t::ERROR_NONE)
		result = mPeri->receive(taddr, (int8_t*)des, size, 300);
	
	mPeri->stop();
	mPeri->unlock();

	return result;
}

#endif

