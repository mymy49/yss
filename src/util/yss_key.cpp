/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE)


#include <config.h>
#include <util/key.h>
#include <util/runtime.h>
#include <yss/thread.h>
#include <stdint.h>

class Key
{
	bool (*mTrigger[2])(void);
	bool *mPushFlag, mCycleFlag;
	void (*mHandler)(void);
	int32_t mThreadId;
	int32_t *mInt, mIntMax, mIntMin;
	uint32_t mDeadtime, mRepeatDelayTime;
	uint32_t mAcceptTime;

  public:
	Key(void);
	bool setPush(bool (*trigger)(void), void (*handler)(void));
	bool setPushWithRepeat(bool (*trigger)(void), void (*handler)(void), uint32_t repeatDelay);
	bool setPush(bool (*trigger)(void), bool &flag);
	bool setRelease(bool (*trigger)(void), bool &flag);
	bool setCountUp(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max);
	bool setCountUpWithRepeat(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, uint32_t acceptTime, uint32_t repeatDelay);
	bool setCountDown(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max);
	bool setCountDownWithRepeat(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, uint32_t acceptTime, uint32_t repeatDelay);
	void reset(void);
	~Key(void);
	bool isDetect(void);
	void waitWhileDeadtime(void);
	void delayForRepeatTime(void);
	void handle(void);
	void setFlag(void);
	void countup(void);
	void countdown(void);
	void setCycle(bool en);
	uint32_t getAcceptTime(void);
	uint32_t getDeadTime(void);
	void setDeadTime(uint32_t time);
};

static Key gKey[NUM_OF_YSS_KEY];

namespace key
{
uint8_t gHandlerCnt;
void clear(void)
{
	for (int32_t  i = 0; i < gHandlerCnt; i++)
		gKey[i].reset();
	gHandlerCnt = 0;
}

bool addPushHandler(bool (*trigger)(void), void (*handler)(void), int32_t  deadTime)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"	
	if (gHandlerCnt >= NUM_OF_YSS_KEY)
		return false;
#pragma GCC diagnostic pop

	if (gKey[gHandlerCnt].setPush(trigger, handler))
	{
		gKey[gHandlerCnt++].setDeadTime(deadTime);
		return true;
	}
	else
		return false;
}

bool addPushHandler(bool (*trigger)(void), bool &flag, int32_t  deadTime)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"	
	if (gHandlerCnt >= NUM_OF_YSS_KEY)
		return false;
#pragma GCC diagnostic pop

	if (gKey[gHandlerCnt].setPush(trigger, flag))
	{
		gKey[gHandlerCnt++].setDeadTime(deadTime);
		return true;
	}
	else
		return false;
}

bool addReleaseHandler(bool (*trigger)(void), bool &flag)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"	
	if (gHandlerCnt >= NUM_OF_YSS_KEY)
		return false;
#pragma GCC diagnostic pop

	if (gKey[gHandlerCnt].setRelease(trigger, flag))
	{
		gHandlerCnt++;
		return true;
	}
	else
		return false;
}

bool addHandlerWithRepeat(bool (*trigger)(void), void (*handler)(void), uint32_t repeatDelay)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"	
	if (gHandlerCnt >= NUM_OF_YSS_KEY)
		return false;
#pragma GCC diagnostic pop

	return gKey[gHandlerCnt++].setPushWithRepeat(trigger, handler, repeatDelay);
}

bool addCountUpHandler(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, bool cycle)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"	
	if (gHandlerCnt >= NUM_OF_YSS_KEY)
		return false;
#pragma GCC diagnostic pop

	gKey[gHandlerCnt].setCycle(cycle);
	return gKey[gHandlerCnt++].setCountUp(trigger, num, min, max);
}

bool addCountUpHandlerWithRepeat(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, bool cycle, uint32_t acceptDelay, uint32_t repeatDelay)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"	
	if (gHandlerCnt >= NUM_OF_YSS_KEY)
		return false;
#pragma GCC diagnostic pop

	gKey[gHandlerCnt].setCycle(cycle);
	return gKey[gHandlerCnt++].setCountUpWithRepeat(trigger, num, min, max, acceptDelay, repeatDelay);
}

bool addCountDownHandler(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, bool cycle)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"	
	if (gHandlerCnt >= NUM_OF_YSS_KEY)
		return false;
#pragma GCC diagnostic pop

	gKey[gHandlerCnt].setCycle(cycle);
	return gKey[gHandlerCnt++].setCountDown(trigger, num, min, max);
}

bool addCountDownHandlerWithRepeat(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, bool cycle, uint32_t acceptDelay, uint32_t repeatDelay)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"	
	if (gHandlerCnt >= NUM_OF_YSS_KEY)
		return false;
#pragma GCC diagnostic pop

	gKey[gHandlerCnt].setCycle(cycle);
	return gKey[gHandlerCnt++].setCountDownWithRepeat(trigger, num, min, max, acceptDelay, repeatDelay);
}
}

