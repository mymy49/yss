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
#include <yss/hmalloc.h>
#include <yss/scheduler.h>
#include <yss/instance.h>
#include <drv/Timer.h>
#include <string.h>

#pragma GCC optimize("O1")

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
#if defined(__FPU_PRESENT) && __FPU_USED == 1
#define MIN_STACK_SIZE		512
#else
#define MIN_STACK_SIZE		256
#endif
#elif defined(YSS__CORE_CA35_H_GENERIC)
#define MIN_STACK_SIZE		2048
#endif

// Pre-allocation depth used for scheduler stack bookkeeping.
#define PREOCCUPY_DEPTH		(MAX_THREAD * 2)

// Scheduler task descriptor.
typedef struct
{
	uintptr_t *malloc;          // Allocated stack memory
	uintptr_t *sp;             // Current stack pointer for context switching
	size_t  size;           // Stack size in bytes
	void (*entry)(void *);    // Entry function for the thread
	void *var;                // Parameter passed to the entry function
	threadId_t indexNumber;
	int16_t lockCnt;          // Nested protection count
	bool able;                // Thread is runnable
	bool allocated;           // This slot is in use
	bool trigger;             // Trigger thread flag
	bool signalLock;          // Prevent thread from being signaled
	bool waitingForSignal;
	bool waitingForSignalPendingFlag;
}volatile task_t;

typedef struct
{
	uint64_t endtime;
	threadId_t id;
}delay_t;

// Global task list and scheduler metadata.
volatile task_t gYssThreadList[MAX_THREAD] = 
{
	{0, 0, 0, 0, 0, 0, 0, true, true, false, false, false},
#if YSS__CORE_COUNT >= 2
	{0, 0, 0, 0, 0, 0, 0, true, true, false, false, false},
#endif
#if YSS__CORE_COUNT >= 3
	{0, 0, 0, 0, 0, 0, 0, true, true, false, false, false},
#endif
#if YSS__CORE_COUNT >= 4
	{0, 0, 0, 0, 0, 0, 0, true, true, false, false, false},
#endif
};

volatile delay_t gYssDelayList[MAX_THREAD];

static volatile int32_t gNumOfThread = YSS__CORE_COUNT;                // Number of active thread slots
static volatile threadId_t gRoundRobinThreadNum;         // Round robin scheduler index
static volatile threadId_t gPendingSignalThreadList[MAX_THREAD];
static volatile uint32_t gPendingSignalThreadCount;       // Pending signal/trigger queue count
static volatile uint32_t gActivatedThreadCount = YSS__CORE_COUNT;
static volatile int32_t gDelayCount;

static volatile threadId_t gActivatedThreadList[MAX_THREAD] = 
{
	0,
#if YSS__CORE_COUNT >= 2
	1,
#endif
#if YSS__CORE_COUNT >= 3
	2,
#endif
#if YSS__CORE_COUNT >= 4
	3,
#endif
};

static volatile threadId_t gCurrentThreadNum[YSS__CORE_COUNT] = 
{
	0,
#if YSS__CORE_COUNT >= 2
	1,
#endif
#if YSS__CORE_COUNT >= 3
	2,
#endif
#if YSS__CORE_COUNT >= 4
	3,
#endif
};

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

inline void disableSchedulerTimer(void)
{
#if defined(YSS__CORE_CA35_H_GENERIC)
	raw_write_cntps_ctl_el1(0);
#elif defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC)
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
#endif
}

