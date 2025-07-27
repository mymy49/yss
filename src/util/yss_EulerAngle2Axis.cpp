/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/EulerAngle2Axis.h>
#include <sac/Accelerometer3Axis.h>
#include <yss/debug.h>
#include <math.h>
#include <util/ElapsedTime.h>
#include <util/Timeout.h>
#include <util/Lpf.h>

#define PI 3.14159265

EulerAngle2Axis::EulerAngle2Axis(void)
{
	mAngle.roll = 0;
	mAngle.pitch = 0;
	mObj = nullptr;
	mThreshold = 0.05;
	mStableTime = 100;
	mUnit = UNIT_RADIAN;
	mUpdateFlag = false;
}

error_t EulerAngle2Axis::initialize(config_t config)
{
	mObj = config.obj;
	mThreshold = config.threshold;
	mStableTime = config.stableTime;
	mScalar.setRatio(config.ratio);
	mUnit = config.unit;

	return error_t::ERROR_NONE;
}

void EulerAngle2Axis::thread(void)
{
	Accelerometer3Axis::axis3_t data;
	float temp, scalar;
	bool firstFlag = true;
	ElapsedTime degreeStableTime;
	angle_t angle;

	while(mObj == nullptr)
		thread::yield();
		
	while(true)
	{
		if(mObj->isUpdated())
		{
			data = mObj->getAccData();
			scalar = pow(data.x * data.x + data.y * data.y + data.z * data.z, 0.5f);

			if(firstFlag)
			{
				mScalar.setCurrentData(scalar);
				firstFlag = false;
			}
			else
			{
				temp = mScalar.getCurrentData() - scalar;
				if(temp < 0)
					temp *=  -1.f;

				if(mThreshold < temp)
				{
					degreeStableTime.reset();
				}
				else if(degreeStableTime.getMsec() >= mStableTime)
				{
					angle.roll = asinf(data.x / scalar);
					angle.pitch = asinf(data.y / scalar);

					if(mUnit == UNIT_DEGREE)
					{
						angle.roll = angle.roll * 180 / PI;
						angle.pitch = angle.pitch * 180 / PI;
					}

					mAngle = angle;

					// mUpdateFlag가 중복으로 접근되는 이슈가 큰 이슈로 여겨지지 않아 Mutex를 구지 사용안함
					mUpdateFlag = true;
				}

				mScalar.calculate(scalar);
			}
		}

		thread::yield();
	}
}

void EulerAngle2Axis::run(void)
{
	runThread();
}

void EulerAngle2Axis::stop(void)
{
	stopThread();
}

bool EulerAngle2Axis::isUpdated(void)
{
	bool flag = mUpdateFlag;
	
	// mUpdateFlag가 중복으로 접근되는 이슈가 큰 이슈로 여겨지지 않아 Mutex를 구지 사용안함
	mUpdateFlag = false;

	return flag;
}

EulerAngle2Axis::angle_t EulerAngle2Axis::getAngle(void)
{
	return mAngle;
}

