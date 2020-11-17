////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>

#include <yss/thread.h>
#include <config.h>
#include <internal/malloc.h>
#include <yss/mcu.h>

// hmalloc의 전체 클러스터 용량(수정 금지)
#define	YSS_H_HEAP_TOTAL_CLUSTER_SIZE	(YSS_H_HEAP_SIZE / YSS_H_HEAP_CLUSTER_SIZE / 32)

#if YSS_H_HEAP_SIZE % YSS_H_HEAP_CLUSTER_SIZE
#error "YSS_H_HEAP_SIZE가 YSS_H_HEAP_CLUSTER_SIZE로 나누어 떨어지게 설정해주세요."
#endif

#if YSS_H_HEAP_CLUSTER_SIZE % 4
#error "YSS_H_HEAP_CLUSTER_SIZE 4로 나누어 떨어지게 설정해주세요."
#endif

#if YSS_H_HEAP_SIZE / YSS_H_HEAP_CLUSTER_SIZE < 32
#error "YSS_H_HEAP_SIZE의 값이 YSS_H_HEAP_CLUSTER_SIZE로 나누어 32보다 작지 않게 해주세요."
#endif

static unsigned long gCluster[YSS_H_HEAP_TOTAL_CLUSTER_SIZE];
static char	gHeap[YSS_H_HEAP_SIZE];
static Malloc::MallocTable gMallocDataTable[YSS_H_MAX_NUM_OF_MALLOC];
static unsigned long gWaitNum, gCurrentNum;

static Malloc::MallocSet gMallocSet = 
{
	gHeap, 
	gMallocDataTable, gCluster, 
	YSS_H_HEAP_TOTAL_CLUSTER_SIZE, 
	YSS_H_HEAP_CLUSTER_SIZE,
	YSS_H_MAX_NUM_OF_MALLOC,
    (unsigned long)&gHeap + YSS_H_HEAP_SIZE
};

void* hmalloc(unsigned long	size)
{
	void *addr;
	unsigned long myNum;
	
	thread::protect();
	__disable_irq();
	myNum = gWaitNum;
	gWaitNum++;
	__enable_irq();

	while(myNum != gCurrentNum)
	{
		thread::switchContext();
	}

	addr = Malloc::malloc(gMallocSet, size);

	__disable_irq();
	gCurrentNum++;
	__enable_irq();
	thread::unprotect();
	
	return addr;
}

void hfree(void *addr)
{
	unsigned long myNum;
	
	thread::protect();
	__disable_irq();
	myNum = gWaitNum;
	gWaitNum++;
	__enable_irq();

	while(myNum != gCurrentNum)
	{
		thread::switchContext();
	}

	Malloc::free(gMallocSet, addr);

	__disable_irq();
	gCurrentNum++;
	__enable_irq();
	thread::unprotect();
}

#if YSS_NEW_DELETE_USING_HEAP == YSS_H_HEAP
void* operator new[] (unsigned int size)
{
	return hmalloc(size);
}

void* operator new (unsigned int size)
{
	return hmalloc(size);
}

void operator delete (void *pt)
{
	hfree(pt);
}
#endif
