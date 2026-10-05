/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file msp_m4xx.cpp
 * @brief MCU Support Package (MSP) system/peripheral clock configuration for Nuvoton M4xx.
 */

#include <drv/peripheral.h>

#if defined(__MA35H0_FAMILY)

#include <config.h>
#include <yss/instance.h>

#if defined(__M46x_SUBFAMILY)
#define FBDIV_VALUE		48
#elif defined(__M480_FAMILY)
#define FBDIV_VALUE		46
#elif defined(__M4xx_FAMILY)
#define FBDIV_VALUE		34
#endif

void initializeDma(void)
{

}

// 1. 메모리 지도(Page Table) 생성
// 1GB 단위로 총 4GB 공간을 커버하므로 4칸짜리 배열이면 충분합니다.
// (MMU 테이블은 메모리에서 4KB 단위로 정렬되어야 하므로 aligned 속성을 줍니다)
static volatile uint64_t l1_page_table[4] __attribute__((aligned(4096))) ;

void enable_simple_mmu_cache(void)
{
    // =========================================================================
    // 단계 1: 메모리 속성(Attribute) 2가지 정의 (MAIR_EL3 레지스터)
    // - 속성 0 (0x00): Device 메모리 (캐시 꺼짐, 페리퍼럴용)
    // - 속성 1 (0xFF): Normal 메모리 (캐시 켜짐, DDR 램용)
    // =========================================================================
    uint64_t mair = (0xFFULL << 8) | (0x00ULL << 0);
    __asm__ volatile("msr mair_el3, %0" : : "r"(mair));
    // =========================================================================
    // 단계 2: 1GB 단위(Level 1 Block) 메모리 지도(Page Table) 작성
    // 비트 설명: 
    //   [1:0] = 0x1 (1GB Block 임을 의미)
    //   [4:2] = 속성 인덱스 (0: Device, 1: Cached)
    //   [10]  = 1 (Access Flag 활성화, 이거 없으면 에러남)
    // =========================================================================
    
    // [인덱스 0] 0x00000000 ~ 0x3FFFFFFF (1GB) : SRAM 구역 -> 캐시 켜기(속성 1)
    l1_page_table[0] = (0x00000000ULL) | (1 << 2) | (1 << 10) | 0x1;
    
    // [인덱스 1] 0x40000000 ~ 0x7FFFFFFF (1GB) : 페리퍼럴 -> 캐시 끄기(속성 0)
    l1_page_table[1] = (0x40000000ULL) | (0 << 2) | (1 << 10) | 0x1;
    
    // [인덱스 2] 0x80000000 ~ 0xBFFFFFFF (1GB) : DDRAM 구역-> 캐시 켜기(속성 1)
    l1_page_table[2] = (0x80000000ULL) | (1 << 2) | (1 << 10) | 0x1;
    
    // [인덱스 3] 0xC0000000 ~ 0xFFFFFFFF (1GB) : DDRAM 구역 -> 캐시 켜기(속성 1)
    l1_page_table[3] = (0xC0000000ULL) | (1 << 2) | (1 << 10) | 0x1;
    // =========================================================================
    // 단계 3: 변환 제어 레지스터 (TCR_EL3) 설정
    // 32비트 주소 공간 사용(4GB), 4KB 페이지 단위 사용 설정
    // =========================================================================
    uint64_t tcr = (32ULL << 0)  |  // T0SZ = 64 - 32(비트) = 32
                   (1ULL << 8)   |  // 캐시 정책: Inner Write-Back
                   (1ULL << 10)  |  // 캐시 정책: Outer Write-Back
                   (3ULL << 12)  |  // Shareability: Inner Shareable
                   (0ULL << 14)  |  // TG0 (Granule) = 4KB
                   (0ULL << 16);    // 물리 주소 최대 크기 = 32비트(4GB)
    __asm__ volatile("msr tcr_el3, %0" : : "r"(tcr));
    // =========================================================================
    // 단계 4: 페이지 테이블 시작 주소 입력 (TTBR0_EL3)
    // =========================================================================
    __asm__ volatile("msr ttbr0_el3, %0" : : "r"((uint64_t)l1_page_table));
    // =========================================================================
    // 단계 5: 기존 TLB 찌꺼기 초기화 및 동기화 배리어
    // =========================================================================
    __asm__ volatile("tlbi alle3\n dsb sy\n isb");
    // =========================================================================
    // 단계 6: 대망의 MMU 및 캐시(I-Cache, D-Cache) 활성화 (SCTLR_EL3)
    // =========================================================================
    uint64_t sctlr;
    __asm__ volatile("mrs %0, sctlr_el3" : "=r"(sctlr));
    sctlr |= (1 << 0)  |  // M 비트: MMU 켜기
             (1 << 2)  |  // C 비트: Data Cache 켜기
             (1 << 12);   // I 비트: Instruction Cache 켜기
    __asm__ volatile("msr sctlr_el3, %0\n isb" : : "r"(sctlr));
}

volatile uint32_t systick_cnt, default_cnt;

extern "C"
{
	void SystemCoreClockUpdate(void)
	{

	}

	void TMR1_IRQHandler();

	void irqExceptionHandler()
	{
	    IRQn_Type irq_num = (IRQn_Type)(GICInterface->IAR & 0x3FF);

		switch(irq_num)
		{
		case SecPhysicalTimer_IRQn :
			systick_cnt++;
			break;
			
		case TMR1_IRQn :
			TMR1_IRQHandler();
			break;
		
		default :
			printf("%d\n", irq_num);
			break;
		}
		GIC_EndInterrupt(irq_num);
	}
}

#endif

