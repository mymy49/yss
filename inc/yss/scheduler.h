/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_THREAD__H_
#define YSS_THREAD__H_

#include <drv/mcu.h>
#include <yss/Mutex.h>

typedef int32_t		threadId_t;

namespace thread
{
	/**
	 * @brief Create a new thread with the specified entry function, parameter, and stack size.
	 *
	 * @details Allocates a scheduler slot and stack memory, then constructs the initial
	 *          ARM exception frame so that the first PendSV context switch resumes
	 *          execution at @p func with @p var in R0.
	 *          On FPU-enabled cores the frame includes space for S0-S15 (saved by hardware)
	 *          and S16-S31 (managed manually); the EXC_RETURN value 0xFFFFFFFD selects
	 *          Thread mode with PSP.
	 *
	 * @param func Thread entry point that receives one void* parameter.
	 * @param var Parameter passed to the thread entry point.
	 * @param stackSize Stack size in bytes for the new thread.
	 * @param signalLock If true, the new thread is not eligible to receive signal() calls.
	 * @return Thread ID on success, or -1 on failure.
	 */
	threadId_t add(void (*func)(void *), void *var, int32_t stackSize, bool signalLock = false);

	/**
	 * @brief Create a new thread while initializing additional registers r8-r12.
	 *
	 * @details Identical to the basic add() overload, but also places caller-supplied values
	 *          for R8-R12 into the initial software-saved register area of the exception frame.
	 *          This is used when the thread entry function reads those registers on startup
	 *          (e.g., when a single entry stub dispatches to different handlers based on R8-R12).
	 *
	 * @param func Thread entry point that receives one void* parameter.
	 * @param var Parameter passed to the thread entry point.
	 * @param stackSize Stack size in bytes for the new thread.
	 * @param r8 Initial r8 register value on thread startup.
	 * @param r9 Initial r9 register value on thread startup.
	 * @param r10 Initial r10 register value on thread startup.
	 * @param r11 Initial r11 register value on thread startup.
	 * @param r12 Initial r12 register value on thread startup.
	 * @param signalLock If true, the new thread is not eligible to receive signal() calls.
	 * @return Thread ID on success, or -1 on failure.
	 */
	threadId_t add(void (*func)(void *), void *var, int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock = false);

	/**
	 * @brief Create a new parameterless thread.
	 *
	 * @details Casts @p func to a void*(void*) signature and passes nullptr as the argument,
	 *          then delegates to the primary add() overload.
	 *
	 * @param func Entry point for the new thread.
	 * @param stackSize Stack size in bytes for the new thread.
	 * @param signalLock If true, the new thread is not eligible to receive signal() calls.
	 * @return Thread ID on success, or -1 on failure.
	 */
	threadId_t add(void (*func)(void), int32_t stackSize, bool signalLock = false);

	/**
	 * @brief Create a new parameterless thread and preload registers r8-r12.
	 *
	 * @details Casts @p func to a void*(void*) signature and passes nullptr as the argument,
	 *          then delegates to the register-preloaded add() overload.
	 *
	 * @param func Entry point for the new thread.
	 * @param stackSize Stack size in bytes for the new thread.
	 * @param r8 Initial r8 register value on thread startup.
	 * @param r9 Initial r9 register value on thread startup.
	 * @param r10 Initial r10 register value on thread startup.
	 * @param r11 Initial r11 register value on thread startup.
	 * @param r12 Initial r12 register value on thread startup.
	 * @param signalLock If true, the new thread is not eligible to receive signal() calls.
	 * @return Thread ID on success, or -1 on failure.
	 */
	threadId_t add(void (*func)(void), int32_t stackSize, void *r8, void *r9, void *r10, void *r11, void *r12, bool signalLock = false);

	/**
	 * @brief Remove a thread from scheduling and free its resources.
	 *
	 * @details Stops the SysTick-driven context switch while the thread list is modified
	 *          to prevent a preemption that could leave the list in an inconsistent state.
	 *          If the target thread has a non-zero protection count (lockCnt > 0), the
	 *          function busy-waits with yield() until the count drops to zero before
	 *          proceeding with removal.
	 *
	 * @param id Reference to the thread ID to remove; set to 0 on success.
	 */
	void remove(threadId_t &id);

	/**
	 * @brief Get the current thread identifier.
	 *
	 * @return ID of the currently executing thread.
	 */
	threadId_t getCurrentThreadId(void);

	/**
	 * @brief Increase the protection count for the current thread.
	 *
	 * @details Disables IRQ while incrementing lockCnt so the increment is atomic.
	 *          Any call to thread::remove() on this thread will busy-wait until
	 *          lockCnt returns to zero.  Calls may be nested; each protect() must
	 *          be paired with a corresponding unprotect().
	 */
	void protect(void);

	/**
	 * @brief Increase the protection count for the specified thread.
	 *
	 * @param id Thread ID to protect.
	 */
	void protect(threadId_t id);

	/**
	 * @brief Decrease the protection count for the current thread.
	 *
	 * @details Mirrors protect(). When lockCnt reaches zero the thread can be removed
	 *          by an external caller that was blocked in thread::remove().
	 */
	void unprotect(void);

	/**
	 * @brief Decrease the protection count for the specified thread.
	 *
	 * @param id Thread ID to unprotect.
	 */
	void unprotect(threadId_t id);

