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
	threadId_t indexNumber;
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
static volatile uint32_t gActivatedThreadCount = 1;
static volatile threadId_t gActivatedThreadList[MAX_THREAD] = {0};

static Mutex gMutex;                             // Global scheduler mutex

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
			gActivatedThreadList[i] = gActivatedThreadList[i + 1];

		gYssThreadList[id].able = false;
		gYssThreadList[id].indexNumber = -1;
	}
}

namespace thread
{
void terminateThread(void);

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
		debug_printf("Thread creation failed!! The number of created threads has exceeded the configured limit of %d.", MAX_THREAD);
#endif
		return -1;
	}

	// Scan from slot 1 (slot 0 is the idle/main thread) to find an unused slot.
	for (i = 1; i < MAX_THREAD; i++)
	{
		if (!gYssThreadList[i].allocated)
		{
			// Reserve this slot immediately so no other call claims it concurrently.
			gYssThreadList[i].allocated = true;
			break;
		}
	}

	// Allocate stack memory for the new thread.
	gYssThreadList[i].malloc = new int32_t [stackSize/sizeof(int32_t )];

	if (!gYssThreadList[i].malloc)
	{
		// Stack allocation failed; release the slot reservation and report failure.
		gYssThreadList[i].allocated = false;
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("Thread creation failed!! Stack allocation failed.");
#endif
		return -1;
	}
	gYssThreadList[i].size = stackSize;

#if(FILL_THREAD_STACK)
	// Fill the entire stack with 0xAA pattern to aid in stack-usage analysis.
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

	// Convert allocated stack size from bytes to 32-bit words so the stack pointer
	// arithmetic below uses word-aligned offsets.
	stackSize >>= 2;

	// Non-FPU variant: no FPU register slots needed in the exception frame.
	sp = (uint32_t *)((uint32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;								// xPSR: Thumb bit set
	*sp-- = (int32_t )func;							// PC: thread entry point
	*sp-- = (int32_t )(void (*)(void))terminateThread;	// LR: termination handler
	sp -= 4;										// Skip R1, R2, R3, R12
	*sp-- = (int32_t )var;							// R0: thread argument
	sp -= 8;										// Skip R4-R11 (software-saved callee registers)
	*sp = 0xfffffffd;								// EXC_RETURN: Thread mode, PSP
	gYssThreadList[i].sp = sp;

	gYssThreadList[i].lockCnt = 0;
	gYssThreadList[i].trigger = false;
	gYssThreadList[i].entry = func;
	gYssThreadList[i].able = false;
	gYssThreadList[i].signalLock = signalLock;

	insertToActivatedThreadList(i);

	gNumOfThread++;
	gMutex.unlock();
	return i;
}

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
		debug_printf("Thread creation failed!! The number of created threads has exceeded the configured limit of %d.", MAX_THREAD);
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
	gYssThreadList[i].malloc = new int32_t [stackSize/sizeof(int32_t)];

	if (!gYssThreadList[i].malloc)
	{
		gYssThreadList[i].allocated = false;
		gMutex.unlock();
#if defined(THREAD_MONITOR)
		debug_printf("Thread creation failed!! Stack allocation failed.");
#endif
		return -1;
	}
	gYssThreadList[i].size = stackSize;

#if(FILL_THREAD_STACK)
	// Fill the stack region with 0xAA to make high-water mark analysis easier.
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

	// Convert byte count to 32-bit word count for pointer arithmetic.
	stackSize >>= 2;

	// Non-FPU variant: lay out R8-R12 in the software-saved callee register area.
	sp = (uint32_t *)((uint32_t )gYssThreadList[i].malloc & ~0x7) - 1;
	sp += stackSize;
	*sp-- = 0x61000000;								// xPSR
	*sp-- = (uint32_t )func;						// PC
	*sp-- = (uint32_t )(void (*)(void))terminateThread;	// LR
	*sp-- = (uint32_t )r12;							// R12
	sp -= 3;										// Skip R1-R3
	*sp-- = (uint32_t )var;							// R0
	*sp-- = (uint32_t )r11;							// R11
	*sp-- = (uint32_t )r10;							// R10
	*sp-- = (uint32_t )r9;							// R9
	*sp-- = (uint32_t )r8;							// R8
	sp -= 4;										// Skip R4-R7
	*sp = 0xfffffffd;								// EXC_RETURN
	gYssThreadList[i].sp = sp;

	gYssThreadList[i].lockCnt = 0;
	gYssThreadList[i].trigger = false;
	gYssThreadList[i].entry = func;
	gYssThreadList[i].able = false;
	gYssThreadList[i].signalLock = signalLock;

	insertToActivatedThreadList(i);

	gNumOfThread++;
	gMutex.unlock();
	return i;
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

	// Only remove threads that are not the currently executing one and have valid IDs.
	if (id != gCurrentThreadNum && id > 0)
	{
		if (gYssThreadList[id].allocated == true)
		{
			// Mark thread as inactive and free its stack memory.
			gYssThreadList[id].able = false;
			gYssThreadList[id].allocated = false;
			gYssThreadList[id].signalLock = true;
			delete[] gYssThreadList[id].malloc;
			gYssThreadList[id].malloc = 0;
			gYssThreadList[id].sp = 0;
			gYssThreadList[id].size = 0;
			gNumOfThread--;
		}
	}

	// If the removed thread was the next round-robin candidate,
	// advance to the next runnable thread so the scheduler does not
	// attempt to switch to a freed slot.
	if(id == gRoundRobinThreadNum)
	{
		do
		{
			gRoundRobinThreadNum++;
			if (gRoundRobinThreadNum >= MAX_THREAD)
				gRoundRobinThreadNum = 0;
		}while (!gYssThreadList[gRoundRobinThreadNum].able);
	}

	// Clear the holding slot if it pointed to the thread being removed.
	if(id == gHoldingThreadNum)
		gHoldingThreadNum = -1;
	
	// Reset caller's ID to indicate removal.
	id = 0;
	gMutex.unlock();
	unlockContextSwitch();
}

