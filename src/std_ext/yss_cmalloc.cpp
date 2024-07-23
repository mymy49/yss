/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/thread.h>
#include <config.h>
#include <internal/malloc.h>
#include <drv/peripheral.h>

#if defined(CCMSRAM_BASE)
#define CCMDATARAM_BASE	CCMSRAM_BASE
#endif

#if YSS_C_HEAP_USE && defined(CCMDATARAM_BASE)

static uint32_t gWaitNum, gCurrentNum;

static Malloc::MallocSet gMallocSet = 
{
	(void*)YSS_C_HEAP_BASE_ADDR, 
	(Malloc::MallocTable*)YSS_C_HEAP_TABLE_BASE_ADDR, 
	(uint32_t *)YSS_C_HEAP_CLUSTER_BASE_ADDR, 
	YSS_C_HEAP_TOTAL_CLUSTER_SIZE, YSS_C_HEAP_CLUSTER_SIZE,
	YSS_C_MAX_NUM_OF_MALLOC,
	CCMDATARAM_BASE + YSS_C_HEAP_SIZE
};

void* cmalloc(uint32_t size)
{
	void *addr;
	uint32_t myNum;
	
	thread::protect();
	__disable_irq();
	myNum = gWaitNum;
	gWaitNum++;
	__enable_irq();

	while(myNum != gCurrentNum)
	{
		thread::yield();
	}

	addr = Malloc::malloc(gMallocSet, size);

	__disable_irq();
	gCurrentNum++;
	__enable_irq();
	thread::unprotect();

	return addr;
}

void cfree(void *addr)
{
	uint32_t myNum;
	
	thread::protect();
	__disable_irq();
	myNum = gWaitNum;
	gWaitNum++;
	__enable_irq();

	while(myNum != gCurrentNum)
	{
		thread::yield();
	}

	Malloc::free(gMallocSet, addr);

	__disable_irq();
	gCurrentNum++;
	__enable_irq();
	thread::unprotect();
}

#endif

