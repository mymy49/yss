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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

