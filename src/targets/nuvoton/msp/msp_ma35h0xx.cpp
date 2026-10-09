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

// Stage-1 Level-1 Block Descriptor (1GB) 필드
#define PTE_BLOCK		(0x1ULL)			// [1:0] = 01 : Block descriptor
#define PTE_ATTR(n)		((uint64_t)(n) << 2)	// [4:2] AttrIndx (MAIR 인덱스)
#define PTE_AP_RW_ALL	(0ULL << 6)			// [7:6] AP = 01 : EL1/EL0 모두 RW
#define PTE_SH_OUTER	(2ULL << 8)			// [9:8] SH = 10 : Outer Shareable
#define PTE_SH_INNER	(3ULL << 8)			// [9:8] SH = 11 : Inner Shareable
#define PTE_AF			(1ULL << 10)		// [10] Access Flag
#define PTE_XN_EL3		(1ULL << 54)		// [54] Execute Never (EL3 체계는 이 비트만 사용)
#define PTE_NORMAL		(PTE_BLOCK | PTE_ATTR(1) | PTE_AP_RW_ALL | PTE_SH_INNER | PTE_AF)
#define PTE_DEVICE		(PTE_BLOCK | PTE_ATTR(0) | PTE_AP_RW_ALL | PTE_SH_OUTER | PTE_AF | PTE_XN_EL3)

// 1. 메모리 지도(Page Table) 생성
// 1GB 단위로 총 4GB 공간을 커버하므로 4칸짜리 배열이면 충분합니다.
// (MMU 테이블은 메모리에서 4KB 단위로 정렬되어야 하므로 aligned 속성을 줍니다)
static volatile uint64_t l1_page_table[4]  __attribute__((section(".non_init"), aligned(4096)));

