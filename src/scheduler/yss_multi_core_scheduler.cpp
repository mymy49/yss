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

#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE) && defined(YSS__MULTI_CORE)

#include <config.h>
#include <util/runtime.h>
#include <yss/hmalloc.h>
#include <yss/scheduler.h>
#include <yss/instance.h>
#include <drv/Timer.h>
#include <string.h>

//#error "gMutex와 __disable_irq()와 __get_PRIMASK()의 교통정리가 필요"
//#error "gMutex가 대부분 누락되어 추가 필요"


#pragma GCC optimize("O1")

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
// In multi-core mode two idle threads occupy slots 0 and 1 (one per core).
volatile task_t gYssThreadList[MAX_THREAD] = 
{
	{0, 0, 0, 0, 0, 0, 0, true, true, false, false, false},
	{0, 0, 0, 0, 0, 1, 0, true, true, false, false, false}
};

delay_t gYssDelayList[MAX_THREAD];

static volatile threadId_t gRoundRobinThreadNum;         // Round robin scheduler index shared between cores
static volatile threadId_t gHoldingThreadNum = -1;        // Thread currently holding execution
static volatile threadId_t gPendingSignalThreadList[MAX_THREAD];
static volatile uint32_t gPendingSignalThreadCount;       // Pending signal/trigger queue count
static volatile uint32_t gActivatedThreadCount = YSS__CORE_COUNT;
static volatile int32_t gDelayCount;

void setDelayTimer(threadId_t id, uint64_t sleepTime);

#if YSS__CORE_COUNT == 2
// Per-core currently-executing thread index.  Core 0 starts on slot 0, Core 1 on slot 1.
static volatile int32_t gNumOfThread = 2;                // Number of active thread slots (2 idle threads pre-allocated)
static volatile threadId_t gActivatedThreadList[MAX_THREAD] = {0, 1};
static volatile threadId_t gCurrentThreadNum[YSS__CORE_COUNT] = {0, 1};
#endif

