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
	 * Create a new thread with the specified entry function, parameter, and stack size.
	 *
	 * @param func Thread entry point that receives one void* parameter.
	 * @param var Parameter passed to the thread entry point.
	 * @param stackSize Stack size in bytes for the new thread.
	 * @param signalLock If true, the new thread is not eligible to receive signal() calls.
	 * @return Thread ID on success, or -1 on failure.
	 */
	threadId_t add(void (*func)(void *), void *var, int32_t stackSize, bool signalLock = false);

	/**
	 * Create a new thread while initializing additional registers r8-r12.
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
	 * Create a new parameterless thread.
	 *
	 * @param func Entry point for the new thread.
	 * @param stackSize Stack size in bytes for the new thread.
	 * @param signalLock If true, the new thread is not eligible to receive signal() calls.
	 * @return Thread ID on success, or -1 on failure.
	 */
	threadId_t add(void (*func)(void), int32_t stackSize, bool signalLock = false);

	/**
	 * Create a new parameterless thread and preload registers r8-r12.
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
	 * Remove a thread from scheduling and free its resources.
	 *
	 * @param id Reference to the thread ID to remove; set to 0 on success.
	 */
	void remove(threadId_t &id);

	/**
	 * Get the current thread identifier.
	 *
	 * @return ID of the currently executing thread.
	 */
	threadId_t getCurrentThreadId(void);

	/**
	 * Increase the protection count for the current thread.
	 *
	 * This prevents the current thread from being removed while protected.
	 */
	void protect(void);

	/**
	 * Increase the protection count for the specified thread.
	 *
	 * @param id Thread ID to protect.
	 */
	void protect(threadId_t id);

	/**
	 * Decrease the protection count for the current thread.
	 */
	void unprotect(void);

	/**
	 * Decrease the protection count for the specified thread.
	 *
	 * @param id Thread ID to unprotect.
	 */
	void unprotect(threadId_t id);

	/**
	 * Delay the current thread for a number of milliseconds.
	 *
	 * @param delayTime Delay duration in milliseconds.
	 */
	void delay(uint32_t delayTime);

	/**
	 * Delay the current thread for a number of microseconds.
	 *
	 * @param delayTime Delay duration in microseconds.
	 */
	void delayUs(uint32_t delayTime);

	/**
	 * Block the current thread until it receives a signal.
	 */
	void waitForSignal(void);

	/**
	 * Signal a thread to wake it and schedule it for execution.
	 *
	 * @param id Thread ID to signal.
	 */
	void signal(threadId_t id);

extern "C"
{
	/**
	 * Yield execution to allow a context switch.
	 */
	void yield(void);
}
}

typedef int32_t		triggerId_t;

namespace trigger
{
	/**
	 * Create a new trigger task with a parameter.
	 *
	 * @param func Trigger entry function that receives one void* parameter.
	 * @param var Parameter passed to the trigger entry function.
	 * @param stackSize Stack size in bytes for the trigger task.
	 * @return Trigger ID on success, or -1 on failure.
	 */
	triggerId_t add(void (*func)(void *), void *var, int32_t stackSize);

	/**
	 * Create a new parameterless trigger task.
	 *
	 * @param func Trigger entry function.
	 * @param stackSize Stack size in bytes for the trigger task.
	 * @return Trigger ID on success, or -1 on failure.
	 */
	triggerId_t add(void (*func)(void), int32_t stackSize);

	/**
	 * Remove a trigger task and free its resources.
	 *
	 * @param num Reference to the trigger ID to remove.
	 */
	void remove(triggerId_t &num);

	/**
	 * Activate a trigger task for execution.
	 *
	 * @param num Trigger ID to run.
	 */
	void run(triggerId_t num);

	/**
	 * Increase the protection count for the current trigger.
	 */
	void protect(void);

	/**
	 * Increase the protection count for the specified trigger.
	 *
	 * @param num Trigger ID to protect.
	 */
	void protect(triggerId_t num);

	/**
	 * Decrease the protection count for the current trigger.
	 */
	void unprotect(void);

	/**
	 * Decrease the protection count for the specified trigger.
	 *
	 * @param num Trigger ID to unprotect.
	 */
	void unprotect(triggerId_t num);
}

#endif

