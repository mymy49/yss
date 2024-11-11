/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/interface/MCP23017.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED)

#define I2C_ADDR 0x40

MCP23017::MCP23017(void)
{
	mDev = 0;
	mInitFlag = false;
	mAddr = I2C_ADDR;
}

error_t MCP23017::initialize(const config_t config)
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

void MCP23017::setDirection(port_t port, uint8_t direction)
{
	uint8_t data[2] = {0, direction};

	if(port == PORT_GPA)
		data[0] = 0x00;
	else
		data[0] = 0x01;

	if(mInitFlag == false)
		return;

	mDev->lock();
	mDev->send(mAddr, &data, 2);
	mDev->stop();
	mDev->unlock();
}

void MCP23017::write(port_t port, uint8_t data)
{
	uint8_t buf[2] = {0, data};

	if(mInitFlag == false)
		return;

	if(port == PORT_GPA)
		buf[0] = 0x14;
	else
		buf[0] = 0x15;

	mDev->lock();
	mDev->send(mAddr, &buf, 2);
	mDev->stop();
	mDev->unlock();
}

#endif

