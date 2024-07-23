/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>
#include <mod/dynamixel/XL330.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

XL330::XL330(Uart &uart) : DynamixelV2(uart)
{

}

error_t XL330::changeId(uint8_t id)
{
	error_t result;
	uint8_t id_ = id;
	uint16_t len = 1;

	result = write(EEP_ID, &id, len);
	if(result == error_t::ERROR_NONE)
		setId(id_);
	
	return result;
}

error_t XL330::setCurrentLimit(uint16_t current)
{
	uint16_t len = 2;

	return write(EEP_CURRENT_LIMIT, &current, len);
}

error_t XL330::getCurrentLimit(uint16_t &current)
{
	uint16_t len = 2;

	return read(EEP_CURRENT_LIMIT, &current, len);
}

error_t XL330::setTorqueEnable(bool en)
{
	uint16_t len = 1;

	return write(RAM_TORQUE_ENABLE, &en, len);
}

error_t XL330::getTorqueEnable(bool &en)
{
	uint16_t len = 1;

	return read(RAM_TORQUE_ENABLE, &en, len);
}

error_t XL330::setLed(bool en)
{
	uint16_t len = 1;

	return write(RAM_LED, &en, len);
}

error_t XL330::getLed(bool &en)
{
	uint16_t len = 1;

	return read(RAM_LED, &en, len);
}

error_t XL330::setProfileVelocity(uint16_t value)
{
	uint16_t len = 2;

	return write(RAM_PROFILE_VELOCITY, &value, len);
}

error_t XL330::getProfileVelocity(uint16_t &value)
{
	uint16_t len = 2;

	return read(RAM_PROFILE_VELOCITY, &value, len);
}

error_t XL330::setProfileAcceleration(uint16_t value)
{
	uint16_t len = 2;

	return write(RAM_PROFILE_ACCELERATION, &value, len);
}

error_t XL330::getProfileAcceleration(uint16_t &value)
{
	uint16_t len = 2;

	return read(RAM_PROFILE_ACCELERATION, &value, len);
}

error_t XL330::setGoalPosition(int32_t position)
{
	uint16_t len = 4;

	return write(RAM_GOAL_POSITION, &position, len);
}

error_t XL330::getGoalPosition(int32_t &position)
{
	uint16_t len = 4;

	return read(RAM_GOAL_POSITION, &position, len);
}

#endif

