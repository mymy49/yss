/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_ACCELEROMETER_3AXIS__H_
#define YSS_SAC_ACCELEROMETER_3AXIS__H_

#include <stdint.h>
#include <yss/Thread.h>
#include <yss/error.h>

class Accelerometer3Axis
{
public :
	typedef struct
	{
		float x;
		float y;
		float z;
	}axis3_t;

	virtual bool isUpdated(void) = 0;

	virtual axis3_t getAccData(void) = 0;

private :
};

#endif

