////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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