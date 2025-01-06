/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/interface/PCA9555A.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED)

#define ADDR 0x40

PCA9555A::PCA9555A(void)
{
	mDev = 0;
	mInitFlag = false;
	mAddr = ADDR;
}

error_t PCA9555A::initialize(const config_t config)
{
	error_t result;
	char data = 0;

	mDev = &config.dev;
	mAddr |= config.addr & 0x0E;

	mDev->lock();
	result = mDev->send(mAddr, &data, 1);
	mDev->stop();
	mDev->unlock();

	if(result == error_t::ERROR_NONE)
		mInitFlag = true;

	return result;
}

uint8_t PCA9555A::read(port_t port)
{
	uint8_t port_ = port;
	if(mInitFlag == false)
		return 0;

	error_t result;

	port_ &= 0x03;
	
	mDev->lock();
	result = mDev->send(mAddr, &port_, 1);
	if(result == error_t::ERROR_NONE)
	{
		result = mDev->receive(mAddr, &port_, 1);
	}
	mDev->stop();
	mDev->unlock();
	
	if(result == error_t::ERROR_NONE)
		return port_;
	else
		return 0;
}

void PCA9555A::setDirection(port_t port, uint8_t config)
{
	uint8_t data[2] = {port, config};

	if(mInitFlag == false)
		return;

	data[0] &= 0x03;
	data[0] += 6;

	mDev->lock();
	mDev->send(mAddr, &data, 2);
	mDev->stop();
	mDev->unlock();
}

void PCA9555A::write(port_t port, uint8_t data)
{
	uint8_t buf[2] = {port, data};

	if(mInitFlag == false)
		return;

	buf[0] &= 0x03;
	buf[0] += 2;

	mDev->lock();
	mDev->send(mAddr, &buf, 2);
	mDev->stop();
	mDev->unlock();
}

void PCA9555A::polarity(port_t port, uint8_t polarity)
{
	uint8_t data[2] = {port, polarity};

	if(mInitFlag == false)
		return;

	data[0] &= 0x03;
	data[0] += 4;

	mDev->lock();
	mDev->send(mAddr, &data, 2);
	mDev->stop();
	mDev->unlock();
}

#endif

