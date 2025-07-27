/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/sensor/accelerometer/LIS302DL.h>

#if !(defined(YSS_DRV_SPI_UNSUPPORTED) || defined(YSS_DRV_GPIO_UNSUPPORTED))

static const Spi::specification_t gSpiSpec =
{
	Spi::MODE_MODE3,	//uint8_t mode;
	10000000,			//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
};

error_t LIS302DL::initialize(const config_t config)
{
	uint8_t data = 0x47, result;

	mPeri = &config.peri;
	mCsPin = config.chipSelect;

	mCsPin.port->setOutput(mCsPin.pin, true);

	thread::delay(10);

	result = readRegister(WHO_AM_I);
	
	if(result == 0x3B)
	{
		if(config.datarate)
		{
			data |= 0x80;
			mRefreshTime = 2500;
		}
		else 
		{
			mRefreshTime = 10000;
		}

		if(config.fullscale)
		{
			mSensitivity = 0.072;
			data |= 0x20;
		}
		else
			mSensitivity = 0.018;

		writeRegister(CTRL_REG1, data);

		return error_t::ERROR_NONE;
	}
	else
		return error_t::WRONG_RESPONSE;
}

bool LIS302DL::isUpdated(void)
{
	if(mUpdateTime.getUsec() >= mRefreshTime)
	{
		mUpdateTime.reset();
		return true;
	}
	else 
		return false;
}

Accelerometer3Axis::axis3_t LIS302DL::getAccData(void)
{
	int8_t data[5];
	Accelerometer3Axis::axis3_t result;

	readRegister(OUT_X, (uint8_t*)data, 5);
	result.x = data[0] * mSensitivity;
	result.y = data[2] * mSensitivity;
	result.z = data[4] * mSensitivity;

	return result;
}


uint8_t LIS302DL::readRegister(addr_t addr)
{
	uint8_t data[2] = {(uint8_t)((addr & 0x3F) | 0xC0), 0xFF};

	mPeri->lock();
	mPeri->setSpecification(gSpiSpec);
	mPeri->enable(true);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->exchange(data, 2);
	mCsPin.port->setOutput(mCsPin.pin, true);
	mPeri->enable(false);
	mPeri->unlock();

	return data[1];
}

void LIS302DL::writeRegister(addr_t addr, uint8_t data)
{
	uint8_t buf[2] = {(uint8_t)((addr & 0x3F) | 0x40), data};

	mPeri->lock();
	mPeri->setSpecification(gSpiSpec);
	mPeri->enable(true);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(buf, 2);
	mCsPin.port->setOutput(mCsPin.pin, true);
	mPeri->enable(false);
	mPeri->unlock();
}

void LIS302DL::readRegister(addr_t addr, uint8_t *des, uint32_t size)
{
	uint8_t data = (uint8_t)((addr & 0x3F) | 0xC0);

	mPeri->lock();
	mPeri->setSpecification(gSpiSpec);
	mPeri->enable(true);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(data);
	mPeri->exchange(des, size);
	mCsPin.port->setOutput(mCsPin.pin, true);
	mPeri->enable(false);
	mPeri->unlock();
}

LIS302DL::LIS302DL(void)
{
	mSensitivity = 1.;
}

#endif

