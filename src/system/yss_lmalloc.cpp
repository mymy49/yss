/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file yss_lmalloc.cpp
 * @brief Local heap memory allocator (lmalloc/lfree) implementation.
 *
 * @details
 * Manages allocation and deallocation of memory from the external SDRAM-based local heap.
 * Employs a thread-safe ticket lock mechanism to serialize allocations from multiple threads.
 */

#include <yss/scheduler.h>
#include <config.h>
#include <yss/malloc.h>
#include <drv/peripheral.h>

#if YSS_L_HEAP_USE == true

// Internal calculation formulas for lmalloc (Do not modify)
#define	YSS_L_HEAP_TOTAL_CLUSTER_SIZE		(YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE / 32)
#define YSS_L_HEAP_CLUSTER_BASE_ADDR		(YSS_SDRAM_ADDR)
#define YSS_L_HEAP_TABLE_BASE_ADDR			(YSS_L_HEAP_CLUSTER_BASE_ADDR + YSS_L_HEAP_TOTAL_CLUSTER_SIZE * sizeof(int32_t))
#define YSS_L_HEAP_BASE_ADDR				(YSS_L_HEAP_TABLE_BASE_ADDR + YSS_L_MAX_NUM_OF_MALLOC * 12)

#if YSS_L_HEAP_SIZE % YSS_L_HEAP_CLUSTER_SIZE
#error "Please configure YSS_L_HEAP_SIZE to be divisible by YSS_L_HEAP_CLUSTER_SIZE."
#endif

#if YSS_L_HEAP_CLUSTER_SIZE % 4
#error "Please configure YSS_L_HEAP_CLUSTER_SIZE to be divisible by 4."
#endif

#if YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE < 32
#error "Please configure YSS_L_HEAP_SIZE divided by YSS_L_HEAP_CLUSTER_SIZE to be at least 32."
#endif

static uint32_t gWaitNum, gCurrentNum;

static Malloc::MallocSet gMallocSet = 
{
	(void*)YSS_L_HEAP_BASE_ADDR, 
	(Malloc::MallocTable*)YSS_L_HEAP_TABLE_BASE_ADDR, 
	(uint32_t *)YSS_L_HEAP_CLUSTER_BASE_ADDR, 
	YSS_L_HEAP_TOTAL_CLUSTER_SIZE, YSS_L_HEAP_CLUSTER_SIZE,
	YSS_L_MAX_NUM_OF_MALLOC,
	YSS_SDRAM_ADDR + YSS_L_HEAP_SIZE
};

void* lmalloc(uint32_t size)
{
	void *addr;
	uint32_t myNum;

	// Acquire a ticket lock to serialize access to the local heap allocator.
	thread::protect();
	__disable_irq();
	myNum = gWaitNum;
	gWaitNum++;
	__enable_irq();

	// Wait until it is our turn to allocate.
	while(myNum != gCurrentNum)
	{
		thread::yield();
	}

	// Perform the allocation from the local heap.
	addr = Malloc::malloc(gMallocSet, size);

	// Release the ticket lock and restore interrupt/thread protection state.
	__disable_irq();
	gCurrentNum++;
	__enable_irq();
	thread::unprotect();

	return addr;
}

void lfree(void *addr)
{
	uint32_t myNum;

	// Acquire the ticket lock before modifying the shared local heap structures.
	thread::protect();
	__disable_irq();
	myNum = gWaitNum;
	gWaitNum++;
	__enable_irq();

	// Wait until it is our turn to free memory.
	while(myNum != gCurrentNum)
	{
		thread::yield();
	}

	// Free the block from the local heap allocator.
	Malloc::free(gMallocSet, addr);

	// Release the ticket lock and restore scheduling state.
	__disable_irq();
	gCurrentNum++;
	__enable_irq();
	thread::unprotect();
}

#endif