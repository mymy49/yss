/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_H_MALLOC__H_
#define YSS_H_MALLOC__H_

#include <stdint.h>

/**
 * @file hmalloc.h
 * @brief Heap memory allocation helpers for the YSS heap manager.
 */

/**
 * @brief Allocate memory from the heap.
 *
 * @param size Number of bytes to allocate.
 * @return void* Pointer to the allocated memory, or nullptr if allocation fails.
 */
void* hmalloc(uint32_t size);

/**
 * @brief Free a previously allocated heap block.
 *
 * @param addr Pointer to the memory block to free.
 */
void hfree(void* addr);

/**
 * @brief Lock the heap allocator to protect against concurrent access.
 */
void lockHmalloc(void);

/**
 * @brief Unlock the heap allocator after protected access.
 */
void unlockHmalloc(void);

/**
 * @brief Get the remaining heap capacity.
 *
 * @return uint32_t Remaining number of bytes available in the heap.
 */
uint32_t getHeapRemainingCapacity(void);

#endif