inline void enableSchedulerTimer(void)
{
#if defined(YSS__CORE_CA35_H_GENERIC)
	raw_write_cntps_ctl_el1(1);
#elif defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC)
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
#endif
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

/// @brief Put the current thread to sleep until it is signaled.
/// @warning Must be called with interrupts DISABLED and the scheduler semaphore locked.
/// @details Removes the current thread from the active runnable list and releases the
///          scheduler semaphore. When no runnable thread remains, WFI is executed and
///          interrupts are re-enabled so the wake-up ISR can run; otherwise yield() is
///          called to switch to another runnable thread.
/// @param cid Core ID of the calling processor.
static inline void sleep(uint32_t cid)
{
    removeFromActivatedThreadList(gCurrentThreadNum[cid]);
	gYssThreadList[gCurrentThreadNum[cid]].waitingForSignal = true;

	if(gActivatedThreadCount == 0)
	{
		semaphore::unlockSchedule();
		__WFI();
		__enable_irq();
	}
	else
	{
		semaphore::unlockSchedule();
		thread::yield();
	}
}

#if YSS__CORE_COUNT == 1
namespace semaphore
{
uint32_t getId()
{
	return 0;
}

uint32_t lockSchedule()
{
	return 0;
}

void unlockSchedule()
{

}
}
#endif

namespace thread
{
void terminateThread(void);

threadId_t add(void (*func)(void *), void *var, int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock)
{
	volatile task_t *thread;
    int32_t id = -1;

    if (!func)
        return -1;

    // 1. Align stack size to an 8-byte (Cortex-M) or 16-byte (Cortex-A35) boundary and enforce minimum size.
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    stackSize = (stackSize + 7) & ~0x7;
#elif defined(YSS__CORE_CA35_H_GENERIC)
    stackSize = (stackSize + 15) & ~0xF;
#endif

    if (stackSize < MIN_STACK_SIZE)
        return -1;

    // 2. Enter critical section by capturing interrupt status, disabling interrupts, and acquiring the scheduler lock.
    uint32_t primask = __getCoreInterruptStatus();
	uintptr_t *stackMem;
	uintptr_t wordCount;
	uintptr_t *sp;

    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();

    // 3. Validate slot capacity and allocate stack buffer.
    if (gNumOfThread >= MAX_THREAD)
		 goto error_handler;

	stackMem = new uintptr_t[stackSize / sizeof(uintptr_t)];
    if (!stackMem)
    {
#if defined(THREAD_MONITOR)
        debug_printf("Thread creation failed!! Stack allocation failed.");
#endif
		 goto error_handler;
    }

#if (FILL_THREAD_STACK)
    // Pre-fill stack buffer with watermark pattern for high-water analysis.
    memset(stackMem, 0xAA, stackSize);
#endif

    // 4. Locate an available scheduler slot.
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
        delete[] stackMem;
		goto error_handler;
    }

    // 5. Construct the initial exception frame on the allocated stack.
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    wordCount = stackSize >> 2;
#elif defined(YSS__CORE_CA35_H_GENERIC)
    wordCount = stackSize >> 3;
#endif
    sp = (uintptr_t *)stackMem + wordCount;

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    // Ensure 8-byte stack alignment at exception entry point.
    if (((uintptr_t)sp & 0x7) == 0)
        sp--;

    *sp-- = 0x61000000;                                     // xPSR (Thumb state)
    *sp-- = (uintptr_t)func;                                 // PC (Thread entry function)
    *sp-- = (uintptr_t)(void (*)(void))terminateThread;      // LR (Return stub upon thread completion)
    *sp-- = (uintptr_t)r12;                                  // R12
    sp -= 3;                                                // Skip R3, R2, R1
    *sp-- = (uintptr_t)var;                                  // R0 (Parameter)
    *sp-- = (uintptr_t)r11;                                  // R11
    *sp-- = (uintptr_t)r10;                                  // R10
    *sp-- = (uintptr_t)r9;                                   // R9
    *sp-- = (uintptr_t)r8;                                   // R8
    sp -= 4;                                                // Skip R7-R4
    *sp = 0xfffffffd;                                       // EXC_RETURN (Thread mode using PSP)
#elif defined(YSS__CORE_CA35_H_GENERIC)
    if ((uintptr_t)sp & 0xF)
        sp--;
	
	sp -= 100;
	sp[98] = (uintptr_t )var;                             // X0 (First argument passed to the thread entry function)
	sp[69] = 0;                                           // Padding (8-byte alignment slot left by 'str x30, [x0, #-16]!')
	sp[68] = (uintptr_t)(void (*)(void))terminateThread;  // X30 (LR - Link Register)
	sp[67] = (uint64_t)func;                              // ELR_EL1 (Thread entry point PC)
	sp[66] = 0x04;                                        // SPSR_EL1 (PSTATE: EL1t mode with IRQ/FIQ unmasked)
	sp[1] = 0;                                            // FPCR (Floating-point Control Register)
	sp[0] = 0;                                            // FPSR (Floating-point Status Register)
#endif

    // 6. Initialize Task descriptor metadata.
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

    // 7. Insert the new thread into the active runnable list and increment count.
    insertToActivatedThreadList(id);
    gNumOfThread++;

error_handler :
    // 8. Release the scheduler lock and restore the previous interrupt state.
	semaphore::unlockSchedule();
    __setCoreInterruptStatus(primask);

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
	// 1. Enter critical section by capturing interrupt status, disabling interrupts, and acquiring the scheduler lock.
	uint32_t primask = __getCoreInterruptStatus();
	__disable_irq();
	uint32_t cid = semaphore::lockSchedule();

	if (!isAllocatedThreadId(id))
		goto error_handler;

	// 2. A thread cannot remove itself via remove() (use terminateThread() instead), and invalid IDs are rejected.
	if (id == gCurrentThreadNum[0]
#if YSS__CORE_COUNT >= 2
		|| id == gCurrentThreadNum[1]
#endif
#if YSS__CORE_COUNT >= 3
		|| id == gCurrentThreadNum[2]
#endif
#if YSS__CORE_COUNT >= 4
		|| id == gCurrentThreadNum[3]
#endif
		|| id <= 0)
	{
		goto error_handler;
	}

	// 3. Wait until the thread's protection count drops to zero before proceeding.
	while (gYssThreadList[id].lockCnt > 0)
	{
		semaphore::unlockSchedule();
		yield();
		cid = semaphore::lockSchedule();
	}

	if (gYssThreadList[id].allocated)
	{
		// 4. Remove from active scheduling and mark as inactive.
		removeFromActivatedThreadList(id);
		gYssThreadList[id].allocated = false;
		gYssThreadList[id].signalLock = true;

		// 5. Purge any pending signal entries for this thread to prevent Use-After-Free in PendSV.
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
		// Purge any remaining entry in the delay queue and reschedule the timer if needed.
		for (uint32_t i = 0; i < gDelayCount; i++)
		{
			if (gYssDelayList[i].id == id)
			{
				gDelayCount--;
				for (uint32_t j = i; j < gDelayCount; j++)
				{
					gYssDelayList[j].endtime = gYssDelayList[j + 1].endtime;
					gYssDelayList[j].id = gYssDelayList[j + 1].id;
				}

				if (i == 0 && gDelayCount > 0)
				{
					uint64_t curTime = runtime::getUsec();
					if (gYssDelayList[0].endtime > curTime + 1000)
						setDelayTimer(gYssDelayList[0].id, gYssDelayList[0].endtime - curTime - 1000);
					else
						signal(gYssDelayList[0].id, false);
				}
				break;
			}
		}
#endif

		// 6. Free the allocated stack memory and reset task descriptor fields.
		delete[] gYssThreadList[id].malloc;
		gYssThreadList[id].malloc = nullptr;
		gYssThreadList[id].sp = nullptr;
		gYssThreadList[id].size = 0;
		gNumOfThread--;
	}

	// 7. Invalidate the caller's thread ID reference.
	id = 0;

	// 8. Release the scheduler lock and restore the previous interrupt state.
error_handler :
	semaphore::unlockSchedule();
	__setCoreInterruptStatus(primask);
}

threadId_t getCurrentThreadId(void)
{
	return gCurrentThreadNum[semaphore::getId()];
}

void protect(void)
{
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __getCoreInterruptStatus();
    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();

    // 2. Atomically increment the protection count for the currently running thread.
    gYssThreadList[gCurrentThreadNum[cid]].lockCnt++;

    // 3. Release the scheduler lock and restore the previous interrupt state.
	semaphore::unlockSchedule();
    __setCoreInterruptStatus(primask);
}

void unprotect(void)
{
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __getCoreInterruptStatus();
    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();

    // 2. Atomically decrement the protection count, preventing negative underflow.
    if (gYssThreadList[gCurrentThreadNum[cid]].lockCnt > 0)
        gYssThreadList[gCurrentThreadNum[cid]].lockCnt--;

    bool isUnprotected = (gYssThreadList[gCurrentThreadNum[cid]].lockCnt == 0);

    // 3. Release the scheduler lock and restore the previous interrupt state.
	semaphore::unlockSchedule();
    __setCoreInterruptStatus(primask);

    // 4. If fully unprotected, yield to let any waiting remove() call proceed.
    if (isUnprotected)
        yield();
}

/// @brief Terminate the current thread and switch to the next runnable thread.
/// @details This function is placed in the LR slot of the initial exception frame so
///          that it is called automatically when the thread's entry function returns.
///          It frees the heap-allocated stack, marks the slot as unused, decrements
///          the thread count, and finally invokes yield() to trigger a PendSV context
///          switch away from this (now freed) thread.
void terminateThread(void)
{
	__disable_irq();
	uint32_t cid = semaphore::lockSchedule();

	// Release the current thread's stack before requesting a context switch.
	// This is intentional: PendSV must perform the final context save using the
	// current stack pointer before switching to another thread. yss guarantees that this
	// stack cannot be reallocated during this transition, so the memory remains
	// available until PendSV completes the context save.
	delete[] gYssThreadList[gCurrentThreadNum[cid]].malloc;
	gYssThreadList[gCurrentThreadNum[cid]].signalLock = true;
	removeFromActivatedThreadList(gCurrentThreadNum[cid]);
	gYssThreadList[gCurrentThreadNum[cid]].allocated = false;
	gNumOfThread--;

	semaphore::unlockSchedule();

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
	uint32_t primask = __getCoreInterruptStatus();
	__disable_irq();
	uint32_t cid = semaphore::lockSchedule();
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
		{
			gYssDelayList[i].endtime = gYssDelayList[i - 1].endtime;
			gYssDelayList[i].id = gYssDelayList[i - 1].id;
		}

		gYssDelayList[index].endtime = endTime;
		gYssDelayList[index].id = gCurrentThreadNum[cid];

		gDelayCount++;

		if(index == 0)
		{
			setDelayTimer(gCurrentThreadNum[cid], endTime - curTime - 500);
		}

		sleep(cid);

		__disable_irq();
		cid = semaphore::lockSchedule();

		for(index = 0; index < gDelayCount; index++)
		{
			if(gCurrentThreadNum[cid] == gYssDelayList[index].id)
				break;
		}

		if(index < gDelayCount)
		{
		    gDelayCount--;
		    for(int32_t i = index; i < gDelayCount; i++)
			{
				gYssDelayList[i].endtime = gYssDelayList[i + 1].endtime;
				gYssDelayList[i].id = gYssDelayList[i + 1].id;
			}

		    if(index == 0 && gDelayCount > 0)
		    {
		        curTime = runtime::getUsec();
		        if(gYssDelayList[0].endtime > curTime + 1000)
		        {
		            setDelayTimer(gYssDelayList[0].id, gYssDelayList[0].endtime - curTime - 500);
		        }
		        else
		        {
		            signal(gYssDelayList[0].id, false);
		        }
		    }
		}
	}
	
	semaphore::unlockSchedule();
	__setCoreInterruptStatus(primask);

	while (1)
	{
		// Return as soon as the current time meets or exceeds the deadline.
		if (runtime::getUsec() >= endTime)
			return;

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

void resetWaitingSignalPendingFlag(void)
{
	uint32_t cid = semaphore::lockSchedule();
	uint32_t primask = __getCoreInterruptStatus();
	__disable_irq();
	
	gYssThreadList[gCurrentThreadNum[cid]].waitingForSignalPendingFlag = false;

	__setCoreInterruptStatus(primask);
	semaphore::unlockSchedule();		
}

void waitForSignal(uint32_t timeout)
{
	if(timeout == 0)
		return;

	uint32_t cid = semaphore::lockSchedule();
	uint32_t primask = __getCoreInterruptStatus();
	volatile task_t *thread = &gYssThreadList[gCurrentThreadNum[cid]];

	__disable_irq();

	if(thread->waitingForSignalPendingFlag)
	{
		thread->waitingForSignalPendingFlag = false;
		__setCoreInterruptStatus(primask);
		semaphore::unlockSchedule();
		return;
	}

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
		{
			gYssDelayList[i].endtime = gYssDelayList[i - 1].endtime;
			gYssDelayList[i].id = gYssDelayList[i - 1].id;
		}

		gYssDelayList[index].endtime = endTime;
		gYssDelayList[index].id = gCurrentThreadNum[cid];

		gDelayCount++;

		if(index == 0)
		{
			setDelayTimer(gCurrentThreadNum[cid], endTime - curTime - 500);
		}

		sleep(cid);

		__disable_irq();
		cid = semaphore::lockSchedule();

		for(index = 0; index < gDelayCount; index++)
		{
			if(gCurrentThreadNum[cid] == gYssDelayList[index].id)
				break;
		}

		if(index < gDelayCount)
		{
		    gDelayCount--;
		    for(int32_t i = index; i < gDelayCount; i++)
			{
				gYssDelayList[i].endtime = gYssDelayList[i + 1].endtime;
				gYssDelayList[i].id = gYssDelayList[i + 1].id;
			}

		    if(index == 0 && gDelayCount > 0)
		    {
		        curTime = runtime::getUsec();
		        if(gYssDelayList[0].endtime > curTime + 1000)
		        {
		            setDelayTimer(gYssDelayList[0].id, gYssDelayList[0].endtime - curTime - 500);
		        }
		        else
		        {
		            signal(gYssDelayList[0].id, false);
		        }
		    }
		}
	}

	semaphore::unlockSchedule();
	__setCoreInterruptStatus(primask);
}

void signal(threadId_t id, bool lock)
{	
    // 1. Capture current interrupt state and enter critical section if requested.
    uint32_t primask;
	uint32_t cid;

	if(lock)
	{
		primask = __getCoreInterruptStatus();
	    __disable_irq();
		cid = semaphore::lockSchedule();
	}
	else
	{
		cid = semaphore::getId();
	}

	volatile task_t *thread = &gYssThreadList[id];

	switch(cid)
	{
	case 0 :
	    if (!isAllocatedThreadId(id)
#if YSS__CORE_COUNT >= 2
		 || id == gCurrentThreadNum[1]
#endif
#if YSS__CORE_COUNT >= 3
		 || id == gCurrentThreadNum[2]
#endif
#if YSS__CORE_COUNT >= 4
		 || id == gCurrentThreadNum[3]
#endif
		)
			goto error_handler;
		break;

	case 1 :
	    if (!isAllocatedThreadId(id)
#if YSS__CORE_COUNT >= 2
		 || id == gCurrentThreadNum[0]
#endif
#if YSS__CORE_COUNT >= 3
		 || id == gCurrentThreadNum[2]
#endif
#if YSS__CORE_COUNT >= 4
		 || id == gCurrentThreadNum[3]
#endif
		)
			goto error_handler;
		break;

	case 2 :
	    if (!isAllocatedThreadId(id)
#if YSS__CORE_COUNT >= 2
		 || id == gCurrentThreadNum[0]
#endif
#if YSS__CORE_COUNT >= 3
		 || id == gCurrentThreadNum[1]
#endif
#if YSS__CORE_COUNT >= 4
		 || id == gCurrentThreadNum[3]
#endif
		)
			goto error_handler;
		break;

	case 3 :
	    if (!isAllocatedThreadId(id)
#if YSS__CORE_COUNT >= 2
		 || id == gCurrentThreadNum[0]
#endif
#if YSS__CORE_COUNT >= 3
		 || id == gCurrentThreadNum[1]
#endif
#if YSS__CORE_COUNT >= 4
		 || id == gCurrentThreadNum[2]
#endif
		)
			goto error_handler;
		break;
	}

    // 2. Reject invalid IDs or threads that explicitly disallow signaling.
    if (id < 0 || thread->signalLock)
		goto error_handler;

	if(thread->waitingForSignal == false)
	{
		thread->waitingForSignalPendingFlag = true;
		return;
	}

    // 3. Guard against pending dispatch queue overflow[cite: 5].
    if (gPendingSignalThreadCount >= MAX_THREAD)
		goto error_handler;

	if(thread->able)
	{
		goto error_handler;
	}
	else
	{
	    // 4. Ensure the target thread is re-inserted into the active runnable list.
	    insertToActivatedThreadList(id);
		thread->waitingForSignal = false;

		if(gActivatedThreadCount > 0)
			enableSchedulerTimer();

	    // 5. Check if the thread is already in the pending dispatch queue; if so, move it to the tail.
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

	    // 6. Enqueue the thread into the pending signal list for prioritized dispatch in PendSV.
	    gPendingSignalThreadList[gPendingSignalThreadCount++] = id;
	}


finish:
    // 7. Request a context switch to immediately schedule the signaled thread.
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
#elif defined(YSS__CORE_CA35_H_GENERIC)
	GIC_SendSGI((IRQn_Type)0, 0, 2);
#endif

    // 8. Release the scheduler lock and restore the previous interrupt state if locked here.
error_handler :
	if(lock)
	{
		semaphore::unlockSchedule();
	    __setCoreInterruptStatus(primask);
	}
}

void yield(void)
{
    uint32_t primask = __getCoreInterruptStatus();

	__enable_irq();
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
#elif defined(YSS__CORE_CA35_H_GENERIC)
	GIC_SendSGI((IRQn_Type)0, 0, 2);
#endif

	__setCoreInterruptStatus(primask);
}
}