/// @brief Temporarily disable SysTick to prevent an interrupt-driven context switch
///        while scheduler state is being modified.
inline void lockContextSwitch(void)
{
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

/// @brief Re-enable SysTick after a protected scheduler operation completes.
inline void unlockContextSwitch(void)
{
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

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

threadId_t add(void (*func)(void *), void *var, int32_t  stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock)
{
	volatile task_t *thread;

    if (!func)
        return -1;

    // 1. Align stack size to an 8-byte boundary and enforce the minimum size requirement[cite: 5].
    stackSize = (stackSize + 7) & ~0x7;
    if (stackSize < MIN_STACK_SIZE)
        return -1;

    // 4. Validate slot capacity and locate an available scheduler slot[cite: 5].
    if (gNumOfThread >= MAX_THREAD)
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
    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();
    uint32_t primask = __get_PRIMASK();

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
		semaphore::unlockSchedule();
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
	semaphore::unlockSchedule();
	__set_PRIMASK(primask);

    return id;
}

threadId_t add(void (*func)(void *var), void *var, int32_t stackSize, bool signalLock)
{
	return add(func, var, stackSize, 0, 0, 0, 0, 0, signalLock);
}

threadId_t add(void (*func)(void), int32_t stackSize, bool signalLock)
{
	return add((void (*)(void *))func, 0, stackSize, signalLock);
}

threadId_t add(void (*func)(void), int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock)
{
	return add((void (*)(void *))func, 0, stackSize, r8, r9, r10, r11, r12, signalLock);
}

void remove(threadId_t &id)
{
	if (!isAllocatedThreadId(id))
		return;

	// 1. A thread cannot remove itself via remove() (use terminateThread() instead), and invalid IDs are rejected[cite: 5].
#if YSS__CORE_COUNT == 2
	if (id == gCurrentThreadNum[0] || id == gCurrentThreadNum[1] || id <= 0)
		return;
#endif

	// 2. Wait until the thread's protection count drops to zero before proceeding[cite: 5, 9].
	while (gYssThreadList[id].lockCnt > 0)
	{
		yield();
	}

	// 3. Enter critical section by capturing the PRIMASK state and disabling interrupts.
	// Acquire the inter-core semaphore and record the calling core ID.
	uint32_t primask = __get_PRIMASK();
	__disable_irq();
	uint32_t cid = semaphore::lockSchedule();

	if(gYssThreadList[id].allocated)
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
	semaphore::unlockSchedule();
	__set_PRIMASK(primask);
}

threadId_t getCurrentThreadId(void)
{
	return gCurrentThreadNum[semaphore::getId()];
}

void protect(void)
{
	// Identify the calling core to index into the per-core current-thread array.
    uint32_t primask = __get_PRIMASK();
	uint32_t cid = semaphore::getId();
	__disable_irq();

	gYssThreadList[gCurrentThreadNum[cid]].lockCnt++;

    __set_PRIMASK(primask);
}

void unprotect(void)
{
	// Identify the calling core to index into the per-core current-thread array.
	uint32_t cid = semaphore::getId();
    uint32_t primask = __get_PRIMASK();
	__disable_irq();

    if (gYssThreadList[gCurrentThreadNum[cid]].lockCnt > 0)
        gYssThreadList[gCurrentThreadNum[cid]].lockCnt--;

    bool isUnprotected = (gYssThreadList[gCurrentThreadNum[cid]].lockCnt == 0);

	semaphore::unlockSchedule();
    __set_PRIMASK(primask);

    if (isUnprotected)
        yield();
}

/// @brief Terminate the current thread and switch to the next runnable thread (multi-core variant).
/// @details Called automatically when the thread's entry function returns (placed in LR slot of
///          the initial exception frame).  Acquires both the heap lock and the inter-core
///          scheduling semaphore to safely free the stack and update the shared task list,
///          then yields to trigger a PendSV switch away from this freed thread.
void terminateThread(void)
{
	// Lock the inter-core scheduling semaphore and record the calling core ID.
	__disable_irq();
	uint32_t cid = semaphore::lockSchedule();

	// Release the current thread's stack before requesting a context switch.
	// This is intentional: PendSV must perform the final context save using the
	// current PSP before switching to another thread. yss guarantees that this
	// stack cannot be reallocated during this transition, so the memory remains
	// available until PendSV completes the context save.
	delete[] gYssThreadList[gCurrentThreadNum[cid]].malloc;
	gYssThreadList[gCurrentThreadNum[cid]].signalLock = true;
	removeFromActivatedThreadList(gCurrentThreadNum[cid]);
	gYssThreadList[gCurrentThreadNum[cid]].allocated = false;
	gNumOfThread--;

	semaphore::unlockSchedule();
	__enable_irq();

	// Yield to let PendSV select the next runnable thread.
	thread::yield();
}

void delay(uint32_t delayTime)
{
	delayUs(delayTime * 1000);
}

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

void waitForSignal(void)
{
	uint32_t cid = semaphore::lockSchedule();

    removeFromActivatedThreadList(gCurrentThreadNum[cid]);
	gYssThreadList[gCurrentThreadNum[cid]].waitingForSignal = true;

	if(gActivatedThreadCount == 0)
	{
		disableSystickInterrupt();
		__enable_irq();
		semaphore::unlockSchedule();
		__WFI();
	}
	else	
		__enable_irq();

    yield();
}

void waitForSignal(uint32_t timeout)
{
	if(timeout == 0)
		return;

	uint32_t primask = __get_PRIMASK();
	uint32_t cid = semaphore::lockSchedule();
	__disable_irq();

	uint64_t curTime = runtime::getUsec();
	uint64_t endTime = curTime + timeout * 1000;

	if(gDelayCount < MAX_THREAD)
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
		gYssDelayList[index].id = gCurrentThreadNum[cid];

		gDelayCount++;

		if(index == 0)
		{
			setDelayTimer(gCurrentThreadNum[cid], endTime - curTime - 500);
		}
		
		semaphore::unlockSchedule();
		waitForSignal();

		__disable_irq();

		for(index = 0; index < gDelayCount; index++)
		{
			if(gCurrentThreadNum[cid] == gYssDelayList[index].id)
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
	
	semaphore::unlockSchedule();
	__set_PRIMASK(primask);
}

void signal(threadId_t id)
{
	volatile task_t *thread = &gYssThreadList[id];
    uint32_t primask = __get_PRIMASK();

	uint32_t cid = semaphore::lockSchedule();
    __disable_irq();

	switch(cid)
	{
#if YSS__CORE_COUNT == 2
	case 0 :
	    if (!isAllocatedThreadId(id) || id == gCurrentThreadNum[1])
			goto error_handler;
		break;
	case 1 :
	    if (!isAllocatedThreadId(id) || id == gCurrentThreadNum[0])
			goto error_handler;
		break;
#endif
	}


    // 2. Reject invalid IDs or threads that explicitly disallow signaling[cite: 5, 9].
    if (id < 0 || thread->signalLock || thread->waitingForSignal == false)
		goto error_handler;

    // 3. Guard against pending dispatch queue overflow[cite: 5].
    if (gPendingSignalThreadCount >= MAX_THREAD)
		goto error_handler;

	if(thread->able)
		goto error_handler;
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

error_handler :
	semaphore::unlockSchedule();

    // 9. Restore the previous interrupt state.
    __set_PRIMASK(primask);
}

void yield(void)
{
    uint32_t primask = __get_PRIMASK();
	
	__enable_irq();
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC)
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
#endif

	__set_PRIMASK(primask);
}
}

namespace trigger
{
void disable(void);

triggerId_t add(void (*func)(void *), void *var, int32_t stackSize)
{
	task_t *thread;

    if (!func)
        return -1;

    // 1. Align stack size to an 8-byte boundary and enforce minimum size[cite: 5].
    stackSize = (stackSize + 7) & ~0x7;
    if (stackSize < MIN_STACK_SIZE)
        return -1;

    // 4. Validate slot capacity and locate an available scheduler slot[cite: 5].
    if (gNumOfThread >= MAX_THREAD)
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
	uint32_t cid = semaphore::lockSchedule();
    __disable_irq();








	int32_t i;

	// Reject the request if the maximum number of scheduler slots is reached.
	if (gNumOfThread >= MAX_THREAD)
	{
		semaphore::unlockSchedule();
		return -1;
	}

	// Scan for an unallocated slot starting from index 1.
	for (i = 1; i < MAX_THREAD; i++)
	{
		if (!gYssThreadList[i].allocated)
		{
			gYssThreadList[i].allocated = true;
			break;
		}
	}

	// Allocate stack space; the trigger builds its frame each time run() is called.
	gYssThreadList[i].malloc = new int32_t [stackSize/sizeof(int32_t )];

	if (!gYssThreadList[i].malloc)
	{
		// Stack allocation failed; release the slot and unlock before returning.
		gYssThreadList[i].allocated = false;
		semaphore::unlockSchedule();
		return -1;
	}
	gYssThreadList[i].size = stackSize;

#if(FILL_THREAD_STACK)
	// Pre-fill the stack region for easier high-water mark inspection.
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

	// Store trigger metadata; able is false until trigger::run() is called.
	gYssThreadList[i].var = var;
	gYssThreadList[i].lockCnt = 0;
	gYssThreadList[i].trigger = true;   // Distinguish this slot as a trigger, not a regular thread.
	gYssThreadList[i].entry = func;
	gYssThreadList[i].able = false;     // Trigger is dormant until explicitly activated.
	gYssThreadList[i].signalLock = false;

	gNumOfThread++;

	semaphore::unlockSchedule();
	return i;
}

triggerId_t add(void (*func)(void), int32_t  stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

void remove(triggerId_t &id)
{
	// Acquire the inter-core scheduling semaphore and record the calling core ID.
	uint32_t cid = semaphore::lockSchedule();
	// Stop the SysTick-driven context switch to safely modify the task list.
	lockContextSwitch();
	if(gYssThreadList[id].lockCnt > 0)
	{
		// Unlock and busy-wait until the protection count drops to zero.
		unlockContextSwitch();
		semaphore::unlockSchedule();
		while (gYssThreadList[id].lockCnt > 0)
			thread::yield();
		// Re-acquire both locks after the busy-wait.
		cid = semaphore::lockSchedule();
		lockContextSwitch();
	}

	// Do not remove the currently executing trigger on this core or an invalid slot.
	if (id != gCurrentThreadNum[cid] && id > 0)
	{
		if (gYssThreadList[id].allocated == true)
		{
			// Mark the slot as free and release its stack memory.
			removeFromActivatedThreadList(id);
			gYssThreadList[id].allocated = false;
			delete[] gYssThreadList[id].malloc;
			gYssThreadList[id].sp = 0;
			gYssThreadList[id].size = 0;
			gNumOfThread--;
		}
	}

	// Clear the holding slot if it referenced this trigger.
	if(gCurrentThreadNum[cid] == gHoldingThreadNum)
		gHoldingThreadNum = -1;
	
	// Notify the caller that the trigger has been removed.
	id = 0;
	unlockContextSwitch();
	semaphore::unlockSchedule();
}

void run(triggerId_t id)
{
	uint32_t buf, *sp;
	// Acquire the inter-core scheduling semaphore and record the calling core ID.
	uint32_t cid = semaphore::lockSchedule();

	__disable_irq();

	// Reject non-trigger tasks or triggers that are already running (able == true).
	if(!gYssThreadList[id].trigger || gYssThreadList[id].able)
	{
		// Reject non-trigger tasks or triggers that are already active.
		__enable_irq();	
		semaphore::unlockSchedule();
		return;
	}

	// Avoid enqueueing the same trigger twice by scanning the pending list.
	for(buf=0;buf<gPendingSignalThreadCount;buf++)
	{
		if(gPendingSignalThreadList[buf] == id)
		{
			// Trigger is already pending; do not enqueue again.
			__enable_irq();	 
			semaphore::unlockSchedule();
			return;
		}
	}
	
	// Convert byte size to word count for stack pointer arithmetic.
	buf = gYssThreadList[id].size >> 2;
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__)
	// Re-initialise the exception frame at the top of the trigger's stack buffer.
	sp = (uint32_t *)((uint32_t )gYssThreadList[id].malloc & ~0x7) - 1;
	sp += buf;
	*sp-- = 0x61000000;								// xPSR: Thumb bit set
	*sp-- = (uint32_t )gYssThreadList[id].entry;	// PC: trigger entry function
	*sp-- = (uint32_t )(void (*)(void))disable;		// LR: called when entry() returns to self-disable
	sp -= 4;										// Skip R1, R2, R3, R12
	*sp-- = (uint32_t )gYssThreadList[id].var;		// R0: trigger argument
	sp -= 24;										// Skip S16-S31 FPU register slots
	*sp = 0xfffffffd;								// EXC_RETURN: Thread mode, PSP
	gYssThreadList[id].sp = sp;
#else
	// Non-FPU variant of the exception frame construction.
	sp = (uint32_t *)((int32_t )gYssThreadList[id].malloc & ~0x7) - 1;
	sp += buf;
	*sp-- = 0x61000000;								// xPSR
	*sp-- = (uint32_t )gYssThreadList[id].entry;	// PC
	*sp-- = (uint32_t )(void (*)(void))disable;		// LR
	sp -= 4;										// Skip R1-R3, R12
	*sp-- = (uint32_t )gYssThreadList[id].var;		// R0
	sp -= 8;										// Skip R4-R11
	*sp = 0xfffffffd;								// EXC_RETURN
	gYssThreadList[id].sp = sp;
#endif
	// Mark the trigger as runnable and push it into the pending queue.
	insertToActivatedThreadList(id);
	gPendingSignalThreadList[gPendingSignalThreadCount++] = id;
	// Record the calling thread as the holder so PendSV returns to it after the trigger.
	if(gHoldingThreadNum < 0)
		gHoldingThreadNum = gCurrentThreadNum[cid];
	// Request a PendSV context switch to dispatch the trigger at the next safe point.
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	__enable_irq();	 
		semaphore::unlockSchedule();
}

/// @brief Disable the currently running trigger (multi-core variant).
/// @details Placed in the LR slot of the trigger's exception frame so it executes when
///          the trigger entry function returns.  Acquires the inter-core semaphore each
///          iteration to safely clear the able flag, then yields.  The infinite loop is
///          required because a PendSV may not fire immediately.
void disable(void)
{
	// Keep this trigger disabled until it is explicitly re-triggered.
	// The loop ensures the able flag stays clear even if a PendSV is delayed.
	while(1)
	{
		// Re-acquire the semaphore each iteration to safely read the current thread index.
		uint32_t cid = semaphore::lockSchedule();

		__disable_irq();
		removeFromActivatedThreadList(gCurrentThreadNum[cid]);
		__enable_irq();
		semaphore::unlockSchedule();
		thread::yield();
	}
}

void protect(void)
{
	// Identify the calling core to index into the per-core current-thread array.
	uint32_t cid = semaphore::getId();
	__disable_irq();
	gYssThreadList[gCurrentThreadNum[cid]].lockCnt++;
	__enable_irq();
}

void unprotect(void)
{
	// Identify the calling core to index into the per-core current-thread array.
	uint32_t cid = semaphore::getId();
	__disable_irq();
	gYssThreadList[gCurrentThreadNum[cid]].lockCnt--;
	__enable_irq();

	// If fully unprotected, yield to let any waiting remove() call proceed.
	if (gYssThreadList[gCurrentThreadNum[cid]].lockCnt == 0)
	{
		thread::yield();
	}
}
}

// System exception handlers used by the scheduler for context switching.
extern "C"
{
	/// @brief SysTick ISR — requests a PendSV context switch on every tick (multi-core variant).
	/// @details Identical to the single-core SysTick_Handler: simply pends PendSV to defer
	///          the actual register save/restore until all higher-priority ISRs complete.
	void SysTick_Handler(void)
	{
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC)
		// Do not disable interrupts here to reduce latency for higher-priority interrupts.
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
#endif
#endif
	}

uint32_t yss_switchContext(uint32_t currentSp) __attribute__((optimize("-O2")));
uint32_t yss_switchContext(uint32_t currentSp)
{
	uint32_t cid = semaphore::lockSchedule();

    // 1. Save the updated PSP of the interrupted thread into its task descriptor.
    gYssThreadList[gCurrentThreadNum[cid]].sp = (uint32_t *)currentSp;

    // 2. Select the next runnable thread based on priority.
    if (gPendingSignalThreadCount > 0)
    {
        // Highest priority: Dispatched pending signals/triggers.
        gPendingSignalThreadCount--;
        gCurrentThreadNum[cid] = gPendingSignalThreadList[gPendingSignalThreadCount];
        gPendingSignalThreadList[gPendingSignalThreadCount] = 0;
    }
    else if (gHoldingThreadNum >= 0)
    {
        // Resume previous caller thread after trigger/signal execution.
        gCurrentThreadNum[cid] = gHoldingThreadNum;
        gHoldingThreadNum = -1;
    }
    else
    {
		gCurrentThreadNum[cid] = 0xFF;
        // Standard round-robin selection among active threads[cite: 5].
		do
		{
	        gRoundRobinThreadNum++;
	        if (gRoundRobinThreadNum >= gActivatedThreadCount)
	            gRoundRobinThreadNum = 0;
		}while (gActivatedThreadList[gRoundRobinThreadNum] == gCurrentThreadNum[0] || gActivatedThreadList[gRoundRobinThreadNum] == gCurrentThreadNum[1]);

        gCurrentThreadNum[cid] = gActivatedThreadList[gRoundRobinThreadNum];
    }

    // 3. Reset SysTick Current Value Register to 0 so the new thread gets a full time-slice[cite: 5].
    SysTick->VAL = 0;

    // 4. Return the next thread's saved top-of-stack pointer (passed back in R0)[cite: 5].

	semaphore::unlockSchedule();

    return (uint32_t)gYssThreadList[gCurrentThreadNum[cid]].sp;
}

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

#endif

