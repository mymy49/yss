/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file malloc.h
 * @brief Heap allocation helpers and internal malloc structures.
 */

#ifndef YSS_INTERNAL_MALLOC__H_
#define YSS_INTERNAL_MALLOC__H_

#include <config.h>
#include <drv/peripheral.h>
#include <stdint.h>

namespace Malloc
{
/**
 * @brief Table entry describing an allocated or free block.
 */
struct MallocTable
{
	void *addr;
	uint32_t begin;
	uint32_t clusterSize;
};

struct MallocSet
{
	void *heap;
	MallocTable *table;
	uint32_t *cluster;
	uint32_t totalClusterNum;
	uint32_t clusterSize;
	uint32_t maxNumOfMalloc;
	uint32_t endOfHeapAddr;
};

/**
 * @brief Allocate memory from the configured heap.
 *
 * @param obj Heap state object tracking allocations.
 * @param mallocClusterNum Number of clusters to allocate.
 * @return void* Pointer to the allocated memory, or nullptr on failure.
 */
void *malloc(MallocSet &obj, uint32_t mallocClusterNum);

/**
 * @brief Free a previously allocated block.
 *
 * @param obj Heap state object tracking allocations.
 * @param addr Pointer to the block to free.
 */
void free(MallocSet &obj, void *addr);
}

#endif

