////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_INTERNAL_MALLOC__H_
#define YSS_INTERNAL_MALLOC__H_

#include <yss/mcu.h>

namespace Malloc
{
	struct MallocTable
	{
		void* addr;
		unsigned long begin;
		unsigned long clusterSize;
	};

	struct MallocSet
	{
		void *heap;
        MallocTable *table;
		unsigned long *cluster;
        unsigned long totalClusterNum;
        unsigned long clusterSize;
		unsigned long maxNumOfMalloc;
        unsigned long endOfHeapAddr;
	};

	void* malloc(MallocSet &obj, unsigned long mallocClusterNum);
	void free(MallocSet &obj, void *addr);
}

#endif


#if	YSS_L_HEAP_USE == true

// lmalloc의 내부 계산 식(수정 금지)
#define	YSS_L_HEAP_TOTAL_CLUSTER_SIZE		(YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE / 32)
#define YSS_L_HEAP_CLUSTER_BASE_ADDR		(YSS_SDRAM_ADDR)
#define YSS_L_HEAP_TABLE_BASE_ADDR			(YSS_L_HEAP_CLUSTER_BASE_ADDR + YSS_L_HEAP_TOTAL_CLUSTER_SIZE * sizeof(long))
#define YSS_L_HEAP_BASE_ADDR				(YSS_L_HEAP_TABLE_BASE_ADDR + YSS_L_MAX_NUM_OF_MALLOC * 12)

#if YSS_L_HEAP_SIZE % YSS_L_HEAP_CLUSTER_SIZE
#error "YSS_L_HEAP_SIZE가 YSS_L_HEAP_CLUSTER_SIZE로 나누어 떨어지게 설정해주세요."
#endif

#if YSS_L_HEAP_CLUSTER_SIZE % 4
#error "YSS_L_HEAP_CLUSTER_SIZE 4로 나누어 떨어지게 설정해주세요."
#endif

#if YSS_L_HEAP_SIZE / YSS_L_HEAP_CLUSTER_SIZE < 32
#error "YSS_L_HEAP_SIZE의 값이 YSS_L_HEAP_CLUSTER_SIZE로 나누어 32보다 작지 않게 해주세요."
#endif
#endif

#if !YSS_H_HEAP_USE && !YSS_L_HEAP_USE
#error "H_HEAP 또는 L_HEAP 둘중에 하나는 반드시 활성화가 되어야 합니다."
#endif


#if	YSS_C_HEAP_USE == true && defined(CCMDATARAM_BASE)

// lmalloc의 내부 계산 식(수정 금지)
#define	YSS_C_HEAP_TOTAL_CLUSTER_SIZE		(YSS_C_HEAP_SIZE / YSS_C_HEAP_CLUSTER_SIZE / 32)
#define YSS_C_HEAP_CLUSTER_BASE_ADDR		(CCMDATARAM_BASE)
#define YSS_C_HEAP_TABLE_BASE_ADDR			(YSS_C_HEAP_CLUSTER_BASE_ADDR + YSS_C_HEAP_TOTAL_CLUSTER_SIZE * sizeof(long))
#define YSS_C_HEAP_BASE_ADDR				(YSS_C_HEAP_TABLE_BASE_ADDR + YSS_C_MAX_NUM_OF_MALLOC * 12)
#define YSS_C_HEAP_SIZE						(CCMDATARAM_END-CCMDATARAM_BASE+1)

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



