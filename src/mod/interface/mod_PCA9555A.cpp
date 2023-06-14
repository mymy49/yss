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

#include <mod/interface/PCA9555A.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED)

#define ADDR 0x40

PCA9555A::PCA9555A(void)
{
	mDev = 0;
	mInitFlag = false;
	mAddr = ADDR;
}

error PCA9555A::initialize(const Config config)
{
	error result;
	char data = 0;

	mDev = &config.dev;
	mAddr |= config.addr & 0x0E;

	mDev->lock();
	result = mDev->send(mAddr, &data, 1);
	mDev->stop();
	mDev->unlock();

	if(result == error::ERROR_NONE)
		mInitFlag = true;

	return result;
}

uint8_t PCA9555A::readPort0(void)
{
	if(mInitFlag == false)
		return 0;

	char data = 0;
	error result;
	
	mDev->lock();
	result = mDev->send(mAddr, &data, 1);
	if(result == error::ERROR_NONE)
	{
		result = mDev->receive(mAddr, &data, 1);
	}
	mDev->stop();
	mDev->unlock();
	
	if(result == error::ERROR_NONE)
		return data;
	else
		return 0;
}

uint8_t PCA9555A::readPort1(void)
{
	if(mInitFlag == false)
		return 0;

	char data = 1;
	error result;
	
	mDev->lock();
	result = mDev->send(mAddr, &data, 1);
	if(result == error::ERROR_NONE)
	{
		result = mDev->receive(mAddr, &data, 1);
	}
	mDev->stop();
	mDev->unlock();
	
	if(result == error::ERROR_NONE)
		return data;
	else
		return 0;
}

#endif

