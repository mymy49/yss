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

#if YSS_L_HEAP_USE == true

// lmalloc의 내부 계산 식(수정 금지)
#define	YSS_L_HEAP_TOTAL_CLUSTER_SIZE		(YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE / 32)
#define YSS_L_HEAP_CLUSTER_BASE_ADDR		(YSS_SDRAM_ADDR)
#define YSS_L_HEAP_TABLE_BASE_ADDR			(YSS_L_HEAP_CLUSTER_BASE_ADDR + YSS_L_HEAP_TOTAL_CLUSTER_SIZE * sizeof(int32_t))
#define YSS_L_HEAP_BASE_ADDR				(YSS_L_HEAP_TABLE_BASE_ADDR + YSS_L_MAX_NUM_OF_MALLOC * 12)

#if YSS_L_HEAP_SIZE % YSS_L_HEAP_CLUSTER_SIZE
#error "YSS_L_HEAP_SIZE가 YSS_L_HEAP_CLUSTER_SIZE로 나누어 떨어지게 설정해주세요."
#endif

#if YSS_L_HEAP_CLUSTER_SIZE % 4
#error "YSS_L_HEAP_CLUSTER_SIZE 4로 나누어 떨어지게 설정해주세요."
#endif

#if YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE < 32
#error "YSS_L_HEAP_SIZE의 값이 YSS_L_HEAP_CLUSTER_SIZE로 나누어 32보다 작지 않게 해주세요."
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

void lfree(void *addr)
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