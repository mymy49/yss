////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/codec/WM8994.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED) || defined(YSS_DRV_SAI_UNSUPPORTED))

WM8994::WM8994(void)
{
	mInitFlag = false;
	mAddr = ADDR_LOW;
	mCMFMODpin.port = 0;
	mCMFMODpin.pin = 0;
	mPeri = 0;
}

bool WM8994::init(const Config config)
{
	uint16_t data;

	mPeri = &(config.peri);
	mAddr = config.addr;
	mCMFMODpin = config.CMFMOD;
	mInitFlag = true;

	if(mCMFMODpin.port)
		mCMFMODpin.port->setOutput(mCMFMODpin.pin, false);

	read(0, &data, 1);

	if(data == 0x8994)
		return true;
	else
		return false;
}

bool WM8994::read(uint16_t addr, void *des, uint32_t len)
{
	bool result;
	uint8_t buf;
	uint8_t *cDes = (uint8_t*)des;

	len *= 2;

	mPeri->lock();
	result = mPeri->send(mAddr, &addr, 2);
	if(result)
		result = mPeri->receive(mAddr, des, len);
	mPeri->stop();
	mPeri->unlock();

	if(result)
	{
		for(int32_t  i=0;i<len;i+=2)
		{
			buf = cDes[i];
			cDes[i] = cDes[i+1];
			cDes[i+1] = buf;
		}
	}

	return result;
}

#endif

