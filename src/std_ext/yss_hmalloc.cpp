/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>
#include <stdlib.h>
#include <yss/thread.h>
#include <cmsis/cmsis_compiler.h>

static uint32_t gWaitNum, gCurrentNum;
#if defined(ST_CUBE_IDE)
#else
static uint32_t gFreeSpace = __HEAP_SIZE__;
#endif

void lockHmalloc(void)
{
	uint32_t myNum;

	thread::protect();
	__disable_irq();
	myNum = gWaitNum;
	gWaitNum++;
	__enable_irq();

	while (myNum != gCurrentNum)
	{
		thread::yield();
	}
}

void unlockHmalloc(void)
{
	__disable_irq();
	gCurrentNum++;
	__enable_irq();
	thread::unprotect();
}

void *hmalloc(uint32_t size)
{
	void* addr = malloc(size);
#if !defined(ST_CUBE_IDE)
	if((uint32_t)addr > 0)
	{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
		uint32_t *size = &((uint32_t*)addr)[-1];
		gFreeSpace -= *size;	
#pragma GCC diagnostic pop
	}
#endif
	return addr;
}

void hfree(void *addr)
{
#if !defined(ST_CUBE_IDE)
	uint32_t *size = &((uint32_t*)addr)[-1];
	gFreeSpace += *size;	
#endif
	free(addr);
}

uint32_t getHeapRemainingCapacity(void)
{
#if !defined(ST_CUBE_IDE)
	return gFreeSpace;
#else
	return 0;
#endif
}

void *operator new[](unsigned int size)
{
	void *addr;
	
	lockHmalloc();
	addr = malloc(size);
#if !defined(ST_CUBE_IDE)
	if((uint32_t)addr > 0)
	{
		uint32_t *msize = &((uint32_t*)addr)[-1];
		gFreeSpace -= *msize;
	}
#endif
	unlockHmalloc();

	return addr;
}

void *operator new(unsigned int size)
{
	void *addr;

	lockHmalloc();
	addr = malloc(size);
#if !defined(ST_CUBE_IDE)
	if((uint32_t)addr > 0)
	{
		uint32_t *size = &((uint32_t*)addr)[-1];
		gFreeSpace -= *size;	
	}
#endif
	unlockHmalloc();

	return addr;
}

void operator delete(void *pt) noexcept 
{
	lockHmalloc();
#if !defined(ST_CUBE_IDE)
	uint32_t *size = &((uint32_t*)pt)[-1];
	gFreeSpace += *size;	
#endif
	free(pt);
	unlockHmalloc();
}

void operator delete[](void *pt) noexcept 
{
	lockHmalloc();
#if !defined(ST_CUBE_IDE)
	uint32_t *size = &((uint32_t*)pt)[-1];
	gFreeSpace += *size;	
#endif
	free(pt);
	unlockHmalloc();
}