static void thread_handlerPush(void *arg);
static void thread_handlerPushWithRepeat(void *arg);
static void thread_handlerPushUsingBoolFlag(void *arg);
static void thread_handlerReleaseUsingBoolFlag(void *arg);
static void thread_handlerCountUp(void *arg);
static void thread_handlerCountUpWithRepeat(void *arg);
static void thread_handlerCountDown(void *arg);
static void thread_handlerCountDownWithRepeat(void *arg);

Key::Key(void)
{
	mThreadId = 0;
	reset();
}

Key::~Key(void)
{
	if (mThreadId)
		thread::remove(mThreadId);
}

void Key::reset(void)
{
	if (mThreadId)
	{
		thread::remove(mThreadId);
		mThreadId = 0;
	}

	mTrigger[0] = 0;
	mTrigger[1] = 0;
	mHandler = 0;
	mDeadtime = 50;
	mRepeatDelayTime = 50;
}

bool Key::setPush(bool (*trigger)(void), void (*handler)(void))
{
	if (trigger)
		mTrigger[0] = trigger;
	else
		return false;

	if (handler)
		mHandler = handler;
	else
		return false;

	mThreadId = thread::add(thread_handlerPush, this, 512);

	if (mThreadId < 0)
		return false;
	else
		return true;
}

bool Key::setPushWithRepeat(bool (*trigger)(void), void (*handler)(void), uint32_t repeatDelay)
{
	if (trigger)
		mTrigger[0] = trigger;
	else
		return false;

	if (handler)
		mHandler = handler;
	else
		return false;

	mRepeatDelayTime = repeatDelay;
	mThreadId = thread::add(thread_handlerPushWithRepeat, this, 512);

	if (mThreadId < 0)
		return false;
	else
		return true;
}

bool Key::setPush(bool (*trigger)(void), bool &flag)
{
	if (trigger)
		mTrigger[0] = trigger;
	else
		return false;

	mPushFlag = &flag;
	mThreadId = thread::add(thread_handlerPushUsingBoolFlag, this, 512);

	if (mThreadId < 0)
		return false;
	else
		return true;
}

bool Key::setRelease(bool (*trigger)(void), bool &flag)
{
	if (trigger)
		mTrigger[0] = trigger;
	else
		return false;

	mPushFlag = &flag;
	mThreadId = thread::add(thread_handlerReleaseUsingBoolFlag, this, 512);

	if (mThreadId < 0)
		return false;
	else
		return true;
}

bool Key::setCountUp(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max)
{
	if (trigger)
		mTrigger[0] = trigger;
	else
		return false;

	mInt = &num;
	mIntMin = min;
	mIntMax = max;
	mThreadId = thread::add(thread_handlerCountUp, this, 512);

	if (mThreadId < 0)
		return false;
	else
		return true;
}

bool Key::setCountUpWithRepeat(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, uint32_t acceptDelay, uint32_t repeatDelay)
{
	if (trigger)
		mTrigger[0] = trigger;
	else
		return false;

	mInt = &num;
	mIntMin = min;
	mIntMax = max;
	mRepeatDelayTime = repeatDelay;
	mAcceptTime = acceptDelay;
	mThreadId = thread::add(thread_handlerCountUpWithRepeat, this, 512);

	if (mThreadId < 0)
		return false;
	else
		return true;
}

bool Key::setCountDown(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max)
{
	if (trigger)
		mTrigger[0] = trigger;
	else
		return false;

	mInt = &num;
	mIntMin = min;
	mIntMax = max;
	mThreadId = thread::add(thread_handlerCountDown, this, 512);

	if (mThreadId < 0)
		return false;
	else
		return true;
}

bool Key::setCountDownWithRepeat(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, uint32_t acceptDelay, uint32_t repeatDelay)
{
	if (trigger)
		mTrigger[0] = trigger;
	else
		return false;

	mInt = &num;
	mIntMin = min;
	mIntMax = max;
	mRepeatDelayTime = repeatDelay;
	mAcceptTime = acceptDelay;
	mThreadId = thread::add(thread_handlerCountDownWithRepeat, this, 512);

	if (mThreadId < 0)
		return false;
	else
		return true;
}

void Key::delayForRepeatTime(void)
{
	if (mRepeatDelayTime)
		thread::delay(mRepeatDelayTime);
}

bool Key::isDetect(void)
{
	return mTrigger[0]();
}

void Key::waitWhileDeadtime(void)
{
	if (mDeadtime > 0)
		thread::delay(mDeadtime);
}

void Key::handle(void)
{
	mHandler();
}

void Key::setCycle(bool en)
{
	mCycleFlag = en;
}

void Key::setFlag(void)
{
	if (mPushFlag)
		*mPushFlag = true;
}

void Key::countup(void)
{
	if (mCycleFlag)
	{
		*mInt += 1;
		if (*mInt > mIntMax)
			*mInt = mIntMin;
	}
	else
	{
		if (*mInt < mIntMax)
			*mInt += 1;
	}
}

void Key::countdown(void)
{
	if (mCycleFlag)
	{
		*mInt -= 1;
		if (*mInt < mIntMin)
			*mInt = mIntMax;
	}
	else
	{
		if (*mInt > mIntMin)
			*mInt -= 1;
	}
}

