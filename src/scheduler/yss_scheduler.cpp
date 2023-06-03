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

#include <drv/mcu.h>
#include <stdint.h>

#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE)

#include <config.h>
#include <internal/scheduler.h>
#include <string.h>
#include <util/runtime.h>
#include <std_ext/malloc.h>
#include <yss/thread.h>
#include <yss/instance.h>
#include <drv/Timer.h>

#define PREOCCUPY_DEPTH		(MAX_THREAD * 2)

struct Task
{
	int32_t *malloc;
	int32_t *sp;
	int32_t  size;
	bool able, mallocated, trigger, pending, ready;
	int16_t lockCnt;
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
void activeTriggerThread(int32_t  num);
}

Task gYssThreadList[MAX_THREAD];
static int32_t gPreoccupyThread[PREOCCUPY_DEPTH];
static int32_t gNumOfThread = 1;
static int32_t  gCurrentThreadNum;
static Mutex gMutex;
static int32_t gPreoccupyThreadHead, gPreoccupyThreadTail;

void initializeScheduler(void)
{
	gYssThreadList[0].able = true;
	gYssThreadList[0].mallocated = true;
}

namespace thread
{
void terminateThread(void);

threadId add(void (*func)(void *var), void *var, int32_t stackSize)
{
	int32_t i, *sp;

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

	gYssThreadList[i].malloc = new int32_t [stackSize/sizeof(int32_t )];

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

#if(FILL_THREAD_STACK)
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

	stackSize >>= 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	sp = (int32_t *)((int32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;									// xPSR
	*sp-- = (int32_t )func;								// PC
	*sp-- = (int32_t )(void (*)(void))terminateThread;	// LR
	sp -= 4;
	*sp-- = (int32_t )var;								// R0
	sp -= 24;
	*sp-- = 0xfffffffd;									// R3
	*sp-- = 0x0;										// R2
	*sp = 0xC0000000;									// R1
	gYssThreadList[i].sp = sp;
#else
	sp = (int32_t *)((int32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;									// xPSR
	*sp-- = (int32_t )func;								// PC
	*sp-- = (int32_t )(void (*)(void))terminateThread;	// LR
	sp -= 4;
	*sp-- = (int32_t )var;								// R0
	sp -= 8;
	*sp = 0xfffffffd;									// R3
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

threadId add(void (*func)(void *), void *var, int32_t  stackSize, void *r8, void *r9, void *r10, void *r11, void *r12)
{
	int32_t  i, *sp;

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
	
	gYssThreadList[i].malloc = new int32_t (stackSize/sizeof(int32_t ));

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

#if(FILL_THREAD_STACK)
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

	stackSize >>= 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	sp = (int32_t *)((int32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;									// xPSR
	*sp-- = (int32_t )func;								// PC
	*sp-- = (int32_t )(void (*)(void))terminateThread;	// LR
	sp -= 4;
	*sp-- = (int32_t )var;								// R0
	sp -= 16;
	*sp-- = (int32_t )r11;								// R11
	*sp-- = (int32_t )r10;								// R10
	*sp-- = (int32_t )r9;								// R9
	*sp-- = (int32_t )r8;								// R8
	sp -= 4;
	*sp-- = 0xfffffffd;									// R3
	*sp-- = 0x0;										// R2
	*sp = 0xC0000000;									// R1
	gYssThreadList[i].sp = sp;
#else
	sp = (int32_t *)((int32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;									// xPSR
	*sp-- = (int32_t )func;								// PC
	*sp-- = (int32_t )(void (*)(void))terminateThread;	// LR
	*sp-- = (int32_t )r12;								// R12
	sp -= 3;
	*sp-- = (int32_t )var;								// R0
	*sp-- = (int32_t )r11;								// R11
	*sp-- = (int32_t )r10;								// R10
	*sp-- = (int32_t )r9;								// R9
	*sp-- = (int32_t )r8;								// R8
	sp -= 4;
	*sp = 0xfffffffd;									// R3
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

threadId add(void (*func)(void), int32_t stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

threadId add(void (*func)(void), int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12)
{
	return add((void (*)(void *))func, 0, stackSize, r8, r9, r10, r11, r12);
}

void remove(threadId id)
{
	lockContextSwitch();
	if(gYssThreadList[id].lockCnt > 0)
	{
		unlockContextSwitch();
		while (gYssThreadList[id].lockCnt > 0)
			yield();
		lockContextSwitch();
	}
	gMutex.lock();

	if (id != gCurrentThreadNum && id > 0)
	{
		if (gYssThreadList[id].mallocated == true)
		{
			gYssThreadList[id].able = false;
			gYssThreadList[id].mallocated = false;
			delete gYssThreadList[id].malloc;
			gYssThreadList[id].malloc = 0;
			gYssThreadList[id].sp = 0;
			gYssThreadList[id].size = 0;
			gNumOfThread--;
		}
	}

	unlockContextSwitch();
	gMutex.unlock();
}

threadId getCurrentThreadId(void)
{
	return gCurrentThreadNum;
}

void protect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt++;
	__enable_irq();
}

void protect(threadId num)
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

void unprotect(threadId num)
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

void delay(int32_t delayTime)
{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	int64_t endTime = runtime::getUsec() + delayTime * 1000;
#else
	int64_t endTime = runtime::getMsec() + delayTime;
#endif
	while (1)
	{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
		if (runtime::getUsec() >= endTime)
#else
		if (runtime::getMsec() >= endTime)
#endif
			return;

		thread::yield();
	}
}

#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
void delayUs(int32_t delayTime)
{
	int64_t endTime = runtime::getUsec() + delayTime;
	while (1)
	{
		if (runtime::getUsec() >= endTime)
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

void signal(threadId id)
{
	__disable_irq();
	gYssThreadList[id].able = true;
	gPreoccupyThread[gPreoccupyThreadHead++] = id;
	if(gPreoccupyThreadHead >= PREOCCUPY_DEPTH)
		gPreoccupyThreadHead = 0;

	gPreoccupyThread[gPreoccupyThreadHead++] = gCurrentThreadNum;
	if(gPreoccupyThreadHead >= PREOCCUPY_DEPTH)
		gPreoccupyThreadHead = 0;
	SCB->ICSR = SCB_ICSR_PENDSTSET_Msk;
	__enable_irq();
}
}

namespace trigger
{
void disable(void);

triggerId add(void (*func)(void *), void *var, int32_t stackSize)
{
	int32_t i, *sp;
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

	gYssThreadList[i].malloc = new int32_t [stackSize/sizeof(int32_t )];

	if (!gYssThreadList[i].malloc)
	{
		gYssThreadList[i].mallocated = false;
		gMutex.unlock();
		return -1;
	}
	gYssThreadList[i].size = stackSize;

#if(FILL_THREAD_STACK)
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

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

triggerId add(void (*func)(void), int32_t  stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

void remove(triggerId id)
{
	lockContextSwitch();
	if(gYssThreadList[id].lockCnt > 0)
	{
		unlockContextSwitch();
		while (gYssThreadList[id].lockCnt > 0)
			thread::yield();
		lockContextSwitch();
	}

	gMutex.lock();
	while (gYssThreadList[id].lockCnt)
	{
		thread::yield();
	}
	if (id != gCurrentThreadNum && id > 0)
	{
		if (gYssThreadList[id].mallocated == true)
		{
			gYssThreadList[id].able = false;
			gYssThreadList[id].mallocated = false;
			delete gYssThreadList[id].malloc;
			gYssThreadList[id].sp = 0;
			gYssThreadList[id].size = 0;
			gNumOfThread--;
		}
	}

	unlockContextSwitch();
	gMutex.unlock();
}

void run(triggerId id)
{
	__disable_irq();
	if (!gYssThreadList[id].able && gYssThreadList[id].ready)
	{
		gYssThreadList[id].able = true;
		gPreoccupyThread[gPreoccupyThreadHead++] = id;
		if(gPreoccupyThreadHead >= PREOCCUPY_DEPTH)
			gPreoccupyThreadHead = 0;

		gPreoccupyThread[gPreoccupyThreadHead++] = gCurrentThreadNum;
		if(gPreoccupyThreadHead >= PREOCCUPY_DEPTH)
			gPreoccupyThreadHead = 0;

		SCB->ICSR = SCB_ICSR_PENDSTSET_Msk;
	}
	else
	{
		gYssThreadList[id].pending = true;
	}
	__enable_irq();
}

void activeTriggerThread(triggerId id)
{
	int32_t  size = gYssThreadList[id].size >> 2, *sp;
	
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	sp = (int32_t *)((int32_t )gYssThreadList[id].malloc & ~0x7) - 1;
	sp += size;
	*sp-- = 0x61000000;								// xPSR
	*sp-- = (int32_t )gYssThreadList[id].entry;	// PC
	*sp-- = (int32_t )(void (*)(void))disable;		// LR
	sp -= 4;
	*sp-- = (int32_t )gYssThreadList[id].var;		// R0
	sp -= 24;
	*sp-- = 0xfffffffd;								// R3
	*sp-- = 0x0;									// R2
	*sp = 0xC0000000;								// R1
	gYssThreadList[id].sp = sp;
#else
	sp = (int32_t *)((int32_t )gYssThreadList[id].malloc & ~0x7) - 1;
	sp += size;
	*sp-- = 0x61000000;								// xPSR
	*sp-- = (int32_t )gYssThreadList[id].entry;	// PC
	*sp-- = (int32_t )(void (*)(void))disable;		// LR
	sp -= 4;
	*sp-- = (int32_t )gYssThreadList[id].var;		// R0
	sp -= 8;
	*sp = 0xfffffffd;                           // R3
	gYssThreadList[id].sp = sp;
#endif
	gYssThreadList[id].ready = true;
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

void protect(triggerId id)
{
	__disable_irq();
	gYssThreadList[id].lockCnt++;
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

void unprotect(triggerId id)
{
	__disable_irq();
	gYssThreadList[id].lockCnt--;
	__enable_irq();
}
}

extern "C"
{
	int32_t *getNextContext(int32_t *sp)
	{
		int32_t  i = 0;
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
			if(gPreoccupyThreadTail >= PREOCCUPY_DEPTH)
				gPreoccupyThreadTail = 0;

			if (!gYssThreadList[gCurrentThreadNum].able)
				goto repeat;

			SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;
		}
		else
		{
			gCurrentThreadNum++;
			if (gCurrentThreadNum >= MAX_THREAD)
				gCurrentThreadNum = 0;

			while (!gYssThreadList[gCurrentThreadNum].able)
			{
				gCurrentThreadNum++;
				if (gCurrentThreadNum >= MAX_THREAD)
					gCurrentThreadNum = 0;
			}
		}
		sp = (int32_t *)gYssThreadList[gCurrentThreadNum].sp;
		__enable_irq();
		return sp;
	}
}
#else

extern "C"
{
volatile int32_t *getNextContext(int32_t *sp)
{
	return 0;
}
}

#endif