threadId_t getCurrentThreadId(void) __attribute__((optimize("-O1")));
threadId_t getCurrentThreadId(void)
{
	return gCurrentThreadNum;
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
	hfree(gYssThreadList[gCurrentThreadNum].malloc);
	gYssThreadList[gCurrentThreadNum].signalLock = true;
	gYssThreadList[gCurrentThreadNum].able = false;
	gYssThreadList[gCurrentThreadNum].allocated = false;
	gNumOfThread--;

	// If the terminating thread was the current round-robin candidate,
	// advance the index to the next runnable thread.
	if(gCurrentThreadNum == gRoundRobinThreadNum)
	{
		do
		{
			gRoundRobinThreadNum++;
			if (gRoundRobinThreadNum >= MAX_THREAD)
				gRoundRobinThreadNum = 0;
		}while (!gYssThreadList[gRoundRobinThreadNum].able);
	}

	// Release the holding slot if it referenced this thread.
	if(gCurrentThreadNum == gHoldingThreadNum)
		gHoldingThreadNum = -1;

	__enable_irq();
	unlockHmalloc();
	// Yield to let PendSV select the next runnable thread.
	thread::yield();
}

void delay(uint32_t delayTime) __attribute__((optimize("-O1")));
void delay(uint32_t delayTime)
{
	// Compute the absolute wake-up time in microseconds.
	uint64_t endTime = runtime::getUsec() + delayTime * 1000;

	while (1)
	{
		// Return as soon as the current time meets or exceeds the deadline.
		if (runtime::getUsec() >= endTime)
			return;

		// Yield the CPU so other threads can execute during the delay.
		thread::yield();
	}
}

void delayUs(uint32_t delayTime) __attribute__((optimize("-O1")));
void delayUs(uint32_t delayTime)
{
	// Compute the absolute wake-up time in microseconds.
	uint64_t endTime = runtime::getUsec() + delayTime;
	while (1)
	{
		if (runtime::getUsec() >= endTime)
			return;

		thread::yield();
	}
}

void waitForSignal(void) __attribute__((optimize("-O1")));
void waitForSignal(void)
{
	__disable_irq();
	// Mark the current thread as blocked so the scheduler will not select it.
	removeFromActivatedThreadList(gCurrentThreadNum);
	__enable_irq();
	yield();
}