uint32_t Key::getAcceptTime(void)
{
	return mAcceptTime;
}

uint32_t Key::getDeadTime(void)
{
	return mDeadtime;
}

void Key::setDeadTime(uint32_t time)
{
	mDeadtime = time;
}

static void thread_handlerPush(void *arg)
{
	Key *key = (Key *)arg;
	uint64_t detectTime;

	while (key->isDetect())
		thread::yield();

	while (1)
	{
	start:
		while (key->isDetect() == false)
			thread::yield();

		detectTime = runtime::getMsec() + key->getDeadTime();

		while (detectTime >= runtime::getMsec())
		{
			thread::yield();
			if (key->isDetect() == false)
				goto start;
		}

		key->handle();

		while (key->isDetect() == true)
			thread::yield();
	}
}

static void thread_handlerPushWithRepeat(void *arg)
{
	Key *key = (Key *)arg;
	uint64_t detectTime;

	while (key->isDetect())
		thread::yield();

	while (1)
	{
	start:
		while (key->isDetect() == false)
			thread::yield();

		detectTime = runtime::getMsec() + key->getDeadTime();

		while (detectTime >= runtime::getMsec())
		{
			thread::yield();
			if (key->isDetect() == false)
				goto start;
		}

		while (key->isDetect())
		{
			key->handle();
			key->delayForRepeatTime();
		}
	}
}

static void thread_handlerPushUsingBoolFlag(void *arg)
{
	Key *key = (Key *)arg;
	uint64_t detectTime;

	while (key->isDetect())
		thread::yield();

	while (1)
	{
	start:
		while (key->isDetect() == false)
			thread::yield();

		detectTime = runtime::getMsec() + key->getDeadTime();

		while (detectTime >= runtime::getMsec())
		{
			thread::yield();
			if (key->isDetect() == false)
				goto start;
		}

		key->setFlag();

		while (key->isDetect() == true)
			thread::yield();
	}
}

static void thread_handlerReleaseUsingBoolFlag(void *arg)
{
	Key *key = (Key *)arg;
	uint64_t detectTime;

	while (key->isDetect())
		thread::yield();

	while (1)
	{
	start:
		while (key->isDetect() == false)
			thread::yield();

		detectTime = runtime::getMsec() + key->getDeadTime();

		while (detectTime >= runtime::getMsec())
		{
			thread::yield();
			if (key->isDetect() == false)
				goto start;
		}

		while (key->isDetect() == true)
			thread::yield();

		key->setFlag();
	}
}

static void thread_handlerCountUp(void *arg)
{
	Key *key = (Key *)arg;
	uint64_t detectTime;

	while (key->isDetect())
		thread::yield();

	while (1)
	{
	start:
		while (key->isDetect() == false)
			thread::yield();

		detectTime = runtime::getMsec() + key->getDeadTime();

		while (detectTime >= runtime::getMsec())
		{
			thread::yield();
			if (key->isDetect() == false)
				goto start;
		}

		key->countup();

		while (key->isDetect() == true)
			thread::yield();
	}
}

static void thread_handlerCountUpWithRepeat(void *arg)
{
	Key *key = (Key *)arg;
	uint32_t acceptTime = key->getAcceptTime(), deadTime = key->getDeadTime();
	uint64_t time, start;

	while (key->isDetect())
		thread::yield();

	while (1)
	{
	start:
		while (key->isDetect() == false)
			thread::yield();

		start = runtime::getMsec();
		do
		{
			thread::yield();
			time = runtime::getMsec();
			if (key->isDetect() == false)
			{
				if (time > start + (uint64_t)deadTime)
					key->countup();
				goto start;
			}
		} while (start + (uint64_t)acceptTime > time);

		while (key->isDetect())
		{
			key->countup();
			key->delayForRepeatTime();
		}
	}
}

static void thread_handlerCountDown(void *arg)
{
	Key *key = (Key *)arg;
	uint64_t detectTime;

	while (key->isDetect())
		thread::yield();

	while (1)
	{
	start:
		while (key->isDetect() == false)
			thread::yield();

		detectTime = runtime::getMsec() + key->getDeadTime();

		while (detectTime >= runtime::getMsec())
		{
			thread::yield();
			if (key->isDetect() == false)
				goto start;
		}

		key->countdown();

		while (key->isDetect() == true)
			thread::yield();
	}
}

static void thread_handlerCountDownWithRepeat(void *arg)
{
	Key *key = (Key *)arg;
	uint32_t acceptTime = key->getAcceptTime(), deadTime = key->getDeadTime();
	uint64_t time, start;

	while (key->isDetect())
		thread::yield();

	while (1)
	{
	start:
		while (key->isDetect() == false)
			thread::yield();

		start = runtime::getMsec();
		do
		{
			thread::yield();
			time = runtime::getMsec();
			if (key->isDetect() == false)
			{
				if (time > start + (uint64_t)deadTime)
					key->countdown();
				goto start;
			}
		} while (start + (uint64_t)acceptTime > time);

		while (key->isDetect())
		{
			key->countdown();
			key->delayForRepeatTime();
		}
	}
}

#endif