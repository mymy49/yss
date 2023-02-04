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

#ifndef YSS_MALLOC__H_
#define YSS_MALLOC__H_

#include <config.h>
#include <stdint.h>

// MCU 내장 SRAM(Heap)으로부터 동적 메모리 할당받는 함수이다.
// hmalloc 함수는 다른 함수(lmalloc, cmalloc)와 다르게 호출전에 lockHmalloc() 함수를 호출해서 뮤텍스 락을 걸어야 한다.
// 할당이 끝나면 unlockHmalloc() 함수를 호출해서 뮤텍스 언락을 해줘야 한다.
// new, delete함수는 내부적으로 수행하지만 스케줄러 속도 개선을 위해 해당 함수에 대해만 lock, unlock을
// 별도로 두었다.
// 
// 반환
//		할당받은 메모리의 번지를 반환한다.
// uint32_t size
//		메모리 할당받을 용량을 설정한다.
void* hmalloc(uint32_t size);

// hmalloc을 통해 MCU 내장 SRAM(Heap)으로부터 동적 메모리 할당 받은 메모리를 반환하는 함수이다.
// hfree 함수는 다른 함수(lfree, cfree)와 다르게 호출전에 lockHmalloc() 함수를 호출해서 뮤텍스 락을 걸어야 한다.
// 할당이 끝나면 unlockHmalloc() 함수를 호출해서 뮤텍스 언락을 해줘야 한다.
// new, delete함수는 내부적으로 수행하지만 스케줄러 속도 개선을 위해 해당 함수에 대해만 lock, unlock을
// 별도로 두었다.
// 
// void* addr
//		반환할 메모리의 번지를 설정한다.
void hfree(void* addr);

// hmalloc, hfree 함수에 대한 뮤텍스 락을 거는 함수이다.
void lockHmalloc(void);

// hmalloc, hfree 함수에 대한 뮤텍스 언락을 하는 함수이다.
void unlockHmalloc(void);

// Heap 영역의 남은 용량을 얻는 함수이다.
//
// 반환
//		Heap 영역의 남은 용량을 반환한다.
uint32_t getHeapRemainingCapacity(void);

#if	YSS_L_HEAP_USE == true
// lmalloc을 통해 MCU 외장 SDRAM으로부터 동적 메모리 할당 받은 메모리를 반환하는 함수이다.
// 뮤텍스 lock, unlock은 내부에서 호출하기 때문에 호출 전후에 별도로 호출해줘야 할 함수는 없다.
// 
// void* addr
//		반환할 메모리의 번지를 설정한다.
void lfree(void* addr);

// MCU 외장 SDRAM으로부터 동적 메모리 할당받는 함수이다.
// 뮤텍스 lock, unlock은 내부에서 호출하기 때문에 호출 전후에 별도로 호출해줘야 할 함수는 없다.
// 
// 반환
//		할당받은 메모리의 번지를 반환한다.
// uint32_t size
//		메모리 할당받을 용량을 설정한다.
void* lmalloc(uint32_t size);
#endif

#if	YSS_C_HEAP_USE == true
// cmalloc을 통해 Core Coupled Memory로부터 동적 메모리 할당 받은 메모리를 반환하는 함수이다.
// 뮤텍스 lock, unlock은 내부에서 호출하기 때문에 호출 전후에 별도로 호출해줘야 할 함수는 없다.
// 
// void* addr
//		반환할 메모리의 번지를 설정한다.
void cfree(void* addr);

// Core Coupled Memory로부터 동적 메모리 할당받는 함수이다.
// 뮤텍스 lock, unlock은 내부에서 호출하기 때문에 호출 전후에 별도로 호출해줘야 할 함수는 없다.
// 
// 반환
//		할당받은 메모리의 번지를 반환한다.
// uint32_t size
//		메모리 할당받을 용량을 설정한다.
void* cmalloc(uint32_t size);
#endif

#endif