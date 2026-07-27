/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file yss_Malloc.cpp
 * @brief Common heap memory allocation and management algorithms.
 *
 * @details
 * Implements low-level cluster-based allocation (`malloc`) and deallocation (`free`)
 * functions used by specific heap instances (e.g. c_heap, l_heap, h_heap).
 */

#include <config.h>
#include <yss/malloc.h>

namespace Malloc
{
/**
 * @brief Allocates a block of memory from a MallocSet heap.
 *
 * @param[in,out] obj Reference to the MallocSet heap configuration.
 * @param[in] size Size of the memory block to allocate in bytes.
 * @return void* Pointer to the allocated memory block, or nullptr if allocation fails.
 */
void *malloc(MallocSet &obj, uint32_t size)
{
	MallocTable *table;
	uint32_t buffer = 0;
	uint32_t cnt = 0, begin = 0, shifter = 0, index;
	uint32_t addr;
	uint32_t *cluster = obj.cluster;
	uint32_t needNumOfCluster = size / obj.clusterSize;
	bool checking = false, complete = false;

	if (size % obj.clusterSize)
		needNumOfCluster++;

	// Find an unused allocation table entry.
	for (uint32_t i = 0; i < obj.maxNumOfMalloc; i++)
	{
		if (!obj.table[i].addr)
		{
			table = &obj.table[i];
			goto next1;
		}
	}
	return 0;

next1:
	// Search for a free cluster region that can satisfy the request.
	for (uint32_t i = 0, index = 0xffffffff; i < obj.totalClusterNum * 32; i++)
	{
		if (i % 32 == 0)
		{
			index++;
			buffer = ~cluster[index];
			if (buffer == 0)
			{
				i += 31;
				goto next;
			}
			shifter = 1;
		}

		if (checking)
		{
			if (buffer & shifter)
			{
				cnt++;
			}
			else
			{
				checking = false;
				cnt = 0;
			}
		}
		else
		{
			if (buffer & shifter)
			{
				checking = true;
				begin = i;
				cnt++;
			}
		}

		if (needNumOfCluster == cnt)
		{
			complete = true;
			break;
		}
	next:
		shifter <<= 1;
	}

	if (complete == false)
		return 0;

	// Calculate the returned address from the heap base and starting cluster.
	addr = (uint32_t)obj.heap;
	addr += begin * obj.clusterSize;

	// Check whether the found address exceeds the heap bounds.
	if (addr + size > obj.endOfHeapAddr)
		return 0;

	// Mark the allocated clusters as used in the cluster bitmap.
	shifter = 1 << (begin % 32);
	index = begin / 32;
	while (cnt)
	{
		if (shifter == 0)
		{
			shifter = 1;
			index++;
		}
		if (shifter == 1 && cnt > 32)
		{
			cluster[index] = 0xffffffff;
			shifter = 0;
			cnt -= 32;
		}
		else
		{
			cluster[index] |= shifter;
			shifter <<= 1;
			cnt--;
		}
	}

	// Store allocation data in the metadata table
	table->addr = (void *)addr;
	table->begin = begin;
	table->clusterSize = needNumOfCluster;

	return (void *)addr;
}

/**
 * @brief Frees an allocated block of memory in a MallocSet heap.
 *
 * @param[in,out] obj Reference to the MallocSet heap configuration.
 * @param[in] addr Pointer to the memory block to free.
 */
void free(MallocSet &obj, void *addr)
{
	uint32_t shifter, index, cnt;
	MallocTable *table;

	// Find the allocation table entry for the given address.
	for (uint32_t i = 0; i < obj.maxNumOfMalloc; i++)
	{
		if (obj.table[i].addr == addr)
		{
			table = &obj.table[i];
			goto next;
		}
	}
	return;

next:
	// Clear the cluster bits for this allocation.
	cnt = table->clusterSize;
	shifter = 1 << (table->begin % 32);
	index = table->begin / 32;
	while (cnt)
	{
		if (shifter == 0)
		{
			shifter = 1;
			index++;
		}
		if (shifter == 1 && cnt > 32)
		{
			obj.cluster[index] = 0x0;
			shifter = 0;
			cnt -= 32;
		}
		else
		{
			obj.cluster[index] &= ~shifter;
			shifter <<= 1;
			cnt--;
		}
	}

	table->addr = 0;
	table->begin = 0;
	table->clusterSize = 0;
}
}