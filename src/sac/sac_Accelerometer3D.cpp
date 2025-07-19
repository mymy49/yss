/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <sac/Accelerometer3D.h>
#include <yss/debug.h>

static void thread_process(void *var)
{
	Accelerometer3D *obj = (Accelerometer3D*)var;

	obj->process();
}

Accelerometer3D::Accelerometer3D(void)
{
	mId = 0;
}

void Accelerometer3D::process(void)
{
	accData_t data;

	while(1)
	{
		if(isUpdated())
		{
		}
		thread::yield();
	}
}

void Accelerometer3D::run(void)
{
	if(mId == 0)
		mId = thread::add(thread_process, this, 512);
}

void Accelerometer3D::stop(void)
{
	if(mId)
	{
		thread::remove(mId);
		mId = 0;
	}
}

