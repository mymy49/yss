// MIT License

// Copyright (c) 2024 Yoon-Ki Hong

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef YSS_STRING__H_
#define YSS_STRING__H_

#include <string.h>
#include <stdint.h>

/**
 * @file string.h
 * @brief Extended memory copy and fill functions for the YSS framework.
 *
 * @details
 * This file provides optimized memory manipulation utilities, including fast assembly-optimized
 * memory setting routines (`memsethw`, `memsetw`) and DMA-based memory copy/set
 * operations (`memcpyd`, `memsetd`, `memsethwd`, `memsetwd`).
 *
 * ### Assembly-Optimized Operations
 * The `memsethw` and `memsetw` functions are implemented in ARM assembly for high-performance memory filling.
 *
 * ### DMA Memory Operations
 * The DMA-based functions (`memcpyd`, `memsetd`, `memsethwd`, `memsetwd`) leverage the system DMA controller
 * to perform operations. These functions block the calling thread (`thread::yield()`) until the DMA transfer completes,
 * making them suitable for large buffer operations while freeing CPU cycles for other threads.
 */

extern "C"
{
	/**
	 * @brief Fills a block of memory with a 16-bit halfword value.
	 *
	 * @details
	 * Fills the destination memory block with a specified 16-bit value. This function
	 * is implemented in assembly for optimized execution.
	 *
	 * @param[in] __s Pointer to the destination memory block.
	 * @param[in] __c The 16-bit value to fill with (lower 16 bits of the integer are used).
	 * @param[in] __n The size of the memory block to fill, in bytes. Must be a multiple of 2.
	 * @return void* A pointer to the destination memory block `__s`.
	 */
	void *memsethw(void *__s, int32_t  __c, uint32_t __n);

	/**
	 * @brief Fills a block of memory with a 32-bit word value.
	 *
	 * @details
	 * Fills the destination memory block with a specified 32-bit value. This function
	 * is implemented in assembly for optimized execution.
	 *
	 * @param[in] __s Pointer to the destination memory block.
	 * @param[in] __c The 32-bit value to fill with.
	 * @param[in] __n The size of the memory block to fill, in bytes. Must be a multiple of 4.
	 * @return void* A pointer to the destination memory block `__s`.
	 */
	void *memsetw(void *__s, int32_t  __c, uint32_t __n);
}

/**
 * @brief Copies a block of memory using DMA.
 *
 * @details
 * Performs a fast memory copy from a source pointer to a destination pointer using the DMA controller.
 * The calling thread will yield (`thread::yield()`) until the transfer is finished.
 *
 * @param[out] des Pointer to the destination memory block.
 * @param[in] src Pointer to the source memory block.
 * @param[in] size The size of the memory block to copy, in bytes.
 */
void memcpyd(void* des, void* src, uint32_t size) __attribute__((optimize("-O1")));

/**
 * @brief Fills a block of memory with an 8-bit byte value using DMA.
 *
 * @details
 * Fills a memory block with an 8-bit byte value using the DMA controller.
 * The calling thread will yield (`thread::yield()`) until the transfer is finished.
 *
 * @param[out] des Pointer to the destination memory block.
 * @param[in] data The 8-bit value to fill the memory with.
 * @param[in] count The number of bytes to fill.
 */
void memsetd(void* des, uint8_t data, uint32_t count) __attribute__((optimize("-O1")));

/**
 * @brief Fills a block of memory with a 16-bit halfword value using DMA.
 *
 * @details
 * Fills a memory block with a 16-bit halfword value using the DMA controller.
 * The calling thread will yield (`thread::yield()`) until the transfer is finished.
 *
 * @param[out] des Pointer to the destination memory block.
 * @param[in] data The 16-bit value to fill the memory with.
 * @param[in] count The number of 16-bit halfword elements to fill.
 */
void memsethwd(void* des, uint16_t data, uint32_t count) __attribute__((optimize("-O1")));

/**
 * @brief Fills a block of memory with a 32-bit word value using DMA.
 *
 * @details
 * Fills a memory block with a 32-bit word value using the DMA controller.
 * The calling thread will yield (`thread::yield()`) until the transfer is finished.
 *
 * @param[out] des Pointer to the destination memory block.
 * @param[in] data The 32-bit value to fill the memory with.
 * @param[in] count The number of 32-bit word elements to fill.
 */
void memsetwd(void* des, uint32_t data, uint32_t count) __attribute__((optimize("-O1")));

#endif
