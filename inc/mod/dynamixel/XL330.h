/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_DYNAMIXEL_XL330__H_
#define YSS_MOD_DYNAMIXEL_XL330__H_

#include "DynamixelV2.h"

#ifndef YSS_DRV_UART_UNSUPPORTED

class XL330 : public DynamixelV2
{
public:
	typedef enum
	{
		EEP_ID = 7,
		EEP_CURRENT_LIMIT = 38,
		RAM_TORQUE_ENABLE = 64,
		RAM_LED = 65,
		RAM_PROFILE_ACCELERATION = 108,
		RAM_PROFILE_VELOCITY = 112,
		RAM_GOAL_POSITION = 116,
	}addr_t;

	XL330(Uart &uart);

	error_t changeId(uint8_t current);
	
	error_t setCurrentLimit(uint16_t current);
	
	error_t getCurrentLimit(uint16_t &current);

	error_t setTorqueEnable(bool en);
	
	error_t getTorqueEnable(bool &en);

	error_t setLed(bool en);
	
	error_t getLed(bool &en);

	error_t setProfileAcceleration(uint16_t value);
	
	error_t getProfileAcceleration(uint16_t &value);

	error_t setProfileVelocity(uint16_t value);
	
	error_t getProfileVelocity(uint16_t &value);

	error_t setGoalPosition(int32_t position);

	error_t getGoalPosition(int32_t &position);

};

#endif

#endif

