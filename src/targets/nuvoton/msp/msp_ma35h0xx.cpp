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
#include <string.h>

void initializeDma(void)
{

}

extern "C" void reset_handler();

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
static volatile uint64_t l1_page_table0[4]  __attribute__((section(".non_init"), aligned(4096)));
static volatile uint64_t l1_page_table1[4]  __attribute__((section(".non_init"), aligned(4096)));

void initializeMmu(volatile uint64_t *table)
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
	table[0] = 0x00000000ULL | PTE_NORMAL;   // SRAM

	// [인덱스 1] 0x40000000 ~ 0x7FFFFFFF (1GB) : 페리퍼럴 -> 캐시 끄기(속성 0)
	table[1] = 0x40000000ULL | PTE_DEVICE;   // 페리퍼럴

	// [인덱스 2] 0x80000000 ~ 0xBFFFFFFF (1GB) : DDRAM 구역-> 캐시 켜기(속성 1)
	table[2] = 0x80000000ULL | PTE_NORMAL;   // DDR

	// [인덱스 3] 0xC0000000 ~ 0xFFFFFFFF (1GB) : DDRAM 구역 -> 캐시 켜기(속성 1)
	table[3] = 0xC0000000ULL | PTE_NORMAL;   // (일단 유지, 나중에 정리)
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
    __asm__ volatile("msr ttbr0_el3, %0" : : "r"((uint64_t)table));
    __asm__ volatile("msr ttbr0_el2, %0" : : "r"((uint64_t)table));
    __asm__ volatile("msr ttbr0_el1, %0" : : "r"((uint64_t)table));
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

void __WEAK initializeSystem(void)
{
	initializeMmu(l1_page_table0);

	SYS->RLKTZS = 0x59;
	SYS->RLKTZS = 0x16;
	SYS->RLKTZS = 0x88;

	CLK->SYSCLK1 |= CLK_SYSCLK1_HWSCKEN_Msk;

	SYS->RLKTZS = 0x00;

	CLK->SYSCLK1 |=	CLK_SYSCLK1_GPACKEN_Msk | CLK_SYSCLK1_GPBCKEN_Msk | CLK_SYSCLK1_GPCCKEN_Msk | CLK_SYSCLK1_GPDCKEN_Msk |
					CLK_SYSCLK1_GPECKEN_Msk | CLK_SYSCLK1_GPFCKEN_Msk | CLK_SYSCLK1_GPGCKEN_Msk | CLK_SYSCLK1_GPHCKEN_Msk |
					CLK_SYSCLK1_GPHCKEN_Msk | CLK_SYSCLK1_GPICKEN_Msk | CLK_SYSCLK1_GPJCKEN_Msk | CLK_SYSCLK1_GPKCKEN_Msk |
					CLK_SYSCLK1_GPLCKEN_Msk | CLK_SYSCLK1_GPMCKEN_Msk | CLK_SYSCLK1_GPNCKEN_Msk;
}

void __WEAK initializeSystem1(void)
{
	initializeMmu(l1_page_table1);

	uint32_t clk = raw_read_cntfrq_el0();
	if (clk == 0)
	{
		clk = 12000000;
		raw_write_cntfrq_el0(clk);
	}
}

void initializeMultiCore(void)
{
	SYS->RLKTZS = 0x59;
	SYS->RLKTZS = 0x16;
	SYS->RLKTZS = 0x88;

	SYS->CA35WRBADR1 = (uintptr_t)reset_handler;
	__asm__ volatile("dsb sy");
	sev();

	SYS->RLKTZS = 0x00;
}

extern "C"
{
	void main1()
	{
		GIC_CPUInterfaceInit();

		__disableInterrupt(NonSecPhysicalTimer_IRQn);
		__disableInterrupt(SecPhysicalTimer_IRQn);

		uint32_t clk = raw_read_cntfrq_el0();
 
		raw_write_cntps_tval_el1(clk / THREAD_GIVEN_CLOCK);
		__ISB();
	
		raw_write_cntps_ctl_el1(1);
		__ISB();

		__setInterruptPriority(SecPhysicalTimer_IRQn, 0x10); 
		__enableInterrupt(SecPhysicalTimer_IRQn);
	
	    GIC_SetPriority(SGI0_IRQn, 0x10);
	    GIC_EnableIRQ(SGI0_IRQn);
		GIC_SetGroup(SGI0_IRQn, 0);

		__enable_irq();

		while(1)
		{
			thread::yield();
		}
	}

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

	volatile uint64_t gSyncFaultElr[2];
	volatile uint64_t gSyncFaultEsr[2];

	void synchronousExceptionHandler()
	{
		uint32_t cid = semaphore::getId();
		__asm__ volatile("mrs %0, elr_el1" : "=r"(gSyncFaultElr[cid]));
		__asm__ volatile("mrs %0, esr_el1" : "=r"(gSyncFaultEsr[cid]));
		while(1);
	}

	volatile uint64_t gSErrorFaultElr[2];
	volatile uint64_t gSErrorFaultEsr[2];

	void sErrorExceptionHandler()
	{
		uint32_t cid = semaphore::getId();
		__asm__ volatile("mrs %0, elr_el1" : "=r"(gSErrorFaultElr[cid]));
		__asm__ volatile("mrs %0, esr_el1" : "=r"(gSErrorFaultEsr[cid]));
		while(1);
	}

	void fiqExceptionHandler()
	{
		while(1);
	}
}

namespace semaphore
{
#define CORE_ID_UNLOCKED 0
#define CORE_ID_A35      1
#define CORE_ID_M4       2

uint32_t getId()
{
	uint64_t mpidr;

	__asm__ volatile ("mrs %0, mpidr_el1" : "=r" (mpidr));

	return mpidr & 3;
}

#define HWSEM_MAGIC_KEY  0xAA

uint32_t lockSchedule()
{
	uint64_t mpidr;
	uint32_t id, key, cid;

	__asm__ volatile ("mrs %0, mpidr_el1" : "=r" (mpidr));
	
	cid = mpidr &= 0x03;
	mpidr += 0xAA;

	do
	{
		HWSEM0->SEM[0] = (mpidr << HWSEM_SEM_KEY_Pos);
		key = (HWSEM0->SEM[0] & HWSEM_SEM_KEY_Msk) >> HWSEM_SEM_KEY_Pos;
		id = (HWSEM0->SEM[0] & HWSEM_SEM_ID_Msk) >> HWSEM_SEM_ID_Pos;
	}while(id != CORE_ID_A35 || key != mpidr);
    __DMB();

    return cid;
}

void unlockSchedule()
{
	uint64_t mpidr;

	__DMB();
	__asm__ volatile ("mrs %0, mpidr_el1" : "=r" (mpidr));
	
	mpidr &= 0x03;
	mpidr += 0xAA;
	
	HWSEM0->SEM[0] = (mpidr << HWSEM_SEM_KEY_Pos);
}
}

#endif