namespace trigger
{
void disable(void);

triggerId_t add(void (*func)(void *), void *var, int32_t stackSize)
{
	volatile task_t *thread;
    int32_t id = -1;

    if (!func)
        return id;

    // 1. Align stack size to an 8-byte (Cortex-M) or 16-byte (Cortex-A35) boundary and enforce minimum size.
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    stackSize = (stackSize + 7) & ~0x7;
#elif defined(YSS__CORE_CA35_H_GENERIC)
    stackSize = (stackSize + 15) & ~0xF;
#endif
    if (stackSize < MIN_STACK_SIZE)
        return id;

    // 2. Pre-allocate stack buffer outside the critical section.
    uintptr_t *stackMem = new uintptr_t[stackSize / sizeof(uintptr_t)];
    if (!stackMem)
        return id;

#if (FILL_THREAD_STACK)
    // Pre-fill stack buffer with watermark pattern for diagnostic analysis.
    memset(stackMem, 0xAA, stackSize);
#endif

    // 3. Enter critical section by capturing interrupt status, disabling interrupts, and acquiring the scheduler lock.
    uint32_t primask = __getCoreInterruptStatus();
    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();

    // 4. Validate slot capacity and locate an available scheduler slot.
    if (gNumOfThread >= MAX_THREAD)
		goto error_handler;

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
        delete[] stackMem;
		goto error_handler;
    }

