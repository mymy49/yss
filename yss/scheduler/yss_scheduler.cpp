////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE)

//#include <__cross_studio_io.h>
#include <config.h>
#include <internal/scheduler.h>
#include <string.h>
#include <util/time.h>
#include <yss/malloc.h>
#include <yss/thread.h>
#include <yss/instance.h>
#include <drv/Timer.h>

struct Task
{
	int *malloc;
	int *stack;
	int *sp;
	int size;
	bool able, mallocated, trigger, pending, ready;
	short lockCnt;
	void (*entry)(void *);
	void *var;
};

void terminateThread(void);

inline void lockContextSwitch(void)
{
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

inline void unlockContextSwitch(void)
{
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

namespace trigger
{
void activeTriggerThread(int num);
}

Task gYssThreadList[MAX_THREAD];
static short gPreoccupyThread[MAX_THREAD];
static short gNumOfThread = 1;
static int gCurrentThreadNum;
static Mutex gMutex;
static short gPreoccupyThreadHead, gPreoccupyThreadTail;

void initScheduler(void)
{
	gYssThreadList[0].able = true;
	gYssThreadList[0].mallocated = true;
}

namespace thread
{
void terminateThread(void);

int add(void (*func)(void *var), void *var, int stackSize)
{
	int i, *sp;

	gMutex.lock();
	if (gNumOfThread >= MAX_THREAD)
	{
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("쓰레드 생성 실패!! 쓰레드 생성 갯수가 설정된 %d개를 초과했습니다.", MAX_THREAD);
#endif
		return -1;
	}

	for (i = 1; i < MAX_THREAD; i++)
	{
		if (!gYssThreadList[i].mallocated)
		{
			gYssThreadList[i].mallocated = true;
			break;
		}
	}

	gYssThreadList[i].malloc = new int[stackSize/sizeof(int)];

	if (!gYssThreadList[i].malloc)
	{
		gYssThreadList[i].mallocated = false;
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("쓰레드 생성 실패!! 스텍 할당에 실패 했습니다.");
#endif
		return -1;
	}
	gYssThreadList[i].size = stackSize;
	//		memset(gYssThreadList[i].malloc, 0xaa, stackSize);
	stackSize >>= 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	gYssThreadList[i].stack = (int*)((int)gYssThreadList[i].malloc & ~0x7);
	sp = &gYssThreadList[i].stack[stackSize-1];
	gYssThreadList[i].stack = sp;
	*sp-- = 0x61000000;                           // xPSR
	*sp-- = (int)func;                            // PC
	*sp-- = (int)(void (*)(void))terminateThread;    // LR
	sp -= 4;
	*sp-- = (int)var;                             // R0
	sp -= 24;
	*sp-- = 0xfffffffd;                           // R3
	*sp-- = 0x0;                                 // R2
	*sp = 0xC0000000;                             // R1
	gYssThreadList[i].sp = sp;
#else
	gYssThreadList[i].stack = (int*)((int)gYssThreadList[i].malloc & ~0x7);
	sp = &gYssThreadList[i].stack[stackSize-1];
	gYssThreadList[i].stack = sp;
	*sp-- = 0x61000000;                           // xPSR
	*sp-- = (int)func;                            // PC
	*sp-- = (int)(void (*)(void))terminateThread;    // LR
	sp -= 4;
	*sp-- = (int)var;                             // R0
	sp -= 8;
	*sp = 0xfffffffd;                           // R3
	gYssThreadList[i].sp = sp;
#endif
	gYssThreadList[i].lockCnt = 0;
	gYssThreadList[i].trigger = false;
	gYssThreadList[i].entry = func;
	gYssThreadList[i].able = true;

	gNumOfThread++;
	gMutex.unlock();
	return i;
}

int add(void (*func)(void *), void *var, int stackSize, void *r8, void *r9, void *r10, void *r11, void *r12)
{
	int i, *sp;

	gMutex.lock();
	if (gNumOfThread >= MAX_THREAD)
	{
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("쓰레드 생성 실패!! 쓰레드 생성 갯수가 설정된 %d개를 초과했습니다.", MAX_THREAD);
#endif
		return -1;
	}

	for (i = 1; i < MAX_THREAD; i++)
	{
		if (!gYssThreadList[i].mallocated)
		{
			gYssThreadList[i].mallocated = true;
			break;
		}
	}
	
	gYssThreadList[i].malloc = new int(stackSize/sizeof(int));

	if (!gYssThreadList[i].malloc)
	{
		gYssThreadList[i].mallocated = false;
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("쓰레드 생성 실패!! 스텍 할당에 실패 했습니다.");
#endif
		return -1;
	}
	gYssThreadList[i].size = stackSize;

	stackSize >>= 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	gYssThreadList[i].stack = (int*)((int)gYssThreadList[i].malloc & ~0x7);
	sp = &gYssThreadList[i].stack[stackSize-1];
	gYssThreadList[i].stack = sp;
	*sp-- = 0x61000000;                           // xPSR
	*sp-- = (int)func;                            // PC
	*sp-- = (int)(void (*)(void))terminateThread;    // LR
	sp -= 4;
	*sp-- = (int)var;                             // R0
	sp -= 16;
	*sp-- = (int)r11;                    // R11
	*sp-- = (int)r10;                    // R10
	*sp-- = (int)r9;                     // R9
	*sp-- = (int)r8;                     // R8
	sp -= 4;
	*sp-- = 0xfffffffd;                           // R3
	*sp-- = 0x0;                                 // R2
	*sp = 0xC0000000;                             // R1
	gYssThreadList[i].sp = sp;
#else
	gYssThreadList[i].stack = (int*)((int)gYssThreadList[i].malloc & ~0x7);
	sp = &gYssThreadList[i].stack[stackSize-1];
	gYssThreadList[i].stack = sp;
	*sp-- = 0x61000000;                           // xPSR
	*sp-- = (int)func;                            // PC
	*sp-- = (int)(void (*)(void))terminateThread;    // LR
	*sp-- = (int)r12;                     // R12
	sp -= 3;
	*sp-- = (int)var;                             // R0
	*sp-- = (int)r11;                    // R11
	*sp-- = (int)r10;                    // R10
	*sp-- = (int)r9;                    // R9
	*sp-- = (int)r8;                    // R8
	sp -= 4;
	*sp = 0xfffffffd;                             // R3
	gYssThreadList[i].sp = sp;
#endif
	gYssThreadList[i].lockCnt = 0;
	gYssThreadList[i].trigger = false;
	gYssThreadList[i].entry = func;
	gYssThreadList[i].able = true;

	gNumOfThread++;
	gMutex.unlock();
	return i;
}

int add(void (*func)(void), int stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

int add(void (*func)(void), int stackSize, void *r8, void *r9, void *r10, void *r11, void *r12)
{
	return add((void (*)(void *))func, 0, stackSize, r8, r9, r10, r11, r12);
}

void remove(int num)
{
	lockContextSwitch();
	if(gYssThreadList[num].lockCnt > 0)
	{
		unlockContextSwitch();
		while (gYssThreadList[num].lockCnt > 0)
			yield();
		lockContextSwitch();
	}
	gMutex.lock();

	if (num != gCurrentThreadNum && num > 0)
	{
		if (gYssThreadList[num].mallocated == true)
		{
			gYssThreadList[num].able = false;
			gYssThreadList[num].mallocated = false;
			delete gYssThreadList[num].malloc;
			gYssThreadList[num].stack = 0;
			gYssThreadList[num].malloc = 0;
			gYssThreadList[num].sp = 0;
			gYssThreadList[num].size = 0;
			gNumOfThread--;
		}
	}

	unlockContextSwitch();
	gMutex.unlock();
}

int getCurrentThreadNum(void)
{
	return gCurrentThreadNum;
}

void protect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt++;
	__enable_irq();
}

void protect(short num)
{
	__disable_irq();
	gYssThreadList[num].lockCnt++;
	__enable_irq();
}

void unprotect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt--;
	__enable_irq();
}

void unprotect(short num)
{
	__disable_irq();
	gYssThreadList[num].lockCnt--;
	__enable_irq();
}

void terminateThread(void)
{
	lockHmalloc();
	hfree(gYssThreadList[gCurrentThreadNum].malloc);
	gYssThreadList[gCurrentThreadNum].able = false;
	gYssThreadList[gCurrentThreadNum].mallocated = false;
	gNumOfThread--;
	unlockHmalloc();
	thread::yield();
}

void delay(int delayTime)
{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	long long endTime = time::getRunningUsec() + delayTime * 1000;
#else
	long long endTime = time::getRunningMsec() + delayTime;
#endif
	while (1)
	{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
		if (time::getRunningUsec() >= endTime)
#else
		if (time::getRunningMsec() >= endTime)
#endif
			return;

		thread::yield();
	}
}

#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
void delayUs(int delayTime)
{
	long long endTime = time::getRunningUsec() + delayTime;
	while (1)
	{
		if (time::getRunningUsec() >= endTime)
			return;

		thread::yield();
	}
}
#endif

void waitSignal(void)
{
	gYssThreadList[gCurrentThreadNum].able = false;
	yield();
}

void signal(int threadNum)
{
	__disable_irq();
	gYssThreadList[threadNum].able = true;
	gPreoccupyThread[gPreoccupyThreadHead++] = threadNum;
	if(gPreoccupyThreadHead >= MAX_THREAD)
		gPreoccupyThreadHead = 0;
	SCB->ICSR = SCB_ICSR_PENDSTSET_Msk;
	__enable_irq();
}
}

namespace trigger
{
void disable(void);

int add(void (*func)(void *), void *var, int stackSize)
{
	int i, *sp;
	gMutex.lock();

	if (gNumOfThread >= MAX_THREAD)
	{
		gMutex.unlock();
		return -1;
	}

	for (i = 1; i < MAX_THREAD; i++)
	{
		if (!gYssThreadList[i].mallocated)
		{
			gYssThreadList[i].mallocated = true;
			break;
		}
	}

	gYssThreadList[i].malloc = new int[stackSize/sizeof(int)];

	if (!gYssThreadList[i].malloc)
	{
		gYssThreadList[i].mallocated = false;
		gMutex.unlock();
		return -1;
	}
	gYssThreadList[i].size = stackSize;

	gYssThreadList[i].var = var;
	gYssThreadList[i].lockCnt = 0;
	gYssThreadList[i].trigger = true;
	gYssThreadList[i].entry = func;
	gYssThreadList[i].able = false;
	gYssThreadList[i].ready = false;
	gYssThreadList[i].pending = false;

	gNumOfThread++;

	activeTriggerThread(i);
	gMutex.unlock();
	return i;
}

int add(void (*func)(void), int stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

void remove(int num)
{
	lockContextSwitch();
	if(gYssThreadList[num].lockCnt > 0)
	{
		unlockContextSwitch();
		while (gYssThreadList[num].lockCnt > 0)
			thread::yield();
		lockContextSwitch();
	}

	gMutex.lock();
	while (gYssThreadList[num].lockCnt)
	{
		thread::yield();
	}
	if (num != gCurrentThreadNum && num > 0)
	{
		if (gYssThreadList[num].mallocated == true)
		{
			gYssThreadList[num].able = false;
			gYssThreadList[num].mallocated = false;
			delete gYssThreadList[num].malloc;
			gYssThreadList[num].stack = 0;
			gYssThreadList[num].sp = 0;
			gYssThreadList[num].size = 0;
			gNumOfThread--;
		}
	}

	unlockContextSwitch();
	gMutex.unlock();
}

void run(int num)
{
	__disable_irq();
	if (!gYssThreadList[num].able && gYssThreadList[num].ready)
	{
		gYssThreadList[num].able = true;
		gPreoccupyThread[gPreoccupyThreadHead++] = num;
		if(gPreoccupyThreadHead >= MAX_THREAD)
			gPreoccupyThreadHead = 0;
		SCB->ICSR = SCB_ICSR_PENDSTSET_Msk;
	}
	else
	{
		gYssThreadList[num].pending = true;
	}
	__enable_irq();
}

void activeTriggerThread(int num)
{
	int size = gYssThreadList[num].size >> 2, *sp;
	
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	gYssThreadList[num].stack = (int*)((int)gYssThreadList[num].malloc & ~0x7);
	sp = &gYssThreadList[num].stack[size-1];
	gYssThreadList[num].stack = sp;
	*sp-- = 0x61000000;								// xPSR
	*sp-- = (int)gYssThreadList[num].entry;			// PC
	*sp-- = (int)(void (*)(void))disable;			// LR
	sp -= 4;
	*sp-- = (int)gYssThreadList[num].var;			// R0
	sp -= 24;
	*sp-- = 0xfffffffd;								// R3
	*sp-- = 0x0;									// R2
	*sp = 0xC0000000;								// R1
	gYssThreadList[num].sp = sp;
#else
	gYssThreadList[num].stack = (int*)((int)gYssThreadList[num].malloc & ~0x7);
	sp = &gYssThreadList[num].stack[size-1];
	gYssThreadList[num].stack = sp;
	*sp-- = 0x61000000;                           // xPSR
	*sp-- = (int)gYssThreadList[num].entry;         // PC
	*sp-- = (int)(void (*)(void))disable;          // LR
	sp -= 4;
	*sp-- = (int)gYssThreadList[num].var;          // R0
	sp -= 8;
	*sp = 0xfffffffd;                           // R3
	gYssThreadList[num].sp = sp;
#endif
	gYssThreadList[num].ready = true;
}

void disable(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].ready = false;
	gYssThreadList[gCurrentThreadNum].able = false;
	__enable_irq();
	thread::yield();
}

void protect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt++;
	__enable_irq();
}

void protect(short num)
{
	__disable_irq();
	gYssThreadList[num].lockCnt++;
	__enable_irq();
}

void unprotect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt--;
	__enable_irq();

	if (gYssThreadList[gCurrentThreadNum].lockCnt == 0)
		thread::yield();
}

