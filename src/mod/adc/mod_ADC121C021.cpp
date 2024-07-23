/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/adc/ADC121C021.h>

#ifndef YSS_DRV_I2C_UNSUPPORTED

#include <string.h>

#define ADDR 0xA8

#define ADDR_RESULT 0
#define ADDR_STATUS 1
#define ADDR_CONFIG 2
#define ADDR_LOW_LIMIT 3
#define ADDR_HIGH_LIMIT 4
#define ADDR_HYSTERESIS 5
#define ADDR_LOW_CONVERSION 6
#define ADDR_HIGH_CONVERSION 7

namespace mod
{
namespace adc
{
ADC121C021::ADC121C021(void)
{
	mInitFlag = false;
	mPeri = 0;
	mConfigReg = 0;
}

bool ADC121C021::init(const Config config)
{
	uint8_t data = 0x00;

	mPeri = &config.peri;

	mInitFlag = true;
	mPeri->lock();
	mInitFlag = mPeri->send(ADDR, &data, 1);
	mPeri->stop();
	mPeri->unlock();

	return mInitFlag;
}

void ADC121C021::setConversionTime(uint8_t cycleTime)
{
	mConfigReg &= ~0xE0;
	mConfigReg |= (cycleTime & 0x07) << 5;

	sendResistor(ADDR_CONFIG, mConfigReg);
}

void ADC121C021::sendResistor(uint8_t addr, uint8_t data)
{
	if (mInitFlag == false)
		return;

	uint8_t sendBuf[2] = {addr, data};

	mPeri->lock();
	mPeri->send(ADDR, sendBuf, 2);
	mPeri->stop();
	mPeri->unlock();
}

void ADC121C021::setAddr(uint8_t addr)
{
	if (mInitFlag == false)
		return;

	mPeri->lock();
	mPeri->send(ADDR, &addr, 2);
	mPeri->stop();
	mPeri->unlock();
}

uint16_t ADC121C021::getResult(void)
{
	if (mInitFlag == false)
		return 0;

	uint8_t data[2] = {
		ADDR_RESULT,
	};

	mPeri->lock();
	mPeri->send(ADDR, data, 1);
	mPeri->receive(ADDR, data, 2);
	mPeri->stop();
	mPeri->unlock();

	return ((uint16_t)data[0] << 8) | (uint16_t)data[1];
}
}
}

#endif

