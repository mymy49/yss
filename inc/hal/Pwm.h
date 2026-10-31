/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_HAL_PWM__H_
#define	YSS_HAL_PWM__H_

#include <yss/Mutex.h>
#include <yss/error.h>

class Pwm
{
public :
	virtual error_t changeFrequency(uint32_t freq) __attribute__((optimize("-O1"))) = 0;
	
	virtual void start(void) __attribute__((optimize("-O1"))) = 0;

	virtual void stop(void) __attribute__((optimize("-O1"))) = 0;

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1"))) = 0;

	virtual void setDutyRatio(float ratio) __attribute__((optimize("-O1"))) = 0;

	virtual void setCompareValue(uint32_t  counter) __attribute__((optimize("-O1"))) = 0;
};

class PwmCh0 : public Pwm
{

};

class PwmCh1 : public Pwm
{

};

class PwmCh2 : public Pwm
{

};

class PwmCh3 : public Pwm
{

};

#endif

