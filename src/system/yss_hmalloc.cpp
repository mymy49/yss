/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>
#include <stdlib.h>
#include <yss/scheduler.h>

static uint32_t gWaitNum, gCurrentNum;
static uint32_t gFreeSpace = __HEAP_SIZE__;

void lockHmalloc(void)
{
	uint32_t myNum;

	// Protect against context switches while updating the ticket counter.
	thread::protect();
	__disable_irq();
	myNum = gWaitNum;
	gWaitNum++;
	__enable_irq();

	// Wait until our ticket number is served.
	while (myNum != gCurrentNum)
	{
		thread::yield();
	}
}

void unlockHmalloc(void)
{
	// Release the ticket lock and restore thread protection state.
	__disable_irq();
	gCurrentNum++;
	__enable_irq();
	thread::unprotect();
}

void *hmalloc(uint32_t size)
{
	void* addr = malloc(size);

	if((uint32_t)addr > 0)
	{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
		// The runtime allocator stores the allocated size immediately before the returned pointer.
		uint32_t *size = &((uint32_t*)addr)[-1];
		gFreeSpace -= *size;	
#pragma GCC diagnostic pop
	}

	return addr;
}

void hfree(void *addr)
{
	// Retrieve the stored allocation size from the metadata header.
	uint32_t *size = &((uint32_t*)addr)[-1];
	gFreeSpace += *size;
	free(addr);
}

uint32_t getHeapRemainingCapacity(void)
{
	return gFreeSpace;
}

void *operator new[](unsigned int size)
{
	void *addr;
	
	// Serialize heap allocation to update free space atomically.
	lockHmalloc();
	addr = malloc(size);

	if((uint32_t)addr > 0)
	{
		// Deduct the recorded allocation size from the global heap budget.
		uint32_t *msize = &((uint32_t*)addr)[-1];
		gFreeSpace -= *msize;
	}
	unlockHmalloc();

	return addr;
}

void *operator new(unsigned int size)
{
	void *addr;

	// Serialize heap allocation to protect global free space tracking.
	lockHmalloc();
	addr = malloc(size);

	if((uint32_t)addr > 0)
	{
		uint32_t *size = &((uint32_t*)addr)[-1];
		gFreeSpace -= *size;	
	}
	unlockHmalloc();

	return addr;
}

void operator delete(void *pt) noexcept 
{
	lockHmalloc();
	uint32_t *size = &((uint32_t*)pt)[-1];
	gFreeSpace += *size;	
	free(pt);
	unlockHmalloc();
}

void operator delete[](void *pt) noexcept 
{
	lockHmalloc();
	uint32_t *size = &((uint32_t*)pt)[-1];
	gFreeSpace += *size;	
	free(pt);
	unlockHmalloc();
}

