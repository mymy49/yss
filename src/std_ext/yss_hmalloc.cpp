////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
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
#if defined(ST_CUBE_IDE)
extern uint32_t _Min_Heap_Size;
static uint32_t gFreeSpace = _Min_Heap_Size;
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

void *operator new[](unsigned int size)
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

void *operator new(unsigned int size)
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

