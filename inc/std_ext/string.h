////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_STRING__H_
#define YSS_STRING__H_

#include <string.h>
#include <stdint.h>

extern "C"
{
	// 메모리 값 설정을 한다. 2바이트 설정 값을 사용한다.
	// 
	// void* __s
	//		메모리가 설정되는 대상의 포인터를 설정한다.
	// int32_t __c
	//		des에 설정할 데이터를 설정한다.
	// uint32_t __n
	//		설정할 데이터의 크기를 설정한다.
	void *memsethw(void *__s, int32_t  __c, uint32_t __n);

	// 메모리 값 설정을 한다. 4바이트 설정 값을 사용한다.
	// 
	// void* __s
	//		메모리가 설정되는 대상의 포인터를 설정한다.
	// int32_t __c
	//		des에 설정할 데이터를 설정한다.
	// uint32_t __n
	//		설정할 데이터의 크기를 설정한다.
	void *memsetw(void *__s, int32_t  __c, uint32_t __n);
}

// DMA를 사용하는 메모리 복사를 한다.
// 
// void* des
//		메모리가 복사되는 대상의 포인터를 설정한다.
// void* src
//		복사할 데이터가 저장된 포인터를 설정한다.
// uint32_t size
//		복사할 데이터의 크기를 설정한다.
void memcpyd(void* des, void* src, uint32_t size) __attribute__((optimize("-O1")));

// DMA를 사용하는 메모리 값 설정을 한다. 1바이트 설정 값을 사용한다.
// 
// void* des
//		메모리가 설정되는 대상의 포인터를 설정한다.
// uint8_t data
//		des에 설정할 데이터를 설정한다.
// uint32_t count
//		설정할 데이터의 개수를 설정한다.
void memsetd(void* des, uint8_t data, uint32_t count) __attribute__((optimize("-O1")));

// DMA를 사용하는 메모리 값 설정을 한다. 2바이트 설정 값을 사용한다.
// 
// void* des
//		메모리가 설정되는 대상의 포인터를 설정한다.
// uint16_t data
//		des에 설정할 데이터를 설정한다.
// uint32_t count
//		설정할 데이터의 개수를 설정한다.
void memsethwd(void* des, uint16_t data, uint32_t count) __attribute__((optimize("-O1")));

// DMA를 사용하는 메모리 값 설정을 한다. 4바이트 설정 값을 사용한다.
// 
// void* des
//		메모리가 설정되는 대상의 포인터를 설정한다.
// uint32_t data
//		des에 설정할 데이터를 설정한다.
// uint32_t count
//		설정할 데이터의 개수를 설정한다.
void memsetwd(void* des, uint32_t data, uint32_t count) __attribute__((optimize("-O1")));

#endif
