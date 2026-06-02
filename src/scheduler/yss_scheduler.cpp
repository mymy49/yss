/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

// yss scheduler implementation.
// This module provides cooperative/threaded scheduling with PendSV
// context switching, thread creation, signal/trigger support, and
// syscall-level synchronization primitives.

#include <drv/mcu.h>
#include <stdint.h>

#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE)

#include <config.h>
#include <util/runtime.h>
#include <std_ext/malloc.h>
#include <yss/scheduler.h>
#include <yss/instance.h>
#include <drv/Timer.h>
#include <string.h>

// Pre-allocation depth used for scheduler stack bookkeeping.
#define PREOCCUPY_DEPTH		(MAX_THREAD * 2)

// Scheduler task descriptor.
struct Task
{
	int32_t *malloc;          // Allocated stack memory
	uint32_t *sp;             // Current stack pointer for context switching
	uint32_t  size;           // Stack size in bytes
	bool able;                // Thread is runnable
	bool allocated;           // This slot is in use
	bool trigger;             // Trigger thread flag
	bool signalLock;          // Prevent thread from being signaled
	int16_t lockCnt;          // Nested protection count
	void (*entry)(void *);    // Entry function for the thread
	void *var;                // Parameter passed to the entry function
};

// Global task list and scheduler metadata.
Task gYssThreadList[MAX_THREAD] = 
{
	{0, 0, 0, true, true, false, false, 0, 0, 0}
};

static int32_t gNumOfThread = 1;                // Number of active thread slots
static threadId_t  gCurrentThreadNum;            // Currently executing thread
static threadId_t  gRoundRobinThreadNum;         // Round robin scheduler index
static threadId_t gHoldingThreadNum = -1;        // Thread currently holding execution
static threadId_t gPendingSignalThreadList[MAX_THREAD];
static uint32_t gPendingSignalThreadCount;       // Pending signal/trigger queue count

static Mutex gMutex;                             // Global scheduler mutex

