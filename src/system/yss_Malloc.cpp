/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <internal/malloc.h>

namespace Malloc
{
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

	// 빈 테이블 검색
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
	// 빈 클러스터 탐색
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

	// 반환될 주소 계산
	addr = (uint32_t)obj.heap;
	addr += begin * obj.clusterSize;

	// 찾아진 주소 위치가 힙의 전체 크기를 초과하는지 검사
	if (addr + size > obj.endOfHeapAddr)
		return 0;

	// 할당된 클러스터 채우기
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

	// 할당 테이블에 데이터 저장
	table->addr = (void *)addr;
	table->begin = begin;
	table->clusterSize = needNumOfCluster;

	return (void *)addr;
}

void free(MallocSet &obj, void *addr)
{
	uint32_t shifter, index, cnt;
	MallocTable *table;

	// 할당된 클러스터 테이블 찾기
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
	// 할당된 클러스터 지우기
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