void unprotect(short num)
{
	__disable_irq();
	gYssThreadList[num].lockCnt--;
	__enable_irq();
}
}

extern "C"
{
	int *getNextContext(int *sp)
	{
		int i = 0;
		gYssThreadList[gCurrentThreadNum].sp = sp;

		if (gYssThreadList[gCurrentThreadNum].trigger && !gYssThreadList[gCurrentThreadNum].able && !gYssThreadList[gCurrentThreadNum].ready)
		{
			trigger::activeTriggerThread(gCurrentThreadNum);
			if (gYssThreadList[gCurrentThreadNum].pending)
			{
				gYssThreadList[gCurrentThreadNum].pending = false;
				trigger::run(gCurrentThreadNum);
			}
		}

		__disable_irq();
repeat:
		if (gPreoccupyThreadHead != gPreoccupyThreadTail)
		{
			gCurrentThreadNum = gPreoccupyThread[gPreoccupyThreadTail++];
			if(gPreoccupyThreadTail >= MAX_THREAD)
				gPreoccupyThreadTail = 0;

			if (!gYssThreadList[gCurrentThreadNum].able)
				goto repeat;

			SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;
		}
		else
		{
			gCurrentThreadNum++;
			while (!gYssThreadList[gCurrentThreadNum].able)
			{
				gCurrentThreadNum++;
				if (gCurrentThreadNum >= MAX_THREAD)
					gCurrentThreadNum = 0;
			}
		}
		sp = (int *)gYssThreadList[gCurrentThreadNum].sp;
		__enable_irq();
		return sp;
	}
}
#else

extern "C"
{
volatile int *getNextContext(int *sp)
{
	return 0;
}
}

#endif


