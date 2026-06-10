/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_L_MALLOC__H_
#define YSS_L_MALLOC__H_

#include <stdint.h>

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