void signal(threadId_t id) __attribute__((optimize("-O1")));
void signal(threadId_t id)
{
	uint32_t count;

	// Ignore invalid thread IDs and threads that have signaling disabled.
	if(id < 0 || gYssThreadList[id].signalLock)
	{
		return;
	}

	__disable_irq();
	if(gPendingSignalThreadCount >= MAX_THREAD)
		// Pending queue is full; cannot enqueue another signal.
		goto finish;
	
	// Check for duplicate signal entries and move existing entry to the tail
	// to refresh the thread's position in the pending queue.
	for(uint32_t i = 0; i < gPendingSignalThreadCount; i++)
	{
		if(gPendingSignalThreadList[i] == id)
		{
			// Shift subsequent entries one position left to close the gap.
			count = gPendingSignalThreadCount - 1;
			for(uint32_t j = i; j < count; j++)
				gPendingSignalThreadList[j] = gPendingSignalThreadList[j+1];
			// Append the thread ID at the tail.
			gPendingSignalThreadList[count] = id;
			if(gHoldingThreadNum < 0)
				gHoldingThreadNum = gCurrentThreadNum;
			goto finish;
		}
	}
	
	// Enqueue the signaled thread and mark the current (calling) thread runnable again.
	gPendingSignalThreadList[gPendingSignalThreadCount++] = id;
	gYssThreadList[gCurrentThreadNum].able = true;
	if(gHoldingThreadNum < 0)
		gHoldingThreadNum = gCurrentThreadNum;
finish :
	// Trigger PendSV to perform the context switch after the signal.
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	__enable_irq();
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
	int32_t i;
	gMutex.lock();

	// Reject the request if the maximum number of scheduler slots is reached.
	if (gNumOfThread >= MAX_THREAD)
	{
		gMutex.unlock();
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

	// Allocate stack space; the trigger will build its frame each time run() is called.
	gYssThreadList[i].malloc = new int32_t [stackSize/sizeof(int32_t )];

	if (!gYssThreadList[i].malloc)
	{
		// Stack allocation failed; release the slot.
		gYssThreadList[i].allocated = false;
		gMutex.unlock();
		return -1;
	}
	gYssThreadList[i].size = stackSize;

#if(FILL_THREAD_STACK)
	// Pre-fill the stack region for easier high-water mark inspection.
	memset(gYssThreadList[i].malloc, 0xaa, stackSize);
#endif

	// Store trigger metadata; note that able is false until trigger::run() is called.
	gYssThreadList[i].var = var;
	gYssThreadList[i].lockCnt = 0;
	gYssThreadList[i].trigger = true;   // Mark this slot as a trigger, not a regular thread.
	gYssThreadList[i].entry = func;
	gYssThreadList[i].able = false;     // Trigger is dormant until explicitly activated.
	gYssThreadList[i].signalLock = false;

	gNumOfThread++;

	gMutex.unlock();
	return i;
}

triggerId_t add(void (*func)(void), int32_t  stackSize) __attribute__((optimize("-O1")));
triggerId_t add(void (*func)(void), int32_t  stackSize)
{
	return add((void (*)(void *))func, 0, stackSize);
}

void remove(triggerId_t &id) __attribute__((optimize("-O1")));
void remove(triggerId_t &id)
{
	// Stop the SysTick-driven context switch to safely modify the task list.
	lockContextSwitch();
	if(gYssThreadList[id].lockCnt > 0)
	{
		// Unlock and busy-wait until the protection count drops to zero.
		unlockContextSwitch();
		while (gYssThreadList[id].lockCnt > 0)
			thread::yield();
		lockContextSwitch();
	}
	gMutex.lock();

	// Do not remove the currently executing trigger or an invalid slot.
	if (id != gCurrentThreadNum && id > 0)
	{
		if (gYssThreadList[id].allocated == true)
		{
			// Mark the slot as free and release its stack memory.
			gYssThreadList[id].able = false;
			gYssThreadList[id].allocated = false;
			gYssThreadList[id].signalLock = true;
			delete[] gYssThreadList[id].malloc;
			gYssThreadList[id].sp = 0;
			gYssThreadList[id].size = 0;
			gNumOfThread--;
		}
	}

	// Advance the round-robin index if it pointed to the removed slot.
	if(gCurrentThreadNum == gRoundRobinThreadNum)
	{
		do
		{
			gRoundRobinThreadNum++;
			if (gRoundRobinThreadNum >= MAX_THREAD)
				gRoundRobinThreadNum = 0;
		}while (!gYssThreadList[gRoundRobinThreadNum].able);
	}

	// Clear the holding slot if it referenced this trigger.
	if(gCurrentThreadNum == gHoldingThreadNum)
		gHoldingThreadNum = -1;
	
	// Notify the caller that the trigger has been removed.
	id = 0;
	gMutex.unlock();
	unlockContextSwitch();
}

void run(triggerId_t id) __attribute__((optimize("-O1")));
void run(triggerId_t id)
{
	uint32_t buf, *sp;

	__disable_irq();

	// Reject non-trigger tasks or triggers that are already running (able == true).
	if(!gYssThreadList[id].trigger || gYssThreadList[id].able)
	{
		// Reject non-trigger tasks or triggers that are already active.
		__enable_irq();	 
		return;
	}

	// Avoid enqueueing the same trigger twice by scanning the pending list.
	for(buf=0;buf<gPendingSignalThreadCount;buf++)
	{
		if(gPendingSignalThreadList[buf] == id)
		{
			// Trigger is already pending, do not enqueue again.
			__enable_irq();	 
			return;
		}
	}
	
	// Convert byte size to word count for stack pointer arithmetic.
	buf = gYssThreadList[id].size >> 2;
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

	// Mark the trigger as runnable and push it into the pending queue.
	insertToActivatedThreadList(id);
	gPendingSignalThreadList[gPendingSignalThreadCount++] = id;
	// Record the calling thread as the holder so PendSV returns to it later.
	if(gHoldingThreadNum < 0)
		gHoldingThreadNum = gCurrentThreadNum;
	// Request a PendSV context switch to dispatch the trigger at the next safe point.
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	__enable_irq();	 
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

	// If fully unprotected, yield to let any waiting remove() call proceed.
	if (gYssThreadList[gCurrentThreadNum].lockCnt == 0)
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

	/// @brief PendSV handler — performs the actual thread context switch.
	/// @details This naked function is the core of the yss scheduler.  The sequence is:
	///          1. Save the current thread's callee-saved registers (R3-R11, and S16-S31
	///             on FPU cores) above the hardware-saved exception frame on the PSP stack.
	///          2. Store the updated PSP into gYssThreadList[gCurrentThreadNum].sp.
	///          3. Select the next thread: pending-signal queue takes priority over the
	///             holding thread, which takes priority over round-robin selection.
	///          4. Reset the SysTick CVR to zero so the new thread gets a full time slice.
	///          5. Restore the new thread's callee-saved registers from its saved stack.
	///          6. Write the new PSP and branch to LR (EXC_RETURN) to complete the switch.
	///
	/// @note The function is declared naked to prevent the compiler from generating its own
	///       prologue/epilogue, which would corrupt the carefully constructed stack frame.
	void PendSV_Handler(void)__attribute__((optimize("-O1"))) __attribute__ ((naked));
	void PendSV_Handler(void) 
	{
#if !defined(YSS__MCU_SMALL_SRAM_NO_SCHEDULE)
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
		// Read the Process Stack Pointer of the interrupted thread into R0.
		asm("mrs r0, psp");

#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
		asm("tst lr, #0x10");
		asm("it eq");
		asm("vstmdbeq r0!, {s16-s31}");		// Copy LR (EXC_RETURN) into R3, then push R3-R11 onto the PSP stack.

		asm("mov r3, lr");
		asm("stmdb r0!, {r3-r11}");
#else
		// No FPU: copy LR into R3, then push R3-R11 (integer callee-saved registers).
		asm("mov r3, lr");
		asm("stmdb r0!, {r3-r11}");
#endif
#elif defined(YSS__CORE_CM0_H_GENERIC)
		// Read PSP of the interrupted thread into R0.
		asm("mrs r0, psp");

		// Cortex-M0 does not support STMDB with high registers, so manually copy
		// LR into R3, then push R3-R7 first, followed by R8-R11.
		asm("mov r3, lr");
		asm("sub r0, r0, #36");        // Reserve 9 words (36 bytes) on the stack.
		asm("stm r0!, {r3-r7}");       // Store R3-R7 (includes LR copy in R3).
		asm("mov r3, r8");             // Copy high registers into low registers.
		asm("mov r4, r9");
		asm("mov r5, r10");
		asm("mov r6, r11");
		asm("stm r0!, {r3-r6}");       // Store R8-R11 (via R3-R6).
		asm("sub r0, r0, #36");        // Restore R0 to the base of the saved frame.
#endif
		// Capture the updated PSP value (now pointing to the bottom of the saved frame)
		// into a local variable via inline assembly.
		uint32_t  sp;
		asm("mov %0, r0" : "=r" (sp) :);

		// Persist the current stack pointer so we can restore this thread later.
		gYssThreadList[gCurrentThreadNum].sp = (uint32_t*)sp;
		sp = 0;
		
		// Determine the next thread to run and load its saved stack pointer.
		__disable_irq();
		if(gPendingSignalThreadCount)
		{	// A signal() or trigger::run() has queued a thread; dispatch it next.
			gPendingSignalThreadCount--;
			gCurrentThreadNum = gPendingSignalThreadList[gPendingSignalThreadCount];
			gPendingSignalThreadList[gPendingSignalThreadCount] = 0;
			sp = (uint32_t)gYssThreadList[gCurrentThreadNum].sp;
			__enable_irq();
		}
		else if(gHoldingThreadNum >= 0)
		{
			// A holding thread was set (e.g., the signaling caller); resume it.
			gCurrentThreadNum = gHoldingThreadNum;
			gHoldingThreadNum = -1;
			sp = (uint32_t)gYssThreadList[gCurrentThreadNum].sp;
		}
		else
		{
			__enable_irq();
			gRoundRobinThreadNum++;
			if((uint32_t)gRoundRobinThreadNum >= gActivatedThreadCount)
				gRoundRobinThreadNum = 0;

			gCurrentThreadNum = gActivatedThreadList[gRoundRobinThreadNum];
			sp = (uint32_t)gYssThreadList[gCurrentThreadNum].sp;
		}
		__enable_irq();

		// Load the selected thread's stack pointer into R0 for use in the restore sequence.
		asm("mov r0, %0" : : "r" (sp));
#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC) || defined(YSS__CORE_CM33_H_GENERIC)
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
		// Reset the SysTick Current Value Register to zero so the new thread receives
		// a full time slice.  The counter may have decremented before the context switch
		// started or during intermediate ISRs, so an explicit reset is necessary.
		asm("ldr r3, =0xe000e010");    // Address of SysTick control/status register base.
		asm("movs r1, #0");
		asm("str r1, [r3, #8]");       // Write 0 to SYST_CVR (offset 8) to clear the counter.

		// Restore the new thread's FPU and integer callee-saved registers from its stack.
		asm("ldm  r0!, {r3-r11}");     // Restore R3-R11 (R3 holds EXC_RETURN).
		asm("mov lr, r3");             // Move EXC_RETURN back into LR.

		asm("tst lr, #0x10");
		asm("it eq");
		asm("vldmeq r0!, {s16-s31}");
#else
		// Reset SysTick counter for the non-FPU path.
		asm("ldr r3, =0xe000e010");
		asm("movs r1, #0");
		asm("str r1, [r3, #8]");

		// Restore R3-R11 of the new thread (no FPU registers to restore).
		asm("ldm  r0!, {r3-r11}");
		asm("mov lr, r3");             // Recover EXC_RETURN into LR.
#endif
#elif defined(YSS__CORE_CM0_H_GENERIC)

		// Reset SysTick counter on Cortex-M0.
		asm("ldr r3, =0xe000e010");
		asm("movs r1, #0");
		asm("str r1, [r3, #8]");

		// On Cortex-M0 high registers cannot be loaded directly, so first advance
		// R0 past the R3-R7 area and restore R8-R11 via low register intermediates.
		asm("add r0, r0, #20");        // Skip over the saved R3-R7 block (5 words).
		asm("ldm  r0!, {r3-r6}");      // Load saved R8-R11 into R3-R6.
		asm("mov r8, r3");
		asm("mov r9, r4");
		asm("mov r10, r5");
		asm("mov r11, r6");

		// Step back to the base of the saved frame and restore R3-R7.
		asm("sub r0, r0, #36");
		asm("ldm  r0!, {r3-r7}");      // Load R3-R7 (R3 holds EXC_RETURN / LR).
		asm("add r0, r0, #16");        // Advance R0 past the R8-R11 block.
#endif
		// Write the restored stack pointer back to PSP to complete the context switch.
		asm("msr psp, r0");
#endif
		// Return from exception using the EXC_RETURN value in LR to switch to the new thread.
		asm("bx lr");
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