// Temporarily disable SysTick to prevent an interrupt-driven context switch
// while scheduler state is being modified.
inline void lockContextSwitch(void)
{
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

// Re-enable SysTick after a protected scheduler operation completes.
inline void unlockContextSwitch(void)
{
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

namespace thread
{
void terminateThread(void);

// Create a new thread with a stack and optional signal locking behavior.
threadId_t add(void (*func)(void *var), void *var, int32_t stackSize, bool signalLock) __attribute__((optimize("-O1")));
threadId_t add(void (*func)(void *var), void *var, int32_t stackSize, bool signalLock)
{
	uint32_t i, *sp;

	gMutex.lock();
	// Prevent concurrent scheduler modifications during thread creation.
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
		if (!gYssThreadList[i].allocated)
		{
			gYssThreadList[i].allocated = true;
			break;
		}
	}

	// Allocate stack memory for the new thread.
	gYssThreadList[i].malloc = new int32_t [stackSize/sizeof(int32_t )];

	if (!gYssThreadList[i].malloc)
	{
		gYssThreadList[i].allocated = false;
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("쓰레드 생성 실패!! 스택 할당에 실패 했습니다.");
#endif
		return -1;
	}
	gYssThreadList[i].size = stackSize;

#if(FILL_THREAD_STACK)
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

	// Convert allocated stack size from bytes to 32-bit words.
	stackSize >>= 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	sp = (uint32_t *)((int32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;									// xPSR
	*sp-- = (int32_t )func;								// PC
	*sp-- = (int32_t )(void (*)(void))terminateThread;	// LR
	sp -= 4;
	*sp-- = (int32_t )var;								// R0
	sp -= 24;
	*sp = 0xfffffffd;									// R3
	gYssThreadList[i].sp = sp;
#else
	sp = (uint32_t *)((uint32_t )gYssThreadList[i].malloc & ~0x7) - 1;
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
	gYssThreadList[i].signalLock = signalLock;

	gNumOfThread++;
	gMutex.unlock();
	return i;
}

// Create a thread and preload additional registers r8-r12 before the first context switch.
threadId_t add(void (*func)(void *), void *var, int32_t  stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock) __attribute__((optimize("-O1")));
threadId_t add(void (*func)(void *), void *var, int32_t  stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock)
{
	uint32_t  i, *sp;

	gMutex.lock();
	// Lock scheduler while setting up the new thread.
	if (gNumOfThread >= MAX_THREAD)
	{
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("쓰레드 생성 실패!! 쓰레드 생성 갯수가 설정된 %d개를 초과했습니다.", MAX_THREAD);
#endif
		return -1;
	}

	// Find the next available scheduler slot.
	for (i = 1; i < MAX_THREAD; i++)
	{
		if (!gYssThreadList[i].allocated)
		{
			gYssThreadList[i].allocated = true;
			break;
		}
	}
	
	// Allocate memory for the thread stack.
	gYssThreadList[i].malloc = new int32_t (stackSize/sizeof(int32_t ));

	if (!gYssThreadList[i].malloc)
	{
		gYssThreadList[i].allocated = false;
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("쓰레드 생성 실패!! 스택 할당에 실패 했습니다.");
#endif
		return -1;
	}
	gYssThreadList[i].size = stackSize;

#if(FILL_THREAD_STACK)
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

	stackSize >>= 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	sp = (uint32_t *)((uint32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;									// xPSR
	*sp-- = (uint32_t )func;							// PC
	*sp-- = (uint32_t )(void (*)(void))terminateThread;	// LR
	*sp-- = (uint32_t )r12;								// R12
	sp -= 3;
	*sp-- = (uint32_t )var;								// R0
	sp -= 16;
	*sp-- = (uint32_t )r11;								// R11
	*sp-- = (uint32_t )r10;								// R10
	*sp-- = (uint32_t )r9;								// R9
	*sp-- = (uint32_t )r8;								// R8
	sp -= 4;
	*sp = 0xfffffffd;									// R3
	gYssThreadList[i].sp = sp;
#else
	sp = (uint32_t *)((uint32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;									// xPSR
	*sp-- = (uint32_t )func;								// PC
	*sp-- = (uint32_t )(void (*)(void))terminateThread;	// LR
	*sp-- = (uint32_t )r12;								// R12
	sp -= 3;
	*sp-- = (uint32_t )var;								// R0
	*sp-- = (uint32_t )r11;								// R11
	*sp-- = (uint32_t )r10;								// R10
	*sp-- = (uint32_t )r9;								// R9
	*sp-- = (uint32_t )r8;								// R8
	sp -= 4;
	*sp = 0xfffffffd;									// R3
	gYssThreadList[i].sp = sp;
#endif
	gYssThreadList[i].lockCnt = 0;
	gYssThreadList[i].trigger = false;
	gYssThreadList[i].entry = func;
	gYssThreadList[i].able = true;
	gYssThreadList[i].signalLock = signalLock;

	gNumOfThread++;
	gMutex.unlock();
	return i;
}

// Wrapper for creating a parameterless thread.
threadId_t add(void (*func)(void), int32_t stackSize, bool signalLock) __attribute__((optimize("-O1")));
threadId_t add(void (*func)(void), int32_t stackSize, bool signalLock)
{
	return add((void (*)(void *))func, 0, stackSize, signalLock);
}

// Wrapper for creating a parameterless thread with initial register values.
threadId_t add(void (*func)(void), int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock) __attribute__((optimize("-O1")));
threadId_t add(void (*func)(void), int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock)
{
	return add((void (*)(void *))func, 0, stackSize, r8, r9, r10, r11, r12, signalLock);
}

// Remove a thread and release its resources if it is not the current thread.
void remove(threadId_t &id) __attribute__((optimize("-O1")));
void remove(threadId_t &id)
{
	// Prevent a context switch while removing this thread.
	lockContextSwitch();
	if(gYssThreadList[id].lockCnt > 0)
	{
		// The thread is currently protected; wait until protection is released.
		unlockContextSwitch();
		while (gYssThreadList[id].lockCnt > 0)
			yield();
		lockContextSwitch();
	}
	gMutex.lock();

	if (id != gCurrentThreadNum && id > 0)
	{
		if (gYssThreadList[id].allocated == true)
		{
			// Mark thread as inactive and free its stack memory.
			gYssThreadList[id].able = false;
			gYssThreadList[id].allocated = false;
			delete gYssThreadList[id].malloc;
			gYssThreadList[id].malloc = 0;
			gYssThreadList[id].sp = 0;
			gYssThreadList[id].size = 0;
			gNumOfThread--;
		}
	}

	// If the removed thread was the next round-robin candidate,
	// advance to the next runnable thread.
	if(id == gRoundRobinThreadNum)
	{
		do
		{
			gRoundRobinThreadNum++;
			if (gRoundRobinThreadNum >= MAX_THREAD)
				gRoundRobinThreadNum = 0;
		}while (!gYssThreadList[gRoundRobinThreadNum].able);
	}

	if(id == gHoldingThreadNum)
		gHoldingThreadNum = -1;
	
	// Reset caller's ID to indicate removal.
	id = 0;
	unlockContextSwitch();
	gMutex.unlock();
}

// Return ID of the currently running thread.
threadId_t getCurrentThreadId(void) __attribute__((optimize("-O1")));
threadId_t getCurrentThreadId(void)
{
	return gCurrentThreadNum;
}

// Increment thread protection count to defer removal or scheduler interference.
void protect(void) __attribute__((optimize("-O1")));
void protect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt++;
	__enable_irq();
}

// Decrement protection count and allow this thread to be removed when safe.
void unprotect(void) __attribute__((optimize("-O1")));
void unprotect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt--;
	__enable_irq();
}

// Terminate the current thread and switch to the next runnable thread.
void terminateThread(void) __attribute__((optimize("-O1")));
void terminateThread(void)
{
	lockHmalloc();
	__disable_irq();
	hfree(gYssThreadList[gCurrentThreadNum].malloc);
	gYssThreadList[gCurrentThreadNum].able = false;
	gYssThreadList[gCurrentThreadNum].allocated = false;
	gNumOfThread--;

	if(gCurrentThreadNum == gRoundRobinThreadNum)
	{
		do
		{
			gRoundRobinThreadNum++;
			if (gRoundRobinThreadNum >= MAX_THREAD)
				gRoundRobinThreadNum = 0;
		}while (!gYssThreadList[gRoundRobinThreadNum].able);
	}

	if(gCurrentThreadNum == gHoldingThreadNum)
		gHoldingThreadNum = -1;

	__enable_irq();
	unlockHmalloc();
	thread::yield();
}

// Suspend execution of the current thread for the specified milliseconds.
void delay(uint32_t delayTime) __attribute__((optimize("-O1")));
void delay(uint32_t delayTime)
{
	uint64_t endTime = runtime::getUsec() + delayTime * 1000;

	while (1)
	{
		if (runtime::getUsec() >= endTime)
			return;

		thread::yield();
	}
}

// Suspend execution of the current thread for the specified microseconds.
void delayUs(uint32_t delayTime) __attribute__((optimize("-O1")));
void delayUs(uint32_t delayTime)
{
	uint64_t endTime = runtime::getUsec() + delayTime;
	while (1)
	{
		if (runtime::getUsec() >= endTime)
			return;

		thread::yield();
	}
}

// Block current thread until another thread signals it.
void waitForSignal(void) __attribute__((optimize("-O1")));
void waitForSignal(void)
{
	gYssThreadList[gCurrentThreadNum].able = false;
	yield();
}

// Signal a thread to wake it and enqueue it for scheduling.
void signal(threadId_t id) __attribute__((optimize("-O1")));
void signal(threadId_t id)
{
	uint32_t count;

	// Ignore invalid thread IDs and threads that have signaled disabled.
	if(id < 0 || gYssThreadList[id].signalLock)
		return;

	__disable_irq();
	if(gPendingSignalThreadCount >= MAX_THREAD)
		// Pending queue is full; cannot enqueue another signal.
		goto finish;
	
	// Check for duplicate signal entries and move existing entry to the end.
	for(uint32_t i = 0; i < gPendingSignalThreadCount; i++)
	{
		if(gPendingSignalThreadList[i] == id)
		{
			count = gPendingSignalThreadCount - 1;
			for(uint32_t j = i; j < count; j++)
				gPendingSignalThreadList[j] = gPendingSignalThreadList[j+1];
			gPendingSignalThreadList[count] = id;
			if(gHoldingThreadNum < 0)
				gHoldingThreadNum = gCurrentThreadNum;
			goto finish;
		}
	}
	
	// Enqueue the signaled thread and unblock the current thread if needed.
	gPendingSignalThreadList[gPendingSignalThreadCount++] = id;
	gYssThreadList[gCurrentThreadNum].able = true;
	if(gHoldingThreadNum < 0)
		gHoldingThreadNum = gCurrentThreadNum;
finish :
	// Trigger PendSV to perform the context switch after the signal.
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	__enable_irq();
}

// Request a context switch by setting PendSV if supported.
void yield(void) __attribute__((optimize("-O1")));
void yield(void)
{
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC)
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
#endif
}
}

namespace trigger
{
void disable(void);

// Create a trigger task. Trigger tasks are activated explicitly via trigger::run().
triggerId_t add(void (*func)(void *), void *var, int32_t stackSize) __attribute__((optimize("-O1")));
triggerId_t add(void (*func)(void *), void *var, int32_t stackSize)
{
	int32_t i;
	gMutex.lock();

	if (gNumOfThread >= MAX_THREAD)
	{
		gMutex.unlock();
		return -1;
	}

	for (i = 1; i < MAX_THREAD; i++)
	{
		if (!gYssThreadList[i].allocated)
		{
			gYssThreadList[i].allocated = true;
			break;
		}
	}

	gYssThreadList[i].malloc = new int32_t [stackSize/sizeof(int32_t )];

	if (!gYssThreadList[i].malloc)
	{
		gYssThreadList[i].allocated = false;
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
	gYssThreadList[i].signalLock = false;

	gNumOfThread++;

	gMutex.unlock();
	return i;
}

// Create a parameterless trigger task.
triggerId_t add(void (*func)(void), int32_t  stackSize) __attribute__((optimize("-O1")));
triggerId_t add(void (*func)(void), int32_t  stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

// Remove a trigger task from scheduler state.
void remove(triggerId_t &id) __attribute__((optimize("-O1")));
void remove(triggerId_t &id)
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

	if (id != gCurrentThreadNum && id > 0)
	{
		if (gYssThreadList[id].allocated == true)
		{
			gYssThreadList[id].able = false;
			gYssThreadList[id].allocated = false;
			delete gYssThreadList[id].malloc;
			gYssThreadList[id].sp = 0;
			gYssThreadList[id].size = 0;
			gNumOfThread--;
		}
	}

	if(gCurrentThreadNum == gRoundRobinThreadNum)
	{
		do
		{
			gRoundRobinThreadNum++;
			if (gRoundRobinThreadNum >= MAX_THREAD)
				gRoundRobinThreadNum = 0;
		}while (!gYssThreadList[gRoundRobinThreadNum].able);
	}

	if(gCurrentThreadNum == gHoldingThreadNum)
		gHoldingThreadNum = -1;
	
	id = 0;
	unlockContextSwitch();
	gMutex.unlock();
}

// Activate a trigger task by initializing its stack and enqueueing it.
void run(triggerId_t id) __attribute__((optimize("-O1")));
void run(triggerId_t id)
{
	uint32_t buf, *sp;

	__disable_irq();

	if(!gYssThreadList[id].trigger || gYssThreadList[id].able)
	{
		// Reject non-trigger tasks or triggers that are already active.
		__enable_irq();	 
		return;
	}

	// Avoid enqueueing the same trigger twice.
	for(buf=0;buf<gPendingSignalThreadCount;buf++)
	{
		if(gPendingSignalThreadList[buf] == id)
		{
			// Trigger is already pending, do not enqueue again.
			__enable_irq();	 
			return;
		}
	}
	
	buf = gYssThreadList[id].size >> 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	sp = (uint32_t *)((uint32_t )gYssThreadList[id].malloc & ~0x7) - 1;
	sp += buf;
	*sp-- = 0x61000000;								// xPSR
	*sp-- = (uint32_t )gYssThreadList[id].entry;	// PC
	*sp-- = (uint32_t )(void (*)(void))disable;		// LR
	sp -= 4;
	*sp-- = (uint32_t )gYssThreadList[id].var;		// R0
	sp -= 24;
	*sp = 0xfffffffd;								// R3
	gYssThreadList[id].sp = sp;
#else
	sp = (uint32_t *)((int32_t )gYssThreadList[id].malloc & ~0x7) - 1;
	sp += buf;
	*sp-- = 0x61000000;								// xPSR
	*sp-- = (uint32_t )gYssThreadList[id].entry;		// PC
	*sp-- = (uint32_t )(void (*)(void))disable;		// LR
	sp -= 4;
	*sp-- = (uint32_t )gYssThreadList[id].var;		// R0
	sp -= 8;
	*sp = 0xfffffffd;								// R3
	gYssThreadList[id].sp = sp;
#endif
	gYssThreadList[id].able = true;
	gPendingSignalThreadList[gPendingSignalThreadCount++] = id;
	if(gHoldingThreadNum < 0)
		gHoldingThreadNum = gCurrentThreadNum;
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	__enable_irq();	 
}

// Disable the currently running trigger, preventing it from running until re-triggered.
void disable(void) __attribute__((optimize("-O1")));
void disable(void)
{
	// Keep this trigger disabled until it is explicitly re-triggered.
	// If run() is called from an interrupt context instead of PendSV,
	// the disable condition must remain enforced.
	while(1)
	{
		__disable_irq();
		gYssThreadList[gCurrentThreadNum].able = false;
		__enable_irq();
		thread::yield();
	}
}

void protect(void) __attribute__((optimize("-O1")));
void protect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt++;
	__enable_irq();
}

void unprotect(void) __attribute__((optimize("-O1")));
void unprotect(void)
{
	__disable_irq();
	gYssThreadList[gCurrentThreadNum].lockCnt--;
	__enable_irq();

	if (gYssThreadList[gCurrentThreadNum].lockCnt == 0)
		thread::yield();
}
}

// System exception handlers used by the scheduler for context switching.
extern "C"
{
	void SysTick_Handler(void)__attribute__((optimize("-O1")));
	void SysTick_Handler(void)
	{
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC)
		// Do not disable interrupts here to reduce latency for higher-priority interrupts.
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
#endif
#endif
	}

	// PendSV handler performs the actual thread context switch.
	void PendSV_Handler(void)__attribute__((optimize("-O1"))) __attribute__ ((naked));
	void PendSV_Handler(void) 
	{
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
		// PSP에 저장된 스택 포인터를 R0로 이동
		asm("mrs r0, psp");

#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
		// FPU 관련 레지스터 백업
		asm("vstmdb r0!,{s16-s31}");
		asm("mov r3, lr");
		asm("stmdb r0!, {r3-r11}");
#else
		// LR 레지스터를 R3에 넣고 R3 ~ R11까지 스택에 백업
		asm("mov r3, lr");
		asm("stmdb r0!, {r3-r11}");
#endif
#elif defined(YSS__CORE_CM0_H_GENERIC)
		asm("mrs r0, psp");

		// LR 레지스터를 R3에 넣고 R3 ~ R11까지 스택에 백업
		asm("mov r3, lr");
		asm("sub r0, r0, #36");
		asm("stm r0!, {r3-r7}");
		asm("mov r3, r8");
		asm("mov r4, r9");
		asm("mov r5, r10");
		asm("mov r6, r11");
		asm("stm r0!, {r3-r6}");
		asm("sub r0, r0, #36");
#endif
		// 스택 포인터 저장
		uint32_t  sp;
		asm("mov %0, r0" : "=r" (sp) :);

		gYssThreadList[gCurrentThreadNum].sp = (uint32_t*)sp;
		sp = 0;
		
		// 스택 포인터 교환  
		__disable_irq();
		if(gPendingSignalThreadCount)
		{	// signal 또는 trigger가 발생하면 진입
			gPendingSignalThreadCount--;
			gCurrentThreadNum = gPendingSignalThreadList[gPendingSignalThreadCount];
			gPendingSignalThreadList[gPendingSignalThreadCount] = 0;
			sp = (uint32_t)gYssThreadList[gCurrentThreadNum].sp;
			__enable_irq();
		}
		else if(gHoldingThreadNum >= 0)
		{
			gCurrentThreadNum = gHoldingThreadNum;
			gHoldingThreadNum = -1;
			sp = (uint32_t)gYssThreadList[gCurrentThreadNum].sp;
		}
		else
		{	// signal 또는 trigger에서 SP 갱신이 없다면 라운드 로빈 스케줄러에 의해 선택된 쓰레드 수행
			__enable_irq();
			do
			{
				gRoundRobinThreadNum++;
				if (gRoundRobinThreadNum >= MAX_THREAD)
					gRoundRobinThreadNum = 0;
			}while (!gYssThreadList[gRoundRobinThreadNum].able);

			gCurrentThreadNum = gRoundRobinThreadNum;
			sp = (uint32_t)gYssThreadList[gCurrentThreadNum].sp;
		}
		__enable_irq();

		asm("mov r0, %0" : : "r" (sp));
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
		// SYSTICK의 카운터를 초기화
		// SYSTICK이 문맥 전환 시작전에 한번 오버플로우가 났기 때문에
		// 중간에 인터럽트 등이 발생해 카운터가 감소했을 수 있으므로 초기화를 진행함
		asm("ldr r3, =0xe000e010");
		asm("movs r1, #0");
		asm("str r1, [r3, #8]");

		// FPU 관련 레지스터 복원
		asm("ldm  r0!, {r3-r11}");
		asm("vldm r0!,{s16-s31}");
		asm("mov lr, r3");
#else
		// SYSTICK의 카운터를 초기화
		// SYSTICK이 문맥 전환 시작전에 한번 오버플로우가 났기 때문에
		// 중간에 인터럽트 등이 발생해 카운터가 감소했을 수 있으므로 초기화를 진행함
		asm("ldr r3, =0xe000e010");
		asm("movs r1, #0");
		asm("str r1, [r3, #8]");

		// 백업했던 R3~R11까지 스택으로부터 복원
		asm("ldm  r0!, {r3-r11}");
		asm("mov lr, r3");
#endif
#elif defined(YSS__CORE_CM0_H_GENERIC)

		// SYSTICK의 카운터를 초기화
		// SYSTICK이 문맥 전환 시작전에 한번 오버플로우가 났기 때문에
		// 중간에 인터럽트 등이 발생해 카운터가 감소했을 수 있으므로 초기화를 진행함
		asm("ldr r3, =0xe000e010");
		asm("movs r1, #0");
		asm("str r1, [r3, #8]");

		// 백업했던 R8~R11까지 스택으로부터 복원
		asm("add r0, r0, #20");
		asm("ldm  r0!, {r3-r6}");
		asm("mov r8, r3");
		asm("mov r9, r4");
		asm("mov r10, r5");
		asm("mov r11, r6");

		// 백업했던 R3~R7까지 스택으로부터 복원
		asm("sub r0, r0, #36");
		asm("ldm  r0!, {r3-r7}");
		asm("add r0, r0, #16");
#endif
		// RO에 저장된 스택 포인터를 PSP로 이동
		asm("msr psp, r0");
#endif
		asm("bx lr");
	}
}

#else

// Scheduling is disabled for this MCU configuration, so yield is a no-op.
namespace thread
{
extern "C"
{
void yield(void) __attribute__((optimize("-O1")));
void yield(void)
{

}
}
}

#endif