    // 5. Initialize trigger task descriptor metadata.
    // The initial exception frame is constructed on demand inside prepareStack() when dispatched.
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

error_handler :
    // 6. Release the scheduler lock and restore the previous interrupt state.
	semaphore::unlockSchedule();
    __setCoreInterruptStatus(primask);

    return id;
}

triggerId_t add(void (*func)(void), int32_t  stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

void remove(triggerId_t &id)
{
    // 1. Enter critical section by capturing interrupt status, disabling interrupts, and acquiring the scheduler lock.
    uint32_t primask = __getCoreInterruptStatus();
    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();

    if (!isAllocatedThreadId(id))
		goto error_handler;

    // 2. A running trigger cannot remove itself directly, and invalid IDs are rejected.
    if (id == gCurrentThreadNum[0]
#if YSS__CORE_COUNT >= 2
		|| id == gCurrentThreadNum[1]
#endif	
#if YSS__CORE_COUNT >= 3
		|| id == gCurrentThreadNum[2]
#endif	
#if YSS__CORE_COUNT >= 4
		|| id == gCurrentThreadNum[3]
#endif	
		|| id <= 0)
		goto error_handler;

    // 3. Wait until the trigger's protection count drops to zero before proceeding.
    while (gYssThreadList[id].lockCnt > 0)
    {
		semaphore::unlockSchedule();
        thread::yield();
		cid = semaphore::lockSchedule();
    }

    if (gYssThreadList[id].allocated)
    {
        // 4. Remove from active scheduling and mark as inactive.
        removeFromActivatedThreadList(id);
        gYssThreadList[id].allocated = false;
        gYssThreadList[id].signalLock = true;
        gYssThreadList[id].trigger = false;

        // 5. Purge any pending trigger entries for this ID to prevent Use-After-Free in PendSV.
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
        // Purge any remaining entry in the delay queue and reschedule the timer if needed.
		for (uint32_t i = 0; i < gDelayCount; i++)
		{
			if (gYssDelayList[i].id == id)
			{
				gDelayCount--;
				for (uint32_t j = i; j < gDelayCount; j++)
				{
					gYssDelayList[j].endtime = gYssDelayList[j + 1].endtime;
					gYssDelayList[j].id = gYssDelayList[j + 1].id;
				}

				if (i == 0 && gDelayCount > 0)
				{
					uint64_t curTime = runtime::getUsec();
					if (gYssDelayList[0].endtime > curTime + 1000)
						setDelayTimer(gYssDelayList[0].id, gYssDelayList[0].endtime - curTime - 1000);
					else
						thread::signal(gYssDelayList[0].id, false);
				}
				break;
			}
		}
#endif

        // 6. Free the allocated stack memory and reset task descriptor fields.
        delete[] gYssThreadList[id].malloc;
        gYssThreadList[id].malloc = nullptr;
        gYssThreadList[id].sp = nullptr;
        gYssThreadList[id].size = 0;
        gNumOfThread--;

        // 7. Ensure the round-robin index stays within valid active thread bounds.
        if (gRoundRobinThreadNum >= gActivatedThreadCount)
            gRoundRobinThreadNum = 0;
    }

    // 8. Invalidate the caller's trigger ID reference.
    id = -1;

error_handler :
    // 9. Release the scheduler lock and restore the previous interrupt state.
	semaphore::unlockSchedule();
    __setCoreInterruptStatus(primask);
}

static inline void prepareStack(triggerId_t id)
{
	volatile task_t *thread = &gYssThreadList[id];

    // Reconstruct the initial exception frame on the trigger's pre-allocated stack buffer.
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    uintptr_t stackSize = thread->size >> 2;
#elif defined(YSS__CORE_CA35_H_GENERIC)
    uintptr_t stackSize = thread->size >> 3;
#endif
    uintptr_t *sp = (uintptr_t *)thread->malloc + stackSize;

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    // Ensure 8-byte stack alignment at exception entry point.
    if (((uintptr_t)sp & 0x7) == 0)
        sp--;

    *sp-- = 0x61000000;                              // xPSR (Thumb state)
    *sp-- = (uintptr_t)thread->entry;      // PC (Trigger entry function)
    *sp-- = (uintptr_t)(void (*)(void))disable;       // LR (Return stub that puts trigger into dormant state)
    sp -= 4;                                         // Skip hardware-saved R12, R3, R2, R1
    *sp-- = (uintptr_t)thread->var;        // R0 (Parameter passed to trigger)
    sp -= 8;                                         // Skip callee-saved R11-R4
    *sp = 0xfffffffd;                                // EXC_RETURN (Return to Thread mode using PSP)
#elif defined(YSS__CORE_CA35_H_GENERIC)
    if ((uintptr_t)sp & 0xF)
        sp--;
	
	sp -= 100;
	sp[98] = (uintptr_t )thread->var;                // X0 (First argument passed to the trigger entry function)
    sp[69] = 0;                                      // Padding (8-byte alignment slot left by 'str x30, [x0, #-16]!')
    sp[68] = (uintptr_t)(void (*)(void))disable;     // X30 (LR - Link Register)
    sp[67] = (uintptr_t)thread->entry;               // ELR_EL1 (Trigger entry point PC)
    sp[66] = 0x04;                                   // SPSR_EL1 (PSTATE: EL1t mode with IRQ/FIQ unmasked)
    sp[1] = 0;                                       // FPCR (Floating-point Control Register)
    sp[0] = 0;                                       // FPSR (Floating-point Status Register)
#endif

    thread->sp = sp;
}

void run(triggerId_t id)
{
	volatile task_t *thread = &gYssThreadList[id];

    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __getCoreInterruptStatus();
    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();

    if (!isAllocatedThreadId(id))
        goto error_handler;

    // 2. Reject tasks that are not configured as triggers or are already active.
    if (!thread->trigger || thread->able || thread->waitingForSignal || gPendingSignalThreadCount >= MAX_THREAD)
        goto error_handler;

    // 3. Prevent duplicate enqueueing if the trigger ID is already pending.
    for (uint32_t i = 0; i < gPendingSignalThreadCount; i++)
    {
        if (gPendingSignalThreadList[i] == id)
	        goto error_handler;
    }


    // 4. Mark the trigger as active and push it into the pending dispatch queue.
    insertToActivatedThreadList(id);
    gPendingSignalThreadList[gPendingSignalThreadCount++] = id;

    // 5. Request a context switch to dispatch the trigger.
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
#elif defined(YSS__CORE_CA35_H_GENERIC)
	GIC_SendSGI((IRQn_Type)0, 0, 2);
#endif

error_handler :
    // 6. Release the scheduler lock and restore the previous interrupt state.
	semaphore::unlockSchedule();
    __setCoreInterruptStatus(primask);
}

/// @brief Disable the currently running trigger, preventing it from running until re-triggered.
/// @details This function is placed in the LR slot of the trigger's exception frame so that
///          it executes automatically when the trigger entry function returns.  It loops
///          forever, each iteration clearing the able flag and yielding so the scheduler
///          selects another thread.  The loop is necessary because a PendSV may not fire
///          immediately if it is invoked from an interrupt context; repeating the disable
///          ensures the trigger never re-enters its entry function before the next run().
void disable(void)
{
	// Keep this trigger disabled until it is explicitly re-triggered.
	// The loop ensures the able flag stays clear even if a PendSV is delayed
	// (e.g., when run() is called from an interrupt context).
	while(1)
	{
		__disable_irq();
		uint32_t cid = semaphore::lockSchedule();

		removeFromActivatedThreadList(gCurrentThreadNum[cid]);

		semaphore::unlockSchedule();
		thread::yield();
	}
}

void protect(void)
{
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __getCoreInterruptStatus();
    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();

    // 2. Atomically increment the protection count for the current trigger task.
    gYssThreadList[gCurrentThreadNum[cid]].lockCnt++;

    // 3. Release the scheduler lock and restore the previous interrupt state.
	semaphore::unlockSchedule();
    __setCoreInterruptStatus(primask);
}

void unprotect(void)
{
    // 1. Capture current interrupt state and enter critical section.
    uint32_t primask = __getCoreInterruptStatus();
    __disable_irq();
	uint32_t cid = semaphore::lockSchedule();

    // 2. Decrement protection count and check if it reached zero.
    if (gYssThreadList[gCurrentThreadNum[cid]].lockCnt > 0)
        gYssThreadList[gCurrentThreadNum[cid]].lockCnt--;

    bool isUnprotected = (gYssThreadList[gCurrentThreadNum[cid]].lockCnt == 0);

    // 3. Release the scheduler lock and restore the previous interrupt state.
	semaphore::unlockSchedule();
    __setCoreInterruptStatus(primask);

    // 4. Yield CPU if protection is fully released to allow pending trigger::remove() calls to execute.
    if (isUnprotected)
        thread::yield();
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
	void SysTick_Handler(void)
	{
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC)
		// Do not disable interrupts here to reduce latency for higher-priority interrupts.
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
#endif
#endif
	}

uintptr_t yss_switchContext(uintptr_t currentSp) __attribute__((optimize("-O2")));
uintptr_t yss_switchContext(uintptr_t currentSp)
{
	uint32_t cid = semaphore::lockSchedule();
    // 1. Save the updated stack pointer of the interrupted thread into its task descriptor.
    gYssThreadList[gCurrentThreadNum[cid]].sp = (uintptr_t *)currentSp;

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
	__disable_irq();
#endif

    // 2. Select the next runnable thread based on priority.
    if (gPendingSignalThreadCount > 0)
    {
        // Highest priority: Dispatched pending signals/triggers.
        gPendingSignalThreadCount--;
        gCurrentThreadNum[cid] = gPendingSignalThreadList[gPendingSignalThreadCount];
        gPendingSignalThreadList[gPendingSignalThreadCount] = 0;
		
		if(gYssThreadList[gCurrentThreadNum[cid]].trigger)
			trigger::prepareStack(gCurrentThreadNum[cid]);
    }
    else
    {
#if YSS__CORE_COUNT >= 2
		gCurrentThreadNum[cid] = -1;

		do
		{
	        gRoundRobinThreadNum++;
	        if (gRoundRobinThreadNum >= gActivatedThreadCount)
	            gRoundRobinThreadNum = 0;
		}while (gActivatedThreadList[gRoundRobinThreadNum] == gCurrentThreadNum[0]
#if YSS__CORE_COUNT >= 2
		 || gActivatedThreadList[gRoundRobinThreadNum] == gCurrentThreadNum[1]
#endif
#if YSS__CORE_COUNT >= 3
		 || gActivatedThreadList[gRoundRobinThreadNum] == gCurrentThreadNum[2]
#endif
#if YSS__CORE_COUNT >= 4
		 || gActivatedThreadList[gRoundRobinThreadNum] == gCurrentThreadNum[3]
#endif
		);

        gCurrentThreadNum[cid] = gActivatedThreadList[gRoundRobinThreadNum];
#else
        // Standard round-robin selection among active threads.
        gRoundRobinThreadNum++;
        if ((uint32_t)gRoundRobinThreadNum >= gActivatedThreadCount)
            gRoundRobinThreadNum = 0;

        gCurrentThreadNum[0] = gActivatedThreadList[gRoundRobinThreadNum];
#endif
    }

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
	__enable_irq();
#endif

    // 3. Reset the scheduler timer counter so the new thread gets a full time-slice.
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC) || defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC) 
    SysTick->VAL = 0;
