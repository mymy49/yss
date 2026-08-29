/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_HAL_BLE__H_
#define YSS_HAL_BLE__H_

#include <yss/error.h>
#include <bluetooth/Ble4p0.h>

class Ble
{
public :
	typedef enum
	{
		BLE_1MBPS,
		BLE_2MBPS
	}speed_t;

	Ble();

	virtual error_t initializeAsBle() = 0;

	virtual error_t setChannel(uint8_t channel) = 0;

	virtual error_t setSpeed(speed_t speed) = 0;

	virtual error_t receive() = 0;

	virtual void* getRxBuffer() = 0;

protected :
	uint32_t getFrequency(uint8_t channel);
	 
private :
};

#endif

