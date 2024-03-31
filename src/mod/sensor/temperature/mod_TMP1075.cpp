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

#include <mod/sensor/temperature/TMP1075.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

enum class REG
{
	TEMP = 0,
	CFGR,
	LLIM,
	HLIM,
	DIEID = 0x0F
};

TMP1075::TMP1075(void)
{
	mPeri = nullptr;
	mAddr = 0;
}

error_t TMP1075::initialize(const config_t config)
{
	uint8_t data[2] = {(uint8_t)REG::TEMP, };
	error_t result;

	mAddr = (config.addr & 0x1F) | 0x80;
	mPeri = &config.peri;

	mPeri->lock();
	result = mPeri->send(mAddr, data, 1);
	if(result == error_t::ERROR_NONE)
		result = mPeri->receive(mAddr, data, 2, 1000);
	mPeri->unlock();
	
	return result;
}

float TMP1075::getTemperature(void)
{
	uint8_t data[2] = {(uint8_t)REG::TEMP, };
	uint16_t buf;
	error_t result;

	if(mPeri == nullptr)
		return error_t::NOT_INITIALIZED;
	
	mPeri->lock();
	result = mPeri->send(mAddr, data, 1);
	result = mPeri->receive(mAddr, data, 2, 1000);
	mPeri->unlock();

	buf = data[0] << 8;
	buf |= data[1];

	return (float)buf / 256.f;
}


#endif

