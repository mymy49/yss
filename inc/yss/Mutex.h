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
	 * @brief Lock the mutex and block other threads.
	 *
	 * @return uint32_t Current lock key value.
	 */
	uint32_t lock(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Attempt to lock the mutex without blocking.
	 *
	 * If the mutex is available, it is acquired and true is returned.
	 * If it is already held by another thread, false is returned.
	 *
	 * @return true if the mutex was successfully acquired.
	 * @return false if the mutex is already locked.
	 */
	bool check(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Unlock the previously acquired mutex.
	 *
	 * Unlocking a mutex that is not currently held may lead to undefined behavior.
	 */
	void unlock(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Set the IRQ to disable while the mutex is held.
	 *
	 * If the mutex is unlocked, the IRQ is also released.
	 *
	 * @param irq IRQ number to disable during the locked period.
	 */
	void setIrq(IRQn_Type irq) __attribute__((optimize("-O1")));

	/**
	 * @brief Construct a new Mutex object.
	 *
	 * This constructor is intended for internal system use.
	 */
	Mutex(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Initialize the mutex internal state.
	 */
	void initializeMutex(void) __attribute__((optimize("-O1")));

private:
	uint32_t mWaitNum, mCurrentNum;
	IRQn_Type mIrqNum;
	static bool mInit;
};

#endif