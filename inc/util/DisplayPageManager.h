/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_DIPLAY_PAGE_MANAGER__H_
#define YSS_UTIL_DIPLAY_PAGE_MANAGER__H_

#include <stdint.h>
#include <yss/Mutex.h>
#include <yss/Trigger.h>

class DisplayPageManager : private Mutex, private Trigger
{
public:
	DisplayPageManager(int16_t maxCount);

	~DisplayPageManager();

	int16_t add(void (*func)(void*));

	void play(int16_t id, uint32_t stackSize = 512);

private:
	int16_t mMaxCount, mCount, mUpdateIndex;
	uint32_t mStackSize;
	threadId_t mId;
	void* mVar;

	void (**mFunctionList)(void*);

	void trigger(void) override;
};

#endif

