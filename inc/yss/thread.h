/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_THREAD__H_
#define YSS_THREAD__H_

#include <drv/mcu.h>
#include <yss/Mutex.h>

typedef int32_t		threadId_t;

namespace thread
{
	threadId_t add(void (*func)(void *), void *var, int32_t stackSize, bool signalLock = false);
	threadId_t add(void (*func)(void *), void *var, int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock = false);
	threadId_t add(void (*func)(void), int32_t stackSize, bool signalLock = false);
	threadId_t add(void (*func)(void), int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock = false);
	void remove(threadId_t id);
	threadId_t getCurrentThreadId(void);
	void protect(void);
	void protect(threadId_t id);
	void unprotect(void);
	void unprotect(threadId_t id);
	void delay(uint32_t delayTime);
	void delayUs(uint32_t delayTime);
	void waitForSignal(void);
	void signal(threadId_t id);

extern "C"
{
	void yield(void);
}
}

typedef int32_t		triggerId_t;

namespace trigger
{
	triggerId_t add(void (*func)(void *), void *var, int32_t stackSize);
	triggerId_t add(void (*func)(void), int32_t stackSize);
	void remove(triggerId_t num);
	void run(triggerId_t num);
	void protect(void);
	void protect(triggerId_t num);
	void unprotect(void);
	void unprotect(triggerId_t num);
}

#endif

