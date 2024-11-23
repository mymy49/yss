/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/speaker_amp/TAS5756M.h>

#if !(defined(YSS_DRV_I2C_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

#include <yss/debug.h>

#define ADDR	0x98

TAS5756M::TAS5756M(void)
{
	mPeri = nullptr;
	mAddr = ADDR;
}

error_t TAS5756M::initialize(const config_t config)
{
	error_t result;
	uint8_t reg;

	mPeri = &config.peri;
	mAddr |= config.addr;
	result = reset();

	if(result != error_t::ERROR_NONE)
		return result;

	result = readRegister(12, reg);
	if(result == error_t::ERROR_NONE && reg != 0x7C)
		result = error_t::UNKNOWN_DEVICE;

	return result;
}

uint8_t TAS5756M::getStatus(void)
{
	uint8_t data;
	readRegister(95, data);

	return data;
}

void TAS5756M::setWordLength(wordLength_t wordLength)
{
	uint8_t data;
	readRegister(40, data);
	data &= ~0x03;
	data |= wordLength;
	writeRegister(40, data);
}

void TAS5756M::setVolume(uint8_t vol)
{
	writeRegister(61, vol);
	writeRegister(62, vol);
}

error_t TAS5756M::reset(void)
{
	uint8_t data[2] = {1, 0x11};
	error_t result;

	mPeri->lock();
	result = mPeri->send(mAddr, data, 2);
	mPeri->stop();
	mPeri->unlock();

	if(result == error_t::NACK)
		return error_t::ERROR_NONE;

	return result;
}

error_t TAS5756M::readRegister(uint8_t addr, uint8_t &data)
{
	error_t result;

	mPeri->lock();
	result = mPeri->send(mAddr, &addr, 1);
	result = mPeri->receive(mAddr, &data, 1);
	mPeri->stop();
	mPeri->unlock();

	return result;
}

error_t TAS5756M::writeRegister(uint8_t addr, uint8_t data)
{
	uint8_t buf[2] = {addr, data};
	error_t result;

	mPeri->lock();
	result = mPeri->send(mAddr, buf, 2);
	mPeri->stop();
	mPeri->unlock();

	return result;
}

#endif