	/**
	 * @brief Delay the current thread for a number of milliseconds.
	 *
	 * @details Converts @p delayTime to microseconds, captures the absolute wake-up time,
	 *          and then repeatedly yields until the system timer reaches or passes it.
	 *          Yielding allows other threads to run during the wait.
	 *
	 * @param delayTime Delay duration in milliseconds.
	 */
	void delay(uint32_t delayTime);

	/**
	 * @brief Delay the current thread for a number of microseconds.
	 *
	 * @details Same as delay() but accepts a microsecond resolution argument directly,
	 *          avoiding the multiply-by-1000 conversion.
	 *
	 * @param delayTime Delay duration in microseconds.
	 */
	void delayUs(uint32_t delayTime);

	/**
	 * @brief Block the current thread until it receives a signal.
	 *
	 * @details Marks the current thread as non-runnable (able = false) so the round-robin
	 *          scheduler will skip it, then yields to force an immediate context switch.
	 *          The thread remains suspended until thread::signal() re-enables it.
	 */
	void waitForSignal(void);

	/**
	 * @brief Signal a thread to wake it and schedule it for execution.
	 *
	 * @details Places the target thread ID into the pending-signal FIFO so that the next
	 *          PendSV context switch will resume that thread.  If the thread ID is already
	 *          present in the queue it is moved to the tail so that repeated signals do not
	 *          create duplicate entries but still refresh the thread's position.
	 *          A PendSV is pended immediately after modifying the queue so the context
	 *          switch is handled at the earliest safe opportunity.
	 *
	 * @param id Thread ID to signal.
	 */
	void signal(threadId_t id);

extern "C"
{
	/**
	 * @brief Yield execution to allow a context switch.
	 *
	 * @details Writing SCB_ICSR_PENDSVSET to ICSR pends the PendSV exception.
	 *          Because PendSV is configured at the lowest interrupt priority it will only
	 *          run after all higher-priority ISRs complete, making it safe to call from
	 *          both thread and interrupt context.
	 */
	void yield(void);
}
}

typedef int32_t		triggerId_t;

namespace trigger
{
	/**
	 * @brief Create a new trigger task with a parameter.
	 *
	 * @details A trigger differs from a normal thread in that its able flag is initially
	 *          false.  The slot is reserved and the stack is allocated, but the initial
	 *          exception frame is NOT built here; it is constructed on each call to
	 *          trigger::run() so the trigger function always starts from the beginning.
	 *
	 * @param func Trigger entry function that receives one void* parameter.
	 * @param var Parameter passed to the trigger entry function.
	 * @param stackSize Stack size in bytes for the trigger task.
	 * @return Trigger ID on success, or -1 on failure.
	 */
	triggerId_t add(void (*func)(void *), void *var, int32_t stackSize);

	/**
	 * @brief Create a new parameterless trigger task.
	 *
	 * @details Casts the parameterless function pointer to void*(void*) and passes nullptr
	 *          for the argument, then delegates to the primary trigger::add().
	 *
	 * @param func Trigger entry function.
	 * @param stackSize Stack size in bytes for the trigger task.
	 * @return Trigger ID on success, or -1 on failure.
	 */
	triggerId_t add(void (*func)(void), int32_t stackSize);

	/**
	 * @brief Remove a trigger task and free its resources.
	 *
	 * @details Functionally mirrors thread::remove().  The context switch is locked to
	 *          prevent a preemption that could corrupt the task list, and the function
	 *          busy-waits if the trigger's protection count is non-zero.
	 *
	 * @param num Reference to the trigger ID to remove; set to 0 on success.
	 */
	void remove(triggerId_t &num);

	/**
	 * @brief Activate a trigger task for one-shot execution.
	 *
	 * @details Rebuilds the initial exception frame in the trigger's stack buffer every
	 *          time it is called, so the trigger function always re-executes from its
	 *          start.  Guards against re-entrancy by checking both the able flag and the
	 *          pending queue.  After enqueuing, the current thread is marked as the
	 *          holding thread so that PendSV will return to it after the trigger finishes.
	 *
	 * @param num Trigger ID to run.
	 */
	void run(triggerId_t num);

	/**
	 * @brief Increase the protection count for the current trigger.
	 *
	 * @details Prevents external code from removing the trigger via trigger::remove()
	 *          while the protection count is non-zero.  Must be paired with unprotect().
	 */
	void protect(void);

	/**
	 * @brief Increase the protection count for the specified trigger.
	 *
	 * @param num Trigger ID to protect.
	 */
	void protect(triggerId_t num);

	/**
	 * @brief Decrease the protection count for the current trigger.
	 *
	 * @details Decrements lockCnt, and if it reaches zero, yields immediately so
	 *          any pending trigger::remove() call can proceed without further delay.
	 */
	void unprotect(void);

	/**
	 * @brief Decrease the protection count for the specified trigger.
	 *
	 * @param num Trigger ID to unprotect.
	 */
	void unprotect(triggerId_t num);
}

namespace semaphore
{
	/**
	 * @brief Gets the core ID of the CPU currently executing code.
	 *
	 * @return uint32_t The core ID (e.g., 0 for Core 0, 1 for Core 1).
	 */
	uint32_t getId();

	/**
	 * @brief Locks scheduling across cores using a hardware semaphore to prevent race conditions during scheduling state changes.
	 *
	 * @return uint32_t The core ID of the caller.
	 */
	uint32_t lockSchedule();

	/**
	 * @brief Releases the scheduling hardware semaphore lock.
	 */
	void unlockSchedule();
}

#endif


