// MIT License

// Copyright (c) 2024 Yoon-Ki Hong

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
