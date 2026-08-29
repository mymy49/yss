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

#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE) && !defined(YSS__MULTI_CORE)

#include <config.h>
#include <util/runtime.h>
#include <yss/hmalloc.h>
#include <yss/scheduler.h>
#include <yss/instance.h>
#include <drv/Timer.h>
#include <string.h>

#if defined(__FPU_PRESENT) && __FPU_USED == 1
#define MIN_STACK_SIZE		512
#else
#define MIN_STACK_SIZE		256
#endif


// Pre-allocation depth used for scheduler stack bookkeeping.
#define PREOCCUPY_DEPTH		(MAX_THREAD * 2)

// Scheduler task descriptor.
typedef struct
{
	int32_t *malloc;          // Allocated stack memory
	uint32_t *sp;             // Current stack pointer for context switching
	uint32_t  size;           // Stack size in bytes
	void (*entry)(void *);    // Entry function for the thread
	void *var;                // Parameter passed to the entry function
	threadId_t indexNumber;
	int16_t lockCnt;          // Nested protection count
	bool able;                // Thread is runnable
	bool allocated;           // This slot is in use
	bool trigger;             // Trigger thread flag
	bool signalLock;          // Prevent thread from being signaled
	bool waitingForSignal;
}task_t;

typedef struct
{
	uint64_t endtime;
	threadId_t id;
}delay_t;

// Global task list and scheduler metadata.
task_t gYssThreadList[MAX_THREAD] = 
{
	{0, 0, 0, 0, 0, 0, 0, true, true, false, false, false}
};

delay_t gYssDelayList[MAX_THREAD];

static volatile int32_t gNumOfThread = 1;                // Number of active thread slots
static volatile threadId_t gCurrentThreadNum;            // Currently executing thread
static volatile threadId_t gRoundRobinThreadNum;         // Round robin scheduler index
static volatile threadId_t gPendingSignalThreadList[MAX_THREAD];
static volatile uint32_t gPendingSignalThreadCount;       // Pending signal/trigger queue count
static volatile uint32_t gActivatedThreadCount = 1;
static volatile threadId_t gActivatedThreadList[MAX_THREAD] = {0};
static volatile int32_t gDelayCount;

static Mutex gMutex;                             // Global scheduler mutex

void setDelayTimer(threadId_t id, uint64_t sleepTime);

inline void insertToActivatedThreadList(threadId_t id)
{
	if(gYssThreadList[id].able == false && gActivatedThreadCount < MAX_THREAD)
	{
		gActivatedThreadList[gActivatedThreadCount] = id;
		gYssThreadList[id].able = true;
		gYssThreadList[id].indexNumber = gActivatedThreadCount++;
	}
}

inline void removeFromActivatedThreadList(threadId_t id)
{
	if(gYssThreadList[id].able)
	{
		gActivatedThreadCount--;
		for(uint32_t i = gYssThreadList[id].indexNumber; i < gActivatedThreadCount; i++)
		{
			gActivatedThreadList[i] = gActivatedThreadList[i + 1];
			gYssThreadList[gActivatedThreadList[i]].indexNumber = i;		
		}
		gYssThreadList[id].able = false;
	}
}