#elif defined(YSS__CORE_CA35_H_GENERIC)
	raw_write_cntps_tval_el1(raw_read_cntfrq_el0() / THREAD_GIVEN_CLOCK);
#endif
	
	semaphore::unlockSchedule();

    // 4. Return the next thread's saved top-of-stack pointer.
    return (uintptr_t)gYssThreadList[gCurrentThreadNum[cid]].sp;
}

void PendSV_Handler(void) __attribute__((naked));
void PendSV_Handler(void)
{
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
    __asm volatile(
        // ----------------------------------------------------------------------
        // 1. SAVE CURRENT THREAD CONTEXT TO PSP
        // ----------------------------------------------------------------------
        "mrs     r0, psp                 \n" // R0 = Current Process Stack Pointer (PSP)

#if defined(__FPU_PRESENT) && __FPU_USED == 1
        // Test EXC_RETURN bit 4: 0 = FPU frame active (extended), 1 = Standard frame
        "tst     lr, #0x10               \n"
        "it      eq                      \n"
        "vstmdbeq r0!, {s16-s31}         \n" // Save callee-saved FPU registers if used
#endif
        "mov     r3, lr                  \n" // Preserve EXC_RETURN in R3
        "stmdb   r0!, {r3-r11}           \n" // Push EXC_RETURN (R3) and callee registers R4-R11

        // ----------------------------------------------------------------------
        // 2. DISPATCH SCHEDULER (MSP Context)
        // ----------------------------------------------------------------------
        "bl      yss_switchContext       \n" // R0 contains currentSp, returns nextSp in R0

        // ----------------------------------------------------------------------
        // 3. RESTORE NEXT THREAD CONTEXT FROM PSP (R0)
        // ----------------------------------------------------------------------
        "ldmia   r0!, {r3-r11}           \n" // Pop EXC_RETURN (into R3) and callee registers R4-R11
        "mov     lr, r3                  \n" // Restore EXC_RETURN into LR

#if defined(__FPU_PRESENT) && __FPU_USED == 1
        // Test restored EXC_RETURN bit 4: restore FPU registers if next thread used FPU
        "tst     lr, #0x10               \n"
        "it      eq                      \n"
        "vldmiaeq r0!, {s16-s31}         \n" // Restore callee-saved FPU registers
#endif
        "msr     psp, r0                 \n" // Update PSP with the new stack pointer
        "bx      lr                      \n" // Exception return using restored EXC_RETURN
    );

#elif defined(YSS__CORE_CM0_H_GENERIC) || defined(YSS__CORE_CM23_H_GENERIC)
    // Cortex-M0 context save/restore using low registers
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
void yield(void)
{

}
}
}

#endif

