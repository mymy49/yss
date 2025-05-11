/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

	if(mPeri == nullptr)
		return error_t::NOT_INITIALIZED;
	
	mPeri->lock();
	mPeri->send(mAddr, data, 1);
	mPeri->receive(mAddr, data, 2, 1000);
	mPeri->unlock();

	buf = data[0] << 8;
	buf |= data[1];

	return (float)buf / 256.f;
}


#endif