inline void disableSystickInterrupt(void)
{
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

inline void enableSystickInterrupt(void)
{
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

static inline bool isValidThreadId(threadId_t id)
{
    return id >= 0 && id < MAX_THREAD;
}

static inline bool isAllocatedThreadId(threadId_t id)
{
    return id >= 0 &&
           id < MAX_THREAD &&
           gYssThreadList[id].allocated;
}

namespace thread
{
void terminateThread(void);

threadId_t add(void (*func)(void *), void *var, int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock) __attribute__((optimize("-O1")));
threadId_t add(void (*func)(void *), void *var, int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock)
{
	task_t *thread;

    if (!func)
        return -1;

    // 1. Align stack size to an 8-byte boundary and enforce the minimum size requirement[cite: 5].
    stackSize = (stackSize + 7) & ~0x7;
    if (stackSize < MIN_STACK_SIZE)
        return -1;

    // 2. Pre-allocate stack buffer outside the critical section to avoid blocking interrupts during heap operations[cite: 5].
    int32_t *stackMem = new int32_t[stackSize / sizeof(int32_t)];
    if (!stackMem)
    {
#if defined(THREAD_MONITOR)
        debug_printf("Thread creation failed!! Stack allocation failed.");
#endif
        return -1;
    }

#if (FILL_THREAD_STACK)
    // Pre-fill stack buffer with watermark pattern for high-water analysis[cite: 5].
    memset(stackMem, 0xAA, stackSize);
#endif

    // 3. Enter critical section by capturing the PRIMASK state.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 4. Validate slot capacity and locate an available scheduler slot[cite: 5].
    if (gNumOfThread >= MAX_THREAD)
    {
        __set_PRIMASK(primask);
        delete[] stackMem;
#if defined(THREAD_MONITOR)
        debug_printf("Thread creation failed!! Exceeded MAX_THREAD limit of %d.", MAX_THREAD);
#endif
        return -1;
    }

    int32_t id = -1;
    for (uint32_t i = 1; i < MAX_THREAD; i++)
    {
        if (!gYssThreadList[i].allocated)
        {
            id = i;
			thread = &gYssThreadList[id];
            thread->allocated = true;
            break;
        }
    }

    if (id < 0)
    {
        __set_PRIMASK(primask);
        delete[] stackMem;
        return -1;
    }

    // 5. Construct the initial ARM Cortex-M exception frame on the allocated stack[cite: 5, 9].
    uint32_t wordCount = stackSize >> 2;
    uint32_t *sp = (uint32_t *)stackMem + wordCount;

    // Ensure 8-byte stack alignment at exception entry point[cite: 5].
    if (((uint32_t)sp & 0x7) == 0)
        sp--;

    *sp-- = 0x61000000;                                     // xPSR (Thumb state)[cite: 5]
    *sp-- = (uint32_t)func;                                 // PC (Thread entry function)[cite: 5]
    *sp-- = (uint32_t)(void (*)(void))terminateThread;      // LR (Return stub upon thread completion)[cite: 5]
    *sp-- = (uint32_t)r12;                                  // R12[cite: 5]
    sp -= 3;                                                // Skip R3, R2, R1[cite: 5]
    *sp-- = (uint32_t)var;                                  // R0 (Parameter)[cite: 5]
    *sp-- = (uint32_t)r11;                                  // R11[cite: 5]
    *sp-- = (uint32_t)r10;                                  // R10[cite: 5]
    *sp-- = (uint32_t)r9;                                   // R9[cite: 5]
    *sp-- = (uint32_t)r8;                                   // R8[cite: 5]
    sp -= 4;                                                // Skip R7-R4[cite: 5]
    *sp = 0xfffffffd;                                       // EXC_RETURN (Thread mode using PSP)[cite: 5, 9]

    // 6. Initialize Task descriptor metadata[cite: 5].
    thread->malloc = stackMem;
    thread->size = stackSize;
    thread->sp = sp;
    thread->lockCnt = 0;
    thread->trigger = false;
    thread->entry = func;
    thread->var = var;
    thread->able = false;
    thread->signalLock = signalLock;
	thread->waitingForSignal = false;

    // 7. Insert the new thread into the active runnable list and increment count[cite: 5].
    insertToActivatedThreadList(id);
    gNumOfThread++;

    // 8. Restore the previous interrupt state.
    __set_PRIMASK(primask);

    return id;
}

threadId_t add(void (*func)(void *var), void *var, int32_t stackSize, bool signalLock) __attribute__((optimize("-O1")));
threadId_t add(void (*func)(void *var), void *var, int32_t stackSize, bool signalLock)
{
	return add(func, var, stackSize, 0, 0, 0, 0, 0, signalLock);
}

threadId_t add(void (*func)(void), int32_t stackSize, bool signalLock) __attribute__((optimize("-O1")));
threadId_t add(void (*func)(void), int32_t stackSize, bool signalLock)
{
	return add((void (*)(void *))func, 0, stackSize, signalLock);
}

threadId_t add(void (*func)(void), int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock) __attribute__((optimize("-O1")));
threadId_t add(void (*func)(void), int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock)
{
	return add((void (*)(void *))func, 0, stackSize, r8, r9, r10, r11, r12, signalLock);
}

void remove(threadId_t &id) __attribute__((optimize("-O1")));
void remove(threadId_t &id)
{
	if (!isAllocatedThreadId(id))
		return;

	// 1. A thread cannot remove itself via remove() (use terminateThread() instead), and invalid IDs are rejected[cite: 5].
	if (id == gCurrentThreadNum || id <= 0)
		return;

	// 2. Wait until the thread's protection count drops to zero before proceeding[cite: 5, 9].
	while (gYssThreadList[id].lockCnt > 0)
	{
		yield();
	}

	// 3. Enter critical section by capturing the PRIMASK state and disabling interrupts.
	uint32_t primask = __get_PRIMASK();
	__disable_irq();

	if (gYssThreadList[id].allocated)
	{
		// 4. Remove from active scheduling and mark as inactive[cite: 5].
		removeFromActivatedThreadList(id);
		gYssThreadList[id].allocated = false;
		gYssThreadList[id].signalLock = true;

		// 5. Purge any pending signal entries for this thread to prevent Use-After-Free in PendSV[cite: 5].
		for (uint32_t i = 0; i < gPendingSignalThreadCount; i++)
		{
			if (gPendingSignalThreadList[i] == id)
			{
				for (uint32_t j = i; j < gPendingSignalThreadCount - 1; j++)
					gPendingSignalThreadList[j] = gPendingSignalThreadList[j + 1];
				gPendingSignalThreadCount--;
				gPendingSignalThreadList[gPendingSignalThreadCount] = 0;
				break;
			}
		}

#if defined(YSS_DELAY_TIMER)
		// Delay 큐에 남아있는 경우 정리 및 필요 시 타이머 재설정
		for (uint32_t i = 0; i < gDelayCount; i++)
		{
			if (gYssDelayList[i].id == id)
			{
				gDelayCount--;
				for (uint32_t j = i; j < gDelayCount; j++)
					gYssDelayList[j] = gYssDelayList[j + 1];

				if (i == 0 && gDelayCount > 0)
				{
					uint64_t curTime = runtime::getUsec();
					if (gYssDelayList[0].endtime > curTime + 1000)
						setDelayTimer(gYssDelayList[0].id, gYssDelayList[0].endtime - curTime - 1000);
					else
						signal(gYssDelayList[0].id);
				}
				break;
			}
		}
#endif

		// 6. Free the allocated stack memory and reset task descriptor fields[cite: 5].
		delete[] gYssThreadList[id].malloc;
		gYssThreadList[id].malloc = nullptr;
		gYssThreadList[id].sp = nullptr;
		gYssThreadList[id].size = 0;
		gNumOfThread--;
	}

	// 8. Invalidate the caller's thread ID reference[cite: 5, 9].
	id = 0;

	// 9. Restore the previous interrupt state.
	__set_PRIMASK(primask);
}

threadId_t getCurrentThreadId(void) __attribute__((optimize("-O1")));
threadId_t getCurrentThreadId(void)
{
	return gCurrentThreadNum;
}

void protect(void) __attribute__((optimize("-O1")));
void protect(void)
{
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Atomically increment the protection count for the currently running thread[cite: 5, 9].
    gYssThreadList[gCurrentThreadNum].lockCnt++;

    // 3. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

void protect(threadId_t id) __attribute__((optimize("-O1")));
void protect(threadId_t id)
{
    if (!isAllocatedThreadId(id))
        return;

    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Increment the protection count for the designated thread[cite: 9].
    gYssThreadList[id].lockCnt++;

    // 3. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

void unprotect(void) __attribute__((optimize("-O1")));
void unprotect(void)
{
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Atomically decrement the protection count, preventing negative underflow[cite: 5, 9].
    if (gYssThreadList[gCurrentThreadNum].lockCnt > 0)
        gYssThreadList[gCurrentThreadNum].lockCnt--;

    bool isUnprotected = (gYssThreadList[gCurrentThreadNum].lockCnt == 0);

    // 3. Restore the previous interrupt state.
    __set_PRIMASK(primask);

    // 4. If fully unprotected, yield to let any waiting remove() call proceed[cite: 5, 9].
    if (isUnprotected)
        yield();
}

void unprotect(threadId_t id) __attribute__((optimize("-O1")));
void unprotect(threadId_t id)
{
    if (!isAllocatedThreadId(id))
        return;

    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Decrement the protection count for the designated thread[cite: 9].
    if (gYssThreadList[id].lockCnt > 0)
        gYssThreadList[id].lockCnt--;

    // 3. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

/// @brief Terminate the current thread and switch to the next runnable thread.
/// @details This function is placed in the LR slot of the initial exception frame so
///          that it is called automatically when the thread's entry function returns.
///          It frees the heap-allocated stack, marks the slot as unused, decrements
///          the thread count, and finally invokes yield() to trigger a PendSV context
///          switch away from this (now freed) thread.
void terminateThread(void) __attribute__((optimize("-O1")));
void terminateThread(void)
{
	// Lock heap allocator before freeing the stack to prevent concurrent modification.
	lockHmalloc();
	__disable_irq();

	// Release the current thread's stack before requesting a context switch.
	// This is intentional: PendSV must perform the final context save using the
	// current PSP before switching to another thread. yss guarantees that this
	// stack cannot be reallocated during this transition, so the memory remains
	// available until PendSV completes the context save.
	delete[] gYssThreadList[gCurrentThreadNum].malloc;
	gYssThreadList[gCurrentThreadNum].signalLock = true;
	removeFromActivatedThreadList(gCurrentThreadNum);
	gYssThreadList[gCurrentThreadNum].allocated = false;
	gNumOfThread--;

	__enable_irq();
	unlockHmalloc();
	// Yield to let PendSV select the next runnable thread.
	thread::yield();
}

void delay(uint32_t delayTime) __attribute__((optimize("-O1")));
void delay(uint32_t delayTime)
{
	delayUs(delayTime * 1000);
}

void delayUs(uint32_t delayTime) __attribute__((optimize("-O1")));
void delayUs(uint32_t delayTime)
{
#if defined(YSS_DELAY_TIMER)
	// Compute the absolute wake-up time in microseconds.
	uint32_t primask = __get_PRIMASK();

	__disable_irq();
	uint64_t curTime = runtime::getUsec();
	uint64_t endTime = curTime + delayTime;

	if(gDelayCount < MAX_THREAD && delayTime > 500)
	{
		int32_t index;

		for(index = 0; index < gDelayCount; index++)
		{
			if(gYssDelayList[index].endtime > endTime)
				break;		
		}

		for(int32_t i = gDelayCount; index < i; i--)
			gYssDelayList[i] = gYssDelayList[i-1];

		gYssDelayList[index].endtime = endTime;
		gYssDelayList[index].id = gCurrentThreadNum;

		gDelayCount++;

		if(index == 0)
		{
			setDelayTimer(gCurrentThreadNum, endTime - curTime - 500);
		}

		waitForSignal();

		__disable_irq();

		for(index = 0; index < gDelayCount; index++)
		{
			if(gCurrentThreadNum == gYssDelayList[index].id)
				break;
		}

		if(index < gDelayCount)
		{
		    gDelayCount--;
		    for(int32_t i = index; i < gDelayCount; i++)
		        gYssDelayList[i] = gYssDelayList[i + 1];

		    if(index == 0 && gDelayCount > 0)
		    {
		        curTime = runtime::getUsec();
		        if(gYssDelayList[0].endtime > curTime + 1000)
		        {
		            setDelayTimer(gYssDelayList[0].id, gYssDelayList[0].endtime - curTime - 500);
		        }
		        else
		        {
		            signal(gYssDelayList[0].id);
		        }
		    }
		}
	}

	__enable_irq();

	while (1)
	{
		// Return as soon as the current time meets or exceeds the deadline.
		if (runtime::getUsec() >= endTime)
		{
			__set_PRIMASK(primask);
			return;
		}

		// Yield the CPU so other threads can execute during the delay.
		thread::yield();
	}
#else
	// Compute the absolute wake-up time in microseconds.
	uint64_t endTime = runtime::getUsec() + delayTime;

	while (1)
	{
		// Return as soon as the current time meets or exceeds the deadline.
		if (runtime::getUsec() >= endTime)
			return;

		// Yield the CPU so other threads can execute during the delay.
		thread::yield();
	}
#endif
}

void waitForSignal(void) __attribute__((optimize("-O1")));
void waitForSignal(void)
{
    removeFromActivatedThreadList(gCurrentThreadNum);
	gYssThreadList[gCurrentThreadNum].waitingForSignal = true;

	if(gActivatedThreadCount == 0)
	{
		disableSystickInterrupt();
		__enable_irq();
		__WFI();
	}
	else	
		__enable_irq();

    yield();
}

void signal(threadId_t id) __attribute__((optimize("-O1")));
void signal(threadId_t id)
{	
	task_t *thread = &gYssThreadList[id];
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();

    if (!isAllocatedThreadId(id))
        return;

    __disable_irq();

    // 2. Reject invalid IDs or threads that explicitly disallow signaling[cite: 5, 9].
    if (id < 0 || thread->signalLock || thread->waitingForSignal == false)
    {
        __set_PRIMASK(primask);
        return;
    }

    // 3. Guard against pending dispatch queue overflow[cite: 5].
    if (gPendingSignalThreadCount >= MAX_THREAD)
    {
        __set_PRIMASK(primask);
        return;
    }

	if(id == 3)
		__NOP();

	if(thread->able)
	{
	    __set_PRIMASK(primask);

		return;
	}
	else
	{
	    // 4. Ensure the target thread is re-inserted into the active runnable list[cite: 5].
	    insertToActivatedThreadList(id);
		thread->waitingForSignal = false;

		if(gActivatedThreadCount > 0)
			enableSystickInterrupt();

	    // 5. Check if the thread is already in the pending dispatch queue; if so, move it to the tail[cite: 5, 9].
	    for (uint32_t i = 0; i < gPendingSignalThreadCount; i++)
	    {
	        if (gPendingSignalThreadList[i] == id)
	        {
	            uint32_t count = gPendingSignalThreadCount - 1;
	            for (uint32_t j = i; j < count; j++)
	                gPendingSignalThreadList[j] = gPendingSignalThreadList[j + 1];

	            gPendingSignalThreadList[count] = id;

	            goto finish;
	        }
	    }

	    // 6. Enqueue the thread into the pending signal list for prioritized dispatch in PendSV[cite: 5, 9].
	    gPendingSignalThreadList[gPendingSignalThreadCount++] = id;
	}


finish:
    // 8. Request a PendSV context switch to immediately schedule the signaled thread[cite: 5, 9].
    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;

    // 9. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

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

triggerId_t add(void (*func)(void *), void *var, int32_t stackSize) __attribute__((optimize("-O1")));
triggerId_t add(void (*func)(void *), void *var, int32_t stackSize)
{
	task_t *thread;

    if (!func)
        return -1;

    // 1. Align stack size to an 8-byte boundary and enforce minimum size[cite: 5].
    stackSize = (stackSize + 7) & ~0x7;
    if (stackSize < MIN_STACK_SIZE)
        return -1;

    // 2. Pre-allocate stack buffer outside the critical section[cite: 5].
    int32_t *stackMem = new int32_t[stackSize / sizeof(int32_t)];
    if (!stackMem)
        return -1;

#if (FILL_THREAD_STACK)
    // Pre-fill stack buffer with watermark pattern for diagnostic analysis[cite: 5].
    memset(stackMem, 0xAA, stackSize);
#endif

    // 3. Enter critical section by capturing the PRIMASK state.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 4. Validate slot capacity and locate an available scheduler slot[cite: 5].
    if (gNumOfThread >= MAX_THREAD)
    {
        __set_PRIMASK(primask);
        delete[] stackMem;
        return -1;
    }

    int32_t id = -1;
    for (uint32_t i = 1; i < MAX_THREAD; i++)
    {
        if (!gYssThreadList[i].allocated)
        {
            id = i;
			thread = &gYssThreadList[id];
            thread->allocated = true;
            break;
        }
    }

    if (id < 0)
    {
        __set_PRIMASK(primask);
        delete[] stackMem;
        return -1;
    }

    // 5. Initialize trigger task descriptor metadata[cite: 5].
    // The initial exception frame is constructed on demand inside trigger::run()[cite: 5, 9].
    thread->malloc = stackMem;
    thread->size = stackSize;
    thread->sp = nullptr;
    thread->var = var;
    thread->lockCnt = 0;
    thread->trigger = true;
    thread->entry = func;
    thread->able = false;
    thread->signalLock = false;
	thread->waitingForSignal = false;

    gNumOfThread++;

    // 6. Restore the previous interrupt state.
    __set_PRIMASK(primask);

    return id;
}

triggerId_t add(void (*func)(void), int32_t  stackSize) __attribute__((optimize("-O1")));
triggerId_t add(void (*func)(void), int32_t  stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

void remove(triggerId_t &id) __attribute__((optimize("-O1")));
void remove(triggerId_t &id)
{
    if (!isAllocatedThreadId(id))
        return;

    // 1. A running trigger cannot remove itself directly, and invalid IDs are rejected[cite: 5, 9].
    if (id == gCurrentThreadNum || id <= 0)
        return;

    // 2. Wait until the trigger's protection count drops to zero before proceeding[cite: 5, 9].
    while (gYssThreadList[id].lockCnt > 0)
    {
        thread::yield();
    }

    // 3. Enter critical section by capturing the PRIMASK state and disabling interrupts.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    if (gYssThreadList[id].allocated)
    {
        // 4. Remove from active scheduling and mark as inactive[cite: 5].
        removeFromActivatedThreadList(id);
        gYssThreadList[id].allocated = false;
        gYssThreadList[id].signalLock = true;
        gYssThreadList[id].trigger = false;

        // 5. Purge any pending trigger entries for this ID to prevent Use-After-Free in PendSV[cite: 5].
        for (uint32_t i = 0; i < gPendingSignalThreadCount; i++)
        {
            if (gPendingSignalThreadList[i] == id)
            {
                for (uint32_t j = i; j < gPendingSignalThreadCount - 1; j++)
                    gPendingSignalThreadList[j] = gPendingSignalThreadList[j + 1];
                gPendingSignalThreadCount--;
                gPendingSignalThreadList[gPendingSignalThreadCount] = 0;
                break;
            }
        }

#if defined(YSS_DELAY_TIMER)
        // Delay 큐에 남아있는 경우 정리 및 필요 시 타이머 재설정
		for (uint32_t i = 0; i < gDelayCount; i++)
		{
			if (gYssDelayList[i].id == id)
			{
				gDelayCount--;
				for (uint32_t j = i; j < gDelayCount; j++)
					gYssDelayList[j] = gYssDelayList[j + 1];

				if (i == 0 && gDelayCount > 0)
				{
					uint64_t curTime = runtime::getUsec();
					if (gYssDelayList[0].endtime > curTime + 1000)
						setDelayTimer(gYssDelayList[0].id, gYssDelayList[0].endtime - curTime - 1000);
					else
						thread::signal(gYssDelayList[0].id);
				}
				break;
			}
		}
#endif

        // 6. Free the allocated stack memory and reset task descriptor fields[cite: 5].
        delete[] gYssThreadList[id].malloc;
        gYssThreadList[id].malloc = nullptr;
        gYssThreadList[id].sp = nullptr;
        gYssThreadList[id].size = 0;
        gNumOfThread--;

        // 8. Ensure the round-robin index stays within valid active thread bounds[cite: 5].
        if (gRoundRobinThreadNum >= gActivatedThreadCount)
            gRoundRobinThreadNum = 0;
    }

    // 9. Invalidate the caller's trigger ID reference[cite: 5, 9].
    id = 0;

    // 10. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

void run(triggerId_t id) __attribute__((optimize("-O1")));
void run(triggerId_t id)
{
	task_t *thread = &gYssThreadList[id];

    if (!isAllocatedThreadId(id))
        return;

    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Reject tasks that are not configured as triggers or are already active[cite: 5].
    if (!thread->trigger || thread->able || thread->waitingForSignal)
    {
        __set_PRIMASK(primask);
        return;
    }

    // 3. Guard against pending queue overflow before enqueueing[cite: 5].
    if (gPendingSignalThreadCount >= MAX_THREAD)
    {
        __set_PRIMASK(primask);
        return;
    }

    // 4. Prevent duplicate enqueueing if the trigger ID is already pending[cite: 5].
    for (uint32_t i = 0; i < gPendingSignalThreadCount; i++)
    {
        if (gPendingSignalThreadList[i] == id)
        {
            __set_PRIMASK(primask);
            return;
        }
    }

    // 5. Reconstruct the initial exception frame on the trigger's pre-allocated stack buffer[cite: 5, 9].
    uint32_t stackSize = thread->size >> 2;
    uint32_t *sp = (uint32_t *)thread->malloc;
    sp += stackSize;

    // Adjust stack boundary for 8-byte alignment compliance[cite: 5].
    if (((uint32_t)sp & 0x7) == 0)
        sp--;

    *sp-- = 0x61000000;                              // xPSR (Thumb state)[cite: 5]
    *sp-- = (uint32_t)thread->entry;      // PC (Trigger entry function)[cite: 5]
    *sp-- = (uint32_t)(void (*)(void))disable;       // LR (Return stub that puts trigger into dormant state)[cite: 4, 5]
    sp -= 4;                                         // Skip hardware-saved R12, R3, R2, R1[cite: 5]
    *sp-- = (uint32_t)thread->var;        // R0 (Parameter passed to trigger)[cite: 5]
    sp -= 8;                                         // Skip callee-saved R11-R4[cite: 5]
    *sp = 0xfffffffd;                                // EXC_RETURN (Return to Thread mode using PSP)[cite: 5, 9]
    thread->sp = sp;

    // 6. Mark the trigger as active and push it into the pending dispatch queue[cite: 5].
    insertToActivatedThreadList(id);
    gPendingSignalThreadList[gPendingSignalThreadCount++] = id;

    // 8. Request a PendSV context switch to dispatch the trigger[cite: 5].
    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;

    // 9. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

/// @brief Disable the currently running trigger, preventing it from running until re-triggered.
/// @details This function is placed in the LR slot of the trigger's exception frame so that
///          it executes automatically when the trigger entry function returns.  It loops
///          forever, each iteration clearing the able flag and yielding so the scheduler
///          selects another thread.  The loop is necessary because a PendSV may not fire
///          immediately if it is invoked from an interrupt context; repeating the disable
///          ensures the trigger never re-enters its entry function before the next run().
void disable(void) __attribute__((optimize("-O1")));
void disable(void)
{
	// Keep this trigger disabled until it is explicitly re-triggered.
	// The loop ensures the able flag stays clear even if a PendSV is delayed
	// (e.g., when run() is called from an interrupt context).
	while(1)
	{
		__disable_irq();
		removeFromActivatedThreadList(gCurrentThreadNum);
		__enable_irq();
		thread::yield();
	}
}

void protect(void) __attribute__((optimize("-O1")));
void protect(void)
{
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Atomically increment the protection count for the current trigger task[cite: 5, 9].
    gYssThreadList[gCurrentThreadNum].lockCnt++;

    // 3. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

void protect(triggerId_t id) __attribute__((optimize("-O1")));
void protect(triggerId_t id)
{
    if (!isAllocatedThreadId(id))
        return;

    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Increment the protection count for the designated trigger[cite: 9].
    gYssThreadList[id].lockCnt++;

    // 3. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

void unprotect(void) __attribute__((optimize("-O1")));
void unprotect(void)
{
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Decrement protection count and check if it reached zero[cite: 5, 9].
    if (gYssThreadList[gCurrentThreadNum].lockCnt > 0)
        gYssThreadList[gCurrentThreadNum].lockCnt--;

    bool isUnprotected = (gYssThreadList[gCurrentThreadNum].lockCnt == 0);

    // 3. Restore the previous interrupt state.
    __set_PRIMASK(primask);

    // 4. Yield CPU if protection is fully released to allow pending trigger::remove() calls to execute[cite: 5, 9].
    if (isUnprotected)
        thread::yield();
}

void unprotect(triggerId_t id) __attribute__((optimize("-O1")));
void unprotect(triggerId_t id)
{
    if (!isAllocatedThreadId(id))
        return;

    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __get_PRIMASK();
    __disable_irq();

    // 2. Decrement the protection count for the designated trigger[cite: 9].
    if (gYssThreadList[id].lockCnt > 0)
        gYssThreadList[id].lockCnt--;

    // 3. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}
}

// System exception handlers used by the scheduler for context switching.
extern "C"
{
	/// @brief SysTick ISR — requests a PendSV context switch on every tick.
	/// @details SysTick fires at the configured scheduler tick rate.  Instead of
	///          performing the context switch directly (which would increase ISR latency
	///          for other handlers), it simply pends PendSV.  Because PendSV runs at the
	///          lowest interrupt priority, the actual register save/restore occurs only
	///          after all other pending ISRs have completed.
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

uint32_t yss_switchContext(uint32_t currentSp) __attribute__((optimize("-O0")));
uint32_t yss_switchContext(uint32_t currentSp)
{
    // 1. Save the updated PSP of the interrupted thread into its task descriptor.
    gYssThreadList[gCurrentThreadNum].sp = (uint32_t *)currentSp;

	__disable_irq();
    // 2. Select the next runnable thread based on priority.
    if (gPendingSignalThreadCount > 0)
    {
        // Highest priority: Dispatched pending signals/triggers.
        gPendingSignalThreadCount--;
        gCurrentThreadNum = gPendingSignalThreadList[gPendingSignalThreadCount];
        gPendingSignalThreadList[gPendingSignalThreadCount] = 0;
    }
    else
    {
        // Standard round-robin selection among active threads[cite: 5].
        gRoundRobinThreadNum++;
        if ((uint32_t)gRoundRobinThreadNum >= gActivatedThreadCount)
            gRoundRobinThreadNum = 0;

        gCurrentThreadNum = gActivatedThreadList[gRoundRobinThreadNum];
    }
	__enable_irq();

    // 3. Reset SysTick Current Value Register to 0 so the new thread gets a full time-slice[cite: 5].
    SysTick->VAL = 0;

    // 4. Return the next thread's saved top-of-stack pointer (passed back in R0)[cite: 5].
    return (uint32_t)gYssThreadList[gCurrentThreadNum].sp;
}

void PendSV_Handler(void) __attribute__((naked)) __attribute__((optimize("-O1")));
void PendSV_Handler(void)
{
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
    __asm volatile(
        // ----------------------------------------------------------------------
        // 1. SAVE CURRENT THREAD CONTEXT TO PSP
        // ----------------------------------------------------------------------
        "mrs     r0, psp                 \n" // R0 = Current Process Stack Pointer (PSP)[cite: 5]

#if defined(__FPU_PRESENT) && __FPU_USED == 1
        // Test EXC_RETURN bit 4: 0 = FPU frame active (extended), 1 = Standard frame[cite: 5]
        "tst     lr, #0x10               \n"
        "it      eq                      \n"
        "vstmdbeq r0!, {s16-s31}         \n" // Save callee-saved FPU registers if used[cite: 5]
#endif
        "mov     r3, lr                  \n" // Preserve EXC_RETURN in R3[cite: 5]
        "stmdb   r0!, {r3-r11}           \n" // Push EXC_RETURN (R3) and callee registers R4-R11[cite: 5]

        // ----------------------------------------------------------------------
        // 2. DISPATCH SCHEDULER (MSP Context)
        // ----------------------------------------------------------------------
        "bl      yss_switchContext       \n" // R0 contains currentSp, returns nextSp in R0[cite: 5]

        // ----------------------------------------------------------------------
        // 3. RESTORE NEXT THREAD CONTEXT FROM PSP (R0)
        // ----------------------------------------------------------------------
        "ldmia   r0!, {r3-r11}           \n" // Pop EXC_RETURN (into R3) and callee registers R4-R11[cite: 5]
        "mov     lr, r3                  \n" // Restore EXC_RETURN into LR[cite: 5]

#if defined(__FPU_PRESENT) && __FPU_USED == 1
        // Test restored EXC_RETURN bit 4: restore FPU registers if next thread used FPU[cite: 5]
        "tst     lr, #0x10               \n"
        "it      eq                      \n"
        "vldmiaeq r0!, {s16-s31}         \n" // Restore callee-saved FPU registers[cite: 5]
#endif
        "msr     psp, r0                 \n" // Update PSP with the new stack pointer[cite: 5]
        "bx      lr                      \n" // Exception return using restored EXC_RETURN[cite: 5]
    );

#elif defined(YSS__CORE_CM0_H_GENERIC)
    // Cortex-M0 context save/restore using low registers[cite: 5]
    __asm volatile(
        "mrs     r0, psp                 \n"
        "mov     r3, lr                  \n"
        "sub     r0, r0, #36             \n"
        "stm     r0!, {r3-r7}            \n"
        "mov     r3, r8                  \n"
        "mov     r4, r9                  \n"
        "mov     r5, r10                 \n"
        "mov     r6, r11                 \n"
        "stm     r0!, {r3-r6}            \n"
        "sub     r0, r0, #36             \n"

        "bl      yss_switchContext       \n"

        "add     r0, r0, #20             \n"
        "ldm     r0!, {r3-r6}            \n"
        "mov     r8, r3                  \n"
        "mov     r9, r4                  \n"
        "mov     r10, r5                 \n"
        "mov     r11, r6                 \n"
        "sub     r0, r0, #36             \n"
        "ldm     r0!, {r3-r7}            \n"
        "mov     lr, r3                  \n"
        "add     r0, r0, #16             \n"
        "msr     psp, r0                 \n"
        "bx      lr                      \n"
    );
#endif
#endif
}
}

#elif !defined(YSS__MULTI_CORE)

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

