/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_ACCELEROMETER__H_
#define YSS_SAC_ACCELEROMETER__H_

#include <stdint.h>
#include <yss/thread.h>

class Accelerometer3D
{
public :
	typedef struct
	{
		float x;
		float y;
		float z;
	}accData_t;

	Accelerometer3D(void);

	void process(void);

	virtual bool isUpdated(void) = 0;

	virtual accData_t getAccData(void) = 0;

	void run(void);

	void stop(void);

private :
	threadId_t mId;
};

#endif

