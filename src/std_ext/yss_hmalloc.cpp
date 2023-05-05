////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>
#include <stdlib.h>
#include <yss/thread.h>
#include <cmsis/cmsis_compiler.h>

static uint32_t gWaitNum, gCurrentNum;
static uint32_t gFreeSpace = __HEAP_SIZE__;

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
	if((uint32_t)addr >= 0)
	{
		uint32_t *size = &((uint32_t*)addr)[-1];
		gFreeSpace -= *size;	
	}
	return addr;
}

void hfree(void *addr)
{
	uint32_t *size = &((uint32_t*)addr)[-1];
	gFreeSpace += *size;	
	free(addr);
}

uint32_t getHeapRemainingCapacity(void)
{
	return gFreeSpace;
}

void *operator new[](uint32_t size)
{
	void *addr;
	
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

void *operator new(uint32_t size)
{
	void *addr;

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

void operator delete(void *pt)
{
	lockHmalloc();
	uint32_t *size = &((uint32_t*)pt)[-1];
	gFreeSpace += *size;	

	free(pt);
	unlockHmalloc();
}