void __WEAK initializeSystem(void)
{
    // =========================================================================
    // 단계 1: 메모리 속성(Attribute) 2가지 정의 (MAIR_EL3 레지스터)
    // - 속성 0 (0x00): Device 메모리 (캐시 꺼짐, 페리퍼럴용)
    // - 속성 1 (0xFF): Normal 메모리 (캐시 켜짐, DDR 램용)
    // =========================================================================
    uint64_t mair = (0xFFULL << 8) | (0x00ULL << 0);
    __asm__ volatile("msr mair_el3, %0" : : "r"(mair));
    __asm__ volatile("msr mair_el2, %0" : : "r"(mair));
    __asm__ volatile("msr mair_el1, %0" : : "r"(mair));
    // =========================================================================
    // 단계 2: 1GB 단위(Level 1 Block) 메모리 지도(Page Table) 작성
    // 비트 설명: 
    //   [1:0] = 0x1 (1GB Block 임을 의미)
    //   [4:2] = 속성 인덱스 (0: Device, 1: Cached)
    //   [10]  = 1 (Access Flag 활성화, 이거 없으면 에러남)
    // =========================================================================

	// [인덱스 0] 0x00000000 ~ 0x3FFFFFFF (1GB) : SRAM 구역 -> 캐시 켜기(속성 1)
	l1_page_table[0] = 0x00000000ULL | PTE_NORMAL;   // SRAM

	// [인덱스 1] 0x40000000 ~ 0x7FFFFFFF (1GB) : 페리퍼럴 -> 캐시 끄기(속성 0)
	l1_page_table[1] = 0x40000000ULL | PTE_DEVICE;   // 페리퍼럴

	// [인덱스 2] 0x80000000 ~ 0xBFFFFFFF (1GB) : DDRAM 구역-> 캐시 켜기(속성 1)
	l1_page_table[2] = 0x80000000ULL | PTE_NORMAL;   // DDR

	// [인덱스 3] 0xC0000000 ~ 0xFFFFFFFF (1GB) : DDRAM 구역 -> 캐시 켜기(속성 1)
	l1_page_table[3] = 0xC0000000ULL | PTE_NORMAL;   // (일단 유지, 나중에 정리)
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
    __asm__ volatile("msr tcr_el2, %0" : : "r"(tcr));

	uint64_t tcr_el1 = (32ULL << 0)  |  // T0SZ = 64 - 32(비트) = 32
                       (1ULL << 8)   |  // 캐시 정책: Inner Write-Back
                       (1ULL << 10)  |  // 캐시 정책: Outer Write-Back
                       (3ULL << 12)  |  // Shareability: Inner Shareable
                       (0ULL << 14)  |  // TG0 (Granule) = 4KB
                       (1ULL << 23)  |  // EPD1 = 1 : TTBR1_EL1(상위 주소) 페이지 테이블 탐색 중지
                       (0ULL << 32);    // IPS = 0 : 물리 주소 최대 크기 = 32비트(4GB)

    __asm__ volatile("msr tcr_el1, %0" : : "r"(tcr_el1));
    // =========================================================================
    // 단계 4: 페이지 테이블 시작 주소 입력 (TTBR0_EL3)
    // =========================================================================
    __asm__ volatile("msr ttbr0_el3, %0" : : "r"((uint64_t)l1_page_table));
    __asm__ volatile("msr ttbr0_el2, %0" : : "r"((uint64_t)l1_page_table));
    __asm__ volatile("msr ttbr0_el1, %0" : : "r"((uint64_t)l1_page_table));
    // =========================================================================
    // 단계 5: 기존 TLB 찌꺼기 초기화 및 동기화 배리어
    // =========================================================================
    __asm__ volatile("tlbi alle3\n tlbi vmalle1\n dsb sy\n isb");
    // =========================================================================
    // 단계 6: 대망의 MMU 및 캐시(I-Cache, D-Cache) 활성화 (SCTLR_EL3)
    // =========================================================================
    uint64_t sctlr;
    __asm__ volatile("mrs %0, sctlr_el3" : "=r"(sctlr));
    sctlr |= (1 << 0)  |  // M 비트: MMU 켜기
             (1 << 2)  |  // C 비트: Data Cache 켜기
             (1 << 12);   // I 비트: Instruction Cache 켜기
    __asm__ volatile("msr sctlr_el3, %0\n isb" : : "r"(sctlr));

    __asm__ volatile("mrs %0, sctlr_el2" : "=r"(sctlr));
    sctlr |= (1 << 0)  |  // M 비트: MMU 켜기
             (1 << 2)  |  // C 비트: Data Cache 켜기
             (1 << 12);   // I 비트: Instruction Cache 켜기
    __asm__ volatile("msr sctlr_el2, %0\n isb" : : "r"(sctlr));

    __asm__ volatile("mrs %0, sctlr_el1" : "=r"(sctlr));
    sctlr |= (1 << 0)  |  // M 비트: MMU 켜기
             (1 << 2)  |  // C 비트: Data Cache 켜기
             (1 << 12);   // I 비트: Instruction Cache 켜기
    __asm__ volatile("msr sctlr_el1, %0\n isb" : : "r"(sctlr));

    // =========================================================================
    // 단계 7: EL0(유저 모드)에 일부 EL1 권한 위임하기
    // =========================================================================
    // 1. EL0에게 타이머 제어 권한 허용 (CNTKCTL_EL1 레지스터)
    // - Physical / Virtual Timer를 EL0에서 직접 읽고 쓸 수 있게 합니다.
    uint64_t cntkctl = (1ULL << 9) | // EL0PTEN: Physical Timer 접근 허용
                       (1ULL << 8) | // EL0VTEN: Virtual Timer 접근 허용
                       (1ULL << 1) | // EL0VCTEN: Virtual Counter 접근 허용
                       (1ULL << 0);  // EL0PCTEN: Physical Counter 접근 허용
    __asm__ volatile("msr cntkctl_el1, %0" : : "r"(cntkctl));
    // 2. EL0에게 인터럽트 및 캐시 명령어 제어 권한 허용 (SCTLR_EL1 수정)
    __asm__ volatile("mrs %0, sctlr_el1" : "=r"(sctlr));
    sctlr |= (1ULL << 9)   | // UMA: EL0에서 인터럽트 전체 끄기/켜기(DAIF 마스크) 명령어 허용
             (1ULL << 26)  | // UCI: EL0에서 캐시 비우기(Cache Maintenance) 명령어 허용
             (1ULL << 14)  | // DZE: EL0에서 메모리 블록을 0으로 초기화(DC ZVA)하는 명령어 허용
             (1ULL << 15);   // UCT: EL0에서 캐시 타입 정보(CTR_EL0) 읽기 허용
    __asm__ volatile("msr sctlr_el1, %0\n isb" : : "r"(sctlr));
}

extern "C"
{
	void SystemCoreClockUpdate(void)
	{

	}

	void TMR1_IRQHandler();

	void irqExceptionHandler(IRQn_Type irqNum)
	{
		switch(irqNum)
		{
		case SecPhysicalTimer_IRQn :
			raw_write_cntps_tval_el1(raw_read_cntfrq_el0() / THREAD_GIVEN_CLOCK);
			GIC_SendSGI((IRQn_Type)0, 0, 2);
			break;
			
		case TMR1_IRQn :
			TMR1_IRQHandler();
			break;
		
		default :
			break;
		}
	}

	void synchronousExceptionHandler()
	{
		while(1);
	}

	void sErrorExceptionHandler()
	{
		while(1);
	}

	void fiqExceptionHandler()
	{
		while(1);
	}
}

#endif

