/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INTERNAL_MALLOC__H_
#define YSS_INTERNAL_MALLOC__H_

#include <config.h>
#include <drv/peripheral.h>
#include <stdint.h>

namespace Malloc
{
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

void *malloc(MallocSet &obj, uint32_t mallocClusterNum);
void free(MallocSet &obj, void *addr);
}

#endif

#if defined(CCMSRAM_BASE)
#define CCMDATARAM_BASE CCMSRAM_BASE
#endif

#if defined(CCMSRAM_SIZE)
#define CCMDATARAM_END (CCMSRAM_BASE + CCMSRAM_SIZE - 1)
#endif

#if YSS_C_HEAP_USE == true && defined(CCMDATARAM_BASE)

// lmalloc의 내부 계산 식(수정 금지)
#define YSS_C_HEAP_TOTAL_CLUSTER_SIZE (YSS_C_HEAP_SIZE / YSS_C_HEAP_CLUSTER_SIZE / 32)
#define YSS_C_HEAP_CLUSTER_BASE_ADDR (CCMDATARAM_BASE)
#define YSS_C_HEAP_TABLE_BASE_ADDR (YSS_C_HEAP_CLUSTER_BASE_ADDR + YSS_C_HEAP_TOTAL_CLUSTER_SIZE * sizeof(int32_t))
#define YSS_C_HEAP_BASE_ADDR (YSS_C_HEAP_TABLE_BASE_ADDR + YSS_C_MAX_NUM_OF_MALLOC * 12)
#define YSS_C_HEAP_SIZE (CCMDATARAM_END - CCMDATARAM_BASE + 1)

#if YSS_C_HEAP_SIZE % YSS_C_HEAP_CLUSTER_SIZE
#error "YSS_C_HEAP_SIZE가 YSS_C_HEAP_CLUSTER_SIZE로 나누어 떨어지게 설정해주세요."
#endif

#if YSS_C_HEAP_CLUSTER_SIZE % 4
#error "YSS_C_HEAP_CLUSTER_SIZE 4로 나누어 떨어지게 설정해주세요."
#endif

#if YSS_C_HEAP_SIZE / YSS_C_HEAP_CLUSTER_SIZE < 32
#error "YSS_C_HEAP_SIZE의 값이 YSS_C_HEAP_CLUSTER_SIZE로 나누어 32보다 작지 않게 해주세요."
#endif

#endif