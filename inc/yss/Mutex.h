/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Mutex.h
 * @brief Mutex synchronization primitive for thread-safe resource access.
 */

#ifndef YSS_MUTEX__H_
#define YSS_MUTEX__H_	`

#include <stdint.h>
#include <drv/peripheral.h>

class Mutex
{
public:

	/**
	 * @brief Lock the mutex using a ticket-lock algorithm and block other threads.
	 *
	 * @details Implements a fair, FIFO ticket lock:
	 *          1. Increments the thread's protection count so the scheduler does not
	 *             remove it while waiting.
	 *          2. Atomically reads-and-increments mWaitNum to obtain a unique ticket number.
	 *          3. If an IRQ is associated with this mutex, disables it so the lock holder
	 *             is not preempted by the hardware the mutex protects.
	 *          4. Spin-yields until mCurrentNum equals the obtained ticket number, meaning
	 *             all earlier lock holders have called unlock().
	 *
	 *          If THREAD_WATCHDOG_ENABLE is defined, a deadline is set at acquisition time
	 *          and mutexWatchdogHandler() is called if the lock is not acquired within
	 *          THREAD_WATCHDOG_OVERFLOW_TIME milliseconds.
	 *
	 * @return uint32_t Current lock key value (the ticket number obtained).
	 */
	uint32_t lock(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Attempt to lock the mutex without blocking.
	 *
	 * @details Checks whether the mutex is currently free (mWaitNum == mCurrentNum).
	 *          If free, atomically acquires it by incrementing mWaitNum and optionally
	 *          disabling the associated IRQ, then returns true.
	 *          If already held by another thread, returns false immediately without waiting.
	 *
	 * @return true if the mutex was successfully acquired.
	 * @return false if the mutex is already locked.
	 */
	bool check(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Unlock the previously acquired mutex and wake waiting threads.
	 *
	 * @details Advances mCurrentNum by one so the next waiting ticket holder is unblocked.
	 *          If an IRQ was disabled during lock(), it is re-enabled here.  If other
	 *          threads are still waiting (mWaitNum != mCurrentNum) and the mutex subsystem
	 *          has been initialized, thread::yield() is called to let the scheduler switch
	 *          to one of them immediately.
	 *
	 *          Unlocking a mutex that is not currently held may lead to undefined behavior.
	 */
	void unlock(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Associate an IRQ with this mutex so it is disabled while the mutex is held.
	 *
	 * @details When a hardware peripheral's ISR must be excluded while its driver holds
	 *          the mutex, storing the IRQ number here causes lock() to disable the IRQ
	 *          and unlock() to re-enable it, preventing ISR re-entrancy.
	 *          If the mutex is unlocked, the IRQ is also released.
	 *
	 * @param irq IRQ number to disable during the locked period.
	 */
	void setIrq(IRQn_Type irq) __attribute__((optimize("-O1")));

	/**
	 * @brief Construct a new Mutex object and initialize its ticket-lock counters.
	 *
	 * @details Sets mWaitNum and mCurrentNum to zero (no tickets issued, no tickets
	 *          served) and mIrqNum to -1 (no associated IRQ).
	 *          This constructor is intended for internal system use.
	 */
	Mutex(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Initialize the mutex subsystem and enable watchdog functionality.
	 *
	 * @details Sets the global initialization flag to true so that unlock() will call
	 *          thread::yield() when other threads are waiting for the lock.
	 *          Must be called once during system startup before any mutex is used.
	 */
	void initializeMutex(void) __attribute__((optimize("-O1")));

private:
	uint32_t mWaitNum, mCurrentNum;
	IRQn_Type mIrqNum;
	static bool mInit;
};

#endif