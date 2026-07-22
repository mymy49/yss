/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_DIPLAY_PAGE_MANAGER__H_
#define YSS_UTIL_DIPLAY_PAGE_MANAGER__H_

#include <stdint.h>
#include <yss/Mutex.h>
#include <yss/Trigger.h>

/**
 * @file DisplayPageManager.h
 * @brief Display Page Manager class header file.
 */

/**
 * @class DisplayPageManager
 * @brief Manages multiple display pages or UI view threads.
 *
 * @details
 * This class registers page update/rendering functions (as thread routines) and executes
 * them in a synchronized, thread-safe sequence. When a page transition is requested (via play),
 * the currently executing page thread is stopped, and the new page thread starts.
 */
class DisplayPageManager : private Mutex, private Trigger
{
public:
	/**
	 * @brief Constructor for DisplayPageManager.
	 *
	 * @param[in] maxCount Maximum number of page functions that can be registered.
	 */
	DisplayPageManager(int16_t maxCount);

	/**
	 * @brief Destructor for DisplayPageManager.
	 */
	~DisplayPageManager();

	/**
	 * @brief Registers a page function to be managed.
	 *
	 * @param[in] func Pointer to the page rendering/logic function (takes void* parameter).
	 * @return int16_t The registered Page ID on success, or -1 if the manager is full.
	 */
	int16_t add(void (*func)(void*));

	/**
	 * @brief Stops the current page and runs the page matching the specified ID.
	 *
	 * @param[in] id The ID of the page to run.
	 * @param[in] stackSize Stack size allocated to the new page thread (default is 512 bytes).
	 */
	void play(int16_t id, uint32_t stackSize = 512);

private:
	int16_t mMaxCount, mCount, mUpdateIndex;
	uint32_t mStackSize;
	threadId_t mId;
	void* mVar;

	void (**mFunctionList)(void*);

	void trigger(void) override;
};

#endif


