/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_L_MALLOC__H_
#define YSS_L_MALLOC__H_

#include <stdint.h>

/**
 * @file lmalloc.h
 * @brief Dynamic memory allocation helper functions for external SDRAM/L-heap memory.
 */

/**
 * @brief Frees the memory space pointed to by addr, which must have been returned by a previous call to lmalloc().
 * @note Mutex lock and unlock operations are managed internally.
 *
 * @param[in] addr Pointer to the memory block to free.
 */
void lfree(void* addr);

/**
 * @brief Allocates size bytes and returns a pointer to the allocated memory from the external SDRAM space.
 * @note Mutex lock and unlock operations are managed internally.
 *
 * @param[in] size Number of bytes to allocate.
 * @return void* Pointer to the allocated memory, or nullptr on failure.
 */
void* lmalloc(uint32_t size);

#endif


